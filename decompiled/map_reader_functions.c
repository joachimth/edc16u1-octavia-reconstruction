
// ==== FUN_830444  (size=52) ====

void FUN_00830444(void)

{
  int unaff_r15;
  
  DAT_003facec = KL_lookup1d((int)DAT_003fb326,*(int *)(unaff_r15 + 0x2a4) + 2,&DAT_00403cb6);
  return;
}


// ==== FUN_819ee4  (size=76) ====

void FUN_00819ee4(void)

{
  int unaff_r15;
  
  if ((DAT_00401a90 & 1) == 0) {
    DAT_003fad40 = **(undefined2 **)(unaff_r15 + 0x300);
  }
  else {
    DAT_003fad40 = KL_lookup1d((int)DAT_003fad22,*(int *)(unaff_r15 + 0x300) + 2,&DAT_004025e0);
  }
  return;
}


// ==== FUN_05b994  (size=84) ====

void FUN_0005b994(int param_1,undefined2 *param_2,undefined4 param_3)

{
  undefined1 uVar2;
  undefined2 uVar1;
  
  uVar2 = FUN_0005bc64((int)(short)param_2[1],param_1);
  *(undefined1 *)(param_2 + 2) = uVar2;
  uVar1 = KL_lookup1d((int)(short)param_2[1],param_1 + 4,param_3);
  *param_2 = uVar1;
  return;
}


// ==== FUN_8315ac  (size=92) ====

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


// ==== FUN_04e83c  (size=108) ====

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


// ==== FUN_831710  (size=148) ====

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


// ==== FUN_8317a4  (size=152) ====

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


// ==== FUN_82bb10  (size=156) ====

void FUN_0082bb10(void)

{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  int unaff_r15;
  undefined4 uVar5;
  uint uVar6;
  
  if (DAT_003fa95b == '\x01') {
    uVar5 = *(undefined4 *)(unaff_r15 + 0x450);
    uVar6 = 0;
    do {
      sVar1 = (&DAT_003faeea)[uVar6];
      uVar3 = KL_lookup1d((int)sVar1,uVar5,&DAT_00403478 + uVar6);
      (&DAT_003faf1a)[uVar6] = (short)uVar3;
      uVar4 = sat_div16(1000000,uVar3);
      uVar2 = uVar6 + 1 & 0xff;
      (&DAT_003faf18)[uVar6] = uVar4;
      DAT_004013da = sVar1;
      (&DAT_003faf1e)[uVar6] = sVar1;
      uVar6 = uVar2;
    } while (uVar2 == 0);
  }
  return;
}


// ==== FUN_82ee70  (size=160) ====

void FUN_0082ee70(void)

{
  int unaff_r15;
  byte *pbVar1;
  
  pbVar1 = *(byte **)(unaff_r15 + 0x2c4);
  DAT_003fa85e = *pbVar1;
  DAT_00400e22 = (&DAT_003fb10c)[DAT_003fa85e];
  DAT_003facd2 = KF_lookup2d((int)DAT_003fb326,(int)DAT_00400e22,pbVar1 + 0x68,&DAT_003fd050);
  DAT_003facd4 = KL_lookup1d((int)DAT_003fb326,pbVar1 + 2,&DAT_003fd052);
  DAT_00400e1e = DAT_003facd2;
  FUN_0006a5b0(&DAT_008d1358,&DAT_003facd2);
  DAT_00400e20 = DAT_003facd4;
  FUN_0006a5b0(&DAT_008d1356,&DAT_003facd4);
  return;
}


// ==== FUN_8314fc  (size=164) ====

void FUN_008314fc(void)

{
  int unaff_r15;
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(unaff_r15 + 0x400);
  DAT_003fae56 = KL_lookup1d((int)DAT_003fb326,iVar1 + 8,&DAT_00401d20);
  iVar2 = (int)DAT_003fadf6;
  if (0x7ffe < iVar2) {
    iVar2 = 0x7fff;
  }
  DAT_00401334 = (undefined2)iVar2;
  FUN_0005a58c((int)DAT_003fae56,iVar2,(DAT_00401aee & 1) == 0,iVar1,&DAT_003fae58,&DAT_003fa92c,
               20000);
  if (DAT_003fae58 < iVar2) {
    iVar2 = (int)DAT_003fae58;
  }
  DAT_003fae54 = (short)iVar2;
  return;
}


// ==== FUN_82ac80  (size=176) ====

void FUN_0082ac80(void)

{
  short sVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  int iVar5;
  undefined *puVar6;
  int unaff_r15;
  int iVar7;
  uint uVar8;
  
  if (DAT_003fa95b == '\x01') {
    iVar7 = *(int *)(unaff_r15 + 0x468);
    uVar8 = 0;
    do {
      sVar1 = (&DAT_003fac80)[uVar8];
      if ((short)(&DAT_003faeee)[uVar8] < *(short *)(iVar7 + 0x54)) {
        puVar6 = &DAT_0040341d;
        iVar5 = iVar7 + 0x2a;
      }
      else {
        puVar6 = &DAT_0040341e;
        iVar5 = iVar7;
      }
      uVar3 = KL_lookup1d((int)sVar1,iVar5,puVar6);
      (&DAT_00401410)[uVar8] = (short)uVar3;
      uVar4 = FUN_00059860(uVar3,(int)(short)(&DAT_003faeee)[uVar8],0xd);
      uVar2 = uVar8 + 1 & 0xff;
      (&DAT_003faeec)[uVar8] = uVar4;
      uVar8 = uVar2;
      DAT_00401412 = sVar1;
    } while (uVar2 == 0);
  }
  return;
}


// ==== FUN_04bba8  (size=176) ====

double FUN_0004bba8(undefined8 param_1,double param_2,double param_3,undefined4 param_4,
                   undefined4 param_5,int param_6,float *param_7)

{
  float fVar1;
  undefined4 uVar2;
  short sVar4;
  int iVar3;
  int unaff_r14;
  int unaff_r15;
  undefined4 unaff_r27;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  int iVar5;
  double dVar6;
  undefined8 uVar7;
  
  uVar7 = FUN_0006d214();
  uVar2 = (undefined4)((ulonglong)uVar7 >> 0x20);
  *(undefined4 *)((int)register0x00000004 + -0x18) = unaff_r27;
  *(undefined4 *)((int)register0x00000004 + -0x14) = unaff_r28;
  *(undefined4 *)((int)register0x00000004 + -0x10) = unaff_r29;
  *(undefined4 *)((int)register0x00000004 + -0xc) = unaff_r30;
  *(undefined4 *)((int)register0x00000004 + -8) = unaff_r31;
  if ((int)uVar7 == 0) {
LAB_0004bc40:
    fVar1 = *(float *)(*(int *)(unaff_r15 + 0x2ec) + 0x1c);
  }
  else {
    iVar5 = *(int *)(unaff_r15 + 0x2ec);
    sVar4 = FUN_000595c8(uVar2,0x7fff);
    iVar3 = KL_lookup1d((int)sVar4,iVar5 + 0xa2,&DAT_003fd245);
    iVar3 = iVar3 + *(short *)(iVar5 + 0xee);
    if (iVar3 - *(short *)(iVar5 + 0xec) <= param_6) {
      if (param_6 <= iVar3 + *(short *)(iVar5 + 0xec)) goto LAB_0004bc4c;
      goto LAB_0004bc40;
    }
    sVar4 = FUN_000595c8(uVar2,0x7fff);
    KL_lookup1d((int)sVar4,iVar5,&DAT_003fd245);
    dVar6 = (double)FUN_0006cd10();
    fVar1 = (float)(dVar6 * (double)*(float *)(unaff_r14 + -0x1454));
  }
  *param_7 = fVar1;
LAB_0004bc4c:
  dVar6 = (double)FUN_0006d1b8();
  return (double)(float)(param_3 * dVar6 +
                        (double)(float)(param_2 *
                                       (double)(float)((double)*(float *)(unaff_r14 + 0x4d58) -
                                                      param_3)));
}


