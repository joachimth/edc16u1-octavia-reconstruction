# EDC16 flash checksum — CONFIRMED

The checksum scheme that `docs/RECONSTRUCTION*.md` left as an open question is now
pinned down and **verified byte-exact on the real files** (Octavia 016DJ, 016B stock +
stage-1, Seat Altea 016DG — 4/4, every region).

Algorithm credit: the signature, region-descriptor layout and the sum invariant were
reverse-engineered and documented by the GPL-3.0 project **ZedSuite**
(github.com/LeZed97/ZedSuite). `tools/edc16_checksum.py` is an independent
reimplementation for this repo.

## Scheme
- Each protected region carries the 8-byte signature **`FA DE CA FE CA FE AF FE`** at
  `region_start + 0x3C`.
- The two big-endian dwords immediately **before** the signature are the region's
  **start** and **end** ECU addresses (end inclusive). The memory base (0x800000 on a
  1 MB dump) is implied by the signature living at `start + 0x3C`.
- Regions begin on a `0x100` boundary and are a multiple of 4 bytes long.
- The region's **last** dword (`end+1-4`) is the **checksum word**. The sum (mod 2³²)
  of every big-endian dword across the region — that word included — must equal the
  constant **`0xD01FE500`**. A corrector absorbs the delta into that word.

## Your Octavia (03G906016DJ) — verified
| Region | CPU range | Checksum word (file offset) | Sum | Status |
|---|---|---|---|---|
| 1 ASW / code | `0x800000–0x87FFFF` | `0x7FFFC` | `0xD01FE500` | ✓ |
| 2 data block | `0x880000–0x8CFFFF` | `0xCFFFC` | `0xD01FE500` | ✓ |
| 3 calibration | `0x8D0000–0x8FDFFF` | `0xFDFFC` | `0xD01FE500` | ✓ |

This matches the block layout derived earlier and the stage-1 diff (which touched the
`0xCFF74…` and `0xFDF78…` region tails — exactly the checksum words).

## Tool
```
python3 tools/edc16_checksum.py verify  flash.bin
python3 tools/edc16_checksum.py correct flash.bin fixed.bin
```
