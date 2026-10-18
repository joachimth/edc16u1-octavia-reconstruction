# EDC16U1 reconstruction — update after the BDM batch

Supplements `RECONSTRUCTION.md` / `_v2.md`. Forensic documentation only.

## A. Full dedup inventory — 16 binaries → 10 unique blobs

| SHA1[:12] | Same bytes = these files | What it is |
|---|---|---|
| be9a56db1308 | octavia.bin | Project A ext flash, **03G906016DJ** |
| 64c429a78bc7 | NewClonedEprom **==** NewClonedEprom-immooff | Project A EEPROM (021LB); the "immooff" copy is **not** modified |
| 13134fc2acb6 | **FlashWorkingOri == am29bl802cnoedccrypt.bin** | **Project B ext flash, PLAINTEXT** (03G906016B) |
| f193cfca85d2 | JT_stagev1 | Project B ext flash, stage-1 |
| 3e4fd2f2dc0c | FLASHWORKINGchippedv01.MOD | Project B ext flash, modified |
| 2427ca2155f0 | eprom.e2p **==** dumpfileepromdecoded | Project B EEPROM, read #1 |
| 720c3c9232f5 | Eprom.e2p (new) **==** EDC16U1-New-EEPROM.e2p | Project B EEPROM, read #2 |
| 8109b07797fa | **am29bl802c.bin == EDC16U1-NEW-FlashFileEDC16Enc** | Project B ext flash, **ENCRYPTED** BDM read |
| 17aaf45a5f52 | **mpc.mpc == internalflashmpc.e2p.mpc** | Project B **internal MPC556 flash, ENCRYPTED** |
| af9d843323de | EDC16U1-NEW.dim | DimSport BDM project (`DS  `), encrypted |

So the earlier `mpc.mpc` was the internal-flash dump all along, and
`am29bl802cnoedccrypt.bin` is byte-identical to `FlashWorkingOri.bin`.

## B. External flash — fully recovered ✅

`am29bl802c.bin` (= the `…EDC16Enc.bin`) is the **encrypted** AM29BL802C BDM read;
`am29bl802cnoedccrypt.bin` is its **decrypted** output, and it equals
`FlashWorkingOri.bin`. The enc→dec transform is a genuine position-dependent
encryption (global byte histogram changes, no repeating XOR key ≤32, not a byte/word
permutation), so it is not trivially reversible here — but it doesn't need to be,
because the plaintext already exists. Load `FlashWorkingOri.bin` at CPU `0x800000`.

## C. Internal MPC556 flash — present but ENCRYPTED ⚠️

`internalflashmpc.e2p.mpc` (= `mpc.mpc`), 238,362 B:
- entropy **7.97 bits/byte**; only **1015** `0x00` bytes and **818** `0xFF` bytes
  (~0.4% each). A real flash image always has large runs of both (erased sectors,
  alignment padding). This file has none → it is **encrypted/encoded, not a raw
  image**, and it is smaller than the 448 KB internal flash.
- `EDC16U1-NEW.dim` is a **DimSport** container (magic `DS  `, entropy 7.99). Its
  header references a ~238 KB region (0x3A18C) = the internal block, but it embeds
  neither the internal nor the external bytes verbatim and contains no identity
  strings → also encrypted.

**Consequence:** we still cannot load the internal flash as PowerPC code. The reset
vectors, startup code (which sets r13), and the lower half of the program live at
`0x0–0x6FFFF` and remain locked inside these encrypted containers.

**To unlock the code-level rebuild**, export the internal flash as a **plaintext
~448 KB `.bin`** from the tool that made these (DimSport Trasdata / New Genius /
New Trasdata — "save/export decrypted microprocessor read", or a BDM read via a
tool that outputs plain binary). Then add it in Ghidra at base `0x0`, length
`0x70000`, and the dangling calls from `FlashWorkingOri.bin` resolve.

## D. EEPROM — two reads of the same ECU

Reads #1 (`2427ca`) and #2 (`720c3c`) share identity (03G906016B, VIN
`WVWZZZ1KZ4W121674`, CP `VWZ7Z0D9536116`) but differ in **~397 bytes**, concentrated
in the component-protection / adaptation region around `0x09E–0x13F`. That is the
expected per-read variation of the rolling/adaptation values; the static identity
fields are unchanged.

## E. Status of the reconstruction

| Component | State |
|---|---|
| External flash (0x800000) | ✅ plaintext, mapped, 412 maps scanned, 133 named (project B) |
| Calibration maps + names | ✅ `named_maps_369564.csv` |
| Checksum regions | ✅ block tails 0xCFF74 / 0xFDF78 |
| EEPROM layout | ✅ fields mapped, 2 reads |
| **Internal MPC556 flash (0x0)** | ⚠️ **encrypted — need plaintext ~448 KB export** |
