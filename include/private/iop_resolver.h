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
 * SOResolveer structure
 * 
 *---------------------------------------------------------------------------*/

#ifndef __IOP_RESOLVER_H__
#define __IOP_RESOLVER_H__

#ifdef IOP_OS
#include "dolphin/os.h"
#include "dolphin/ip.h"
#endif // IOP_OS

// 35 aliases, 35 addr, 8192 buffer
typedef struct SOResolver
{
    SOHostEnt   ent;
    char        name[SO_MAXDNAME];
#ifndef IP_INET6
    u8          addrList[35 * sizeof(SOInAddr)];
#else
    u8          addrList[35 * sizeof(SOIn6Addr)];
#endif  // IP_INET6
    u8*         ptrList[72];

#ifdef IOP_OS
    // the following fields will not be used in the PPC side.
    // must be kept at the end so IOP and PPC will have a consistent
    // view of above fields
    DNSInfo     info;
    char        buf[8192 - 35 * sizeof(SOInAddr)];
    char        suffix[SO_MAXDNAME];
#endif // IOP_OS
} SOResolver;

#endif // __IOP_RESOLVER_H__
