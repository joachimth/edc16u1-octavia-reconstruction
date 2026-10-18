# EDC16U1 firmware reconstruction — Skoda Octavia 1.9 TDI

Reverse-engineering notes for your own ECU data. Structural reconstruction only.
This file deliberately contains no tuning recipes and no emissions- or
immobiliser-defeat procedures.

## 0. Files in this set

| File | SHA1 (first 8) | What it is |
|---|---|---|
| `4923927c-octaviaor.bin` | be9a56db | 1,048,576 B — **external flash** read (Am29BL802C, 512K×16) |
| `759f7b81-NewClonedEprom.bin` | 64c429a7 | 4,096 B — ST95320 serial **EEPROM** |
| `6024e2c7-NewClonedEprom-immooff.bin` | 64c429a7 | 4,096 B — **byte-identical** to the clone above |

> ⚠️ **Two important facts before you start**
> 1. The two EEPROM files are **identical** (same SHA1, `cmp` = 0 differences).
>    The "immooff" copy is not modified relative to the clone.
> 2. The flash and the EEPROM come from **different control units**:
>    - flash part number **03G906016DJ**, SW 6250, Bosch **1037371259**
>    - EEPROM part number **03G906021LB / 03G906021AN**, SW 9251, Bosch 1037382414 / 1037377150
>    Both are 105 PS 1.9 TDI EDC16U1, but they are not a matched pair. For a full
>    reconstruction you want the flash and EEPROM from the *same* ECU.

## 1. Hardware / memory map (MPC556, EDC16U1)

| Region | CPU address | Size | Notes |
|---|---|---|---|
| Internal CMF flash (boot, reset vectors, core code) | `0x000000` | `0x70000` (448 KB) | **NOT in your dump** — needs a BDM read of the MPC556 |
| Internal SRAM | `0x3F9800` | `0x6800` | 26 KB (SRAM A+B) |
| Work RAM | `0x400000` | `0x8000` | |
| Cal-tool RAM (CCP/ETK, dev HW) | `0x4FE000` | `0x2000` | often absent |
| USIU / flash control regs | `0x2FC000` | `0x880` | volatile |
| IMB3 peripherals (TPU, QADC, TouCAN, MIOS, QSMCM) | `0x300000` | `0x8000` | volatile |
| **External flash (your 1 MB dump)** | **`0x800000`** | `0x100000` | load file offset 0 here |

- CPU: **MPC556** (MPC555 family), 32-bit **big-endian PowerPC**, classic FPU.
- Ghidra language: **`PowerPC:BE:32:default`**. Do *not* use e500 or any VLE variant.
- Small-data base: **r13 = 0x4017F0** (0x4017F0 − 0x8000 = 0x3F97F0, just below SRAM).
  Confirm in startup code: `lis r13,0x40` (`3D A0 00 40`) + `addi r13,r13,0x17F0`
  (`39 AD 17 F0`) or `ori` (`61 AD 17 F0`). On EDC16U1, r2/TOC is not used to
  point into flash — a GOT/offset table is used instead.

**Base address is independently confirmed by your own dump:** every block header's
2nd dword is `0x0080D5xx` (inside the 0x800000 window), and block 0 holds 239
pointers into `0x008xxxxx` within its first 0x400 bytes.

## 2. Flash dump layout (measured from the region descriptors)

Each block starts with `00 00 00 58 | <hdrptr u32> | <length u32> | <link u32>`
then the ASCII SW tag `1037371259379U85B6`.

| File offset | CPU addr | Length (from header) | Ends at | Role |
|---|---|---|---|---|
| `0x00000` | `0x800000` | `0x80000` | `0x87FFFF` | **ASW** — application code + addressing/pointer table at the very start |
| `0x80000` | `0x880000` | `0x50000` | `0x8CFFFF` | 2nd program/data block |
| `0xD0000` | `0x8D0000` | `0x2E000` | `0x8FDFFF` | **Calibration / data set** (`03G906016DJ` at file 0xD0064) |

`0x70000–0x7FFFF`, `0x90000–0xCFFFF`, `0x8FE000–0x8FFFFF` are erased (`0xFF`) tails
of each sector range. The `length` dwords above match the real data extents exactly,
which is why they are the natural **checksum-region descriptors** (see §4).

