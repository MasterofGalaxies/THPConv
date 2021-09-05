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

#ifndef __IOP_IPDNS_H__
#define __IOP_IPDNS_H__

#ifndef DNS_NAME_MAX
#define DNS_NAME_MAX        255     // names are 255 octets or less
#endif

#define SO_MAX_ADDRINFO     35

#define SO_EAI_AGAIN        -300
#define SO_EAI_BADFLAGS     -301
#define SO_EAI_FAIL         -302
#define SO_EAI_FAMILY       -303
#define SO_EAI_MEMORY       -304
#define SO_EAI_NONAME       -305
#define SO_EAI_SERVICE      -306
#define SO_EAI_SOCKTYPE     -307
#define SO_EAI_SYSTEM       -308
#define SO_EAI_OVERFLOW     -309

// SOGetNameInfo() flags
#define SO_NI_NOFQDN        0x01
#define SO_NI_NUMERICHOST   0x02
#define SO_NI_NAMEREQD      0x04
#define SO_NI_NUMERICSERV   0x08
#define SO_NI_DGRAM         0x10
#define SO_NI_NUMERICSCOPE  0x20

#define SO_NI_MAXHOST       256
#define SO_NI_MAXSERV       32

typedef struct SOAddrInfo   SOAddrInfo;
struct SOAddrInfo
{
    int             flags;         // input flags
    int             family;        // address family of socket
    int             sockType;      // socket type
    int             protocol;      // protocol of socket
    unsigned        addrLen;       // length of socket address
    char*           canonName;     // canonical name of service location
    void*           addr;          // socket address of socket
    SOAddrInfo*     next;          // pointer to next in list
};

#endif // __IOP_IPDNS_H__
