/*---------------------------------------------------------------------------*
  Project:  Revolution MIC library
  File:     mic.h

  Copyright (C)2004-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __MIC_H__
#define __MIC_H__

#ifdef __cplusplus
extern "C" {
#endif


//
// 定義
//

// デバドラ用バッファのサイズ
//    12KB =  約 139msec 分 @ 44100Hz
//         =  約 279msec 分 @ 22050Hz
//         =  約 557msec 分 @ 11025Hz
#define MIC_RINGBUFF_SIZE         12288

// 返り値・ステート etc.
#define MIC_RESULT_UNLOCKED           1
#define MIC_RESULT_READY              0
#define MIC_RESULT_BUSY              -1
#define MIC_RESULT_WRONGDEVICE       -2
#define MIC_RESULT_NOCARD            -3
#define MIC_RESULT_INVALID_STATE     -4
#define MIC_RESULT_FATAL_ERROR     -128

// ボタンビット
#define MIC_BUTTON_0             0x0001 // (0000_0000_0000_0001)2
#define MIC_BUTTON_1             0x0002 // (0000_0000_0000_0010)2
#define MIC_BUTTON_2             0x0004 // (0000_0000_0000_0100)2
#define MIC_BUTTON_3             0x0008 // (0000_0000_0000_1000)2
#define MIC_BUTTON_4             0x0010 // (0000_0000_0001_0000)2
#define MIC_BUTTON_TALK    MIC_BUTTON_4 // (0000_0000_0001_0000)2

// デバイス ID
#define MIC_BMC              0x00000000

    
//
// 関数
//

typedef void (*MICCallback)( s32 chan, s32 result );

void MICInit             ( void );
s32  MICProbeEx          ( s32 chan );
s32  MICGetResultCode    ( s32 chan );
u32  MICGetErrorCount    ( s32 chan );
    
s32  MICMountAsync       ( s32  chan, s16*        buffer,
                                      s32         size,
                                      MICCallback detachCallback,
                                      MICCallback attachCallback );
s32  MICMount            ( s32  chan, s16*        buffer,
                                      s32         size,
                                      MICCallback detachCallback);
s32  MICUnmount          ( s32 chan );
s32  MICGetRingbuffsize  ( s32 chan, s32* size );
    
s32  MICSetStatusAsync   ( s32 chan, u32  status, MICCallback setCallback );
s32  MICSetStatus        ( s32 chan, u32  status );
s32  MICGetStatus        ( s32 chan, u32* status );

s32  MICSetParamsAsync   ( s32 chan, s32         size,
                                     s32         rate,
                                     s32         gain,
                                     MICCallback setCallback );
s32  MICSetParams        ( s32 chan, s32  size, s32  rate, s32  gain );
s32  MICGetParams        ( s32 chan, s32* size, s32* rate, s32* gain );

s32  MICSetBuffsizeAsync ( s32 chan, s32  size, MICCallback setCallback );
s32  MICSetBuffsize      ( s32 chan, s32  size );
s32  MICGetBuffsize      ( s32 chan, s32* size );

s32  MICSetRateAsync     ( s32 chan, s32  rate, MICCallback setCallback );
s32  MICSetRate          ( s32 chan, s32  rate );
s32  MICGetRate          ( s32 chan, s32* rate );

s32  MICSetGainAsync     ( s32 chan, s32  gain, MICCallback setCallback );
s32  MICSetGain          ( s32 chan, s32  gain );
s32  MICGetGain          ( s32 chan, s32* gain );

s32  MICGetButton        ( s32 chan, u32* button );
s32  MICGetDeviceID      ( s32 chan, u32* id );
    
s32  MICSetOutAsync      ( s32 chan, u32  pattern, MICCallback setCallback );
s32  MICSetOut           ( s32 chan, u32  pattern );
s32  MICGetOut           ( s32 chan, u32* pattern );

s32  MICStartAsync       ( s32 chan, MICCallback startCallback );
s32  MICStart            ( s32 chan );

s32  MICStopAsync        ( s32 chan, MICCallback stopCallback  );
s32  MICStop             ( s32 chan );

s32  MICResetAsync       ( s32 chan, MICCallback stopCallback  );
s32  MICReset            ( s32 chan );

BOOL MICIsActive         ( s32 chan );
BOOL MICIsAttached       ( s32 chan );

s32  MICGetCurrentTop    ( s32 chan );
s32  MICUpdateIndex      ( s32 chan, s32 index, s32 samples );
s32  MICGetSamplesLeft   ( s32 chan, s32 index );
s32  MICGetSamples       ( s32 chan, s16* buffer, s32 index, s32 samples );

MICCallback  MICSetExiCallback( s32 chan, MICCallback exiCallback );
MICCallback  MICSetTxCallback ( s32 chan, MICCallback txCallback  );


#ifdef __cplusplus
}
#endif

#endif /* __MIC_H__ */
