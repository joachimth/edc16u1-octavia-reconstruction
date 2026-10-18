# Ghidra post-import script for a 1 MB EDC16U1 external-flash dump (MPC556, PPC BE32).
# Import the .bin first as: Format=Raw Binary, Language=PowerPC:BE:32:default,
# Options -> Base Address = 0x800000. Then run this from the Script Manager.
#
# It adds the RAM / peripheral blocks and sets r13 (small-data base) so that
# global accesses decompile with cross-references instead of *(r13 + 0x1234).
#@category EDC16
from ghidra.program.model.address import AddressSet
from ghidra.program.model.lang import Register

def mk(name, start, length, read=True, write=True, exe=False, vol=False):
    sp=currentProgram.getAddressFactory().getDefaultAddressSpace()
    addr=sp.getAddress(start)
    mem=currentProgram.getMemory()
    try:
        b=mem.createUninitializedBlock(name, addr, length, False)
        b.setRead(read); b.setWrite(write); b.setExecute(exe); b.setVolatile(vol)
        print("block %s @ 0x%X (0x%X)" % (name, start, length))
    except Exception as e:
        print("skip %s: %s" % (name, e))

# internal SRAM + work RAM (uninitialised; fill from a BDM read if you have one)
mk("sram_3F9800", 0x3F9800, 0x6800)
mk("ram_400000",  0x400000, 0x8000)
mk("extram_4FE000",0x4FE000,0x2000)
# volatile peripheral windows (MPC555, ISB=0)
mk("usiu_2FC000", 0x2FC000, 0x880, exe=False, vol=True)
mk("imb3_300000", 0x300000, 0x8000, exe=False, vol=True)

# small-data base r13 (confirm against startup code: lis r13,0x40 / addi r13,r13,0x17F0)
try:
    r13=currentProgram.getRegister("r13")
    ctx=currentProgram.getProgramContext()
    whole=AddressSet(currentProgram.getMemory())
    from java.math import BigInteger
    ctx.setValue(r13, whole.getMinAddress(), whole.getMaxAddress(),
                 BigInteger.valueOf(0x4017F0))
    print("set r13 = 0x4017F0 over whole program")
except Exception as e:
    print("r13 set failed: %s" % e)

print("done. Disassemble from pointer-table targets, not from 0x800000 (header bytes).")
