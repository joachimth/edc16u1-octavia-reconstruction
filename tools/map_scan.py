#!/usr/bin/env python3
"""
EDC16U1 / Bosch calibration-map scanner.
Bosch EDC16 map layout:  [nx:u16][ny:u16][X axis: nx*u16][Y axis: ny*u16][data: nx*ny*u16]
All values 16-bit big-endian. A 1-D curve has nx==1 or ny==1.

Usage:  python3 map_scan.py octavia.bin --base 0x800000 --start 0xD0000 --end 0xFDFFF --csv maps.csv
Raw values only; physical scaling (°CA, mg/stk, bar ...) lives in the A2L/DAMOS.
"""
import struct, argparse, csv, sys

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument("binary")
    ap.add_argument("--base", type=lambda x:int(x,0), default=0x800000,
                    help="CPU address that file offset 0 maps to")
    ap.add_argument("--start", type=lambda x:int(x,0), default=0xD0000)
    ap.add_argument("--end",   type=lambda x:int(x,0), default=0xFDFFF)
    ap.add_argument("--min-axis", type=int, default=1)
    ap.add_argument("--max-axis", type=int, default=31)
    ap.add_argument("--max-size", type=int, default=800)
    ap.add_argument("--csv")
    a=ap.parse_args()
    d=open(a.binary,"rb").read()
    u16=lambda o:struct.unpack(">H",d[o:o+2])[0]
    rows=[]; o=a.start
    end=min(a.end, len(d)-1)
    while o < end-8:
        nx=u16(o); ny=u16(o+2)
        if a.min_axis<=nx<=a.max_axis and a.min_axis<=ny<=a.max_axis:
            size=4+2*nx+2*ny+2*nx*ny
            if size<a.max_size and o+size<=end:
                xs=[u16(o+4+2*i) for i in range(nx)]
                ys=[u16(o+4+2*nx+2*j) for j in range(ny)]
                mx=all(xs[i]<xs[i+1] for i in range(nx-1)) if nx>1 else True
                my=all(ys[i]<ys[i+1] for i in range(ny-1)) if ny>1 else True
                if (mx and my) and (nx>1 or ny>1):
                    rows.append((o,a.base+o,nx,ny,size)); o+=size; continue
        o+=2
    print(f"{len(rows)} candidate maps in 0x{a.start:X}..0x{a.end:X}")
    for o,c,nx,ny,size in rows:
        print(f"  file 0x{o:06X}  cpu 0x{c:06X}  {nx}x{ny}  {size} B")
    if a.csv:
        with open(a.csv,"w",newline="") as f:
            w=csv.writer(f); w.writerow(["file_offset","cpu_addr","nx","ny","size"])
            for o,c,nx,ny,size in rows:
                w.writerow([f"0x{o:06X}",f"0x{c:06X}",nx,ny,size])
        print("wrote",a.csv)

if __name__=="__main__": main()
