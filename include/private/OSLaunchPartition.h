/*---------------------------------------------------------------------------*
  Project:      Launch partition
  File:         OSLaunchParition.h

  Copyright (C) 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
 *---------------------------------------------------------------------------*/

#ifndef __OSLAUNCHPARITION_H__
#define __OSLAUNCHPARITION_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OS_RESETCODE_LAUNCH     0xA0000000

typedef u64 OSTitleId;

void OSLaunchPartitionv(OSTitleId titleId, u32 launchCode, char* const argv[]);
void OSLaunchPartitionl(OSTitleId titleId, u32 launchCode, const char* arg0, .../*, (char*)NULL */);

u32  OSGetLaunchCode(void);

#ifdef __cplusplus
}
#endif

#endif // __OSLAUNCHPARTITION_H__