// ==== FUN_8048e4  (size=180) ====

void FUN_008048e4(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int unaff_r15;
  
  sVar1 = sat_add16((int)DAT_003fab2e,-(int)DAT_003faf3c);
  sVar2 = KF_lookup2d((int)DAT_003facb0,(int)sVar1,*(undefined4 *)(unaff_r15 + 0x2a8),&DAT_00401f78)
  ;
  sVar3 = DAT_003fab2e;
  if ((DAT_00401a83 & 1) != 0) {
    sVar3 = sat_add16((int)DAT_003fab2e,-(int)sVar2);
  }
  DAT_003face8 = sVar3;
  DAT_003fb10c = DAT_003fab2e;
  DAT_003fb10e = DAT_003faf3c;
  DAT_003fb110 = sVar3;
  DAT_003fb112 = DAT_003fad22;
  DAT_003fb114 = DAT_003fab30;
  DAT_00400db8 = sVar1;
  DAT_00400db6 = sVar2;
  return;
}


// ==== FUN_0398e0  (size=180) ====

undefined2
FUN_000398e0(int param_1,undefined4 param_2,int param_3,int param_4,short *param_5,short *param_6,
            undefined4 param_7)

{
  short sVar2;
  short sVar3;
  undefined4 uVar1;
  undefined2 uVar4;
  int unaff_r15;
  
  sVar2 = sat_div16(param_4 * 0xf42,param_7);
  *param_6 = sVar2;
  sVar3 = sat_add16(param_2,-param_3);
  sVar3 = sat_add16((int)sVar3,-param_4);
  sVar3 = sat_div16(sVar3 * 0xf42,param_7);
  sVar3 = sat_add16((int)sVar3,-param_1);
  *param_5 = sVar3;
  uVar1 = KF_lookup2d((int)sVar3,(int)sVar2,*(int *)(unaff_r15 + 0x120) + 0x164,&DAT_003fca44);
  uVar4 = FUN_00059650(param_1,uVar1);
  return uVar4;
}


// ==== FUN_804998  (size=180) ====

void FUN_00804998(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int unaff_r15;
  
  sVar1 = sat_add16((int)DAT_003fab2e,-(int)DAT_003faf3c);
  sVar2 = KF_lookup2d((int)DAT_003fb324,(int)sVar1,*(undefined4 *)(unaff_r15 + 0x2a8),&DAT_00401f78)
  ;
  sVar3 = DAT_003fab2e;
  if ((DAT_00401a83 & 1) != 0) {
    sVar3 = sat_add16((int)DAT_003fab2e,-(int)sVar2);
  }
  DAT_003face8 = sVar3;
  DAT_003fb10c = DAT_003fab2e;
  DAT_003fb10e = DAT_003faf3c;
  DAT_003fb110 = sVar3;
  DAT_003fb112 = DAT_003fad22;
  DAT_003fb114 = DAT_003fab30;
  DAT_00400db8 = sVar1;
  DAT_00400db6 = sVar2;
  return;
}


// ==== FUN_83183c  (size=184) ====

void FUN_0083183c(void)

{
  undefined4 uVar1;
  short sVar2;
  int unaff_r15;
  int iVar3;
  
  if (DAT_003fa77f == '\x01') {
    uVar1 = 0;
    sVar2 = 0;
    iVar3 = 0;
    DAT_003fac84 = 0;
  }
  else {
    iVar3 = *(int *)(unaff_r15 + 0x278);
    uVar1 = KF_lookup2d((int)DAT_003faa02,(int)DAT_003fb342,iVar3,&DAT_003fcf46);
    sVar2 = KF_lookup2d(uVar1,(int)DAT_003faf5e,iVar3 + 0xf4,&DAT_003fcf48);
    iVar3 = KF_lookup2d((int)DAT_003faf4c,(int)sVar2,iVar3 + 0x1e8,&DAT_003fcf4a);
    DAT_003fac84 = sat_div16(DAT_003fac82 * iVar3,0x2000);
  }
  DAT_00400cc4 = (short)uVar1;
  DAT_00400cc6 = sVar2;
  DAT_00400cc8 = (short)iVar3;
  return;
}


// ==== FUN_830558  (size=188) ====

void FUN_00830558(void)

{
  int unaff_r15;
  int iVar1;
  undefined1 local_8 [4];
  
  iVar1 = *(int *)(unaff_r15 + 0x2f4);
  FUN_008683f0(0xf,iVar1 + 0xf32,local_8);
  DAT_003fa87e = local_8[0];
  if (*(char *)(iVar1 + 0xf35) != '\0') {
    DAT_00400fc8 = DAT_003faa3c;
    if (*(char *)(iVar1 + 0xf31) != '\0') {
      DAT_00400fc8 = DAT_003faae0;
    }
    DAT_00402dcc = DAT_00400fc8;
    if (*(char *)(iVar1 + 0xf37) == '\0') {
      DAT_003fad38 = FUN_00830478();
    }
    else {
      DAT_00400fca = KF_lookup2d((int)DAT_00400fc8,(int)DAT_003fae00,iVar1 + 0x134,&DAT_00402dc2);
      DAT_00402dce = DAT_00400fca;
      DAT_003fad38 = KF_lookup2d((int)DAT_003face4,(int)DAT_00400fca,iVar1 + 0x56a,&DAT_00402dc4);
    }
  }
  return;
}


// ==== FUN_040804  (size=196) ====

void FUN_00040804(void)

{
  int iVar1;
  int unaff_r15;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  
  FUN_000635dc(0,(int)DAT_008d023a,(int)DAT_008d0238);
  iVar1 = FUN_000643d0(0,(int)DAT_008d023a);
  if (iVar1 < 0x7fff) {
    DAT_003fac48 = (short)iVar1;
  }
  else {
    DAT_003fac48 = 0x7fff;
  }
  iVar1 = *(int *)(unaff_r15 + 0x1ec);
  local_10 = KL_lookup1d((int)DAT_003fac48,iVar1 + 0x7e,&DAT_003fcdff);
  local_e = KL_lookup1d((int)DAT_003fac48,iVar1 + 0x54,&DAT_003fce00);
  local_c = KL_lookup1d((int)DAT_003fac48,iVar1 + 0x2a,&DAT_003fce01);
  local_a = KL_lookup1d((int)DAT_003fac48,iVar1,&DAT_003fce02);
  FUN_000633b8(0,&local_10);
  return;
}


// ==== FUN_039da4  (size=200) ====

void FUN_00039da4(void)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_r15;
  
  if (*(char *)(*(int *)(unaff_r15 + 0x120) + 0x162) == '\x02') {
    DAT_003faaa0 = DAT_003fae26;
  }
  if ((DAT_003fae6e & 0xd00f) == 0) {
    uVar1 = KF_lookup2d((int)DAT_003face4,(int)DAT_003fae26,*(int *)(unaff_r15 + 0x120),
                        &DAT_003fca3a);
    uVar2 = FUN_000597d8((uint)DAT_003faaae * (uVar1 & 0xffff),0x1000);
    DAT_003faab2 = FUN_00039994(uVar2,*(undefined2 *)(&DAT_003fb1ba + (uint)DAT_003fb375 * 2),
                                (&DAT_003fb137)[DAT_003fb375]);
  }
  else {
    uVar2 = 0;
    DAT_003faab2 = 0;
  }
  DAT_003faab8 = (undefined2)uVar2;
  DAT_00400342 = DAT_003faab2;
  FUN_0006a5b0(&DAT_008d1310,&DAT_003faab2);
  return;
}


// ==== FUN_825c14  (size=208) ====

