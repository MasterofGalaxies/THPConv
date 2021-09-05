/*---------------------------------------------------------------------------*
  Project:  Revolution DVD eTicket service related functions
  File:     dvdes.h

  Copyright 2007  Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.2  2007/03/28 04:05:29  ooizumi
  Modified structure of DVDPartitionParams.

  Revision 1.1  2007/03/22 23:52:26  ooizumi
  Added dvdes.h.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __DVDES_H__
#define __DVDES_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>
#include <revolution/dvd.h>

#include <secure/es_int.h>

typedef struct DVDPartitionParams  DVDPartitionParams;

struct DVDPartitionParams
{
    ESTicket     ticket;
    u8           padding0[OSRoundUp32B(sizeof(ESTicket)) - sizeof(ESTicket)];
    ESTicketView ticketView;
    u8           padding1[OSRoundUp32B(sizeof(ESTicketView)) - sizeof(ESTicketView)];
    u32          numTmdBytes;
    u8           padding2[28];
    ESTitleMeta  tmd;
    u8           padding3[OSRoundUp32B(sizeof(ESTitleMeta)) - sizeof(ESTitleMeta)];
    u32          numCertBytes;
    u8           padding4[28];
    u8           certificates[4*1024];
    u32          dataWordOffset;
    u8           padding5[28];
    u8           h3Hash[96*1024];
}; // 122368 bytes

#define DVDES_SECURITY_OFFSET                 0x40000
#define DVDES_GAME_PARTITION_ALIGN            (64 * 1024)
#define DVDES_ITEM_ALIGN                      32
#define DVDES_H3_ALIGN                        (32 * 1024)
#define DVDES_H3_SIZE                         (3 * 32 * 1024)
#define DVDES_ENCRYPT_ALIGN                   (32 * 1024)
#define DVDES_DISK_ADDR(x)                    (htonl((uint32_t)(x) >> 2))

typedef struct DVDGamePartition {
    ESTicket            ticket;
    u32                 tmdSize;
    ESTitleMeta         *tmd;               /* Disk (word) address of tmd */
    u32                 certBlobSize;
    void                *certBlob;      
    u8                  *h3Hashes;
    u8                  *encryptedArea;
} DVDGamePartition;

typedef struct DVDPartitionInfo {
        DVDGamePartition  *gamePartition;
        u32               type;
} DVDPartitionInfo;

typedef struct DVDGameTOC {
        u32               numGamePartitions;
        DVDPartitionInfo  *partitionInfos;   // Address of an array of partition infos
} DVDGameTOC;

extern BOOL DVDGetPartitionParamsAsync     (DVDCommandBlock *block, DVDPartitionParams* params, u32 offset, DVDCBCallback callback);
extern BOOL DVDOpenPartitionWithParamsAsync(DVDCommandBlock *block, DVDPartitionParams* params, u32 offset, DVDCBCallback callback);

#ifdef __cplusplus
}
#endif

#endif  // __DVDES_H__
