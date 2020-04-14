0xa0108040 = HI_ERR_VI_FAILED_NOTENABLE

# ./GetDevAttr Sofia!!!!!
//A program used to extract the  VI_DEV_ATTR_S and VI_CHN_ATTR_S  settings while running the Sofia computer program in the original image

enIntfMode = 6 //VI_MODE_LVDS
enWorkMode = 0
au32CompMask[0] = fff00000
au32CompMask[1] = 0
enScanMode = 1
s32AdChnId[0] = -1
s32AdChnId[1] = -1
s32AdChnId[2] = -1
s32AdChnId[3] = -1
enDataSeq = 4 //VI_DATA_YUV_BUTT
enDataPath = 1
enInputDataType = 1
bDataRev = 0

enVsync = 1
enVsyncNeg = 1
enHsync = 0
enHsyncNeg = 0
enVsyncValid = 1
enVsyncValidNeg = 0

stTimingBlank.u32HsyncHfb = 0
stTimingBlank.u32HsyncAct = 1280
stTimingBlank.u32HsyncHbb = 0
stTimingBlank.u32VsyncVfb = 0
stTimingBlank.u32VsyncVact = 720
stTimingBlank.u32VsyncVbb = 0
stTimingBlank.u32VsyncVbfb = 0
stTimingBlank.u32VsyncVbact = 0
stTimingBlank.u32VsyncVbbb = 0

--------------------------------------------------------------------------

stCapRect.s32X = 0
stCapRect.s32Y = 0
stCapRect.u32Width = 1920
stCapRect.u32Height = 1080
stDestSize.u32Width = 1920
stDestSize.u32Height = 1080
enCapSel = 2 //VI_CAPSEL_BOTH
enPixFormat = 23 //PIXEL_FORMAT_YUV_SEMIPLANAR_420
bMirror = 0
bFlip = 0
s32SrcFrameRate = -1

===============================================================

# ./GetDevAttr sample_venc 0 !!!!!!!!!!!!!
enIntfMode = 5 //VI_MODE_MIPI !!!!!!
enWorkMode = 0
au32CompMask[0] = fff00000
au32CompMask[1] = 0
enScanMode = 1
s32AdChnId[0] = -1
s32AdChnId[1] = -1
s32AdChnId[2] = -1
s32AdChnId[3] = -1
enDataSeq = 2 //VI_INPUT_DATA_YUYV
enDataPath = 1
enInputDataType = 1
bDataRev = 0

enVsync = 1
enVsyncNeg = 1
enHsync = 0
enHsyncNeg = 0
enVsyncValid = 1
enVsyncValidNeg = 0

stTimingBlank.u32HsyncHfb = 0
stTimingBlank.u32HsyncAct = 1280
stTimingBlank.u32HsyncHbb = 0
stTimingBlank.u32VsyncVfb = 0
stTimingBlank.u32VsyncVact = 720
stTimingBlank.u32VsyncVbb = 0
stTimingBlank.u32VsyncVbfb = 0
stTimingBlank.u32VsyncVbact = 0
stTimingBlank.u32VsyncVbbb = 0

--------------------------------------------------------------------------

stCapRect.s32X = 0
stCapRect.s32Y = 0
stCapRect.u32Width = 1920
stCapRect.u32Height = 1080
stDestSize.u32Width = 1920
stDestSize.u32Height = 1080
enCapSel = 2
enPixFormat = 23
bMirror = 0
bFlip = 0
s32SrcFrameRate = -1


==============================
//From src decompiled!

