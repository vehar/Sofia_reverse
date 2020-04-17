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

//Detect sensor
      sensor_i2c_addr = 52;
      *(_DWORD *)&sensor_addr_byte = 2;
      *(_DWORD *)&sensor_data_byte = 1;
      Init_i2c_0_sub_4A3CAC();
      v4 = CMD_I2C_READ_sub_4A3DD0(12764) & 7;
      printf("IMX29%d SensorID 0x%x\n", v4, v4);
	  
	  
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
      if ( (unsigned int)(genSensorMode - 0x3) <= 1 ) //Current init!!!!!
      {
        HI_MPI_SYS_GetReg(0x1201002C, &v3);
        v3 = v3 & 0xFC7DFFFF | 0x800000;
        HI_MPI_SYS_SetReg(0x1201002C, v3);
        I2C_WRITE_sub_4A3EEC(0x3000, 0x1); //0x3000 1 Standby
        usleep(0x186A0u);
        I2C_WRITE_sub_4A3EEC(0x3007, 0x0);
        I2C_WRITE_sub_4A3EEC(0x3009, 0x1);
        I2C_WRITE_sub_4A3EEC(0x300A, 0xF0);
        I2C_WRITE_sub_4A3EEC(0x300F, 0x0);
        I2C_WRITE_sub_4A3EEC(0x3010, 0x21);
        I2C_WRITE_sub_4A3EEC(0x3012, 0x64);
        I2C_WRITE_sub_4A3EEC(0x3014, 0x20);
        I2C_WRITE_sub_4A3EEC(0x3016, 0x9);
        I2C_WRITE_sub_4A3EEC(0x3016, 0x9);
        I2C_WRITE_sub_4A3EEC(0x3018, 0x65);
        I2C_WRITE_sub_4A3EEC(0x3019, 0x4);
        I2C_WRITE_sub_4A3EEC(0x301A, 0x0);
        I2C_WRITE_sub_4A3EEC(0x301B, 0x0);
        I2C_WRITE_sub_4A3EEC(0x301C, 0x98);
        I2C_WRITE_sub_4A3EEC(0x301D, 0x8);
        I2C_WRITE_sub_4A3EEC(0x3020, 0x1);
        I2C_WRITE_sub_4A3EEC(0x3021, 0x0);
        I2C_WRITE_sub_4A3EEC(0x3046, 0xE1); //0x3046 225 = LVDS 4CH - 12bit
        I2C_WRITE_sub_4A3EEC(0x305C, 0x18);
        I2C_WRITE_sub_4A3EEC(0x305E, 0x20);
        I2C_WRITE_sub_4A3EEC(0x3070, 0x2);
        I2C_WRITE_sub_4A3EEC(0x3071, 0x11);
        I2C_WRITE_sub_4A3EEC(0x309B, 0x10);
        I2C_WRITE_sub_4A3EEC(0x309C, 0x22);
        I2C_WRITE_sub_4A3EEC(0x30A2, 0x2);
        I2C_WRITE_sub_4A3EEC(0x30A6, 0x20);
        I2C_WRITE_sub_4A3EEC(0x30A8, 0x20);
        I2C_WRITE_sub_4A3EEC(0x30AA, 0x20);
        I2C_WRITE_sub_4A3EEC(0x30AC, 0x20);
        I2C_WRITE_sub_4A3EEC(0x30B0, 0x43);
        I2C_WRITE_sub_4A3EEC(0x3119, 0x9E);
        I2C_WRITE_sub_4A3EEC(0x311C, 0x1E);
        I2C_WRITE_sub_4A3EEC(0x311E, 0x8);
        I2C_WRITE_sub_4A3EEC(0x3128, 0x5);
        I2C_WRITE_sub_4A3EEC(0x313D, 0x83);
        I2C_WRITE_sub_4A3EEC(0x3150, 0x3);
        I2C_WRITE_sub_4A3EEC(0x315E, 0x1A);
        I2C_WRITE_sub_4A3EEC(0x3164, 0x1A);
        I2C_WRITE_sub_4A3EEC(0x317C, 0x0);
        I2C_WRITE_sub_4A3EEC(0x317E, 0x0);
        I2C_WRITE_sub_4A3EEC(0x317E, 0x0);
        I2C_WRITE_sub_4A3EEC(0x32B8, 0x50);
        I2C_WRITE_sub_4A3EEC(0x32B9, 0x10);
        I2C_WRITE_sub_4A3EEC(0x32BA, 0x0);
        I2C_WRITE_sub_4A3EEC(0x32BB, 0x4);
        I2C_WRITE_sub_4A3EEC(0x32C8, 0x50);
        I2C_WRITE_sub_4A3EEC(0x32C9, 0x10);
        I2C_WRITE_sub_4A3EEC(0x32CA, 0x0);
        I2C_WRITE_sub_4A3EEC(0x32CB, 0x4);
        I2C_WRITE_sub_4A3EEC(0x332C, 0xD3);
        I2C_WRITE_sub_4A3EEC(0x332D, 0x10);
        I2C_WRITE_sub_4A3EEC(0x332E, 0xD);
        I2C_WRITE_sub_4A3EEC(0x3358, 0x6);
        I2C_WRITE_sub_4A3EEC(0x3359, 0xE1);
        I2C_WRITE_sub_4A3EEC(0x335A, 0x11);
        I2C_WRITE_sub_4A3EEC(0x3360, 0x1E);
        I2C_WRITE_sub_4A3EEC(0x3361, 0x61);
        I2C_WRITE_sub_4A3EEC(0x3362, 0x10);
        I2C_WRITE_sub_4A3EEC(0x33B0, 0x50);
        I2C_WRITE_sub_4A3EEC(0x33B2, 0x1A);
        I2C_WRITE_sub_4A3EEC(0x33B3, 0x4);
        usleep(0x4E20u);
        I2C_WRITE_sub_4A3EEC(0x3000, 0x0);
        I2C_WRITE_sub_4A3EEC(0x3002, 0x0);
        I2C_WRITE_sub_4A3EEC(0x3049, 0xA);
        result = puts("--IMX291 1080P 60fps LINE Init OK!-------------------");
      }
      else
      {
        HI_MPI_SYS_GetReg(0x1201002C, &v3);
        v3 = v3 & 0xFC7DFFFF | 0x800000;
        HI_MPI_SYS_SetReg(0x1201002C, v3);
        I2C_WRITE_sub_4A3EEC(0x3000, 0x1);
        usleep(0x186A0u);
        I2C_WRITE_sub_4A3EEC(0x3007, 0x0);
        I2C_WRITE_sub_4A3EEC(0x3009, 0x2); /* Gain */
        I2C_WRITE_sub_4A3EEC(0x300A, 0xF0);
        I2C_WRITE_sub_4A3EEC(0x300F, 0x0);
        I2C_WRITE_sub_4A3EEC(0x3010, 0x21);
        I2C_WRITE_sub_4A3EEC(0x3012, 0x64);
        I2C_WRITE_sub_4A3EEC(0x3014, 0x20);
        I2C_WRITE_sub_4A3EEC(0x3016, 0x9);
        I2C_WRITE_sub_4A3EEC(0x3016, 0x9);
        I2C_WRITE_sub_4A3EEC(0x3018, 0x6D);
        I2C_WRITE_sub_4A3EEC(0x3019, 0x4);
        I2C_WRITE_sub_4A3EEC(0x301A, 0x0);
        I2C_WRITE_sub_4A3EEC(0x301B, 0x0);
        I2C_WRITE_sub_4A3EEC(0x301C, 0x30);
        I2C_WRITE_sub_4A3EEC(0x301D, 0x11);
        I2C_WRITE_sub_4A3EEC(0x3020, 0x1); /* SHS1 */
        I2C_WRITE_sub_4A3EEC(0x3021, 0x0);
        I2C_WRITE_sub_4A3EEC(0x3046, 0xE1); //0x3046 225 = LVDS 4CH - 12bit
        I2C_WRITE_sub_4A3EEC(0x305C, 0x18);
        I2C_WRITE_sub_4A3EEC(0x305E, 0x20);
        I2C_WRITE_sub_4A3EEC(0x3070, 0x2);
        I2C_WRITE_sub_4A3EEC(0x3071, 0x11);
        I2C_WRITE_sub_4A3EEC(0x309B, 0x10);
        I2C_WRITE_sub_4A3EEC(0x309C, 0x22);
        I2C_WRITE_sub_4A3EEC(0x30A2, 0x2);
        I2C_WRITE_sub_4A3EEC(0x30A6, 0x20);
        I2C_WRITE_sub_4A3EEC(0x30A8, 0x20);
        I2C_WRITE_sub_4A3EEC(0x30AA, 0x20);
        I2C_WRITE_sub_4A3EEC(0x30AC, 0x20);
        I2C_WRITE_sub_4A3EEC(0x30B0, 0x43);
        I2C_WRITE_sub_4A3EEC(0x3119, 0x9E);
        I2C_WRITE_sub_4A3EEC(0x311C, 0x1E);
        I2C_WRITE_sub_4A3EEC(0x311E, 0x8);
        I2C_WRITE_sub_4A3EEC(0x3128, 0x5);
        I2C_WRITE_sub_4A3EEC(0x313D, 0x83);
        I2C_WRITE_sub_4A3EEC(0x3150, 0x3);
        I2C_WRITE_sub_4A3EEC(0x315E, 0x1A);
        I2C_WRITE_sub_4A3EEC(0x3164, 0x1A);
        I2C_WRITE_sub_4A3EEC(0x317C, 0x0);
        I2C_WRITE_sub_4A3EEC(0x317E, 0x0);
        I2C_WRITE_sub_4A3EEC(0x317E, 0x0);
        I2C_WRITE_sub_4A3EEC(0x32B8, 0x50);
        I2C_WRITE_sub_4A3EEC(0x32B9, 0x10);
        I2C_WRITE_sub_4A3EEC(0x32BA, 0x0);
        I2C_WRITE_sub_4A3EEC(0x32BB, 0x4);
        I2C_WRITE_sub_4A3EEC(0x32C8, 0x50);
        I2C_WRITE_sub_4A3EEC(0x32C9, 0x10);
        I2C_WRITE_sub_4A3EEC(0x32CA, 0x0);
        I2C_WRITE_sub_4A3EEC(0x32CB, 0x4);
        I2C_WRITE_sub_4A3EEC(0x332C, 0xD3);
        I2C_WRITE_sub_4A3EEC(0x332D, 0x10);
        I2C_WRITE_sub_4A3EEC(0x332E, 0xD);
        I2C_WRITE_sub_4A3EEC(0x3358, 0x6);
        I2C_WRITE_sub_4A3EEC(0x3359, 0xE1);
        I2C_WRITE_sub_4A3EEC(0x335A, 0x11);
        I2C_WRITE_sub_4A3EEC(0x3360, 0x1E);
        I2C_WRITE_sub_4A3EEC(0x3361, 0x61);
        I2C_WRITE_sub_4A3EEC(0x3362, 0x10);
        I2C_WRITE_sub_4A3EEC(0x33B0, 0x50);
        I2C_WRITE_sub_4A3EEC(0x33B2, 0x1A);
        I2C_WRITE_sub_4A3EEC(0x33B3, 0x4);
        usleep(0x4E20u);  //delay_ms(20);
        I2C_WRITE_sub_4A3EEC(0x3000, 0x0);
        I2C_WRITE_sub_4A3EEC(0x3002, 0x0);
        I2C_WRITE_sub_4A3EEC(0x3049, 0xA);
        result = puts("----IMX290 1080P 30fps LINE Init OK!------------------------");
      }
    }
  }
  else
  {
    v3 = 0;
    HI_MPI_SYS_GetReg(0x1201002C, &v3);
    v3 = v3 & 0xFC7FFFFF | 0x800000;
    HI_MPI_SYS_SetReg(0x1201002C, v3);
    usleep(0x186A0u);
    I2C_WRITE_sub_4A3EEC(0x3003, 0x1);
    usleep(0x186A0u);
    I2C_WRITE_sub_4A3EEC(0x3002, v2);
    I2C_WRITE_sub_4A3EEC(0x300F, v2);
    I2C_WRITE_sub_4A3EEC(0x3010, 0x21);
    I2C_WRITE_sub_4A3EEC(0x3012, 0x64);
    I2C_WRITE_sub_4A3EEC(0x3016, 0x9);
    I2C_WRITE_sub_4A3EEC(0x304A, 0xC0);
    I2C_WRITE_sub_4A3EEC(0x304B, v2);
    I2C_WRITE_sub_4A3EEC(0x305C, 0x18);
    I2C_WRITE_sub_4A3EEC(0x305D, v2);
    I2C_WRITE_sub_4A3EEC(0x305E, 0x20);
    I2C_WRITE_sub_4A3EEC(0x305F, 0x1);
    I2C_WRITE_sub_4A3EEC(0x3070, 0x2);
    I2C_WRITE_sub_4A3EEC(0x3071, 0x11);
    I2C_WRITE_sub_4A3EEC(0x309B, 0x10);
    I2C_WRITE_sub_4A3EEC(0x309C, 0x22);
    I2C_WRITE_sub_4A3EEC(0x30A2, 0x2);
    I2C_WRITE_sub_4A3EEC(0x30A6, 0x20);
    I2C_WRITE_sub_4A3EEC(0x30A8, 0x20);
    I2C_WRITE_sub_4A3EEC(0x30AA, 0x20);
    I2C_WRITE_sub_4A3EEC(0x30AC, 0x20);
    I2C_WRITE_sub_4A3EEC(0x30B0, 0x43);
    I2C_WRITE_sub_4A3EEC(0x3119, 0x9E);
    I2C_WRITE_sub_4A3EEC(0x311C, 0x1E);
    I2C_WRITE_sub_4A3EEC(0x311E, 0x8);
    I2C_WRITE_sub_4A3EEC(0x3128, 0x5);
    I2C_WRITE_sub_4A3EEC(0x3129, v2);
    I2C_WRITE_sub_4A3EEC(0x313D, 0x83);
    I2C_WRITE_sub_4A3EEC(0x3150, 0x3);
    I2C_WRITE_sub_4A3EEC(0x315E, 0x1A);
    I2C_WRITE_sub_4A3EEC(0x3164, 0x1A);
    I2C_WRITE_sub_4A3EEC(0x317E, v2);
    I2C_WRITE_sub_4A3EEC(0x317C, v2);
    I2C_WRITE_sub_4A3EEC(0x31EC, 0xE);
    I2C_WRITE_sub_4A3EEC(0x32B8, 0x50);
    I2C_WRITE_sub_4A3EEC(0x32B9, 0x10);
    I2C_WRITE_sub_4A3EEC(0x32BA, v2);
    I2C_WRITE_sub_4A3EEC(0x32BB, 0x4);
    I2C_WRITE_sub_4A3EEC(0x32C8, 0x50);
    I2C_WRITE_sub_4A3EEC(0x32C9, 0x10);
    I2C_WRITE_sub_4A3EEC(0x32CA, v2);
    I2C_WRITE_sub_4A3EEC(0x32CB, 0x4);
    I2C_WRITE_sub_4A3EEC(0x332C, 0xD3);
    I2C_WRITE_sub_4A3EEC(0x332D, 0x10);
    I2C_WRITE_sub_4A3EEC(0x332E, 0xD);
    I2C_WRITE_sub_4A3EEC(0x3358, 0x6);
    I2C_WRITE_sub_4A3EEC(0x3359, 0xE1);
    I2C_WRITE_sub_4A3EEC(0x335A, 0x11);
    I2C_WRITE_sub_4A3EEC(0x3360, 0x1E);
    I2C_WRITE_sub_4A3EEC(0x3361, 0x61);
    I2C_WRITE_sub_4A3EEC(0x3362, 0x10);
    I2C_WRITE_sub_4A3EEC(0x33B0, 0x50);
    I2C_WRITE_sub_4A3EEC(0x33B2, 0x1A);
    I2C_WRITE_sub_4A3EEC(0x33B3, 0x4);
    I2C_WRITE_sub_4A3EEC(0x3480, 0x49);
    I2C_WRITE_sub_4A3EEC(0x3009, 0x12);
    I2C_WRITE_sub_4A3EEC(0x3000, v2);
    I2C_WRITE_sub_4A3EEC(0x3002, v2);
    usleep(0x186A0u);
    I2C_WRITE_sub_4A3EEC(0x301C, 0x30);
    I2C_WRITE_sub_4A3EEC(0x301D, 0x11);
    result = puts("Sony IMX290 Init success! 30fps ~~~~~~~~~~~~~~~~~~~~~~~~~");
  }
  return result;
}


//regexp tofind all digits \((\d+)\,
https://vi.stackexchange.com/questions/7104/how-do-i-replace-a-character-with-its-hex-value
