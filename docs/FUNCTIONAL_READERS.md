# Functional index of calibration-read functions (project A, 03G906016DJ)

Derived from the Ghidra decompiles of 45 `KF_lookup2d`/`KL_lookup1d` callers
(`map_reader_functions.c`). Each function reads one or more maps/curves and
writes the result to a RAM variable (`DAT_*`). Without an A2L the exact physical
name of each cannot be stated with certainty, so these are the code-level facts,
not guessed labels.

| function | size | 2D maps | 1D curves | writes (RAM outputs) |
|---|---|---|---|---|
| `FUN_833998` | 308 | 3 | 6 | 0x003faec6, 0x00403ece |
| `FUN_849898` | 380 | 3 | 2 | 0x00401262, 0x00401264, 0x0040126a, 0x00401268, 0x003fae0e |
| `FUN_040804` | 196 | 0 | 4 | 0x003fac48, 0x003fac48 |
| `FUN_0408c8` | 280 | 0 | 4 | 0x003fac48, 0x003fac48, 0x003fac48 |
| `FUN_819160` | 304 | 0 | 4 | 0x00401254, 0x003fa90f, 0x00401255, 0x003fa90f, 0x00401255 |
| `FUN_8317a4` | 152 | 3 | 0 | 0x003fac82, 0x00400cca, 0x00400ccc, 0x00400cce |
| `FUN_83183c` | 184 | 3 | 0 | 0x003fa77f, 0x003fac84, 0x003fac84, 0x00400cc4, 0x00400cc6 |
| `FUN_825c14` | 208 | 1 | 2 | 0x0040012c, 0x0040011e, 0x0040011c |
| `FUN_830478` | 224 | 2 | 1 | — |
| `FUN_830614` | 228 | 2 | 1 | — |
| `FUN_8269c0` | 228 | 1 | 2 | 0x00400148, 0x00400140, 0x00400142, 0x00400136, 0x00400134 |
| `FUN_0379d0` | 268 | 2 | 1 | — |
| `FUN_054f78` | 324 | 2 | 1 | 0x003fae98, 0x003fae98, 0x00401384, 0x00401380, 0x00401382 |
| `FUN_054e24` | 340 | 2 | 1 | 0x003fae92, 0x003fae90, 0x003fae92, 0x0040137e, 0x003fae96 |
| `FUN_82ee70` | 160 | 1 | 1 | 0x003fa85e, 0x00400e22, 0x003facd2, 0x003facd4, 0x00400e1e |
| `FUN_04bba8` | 176 | 0 | 2 | — |
| `FUN_830558` | 188 | 2 | 0 | 0x003fa87e, 0x00400fc8, 0x00400fc8, 0x00402dcc, 0x003fad38 |
| `FUN_809718` | 260 | 2 | 0 | 0x00402080, 0x0040208a, 0x0040208c, 0x00402082, 0x0040208b |
| `FUN_03cbe0` | 260 | 0 | 2 | 0x003fcb9f, 0x003fe45c, 0x003fe460, 0x003fcbd0, 0x003fcbd2 |
| `FUN_8333d4` | 288 | 2 | 0 | 0x003fa77c, 0x003fa77c, 0x003fa77c, 0x00403b52, 0x00403b5c |
| `FUN_039758` | 304 | 0 | 2 | 0x003fca34, 0x003faaae, 0x00400334, 0x00400332 |
| `FUN_8468d0` | 320 | 0 | 2 | 0x0040126c, 0x0040126e, 0x00401270, 0x00401272, 0x003fa7d9 |
| `FUN_811eb0` | 336 | 2 | 0 | 0x003fac98, 0x00400d0a, 0x00400d04, 0x00400d06, 0x00400d08 |
| `FUN_82ef14` | 344 | 2 | 0 | 0x003fa7d9, 0x003fa7d9, 0x003fa9aa, 0x00402e53, 0x00402e53 |
| `FUN_830444` | 52 | 0 | 1 | 0x003facec |
| `FUN_819ee4` | 76 | 0 | 1 | 0x003fad40, 0x003fad40 |
| `FUN_05b994` | 84 | 0 | 1 | — |
| `FUN_8315ac` | 92 | 1 | 0 | 0x003fa842, 0x003fac76 |
| `FUN_04e83c` | 108 | 1 | 0 | 0x00401098 |
| `FUN_831710` | 148 | 1 | 0 | 0x003fa961, 0x003fa961, 0x003fac80 |
| `FUN_82bb10` | 156 | 0 | 1 | 0x003fa95b, 0x004013da |
| `FUN_8314fc` | 164 | 0 | 1 | 0x003fae56, 0x00401334, 0x003fae54 |
| `FUN_82ac80` | 176 | 0 | 1 | 0x003fa95b, 0x00401412 |
| `FUN_8048e4` | 180 | 1 | 0 | 0x003face8, 0x003fb10c, 0x003fb10e, 0x003fb110, 0x003fb112 |
| `FUN_0398e0` | 180 | 1 | 0 | — |
| `FUN_804998` | 180 | 1 | 0 | 0x003face8, 0x003fb10c, 0x003fb10e, 0x003fb110, 0x003fb112 |
| `FUN_039da4` | 200 | 1 | 0 | 0x003faaa0, 0x003faab2, 0x003faab2, 0x003faab8, 0x00400342 |
| `FUN_05e160` | 208 | 0 | 1 | — |
| `FUN_04c220` | 220 | 0 | 1 | 0x003fd242, 0x003fb2aa, 0x003fd228 |
| `FUN_8493e0` | 240 | 0 | 1 | 0x004001c0, 0x004001c2, 0x003fad18, 0x003faa76, 0x004001c2 |
| `FUN_83db34` | 264 | 0 | 1 | 0x003fa8ca, 0x003faea6, 0x004013a8, 0x004013a6 |
| `FUN_826164` | 288 | 0 | 1 | 0x0040326e, 0x00400118, 0x0040326e, 0x00403272, 0x00403273 |
| `FUN_051620` | 312 | 0 | 1 | — |
| `FUN_839c34` | 332 | 0 | 1 | — |
| `FUN_039a34` | 416 | 1 | 0 | 0x003faaa0, 0x003faab4, 0x00400336, 0x00400336, 0x003faab4 |

Common input variables seen as map axes: `DAT_003fb326` (feeds many maps — a
primary axis such as engine speed), `DAT_003face4/face8`, `DAT_003faa00`. Map
dimensions follow the Bosch catalogue (e.g. 16x12 smoke limiter, 15x19 injector
duration, 16x14 start-of-injection) — see the WinOLS type list in the maps folder.
