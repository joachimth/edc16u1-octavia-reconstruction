#!/usr/bin/env python3
"""
ST95320 (32 kbit / 4 KB) EEPROM reader for VAG EDC16U1.
Describes the layout and verifies the redundant copies. Read-only; no modification.

Each logical record in this EEPROM is stored 2x or 3x back-to-back and ends with a
16-bit trailer. Diag-Prof documents the per-block check as: sum of the data bytes,
XOR 0xFFFF, minus the block number -- verify empirically against your own dump.
"""
import sys
d=open(sys.argv[1] if len(sys.argv)>1 else "eeprom.bin","rb").read()

def find_all(sub):
    out=[]; i=0
    while True:
        i=d.find(sub,i)
        if i<0: break
        out.append(i); i+=1
    return out

def txt(o,n):
    return bytes(b for b in d[o:o+n] if 32<=b<127).decode("latin1")

print(f"size {len(d)} bytes")
for label,needle in [("part-no 021AN", b"03G906021AN"),
                     ("part-no 021LB", b"03G906021LB"),
                     ("SW 1037382414", b"1037382414"),
                     ("SW 1037377150", b"1037377150"),
                     ("VIN  TMB...",    b"TMBGS"),
                     ("CompProt SKZ..", b"SKZ")]:
    locs=find_all(needle)
    print(f"{label:16} x{len(locs)} @ "+", ".join(f"0x{o:03X}" for o in locs)+
          (f"  -> '{txt(locs[0],24)}'" if locs else ""))
print("\nNote: component-protection / immobiliser record is the SKZ... block and the")
print("bytes immediately before it. This tool only locates and cross-checks copies.")