int FUN_00825c14(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  short sVar3;
  short sVar4;
  undefined4 uVar2;
  short sVar5;
  int unaff_r15;
  int iVar6;
  
  iVar6 = *(int *)(unaff_r15 + 0x98);
  iVar1 = KL_lookup1d(param_2,iVar6 + 0xac,&DAT_00403267);
  sVar3 = sat_div16(iVar1 * param_1,(int)*(short *)(iVar6 + 0x5ec));
  iVar1 = KL_lookup1d(param_3,*(int *)(unaff_r15 + 0xa0) + 0x412,&DAT_00403268);
  DAT_0040012c = (undefined2)iVar1;
  sVar4 = sat_div16(iVar1 << 0xd,(int)*(short *)(iVar6 + 0x690));
  uVar2 = KF_lookup2d(param_2,param_4,iVar6 + 0x1b6,&DAT_00403269);
  sVar4 = sat_div16((int)sVar4 << 0xd,uVar2);
  sVar5 = sat_div16((int)sVar3 << 0xd,(int)sVar4);
  DAT_0040011e = sVar4;
  DAT_0040011c = sVar3;
  return (int)sVar5;
}


// ==== FUN_05e160  (size=208) ====

uint FUN_0005e160(uint param_1)

{
  ushort uVar1;
  uint uVar2;
  int unaff_r14;
  int iVar3;
  uint uVar4;
  undefined1 local_10 [8];
  
  iVar3 = 0;
  uVar2 = 0;
  uVar4 = 0;
  local_10[0] = 0;
  do {
    if ((1 << (uVar2 & 0x3f) & param_1 & 0xfff) != 0) {
      iVar3 = (int)(short)((ushort)iVar3 | (ushort)(1 << (uVar2 & 0x3f)));
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0xc);
  uVar1 = KL_lookup1d(iVar3,unaff_r14 + 0x4d64,local_10);
  uVar2 = 0;
  do {
    if ((uVar1 & (ushort)(1 << (uVar2 & 0x3f))) != 0) {
      uVar4 = uVar4 | 0x8000U >> (0xf - uVar2 & 0x3f);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x10);
  if (iVar3 == 0xf0f) {
    uVar4 = uVar4 | 0x8000;
  }
  return uVar4 | uVar4 << 0x10;
}


// ==== FUN_04c220  (size=220) ====

void FUN_0004c220(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                 short param_5,int param_6)

{
  undefined4 uVar1;
  float fVar2;
  uint uVar3;
  short sVar5;
  uint uVar4;
  float *pfVar6;
  uint uVar7;
  undefined1 *puVar8;
  int unaff_r14;
  int unaff_r15;
  undefined4 unaff_r25;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  undefined4 unaff_r28;
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  undefined4 unaff_r31;
  int iVar9;
  undefined8 extraout_f1;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined8 uVar14;
  double dVar15;
  undefined8 uVar16;
  undefined4 uStack_10;
  
  puVar8 = &stack0xffffffc8;
  uVar16 = FUN_0006d20c();
  *(undefined4 *)((int)register0x00000004 + -0x28) = unaff_r25;
  *(undefined4 *)((int)register0x00000004 + -0x24) = unaff_r26;
  *(undefined4 *)((int)register0x00000004 + -0x20) = unaff_r27;
  *(undefined4 *)((int)register0x00000004 + -0x1c) = unaff_r28;
  *(undefined4 *)((int)register0x00000004 + -0x18) = unaff_r29;
  *(undefined4 *)((int)register0x00000004 + -0x14) = unaff_r30;
  *(undefined4 *)((int)register0x00000004 + -0x10) = unaff_r31;
  iVar9 = *(int *)(unaff_r15 + 0x2ec);
  param_6 = param_6 >> 1;
  uVar14 = extraout_f1;
  dVar10 = (double)FUN_0005aaa0(extraout_f1,iVar9 + 0xd0);
  FUN_0005ab00(uVar14,param_2,iVar9 + 0xbc,&DAT_003fd200 + param_6);
  sVar5 = KL_lookup1d((int)((ulonglong)uVar16 >> 0x20),iVar9 + 0x10a,&DAT_003fd243);
  *(short *)uVar16 = sVar5 + param_5;
  dVar11 = (double)FUN_0006cd10((int)(short)(sVar5 + param_5));
  dVar15 = (double)(float)(dVar11 * (double)*(float *)(unaff_r14 + -0x144c));
  dVar13 = -dVar15;
  dVar12 = (double)(float)(&DAT_003fd200)[param_6];
  dVar11 = dVar13;
  if ((dVar13 <= dVar12) && (dVar11 = dVar12, dVar15 < dVar12)) {
    dVar11 = dVar15;
  }
  dVar10 = (double)(float)(dVar10 + dVar11);
  (&DAT_003fd200)[param_6] = (float)dVar11;
  if ((dVar13 <= dVar10) && (dVar13 = dVar10, dVar15 < dVar10)) {
    dVar13 = dVar15;
  }
  FUN_0006d1b0(dVar13);
  uVar4 = FUN_0006d214();
  *(undefined4 *)(puVar8 + -8) = uStack_10;
  uVar7 = 0;
  dVar11 = (double)*(float *)(unaff_r14 + 0x4d50);
  if (0 < (int)uVar4) {
    do {
      pfVar6 = (float *)(&DAT_003fd200 + uVar7);
      uVar7 = uVar7 + 1 & 0xff;
      dVar11 = (double)(float)(dVar11 + (double)*pfVar6);
    } while ((int)uVar7 < (int)uVar4);
  }
  dVar13 = (double)FUN_0006cd80(uVar4 & 0xff);
  uVar7 = 0;
  if (0 < (int)uVar4) {
    do {
      pfVar6 = (float *)(&DAT_003fd200 + uVar7);
      uVar7 = uVar7 + 1 & 0xff;
      *pfVar6 = *pfVar6 - (float)(dVar11 / dVar13);
    } while ((int)uVar7 < (int)uVar4);
  }
  FUN_0006d1b8();
  FUN_0006e64c();
  DAT_003fd242 = DAT_003fa847 * '\x02';
  uVar1 = *(undefined4 *)(unaff_r14 + 0x4d50);
  uVar7 = 0;
  do {
    uVar4 = uVar7 + 1 & 0xff;
    (&DAT_003fd200)[uVar7] = uVar1;
    (&DAT_003fb296)[uVar7] = 0;
    uVar7 = uVar4;
  } while (uVar4 < 10);
  DAT_003fb2aa = 0;
  uVar7 = 0;
  do {
    uVar4 = 0;
    do {
      uVar3 = uVar4 + 1 & 0xff;
      (&DAT_003fd070)[uVar7 * 0x14 + uVar4] = uVar1;
      uVar4 = uVar3;
    } while (uVar3 < 0x14);
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 5);
  fVar2 = *(float *)(*(int *)(unaff_r15 + 0x2ec) + 0x1c);
  if (fVar2 != *(float *)(unaff_r14 + -0x1448)) {
    DAT_003fd228 = fVar2;
  }
  return;
}


// ==== FUN_830478  (size=224) ====

int FUN_00830478(void)

{
  uint uVar1;
  short sVar3;
  undefined4 uVar2;
  short sVar4;
  int iVar5;
  int unaff_r15;
  uint uVar6;
  int local_18 [3];
  
  iVar5 = *(int *)(unaff_r15 + 0x2f4);
  local_18[0] = iVar5 + 0x48a;
  local_18[1] = iVar5 + 0x49e;
  local_18[2] = iVar5 + 0x4b2;
  uVar1 = KL_lookup1d((int)DAT_003face8,iVar5,&DAT_00402db9);
  iVar5 = (int)(uVar1 & 0xffff) >> 8;
  sVar3 = KF_lookup2d((int)DAT_003face4,(int)DAT_003faa12,local_18[iVar5],&DAT_00402db5);
  if ((uVar1 & 0xff) != 0) {
    uVar6 = iVar5 + 1;
    if (1 < uVar6) {
      uVar6 = 2;
    }
    uVar2 = KF_lookup2d((int)DAT_003face4,(int)DAT_003faa12,local_18[uVar6],&DAT_00402db7);
    sVar4 = sat_add16(uVar2,-(int)sVar3);
    sVar4 = sat_div16((int)sVar4 * (uVar1 & 0xff),0x100);
    sVar3 = sat_add16((int)sVar3,(int)sVar4);
  }
  return (int)sVar3;
}


// ==== FUN_830614  (size=228) ====

int FUN_00830614(void)

{
  uint uVar1;
  short sVar3;
  undefined4 uVar2;
  short sVar4;
  int unaff_r15;
  uint uVar5;
  int iVar6;
  int local_18 [3];
  
  iVar6 = *(int *)(unaff_r15 + 0x2f4);
  local_18[0] = iVar6 + 0x886;
  local_18[1] = iVar6 + 0xa64;
  local_18[2] = iVar6 + 0xc42;
  uVar1 = KL_lookup1d((int)DAT_003face8,iVar6 + 0xe20,&DAT_00402db9);
  iVar6 = (int)(uVar1 & 0xffff) >> 8;
  sVar3 = KF_lookup2d((int)DAT_003fb326,(int)DAT_003faa12,local_18[iVar6],&DAT_00402dba);
  if ((uVar1 & 0xff) != 0) {
    uVar5 = iVar6 + 1;
    if (1 < uVar5) {
      uVar5 = 2;
    }
    uVar2 = KF_lookup2d((int)DAT_003fb326,(int)DAT_003faa12,local_18[uVar5],&DAT_00402dbc);
    sVar4 = sat_add16(uVar2,-(int)sVar3);
    sVar4 = sat_div16((int)sVar4 * (uVar1 & 0xff),0x100);
    sVar3 = sat_add16((int)sVar3,(int)sVar4);
  }
  return (int)sVar3;
}


// ==== FUN_8269c0  (size=228) ====

int FUN_008269c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  short sVar3;
  short sVar4;
  undefined4 uVar2;
  short sVar5;
  int unaff_r15;
  int iVar6;
  
  iVar6 = *(int *)(unaff_r15 + 0x98);
  iVar1 = KL_lookup1d(param_2,iVar6 + 0xac,&DAT_00403233);
  sVar3 = sat_div16(iVar1 * param_1,(int)*(short *)(iVar6 + 0x5ec));
  iVar1 = KL_lookup1d(param_3,iVar6 + 0x628,&DAT_00403234);
  DAT_00400148 = (undefined2)iVar1;
  sVar4 = sat_div16(iVar1 << 0xd,(int)*(short *)(iVar6 + 0x690));
  uVar2 = KF_lookup2d(param_2,param_4,iVar6 + 0x1b6,&DAT_00403235);
  sVar4 = sat_div16((int)sVar4 << 0xd,uVar2);
  sVar5 = sat_div16((int)sVar3 << 0xd,(int)sVar4);
  DAT_00400140 = *(undefined2 *)(iVar6 + 0x5d4);
  DAT_00400142 = *(undefined2 *)(iVar6 + 0x5dc);
  DAT_00400136 = sVar4;
  DAT_00400134 = sVar3;
  return (int)sVar5;
}


// ==== FUN_8493e0  (size=240) ====

void FUN_008493e0(void)

{
  int unaff_r15;
  int iVar1;
  
  iVar1 = *(int *)(unaff_r15 + 0xc0);
  DAT_004001c0 = KL_lookup1d((int)DAT_003fb346,iVar1,&DAT_00403275);
  DAT_004001c2 = 0;
  if ((DAT_003fad18 == 0) || (*(char *)(iVar1 + 0x43) == '\0')) {
    DAT_003faa76 = DAT_003fb346;
  }
  else {
    DAT_004001c2 = 1;
    DAT_003faa76 = DAT_004001c0;
  }
  if ((DAT_003fad18 == 0) || (*(char *)(iVar1 + 0x42) == '\0')) {
    DAT_003faa74 = DAT_003fb346;
  }
  else {
    DAT_004001c2 = DAT_004001c2 | 2;
    DAT_003faa74 = DAT_004001c0;
  }
  if ((DAT_003fad18 == 0) || (*(char *)(iVar1 + 0x44) == '\0')) {
    DAT_003faa78 = DAT_003fb346;
  }
  else {
    DAT_004001c2 = DAT_004001c2 | 4;
    DAT_003faa78 = DAT_004001c0;
  }
  if ((DAT_003fad18 == 0) || (*(char *)(iVar1 + 0x45) == '\0')) {
    DAT_003faa7a = DAT_003fb346;
  }
  else {
    DAT_004001c2 = DAT_004001c2 | 8;
    DAT_003faa7a = DAT_004001c0;
  }
  return;
}


// ==== FUN_809718  (size=260) ====

void FUN_00809718(void)

{
  int unaff_r15;
  int iVar1;
  undefined1 local_8 [4];
  
  iVar1 = *(int *)(unaff_r15 + 0x2e8);
  if (*(short *)(iVar1 + 0x666) != 0) {
    DAT_00402080 = *(short *)(iVar1 + 0x666);
  }
  DAT_0040208a = DAT_0040208a & 0xfd | 1;
  DAT_0040208c = DAT_0040208c & 0xfd | 1;
  DAT_00402082 = KF_lookup2d((int)DAT_003fac66,(int)DAT_003fab2e,iVar1 + 0x86,&DAT_00402062);
  DAT_0040208b = DAT_0040208b & 0xfd | 1;
  DAT_0040208d = DAT_0040208d & 0xfd | 1;
  DAT_00402084 = DAT_00402082;
  DAT_00402086 = KF_lookup2d((int)DAT_003fac66,(int)DAT_003fab2e,iVar1 + 0xe,&DAT_00402060);
  DAT_00402088 = DAT_00402086;
  FUN_008683f0(0x38,iVar1 + 0x6cf,local_8);
  DAT_003fa87d = local_8[0];
  DAT_003fad2e = *(undefined2 *)(iVar1 + 0x58);
  DAT_003fad30 = *(undefined2 *)(iVar1 + 0xd0);
  DAT_0040209c = DAT_003fa9bf;
  if ((DAT_003fa9bb >> 4 & 1) == 0) {
    DAT_0040209c = 0xff;
  }
  return;
}


// ==== FUN_03cbe0  (size=260) ====

undefined4 FUN_0003cbe0(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int unaff_r14;
  int unaff_r15;
  short *psVar4;
  undefined4 uVar5;
  
  uVar1 = FUN_00068e34(param_1,0x3fffffff,param_2,0x3fffffff,1);
  iVar2 = sat_div16(DAT_003fe45c << 7,uVar1);
  if ((iVar2 < DAT_003fcbd0) || (DAT_003fcbd2 < iVar2)) {
    DAT_003fcb9f = 5;
    uVar5 = 0;
  }
  else {
    psVar4 = *(short **)(unaff_r15 + 0x154);
    uVar3 = *(int *)(unaff_r14 + 0x24fc) * (int)*psVar4;
    DAT_003fe45c = uVar1;
    DAT_003fe460 = sat_div16(((int)uVar3 >> 1) + (uint)((int)uVar3 < 0 && (uVar3 & 1) != 0),
                             uVar1 / *(uint *)(unaff_r14 + 0x42fc));
    DAT_003fcbd0 = KL_lookup1d((int)DAT_003fe460,psVar4 + 0xe,&DAT_003fcbd4);
    DAT_003fcbd2 = KL_lookup1d((int)DAT_003fe460,psVar4 + 3,&DAT_003fcbd5);
    uVar5 = 1;
  }
  DAT_00400434 = iVar2;
  DAT_00400432 = DAT_003fcbd0;
  DAT_00400430 = DAT_003fcbd2;
  return uVar5;
}


// ==== FUN_83db34  (size=264) ====

void FUN_0083db34(void)

{
  undefined4 uVar1;
  int unaff_r15;
  int iVar2;
  undefined4 local_28;
  undefined1 local_24;
  undefined1 local_23;
  short local_22;
  undefined2 local_20;
  undefined1 local_1e;
  undefined4 local_1c;
  undefined2 local_18;
  
  if (DAT_003fa933 != '\0') {
    if (DAT_003fa8ca == '\x04') {
      local_24 = 1;
      local_23 = 0;
      local_20 = 0xf3;
      local_1c = 20000;
      local_18 = DAT_003fad4c;
      if (((DAT_00401b05 & 1) == 0) || ((DAT_003fa8b5 & 0x3c) != 0)) {
        local_1e = 1;
      }
      else {
        local_1e = 0;
      }
      iVar2 = *(int *)(unaff_r15 + 0x438);
      FUN_00870710(&local_24,&DAT_003fd836,0,0,0,iVar2 + 4,iVar2 + 0x28,iVar2 + 8);
      uVar1 = FUN_00059b84((int)local_22,iVar2,&DAT_003fd82c,20000);
      local_28 = KL_lookup1d(uVar1,iVar2 + 0x12,&DAT_003fd834);
      DAT_003faea6 = FUN_00059b84(uVar1,&local_28,&DAT_003fd830,20000);
      DAT_004013a8 = local_22;
      DAT_004013a6 = (undefined2)uVar1;
    }
  }
  return;
}


// ==== FUN_0379d0  (size=268) ====

int FUN_000379d0(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  short sVar3;
  undefined4 uVar2;
  short sVar4;
  int unaff_r15;
  int iVar5;
  uint uVar6;
  int local_28 [4];
  int local_18;
  int local_14;
  
  iVar5 = *(int *)(unaff_r15 + 0xfc);
  local_28[0] = iVar5 + 0x21c;
  local_28[1] = iVar5 + 0x280;
  local_28[2] = iVar5 + 0x2e4;
  local_28[3] = iVar5 + 0x348;
  local_18 = iVar5 + 0x3ac;
  local_14 = iVar5 + 0x410;
  uVar1 = KL_lookup1d(param_1,iVar5 + 0x5ca,&DAT_003fc96b);
  uVar1 = uVar1 & 0xffff;
  if (0x500 < uVar1) {
    uVar1 = 0x500;
  }
  sVar3 = KF_lookup2d(param_2,(int)DAT_003face4,local_28[(int)uVar1 >> 8],&DAT_003fc96d);
  if ((uVar1 & 0xff) != 0) {
    uVar6 = ((int)uVar1 >> 8) + 1;
    if (1 < uVar6) {
      uVar6 = 2;
    }
    uVar2 = KF_lookup2d(param_2,(int)DAT_003face4,local_28[uVar6],&DAT_003fc96f);
    sVar4 = sat_add16(uVar2,-(int)sVar3);
    sVar4 = sat_div16((int)sVar4 * (uVar1 & 0xff),0x100);
    sVar3 = sat_add16((int)sVar3,(int)sVar4);
  }
  return (int)sVar3;
}


// ==== FUN_0408c8  (size=280) ====

void FUN_000408c8(void)

{
  uint uVar1;
  int unaff_r14;
  int unaff_r15;
  int iVar2;
  uint local_10;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  uVar1 = FUN_00063ac4(0);
  if (*(byte *)(unaff_r14 + -0x4674 + (uVar1 >> 1 & 0xf)) < 0x20) {
    local_10 = FUN_000643d0(0,(int)DAT_008d023a);
    if (local_10 < 0x7fff) {
      DAT_003fac48 = (short)local_10;
    }
    else {
      DAT_003fac48 = 0x7fff;
    }
  }
  else {
    FUN_00063350(0,&local_10);
    uVar1 = local_10;
    if (0x7ffe < local_10) {
      uVar1 = 0x7fff;
    }
    DAT_003fac48 = (short)uVar1;
    if ((DAT_003fac48 <= DAT_008d0254) && (DAT_003fb38c != '\x02')) {
      return;
    }
  }
  iVar2 = *(int *)(unaff_r15 + 0x1ec);
  local_c = KL_lookup1d((int)DAT_003fac48,iVar2 + 0x7e,&DAT_003fcdff);
  local_a = KL_lookup1d((int)DAT_003fac48,iVar2 + 0x54,&DAT_003fce00);
  local_8 = KL_lookup1d((int)DAT_003fac48,iVar2 + 0x2a,&DAT_003fce01);
  local_6 = KL_lookup1d((int)DAT_003fac48,iVar2,&DAT_003fce02);
  FUN_000633b8(0,&local_c);
  return;
}


// ==== FUN_8333d4  (size=288) ====

void FUN_008333d4(void)

{
  short sVar1;
  short sVar2;
  int unaff_r15;
  
  if ((DAT_003fa77c == '\0') || (DAT_003fa77c == '\x01')) {
    if (DAT_003fa77c == '\0') {
      sVar1 = KF_lookup2d((int)DAT_003fb326,(int)DAT_003fae00,*(int *)(unaff_r15 + 0x88) + 0xb2,
                          &DAT_00403b50);
    }
    else {
      sVar1 = KF_lookup2d((int)DAT_003fb326,(int)DAT_003fa9dc,*(int *)(unaff_r15 + 0x88) + 0xe,
                          &DAT_00403b50);
    }
    if ((DAT_003fa76d != '\0') && (DAT_00403b52 == '\0')) {
      DAT_00403b5c = 0;
      DAT_00403b58 = 0;
      DAT_00403b54 = sVar1;
    }
    sVar2 = FUN_00059c68((int)DAT_00403b54,*(undefined4 *)(unaff_r15 + 0x88),&DAT_00403b58,20000);
    if (DAT_003fa76d == '\0') {
      DAT_003fa9f2 = 0;
      DAT_004000d8 = sVar2;
      DAT_004000da = sVar1;
    }
    else {
      DAT_003fa9f2 = sat_add16((int)sVar1,(int)sVar2);
      DAT_004000d8 = sVar2;
      DAT_004000da = sVar1;
    }
  }
  else {
    DAT_003fa9f2 = sat_div16((int)DAT_003fa9e0 * (int)*(short *)(*(int *)(unaff_r15 + 0x88) + 10),
                             (int)*(short *)(*(int *)(unaff_r15 + 0x88) + 8));
  }
  DAT_00403b52 = DAT_003fa76d;
  DAT_003fa9f4 = DAT_003fa9f2;
  return;
}


// ==== FUN_826164  (size=288) ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00826164(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  short sVar1;
  short sVar2;
  int unaff_r15;
  int iVar3;
  undefined2 local_20 [4];
  
  _DAT_0040326e = FUN_00042200(0xe);
  sVar1 = sat_add16(param_4,-param_5);
  sVar1 = FUN_000595c8((int)sVar1,0x7fff);
  iVar3 = *(int *)(unaff_r15 + 0x9c);
  DAT_00400118 = sVar1;
  sVar2 = KL_lookup1d(param_2,iVar3,&DAT_00403274);
  if ((((param_1 == 2) && (*(short *)(iVar3 + 0x1a) < param_2)) &&
      (*(short *)(iVar3 + 0x24) < param_3)) &&
     (((param_6 != 1 && ((DAT_004019d6 & 1) != 0)) && ((DAT_004019d7 & 1) != 0)))) {
    _DAT_0040326e = CONCAT31(_DAT_0040326e,sVar2 < sVar1);
    DAT_00403272 = 8;
    DAT_00403273 = 0;
    FUN_00041950(&DAT_0040326c,&DAT_0040326e,iVar3 + 0x20);
    local_20[0] = DAT_0040326e;
    FUN_00041f08(0xe,local_20);
    return;
  }
  FUN_00041efc(&DAT_0040326c);
  return;
}


