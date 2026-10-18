
// ==== KL_lookup1d @0x05A074 calls=402 ====

int KL_lookup1d(int param_1,short *param_2,byte *param_3,undefined4 param_4,int param_5)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  uint uVar7;
  
  sVar1 = *param_2;
  param_2 = param_2 + 1;
  uVar7 = 0;
  uVar4 = 0;
  if ((*param_2 < param_1) && (uVar7 = (int)sVar1 - 1, param_1 < param_2[uVar7])) {
    if (*param_3 < uVar7) {
      uVar7 = (uint)*param_3;
    }
    if (param_2[uVar7] < param_1) {
      psVar5 = param_2 + uVar7;
      uVar3 = uVar7;
      do {
        uVar7 = uVar3;
        psVar5 = psVar5 + 1;
        uVar3 = uVar7 + 1;
      } while (*psVar5 <= param_1);
    }
    else if (param_1 < param_2[uVar7]) {
      psVar5 = param_2 + uVar7;
      do {
        psVar5 = psVar5 + -1;
        uVar7 = uVar7 - 1;
      } while (param_1 < *psVar5);
    }
    iVar6 = (int)param_2[uVar7];
    if (iVar6 != param_1) {
      uVar4 = (uint)((param_1 - iVar6) * 0x10000) / (uint)(param_2[uVar7 + 1] - iVar6);
    }
    *param_3 = (byte)uVar7;
  }
  uVar4 = uVar4 + uVar7 * 0x10000;
  uVar7 = uVar4 & 0xffff;
  sVar2 = param_2[(int)sVar1 + (uVar4 >> 0x10)];
  if (uVar7 != 0) {
    param_5 = (int)(param_2 + (int)sVar1 + (uVar4 >> 0x10))[1];
  }
  return (int)(short)(sVar2 + (short)(uVar7 * (param_5 - sVar2) >> 0x10));
}


// ==== KF_lookup2d @0x05A16C calls=387 ====

int KF_lookup2d(int param_1,int param_2,short *param_3,byte *param_4)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  sVar1 = *param_3;
  iVar3 = (int)param_3[1];
  param_3 = param_3 + 2;
  uVar8 = 0;
  uVar6 = 0;
  if ((*param_3 < param_1) && (uVar8 = (int)sVar1 - 1, param_1 < param_3[uVar8])) {
    if (*param_4 < uVar8) {
      uVar8 = (uint)*param_4;
    }
    if (param_3[uVar8] < param_1) {
      psVar4 = param_3 + uVar8;
      uVar2 = uVar8;
      do {
        uVar8 = uVar2;
        psVar4 = psVar4 + 1;
        uVar2 = uVar8 + 1;
      } while (*psVar4 <= param_1);
    }
    else if (param_1 < param_3[uVar8]) {
      psVar4 = param_3 + uVar8;
      do {
        psVar4 = psVar4 + -1;
        uVar8 = uVar8 - 1;
      } while (param_1 < *psVar4);
    }
    iVar5 = (int)param_3[uVar8];
    if (iVar5 != param_1) {
      uVar6 = (uint)((param_1 - iVar5) * 0x10000) / (uint)(param_3[uVar8 + 1] - iVar5);
    }
    *param_4 = (byte)uVar8;
  }
  param_3 = param_3 + sVar1;
  uVar2 = 0;
  uVar6 = uVar6 + uVar8 * 0x10000;
  uVar8 = 0;
  if ((*param_3 < param_2) && (uVar2 = iVar3 - 1, param_2 < param_3[uVar2])) {
    uVar7 = (uint)param_4[1];
    if (uVar7 < uVar2) {
      uVar2 = uVar7;
    }
    if (param_3[uVar2] < param_2) {
      psVar4 = param_3 + uVar2;
      uVar7 = uVar2;
      do {
        uVar2 = uVar7;
        psVar4 = psVar4 + 1;
        uVar7 = uVar2 + 1;
      } while (*psVar4 <= param_2);
    }
    else if (param_2 < param_3[uVar2]) {
      psVar4 = param_3 + uVar2;
      do {
        psVar4 = psVar4 + -1;
        uVar2 = uVar2 - 1;
      } while (param_2 < *psVar4);
    }
    iVar5 = (int)param_3[uVar2];
    if (iVar5 != param_2) {
      uVar8 = (uint)((param_2 - iVar5) * 0x10000) / (uint)(param_3[uVar2 + 1] - iVar5);
    }
    param_4[1] = (byte)uVar2;
  }
  uVar8 = uVar8 + uVar2 * 0x10000;
  uVar2 = uVar6 & 0xffff;
  uVar7 = uVar8 & 0xffff;
  param_3 = param_3 + iVar3 + (uVar8 >> 0x10) + iVar3 * (uVar6 >> 0x10);
  iVar5 = (int)*param_3;
  if (uVar7 != 0) {
    iVar5 = iVar5 + ((int)(uVar7 * (param_3[1] - iVar5)) >> 0x10);
  }
  if (uVar2 != 0) {
    iVar9 = (int)param_3[iVar3];
    if (uVar7 != 0) {
      iVar9 = iVar9 + ((int)(uVar7 * ((param_3 + iVar3)[1] - iVar9)) >> 0x10);
    }
    iVar5 = iVar5 + ((int)(uVar2 * (iVar9 - iVar5)) >> 0x10);
  }
  return (int)(short)iVar5;
}

