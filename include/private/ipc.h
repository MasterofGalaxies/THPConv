/*---------------------------------------------------------------------------*
  Project:  IPC library
  File:     ipc.h

  Copyright 2005-2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.3  2006/03/06 06:07:42  kawaset
  Added IPCGetBuffer* and IPCSetBuffer*.

  Revision 1.2  2006/01/24 02:29:11  hirose
  Added IPC register definitions.

  Revision 1.1  2006/01/23 13:26:02  yasuh-to
  Initial check-in


  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __IPC_H__
#define __IPC_H__
#ifdef linux
#else
#include <revolution/os.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------*
    Copied part from ahb_fdl_defs.h
 *---------------------------------------------------------------------------*/
#define ACR_REGS_BASE   0x0d000000

#define IPCP2SMSG_OFFSET    0x000
#define IPCPPCCTRL_OFFSET   0x004
#define IPCS2PMSG_OFFSET    0x008
#define IPCIOPCTRL_OFFSET   0x00c


/*---------------------------------------------------------------------------*
    Access macros
 *---------------------------------------------------------------------------*/
#define IPC_NUM_REGS 4
#define IPC_REG_IDX_IPCP2SMSG  0
#define IPC_REG_IDX_IPCPPCCTRL 1
#define IPC_REG_IDX_IPCS2PMSG  2
#define IPC_REG_IDX_IPCIOPCTRL 3

// For both IPCPPCCTRL, IPCIOPCTRL
#define IPC_CTRL_ALL_MASK      0x0000003f
#define IPC_CTRL_ACK_INTR_MASK (1<<5)
#define IPC_CTRL_MSG_INTR_MASK (1<<4)
#define IPC_CTRL_OUT_ACK_MASK  (1<<3)
#define IPC_CTRL_IN_MSG_MASK   (1<<2)
#define IPC_CTRL_IN_ACK_MASK   (1<<1)
#define IPC_CTRL_OUT_MSG_MASK  (1<<0)

/*---------------------------------------------------------------------------*
    Function prototypes
 *---------------------------------------------------------------------------*/
extern void IPCInit(void);

extern u32  IPCReadReg(u32 regIdx);
extern void IPCWriteReg(u32 regIdx, u32 data);

extern void* IPCGetBufferHi( void );
extern void* IPCGetBufferLo( void );
extern void  IPCSetBufferHi( void* newHi );
extern void  IPCSetBufferLo( void* newLo );

/*---------------------------------------------------------------------------*
    IPC profiler functions
 *---------------------------------------------------------------------------*/
#define IPCPROF_MAX_REQS    32

extern u32 IPCGetNumPendingReqs ( void );
extern u32 IPCGetNumUnIssuedReqs( void );
extern s32 IPCGetQueueStatus    ( u32 i );



#ifdef __cplusplus
}
#endif

#endif  // __IPC_H__
