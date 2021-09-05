/*---------------------------------------------------------------------------*
  Project:  Dolphin DVD low-level functions
  File:     DVDLow.h

  Copyright 1998-2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.26  2007/04/10 21:33:16  craig
  Added new function calls to asynchronously get the value of the DI
  status register.  Added test of new function calls.

  Revision 1.25  2007/03/12 08:01:51  ooizumi
  Added DVDLowFinalize.

  Revision 1.24  2007/02/13 00:15:54  craig
  Added declaration for new shim function for opening a partition with
  an e-ticket view.

  Revision 1.23  2007/02/08 00:56:37  craig
  Removed contentId from OpenPartitionWithTmd parameter list.

  Revision 1.21  2007/01/30 01:18:06  craig
  Fixed DVDLowOpenPartitionWithTmd declaration.

  Revision 1.20  2007/01/30 00:26:32  craig
  Added declaration for DVDLowOpenPartitionWithTmd.

  Revision 1.19  2007/01/16 02:56:30  craig
  Removed the eTicket error paramenter from DVDLowNoDiscOpenPartition.

  Revision 1.18  2007/01/13 00:59:21  craig
  Added declarations for the last two DVD boot cache functions.

  Revision 1.17  2007/01/12 00:23:33  craig
  Added declaration for DVDLowGetNoDiscBufferSizes.

  Revision 1.16  2006/09/14 08:18:30  ooizumi
  Added DVD_WAIT_WAKE_DVD_TICKS.

  Revision 1.15  2006/06/21 01:34:54  ooizumi
  Changed definition of DVD_INTERNALERROR_GAME_DISK.

  Revision 1.14  2006/06/12 22:43:59  craig
  Added declarations for ETICKET_ERROR and DVDLowGetLastTicketError.

  Revision 1.13  2006/05/12 16:17:16  ooizumi
  Fixed miss spelling.
  Added DVD_INTTYPE_SECURITY_ERROR difinition.

  Revision 1.12  2006/05/09 02:55:04  craig
  Changed DVDLowClosePartition from sync to async.
  Added DVDLowUnencryptedRead to dvdlow.h

  Revision 1.11  2006/05/05 23:09:27  craig
  Additions needed for the new DVD low leve API's: Open/close partition
  and unencrypted read.

  Revision 1.10  2006/05/04 19:49:54  craig
  Changed DVDLowClearCoverInterrupt from synchronous to asynchronous.
  Changed calls to DVDLowClearCoverInterrupt to pass NULL callback.

  Revision 1.9  2006/04/25 10:27:33  ooizumi
  Modified DVDLowDriveSer.

  Revision 1.8  2006/03/15 18:07:42  ooizumi
  Added async version of DVDLowReset.

  Revision 1.7  2006/03/12 23:06:35  ooizumi
  Added DVD_COMMAND_TIMEOUT_TICKS_FOR_READDISKID.

  Revision 1.6  2006/03/01 21:24:46  ooizumi
  Changed function name.

  Revision 1.5  2006/02/06 00:42:29  ooizumi
  Changed DVDLowReadDvdCopyright prototype.
  Added DVDLowInit and DVDLowUnmaskCoverInterrupt.

  Revision 1.4  2006/02/04 13:05:46  hashida
  (none)

  Revision 1.3  2006/02/03 09:29:04  ooizumi
  Changed dvdvideo.h's path.

  Revision 1.2  2006/01/13 08:57:19  ooizumi
  Deleted several functions.
  Changed several functions name.

  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.6  2005/11/25 04:12:45  ooizumi
  Changed DVDLowSetMaximumRotation prototype.

  Revision 1.5  2005/11/25 01:58:04  ooizumi
  Added several reset functions.
  Added DVDLowWaitCommand.

  Revision 1.4  2005/11/16 04:03:49  ooizumi
  Changed DVDLowReset to use spin up flag.
  Deleted DVDLowReadDvdBca.
  Added several functions to issue DI commands for HW debug.
  Added API to manage encrypted data.

  Revision 1.3  2005/06/16 08:11:00  ooizumi
  Changed name the offset for read and seek.
  Changed some function prototype.
  Deleted DI registry defines.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    19    03/06/18 14:19 Hashida
    Added __DVDTestAlarm().
    
    18    02/12/26 5:25p Akagi
    Fixed to be C++ ready.
    
    17    10/30/01 2:59p Hashida
    Added NPDP specific error codes.
    
    16    6/18/01 2:17p Hashida
    Added timeout error.
    
    15    6/15/01 8:44p Hashida
    Added one more error code.
    Deleted several workaround.
    
    14    6/11/01 3:41p Hashida
    Added MEI bug workaround.
    
    13    3/29/01 6:38p Hashida
    Changed 20ms to 100ms to prevent both chattering and false cover open
    report.
    
    12    3/02/01 5:49p Hashida
    Modified error code handling (fatal error, internal retry and retry)
    
    11    3/02/01 12:06p Hashida
    Added DVDLowGetCoverStatus
    
    10    3/02/01 11:35a Hashida
    Added DVDCancel, DVDPause, DVDResume, DVDGetTransferredSize.
    
    9     2/23/01 4:27p Hashida
    Implemented reset cover interrupt callback so that cover close check
    can be done sooner.
    
    8     2/21/01 12:10p Hashida
    Added inquiry command.
    
    7     2/21/01 3:47a Hashida
    Changed POWERON_TICKS from 200ms to 80ms.
    
    6     10/03/00 10:07a Hashida
    Added DVD_RESETCOVER_TIMELAG_TICKS define.
    
    5     5/18/00 11:04a Hashida
    Changed DVD_RESET_TICKS from 10us to 12us.
    
    4     4/17/00 1:35p Hashida
    Added low audio buffer config command.
    
    3     4/07/00 6:54p Hashida
    Added streaming stuffs
    
    2     12/02/99 2:57p Hashida
    Added DVD_POWERON_TICKS.
    Changed DVD_RESET_TICKS to 10us.
    
    6     8/04/99 11:30a Hashida
    Added DVD_RESET_TICKS
    
    5     7/28/99 4:26p Hashida
    Changed error code to use the real one.
    
    4     7/23/99 4:59p Hashida
    Changed DVDLOW_DISKIMAGE_START from cached address to physical address
    
    3     7/20/99 10:31p Hashida
    Added DVDLowSeek
    
    2     7/19/99 4:33p Hashida
    Changed low callback function prototypes.
    Added some #defines.
    Fixed DVDLowRequestError().
    
    1     7/09/99 5:48p Hashida
    initial revision
    
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __DVDLOW_H__
#define __DVDLOW_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/types.h>
#include <revolution/dvd.h>
#include <private/dvdvideo.h>
#include <secure/dvdcb.h>
#if !defined(DI_DIRECT) && defined(IOP_REV)
#include <secure/es_int.h>
#endif

typedef struct DVDLowDiskBca DVDLowDiskBca;

struct DVDLowDiskBca
{
    u8 optInfo[52];
    u8 manufacturer[2];
    u8 recorderDevice[2];
    u8 bcaSerial;
    u8 discDate[2];
    u8 discTime[2];
    u8 discNumber[3];
};

typedef struct DVDLowDriveSer DVDLowDriveSer;

struct DVDLowDriveSer
{
    u8 corrected[4];
    u8 ecc[3];
    u8 padding0;
    u8 incorrected[3];
    u8 padding1[21];
};

typedef void (*DVDLowCallback)(u32 intType);

#define OFFSET(n, a)    (((u32) (n)) & ((a) - 1))

#define DVD_ALIGN_ADDR      32  // DMA transfer address alignment in bytes
#define DVD_ALIGN_SIZE      32  // DMA transfer size alignment in bytes
#define DVD_ALIGN_OFFSET    4   // DMA offset alignment in bytes

#define DVD_POWERON_TICKS   OSMillisecondsToTicks(200 - 120)
                                // 200 ms is needed on power on boot.
                                // However, 120ms has already passed when
                                // CPU starts executing BS1
#define DVD_RESET_TICKS     OSMicrosecondsToTicks(12)
                                // 12 us is needed to reset the drive.
#define DVD_RESET_TIMELAG_TICKS     OSMicrosecondsToTicks(10)
                                // 12 us is needed to reset the drive.
#define DVD_RESETCOVER_TIMELAG_TICKS        \
                            OSMillisecondsToTicks(200)
                                // There's a time lag from reset until the
                                // drive can report the status of the cover 
#define DVD_RESETCOVER_TIMELAG_TICKS2       \
                            OSMillisecondsToTicks(100)
                                // This will eventually be merged to 
                                // TIMELAG_TICKS
                                // This can also prevent chattering

#define DVD_COMMAND_TIMEOUT_TICKS           \
                            OSSecondsToTicks(10)

#define DVD_COMMAND_TIMEOUT_TICKS_FOR_LONGREAD           \
                            OSSecondsToTicks(20)

#define DVD_COMMAND_TIMEOUT_TICKS_FOR_READDISKID           \
                            OSSecondsToTicks(15)

#define DVD_WAIT_WAKE_DVD_TICKS           \
                            OSSecondsToTicks(7)
#define DVD_WAIT_WAKE_DVD_TICKS2           \
                            OSSecondsToTicks(5)

#define DVD_INTERNALERROR_STATUSMASK        0xff000000

#define DVD_INTERNALERROR_STATUS_READY      0x00000000
#define DVD_INTERNALERROR_STATUS_COVEROPEN  0x01000000
#define DVD_INTERNALERROR_STATUS_DISKCHANGE 0x02000000
#define DVD_INTERNALERROR_STATUS_NODISK     0x03000000
#define DVD_INTERNALERROR_STATUS_MOTORSTOP  0x04000000
#define DVD_INTERNALERROR_STATUS_IDNOTREAD  0x05000000

#define DVD_INTERNALERROR_ERRORMASK         0x00ffffff

#define DVD_INTERNALERROR_NO_ERROR          0x00000000
#define DVD_INTERNALERROR_COVEROPEN_OR_NODISK 0x00023a00
#define DVD_INTERNALERROR_COVER_CLOSED      0x00062800
#define DVD_INTERNALERROR_NO_SEEK_COMPLETE  0x00030200
#define DVD_INTERNALERROR_UNRECOVERED_READ  0x00031100
#define DVD_INTERNALERROR_INVALID_COMMAND   0x00052000
#define DVD_INTERNALERROR_AUDIOBUF_NOT_SET  0x00052001
#define DVD_INTERNALERROR_LBA_OUT_OF_RANGE  0x00052100
#define DVD_INTERNALERROR_INVALID_FIELD     0x00052400
#define DVD_INTERNALERROR_INVALID_AUDIO_COMMAND 0x00052401
#define DVD_INTERNALERROR_AUDIOBUF_CONFIG_NOT_ALLOWED 0x00052402
#define DVD_INTERNALERROR_OP_DISK_RM_REQ    0x000b5a01
#define DVD_INTERNALERROR_END_OF_USER_AREA  0x00056300
#define DVD_INTERNALERROR_ID_NOT_READ       0x00020401
#define DVD_INTERNALERROR_MOTOR_STOPPED     0x00020400
#define DVD_INTERNALERROR_PROTOCOL_ERROR    0x00040800

// NNGC drive specific
#define DVD_INTERNALERROR_GAME_DISK         0x00053100
#define DVD_INTERNALERROR_DVD_VIDEO_DISK    0x00053000
#define DVD_INTERNALERROR_EJECT_FAILED      0x00045300
#define DVD_INTERNALERROR_NOT_CORRESPOND_MEDIA 0x00056400

// NPDP cartridge specific
#define DVD_INTERNALERROR_NPDP_UNKNOWNNPDPERROR         0x00100000
#define DVD_INTERNALERROR_NPDP_UNKNOWNFLASHROM          0x00100001
#define DVD_INTERNALERROR_NPDP_FLASHROMERASEERROR       0x00100002
#define DVD_INTERNALERROR_NPDP_FLASHROMWRITEERROR       0x00100003
#define DVD_INTERNALERROR_NPDP_FLASHROMVERIFYERROR      0x00100004
#define DVD_INTERNALERROR_NPDP_SECURITYUNLOCKERROR      0x00100005
#define DVD_INTERNALERROR_NPDP_SECURITYUPDATEERROR      0x00100006
#define DVD_INTERNALERROR_NPDP_HARDDISKREADERROR        0x00100007
#define DVD_INTERNALERROR_NPDP_HARDDISKWRITEERROR       0x00100008

#define DVD_INTERNALERROR_NPDP_MIN                      0x00100000
#define DVD_INTERNALERROR_NPDP_MAX                      0x00100008


#define DVD_INTTYPE_TC              1
#define DVD_INTTYPE_DE              2
#define DVD_INTTYPE_CVR             4
#define DVD_INTTYPE_BRK             8
#define DVD_INTTYPE_TIMEOUT         16
#define DVD_INTTYPE_SECURITY_ERROR  32
#define DVD_INTTYPE_ETICKET_ERROR   64

#define DVD_COVER_UNKNOWN    0
#define DVD_COVER_OPEN       1
#define DVD_COVER_CLOSED     2

#define DVD_UNENCRYPTED_START           0x40000
#define DVD_UNENCRYPTED_LENGTH          (64 * 1024)

enum
{
    DVD_WATYPE_NONE,
    DVD_WATYPE_COMBO1,
    DVD_WATYPE_MAX
};


BOOL DVDLowInit          ( void );

BOOL DVDLowRead          ( void* addr, u32 length, u32 offset_4_byte,
                           DVDLowCallback callback );

BOOL DVDLowSeek          ( u32 offset_4_byte, DVDLowCallback callback );

BOOL DVDLowWaitForCoverClose( DVDLowCallback callback );

BOOL DVDLowReadDiskID    ( DVDDiskID* diskID, DVDLowCallback callback );

BOOL DVDLowStopMotor     ( BOOL eject, BOOL saving, DVDLowCallback callback );

BOOL DVDLowRequestError  ( DVDLowCallback callback );

BOOL DVDLowInquiry       ( DVDDriveInfo* info, DVDLowCallback callback );

BOOL DVDLowAudioStream   ( u32 subcmd, u32 length, u32 offset_4_byte, DVDLowCallback callback );

BOOL DVDLowRequestAudioStatus ( u32 subcmd, DVDLowCallback callback );

BOOL DVDLowSetSpinupFlag ( u32 spinup );

#if !defined(DI_DIRECT) && defined(IOP_REV)
BOOL DVDLowReset(DVDLowCallback callback);
#else
void DVDLowReset         ( void );
#endif

BOOL DVDLowNotifyReset   ( void );

BOOL DVDLowAudioBufferConfig ( BOOL enable, u32 size, DVDLowCallback callback );

BOOL DVDLowBreak         ( void );

// add for NNGC
BOOL DVDLowReadDvd       ( BOOL stream, BOOL retry, void* addr, u32 length, u32 start, DVDLowCallback callback );

BOOL DVDLowReadDvdConfig ( BOOL set, u32 type, u32 config, DVDLowCallback callback );

BOOL DVDLowReadDvdPhysical ( DVDVideoPhysical *physical, u32 layer, DVDLowCallback callback );

BOOL DVDLowReadDvdCopyright ( u32 layer, DVDLowCallback callback );

BOOL DVDLowReadDvdDiscKey (  DVDVideoDiscKey *discKey, u32 layer, DVDLowCallback callback );

BOOL DVDLowReportKey     ( DVDVideoReportKey *reportKey, u32 format, u32 lsn, DVDLowCallback callback );

BOOL DVDLowStopLaser     ( DVDLowCallback callback );

BOOL DVDLowOffset        ( u32 subcmd, u32 offset_4_byte, DVDLowCallback callback );

BOOL DVDLowReadDiskBca   ( DVDLowDiskBca* diskBca, DVDLowCallback callback );

BOOL DVDLowSerMeasControl ( DVDLowDriveSer *ser, BOOL clear, BOOL enable, DVDLowCallback callback );

BOOL DVDLowRequestDiscStatus ( DVDLowCallback callback );

BOOL DVDLowRequestRetryNumber ( DVDLowCallback callback );

BOOL DVDLowSetMaximumRotation ( u32 subcmd, DVDLowCallback callback );

DVDLowCallback DVDLowSetResetCoverCallback ( DVDLowCallback callback );

DVDLowCallback DVDLowClearCallback ( void );

u32 DVDLowGetCoverStatus ( void );

// add for NNGC
u32 DVDLowGetCoverReg(void);

u32 DVDLowGetLength(void);

u32 DVDLowGetImmBufferReg(void);

BOOL DVDLowUnmaskStatusInterrupts(void);

BOOL DVDLowMaskCoverInterrupt(void);

BOOL DVDLowUnmaskCoverInterrupt(void);

#if !defined(DI_DIRECT) && defined(IOP_REV)
BOOL DVDLowClearCoverInterrupt(DVDLowCallback callback);

BOOL DVDLowOpenPartition(const u32 partitionWordOffset,
                         const ESTicket* const eTicket,
                         const u32 numCertBytes, const u8* const certificates,
                         ESTitleMeta *tmd, DVDLowCallback callback);

BOOL DVDLowClosePartition(DVDLowCallback callback);

BOOL DVDLowUnencryptedRead( void* addr, u32 length, u32 offset_4_byte,
                            DVDLowCallback callback );

BOOL DVDLowGetNoDiscBufferSizes(const u32 partitionWordOffset,
                                      u32 *numTmdBytes,
                                      u32 *numCertBytes,
                                      DVDLowCallback callback);

BOOL
DVDLowGetNoDiscOpenPartitionParams(const u32      partitionWordOffset,
                                   ESTicket       *eTicket,
                                   u32            *numTmdBytes,
                                   ESTitleMeta    *tmd,
                                   u32            *numCertBytes,
                                   u8             *certificates,
                                   u32            *dataWordOffset,
                                   u8             *h3HashPtr,
                                   DVDLowCallback callback);
BOOL
DVDLowNoDiscOpenPartition(const ESTicket* const    eTicket,
                          const u32                numTmdBytes,
                          const ESTitleMeta* const tmd,
                          const u32                numCertBytes,
                          const u8* const          certificates,
                          const u32                dataWordOffset,
                          const u8* const          h3HashPtr,
                          DVDLowCallback           callback);

BOOL
DVDLowOpenPartitionWithTmdAndTicket(const u32        partitionWordOffset,
                                    const ESTicket* const     eTicket, 
                                    const u32                 numTmdBytes,
                                    const ESTitleMeta* const  tmd,
                                    const u32                 numCertBytes,
                                    const u8* const           certificates,
                                    DVDLowCallback            callback);

BOOL
DVDLowOpenPartitionWithTmdAndTicketView(const u32        partitionWordOffset,
                                        const ESTicketView* const eTicketView, 
                                        const u32                 numTmdBytes,
                                        const ESTitleMeta* const  tmd,
                                        const u32                 numCertBytes,
                                        const u8* const           certificates,
                                        DVDLowCallback            callback);

u32  DVDLowGetStatusRegister(void);
BOOL DVDLowPrepareStatusRegister(DVDLowCallback callback);

s32 DVDLowGetLastEticketError(void);
#else
BOOL DVDLowClearCoverInterrupt(void);
#endif

BOOL DVDLowFinalize          ( void );

void __DVDLowSetWAType(u32 type, s32 seekLoc);

void __DVDInitWA(void);

BOOL __DVDLowTestAlarm(const OSAlarm* alarm);

#ifdef __cplusplus
}
#endif

#endif  // __DVDLOW_H__