## 3. Calibration maps

Layout (Bosch EDC16): `[nx u16][ny u16][X axis nx·u16][Y axis ny·u16][data nx·ny·u16]`,
all **16-bit big-endian**; a curve has nx or ny = 1. Raw values only — physical
scaling (°CA, mg/stroke, bar, %) is in the A2L/DAMOS, not in the binary.

A scan of `0xD0000–0xFDFFF` finds **412 candidate tables** (monotonic axes).
Most common shapes: 2×2 (×123), 8×8 (×68), 10×10 (×36), 16×13 (×10), 16×16 (×5).
Full list with file + CPU addresses: **`edc16u1_maps.csv`**.

Maps are reached from code through the **pointer/offset table at the start of the
flash** (not by direct addresses). In Ghidra: type the run of `0x008Dxxxx` dwords as
a pointer array, then follow XREFs from the interpolation routines that take a
pointer to a map header. Note the calibration region holds several variants
(e.g. MAN / AUT), selected at run time via an offset table, so a map can appear
more than once.

## 4. Checksums (descriptive)

VAG EDC16 uses **additive checksums over ranges listed in region descriptors inside
the image** (the per-block header dwords in §2 are the descriptor source). The
open-source **ZedSuite** (GPL-3.0) implements an EDC16 "additive corrector" driven
by those region descriptors and returns *unverifiable* when no region is found;
**WinOLS** (OLS285 plugin) also corrects EDC16. The EEPROM carries its own,
separate per-block 16-bit checks. Treat the exact U1 ranges as something to confirm
against a second stock U1 dump before trusting any recomputation.

## 5. EEPROM (ST95320, 4 KB) layout

Records are stored redundantly (2× or 3×) with a 16-bit trailer each:

| Offset(s) | Content |
|---|---|
| `0x000–0x03F` | dates (`25-10-06`, `27-10-06`), SW ids `1037382414A`, `1037377150` |
| `0x049` | `03G906021AN` |
| `0x066`, `0x0A6` | `03G906021LB R4 1,9L EDC 9251` (2×) |
| `0x0E0–0x13F` | **component-protection / immobiliser record** `SKZ7Z0F3868828` (3×) + preceding key bytes |
| `0x145`, `0x165` | **VIN** `TMBGS21Z272076562` (2×) |
| `0x7F0–0x83F` | `--H06---` tags (3×) |
| `0xFC0–0xFFF` | trailing data/checksum area |

Use `eeprom_parse.py` to locate and cross-check the copies. (The component-protection
record is identified here only for mapping purposes.)

## 6. Ghidra bring-up

1. Import `octavia.bin`: Raw Binary, `PowerPC:BE:32:default`, Base Address `0x800000`.
2. Run `ghidra_load_edc16u1.py` from the Script Manager — adds RAM/peripheral blocks
   and sets r13 = 0x4017F0.
3. If you obtain a **BDM read of the MPC556 internal flash**, add it at `0x0`
   (File → Add To Program, length 0x70000). Without it the reset vectors, startup
   code and part of the core are missing, so calls into `0x0–0x6FFFF` dangle.
4. Disassemble from the targets of the pointer tables at each block start, not from
   the header bytes at 0x800000.

## 7. What "reconstruct it all" still needs

- [ ] **BDM dump of the MPC556 internal flash (0x0–0x6FFFF)** — the missing half of
      the code. The 1 MB OBD read is external flash only.
- [ ] A matched **flash + EEPROM pair** from one ECU (yours are from two).
- [ ] An **A2L/DAMOS** for `03G906016DJ / 6250 / 1037371259` to turn the 412 raw
      tables into named, physically-scaled maps.
- [ ] Confirm r13 and the checksum regions against your own startup code / a 2nd dump.

## Tools in this set
- `map_scan.py` — standalone Bosch-map scanner (configurable base/range → CSV)
- `edc16u1_maps.csv` — the 412 tables found in your calibration block
- `eeprom_parse.py` — EEPROM layout locator + redundancy check
- `ghidra_load_edc16u1.py` — Ghidra post-import memory/register setup
