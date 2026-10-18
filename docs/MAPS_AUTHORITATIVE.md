# Authoritative, firmware-confirmed map catalogue (project A, 03G906016DJ)

The static reverse-engineering reached its clean endpoint here. Instead of the
heuristic axis-scan, this catalogue is built from the firmware's own evidence:

1. The real descriptor bases are the **464 cal pointers stored in flash** (the block
   tables copied into the r15 RAM context at boot).
2. Each base is parsed with the **exact format `KF_lookup2d`/`KL_lookup1d` use**
   (proven from their decompiled code): `[nx][ny][Xaxis][Yaxis][data]` for 2D,
   `[n][axis][data]` for 1D, all big-endian u16, with monotonic axes.
3. Each base is group-walked (maps are packed back-to-back; the +0xF4/+0x1E8 offsets
   seen at call sites are the later maps in a group).

## Result — `maps_authoritative_projectA.csv`
- **124 confirmed tables**: **46 two-dimensional maps** + **78 one-dimensional curves**.
- All 46 2D maps were also in the heuristic scan (cross-validated).
- The 78 1D curves are additions the earlier 2D-oriented scan did not list.
- Every entry is referenced by a real flash descriptor pointer, so this is the set the
  firmware actually uses — not candidates.

Columns: `cpu_addr, kind (1D/2D), nx, ny, pointer_base (yes=directly pointed), in_heuristic`.

## How this sits against the 412 heuristic candidates
The heuristic found 412 axis-like byte patterns; most were axis tables, sub-arrays or
false positives. The 124 here are the ones the code demonstrably treats as
lookup tables via a stored descriptor pointer. Axis orientation is now authoritative
too: `nx` = X axis (`*desc`), `ny` = Y axis (`desc[1]`), per the lookup code.

## State of the reconstruction (static limit reached)
| Layer | State |
|---|---|
| External + internal flash + EEPROM | ✅ complete matched plaintext set, linked in Ghidra |
| Interpolation primitives | ✅ `KF_lookup2d` / `KL_lookup1d` named, format proven |
| Map catalogue | ✅ 124 firmware-confirmed (this file); axes extractable for all |
| Per-map → exact reader function | ⚠️ 22 static; rest run through a RAM context pointer set per-subsystem at boot — needs a bench/dynamic trace (no hardware available) or per-subsystem manual context tracing |

## Sensible next step without hardware
**Phase 2 — names:** project the 95 named maps from the 016B set onto these 124
confirmed 016DJ tables by structure/position, giving a named map pack for your car's
file. That is fully offline and builds directly on this catalogue.
