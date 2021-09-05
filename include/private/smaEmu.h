/*---------------------------------------------------------------------------*
  Project:    Shared Memory Access Emulation Library
  File:       smaEmu.h
  Programer:  TOKUNAGA, Yasuhiro

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.4  2006/02/04 13:05:45  hashida
  (none)

  Revision 1.3  2006/01/17 12:38:40  yasuh-to
  Deleted interface of set callback function

  Revision 1.2  2006/01/17 10:54:26  yasuh-to
  Added error state

  Revision 1.1  2006/01/16 06:00:06  yasuh-to
  Initial check-in

  Revision 1.1  2006/01/12 10:57:30  yasuh-to
  Initial check-in

  $NoKeywords: $
 *---------------------------------------------------------------------------*/
#ifndef __SMAEMU_H__
#define __SMAEMU_H__

#include <revolution/os.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SMAEMU_ERR_NONE            0
#define SMAEMU_ERR_NO_RESPONSE    -1
#define SMAEMU_ERR_TRANSFER       -2

void SMAEMUInit(void);
s32  SMAEMUTick(void);

#ifdef __cplusplus
}
#endif

#endif  // __SMAEMU_H__