// ==== FUN_039758  (size=304) ====

void FUN_00039758(void)

{
  uint uVar1;
  uint uVar2;
  int unaff_r14;
  int unaff_r15;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined1 uVar6;
  
  cVar4 = '\0';
  DAT_003fca34 = 0;
  iVar5 = *(int *)(unaff_r15 + 0x11c);
  if ((DAT_004019fc & 1) == 0) {
    iVar3 = (int)*(short *)(iVar5 + 0x44);
    cVar4 = '\x04';
  }
  else {
    iVar3 = (int)DAT_003fab04;
    if (*(short *)(iVar5 + 0x48) < iVar3) {
      if (*(short *)(iVar5 + 0x46) < iVar3) {
        cVar4 = '\x02';
      }
    }
    else {
      cVar4 = '\x01';
    }
  }
  uVar1 = KL_lookup1d(iVar3,iVar5 + 0x1a,&DAT_003fca31);
  uVar2 = KL_lookup1d((int)DAT_003fad22,iVar5,&DAT_003fca32);
  DAT_003faaae = FUN_000597d8((uVar1 & 0xffff) * (uVar2 & 0xffff),0x1000);
  iVar5 = (uint)DAT_003fb375 * 2;
  uVar6 = 3;
  if (((&DAT_004019c3)[*(ushort *)(unaff_r14 + -0x57b0 + iVar5)] & 1) != 0) {
    uVar6 = 2;
  }
  if (((&DAT_004019c3)[*(ushort *)(unaff_r14 + -0x57ca + iVar5)] & 1) != 0) {
    uVar6 = 1;
  }
  if ((((&DAT_004019c3)[*(ushort *)(unaff_r14 + -0x57e4 + iVar5)] & 1) != 0) && (cVar4 == '\0')) {
    uVar6 = 0;
  }
  (&DAT_003fb137)[DAT_003fb375] = uVar6;
  DAT_00400334 = (short)iVar3;
  DAT_00400332 = cVar4;
  return;
}


