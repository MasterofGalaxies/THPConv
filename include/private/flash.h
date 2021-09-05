/*
 *               Copyright (C) 2005, BroadOn Communications Corp.
 *
 *  These coded instructions, statements, and computer programs contain
 *  unpublished proprietary information of BroadOn Communications Corp.,
 *  and are protected by federal copyright law. They may not be disclosed
 *  to third parties or copied or duplicated in any form, in whole or in
 *  part, without the prior written consent of BroadOn Communications Corp.
 *
 *  Description:
 *      This file contains the public declarations for the flash device
 *      driver
 *
 */


#ifndef __FLASH_H__
#define __FLASH_H__


#ifdef NET_CARD
#include <sc/iostypes.h>
#else
#include <iostypes.h>
#endif


#ifdef  __MWERKS__
#pragma warn_padding off
#endif
/* Flash device capabilities */
typedef struct {
    u32     totalSzShift;
    u32     erasableBlockSzShift;
    u32     pageSzShift;
    u32     pageSpareSzShift;
    u32     userSpareSzShift;
    u16     numPlanes;
    u16     supportCopy;
    u16     statusByteOffset;
} FLDevCap;
#ifdef  __MWERKS__
#pragma warn_padding reset
#endif

/*
 *  Description:
 *      Flash device driver statistics information
 *
 */
#define FL_FAILED_ENTRIES           32
#define FL_FAILED_ENTRIES_SHIFT     7

#define FL_OP_ERASE                 0
#define FL_OP_WRITE                 1
#define FL_OP_READ                  2
#define FL_OP_COPY                  3

/* Statistics records */
typedef struct {
    u32         blockIndex;
    u32         opType;
    IOSError    reason;
} FLFailRecord;

typedef struct {
    u32                 numErasesSinceInit;
    u32                 numWritesSinceInit;
    u32                 numReadsSinceInit;
    u32                 numCopiesSinceInit;
    u32                 failRecordStart;
    u32                 failRecordNum;
    FLFailRecord        failRecord[FL_FAILED_ENTRIES];
} FLStats;


/* System-wide maximum number of open flash resource manager contexts */
#define FL_RESRC_MGR_NUMCTX         2

/* Flash resource manager ioctl commands */
#define FL_GETCAP                   1
#define FL_GETSTATS                 2
#define FL_ERASE                    3
#define FL_STATUS                   4

/*
 *  Description:
 *      Flash logical block data and spare size
 *
 */
#define FL_LOGI_BLOCK_SIZE          (16 * 1024) /* Flash logical block size */
#define FL_LOGI_BLOCK_SIZE_SHIFT    14

#define FL_VIRT_SPARE_SIZE          64          /* Spare for a logical block */
#define FL_VIRT_SPARE_SIZE_SHIFT    6

/* Cacheline alignment */
#define FL_BASE_ALIGN_SZ            32

/*
 *  Description:
 *      Flash device driver manufacturing ID
 *
 */
#define FL_SAMSUNG_ID               0xEC
#define FL_SAMSUNG_64MB_ID          0x76
#define FL_SAMSUNG_128MB_ID         0xF1
#define FL_SAMSUNG_256MB_ID         0xDA
#define FL_SAMSUNG_512MB_ID         0xDC

#define FL_TOSHIBA_ID               0x98
#define FL_TOSHIBA_16MB_ID          0x73
#define FL_TOSHIBA_32MB_ID          0x75
#define FL_TOSHIBA_64MB_ID          0x76
#define FL_TOSHIBA_128MB_ID         0xF1
#define FL_TOSHIBA_256MB_ID         0xDA

#define FL_HYNIX_ID                 0xAD
#define FL_HYNIX_64MB_ID            0x76
#define FL_HYNIX_512MB_ID           0xDC


#endif /* __FLASH_H__ */
