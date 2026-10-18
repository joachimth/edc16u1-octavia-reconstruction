
// ==== caller 0x8315AC size=92 callsite=0x8315DC ====

void FUN_008315ac(void)

{
  undefined4 uVar1;
  int unaff_r15;
  int iVar2;
  
  if (DAT_003fa842 == '\x01') {
    iVar2 = *(int *)(unaff_r15 + 0x25c);
    uVar1 = KF_lookup2d((int)DAT_003faf7a,(int)DAT_003faf9a,iVar2,&DAT_00403cb4);
    DAT_003fac76 = FUN_00059b84(uVar1,iVar2 + 0xa4,&DAT_00403cb0,20000);
  }
  return;
}


// ==== caller 0x04E83C size=108 callsite=0x04E860 ====

int FUN_0004e83c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  short sVar2;
  
  uVar1 = KF_lookup2d(param_1,param_2,&DAT_003ffd38,&DAT_003fd508);
  DAT_00401098 = sat_div16(uVar1,10);
  sVar2 = FUN_00059860((int)DAT_00401098,param_3,0xd);
  *param_4 = 0;
  return (int)sVar2;
}


// ==== caller 0x831710 size=148 callsite=0x831754 ====

void FUN_00831710(void)

{
  undefined4 uVar1;
  short sVar2;
  int unaff_r15;
  int iVar3;
  
  if ((DAT_003fa961 == '\0') || (sVar2 = DAT_003faa02, DAT_003fa961 == -1)) {
    sVar2 = DAT_003faa00;
  }
  iVar3 = *(int *)(unaff_r15 + 0x274);
  uVar1 = KF_lookup2d((int)sVar2,(int)DAT_003fb348,iVar3,&DAT_00403bd8);
  sVar2 = sat_add16(uVar1,(int)DAT_003faa3c);
  if (*(char *)(iVar3 + 0xf4) == '\0') {
    sVar2 = sat_add16((int)sVar2,(int)DAT_003faf6a);
    sVar2 = sat_add16((int)sVar2,(int)DAT_003fac76);
  }
  DAT_003fac80 = sVar2;
  return;
}


// ==== caller 0x8317A4 size=152 callsite=0x8317C8 ====

void FUN_008317a4(void)

{
  undefined4 uVar1;
  short sVar2;
  int unaff_r15;
  int iVar3;
  
  iVar3 = *(int *)(unaff_r15 + 0x278);
  uVar1 = KF_lookup2d((int)DAT_003faa00,(int)DAT_003fb342,iVar3,&DAT_003fcf40);
  sVar2 = KF_lookup2d(uVar1,(int)DAT_003faf5c,iVar3 + 0xf4,&DAT_003fcf42);
  iVar3 = KF_lookup2d((int)DAT_003faf4a,(int)sVar2,iVar3 + 0x1e8,&DAT_003fcf44);
  DAT_003fac82 = sat_div16(DAT_003fac80 * iVar3,0x2000);
  DAT_00400cca = (short)uVar1;
  DAT_00400ccc = sVar2;
  DAT_00400cce = (short)iVar3;
  return;
}


// ==== caller 0x8317A4 size=152 callsite=0x8317DC ====

void FUN_008317a4(void)

{
  undefined4 uVar1;
  short sVar2;
  int unaff_r15;
  int iVar3;
  
  iVar3 = *(int *)(unaff_r15 + 0x278);
  uVar1 = KF_lookup2d((int)DAT_003faa00,(int)DAT_003fb342,iVar3,&DAT_003fcf40);
  sVar2 = KF_lookup2d(uVar1,(int)DAT_003faf5c,iVar3 + 0xf4,&DAT_003fcf42);
  iVar3 = KF_lookup2d((int)DAT_003faf4a,(int)sVar2,iVar3 + 0x1e8,&DAT_003fcf44);
  DAT_003fac82 = sat_div16(DAT_003fac80 * iVar3,0x2000);
  DAT_00400cca = (short)uVar1;
  DAT_00400ccc = sVar2;
  DAT_00400cce = (short)iVar3;
  return;
}

