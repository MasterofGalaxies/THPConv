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

#ifndef __IOP_IP_H__
#define __IOP_IP_H__

#ifndef IP_ALEN
#define IP_ALEN               4     // IP address length
#endif

typedef struct IPSocket
{
    u8              len;        // IP_SOCKLEN
    u8              family;     // IP_INET
    u16             port;
    u8              addr[IP_ALEN];
#ifdef WIN32
    u8              zero[8];
#endif
} IPSocket;

#define IP_SOCKLEN                  sizeof(IPSocket)

#define IP_INET                     2       // Internet protocol

#endif // __IOP_IP_H__
