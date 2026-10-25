# Named maps on the Octavia (03G906016DJ) — 139 via A2L axis-match

Real functional names are now on the Octavia's maps, derived reliably — not guessed.

## Method
A user-supplied EDC16U31 1.9 TDI PD A2L (ASAM MCD-2, Golf `74kw.a2l`) was parsed for its
MAP/CURVE characteristics: name, German description, and axis break-points (1-D inline;
2-D via shared AXIS_PTS). Each characteristic's axis values were read from its matching
binary, giving an **axis signature** per map. The Octavia 016DJ maps were scanned (inline
Bosch `[nx][ny][X][Y][data]`) for their axis signatures, and bound **only on exact axis
equality and a unique match** — so every name is validated by identical breakpoints, not
by position or guess.

## Result
- **139** Octavia maps named (`maps/named_016DJ_from_A2L.csv`): address, type, name, German description.
- 35 of these are inside the 124 pointer-confirmed catalogue (shown in the dashboard's
  "Navn (A2L)" column, map viewer and chain-sim); the rest are additional 1-D/2-D tables.

## Note
Names come from a sibling-variant A2L, matched by exact axis identity, so they are highly
reliable for the matched maps. The exact-family **03G906016AA DAMOS** (still password-
protected) would extend coverage further; more A2Ls in the collection (m85dk000, A3
038906016H) can be run the same way to raise the count.

## Physical scaling (units)
`maps/named_016DJ_from_A2L.csv` now also carries the A2L `COMPU_METHOD` for each matched
map, as three extra columns: **unit, factor, offset**. The raw u16 table value converts to
a physical quantity with `physical = factor · raw + offset` (158/158 named maps resolved).
Units seen include mg/hub, mg/Hub Luft, °C, %, Nm, ms, rpm, hPa, mV and dimensionless `[-]`.
The dashboard **simulator** and **chain-sim** apply this live: for a named map the output is
shown as the physical value with its unit, with the raw u16 in parentheses
(e.g. `4.35 mg/hub (435 rå)`).
