#@category EDC16
import os
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
OUT="/tmp/claude-0/-home-claude/c41a0a5e-ea8d-5325-97cf-9e69a91b4034/scratchpad/ghidra/export_a"
try: os.makedirs(OUT)
except: pass
fm=currentProgram.getFunctionManager(); li=currentProgram.getListing()
rm=currentProgram.getReferenceManager()
sp=currentProgram.getAddressFactory().getDefaultAddressSpace()
def A(x): return sp.getAddress(x)
def region(off): return "internal" if off<0x800000 else "external"

funcs=list(fm.getFunctions(True))
intern=[f for f in funcs if f.getEntryPoint().getOffset()<0x70000]
extern=[f for f in funcs if f.getEntryPoint().getOffset()>=0x800000]
# cross-region calls
x2i=i2x=0
for f in funcs:
    fe=f.getEntryPoint().getOffset()
    for r in rm.getReferencesFrom(f.getEntryPoint()): pass
# count call references crossing regions
refmgr=rm
cross_xi=0; cross_ix=0
it=rm.getReferenceIterator(A(0x0))
# simpler: iterate all instructions' flow refs
insit=li.getInstructions(True)
while insit.hasNext():
    ins=insit.next(); fa=ins.getAddress().getOffset()
    for r in ins.getReferencesFrom():
        if r.getReferenceType().isCall() or r.getReferenceType().isJump():
            ta=r.getToAddress().getOffset()
            if fa>=0x800000 and ta<0x70000: cross_xi+=1
            elif fa<0x70000 and ta>=0x800000: cross_ix+=1

with open(OUT+"/summary.txt","w") as f:
    f.write("instructions: %d\n"%li.getNumInstructions())
    f.write("functions total: %d\n"%len(funcs))
    f.write("  internal (0x0-0x6FFFF): %d\n"%len(intern))
    f.write("  external (0x800000+):   %d\n"%len(extern))
    f.write("cross-region flow refs external->internal: %d\n"%cross_xi)
    f.write("cross-region flow refs internal->external: %d\n"%cross_ix)

with open(OUT+"/functions.csv","w") as f:
    f.write("entry_cpu,region,name,size,xrefs\n")
    for fn in sorted(funcs,key=lambda x:x.getEntryPoint().getOffset()):
        e=fn.getEntryPoint().getOffset()
        f.write("0x%06X,%s,%s,%d,%d\n"%(e,region(e),fn.getName(),fn.getBody().getNumAddresses(),rm.getReferenceCountTo(fn.getEntryPoint())))

# decompile reset vector + startup (function containing 0x20C) + a couple internal funcs
di=DecompInterface(); di.openProgram(currentProgram); mon=ConsoleTaskMonitor()
targets=[A(0x0)]
f20c=fm.getFunctionContaining(A(0x20C))
if f20c: targets.append(f20c.getEntryPoint())
with open(OUT+"/decompiled_startup.c","w") as f:
    f.write("// Internal-flash boot/startup (reset vector + r13 setup @0x20C)\n")
    seen=set()
    for ep in targets:
        if ep.getOffset() in seen: continue
        seen.add(ep.getOffset())
        fn=fm.getFunctionContaining(ep) or fm.getFunctionAt(ep)
        if not fn: continue
        try:
            res=di.decompileFunction(fn,60,mon)
            if res and res.decompileCompleted():
                f.write("\n// ==== %s @0x%s ====\n"%(fn.getName(),fn.getEntryPoint()))
                f.write(res.getDecompiledFunction().getC())
        except Exception as e: f.write("// decomp err %s\n"%e)
print("EXPORT_A DONE funcs=%d internal=%d external=%d x->i=%d i->x=%d"%(len(funcs),len(intern),len(extern),cross_xi,cross_ix))
