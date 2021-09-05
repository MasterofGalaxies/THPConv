/*
 *               Copyright (C) 2006, BroadOn Communications Corp.
 *
 *  These coded instructions, statements, and computer programs contain
 *  unpublished  proprietary information of BroadOn Communications Corp.,
 *  and  are protected by Federal copyright law. They may not be disclosed
 *  to  third  parties or copied or duplicated in any form, in whole or in
 *  part, without the prior written consent of BroadOn Communications Corp.
 *
 */
#ifndef __IPCCLT_H__
#define __IPCCLT_H__

#define IPC_STACK_SIZE      16 * 1024
#define IPC_EMU_STACK_SIZE  16 * 1024

#define MAX_SRV_INFLIGHT    8


extern
u8 __iosIpcStack[];

#endif /* __IPCCLT_H__ */

