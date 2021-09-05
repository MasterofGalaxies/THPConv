/*
 *               Copyright (C) 2005, BroadOn Communications Corp.
 *
 *  These coded instructions, statements, and computer programs contain
 *  unpublished  proprietary information of BroadOn Communications Corp.,
 *  and  are protected by Federal copyright law. They may not be disclosed
 *  to  third  parties or copied or duplicated in any form, in whole or in
 *  part, without the prior written consent of BroadOn Communications Corp.
 *
 */

#ifndef __IOP_ICMP_H__
#define __IOP_ICMP_H__

#ifdef __cplusplus
extern "C" {
#endif

#define ICMP_SOCKET_MAX         4

s32 ICMPSocket(int af);
s32 ICMPPing(s32 info, const void* data, s32 len,
             const void* remote, OSTime timeout);
s32 ICMPCancel(s32 info);
s32 ICMPClose(s32 info);

#ifdef __cplusplus
}
#endif

#endif  /* __IOP_ICMP_H__ */
