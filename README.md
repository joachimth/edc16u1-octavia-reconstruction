# EDC16U1 ECU reconstruction — Skoda Octavia 1.9 TDI (03G906016DJ)

A full reverse-engineering reconstruction of a Bosch **EDC16U1** diesel ECU, built
from legally obtained dumps. Covers the complete firmware image, a working Ghidra
project, the calibration-map catalogue, the decompiled lookup engine, and the tools
used — all organized so the work is reproducible.

> Documentation and analysis only. Nothing here is a tuning recipe, and no
> emissions- or immobiliser-defeat procedure is included.

## What was achieved
- **Complete matched firmware image** for the Octavia (03G906016DJ / SW 1037371259):
  external flash (AM29BL802C @ CPU `0x800000`) + internal MPC555 flash (@ `0x0`) +
  the matched ST95320 EEPROM (VIN `TMBDS21ZX52012365`).
- **Ghidra project** with both halves loaded and linked: **208,065 instructions,
  2,159 functions**; `r13 = 0x4017F0` confirmed from the real startup code
  (`lis r13,0x40; addi r13,r13,0x17F0` @ `0x20C`); **5,362** external→internal calls
  resolved.
- **Lookup engine identified and proven**: `KF_lookup2d` (2-D maps, @`0x05A16C`,
  387 calls) and `KL_lookup1d` (1-D curves, @`0x05A074`, 402 calls). Their decompiled
  code proves the Bosch descriptor format `[nx][ny][Xaxis][Yaxis][data]` (big-endian
  u16), matching the raw-byte analysis.
- **Map catalogue**: **124 firmware-confirmed tables** (46 2-D + 78 1-D) with axes,
  derived from the real descriptor pointers — not a heuristic guess.
- **Cross-reference**: 31 axis-identical maps between this file and the 016B sibling.
- **Functional names via A2L axis-match**: **158** maps named reliably (40 of them inside
  the 124-catalogue) by matching exact axis break-points against sibling-variant A2Ls
  (EDC16U31 1.9 TDI PD) — validated by identical breakpoints, not guessed. Each named
  map also carries its A2L `COMPU_METHOD` scaling (`physical = factor·raw + offset`),
  so values show in real units (mg/hub, °C, Nm, µs, …). See `docs/NAMED_MAPS.md`.

## Live dashboard
An interactive dashboard (`index.html`, published via GitHub Pages) presents every table
as a chart/heatmap and runs the ECU's own interpolation live:
- **Simulator** — pick a map, drag the axis inputs; output is computed 1:1 with the
  decompiled `KF_lookup2d`/`KL_lookup1d`, shown in physical units for named maps.
- **Kæde-sim** — chain maps in series (seeded with a physical example: rpm + load →
  injection quantity → injector time, plus the overrun limit).
- **Motormodel** — the canonical EDC16 common-rail fuel path as an interactive block
  diagram laid over the real maps; each block is tagged *verified name* / *core map,
  role unverified* / *modelled*, and clicking a block opens that map in the simulator.
  It is explicit about what a full cycle-accurate simulation would additionally require.

## Honest limits
- **Per-map → exact reader**: only ~22 resolve statically. The rest reach their map
  through a RAM context pointer (`*(r15+off)`) that is populated at boot per
  subsystem, so the map a call uses is only fixed at run time. Closing the last link
  needs a **bench/dynamic trace** of the running ECU (not available) or per-subsystem
  manual tracing. See `docs/PHASE1_ATTRIBUTION_STATUS.md`.
- **Functional names**: the exact-family **03G906016AA DAMOS** is still password-locked,
  and names do **not** transfer by position from the 016B sibling (its maps were retuned).
  Names here come only from **exact axis-signature matches** against sibling-variant A2Ls
  (see above) — reliable for the matched maps, but the unnamed core 2-D maps (base
  quantity, timing, rail pressure) have no verified role or output scaling.
  `docs/FUNCTIONAL_READERS.md` gives the code-level facts; `docs/NAMED_MAPS.md` the names.

## Layout
```
firmware/     plaintext dumps, grouped by control unit (+ MANIFEST with sha1s)
ghidra/       ready-to-open Ghidra projects (projectA = complete, edc16b = 016B)
maps/         map catalogues, axes, cross-references (CSV/JSON/txt)
decompiled/   KF/KL lookup engine, startup, reader functions, pointer tables
tools/        map scanner, EEPROM parser, Ghidra loader/analysis scripts
docs/         the full write-up, in phases
```

## Reproduce the Ghidra project
Unzip `ghidra/ghidra_projectA_complete.zip` and open `edc16a.gpr` in Ghidra 11.3.2
(JDK 21). Or rebuild from `firmware/` with `tools/edc16a_pre.py` (import external at
base `0x800000`, add internal at `0x0`, set `r13`). Details in
`docs/PROJECT_A_COMPLETE.md` and `docs/GHIDRA_README.md`.

## Document index (read in order)
1. `docs/RECONSTRUCTION.md` → `_v2` → `_v3` — identification, memory map, the dump set
2. `docs/PROJECT_A_COMPLETE.md` — the complete linked image
3. `docs/MAPS_README.md`, `docs/MAPS_AUTHORITATIVE.md` — descriptor format + catalogue
4. `docs/PHASE1_*` — the lookup engine and the attribution boundary
5. `docs/PHASE2_RESULT.md` — cross-version name projection (and why it's limited)
6. `docs/FUNCTIONAL_READERS.md` — code-level index of the map-reading functions
