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

/*---------------------------------------------------------------------------*
 * 
 * definitions and structures used between socket lib and network stack
 * 
 *---------------------------------------------------------------------------*/

#ifndef __IOP_IP6_H__
#define __IOP_IP6_H__

#define SO_AF_INET6         23
#define SO_PF_INET6         SO_AF_INET6

typedef struct SOIn6Addr
{
    u8          addr[16];   // IPv6 address
} SOIn6Addr;

typedef struct SOSockAddrIn6
{
    u8          len;        // length of this struct
    u8          family;     // SO_AF_INET6
    u16         port;       // transport layer port #
    u32         flowInfo;   // IPv6 flow information
    SOIn6Addr   addr;       // IPv6 address
    u32         scopeID;    // set of interfaces for a scope
} SOSockAddrIn6;

#endif // __IOP_IP6_H__
