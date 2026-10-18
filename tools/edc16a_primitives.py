#@category EDC16
import sys
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
from ghidra.program.model.symbol import SourceType
sp=currentProgram.getAddressFactory().getDefaultAddressSpace()
def A(x): return sp.getAddress(x)
fm=currentProgram.getFunctionManager(); rm=currentProgram.getReferenceManager()
st=currentProgram.getSymbolTable()
OUT="/tmp/claude-0/-home-claude/c41a0a5e-ea8d-5325-97cf-9e69a91b4034/scratchpad/ghidra/export_a"
di=DecompInterface(); di.openProgram(currentProgram); mon=ConsoleTaskMonitor()

def callcount(ep):
    return sum(1 for r in rm.getReferencesTo(A(ep)) if r.getReferenceType().isCall())

prims={0x05A074:"KL_lookup1d",0x05A16C:"KF_lookup2d",0x05967C:"sat_add16",
       0x059800:"sat_div16",0x059718:"fp_helper_59718",0x0597AC:"fp_helper_597ac",
       0x059794:"fp_mul_597 94".replace(' ',''),0x0596FC:"fp_helper_596fc"}
# rename + report
rep=open(OUT+"/primitives.txt","w")
for ep,nm in prims.items():
    fn=fm.getFunctionAt(A(ep))
    if fn:
        try: fn.setName(nm,SourceType.USER_DEFINED)
        except: pass
    rep.write("0x%06X  %-16s  calls=%d\n"%(ep,nm,callcount(ep)))
rep.flush()
# decompile the two interpolators in full
with open(OUT+"/interpolators.c","w") as f:
    for ep in (0x05A074,0x05A16C):
        fn=fm.getFunctionAt(A(ep))
        res=di.decompileFunction(fn,60,mon)
        f.write("\n// ==== %s @0x%06X calls=%d ====\n"%(fn.getName(),ep,callcount(ep)))
        if res and res.decompileCompleted(): f.write(res.getDecompiledFunction().getC())
# total map-read call sites
tot=callcount(0x05A074)+callcount(0x05A16C)
rep.write("\nTOTAL interpolation call sites (1d+2d): %d\n"%tot); rep.close()
sys.stdout.write("PRIMS DONE 1d_calls=%d 2d_calls=%d total=%d\n"%(callcount(0x05A074),callcount(0x05A16C),tot)); sys.stdout.flush()
