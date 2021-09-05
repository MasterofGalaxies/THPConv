/*---------------------------------------------------------------------------*
  Project:  Dolphin IP API
  File:     IPEntry.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.2  2006/07/07 19:30:29  orest
  Changed include path.

  Revision 1.1  2006/06/06 05:18:40  mxu
  header files restructure

  Revision 1.2  2006/06/03 05:42:52  cnguyen
  - Merged from IOP_OS_075_DEV_BRANCH

  Revision 1.1.2.1  2006/06/02 05:17:04  mxu
  add implementation for SOGetInterfaceOpt/SOSetInterfaceOpt

  Revision 1.4  2006/04/19 22:47:03  mxu
  1. restructure the source tree 2. isolate the internal and exported header files

  Revision 1.3  2006/04/14 22:22:18  mxu
  make prAddr (ip address) 32bites aligned in ARPEntry structure

  Revision 1.2  2006/04/07 23:00:53  mxu
  fix compiling and linking issues

  Revision 1.1  2006/04/05 23:44:20  mxu
  initial network stack code base

    
    6     2/28/06 10:11 Shiki
    Added IP6_PREFIX_FLAG_REDIRECT.

    5     2/28/06 9:05 Shiki
    Fixed IP6PrefixEntry.

    4     2/28/06 8:58 Shiki
    Modified IP6PrefixEntry.

    3     2/23/06 13:58 Shiki
    Added IPAddrEntry.

    2     2/23/06 11:15 Shiki
    Fixed comments.

    1     2/23/06 10:48 Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __IP_IPENTRY_H__
#define __IP_IPENTRY_H__

#include <revolution/socket.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ARP_STATE_INCOMPLETE                1
#define ARP_STATE_REACHABLE                 2
#define ARP_STATE_PROBE                     3

#ifdef __MWERKS__
#pragma warn_padding off
#endif
typedef struct ARPEntry
{
    int             state;              // ARP_STATE_*
// IOP_OS: the order of hwAddr and prAddr is reversed for data alignment
    u8              prAddr[IP_ALEN];    // IP v4 specific
    u8              hwAddr[ETH_ALEN];   // Ether specific
    // 2 bytes padding
} ARPEntry;
#ifdef __MWERKS__
#pragma warn_padding reset
#endif

#define IP_ROUTE_FLAG_G                     0x01    // Router
#define IP_ROUTE_FLAG_D                     0x02    // Created by ICMP
#define IP_ROUTE_FLAG_M                     0x04    // Modified by ICMP

typedef struct IPAddrEntry
{
    u8              addr[IP_ALEN];
    u8              netMask[IP_ALEN];
    u8              bcastAddr[IP_ALEN];
} IPAddrEntry;

typedef struct IPRouteEntry
{
    u8              dst[IP_ALEN];       // destination IP address
    u8              netmask[IP_ALEN];   // netmask
    u8              gateway[IP_ALEN];   // next-hop gateway IP address
    u32             flag;               // IP_ROUTE_FLAG_*
    OSTime          time;               // time of last access
} IPRouteEntry;

// The following six states are used for "Neighbor Cache". [RFC 2461]
#define IP6_PREFIX_STATE_INIT               1
#define IP6_PREFIX_STATE_INCOMPLETE         2
#define IP6_PREFIX_STATE_REACHABLE          3
#define IP6_PREFIX_STATE_STALE              4
#define IP6_PREFIX_STATE_DELAY              5
#define IP6_PREFIX_STATE_PROBE              6

// The following three states are used for address configuration. [RFC 2462]
#define IP6_PREFIX_STATE_TENTATIVE          7
#define IP6_PREFIX_STATE_PREFERRED          8
#define IP6_PREFIX_STATE_DEPRECATED         9

// The following three states are used for "Multicast Listener". [RFC 2710]
#define IP6_PREFIX_STATE_NON_LISTENER       10
#define IP6_PREFIX_STATE_DELAYING_LISTENER  11
#define IP6_PREFIX_STATE_IDLE_LISTENER      12

// The following state is used for "Destination Cache".  [RFC 2461]
#define IP6_PREFIX_STATE_DESTINATION        13

// The following state is used for on-link "Prefix List".  [RFC 2461]
#define IP6_PREFIX_STATE_PREFIX             14

#define IP6_PREFIX_FLAG_IS_ROUTER           0x01u
#define IP6_PREFIX_FLAG_LAST_HOST           0x02u   // MLD
#define IP6_PREFIX_FLAG_STATIC              0x04u
#define IP6_PREFIX_FLAG_ANYCAST             0x08u
#define IP6_PREFIX_FLAG_ON_LINK             0x10u
#define IP6_PREFIX_FLAG_AUTONOMOUS          0x20u
#define IP6_PREFIX_FLAG_REDIRECT            0x40u

#ifdef __MWERKS__
#pragma warn_padding off
#endif
typedef struct IP6PrefixEntry
{
    SOIn6Addr       addr;
    u8              prefixLen;
    SOIn6Addr       nextHop;
    u8              linkAddr[ETH_ALEN];
    int             state;              // IP6_PREFIX_STATE_*
    u32             flags;              // OR-ed IP6_PREFIX_FLAG_*
    OSTime          routerLifetime;
    OSTime          validTime;
    OSTime          preferredTime;
    s32             mtu;
    // 4 bytes padding
    OSTime          lastUpdated;
} IP6PrefixEntry;
#ifdef __MWERKS__
#pragma warn_padding reset
#endif

typedef struct IP6RouteEntry
{
    SOIn6Addr       prefix;
    u8              prefixLen;
    SOIn6Addr       nextHop;
} IP6RouteEntry;

typedef struct UDPEntry
{
    SOSockAddrIn    local;
    SOSockAddrIn    remote;
} UDPEntry;

typedef struct TCPEntry
{
    s32             state;              // TCP_STATE_*
    SOSockAddrIn    local;
    SOSockAddrIn    remote;
} TCPEntry;

typedef struct UDP6Entry
{
    SOSockAddrIn6   local;
    SOSockAddrIn6   remote;
} UDP6Entry;

typedef struct TCP6Entry
{
    s32             state;
    SOSockAddrIn6   local;
    SOSockAddrIn6   remote;
} TCP6Entry;

#ifdef __cplusplus
}
#endif

#endif  /* __IP_IPENTRY_H__ */
