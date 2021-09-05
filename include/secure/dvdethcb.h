/*---------------------------------------------------------------------------*
  Project:  Dolphin DVDETH middle-level functions
  File:     dvdethcb.h

  Copyright 2002  Nintendo.  All rights reserved.

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

    
    7     03/09/08 4:22p Ueno_kyu
    Modefied DVDRemoveAsyncPrio not to use offset.
    
    5     03/09/05 9:16a Ueno_kyu
    
    4     03/09/03 10:51a Ueno_kyu
    03/09/2003 10:50a Ueno
    
    3     03/09/02 5:23p Ueno_kyu
    02/09/2003 3rd release version.
    
    1     03/02/28 5:34p Ooshima
    2nd release version
    3     03/08/18 10:26a Ueno

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __DVDETHCB_H__
#define __DVDETHCB_H__

#include <revolution/types.h>
#include <revolution/dvd.h>
#include <secure/dvdlow.h>

extern BOOL bNetConfigured;	

//defined in dvdcb.h

/*
#define DVD_COMMAND_READ                        1
#define DVD_COMMAND_SEEK                        2
#define DVD_COMMAND_CHANGE_DISK                 3
#define DVD_COMMAND_BSREAD                      4
#define DVD_COMMAND_READID                      5
#define DVD_COMMAND_INITSTREAM                  6
#define DVD_COMMAND_CANCELSTREAM                7
#define DVD_COMMAND_STOP_STREAM_AT_END          8
#define DVD_COMMAND_REQUEST_AUDIO_ERROR         9
#define DVD_COMMAND_REQUEST_PLAY_ADDR           10
#define DVD_COMMAND_REQUEST_START_ADDR          11
#define DVD_COMMAND_REQUEST_LENGTH              12
#define DVD_COMMAND_AUDIO_BUFFER_CONFIG         13
#define DVD_COMMAND_INQUIRY                     14
#define DVD_COMMAND_BS_CHANGE_DISK              15
*/

#define DVD_COMMAND_NETBASE                     32
#define DVD_COMMAND_NETREAD                     32 
#define DVD_COMMAND_WRITE                       33
#define DVD_COMMAND_CREATE                      34
#define DVD_COMMAND_REMOVE                      35
#define DVD_COMMAND_FSTENTRYREAD                36
#define DVD_COMMAND_FSTSTRINGREAD               37

#define DVD_COMMAND_MAX                         38

#define NET_RESULT_FAIL                         -1

BOOL DVDNetReadAbsAsyncPrio(DVDCommandBlock *block, void* addr, s32 length,
                            s32 offset, DVDCBCallback callback, s32 prio);
BOOL DVDWriteAbsAsyncPrio  (DVDCommandBlock *block, void* addr, s32 length, 
                            s32 offset, DVDCBCallback callback, s32 prio);
BOOL DVDRemoveAsyncPrio(DVDCommandBlock *block, void* addr, u32 length,
                         DVDCBCallback callback, const char* fileName, s32 prio);
BOOL DVDCreateAsyncPrio(DVDCommandBlock *block, void* addr, u32 length,
                         DVDCBCallback callback, const char* fileName, s32 prio);
// Exported from dvdethlow.c
BOOL DVDLowCommand      ( void* pRecv, u32 command,
                         u32 recvlen, u32 entryNum,
                         DVDLowCallback callback, const char *pFileName );

BOOL DVDLowNetRead       ( void* addr, u32 length, u32 offset,
                           DVDLowCallback callback, u32 startAddr );

BOOL DVDLowWrite		( void* addr, u32 length, u32 offset, 
						   DVDLowCallback callback, u32 startAddr );

BOOL DVDLowCancel       ( DVDLowCallback callback );

u32	ErrorMsg(s32 error_no);

#endif  // __DVDETHCB_H__


// 3rd release version
BOOL DVDLowNetReadFst(void* addr, u32 length, u32 offset, DVDLowCallback callback,
                                    u32 command);
BOOL DVDNetReadFstEntryAsyncPrio(DVDCommandBlock* block, void* addr, u32 length,
                                 DVDCBCallback callback, s32 prio);
BOOL DVDNetReadFstStringAsyncPrio(DVDCommandBlock* block, void* addr, u32 length,
                                 DVDCBCallback callback, s32 prio);
BOOL DVDConvertEntrynumToPath(s32 entrynum, char* path, u32 maxlen);

