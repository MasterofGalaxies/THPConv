/*---------------------------------------------------------------------------*
  Project:  Dolphin header file for gcam
  File:     gcam.h

  Copyright 2001 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    4     02/12/20 15:36 Hashida
    Added DVDExitInitialData().
    
    3     02/02/14 14:48 Hashida
    Added C++ support.
    
    2     02/02/06 17:49 Hashida
    Added support for JAMMA video standard.
    
    1     1/02/02 5:17p Hashida
    Initial revision for GC-AM support.
    
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __GCAM_H__
#define __GCAM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>
#include <revolution/dvd.h>

#define VI_GCA                      6
#define VI_TVMODE_GCA_INT           (VITVMode)VI_TVMODE(VI_GCA, VI_INTERLACE)
#define VI_TVMODE_GCA_PROG          (VITVMode)VI_TVMODE(VI_GCA, VI_PROGRESSIVE)


void GCAMInit(u32 seed);

s32 DVDWritePrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, s32
                 prio);
BOOL DVDWriteAsyncPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset,
                       DVDCallback callback, s32 prio);

BOOL DVDWriteAbsAsyncPrio(DVDCommandBlock *block, void* addr, s32 length,
                          s32 offset, DVDCBCallback callback, s32 prio);

#define DVDWriteAsync(fileInfo, addr, length, offset, callback)  \
                         DVDWriteAsyncPrio((fileInfo), (addr), (length), (offset), (callback), 2)
#define DVDWrite(fileInfo, addr, length, offset)                 \
                         DVDWritePrio((fileInfo), (addr), (length), (offset), 2)

BOOL DVDGetDeviceIDAsync(DVDCommandBlock *block, DVDCBCallback callback);
s32 DVDGetDeviceID(DVDCommandBlock *block);

BOOL DVDChangeBankAsync(DVDCommandBlock *block, u32 bank, DVDCBCallback callback);
s32 DVDChangeBank(DVDCommandBlock *block, u32 bank);

BOOL DVDSetInitialDataAsync(DVDCommandBlock *block, u32 initData0,
                            u32 initData1, u32 initData2, DVDCBCallback callback);
s32 DVDSetInitialData(DVDCommandBlock *block, u32 initData0, u32 initData1,
                      u32 initData2);
void DVDExitInitialData(void);
  
#ifdef __cplusplus
}
#endif

#endif  // __GCAM_H__
