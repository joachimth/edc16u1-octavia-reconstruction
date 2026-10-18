# Startup-base trace — result & the real boundary

Goal: resolve the descriptor pointer at all 789 KF/KL call sites to concrete maps.

## What the call sites actually look like (from decompiled callers)
Two forms (see `kf_caller_samples.c`):
1. **RAM-direct**: `KF_lookup2d(x, y, &DAT_003ffd38, ...)` — descriptor is a fixed RAM
   address (a map mirrored/kept in RAM). Resolvable, but points at RAM, not flash.
2. **Context + offset (the common form)**:
   `iVar3 = *(r15 + 0x274); KF_lookup2d(x, y, iVar3, ...)`, and grouped maps as
   `iVar3`, `iVar3 + 0xF4`, `iVar3 + 0x1E8`. So `descriptor = *(r15 + ctx_off) [+ sub]`.

## Why it does not reduce to a static formula
- I tested the shortcut "r15-context is a verbatim copy of flash @0x800000", i.e.
  `*(r15+off) == flash32[0x800000+off]`. **Validation rejected it**: some offsets gave
  real map headers (e.g. ctx+0x25C → 0x8D9168, nx=8 ny=8), but others gave `nx=0` or
  garbage — so it is not a straight flash alias.
- `r15` is **not** loaded with a constant (`lis/addi r15`) anywhere in internal or
  external flash — so it is not a fixed global like r13 (which *is* 0x4017F0). It is a
  **context/handle pointer passed into these functions** by their callers, and it
  ultimately points at a RAM working structure whose pointer fields are filled at boot.

## The firm boundary
Full static attribution of all 789 sites needs the **boot-time initialization of that
RAM context** reversed — and `r15` is established per-subsystem up the call chain, not
from one constant. That is an iterative, multi-subsystem RE effort (trace each context
handle to where it is set, then to the flash pointer table that seeds it), not a single
automated pass. The honest state:
- **22 maps** resolve statically (direct/constant descriptors) — `map_readers_projectA.csv`.
- **789 read sites** are located and routed through the two named primitives.
- The remaining links are **runtime-context** — best closed by a **bench/dynamic trace**
  that logs the descriptor pointer at the `KF_lookup2d`/`KL_lookup1d` entry on the
  running ECU (a few minutes of logging attributes every active map), or by the
  per-subsystem context trace above.

## What is solid and usable now
- `KF_lookup2d` / `KL_lookup1d` named in the project; every map read is one XREF away.
- Descriptor format proven from code; all 95 standard maps already extracted with axes.
- Caller decompiles (`kf_caller_samples.c`) show, per call, which inputs feed the map
  and which `DAT_*` output it writes — enough to identify a map's role by hand in Ghidra.

## Files
`kf_caller_samples.c` (5 representative map-reading callers, decompiled), this note.