int __fastcall IMX290_Init_sub_4ABB98(int a1)
{
  int result; // r0
  int v2; // r4
  unsigned int v3; // [sp+4h] [bp-14h]

  result = GetWdrMode(a1);
  v2 = result;
  if ( result )
  {
    if ( result == 1 )
    {
      v3 = 0;
      if ( (unsigned int)(genSensorMode - 3) <= 1 )
      {
        HI_MPI_SYS_GetReg(302055468, &v3);
        v3 = v3 & 0xFC7DFFFF | 0x800000;
        HI_MPI_SYS_SetReg(302055468, v3);
        I2C_WRITE_sub_4A3EEC(12288, 1); //0x3000 Standby
        usleep(0x186A0u);
        I2C_WRITE_sub_4A3EEC(12295, 0);
        I2C_WRITE_sub_4A3EEC(12297, 1);
        I2C_WRITE_sub_4A3EEC(12298, 240);
        I2C_WRITE_sub_4A3EEC(12303, 0);
        I2C_WRITE_sub_4A3EEC(12304, 33);
        I2C_WRITE_sub_4A3EEC(12306, 100);
        I2C_WRITE_sub_4A3EEC(12308, 32);
        I2C_WRITE_sub_4A3EEC(12310, 9);
        I2C_WRITE_sub_4A3EEC(12310, 9);
        I2C_WRITE_sub_4A3EEC(12312, 101);
        I2C_WRITE_sub_4A3EEC(12313, 4);
        I2C_WRITE_sub_4A3EEC(12314, 0);
        I2C_WRITE_sub_4A3EEC(12315, 0);
        I2C_WRITE_sub_4A3EEC(12316, 152);
        I2C_WRITE_sub_4A3EEC(12317, 8);
        I2C_WRITE_sub_4A3EEC(12320, 1);
        I2C_WRITE_sub_4A3EEC(12321, 0);
        I2C_WRITE_sub_4A3EEC(12358, 225); //0x3046 225 = LVDS 4CH - 12bit
        I2C_WRITE_sub_4A3EEC(12380, 24);
        I2C_WRITE_sub_4A3EEC(12382, 32);
        I2C_WRITE_sub_4A3EEC(12400, 2);
        I2C_WRITE_sub_4A3EEC(12401, 17);
        I2C_WRITE_sub_4A3EEC(12443, 16);
        I2C_WRITE_sub_4A3EEC(12444, 34);
        I2C_WRITE_sub_4A3EEC(12450, 2);
        I2C_WRITE_sub_4A3EEC(12454, 32);
        I2C_WRITE_sub_4A3EEC(12456, 32);
        I2C_WRITE_sub_4A3EEC(12458, 32);
        I2C_WRITE_sub_4A3EEC(12460, 32);
        I2C_WRITE_sub_4A3EEC(12464, 67);
        I2C_WRITE_sub_4A3EEC(12569, 158);
        I2C_WRITE_sub_4A3EEC(12572, 30);
        I2C_WRITE_sub_4A3EEC(12574, 8);
        I2C_WRITE_sub_4A3EEC(12584, 5);
        I2C_WRITE_sub_4A3EEC(12605, 131);
        I2C_WRITE_sub_4A3EEC(12624, 3);
        I2C_WRITE_sub_4A3EEC(12638, 26);
        I2C_WRITE_sub_4A3EEC(12644, 26);
        I2C_WRITE_sub_4A3EEC(12668, 0);
        I2C_WRITE_sub_4A3EEC(12670, 0);
        I2C_WRITE_sub_4A3EEC(12670, 0);
        I2C_WRITE_sub_4A3EEC(12984, 80);
        I2C_WRITE_sub_4A3EEC(12985, 16);
        I2C_WRITE_sub_4A3EEC(12986, 0);
        I2C_WRITE_sub_4A3EEC(12987, 4);
        I2C_WRITE_sub_4A3EEC(13000, 80);
        I2C_WRITE_sub_4A3EEC(13001, 16);
        I2C_WRITE_sub_4A3EEC(13002, 0);
        I2C_WRITE_sub_4A3EEC(13003, 4);
        I2C_WRITE_sub_4A3EEC(13100, 211);
        I2C_WRITE_sub_4A3EEC(13101, 16);
        I2C_WRITE_sub_4A3EEC(13102, 13);
        I2C_WRITE_sub_4A3EEC(13144, 6);
        I2C_WRITE_sub_4A3EEC(13145, 225);
        I2C_WRITE_sub_4A3EEC(13146, 17);
        I2C_WRITE_sub_4A3EEC(13152, 30);
        I2C_WRITE_sub_4A3EEC(13153, 97);
        I2C_WRITE_sub_4A3EEC(13154, 16);
        I2C_WRITE_sub_4A3EEC(13232, 80);
        I2C_WRITE_sub_4A3EEC(13234, 26);
        I2C_WRITE_sub_4A3EEC(13235, 4);
        usleep(0x4E20u);
        I2C_WRITE_sub_4A3EEC(12288, 0);
        I2C_WRITE_sub_4A3EEC(12290, 0);
        I2C_WRITE_sub_4A3EEC(12361, 10);
        result = puts("--IMX291 1080P 60fps LINE Init OK!-------------------");
      }
      else
      {
        HI_MPI_SYS_GetReg(302055468, &v3);
        v3 = v3 & 0xFC7DFFFF | 0x800000;
        HI_MPI_SYS_SetReg(302055468, v3);
        I2C_WRITE_sub_4A3EEC(12288, 1);
        usleep(0x186A0u);
        I2C_WRITE_sub_4A3EEC(12295, 0);
        I2C_WRITE_sub_4A3EEC(12297, 2); /* Gain */
        I2C_WRITE_sub_4A3EEC(12298, 240);
        I2C_WRITE_sub_4A3EEC(12303, 0);
        I2C_WRITE_sub_4A3EEC(12304, 33);
        I2C_WRITE_sub_4A3EEC(12306, 100);
        I2C_WRITE_sub_4A3EEC(12308, 32);
        I2C_WRITE_sub_4A3EEC(12310, 9);
        I2C_WRITE_sub_4A3EEC(12310, 9);
        I2C_WRITE_sub_4A3EEC(12312, 109);
        I2C_WRITE_sub_4A3EEC(12313, 4);
        I2C_WRITE_sub_4A3EEC(12314, 0);
        I2C_WRITE_sub_4A3EEC(12315, 0);
        I2C_WRITE_sub_4A3EEC(12316, 48);
        I2C_WRITE_sub_4A3EEC(12317, 17);
        I2C_WRITE_sub_4A3EEC(12320, 1); /* SHS1 */
        I2C_WRITE_sub_4A3EEC(12321, 0);
        I2C_WRITE_sub_4A3EEC(12358, 225); //0x3046 225 = LVDS 4CH - 12bit
        I2C_WRITE_sub_4A3EEC(12380, 24);
        I2C_WRITE_sub_4A3EEC(12382, 32);
        I2C_WRITE_sub_4A3EEC(12400, 2);
        I2C_WRITE_sub_4A3EEC(12401, 17);
        I2C_WRITE_sub_4A3EEC(12443, 16);
        I2C_WRITE_sub_4A3EEC(12444, 34);
        I2C_WRITE_sub_4A3EEC(12450, 2);
        I2C_WRITE_sub_4A3EEC(12454, 32);
        I2C_WRITE_sub_4A3EEC(12456, 32);
        I2C_WRITE_sub_4A3EEC(12458, 32);
        I2C_WRITE_sub_4A3EEC(12460, 32);
        I2C_WRITE_sub_4A3EEC(12464, 67);
        I2C_WRITE_sub_4A3EEC(12569, 158);
        I2C_WRITE_sub_4A3EEC(12572, 30);
        I2C_WRITE_sub_4A3EEC(12574, 8);
        I2C_WRITE_sub_4A3EEC(12584, 5);
        I2C_WRITE_sub_4A3EEC(12605, 131);
        I2C_WRITE_sub_4A3EEC(12624, 3);
        I2C_WRITE_sub_4A3EEC(12638, 26);
        I2C_WRITE_sub_4A3EEC(12644, 26);
        I2C_WRITE_sub_4A3EEC(12668, 0);
        I2C_WRITE_sub_4A3EEC(12670, 0);
        I2C_WRITE_sub_4A3EEC(12670, 0);
        I2C_WRITE_sub_4A3EEC(12984, 80);
        I2C_WRITE_sub_4A3EEC(12985, 16);
        I2C_WRITE_sub_4A3EEC(12986, 0);
        I2C_WRITE_sub_4A3EEC(12987, 4);
        I2C_WRITE_sub_4A3EEC(13000, 80);
        I2C_WRITE_sub_4A3EEC(13001, 16);
        I2C_WRITE_sub_4A3EEC(13002, 0);
        I2C_WRITE_sub_4A3EEC(13003, 4);
        I2C_WRITE_sub_4A3EEC(13100, 211);
        I2C_WRITE_sub_4A3EEC(13101, 16);
        I2C_WRITE_sub_4A3EEC(13102, 13);
        I2C_WRITE_sub_4A3EEC(13144, 6);
        I2C_WRITE_sub_4A3EEC(13145, 225);
        I2C_WRITE_sub_4A3EEC(13146, 17);
        I2C_WRITE_sub_4A3EEC(13152, 30);
        I2C_WRITE_sub_4A3EEC(13153, 97);
        I2C_WRITE_sub_4A3EEC(13154, 16);
        I2C_WRITE_sub_4A3EEC(13232, 80);
        I2C_WRITE_sub_4A3EEC(13234, 26);
        I2C_WRITE_sub_4A3EEC(13235, 4);
        usleep(0x4E20u);  //delay_ms(20);
        I2C_WRITE_sub_4A3EEC(12288, 0);
        I2C_WRITE_sub_4A3EEC(12290, 0);
        I2C_WRITE_sub_4A3EEC(12361, 10);
        result = puts("----IMX290 1080P 30fps LINE Init OK!------------------------");
      }
    }
  }
  else
  {
    v3 = 0;
    HI_MPI_SYS_GetReg(302055468, &v3);
    v3 = v3 & 0xFC7FFFFF | 0x800000;
    HI_MPI_SYS_SetReg(302055468, v3);
    usleep(0x186A0u);
    I2C_WRITE_sub_4A3EEC(12291, 1);
    usleep(0x186A0u);
    I2C_WRITE_sub_4A3EEC(12290, v2);
    I2C_WRITE_sub_4A3EEC(12303, v2);
    I2C_WRITE_sub_4A3EEC(12304, 33);
    I2C_WRITE_sub_4A3EEC(12306, 100);
    I2C_WRITE_sub_4A3EEC(12310, 9);
    I2C_WRITE_sub_4A3EEC(12362, 192);
    I2C_WRITE_sub_4A3EEC(12363, v2);
    I2C_WRITE_sub_4A3EEC(12380, 24);
    I2C_WRITE_sub_4A3EEC(12381, v2);
    I2C_WRITE_sub_4A3EEC(12382, 32);
    I2C_WRITE_sub_4A3EEC(12383, 1);
    I2C_WRITE_sub_4A3EEC(12400, 2);
    I2C_WRITE_sub_4A3EEC(12401, 17);
    I2C_WRITE_sub_4A3EEC(12443, 16);
    I2C_WRITE_sub_4A3EEC(12444, 34);
    I2C_WRITE_sub_4A3EEC(12450, 2);
    I2C_WRITE_sub_4A3EEC(12454, 32);
    I2C_WRITE_sub_4A3EEC(12456, 32);
    I2C_WRITE_sub_4A3EEC(12458, 32);
    I2C_WRITE_sub_4A3EEC(12460, 32);
    I2C_WRITE_sub_4A3EEC(12464, 67);
    I2C_WRITE_sub_4A3EEC(12569, 158);
    I2C_WRITE_sub_4A3EEC(12572, 30);
    I2C_WRITE_sub_4A3EEC(12574, 8);
    I2C_WRITE_sub_4A3EEC(12584, 5);
    I2C_WRITE_sub_4A3EEC(12585, v2);
    I2C_WRITE_sub_4A3EEC(12605, 131);
    I2C_WRITE_sub_4A3EEC(12624, 3);
    I2C_WRITE_sub_4A3EEC(12638, 26);
    I2C_WRITE_sub_4A3EEC(12644, 26);
    I2C_WRITE_sub_4A3EEC(12670, v2);
    I2C_WRITE_sub_4A3EEC(12668, v2);
    I2C_WRITE_sub_4A3EEC(12780, 14);
    I2C_WRITE_sub_4A3EEC(12984, 80);
    I2C_WRITE_sub_4A3EEC(12985, 16);
    I2C_WRITE_sub_4A3EEC(12986, v2);
    I2C_WRITE_sub_4A3EEC(12987, 4);
    I2C_WRITE_sub_4A3EEC(13000, 80);
    I2C_WRITE_sub_4A3EEC(13001, 16);
    I2C_WRITE_sub_4A3EEC(13002, v2);
    I2C_WRITE_sub_4A3EEC(13003, 4);
    I2C_WRITE_sub_4A3EEC(13100, 211);
    I2C_WRITE_sub_4A3EEC(13101, 16);
    I2C_WRITE_sub_4A3EEC(13102, 13);
    I2C_WRITE_sub_4A3EEC(13144, 6);
    I2C_WRITE_sub_4A3EEC(13145, 225);
    I2C_WRITE_sub_4A3EEC(13146, 17);
    I2C_WRITE_sub_4A3EEC(13152, 30);
    I2C_WRITE_sub_4A3EEC(13153, 97);
    I2C_WRITE_sub_4A3EEC(13154, 16);
    I2C_WRITE_sub_4A3EEC(13232, 80);
    I2C_WRITE_sub_4A3EEC(13234, 26);
    I2C_WRITE_sub_4A3EEC(13235, 4);
    I2C_WRITE_sub_4A3EEC(13440, 73);
    I2C_WRITE_sub_4A3EEC(12297, 18);
    I2C_WRITE_sub_4A3EEC(12288, v2);
    I2C_WRITE_sub_4A3EEC(12290, v2);
    usleep(0x186A0u);
    I2C_WRITE_sub_4A3EEC(12316, 48);
    I2C_WRITE_sub_4A3EEC(12317, 17);
    result = puts("Sony IMX290 Init success! 30fps ~~~~~~~~~~~~~~~~~~~~~~~~~");
  }
  return result;
}


//regexp tofind all digits \((\d+)\,
https://vi.stackexchange.com/questions/7104/how-do-i-replace-a-character-with-its-hex-value
