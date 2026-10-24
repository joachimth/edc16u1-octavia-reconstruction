#!/usr/bin/env python3
"""
EDC16 (Bosch VAG: EDC16U1 / U31 / U34) flash checksum — verify & correct.

Independent Python implementation of the region/checksum scheme. The algorithm
(signature, region-descriptor layout and the sum invariant) was reverse-engineered
and documented by the GPL-3.0 project ZedSuite (github.com/LeZed97/ZedSuite);
this is a clean-room reimplementation written for this repo, credited accordingly.

Scheme (verified byte-exact on 016DJ, 016B stock+stage1, 016DG):
  * Each protected region carries the 8-byte signature FA DE CA FE CA FE AF FE
    at  region_start + 0x3C.
  * The two big-endian dwords immediately BEFORE the signature are the region
    start and end ECU addresses (end inclusive). The memory base (0x800000 on a
    1 MB dump) is implied by the signature sitting at start+0x3C.
  * Regions start on a 0x100 boundary and are a multiple of 4 bytes long.
  * The region's LAST dword (at end+1-4) is the checksum word; the sum (mod 2^32)
    of all big-endian dwords across the region, that word included, must equal
    the constant 0xD01FE500. Correction absorbs the delta into that word.

Usage:
  python3 edc16_checksum.py verify  flash.bin
  python3 edc16_checksum.py correct flash.bin fixed.bin
"""
import sys, struct

MAGIC   = bytes([0xFA,0xDE,0xCA,0xFE,0xCA,0xFE,0xAF,0xFE])
TARGET  = 0xD01FE500
ALIGN   = 0x100
MAGIC_OFFSET = 0x3C

def u32(d,o): return struct.unpack('>I', d[o:o+4])[0]

def find_regions(d):
    out=[]; n=len(d); i=8
    while i+8 <= n:
        if d[i:i+8]==MAGIC:
            sa=u32(d,i-8); ea=u32(d,i-4)
            base=sa-(i-MAGIC_OFFSET); start=sa-base; end=ea-base
            if (0<=start<end<n and start%ALIGN==0 and (end+1)%ALIGN==0
                    and (end+1-start)%4==0):
                out.append((start,end,base))
        i+=1
    return out

def region_sum(d,start,end):
    s=0
    for o in range(start,end+1,4): s=(s+u32(d,o))&0xffffffff
    return s

def verify(path):
    d=open(path,'rb').read(); rs=find_regions(d); ok=True
    print("%s: %d region(s)"%(path,len(rs)))
    for start,end,base in rs:
        s=region_sum(d,start,end); good=(s==TARGET); ok&=good
        print("  cpu 0x%06X-0x%06X  sum=0x%08X  %s"%(base+start,base+end,s,"OK" if good else "BAD"))
    return ok

def correct(path,out):
    d=bytearray(open(path,'rb').read())
    for start,end,base in find_regions(d):
        co=end+1-4
        s=region_sum(d,start,end)
        delta=(TARGET-s)&0xffffffff
        new=(u32(d,co)+delta)&0xffffffff
        struct.pack_into('>I',d,co,new)
    open(out,'wb').write(d)
    print("wrote",out); verify(out)

if __name__=="__main__":
    if len(sys.argv)>=3 and sys.argv[1]=="verify": sys.exit(0 if verify(sys.argv[2]) else 1)
    elif len(sys.argv)>=4 and sys.argv[1]=="correct": correct(sys.argv[2],sys.argv[3])
    else: print(__doc__)
