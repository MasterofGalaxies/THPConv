/*---------------------------------------------------------------------------*
  Project:  Dolphin DVD middle-level functions
  File:     dvdcb.h

  Copyright 1998-2007  Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.21  2007/04/20 11:06:58  ooizumi
  Modified DVDErrorInfo.

  Revision 1.20  2007/03/28 04:02:04  ooizumi
  Added DVD_COMMAND_OPEN_PARTITION_WITH_PARAMS.

  Revision 1.19  2007/03/22 23:52:56  ooizumi
  Moved eTicket service related functions to dvdes.h.

  Revision 1.18  2007/03/22 10:33:24  ooizumi
  Added DVDPartitionParams and DVDGetPartitionParamsAsync.

  Revision 1.17  2007/02/23 06:15:05  ooizumi
  Added DVD_COMMAND_PREPARE_DISK.

  Revision 1.16  2006/10/26 06:13:29  ooizumi
  Changed directory.

  Revision 1.15  2006/10/23 00:29:54  ooizumi
  Re-defined __DVDStoreErrorCode for RVL_LEGACYDI.

  Revision 1.14  2006/09/18 16:22:48  ooizumi
  Added DVDErrorInfo and DVDCommandInfo.

  Revision 1.13  2006/09/13 18:23:35  ooizumi
  Added __DVDPrepareReset.

  Revision 1.12  2006/09/06 15:54:53  ooizumi
  Added __DVDGetNextWaitingQueue.

  Revision 1.11  2006/08/03 06:58:54  ooizumi
  Added DVD_COMMAND_GET_COVER_STATUS.

  Revision 1.10  2006/06/27 09:42:37  ooizumi
  Added DVDClosePartitionAsync.

  Revision 1.9  2006/05/19 18:23:29  ooizumi
  Added __DVDStopMotorAsync for internal use.
  Changed function name from DVDRestartMotor to __DVDRestartMotor.
  Modified no input state sequence.

  Revision 1.8  2006/05/18 23:21:31  ooizumi
  Added DVDDownRotationAsync.

  Revision 1.7  2006/05/17 22:30:48  ooizumi
  Added several difinitions.

  Revision 1.6  2006/05/13 20:05:44  ooizumi
  Added DVD_SECURITY_ERROR_CODE.

  Revision 1.5  2006/05/09 03:07:33  ooizumi
  Added DVDResetAsync.

  Revision 1.4  2006/04/04 10:27:42  ooizumi
  Added device codes for revolution production/devkit.

  Revision 1.3  2006/03/10 22:41:59  ooizumi
  Modified DVD[Read|Seek]Abs param offset s32 to u32.

  Revision 1.2  2006/02/04 13:05:46  hashida
  (none)

  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    27    04/03/31 20:27 Hashida
    Added DVDStopMotor.
    
    26    03/06/18 14:19 Hashida
    Added __DVDTestAlarm().
    
    25    02/12/26 5:25p Akagi
    Fixed to be C++ ready.
    
    24    02/04/30 21:52 Hashida
    Added DVD_DEVICECODE_GCAM.
    
    23    1/22/02 18:25 Shiki
    Added DVD_DEVICECODE_FATAL.

    22    1/02/02 5:17p Hashida
    Initial revision for GC-AM support.

    21    8/21/01 3:43p Hashida
    Added DEVICECODE_PRESENT.

    20    8/21/01 12:01p Hashida
    Added definitions for various device codes.

    19    7/22/01 4:53a Hashida
    Changed the transfer size to 512K.

    18    7/17/01 1:08a Hashida
    Added __DVDPrepareResetAsync

    17    6/18/01 2:16p Hashida
    Added timeout error.

    16    6/18/01 11:04a Hashida
    Moved a result code (COVER_CLOSED) from dvd.h to dvdcb.h

    15    6/15/01 8:45p Hashida
    Added an error code for DEINT.
    Added __DVDStoreErrorCode.

    14    6/12/01 3:56p Hashida
    Added reset workaround.

    13    5/10/01 2:25p Hashida
    Added __DVDIsBlockInWaitingQueue.

    12    5/01/01 2:49p Hashida
    Changed DVDGetStreamAddr & DVDGetStreamLength to be internal APIs.

    11    3/07/01 6:50p Hashida
    Added several functions for BS.

    10    2/21/01 12:11p Hashida
    Added inquiry command.

    9     11/01/00 10:03a Hashida
    Changed default audio buffer size from 6 to 10

    8     10/09/00 6:54p Hashida
    Added prioritized queuing.

    7     9/25/00 3:33p Hashida
    Changed API names that don't follow the convention (sync, async)

    6     4/17/00 1:34p Hashida
    Added audio buffer config API.

    5     4/13/00 5:20p Hashida
    DVD_RESULT_COVER_CLOSED definition is moved to dvd.h because streaming
    commands will use that.

    4     4/07/00 6:54p Hashida
    Added streaming stuffs

    3     3/09/00 3:02p Hashida
    Changed #ifdef MARLIN ~ #ifdef SPRUCE into #ifdef SPRUCE_MARLIN to
    describe more specificly.

    2     12/23/99 1:20a Hashida
    Changed MAX_ONE_TRANSFER to be 0x1000 only for SPRUCE_MARLIN.

    10    9/09/99 2:15p Hashida
    Removed warnings.

    9     9/07/99 4:21p Hashida
    Changed the DMA size to 0x1000 because the bug is fixed.

    8     8/31/99 9:29p Hashida
    Changed the transfer size to 0x700

    7     8/31/99 11:01a Hashida
    Added Marlin support

    6     8/17/99 1:39p Hashida
    Changed DVDReset() to an independent function, which resets the drive
    and set interrupt masks properly.

    5     7/20/99 10:35p Hashida
    Added DVDSeekAbs()

    4     7/20/99 2:37p Hashida
    Changed the value of DVD_RESULT_COVER_CLOSED from 1 to -2

    3     7/19/99 11:45p Hashida
    changed the value for fatal error to -1

    2     7/19/99 11:39p Hashida
    Added DVDReset()
    Changed from DVD_RESULT_DISK_CHANGED to DVD_RESULT_COVER_CLOSED

    1     7/19/99 4:32p Hashida
    Initial revision

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __DVDCB_H__
#define __DVDCB_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>
#include <revolution/dvd.h>

typedef struct DVDDriveInfo DVDDriveInfo;

struct DVDDriveInfo
{
    u16         revisionLevel;
    u16         deviceCode;
    u32         releaseDate;        // in BCD
    u8          padding[24];
};

typedef void (*DVDOptionalCommandChecker)(DVDCommandBlock* block, void (*cb)(u32 intType));

// MEI devices, 0x00xx
#define DVD_DEVICECODE_REALDRIVE        0x0000
#define DVD_DEVICECODE_NRDRIVE          0x0001
#define DVD_DEVICECODE_RVLREALDRIVE     0x0002
#define DVD_DEVICECODE_RVLRDRIVE        0x0003

// AMC device, 0x01xx
#define DVD_DEVICECODE_DDH              0x0100

// Hudson devices, 0x02xx
#define DVD_DEVICECODE_NPDP             0x0200
#define DVD_DEVICECODE_GDEV             0x0201
#define DVD_DEVICECODE_NDEV             0x0202
#define DVD_DEVICECODE_RVLH             0x0203

// Arcade devices, 0x03xx
#define DVD_DEVICECODE_RVA              0x0300
    
// Triforce; note this is not what triforce returns to "get device ID"
#define DVD_DEVICECODE_GCAM             0x1000

#define DVD_DEVICECODE_PRESENT          0x8000
#define DVD_DEVICECODE_FATAL            0x0001

#ifdef SPRUCE_MARLIN
// Marlin -2 needs packets to be divided into 4k chunks.
#define DVD_MAX_ONE_TRANSFER      0x1000
#else
//#define DVD_MAX_ONE_TRANSFER      0x00600000
#define DVD_MAX_ONE_TRANSFER      0x00080000
#endif

#define DVD_COMMAND_READ                        1
#define DVD_COMMAND_SEEK                        2
#define DVD_COMMAND_CHANGE_DISK                 3
#define DVD_COMMAND_BSREAD                      4
#define DVD_COMMAND_READID                      5
#define DVD_COMMAND_INITSTREAM                  6
#define DVD_COMMAND_CANCELSTREAM                7
#define DVD_COMMAND_STOP_STREAM_AT_END          8
#define DVD_COMMAND_REQUEST_AUDIO_ERROR         9
#define DVD_COMMAND_REQUEST_PLAY_ADDR           10
#define DVD_COMMAND_REQUEST_START_ADDR          11
#define DVD_COMMAND_REQUEST_LENGTH              12
#define DVD_COMMAND_AUDIO_BUFFER_CONFIG         13
#define DVD_COMMAND_INQUIRY                     14
#define DVD_COMMAND_BS_CHANGE_DISK              15
#define DVD_COMMAND_STOP_MOTOR                  16

#define DVD_COMMAND_RESET                       32
#define DVD_COMMAND_UNENCRYPTED_READ            33
#define DVD_COMMAND_OPEN_PARTITION              34
#define DVD_COMMAND_CLOSE_PARTITION             35
#define DVD_COMMAND_CHECK_DISK                  36
#define DVD_COMMAND_DOWN_ROTATION               37
#define DVD_COMMAND_GET_COVER_STATUS            38
#define DVD_COMMAND_REQUEST_ERROR               39
#define DVD_COMMAND_PREPARE_DISK                40
#define DVD_COMMAND_GET_PARTITION_PARAMS        41
#define DVD_COMMAND_OPEN_PARTITION_WITH_PARAMS  42

// Result that can only be returned for BS2 DVD APIs
#define DVD_RESULT_COVER_CLOSED                 -4      // make sure to check dvd.h

// XXX this value will be eventually decided and hardwired by HW
#define DVD_AUDIO_BUFFER_SIZE                   10

#define DVD_2RESETS_INTERVAL                    OSMillisecondsToTicks(1150)

#define DVD_DE_INT_ERROR_CODE                   0x01234567
#define DVD_TIMEOUT_ERROR_CODE                  0x01234568
#define DVD_SECURITY_ERROR_CODE                 0x01234569

extern BOOL DVDReadAbsAsyncPrio(DVDCommandBlock *block,
                                void* addr, s32 length, u32 offset,
                                DVDCBCallback callback, s32 prio);
extern BOOL DVDReadAbsAsyncForBS(DVDCommandBlock *block,
                                 void* addr, s32 length, u32 offset,
                                 DVDCBCallback callback);
extern BOOL DVDReadDiskID(DVDCommandBlock *block, DVDDiskID* diskID,
                          DVDCBCallback callback);
extern BOOL DVDSeekAbsAsyncPrio(DVDCommandBlock *block, u32 offset,
                                DVDCBCallback callback, s32 prio);
extern void DVDReset(void);
#if !defined(DI_DIRECT) && defined(IOP_REV)
extern BOOL DVDResetAsync(DVDCommandBlock *block, DVDCBCallback callback);
#endif

extern BOOL DVDPrepareStreamAbsAsync(DVDCommandBlock *block, u32 length, u32 offset,
                                     DVDCBCallback callback);

BOOL DVDGetStreamStartAddrAsync(DVDCommandBlock *block, DVDCBCallback callback);
s32  DVDGetStreamStartAddr(DVDCommandBlock *block);

BOOL DVDGetStreamLengthAsync(DVDCommandBlock *block, DVDCBCallback callback);
s32  DVDGetStreamLength(DVDCommandBlock *block);

extern BOOL DVDInquiryAsync(DVDCommandBlock *block, DVDDriveInfo* info,
                            DVDCBCallback callback);

extern s32 DVDInquiry(DVDCommandBlock *block, DVDDriveInfo* info);

BOOL DVDStopMotorAsync(DVDCommandBlock* block, DVDCBCallback callback);
s32 DVDStopMotor(DVDCommandBlock* block);

// This API is for bootrom
extern void __DVDAudioBufferConfig(DVDCommandBlock *block, u32 enable, u32 size,
                                   DVDCBCallback callback);
extern BOOL DVDChangeDiskAsyncForBS(DVDCommandBlock* block, DVDCBCallback callback);

extern BOOL DVDResetRequired(void);

extern void __DVDPrepareResetAsync(DVDCBCallback callback);
extern void __DVDPrepareReset(void);

// Exported from dvdqueue.c
extern void __DVDClearWaitingQueue(void);
extern BOOL __DVDPushWaitingQueue(s32 prio, DVDCommandBlock* block);
extern DVDCommandBlock* __DVDPopWaitingQueue(void);
extern BOOL __DVDCheckWaitingQueue(void);
extern BOOL __DVDDequeueWaitingQueue(DVDCommandBlock* block);
extern BOOL __DVDIsBlockInWaitingQueue(DVDCommandBlock* block);
extern DVDCommandBlock* __DVDGetNextWaitingQueue(void);

// Exported from dvderror.c
#if !defined(DI_DIRECT) && defined(IOP_REV)
extern void __DVDStoreErrorCode(u32 error, DVDCBCallback callback);
#else
extern void __DVDStoreErrorCode(u32 error);
#endif

// Exported from dvd.c
DVDOptionalCommandChecker __DVDSetOptionalCommandChecker(DVDOptionalCommandChecker func);
void __DVDSetImmCommand(u32 command);
void __DVDSetDmaCommand(u32 command);
void* __DVDGetIssueCommandAddr(void);
BOOL __DVDTestAlarm(const OSAlarm* alarm);

/*
 * Prototypes for the following functions should be in dvd.h, which
 * is exported to developers:
 *     DVDChangeDisk()
 *     DVDGetCommandBlockStatus()
 *     DVDGetDriveStatus()
 */

