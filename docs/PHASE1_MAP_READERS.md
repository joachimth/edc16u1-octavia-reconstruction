# Phase 1 — map → reader attribution (project A, complete image)

Run against the full linked image (external 0x800000 + internal MPC555 0x0,
208k instructions, 2,159 functions). Goal: tie each of octavia.bin's 412
calibration maps to the code that reads it.

## Results
- **412 maps labeled** (`MAP_<dims>_<cpu>` symbols).
- **22 maps statically attributed** to a concrete reader — these are reached by a
  resolvable address/pointer. See `map_readers_projectA.csv`
  (columns: direct code refs + the block-0 pointer-table slots that point at them +
  the reader function).
- The other **390 maps are dispatched dynamically**: the map address is a runtime
  argument (base-anchor + offset fetched from an index table, or a descriptor
  pointer passed into a shared routine), so no static code→map reference exists.
  This is why constant propagation over the whole image still resolves only 22.

## Pointer-table structure (`pointer_chain_projectA.csv`)
The block-0/1/2 tables hold **1,524 pointers** into the calibration window; **148**
land on (or within 64 B of) a map. But the slots themselves are almost never read
by a statically-resolvable load (the index is computed at runtime), so the
slot→reader edge is empty for nearly all — same dynamic-dispatch wall.

## The shared library (`interpolation_library.c`, `internal_library_candidates.csv`)
The most-referenced internal functions are the **fixed-point math primitives** every
calibration lookup is built on — decompiled and confirmed:
- `FUN_0005967c` (858 callers) — **saturating add**, clamps to int16 [-0x8000,0x7FFF]
- `FUN_00059800` (506) — **saturating divide**, clamps to int16
- `FUN_00042200` (512) / `FUN_00041f08` (453) — status/diagnostic flag handling
  over the RAM table at `DAT_003ff760`

So every map read funnels through this fixed-point layer; the 2-D/3-D interpolation
routine sits just below these in the xref ranking and takes the map descriptor as an
argument.

## Honest limit & what finishes it
Static, one-pass attribution tops out at the 22 above because the access is
argument-driven. Completing all 412 is an **iterative** job, now fully possible on
this image:
1. Decompile the interpolation dispatcher (the high-xref routine that takes a
   descriptor pointer + axis inputs) and fix its signature.
2. At each call site, back-trace the descriptor-pointer argument (base anchor +
   offset) to the concrete map — Ghidra's decompiler resolves these per-call once
   the base registers (r13/r14 and the table anchors) are typed.
3. Fold in the 016B names (phase 2) to label the resolved maps.

This is reverse-engineering effort per routine, not a single automated sweep — but
the image is now complete enough to do it. Say the word and I'll start on the
interpolation dispatcher.

## Files
`map_readers_projectA.csv`, `pointer_chain_projectA.csv`,
`internal_library_candidates.csv`, `interpolation_library.c`.
