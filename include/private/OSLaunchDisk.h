/*---------------------------------------------------------------------------*
  Project:      Launch DISC application
  File:         OSLaunchDisk.h

  Copyright (C) 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $

 *---------------------------------------------------------------------------*/

#ifndef __OSLAUNCHDISK_H__
#define __OSLAUNCHDISK_H__

#include <revolution/types.h>
#include <revolution/dvd.h>

#ifdef __cplusplus
extern "C" {
#endif

void OSLaunchDiskv(DVDDiskID* id, u32 LaunchCode, char* const argv[]);
void OSLaunchDiskl(DVDDiskID* id, u32 LaunchCode, const char* arg0, .../*, (char*)NULL */);
BOOL DVDPrepareDiskAsync(DVDCommandBlock* block, DVDDiskID* id, DVDCBCallback callback);

#ifdef __cplusplus
}
#endif

#endif // __OSLAUNCHDISK_H__