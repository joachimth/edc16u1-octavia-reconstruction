#@category EDC16
from ghidra.program.model.address import AddressSet
from java.math import BigInteger
from java.io import FileInputStream
mem=currentProgram.getMemory()
sp=currentProgram.getAddressFactory().getDefaultAddressSpace()
def A(x): return sp.getAddress(x)
BASE=0x800000
MIC="/tmp/claude-0/-home-claude/c41a0a5e-ea8d-5325-97cf-9e69a91b4034/scratchpad/fw/set3/Mic.bin"

# 1) move imported external image (octavia.bin) to 0x800000
if currentProgram.getImageBase().getOffset()!=BASE:
    currentProgram.setImageBase(A(BASE),True); print("[preA] ext image base -> 0x800000")

# 2) add INTERNAL MPC555 flash at 0x0 from Mic.bin (first 0x70000 bytes)
try:
    fis=FileInputStream(MIC)
    b=mem.createInitializedBlock("internal_flash",A(0x0),fis,0x70000,monitor,False)
    b.setRead(True);b.setWrite(False);b.setExecute(True)
    fis.close(); print("[preA] internal_flash @0x0 len 0x70000 loaded from Mic.bin")
except Exception as e:
    print("[preA] internal load FAILED:",e)

# 3) RAM + peripherals
def mk(n,s,l,vol=False,ex=False):
    try:
        bl=mem.createUninitializedBlock(n,A(s),l,False)
        bl.setRead(True);bl.setWrite(True);bl.setExecute(ex);bl.setVolatile(vol)
    except Exception as e: print("  skip",n,e)
mk("sram_3F9800",0x3F9800,0x6800); mk("ram_400000",0x400000,0x8000)
mk("extram_4FE000",0x4FE000,0x2000); mk("usiu_2FC000",0x2FC000,0x880,True)
mk("imb3_300000",0x300000,0x8000,True)

# 4) r13 (confirmed from startup: lis r13,0x40; addi r13,r13,0x17F0 @0x20C)
try:
    r13=currentProgram.getRegister("r13"); ctx=currentProgram.getProgramContext()
    w=AddressSet(mem); ctx.setValue(r13,w.getMinAddress(),w.getMaxAddress(),BigInteger.valueOf(0x4017F0))
    print("[preA] r13=0x4017F0 set")
except Exception as e: print("  r13",e)

# 5) seed entry at reset vector 0x0
from ghidra.app.cmd.disassemble import DisassembleCommand
from ghidra.app.cmd.function import CreateFunctionCmd
try:
    DisassembleCommand(A(0x0),None,True).applyTo(currentProgram,monitor)
    CreateFunctionCmd(A(0x0)).applyTo(currentProgram,monitor)
    currentProgram.getSymbolTable().createLabel(A(0x0),"reset_vector",ghidra.program.model.symbol.SourceType.USER_DEFINED)
    print("[preA] reset_vector @0x0 seeded")
except Exception as e: print("  seed",e)