// ==== FUN_819160  (size=304) ====

void FUN_00819160(void)

{
  bool bVar1;
  int iVar2;
  char cVar5;
  undefined4 uVar3;
  undefined4 uVar4;
  int unaff_r15;
  undefined4 *puVar6;
  
  puVar6 = *(undefined4 **)(unaff_r15 + 0x3b4);
  bVar1 = false;
  iVar2 = FUN_00044f1c(DAT_003fb364,*puVar6);
  if ((iVar2 == 0) && (*(char *)(puVar6 + 1) == '\0')) {
    cVar5 = FUN_0005aa78((int)DAT_003fab2e,(int)*(short *)(puVar6 + 0x18),
                         (int)*(short *)((int)puVar6 + 0x5e),&DAT_00402816);
    uVar3 = KL_lookup1d((int)DAT_003fb004,(int)puVar6 + 0x32,&DAT_0040281a);
    uVar4 = KL_lookup1d((int)DAT_003fb004,puVar6 + 0x12,&DAT_00402819);
    iVar2 = FUN_0005aa78((int)DAT_003fab2e,uVar4,uVar3,&DAT_00402817);
    if ((iVar2 == 0) && (cVar5 != '\0')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    uVar3 = KL_lookup1d((int)DAT_003fb004,(int)puVar6 + 6,&DAT_0040281c);
    uVar4 = KL_lookup1d((int)DAT_003fb004,puVar6 + 7,&DAT_0040281b);
    DAT_00401254 = FUN_0005aa78((int)DAT_003fae00,uVar4,uVar3,&DAT_00402818);
    if ((DAT_00401254 != '\0') || (bVar1)) {
      DAT_003fa90f = 1;
      DAT_00401255 = bVar1;
      return;
    }
  }
  DAT_003fa90f = 0;
  DAT_00401255 = bVar1;
  DAT_00401254 = 0;
  return;
}


// ==== FUN_833998  (size=308) ====

void FUN_00833998(void)

{
  int iVar1;
  int iVar2;
  short sVar3;
  undefined *puVar4;
  int unaff_r15;
  int iVar5;
  
  iVar5 = *(int *)(unaff_r15 + 0x440);
  iVar1 = KF_lookup2d((int)DAT_003face8,(int)DAT_003faa3c,iVar5 + 0xe2,&DAT_00403edd);
  iVar2 = KF_lookup2d((int)DAT_003face8,(int)DAT_003faa3c,iVar5,&DAT_003fe4ed);
  if (iVar2 < iVar1) {
    puVar4 = &DAT_00403edd;
    iVar1 = iVar5 + 0xe2;
  }
  else {
    puVar4 = &DAT_003fe4ed;
    iVar1 = iVar5;
  }
  sVar3 = KF_lookup2d((int)DAT_003face8,(int)DAT_003faa3c,iVar1,puVar4);
  iVar1 = KL_lookup1d((int)DAT_003face8,iVar5 + 0x13e,&DAT_00403ed7);
  if (sVar3 < iVar1) {
    sVar3 = KL_lookup1d((int)DAT_003face8,iVar5 + 0x13e,&DAT_00403ed7);
  }
  iVar1 = KL_lookup1d((int)DAT_003face8,iVar5 + 0x12a,&DAT_00403ed8);
  if (sVar3 < iVar1) {
    sVar3 = KL_lookup1d((int)DAT_003face8,iVar5 + 0x12a,&DAT_00403ed8);
  }
  iVar1 = KL_lookup1d((int)DAT_003face8,iVar5 + 0x134,&DAT_00403ed9);
  if (sVar3 < iVar1) {
    sVar3 = KL_lookup1d((int)DAT_003face8,iVar5 + 0x134,&DAT_00403ed9);
  }
  DAT_003faec6 = sVar3;
  DAT_00403ece = FUN_0005976c((int)sVar3,7);
  return;
}


// ==== FUN_051620  (size=312) ====

int FUN_00051620(short *param_1,int param_2,int param_3)

{
  ushort uVar3;
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar4;
  short sVar5;
  byte local_18;
  byte bStack_17;
  
  uVar3 = KL_lookup1d((int)param_1[2],*(undefined4 *)(param_1 + 8),param_3 + 2);
  if (param_1[10] * 0x100 + -0x100 <= (int)(uint)uVar3) {
    uVar3 = (short)((int)param_1[10] << 8) - 0x100;
  }
  uVar1 = FUN_00059f00((int)*param_1,(int)**(short **)(param_1 + 4),*(short **)(param_1 + 4) + 1,
                       param_3);
  uVar2 = FUN_00059f00((int)param_1[1],(int)**(short **)(param_1 + 6),*(short **)(param_1 + 6) + 1,
                       param_3 + 1);
  local_18 = (byte)(uVar3 >> 8);
  sVar4 = FUN_00059ff0(uVar1,uVar2,(int)**(short **)(param_1 + 6),
                       *(undefined4 *)(param_2 + (uint)local_18 * 4));
  bStack_17 = (byte)uVar3;
  if (bStack_17 != 0) {
    uVar1 = FUN_00059ff0(uVar1,uVar2,(int)**(short **)(param_1 + 6),
                         *(undefined4 *)(param_2 + (uint)local_18 * 4 + 4));
    sVar5 = sat_add16(uVar1,-(int)sVar4);
    sVar5 = sat_div16((int)sVar5 * (uint)bStack_17,0x100);
    sVar4 = sat_add16((int)sVar4,(int)sVar5);
  }
  return (int)sVar4;
}


// ==== FUN_8468d0  (size=320) ====

void FUN_008468d0(void)

{
  undefined4 uVar1;
  short sVar3;
  short sVar4;
  int iVar2;
  int unaff_r15;
  int iVar5;
  
  uVar1 = sat_add16((int)DAT_003faae2,-(int)DAT_003faa3c);
  sVar3 = sat_add16(uVar1,-(int)DAT_003fae08);
  iVar5 = *(int *)(unaff_r15 + 0x3c0);
  sVar4 = KL_lookup1d((int)DAT_003fb326,iVar5 + 0x44,&DAT_003fd5f4);
  DAT_0040126c = KL_lookup1d((int)DAT_003fb326,iVar5 + 6,&DAT_003fd5f5);
  DAT_0040126e = sVar4;
  DAT_00401270 = sVar3;
  iVar2 = FUN_0005aa78((int)sVar3,(int)sVar4,(int)DAT_0040126c,&DAT_003fd5f6);
  DAT_00401272 = FUN_0005a688(iVar2 == 0,&DAT_003fd5ec,iVar5,20000);
  if (((DAT_003fa7d9 == '0') ||
      ((*(short *)(iVar5 + 4) < DAT_003fb326 && (DAT_003faa28 <= *(short *)(iVar5 + 0x82))))) &&
     (((DAT_00401ae7 & 1) != 0 &&
      ((((DAT_003fa91a == '\0' && (DAT_003fa808 == '\0')) && (DAT_003faffa == 0)) &&
       ((DAT_003fa774 != '\x01' && (DAT_00401272 != '\0')))))))) {
    DAT_003fa919 = 1;
    return;
  }
  DAT_003fa919 = 0;
  return;
}


// ==== FUN_054f78  (size=324) ====

void FUN_00054f78(void)

{
  short sVar2;
  short sVar3;
  undefined4 uVar1;
  int unaff_r15;
  int iVar4;
  undefined2 local_18;
  int local_14 [2];
  
  iVar4 = *(int *)(unaff_r15 + 0x420);
  local_14[0] = iVar4 + 10;
  local_14[1] = iVar4 + 0x28c;
  local_18 = 0;
  if (DAT_003fae64 < 1) {
    sVar2 = 0;
    DAT_003fae98 = 0;
    sVar3 = DAT_003fae98;
  }
  else {
    sVar2 = sat_add16((int)DAT_003fae28,-(int)DAT_003facb8);
    local_18 = KL_lookup1d((int)sVar2,iVar4,&DAT_003fd725);
    if (0x100 < local_18) {
      local_18 = 0x100;
    }
    sVar3 = KF_lookup2d((int)DAT_003face4,(int)DAT_003fae64,local_14[local_18._0_1_],&DAT_003fd726);
    if ((byte)local_18 != 0) {
      uVar1 = KF_lookup2d((int)DAT_003face4,(int)DAT_003fae64,local_14[local_18._0_1_ + 1],
                          &DAT_003fd728);
      iVar4 = sat_add16(uVar1,-(int)sVar3);
      uVar1 = sat_div16(iVar4 * (uint)(byte)local_18,0x100);
      sVar3 = sat_add16((int)sVar3,uVar1);
    }
  }
  DAT_003fae98 = sVar3;
  DAT_00401384 = DAT_003fae98;
  DAT_00401380 = local_18;
  DAT_00401382 = sVar2;
  FUN_0006a5b0(&DAT_008d13d8,&DAT_003fae98);
  return;
}


// ==== FUN_839c34  (size=332) ====

int FUN_00839c34(short *param_1,int param_2,byte *param_3,int param_4)

{
  ushort uVar3;
  undefined4 uVar1;
  undefined4 uVar2;
  short sVar4;
  short sVar5;
  byte local_20;
  byte bStack_1f;
  
  uVar3 = KL_lookup1d((int)param_1[2],*(undefined4 *)(param_1 + 8),param_4 + 2);
  if (param_1[10] * 0x100 + -0x100 <= (int)(uint)uVar3) {
    uVar3 = (short)((int)param_1[10] << 8) - 0x100;
  }
  uVar1 = FUN_00059f00((int)*param_1,(int)**(short **)(param_1 + 4),*(short **)(param_1 + 4) + 1,
                       param_4);
  uVar2 = FUN_00059f00((int)param_1[1],(int)**(short **)(param_1 + 6),*(short **)(param_1 + 6) + 1,
                       param_4 + 1);
  local_20 = (byte)(uVar3 >> 8);
  sVar4 = FUN_00059ff0(uVar1,uVar2,(int)**(short **)(param_1 + 6),
                       *(undefined4 *)(param_2 + (uint)local_20 * 4));
  bStack_1f = (byte)uVar3;
  if (bStack_1f != 0) {
    uVar1 = FUN_00059ff0(uVar1,uVar2,(int)**(short **)(param_1 + 6),
                         *(undefined4 *)(param_2 + (uint)local_20 * 4 + 4));
    sVar5 = sat_add16(uVar1,-(int)sVar4);
    sVar5 = sat_div16((int)sVar5 * (uint)bStack_1f,0x100);
    sVar4 = sat_add16((int)sVar4,(int)sVar5);
  }
  *param_3 = local_20;
  param_3[1] = bStack_1f;
  return (int)sVar4;
}


// ==== FUN_811eb0  (size=336) ====

void FUN_00811eb0(void)

{
  undefined2 uVar1;
  short sVar2;
  short sVar3;
  int *piVar4;
  short sVar5;
  int unaff_r15;
  int iVar6;
  short *psVar7;
  int local_18;
  
  if ((DAT_00401a69 & 1) == 0) {
    DAT_003fac98 = *(undefined2 *)(*(int *)(unaff_r15 + 0x288) + 10);
    uVar1 = DAT_003fac98;
  }
  else {
    sVar5 = (short)((int)DAT_003fac8e + (int)DAT_003fac98 >> 1);
    sVar2 = KF_lookup2d((int)sVar5,(int)DAT_003fac8a,*(int *)(unaff_r15 + 0x27c) + 0x22,
                        &DAT_004022d4);
    psVar7 = *(short **)(unaff_r15 + 0x288);
    sVar3 = KF_lookup2d((int)sVar5,(int)DAT_003fac8a,psVar7 + 6,&DAT_004022d6);
    DAT_00400d0a = sat_add16((int)DAT_003fac8e,(int)sVar3);
    iVar6 = (int)DAT_00400d0a;
    DAT_00400d04 = sVar2;
    DAT_00400d06 = sVar5;
    DAT_00400d08 = sVar3;
    sVar2 = sat_div16((int)sVar2 * (int)DAT_003fac7e,0xafd);
    sVar2 = sat_div16(sVar2 * 0x150,(int)*psVar7);
    local_18 = (int)sVar2;
    if (*(char *)(psVar7 + 4) == '\0') {
      piVar4 = &local_18;
    }
    else {
      piVar4 = (int *)(psVar7 + 2);
    }
    DAT_003fac98 = FUN_00059b84(iVar6,piVar4,&DAT_004022d8,100000);
    uVar1 = DAT_003fac98;
    if ((DAT_003fa7d9 & 4) == 0) {
      DAT_004022d8 = (int)DAT_003fac9a << 0x10;
      uVar1 = DAT_004022dc;
    }
  }
  DAT_004022dc = uVar1;
  FUN_00869e50(0x10,6,2,0,&DAT_004022dc,0);
  return;
}


// ==== FUN_054e24  (size=340) ====

void FUN_00054e24(void)

{
  short sVar2;
  short sVar3;
  undefined4 uVar1;
  short sVar4;
  int unaff_r15;
  int iVar5;
  undefined2 local_20;
  int local_1c [3];
  
  local_20 = 0;
  sVar2 = 0;
  if (DAT_003fae62 < 1) {
    sVar3 = 0;
    DAT_003fae92 = 0;
    sVar4 = DAT_003fae92;
  }
  else {
    iVar5 = *(int *)(unaff_r15 + 0x41c);
    local_1c[0] = iVar5 + 10;
    local_1c[1] = iVar5 + 0xfe;
    sVar2 = sat_add16((int)DAT_003fae26,-(int)DAT_003facb8);
    local_20 = KL_lookup1d((int)sVar2,iVar5,&DAT_003fd720);
    if (0x100 < local_20) {
      local_20 = 0x100;
    }
    sVar3 = KF_lookup2d((int)DAT_003face4,(int)DAT_003fae62,local_1c[local_20._0_1_],&DAT_003fd721);
    DAT_003fae90 = *(undefined2 *)(iVar5 + (uint)local_20._0_1_ * -2 + 4);
    sVar4 = sVar3;
    if ((byte)local_20 != 0) {
      uVar1 = KF_lookup2d((int)DAT_003face4,(int)DAT_003fae62,local_1c[local_20._0_1_ + 1],
                          &DAT_003fd723);
      iVar5 = sat_add16(uVar1,-(int)sVar3);
      uVar1 = sat_div16(iVar5 * (uint)(byte)local_20,0x100);
      sVar4 = sat_add16((int)sVar3,uVar1);
    }
  }
  DAT_003fae92 = sVar4;
  DAT_0040137e = DAT_003fae92;
  DAT_003fae96 = sVar3;
  DAT_0040137a = local_20;
  DAT_0040137c = sVar2;
  FUN_0006a5b0(&DAT_008d13d6,&DAT_003fae92);
  return;
}


// ==== FUN_82ef14  (size=344) ====

void FUN_0082ef14(void)

{
  short sVar2;
  int iVar1;
  short sVar3;
  int unaff_r15;
  int iVar4;
  int iVar5;
  
  if ((DAT_003fa7d9 == '\x01') || (DAT_003fa7d9 == '\x02')) {
    if ((DAT_003fa9aa == '\0') && (DAT_00402e53 == '\0')) {
      sVar2 = KF_lookup2d((int)DAT_003fb326,(int)DAT_003face8,*(int *)(unaff_r15 + 0x524) + 8,
                          &DAT_00402e4e);
    }
    else {
      DAT_00402e53 = '\x01';
      sVar2 = KF_lookup2d((int)DAT_003fb326,(int)DAT_003face8,*(int *)(unaff_r15 + 0x524) + 0xe6,
                          &DAT_00402e4c);
    }
    if ((DAT_00401b3b & 1) == 0) {
      sVar2 = sat_add16((int)sVar2,(int)*(short *)(*(int *)(unaff_r15 + 0x524) + 6));
    }
    DAT_004016dc = DAT_00402e53;
    DAT_004016e0 = sVar2;
    sVar2 = sat_add16((int)sVar2,(int)DAT_003fafca);
    iVar4 = (int)**(short **)(unaff_r15 + 0x524);
    if ((iVar4 < DAT_003fb326) || (iVar4 < 1)) {
      iVar4 = 0;
    }
    else {
      iVar1 = (int)DAT_00402e50;
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      else {
        iVar5 = (int)(*(short **)(unaff_r15 + 0x524))[1];
        if (iVar5 < iVar1) {
          iVar1 = iVar5;
        }
      }
      sVar3 = sat_div16(iVar1 * DAT_003fb326,iVar4);
      iVar4 = (int)(short)((short)iVar1 - sVar3);
    }
    DAT_004016de = (undefined2)iVar4;
    DAT_004016e2 = DAT_00402e50;
    DAT_003fafcc = sat_add16((int)sVar2,iVar4);
  }
  return;
}


// ==== FUN_849898  (size=380) ====

void FUN_00849898(void)

{
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar1;
  int unaff_r15;
  int iVar6;
  
  iVar6 = *(int *)(unaff_r15 + 0x3bc);
  sVar2 = KF_lookup2d((int)DAT_003fb326,(int)DAT_003fb342,iVar6 + 300,&DAT_003fd5e4);
  sVar3 = KF_lookup2d((int)DAT_003fb326,(int)DAT_003fb342,iVar6 + 0x2c,&DAT_003fd5e8);
  sVar4 = KL_lookup1d((int)DAT_003faa3c,iVar6,&DAT_003fd5eb);
  sVar3 = FUN_00059860((int)sVar3,(int)sVar4,0xd);
  sVar4 = KF_lookup2d((int)DAT_003fb326,(int)DAT_003fb342,iVar6 + 0x370,&DAT_003fd5e6);
  sVar5 = KL_lookup1d((int)DAT_003fab2e,iVar6 + 0x16,&DAT_003fd5ea);
  sVar4 = FUN_00059860((int)sVar4,(int)sVar5,0xd);
  DAT_00401262 = sVar3;
  DAT_00401264 = sVar2;
  DAT_0040126a = sVar4;
  sVar2 = sat_add16((int)sVar2,-(int)sVar3);
  sVar2 = sat_add16((int)sVar2,-(int)sVar4);
  DAT_00401268 = sVar2;
  if (*(char *)(iVar6 + 0x464) != '\0') {
    iVar1 = FUN_0005aa78((int)sVar2,(int)*(short *)(iVar6 + 0x122),(int)*(short *)(iVar6 + 0x124),
                         &DAT_003fd5e3);
    if (iVar1 == 0) {
      sVar2 = *(short *)(iVar6 + 0x126);
    }
    else {
      sVar2 = *(short *)(iVar6 + 0x128);
    }
  }
  if (*(short *)(iVar6 + 0x120) < DAT_003faa80) {
    sVar2 = *(short *)(iVar6 + 0x12a);
  }
  DAT_003fae0e = sVar2;
  DAT_00401266 = sVar2;
  FUN_0006a534(&DAT_008d13b8,&DAT_003fae0e,0,10000);
  FUN_0006a5b0(&DAT_008d13ba,&DAT_003fae0e);
  return;
}


// ==== FUN_039a34  (size=416) ====

void FUN_00039a34(void)

{
  short sVar1;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  int unaff_r15;
  undefined2 local_18 [4];
  short sVar2;
  
  if (*(char *)(*(int *)(unaff_r15 + 0x120) + 0x162) == '\x05') {
    DAT_003faaa0 = DAT_003fae28;
  }
  if ((DAT_003fae6e & 0xdf) != 0) {
    uVar4 = 0;
    bVar3 = false;
    uVar5 = 0;
    DAT_003faab4 = 0;
    local_18[0] = 0;
    DAT_00400336 = 0;
    goto LAB_00039b54;
  }
  uVar4 = KF_lookup2d((int)DAT_003face4,(int)DAT_003fae28,*(int *)(unaff_r15 + 0x120),&DAT_003fca42)
  ;
  uVar4 = FUN_000597d8((uint)DAT_003faaae * (uVar4 & 0xffff),0x1000);
  uVar4 = uVar4 & 0xffff;
  if ((DAT_003fae6e & 0x10f) == 0) {
    puVar6 = &DAT_00400336;
    sVar1 = DAT_003fae1e;
    sVar2 = DAT_003fae84;
LAB_00039af4:
    uVar5 = FUN_000398e0(uVar4,(int)sVar1,(int)DAT_003fae28,(int)sVar2,local_18,puVar6,
                         (int)DAT_003face4);
    bVar3 = true;
  }
  else {
    DAT_00400336 = 0;
    if ((DAT_003fae6e & 0xd00f) == 0) {
      puVar6 = &DAT_00400338;
      sVar1 = DAT_003fae26;
      sVar2 = DAT_003fae92;
      goto LAB_00039af4;
    }
    bVar3 = false;
    local_18[0] = 0;
    uVar5 = uVar4;
  }
  DAT_003faab4 = FUN_00039994(uVar5,*(undefined2 *)(&DAT_003fb1d0 + (uint)DAT_003fb375 * 2),
                              (&DAT_003fb137)[DAT_003fb375]);
LAB_00039b54:
  DAT_003faaba = (undefined2)uVar5;
  if (bVar3) {
    DAT_003faaa6 = DAT_003faaa6 | (ushort)(1 << (DAT_003fb375 & 0x3f));
  }
  else {
    DAT_003faaa6 = DAT_003faaa6 & ~(ushort)(1 << (DAT_003fb375 & 0x3f));
  }
  DAT_0040033e = local_18[0];
  DAT_00400348 = (undefined2)uVar4;
  DAT_00400344 = DAT_003faab4;
  FUN_0006a5b0(&DAT_008d1312,&DAT_003faab4);
  return;
}

