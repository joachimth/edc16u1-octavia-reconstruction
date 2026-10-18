# Ghidra reconstruction — EDC16U1 external flash (03G906016B / 369564)

Built with Ghidra 11.3.2 (JDK 21) from `FlashWorkingOri.bin` (= the decrypted
`am29bl802cnoedccrypt.bin`).

## Import settings used
- Loader: **Raw Binary**, Language **PowerPC:BE:32:default** (classic FPU, not e500/VLE)
- Image base **0x800000** (external AM29BL802C window)
- Extra memory blocks: SRAM `0x3F9800` (0x6800), RAM `0x400000` (0x8000),
  `0x4FE000` (0x2000), USIU `0x2FC000`, IMB3 peripherals `0x300000`
- Small-data base **r13 = 0x4017F0** set over the whole program before analysis

## Result of auto-analysis
- **106,094 instructions**, **659 functions** recovered
- **133 calibration maps labeled** (`MAP_*` symbols) from the WinOLS/TunerPro names
- **1,184 pointer-table slots** at the block heads (0x800058 / 0x880058 / 0x8D0058)
  defined as pointers into the 0x008xxxxx window → `pointer_table.csv`

## Files
- `proj/` (in the zip) — the Ghidra project; open in the Ghidra GUI:
  `ghidra_11.3.2_PUBLIC/ghidraRun` → Import project `edc16b.gpr` → open `flash_ori.bin`
- `functions.csv` — every function (entry, size, xref count)
- `pointer_table.csv` — the descriptor/pointer table slots and their targets
- `decompiled_top_functions.c` — the 8 most-referenced functions (evidence r13 works)
- `scripts/edc16_pre.py` / `edc16_export.py` / `edc16_ptr.py` — reusable, re-runnable

## Notes / limits
- Maps are reached through the pointer/descriptor table, not by direct address, so
  Ghidra makes few *direct* code→map references. The slot targets (0x8D13xx…) are the
  map **descriptor headers**; the WinOLS addresses are the **data** a few bytes later.
  Linking each map to the exact reader needs the descriptor format modeled — a next step.
- Some workhorse functions use **r14** as a passed-in base pointer (shows as
  `unaff_r14`); those are called from the boot/startup code in internal flash.

## Adding the internal MPC556 flash (when you have a PLAINTEXT ~448 KB dump)
1. Open `flash_ori.bin` in the GUI.
2. File → Add To Program → the internal `.bin`, Language PowerPC:BE:32:default,
   Base Address **0x0**, length **0x70000**.
3. Re-run Auto Analyze. The reset vector (0x0), startup code (sets r13/r14) and the
   calls that currently dangle into 0x0–0x6FFFF will resolve.
