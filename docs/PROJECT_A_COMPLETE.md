# Project A — COMPLETE firmware reconstruction (Skoda Octavia 1.9 TDI, 03G906016DJ)

Your original `octaviaor.bin` is the external flash of this ECU. The later uploads
provided the two missing halves — the **plaintext internal MPC555 flash** and the
**matched EEPROM** — so the whole image is now reassembled and analyzed in Ghidra.

## Matched plaintext set (all verified to SW 1037371259 / 03G906016DJ)
| Part | File(s) | Maps to |
|---|---|---|
| External flash (1 MB, AM29BL802C) | `octaviaor.bin` = `a-29bl802c.bin` = `03G906016DJ obd mpps v16.bin` | CPU 0x800000 |
| Internal flash (MPC555, ~448 KB) | `Mic.bin` (used); `b-mpc555.bin` is an alternate read | CPU 0x0 |
| EEPROM (ST95320, 4 KB) | `c-serial epp.bin` — VIN `TMBDS21ZX52012365`, 03G906016DJ | serial EEPROM |

The RAR confirmed it: `a-29bl802c.bin` and the MPPS OBD read are **byte-identical**
to your first file. (Note the EEPROM you first sent, 03G906021LB, was from a
different ECU; `c-serial epp.bin` is the one that matches this flash.)

## Ghidra result — the two halves are now linked
- Loaded: external `octaviaor.bin` @ **0x800000** + internal `Mic.bin` @ **0x0**
- **r13 = 0x4017F0** — now confirmed from the real startup code: `lis r13,0x40` +
  `addi r13,r13,0x17F0` at 0x0020C
- **208,065 instructions**, **2,159 functions** (1,464 internal + 695 external)
- **5,362 external→internal** call/branch references now resolve (126 internal→external)
  — i.e. the ASW calls into the boot/library code that was missing before
- Reset vector at 0x0 branches into the startup (`FUN_00001284`); Bosch markers
  present: `BOSCH EDC16/StartupBlock MPC555/All CC_OFF 40/40/20 11.02.2002`,
  `Bosch.common.RamLoader.EDC16.A000`

## Files (in the zip)
- `proj_a/` — the Ghidra project `edc16a` (open `edc16a.gpr`, program `octavia.bin`)
- `functions.csv` — all 2,159 functions with region (internal/external), size, xrefs
- `decompiled_startup.c` — reset vector + startup
- `summary.txt` — the counts above

## What's now possible (no longer blocked)
With both halves linked, the map→reader attribution that was impossible before can be
finished: the offset tables and base anchors live in the internal flash and are now
disassembled. Next steps on request:
1. Trace the internal offset-table setup to attribute each calibration map to its
   reader function (the step that needed internal flash).
2. Project the 95 named maps (from the 016B set) onto this 016DJ calibration.
3. Decode the matched EEPROM `c-serial epp.bin` layout for this ECU.

## Bonus: a third ECU is in the uploads
`M59BW016.bin` (2 MB) is a different unit — **03G906021TB / 1037391891 / cal 2047**,
an **EDC16+ on MPC561** (`BOSCH EDC16+/StartupBlock MPC561 ... 05.03.2004`), with its
own EEPROM (`ee_95160`, VIN `TMBBS21Z398018793`). Different CPU/flash map from the
MPC555 EDC16U1 above — can be set up separately if you want it.
