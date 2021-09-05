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
 * Network Interface header file. This is the interface between network stack
 * and device drivers
 * 
 *---------------------------------------------------------------------------*/

#ifndef __IOP_NETIF_H__
#define __IOP_NETIF_H__

/* Supported network interface */
#define NET_IF_ETH_WIFI             0x01    /* Ethernet wireless interface */
#define NET_IF_ETH_USB              0x02    /* Ethernet USB interface */

#ifndef ETH_ALEN
#define ETH_ALEN                    6       /* Ethernet address length */
#endif

/*
 * Ethernet header
 */
#define ETH_HLEN                    14

typedef struct ETHHeader
{
    u8  dst[ETH_ALEN];
    u8  src[ETH_ALEN];
    u16 type;
} ETHHeader;

// obsolete
typedef struct IPInterfaceStat
{
    u32             inUcastPackets;     // Input unicast packets
    u32             inNonUcastPackets;  // Input broadcast or multicast packets
    u32             inDiscards;         // Input dropped due to ins. resources
    u32             inErrors;           // Packets dropped on input
    u32             outUcastPackets;    // Output unicast packets
    u32             outNonUcastPackets; // Output broadcast or multicast packets
    u32             outDiscards;        // Output dropped due to ins. resources
    u32             outErrors;          // Output errors
    u32             outCollisions;      // Collisions on CSMA
} IPInterfaceStat;

#endif // __IOP_NETIF_H__