#if !defined(DI_DIRECT) && defined(IOP_REV)
extern BOOL DVDOpenPartitionAsync(DVDCommandBlock *block, void* addr, u32 offset, DVDCBCallback callback);
extern BOOL DVDClosePartitionAsync(DVDCommandBlock *block, DVDCBCallback callback);
extern BOOL DVDUnencryptedReadAbsAsyncForBS(DVDCommandBlock *block, void* addr, s32 length,
                                     u32 offset, DVDCBCallback callback);
#endif
extern BOOL __DVDStopMotorAsync(DVDCommandBlock* block, DVDCBCallback callback);
extern void __DVDRestartMotor(void);
extern BOOL DVDDownRotationAsync(DVDCommandBlock *block, DVDCBCallback callback);

#define DVD_ERROR_INFO_DIR_NAME  "/shared2/test2"
#define DVD_ERROR_INFO_FILE_NAME "/shared2/test2/dvderror.dat"
#define DVD_ERROR_INFO_FILE_PERM \
    (NAND_PERM_OTHER_READ | NAND_PERM_OTHER_WRITE | \
     NAND_PERM_GROUP_READ | NAND_PERM_GROUP_WRITE | \
     NAND_PERM_OWNER_READ | NAND_PERM_OWNER_WRITE)
#define DVD_ERROR_INFO_FILE_ATTR  0x00
#define DVD_ERROR_INFO_MAX_NUM    7

typedef struct DVDCommandInfo DVDCommandInfo;
struct DVDCommandInfo
{
    u32             command;
    u32             offset;
    u32             length;
    u32             intType;
    u32             tick;
};

typedef struct DVDErrorInfo DVDErrorInfo;
struct DVDErrorInfo
{
    char            gameName[4];
    u8              diskNumber;
    u8              gameVersion;
    u8              reserved0[2];
    u32             error;
    u32             dateTime;
    u32             status;
    u8              reserved1[4];
    u32             nextOffset;
    DVDCommandInfo  lastCommand[5];
};

#ifdef __cplusplus
}
#endif

#endif  // __DVDCB_H__
