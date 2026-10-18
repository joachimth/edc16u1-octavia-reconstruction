# Phase 2 — projecting 016B names onto 016DJ: result

## Conclusion: functional names do NOT transfer reliably
Three methods tried to move the 8 functional names (EGR, Drivers Wish, Lambda,
Torque limiting, Torque-by-MAP) from 016B (1037369564) to 016DJ (1037371259):

| Method | Result |
|---|---|
| Same-address transfer | ✗ 016B named addresses are not valid maps in 016DJ (different layout) |
| Axis-similarity (nearest) | ✗ scores 0.31+, multiple names collapse onto one map |
| Exact axis signature | ✗ 0 of 8 named maps have an axis-identical twin in 016DJ |

Reason: the named maps are exactly the ones retuned between the two software
versions, so their axis breakpoints differ. Forcing a name on by weaker heuristics
would be a guess — and on EGR/lambda/torque maps a wrong label is actively
dangerous, so those are left unlabelled rather than mislabelled.

## What IS reliable — `axis_correspondence_016B_to_016DJ.csv`
The two calibrations share their platform maps: **31 two-dimensional maps are
axis-identical** between 016B and 016DJ (22 map one-to-one, 9 ambiguous because the
same RPM×load axis is shared by several maps). This is a verified address↔address
cross-reference — but the matched maps are the unnamed platform ones, so it carries
geometry, not functional names.

## The only reliable way to name the 016DJ maps
Functional identification from the 016DJ code itself: in the Ghidra project, each map
is read by a `KF_lookup2d`/`KL_lookup1d` call whose result is written to a physical
`DAT_*` variable (e.g. the caller samples show inputs = rpm, load → output = injection
quantity / boost / SOI). Decompiling the specific caller tells you what the map
controls, definitively, per map. That is manual per-map work but needs no hardware
and no grey-market A2L. The alternative is a genuine licensed A2L/DAMOS for
03G906016DJ / 6250 / 1037371259.

## Net state of the whole project
- Complete matched plaintext image (ext+int+EEPROM) reconstructed & linked in Ghidra.
- Interpolation primitives named; descriptor format proven.
- 124 firmware-confirmed maps catalogued (46 2D + 78 1D) with axes.
- 31 verified 016B↔016DJ geometric correspondences.
- Functional names: not projectable automatically; obtainable per-map from the code
  or from a licensed A2L.
