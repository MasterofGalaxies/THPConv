/*---------------------------------------------------------------------------*
  Project:  DI Emulation
  File:     diemu.h

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __DIEMU_H__
#define __DIEMU_H__

#ifdef __cplusplus
extern "C" {
#endif

#define DIEMU_TYPE_INT   0x00
#define DIEMU_TYPE_REG   0x01
#define DIEMU_TYPE_DAT   0x02

__declspec(weak) void __DIEMUInterruptHandler(__OSInterrupt interrupt, OSContext* context);

void DIEMUInit(void);
void DIEMUTick(void);

#ifdef __cplusplus
}
#endif

#endif  // __DIEMU_H__
