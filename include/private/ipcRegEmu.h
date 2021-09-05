/*---------------------------------------------------------------------------*
  Project:  IPC Register Emulation Library
  File:     ipcregemu.h

  Copyright 2005-2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __IPCREGEMU_H__
#define __IPCREGEMU_H__

#ifdef linux

#include "../wkmc/wkmc.h"
#include "../ipc/ipc.h"

#else

#include <revolution/os.h>
#include <private/ipc.h>

#endif

#ifdef __cplusplus
extern "C" {
#endif

extern s32  IPCRegEmuInit(void);
extern void IPCRegEmuStop(void);
extern s32  IPCRegEmuTick(void);

extern u32  IPCRegEmuReadReg(u32 regIdx);
extern void IPCRegEmuWriteReg(u32 regIdx, u32 data);

#ifdef __cplusplus
}
#endif

#endif  // __IPCREGEMU_H__
