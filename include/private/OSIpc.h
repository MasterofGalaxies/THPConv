/*---------------------------------------------------------------------------*
  Project:  Revolution OS IPC buffer allocation API
  File:     OSIpc.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.2  2006/02/04 13:05:45  hashida
  (none)

  Revision 1.1  2006/01/23 12:22:26  hirose
  Initial check in.


  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSIPC_H__
#define __OSIPC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>
#include <revolution/os/OSInterrupt.h>

/*---------------------------------------------------------------------------*
    IPC Buffer Allocation API
 *---------------------------------------------------------------------------*/

// Temporary
#define         DEFAULT_IPC_BUFFER_SIZE     0x00040000      // 256KB

extern void*    __OSGetIPCBufferHi( void );
extern void*    __OSGetIPCBufferLo( void );
extern void     __OSInitIPCBuffer( void );

/*---------------------------------------------------------------------------*
    IPC Interrupt Emulation API
 *---------------------------------------------------------------------------*/
// Emulation of ACR interrupt used for IPC driver.
#ifdef EMU_PI_ACRINT
extern void __OSEmulateACRInt( void );
#endif

/*---------------------------------------------------------------------------*/


#ifdef __cplusplus
}
#endif

#endif  // __OSIPC_H__
