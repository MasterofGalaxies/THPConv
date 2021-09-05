/*---------------------------------------------------------------------------*
  Project:  Dolphin IP API
  File:     IPStat.h

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

  Revision 1.3  2006/04/08 01:27:18  mxu
  fix compiling and linking issues

  Revision 1.2  2006/04/07 23:00:53  mxu
  fix compiling and linking issues

  Revision 1.1  2006/04/05 23:44:20  mxu
  initial network stack code base

    
    2     2/23/06 13:57 Shiki
    Modified the type of inOctets and outOctets in IFStat to u64.

    1     2/23/06 10:48 Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __IP_IPSTAT_H__
#define __IP_IPSTAT_H__

#ifdef IOP_OS
#include <iostypes.h>
#include "iop_types.h"
#else
#include <revolution/types.h>
#endif // IOP_OS

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __MWERKS__
#pragma warn_padding off
#endif
typedef struct IFStat
{
    u64             inOctets;
    u32             inUcastPkts;
    u32             inNUcastPkts;
    u32             inDiscards;
    u32             inErrors;
    u32             inUnknownProtos;
    // 4 bytes padding
    u64             outOctets;
    u32             outUcastPkts;
    u32             outNUcastPkts;
    u32             outDiscards;
    u32             outErrors;
    u32             outCollisions;      // Collisions on CSMA
    // 4 bytes padding
} IFStat;
#ifdef __MWERKS__
#pragma warn_padding reset
#endif

typedef struct IPStat
{
    u32             inReceives;
    u32             inHdrErrors;
    u32             inAddrErrors;
    u32             inUnknownProtos;
    u32             inDiscards;
    u32             inDelivers;
    u32             outRequests;
    u32             outDiscards;
    u32             outNoRoutes;
    u32             reasmTimeout;
    u32             reasmReqds;
    u32             reasmOKs;
    u32             reasmFails;
    u32             fragOKs;
    u32             fragFails;
    u32             fragCreates;
} IPStat;

typedef struct ICMPStat
{
    u32             inMsgs;
    u32             inErrors;
    u32             inDestUnreachs;
    u32             inTimeExcds;
    u32             inParmProbs;
    u32             inSrcQuenchs;
    u32             inRedirects;
    u32             inEchos;
    u32             inEchoReps;
    u32             inTimestamps;
    u32             inTimestampReps;
    u32             inAddrMasks;
    u32             inAddrMaskReps;
    u32             outMsgs;
    u32             outErrors;
    u32             outDestUnreachs;
    u32             outTimeExcds;
    u32             outParmProbs;
    u32             outSrcQuenchs;
    u32             outRedirects;
    u32             outEchos;
    u32             outEchoReps;
    u32             outTimestamps;
    u32             outTimestampReps;
    u32             outAddrMasks;
    u32             outAddrMaskReps;
} ICMPStat;

typedef struct UDPStat
{
    u32             inDatagrams;
    u32             inErrors;
    u32             noPorts;
    u32             outDatagrams;
} UDPStat;

typedef struct TCPStat
{
    u32             activeOpens;
    u32             passiveOpens;
    u32             attemptFails;
    u32             estabResets;
    u32             currEstab;
    u32             inSegs;
    u32             outSegs;
    u32             retransSegs;
    u32             inErrs;
    u32             outRsts;
} TCPStat;

typedef struct IPv6Stat
{
    u32             inReceives;
    u32             inHdrErrors;
    u32             inAddrErrors;
    u32             inUnknownProtos;
    u32             inTruncatedPkts;
    u32             inDiscards;
    u32             inDelivers;
    u32             outForwDatasgrams;
    u32             outRequests;
    u32             outDiscards;
    u32             outFragOKs;
    u32             outFragFails;
    u32             outFragCreates;
    u32             reasmReqds;
    u32             reasmOKs;
    u32             reasmFails;
    u32             inMcastPkts;
    u32             outMcastPkts;
} IPv6Stat;

typedef struct ICMPv6Stat
{
    u32             inMsgs;
    u32             inErrors;
    u32             inDestUnreachs;
    u32             inAdminProhibs;
    u32             inTimeExcds;
    u32             inParmProblems;
    u32             inPktTooBigs;
    u32             inEchos;
    u32             inEchoReplies;
    u32             inRouterSolicits;
    u32             inRouterAdvertisements;
    u32             inNeighborSolicits;
    u32             inNeighborAdvertisements;
    u32             inRedirects;
    u32             inGroupMembQueries;
    u32             inGroupMembResponses;
    u32             inGroupMembReductions;
    u32             outMsgs;
    u32             outErrors;
    u32             outDestUnreachs;
    u32             outAdminProhibs;
    u32             outTimeExcds;
    u32             outParmProblems;
    u32             outPktTooBigs;
    u32             outEchos;
    u32             outEchoReplies;
    u32             outRouterSolicits;
    u32             outRouterAdvertisements;
    u32             outNeighborSolicits;
    u32             outNeighborAdvertisements;
    u32             outRedirects;
    u32             outGroupMembQueries;
    u32             outGroupMembResponses;
    u32             outGroupMembReductions;
} ICMPv6Stat;

#ifdef __cplusplus
}
#endif

#endif  /* __IP_IPSTAT_H__ */
