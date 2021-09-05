/*---------------------------------------------------------------------------*
  Project:      Launch NAND application and handling
  File:         OSLaunchForShop.h

  Copyright (C) 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
 *---------------------------------------------------------------------------*/

#ifndef __OSLAUNCHFORSHOP_H__
#define __OSLAUNCHFORSHOP_H__

#include <revolution/types.h>
#include <private/OSTitle.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OSLAUNCH_TID_SHOPCH   (0x0001000248414241)
#define OSLAUNCH_CODE_SHOPCH  (2)

void OSLaunchTitlevForShop(OSTitleId titleId, u32 LaunchCode, char* const argv[]);
void OSLaunchTitlelForShop(OSTitleId titleId, u32 LaunchCode, const char* arg0, .../*, (char*)NULL */);

#ifdef __cplusplus
}
#endif

#endif // __OSLAUNCHFORSHOP_H__