/*---------------------------------------------------------------------------*
  Project:     Waikiki library
  File:        wk.h
  Programmers: Zuyama Yasuhiko
               HIRATSU Daisuke

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/


#ifndef WK_H__
#define WK_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

BOOL WKProbe   ( s32 chan );
BOOL WKCheckBuf( s32 chan, u16 *send, u16 *recv );
s32  WKRead    ( s32 chan, void *buf, u32 len );
s32  WKReadNoConv    ( s32 chan, void *buf, u32 len );
s32  WKWrite   ( s32 chan, void *buf, u32 len );
s32  WKWriteNoConv   ( s32 chan, void *buf, u32 len );

#ifdef __cplusplus
}
#endif

#endif  // WK_H__
