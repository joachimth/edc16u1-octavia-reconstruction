#@category EDC16
import csv,os
from ghidra.program.model.symbol import SourceType
from ghidra.program.model.data import PointerDataType
sp=currentProgram.getAddressFactory().getDefaultAddressSpace()
def A(x): return sp.getAddress(x)
mem=currentProgram.getMemory(); li=currentProgram.getListing()
rm=currentProgram.getReferenceManager(); fm=currentProgram.getFunctionManager()
OUT="/tmp/claude-0/-home-claude/c41a0a5e-ea8d-5325-97cf-9e69a91b4034/scratchpad/ghidra/export_a"
MAPS="/tmp/claude-0/-home-claude/c41a0a5e-ea8d-5325-97cf-9e69a91b4034/scratchpad/fw/out/edc16u1_maps.csv"

# octavia map list = header starts (nx,ny,axes,data). cpu_addr_hex column.
maps=[]
for r in csv.DictReader(open(MAPS)):
    cpu=int(r['cpu_addr_hex'],16); maps.append((cpu,r['dims']))
mapset={c for c,_ in maps}

# 1) direct code references to each map header (constant-prop may have made these)
def code_refs_to(cpu):
    out=[]
    for ref in rm.getReferencesTo(A(cpu)):
        fa=ref.getFromAddress()
        if fa.getOffset()>=0x800000 or fa.getOffset()<0x70000:
            fn=fm.getFunctionContaining(fa)
            out.append((fa.getOffset(),fn.getName() if fn else '',str(ref.getReferenceType())))
    return out

# 2) build block-0 pointer table and index: pointer_value -> [slot_addr]
def rd32(o):
    return (mem.getByte(A(o))&0xff)<<24|(mem.getByte(A(o+1))&0xff)<<16|(mem.getByte(A(o+2))&0xff)<<8|(mem.getByte(A(o+3))&0xff)
slot_of=dict()  # target -> list of slot cpu addrs
for base in (0x800058,0x880058,0x8D0058):
    o=base; end=base+0x4000
    while o<end:
        try: v=rd32(o)
        except: break
        if 0x800000<=v<0x900000:
            slot_of.setdefault(v,[]).append(o)
        o+=4
# code refs to a given slot addr
def code_refs_to_slot(slotcpu):
    r=[]
    for ref in rm.getReferencesTo(A(slotcpu)):
        fn=fm.getFunctionContaining(ref.getFromAddress())
        r.append(fn.getName() if fn else ('0x%06X'%ref.getFromAddress().getOffset()))
    return r

labeled=0; direct=0; viaslot=0
rows=[]
for cpu,dims in maps:
    try: currentProgram.getSymbolTable().createLabel(A(cpu),"MAP_%s_%06X"%(dims,cpu),SourceType.USER_DEFINED); labeled+=1
    except: pass
    dref=code_refs_to(cpu)
    slots=slot_of.get(cpu,[])
    readers=set(fn for _,fn,_ in dref if fn)
    sreaders=set()
    for s in slots:
        for rn in code_refs_to_slot(s): sreaders.add(rn)
    if dref: direct+=1
    if slots: viaslot+=1
    rows.append((cpu,dims,len(dref),';'.join(sorted(readers)[:6]),
                 ';'.join('0x%06X'%s for s in slots),';'.join(sorted(sreaders)[:6])))

with open(OUT+"/map_readers_projectA.csv","w") as f:
    f.write("map_cpu,dims,direct_coderefs,direct_reader_funcs,pointer_slots,slot_reader_funcs\n")
    for cpu,dims,nd,rf,sl,sr in rows:
        f.write("0x%06X,%s,%d,%s,%s,%s\n"%(cpu,dims,nd,rf,sl,sr))
print("MAPSA labeled=%d direct_ref=%d via_pointer_slot=%d total=%d"%(labeled,direct,viaslot,len(maps)))
