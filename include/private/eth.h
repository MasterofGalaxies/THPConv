/*---------------------------------------------------------------------------*
  Project:  ETHERNET API
  File:     eth.h

  Copyright 2000-2003 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    13    1/28/04 9:00 Shiki
    Fixed wrong definition of __ETHInterruptTime to a declaration.

    12    7/11/03 10:08 Shiki
    Clean up.

    11    7/09/03 13:54 Shiki
    Refined the ETHAddMulticastAddress() declaration using const.

    10    6/04/03 10:54 Shiki
    Clean up.

    9     03/06/03 16:15 Ikedae
    Added ETHClearMulticastAddresses()

    8     02/09/09 13:00 Ikedae
    Removed ETHSend, ETHSendBusy

    2     02/04/03 18:07 Ikedae
    added ETHAddMulticastAddress

    1     02/03/13 8:53 Ikedae

    1     6/22/00 1:23p Ikedae
    Initial check-in.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __ETH_H__
#define __ETH_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef void* (* ETHCallback0 )(u16 type, s32 len, u8 lrps);
typedef void  (* ETHCallback1 )(u8* addr, s32 len );
typedef void  (* ETHCallback2 )(u8 ltps );

enum
{
    ETH_MODE_AUTO = 0,
    ETH_MODE_100FULL,
    ETH_MODE_100HALF,
    ETH_MODE_10FULL,
    ETH_MODE_10HALF,
    ETH_MODE_UNKNOWN
};

typedef struct ETHStat
{
    u32 rcvcount;
    u32 sendcount;
    u16 cntof;
    u16 re;
    u16 te;
    u16 fifoe;
    u16 rbf;
    u16 rx_bf;
    u16 rx_crc;
    u16 rx_fae;
    u16 rx_fo;
    u16 rx_rw;
    u16 rx_rf;
    u16 tx_crs;
    u16 tx_uf;
    u16 tx_owc;
} ETHStat;

#define ETH_OK                  1
#define ETH_ERROR_NODEVICE      -1
#define ETH_ERROR_INITERROR     -2

#define ETH_BBA_MP              2

extern s32  ETHInit               ( s32 mode );
extern void ETHGetMACAddr         ( u8* macaddr );
extern void ETHSetMACAddr         ( u8* macaddr );
extern void ETHSetRecvCallback    ( ETHCallback0 callback0, ETHCallback1 callback1 );
extern BOOL ETHGetLinkState       ( void );
extern BOOL ETHGetLinkStateAsync  ( BOOL* status );
extern s32  ETHGetNWAYMode        ( void );
extern void ETHSetProtoType       ( u16* array, s32 num );
extern void ETHGetStatus          ( ETHStat *stat );
extern s32  ETHGetLibraryVersion  ( void );
extern s32  ETHGetBBAType         ( void );
extern void ETHSendAsync          ( void* addr, s32 length, ETHCallback2 callback2 );
extern void ETHAddMulticastAddress( const u8* macaddr );
extern void ETHChangeIntPriority  ( BOOL flag );
extern u32  ETHGetREVID           ( void );

extern void ETHClearMulticastAddresses( void );

extern volatile OSTime __ETHInterruptTime;

// ltps (Last Transmitted Packet Status)

#define ME_LTPS_CC0        0x01
#define ME_LTPS_CC1        0x02
#define ME_LTPS_CC2        0x04
#define ME_LTPS_CC3        0x08
#define ME_LTPS_CRSLOST    0x10
#define ME_LTPS_UF         0x20
#define ME_LTPS_OWC        0x40
#define ME_LTPS_TERR       0x80

// lrps (Last Received Packet Status)

#define ME_LRPS_BF         0x01
#define ME_LRPS_CRC        0x02
#define ME_LRPS_FAE        0x04
#define ME_LRPS_FO         0x08
#define ME_LRPS_RW         0x10
#define ME_LRPS_MF         0x20
#define ME_LRPS_RF         0x40
#define ME_LRPS_RERR       0x80

#ifdef __cplusplus
}
#endif

#endif // __ETH_H__
