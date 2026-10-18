# EDC16U1 reconstruction — update after the WinOLS / TunerPro / EEPROM batch

This supplements `RECONSTRUCTION.md`. The new upload confirms several inferences
and adds a **named map pack**. Structural/forensic documentation only — no tuning
recipe and no emissions/immobiliser-defeat procedure.

## A. The uploads are TWO different ECU projects

| | Project A (first .bin) | Project B (this batch) |
|---|---|---|
| Flash part no. | **03G906016DJ** | **03G906016B** |
| Cal / SW version | 6250 / 1037371259 | **5645 / 1037369564** |
| Bosch HW | 0281011883 | 0281011478 |
| SW tag in flash | `1037371259379U85B6` | `1037369564379U8592` |
| EEPROM in set | NewClonedEprom (03G906021LB — mismatched) | **eprom.e2p (03G906016B — matches)** |
| WinOLS project | — | **"…369564"** (matches SW) |

Project B is internally consistent: flash + EEPROM + WinOLS project + TunerPro log
all belong to the **03G906016B / 1037369564 / 5645** unit. (EEPROM VIN is
`WVWZZZ1KZ4W121674`, a VW 1K platform, despite the WinOLS project being named
"Skoda Octavia" — identify by part number, not the project name.)

## B. File inventory

| File | Size | What it is |
|---|---|---|
| `FlashWorkingOri.bin` | 1 MB | **Original** 03G906016B external flash (reference) |
| `JT_…stagev1becu_…369564.bin` | 1 MB | **Stage-1** modified flash |
| `FLASHWORKINGchippedv01.MOD` | 1 MB | Another modified flash (TunerPro ".MOD" = full bin) |
| `eprom.e2p` / `dumpfileepromdecoded.bin` | 4 KB | **Identical** — decoded ST95320 EEPROM for this ECU |
| `WinOLS…369564.ols` | 1.16 MB | WinOLS project container (original bin + map pack) |
| `WinOLS…369564.kp` | 9 KB | WinOLS project meta (path: `…RightNow\V2-ecu\CurrentWorking`) |
| `mpc.mpc` | 233 KB | WinOLS processor/MPC module (proprietary, compressed) |
| `…csv` ×2 | — | Exported map lists (addresses + WinOLS map types) |
| `FlashWorkingNEWJTRev01.log` | — | TunerPro edit log with **named** tables |

The `.ols/.kp/.mpc` are WinOLS' own compressed formats; they aren't plain-text
parseable here, but the two CSV exports already give their map inventory.

## C. Named map pack  →  `named_maps_369564.csv`

133 maps exported from WinOLS, now with CPU address (= 0x800000 + file offset),
WinOLS map type (Bosch II 16 / Bosch III 16·8 / Statistical 16), dimensions, the
TunerPro name where known, and a **`stage1_changed`** flag computed by diffing
`FlashWorkingOri.bin` against the stage-1 file.

Named tables (from the TunerPro log, 2019):

| CPU addr | File off | Name |
|---|---|---|
| 0x8DF8E6 | 0xDF8E6 | Drivers Wish |
| 0x8EB584 | 0xEB584 | Drivers Wish (2nd) |
| 0x8DDF04 | 0xDDF04 | Torque limiting |
| 0x8DFBA0 | 0xDFBA0 | Torque limiting by MAP → IQ |
| 0x8E009E / 0x8E027C | 0xE009E / 0xE027C | Lambda map |
| 0x8DFEC0 | 0xDFEC0 | Lambda map (MAF) |
| 0x8D3C28 | 0xD3C28 | EGR map |

## D. Checksums — now located

Diffing original → stage-1 shows all data edits sit in the calibration area, and
**two edited blocks fall exactly on the region tails**:

- `0xCFF74–0xCFFFF` = last 0x8C bytes of block 1 (ends 0xCFFFF)
- `0xFDF78–0xFDFFF` = last 0x88 bytes of block 2 / calibration (ends 0xFDFFF)

These tails are the **checksum / region descriptors** for the additive EDC16
checksum (§4 of the main doc). They were recomputed when the maps changed — which
both confirms where the checksums live and that this tool-chain corrects them
automatically. The 12 maps overlapping the stage-1 edits are flagged in the CSV
(EGR, Drivers Wish, Lambda×3, and the 15×19 injection/SOI maps at 0x8E8A24…).

## E. EEPROM structure confirmed (eprom.e2p, same layout as project A)

| Offset(s) | Field |
|---|---|
| 0x026 / 0x034 | SW `1037369564A` / `1037370435` |
| 0x049 | Bosch HW `0281011478` |
| 0x066 / 0x0A6 | part `03G906016B` + `R4 1,9L EDC 5645` (2×) |
| 0x0EC / 0x10C / 0x12C | component-protection record `VWZ7Z0D9536116` (3×) |
| 0x145 / 0x165 | VIN `WVWZZZ1KZ4W121674` (2×) |

Identical field offsets to the Skoda EEPROM → the ST95320 layout is stable across
these EDC16U1 units, so `eeprom_parse.py` works on both.

## F. Net result for the reconstruction

- Map **names + addresses** for 03G906016B are now known (CSV). The same relative
  offsets line up with project A's calibration block, so they transfer as a strong
  starting hypothesis for naming your `03G906016DJ` maps too.
- **Checksum regions** are pinned to the block tails at 0xCFF74 and 0xFDF78.
- The EEPROM layout (part/SW/immo/VIN) is mapped and consistent.
- Still missing for a *code-level* rebuild: a **BDM read of the MPC556 internal
  flash (0x0–0x6FFFF)**; the external flash alone has no reset/boot code.
