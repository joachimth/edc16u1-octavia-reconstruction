# EDC16U1 calibration maps — descriptor model, extraction & reference mechanism

Reverse-engineered from `FlashWorkingOri.bin` (03G906016B / 1037369564 / 5645).
Documentation only.

## 1. Map descriptor format (confirmed empirically)

Every "Bosch II 16 / Bosch III" map is stored **inline** as big-endian u16:

```
header_start:  [cnt1 u16][cnt2 u16][axis1 : cnt1·u16][axis2 : cnt2·u16]
data_start:    [data : cnt1·cnt2 · u16]
```

- The WinOLS address is the **data_start**; the header precedes it by
  `4 + 2·(cnt1+cnt2)` bytes.
- Count order is **cnt1 = rows, cnt2 = cols** (verified: 95/133 maps match this
  order; the rest are square or "Statistical 16", which use a different layout).
- Verification: axis1 and axis2 are monotonically non-decreasing in **92** of the
  95 parsed maps — independent proof the header offset and axis lengths are right.
- `axis1` (cnt1 entries) is the first breakpoint set (typically engine speed),
  `axis2` (cnt2 entries) the second (load / IQ / etc.). Raw counts only.

Worked example — **EGR Map** @ data `0x8D3C28`, header `0x8D3BEA`, 13×16:
- axis1 (16): 0,700,730,740,1000,1239,1386,1491,1596,1743,1911,2058,2247,2499,2830,3423  (≈ rpm)
- axis2 (13): 0,300,740,1000,1240,1500,1740,2000,2240,2500,2900,3300,3800
- 16×13 data grid, monotonic — see `maps_named_readable.txt`.

## 2. What was extracted

- `maps_extracted.json` — all 133 maps; for the 95 standard ones: header addr,
  both axes, and the full data grid (raw u16). The 38 "Statistical 16" / square
  entries are flagged as other-layout (raw only).
- `maps_named_readable.txt` — the 8 TunerPro-named maps rendered as tables
  (axes + full grid) for eyeballing.
- `map_descriptors.csv` — per map: data/header address, axis monotonicity, and any
  absolute 32-bit pointer found to the header or data.

## 3. How code reaches the maps (and why per-map reader attribution is blocked)

- **No absolute pointers.** Scanning the whole flash for a BE32 value equal to each
  map's header/data address finds none for the named maps (only 12 of 133 have any
  absolute pointer, 34 sites total). So maps are **not** reached by a stored pointer.
- **Base + 16-bit offset, table-driven.** The maps sit in 0x8D0000–0x8EFFFF and are
  reached as `base_anchor + displacement`, with anchors 0x10000 apart
  (0x8D0000, 0x8E0000, …) so a signed 16-bit offset covers each. The block-0 table
  at 0x800058+ (1,184 slots) supplies pointers to the axes/curves/anchors in the
  cal block (e.g. slot→0x8D13xx, which is axis data: 500,750,1000… rpm).
- **The displacement is itself fetched from a table at run time, not encoded as an
  immediate.** Scanning all 106,094 instructions for each map's displacement:
  the large unique offsets (e.g. EGR 0x3C28) appear in **zero** instructions; only
  the tiny offsets collide with common immediates (false positives). See
  `map_reader_candidates.csv` — treat the multi-candidate rows as noise.
- **Conclusion:** static per-map→reader attribution is not recoverable from the
  external flash alone. The code that indexes the offset tables and sets the base
  anchors lives largely in the **internal MPC556 flash (0x0–0x6FFFF)**, which is
  still only available encrypted. With a plaintext internal dump — or the A2L/DAMOS,
  which lists each map by descriptor index — the attribution becomes direct.

## 4. Scaling / names
Physical scale factors and the real map names are **not** in the binary; they live
in the A2L/DAMOS. Research located one by name:
`Skoda_Octavia_1,9_TDI_105PS_0281011883_03G906016DJ_6250_1037371259` — the A2L for
the *016DJ* set; an *016B* A2L would scale this file exactly. The TunerPro names used
here come from the uploaded `FlashWorkingNEWJTRev01.log`.

## 5. Files
`maps_extracted.json`, `maps_named_readable.txt`, `map_descriptors.csv`,
`map_reader_candidates.csv`, and this README. Re-generate with the scripts in the
Ghidra bundle.
