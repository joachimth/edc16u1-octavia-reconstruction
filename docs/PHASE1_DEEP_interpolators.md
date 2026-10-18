# Phase 1 (deep) — interpolation dispatcher found & descriptor format proven from code

Worked on the complete linked project A image. The two Bosch calibration-lookup
primitives are now identified, decompiled and named in the Ghidra project.

## The two interpolation primitives (named & saved in the project)
| Addr | Name | Calls | Role |
|---|---|---|---|
| `0x05A16C` | **KF_lookup2d** | **387** | 2-D map interpolation (Kennfeld) |
| `0x05A074` | **KL_lookup1d** | **402** | 1-D curve interpolation (Kennlinie) |

Total **789 calibration-read call sites** across the firmware. Also named the
fixed-point helpers they use: `sat_add16` (0x05967C, 858 calls), `sat_div16`
(0x059800, 506), and `fp_helper_*` (0x0596FC/0x059718/0x0597AC/0x059794).

## The descriptor format is now proven from the lookup code itself
`KF_lookup2d(x, y, short *desc, byte *hint)` decompiles to exactly the layout I had
reverse-engineered from the raw bytes:
```
sVar1 = *desc;          // nx  = X-axis count   (u16)
iVar3 = desc[1];        // ny  = Y-axis count   (u16)
desc  = desc + 2;       // -> X axis (nx entries)
   ...bracket-search x in X axis, frac = (x-x0)*0x10000/(x1-x0)...
desc  = desc + nx;      // -> Y axis (ny entries)
   ...bracket-search y in Y axis...
   ...bilinear interpolation of the data grid, 16-bit, with sat_add16/sat_div16...
```
i.e. `[nx][ny][Xaxis:nx][Yaxis:ny][data:nx*ny]`, all big-endian u16 — independent
confirmation of the format in `MAPS_README.md`. `KL_lookup1d` is the same with one
axis. The `byte *hint` is the cached last-index (search accelerator).

## Why per-map → reader stays unresolved statically (now with the exact reason)
At each of the 789 call sites the descriptor pointer is `desc = GOT_base + constant`,
where `GOT_base` is a **RAM pointer loaded at run time** (e.g. `*(r15+0x1e0)`), not a
flash constant. Resolving all 789 call arguments to a constant flash address yields
**0** — every one goes through the RAM GOT. So the map a call reads is only fixed
once the GOT is populated. (The 22 "resolved" earlier were data pointers from the
block-0 table, not true code readers.)

## The exact next step that cracks it
The GOT (the r13/r15-relative RAM pointer block) is filled by a **startup copy loop**
in the internal flash that reads a flash pointer/offset table and writes the base
pointers into RAM. That routine is now present and disassembled. Reverse that one
loop → each RAM GOT slot's flash source is known → `desc = known_flash_ptr + offset`
resolves, and all 789 sites attribute to concrete maps. That is a single, scoped
target (the init copy loop), not a 789-way manual trace.

Alternatively, a bench/dynamic trace (log `desc` at the KF/KL entry) attributes them
directly — but that needs the running ECU.

## Files
- `interpolators.c` — full decompiled `KF_lookup2d` + `KL_lookup1d`
- `primitives.txt` — the named primitives and their call counts
The Ghidra project (`edc16a`) now carries these names; re-open it to see
`KF_lookup2d` / `KL_lookup1d` / `sat_*` everywhere they're called.
