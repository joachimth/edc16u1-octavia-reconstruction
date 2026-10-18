// Top internal-flash shared functions (calibration/interpolation library candidates)

// ==== FUN_0005967c @0x0005967c  ====

int FUN_0005967c(int param_1,int param_2)

{
  param_1 = param_1 + param_2;
  if (param_1 < -0x7fff) {
    return -0x8000;
  }
  if (param_1 < 0x7fff) {
    return param_1;
  }
  return 0x7fff;
}


// ==== FUN_00042200 @0x00042200  ====

uint FUN_00042200(int param_1)

{
  undefined4 local_8;
  
  local_8 = CONCAT22(*(undefined2 *)(&DAT_003ff760 + param_1 * 2),local_8._2_2_) & 0xf7feffff;
  return local_8;
}


// ==== FUN_00059800 @0x00059800  ====

int FUN_00059800(int param_1,int param_2)

{
  if (param_2 == 0) {
    if (-1 < param_1) {
      return 0x7fff;
    }
  }
  else {
    param_1 = param_1 / param_2;
    if (-0x8000 < param_1) {
      if (param_1 < 0x7fff) {
        return param_1;
      }
      return 0x7fff;
    }
  }
  return -0x8000;
}


// ==== FUN_00041f08 @0x00041f08  ====

void FUN_00041f08(int param_1,ushort *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int unaff_r14;
  int unaff_r15;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  ushort local_18 [4];
  undefined2 uVar6;
  undefined2 uVar9;
  
  bVar1 = (DAT_003fa962 & *(byte *)(*(int *)(unaff_r15 + 0x218) + param_1 + -1)) == 0;
  if (bVar1) {
    (&DAT_003ff760)[param_1 * 2] = (&DAT_003ff760)[param_1 * 2] & 0xdf;
    *(byte *)param_2 = *(byte *)param_2 & 0xdf;
  }
  else {
    (&DAT_003ff760)[param_1 * 2] = (&DAT_003ff760)[param_1 * 2] & 0xdf | 0x20;
  }
  if ((((*param_2 ^ *(ushort *)(&DAT_003ff760 + param_1 * 2)) & 0xfbf6) != 0) && (bVar1)) {
    if (((*param_2 ^ *(ushort *)(&DAT_003ff760 + param_1 * 2)) & 0x40f0) == 0) {
      *(ushort *)(&DAT_003ff760 + param_1 * 2) = *param_2;
    }
    else {
      *(byte *)param_2 = ((byte)((byte)*param_2 >> 4) != 0) << 7 | *(byte *)param_2 & 0x7f;
      if ((DAT_003fce80 == '\0') && (DAT_003fce71 != '\0')) {
        local_18[0] = *param_2;
        FUN_008538bc(param_1,local_18);
      }
      else {
        FUN_00025d2c();
        uVar7 = (DAT_00403ae9 + 1) % 10;
        if (DAT_00403ae8 != uVar7) {
          iVar2 = (uint)DAT_00403ae9 * 2;
          *(ushort *)(&DAT_00403af0 + iVar2) = *param_2;
          *(short *)(&DAT_00403b04 + iVar2) = (short)param_1;
          DAT_00403ae9 = (byte)uVar7;
        }
        FUN_00025d54();
      }
      iVar2 = param_1 + -1 >> 4;
      uVar7 = iVar2 * 0x10;
      uVar3 = uVar7 + 0x10;
      uVar8 = 0;
      uVar9 = 0;
      uVar5 = 0;
      uVar6 = 0;
      uVar4 = 0;
      while (uVar7 = uVar7 + 1, uVar7 <= uVar3) {
        if (uVar7 < 0x143) {
          uVar8 = uVar8 | ((byte)(&DAT_003ff760)[uVar7 * 2] >> 6 & 1) << (uVar4 & 0x3f);
          uVar5 = uVar5 | (uint)((byte)(&DAT_003ff760)[uVar7 * 2] >> 7) << (uVar4 & 0x3f);
        }
        uVar6 = (undefined2)uVar5;
        uVar9 = (undefined2)uVar8;
        uVar4 = uVar4 + 1;
      }
      iVar2 = iVar2 * 2;
      *(undefined2 *)(&DAT_00400bea + iVar2) = uVar9;
      *(undefined2 *)(&DAT_00400bb6 + iVar2) = uVar6;
    }
    **(ushort **)(unaff_r14 + -0x43e8 + param_1 * 4) =
         (ushort)(byte)((byte)*param_2 >> 4) | (ushort)(*(byte *)param_2 >> 7) << 4 |
         (ushort)((*(byte *)param_2 >> 6 & 1) << 5) | (ushort)((*(byte *)param_2 >> 1 & 1) << 6) |
         (ushort)(((byte)(&DAT_003ff761)[param_1 * 2] >> 3 & 1) << 7) |
         (ushort)((*(byte *)param_2 >> 3 & 1) << 8) |
         (ushort)(((byte)((byte)*param_2 >> 2) & 1) << 9);
  }
  return;
}


// ==== FUN_0005a074 @0x0005a074  ====

int FUN_0005a074(int param_1,short *param_2,byte *param_3,undefined4 param_4,int param_5)

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


// ==== FUN_0005a16c @0x0005a16c  ====

int FUN_0005a16c(int param_1,int param_2,short *param_3,byte *param_4)

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

