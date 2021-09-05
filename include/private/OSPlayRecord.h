/*---------------------------------------------------------------------------*
  Project:      Play time record
  File:         OSPlayRecord.h

  Copyright (C) 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.4  2006/09/18 10:46:07  shino
  change titleName size in OSPlayRecord structure.

  Revision 1.3  2006/09/05 07:15:04  shino
  change the type of titleName from wchar_t to u16.

  Revision 1.2  2006/08/28 04:23:20  shino
  clean up.

  Revision 1.1  2006/08/28 02:43:01  shino
  initial checkin.


 *---------------------------------------------------------------------------*/

#ifndef __OSPLAYRECORD_H__
#define __OSPLAYRECORD_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>

enum
{
    OS_PLAY_RECORD_INIT,
    OS_PLAY_RECORD_OPEN,
    OS_PLAY_RECORD_READ,
    OS_PLAY_RECORD_SEEK,
    OS_PLAY_RECORD_START_TIMER,
    OS_PLAY_RECORD_WRITE,
    OS_PLAY_RECORD_CLOSE,
    OS_PLAY_RECORD_ERROR,
    OS_PALY_RECORD_END_TIMEOUT,
    OS_PLAY_RECORD_END
};

#define OS_PLAY_RECORD_PATH   "/title/00000001/00000002/data/play_rec.dat"
#define OS_PLAY_RECORD_PERM \
    (NAND_PERM_OWNER_READ | NAND_PERM_OWNER_WRITE | \
     NAND_PERM_GROUP_READ | NAND_PERM_GROUP_WRITE | \
     NAND_PERM_OTHER_READ | NAND_PERM_OTHER_WRITE)
#define OS_PLAY_RECORD_ATTR   0x00
#define OS_PLAY_RECORD_PERIOD ((OSTime)60 * (OSTime)OSSecondsToTicks(1))
#define OS_PLAY_RECORD_CLOSE_PERIOD ((OSTime)300 * (OSTime)OSSecondsToTicks(1))
#define OS_PLAY_RECORD_RETRY_PERIOD ((OSTime)1 * (OSTime)OSSecondsToTicks(1))

#define OS_PLAY_RECORD_TITLE_NAME_SIZE 21
#define OS_PLAY_RECORD_LANGUAGE_NUM    2

typedef struct
{
    u32     checkSum;
    u16     titleName[OS_PLAY_RECORD_LANGUAGE_NUM][OS_PLAY_RECORD_TITLE_NAME_SIZE];
    OSTime  playStartTime;
    OSTime  playTime;
    char    gameCode[4];
    char    companyCode[2];
    char    reserved[18];
} OSPlayRecord;

void __OSCreatePlayRecord(u16 tilteName[][OS_PLAY_RECORD_TITLE_NAME_SIZE], char gameCode[], char companyCode[]);
BOOL __OSReadPlayRecord(OSPlayRecord *record);
void __OSStartPlayRecord(void);
void __OSStopPlayRecord(void);
s32  __OSGetPlayRecordState(void);

#ifdef __cplusplus
}
#endif

#endif // __OSPLAYRECORD_H__