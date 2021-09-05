/*---------------------------------------------------------------------------*
  Project:  NNGC OS
  File:     dvdvideo.h

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.7  2006/06/21 04:25:17  shino
  add DVDVideoSetEmuError and DVDVideoClearEmuError.

  Revision 1.6  2006/06/20 05:07:49  ooizumi
  Added definition of DVD_RESULT_GAME_DISK.

  Revision 1.5  2006/06/09 07:35:01  ooizumi
  Added error code.

  Revision 1.4  2006/05/10 17:11:04  ooizumi
  Changed command difinitions.

  Revision 1.3  2006/04/24 05:45:58  ooizumi
  Added DVDVideo APIs.

  Revision 1.2  2006/02/04 13:05:45  hashida
  (none)

  Revision 1.1  2006/02/03 01:33:47  ooizumi
  Moved from dolphin directory.

  Revision 1.1.1.1  2005/12/29 06:53:27  hiratsu
  Initial import.

  Revision 1.3  2005/11/25 01:54:12  ooizumi
  Fixed DVDVideoReportKey dataq member.
  Deleted DVDVideoBca.

  Revision 1.2  2005/07/08 04:53:34  ooizumi
  Added the bit-field difinition of bcaFlag.


  $NoKeywords: $
 *---------------------------------------------------------------------------*/


#ifndef __DVDVIDEO_H__
#define __DVDVIDEO_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DVDVIDEO_MAX_ONE_TRANSFER 0x00080000

#define DVD_COMMAND_READ_DVD              64
#define DVD_COMMAND_READ_PHYSICAL         65
#define DVD_COMMAND_READ_COPYRIGHT        66
#define DVD_COMMAND_READ_DISCKEY          67
#define DVD_COMMAND_REPORTKEY             68

#define DVD_RESULT_NO_DISK                -4
#define DVD_RESULT_ECC_ERROR              -5
#define DVD_RESULT_GAME_DISK              -6
#define DVD_RESULT_DVDVIDEO_DISK          -7 // only for DVDReadDiskID

#define DVD_STATE_WII_DISK                13
#define DVD_STATE_GC_DISK                 14

// physical information
typedef struct DVDVideoPhysical DVDVideoPhysical;

struct DVDVideoPhysical
{
    // byte 0
    u8 bookType    :4;
    u8 partVersion :4;

    // byte 1
    u8 discSize    :4;
    u8 maximumRate :4;

    // byte 2
    u8 reserved1   :1;
    u8 numOfLayer  :2;
    u8 trackPath   :1;
    u8 layerType   :4;

    // byte 3
    u8 linearDensity :4;
    u8 trackDensity  :4;

    // byte 4-7
    u8 zero1;
    u8 startingPhysicalSectorNumberOfDataArea[3];

    // byte 8-11
    u8 zero2;
    u8 endPhysicalSectorNumberOfDataArea[3];

    // byte 12-15
    u8 zero3;
    u8 endSectorNumberOfLayer0[3];

    // byte 16
    u8 bcaFlag    :1;
    u8 resesrved2 :7;

    // byte 17-2047
    u8 mediaSpecific[2031];
};

// copyright information
typedef struct DVDVideoCopyright DVDVideoCopyright;

struct DVDVideoCopyright
{
    u8 copyrightProtectionSystemType;
    u8 regionManagementInfo;
    u8 reserved[2];
};

// disk key
typedef struct DVDVideoDiscKey DVDVideoDiscKey;

struct DVDVideoDiscKey
{
    u8 diskKey[2048];
};

// copyright management info and title key
typedef struct DVDVideoContentKey DVDVideoContentKey;
typedef struct DVDVideoContentKey DVDVideoReportKey;  // for backward compatibility

struct DVDVideoContentKey
{
    u8 cpmInfo;
    u8 titleKey[5];
    u8 reserved[26];
};

typedef struct DVDVideoInfo  DVDVideoInfo;

/*---------------------------------------------------------------------------*
  Name:         DVDVideoCallback

  Description:  DVDVideo callback function

  Arguments:    result      If the function that set the callback succeeds,
                            it is the number of bytes transferred. If that
                            function fails, it is -1.

  Returns:      None.
 *---------------------------------------------------------------------------*/
typedef void (*DVDVideoCallback)(s32 result, DVDVideoInfo* videoInfo);


struct DVDVideoInfo
{
    DVDCommandBlock cb;

    u32             startAddr;      // disk address of file
    u32             length;         // file size in bytes

    DVDCallback     callback;
};


void DVDVideoInit(void);

BOOL DVDVideoOpen(DVDVideoInfo* videoInfo);
BOOL DVDVideoClose(DVDVideoInfo* videoInfo);

s32 DVDVideoGetTransferredSector(DVDVideoInfo* videoInfo);

void __DVDVideoNotifyLoaded(void);

s32  DVDVideoReadPrio    ( DVDVideoInfo* videoInfo, void* addr, s32 lsn, s32 length, s32 prio );

BOOL DVDVideoReadAsyncPrio
                         ( DVDVideoInfo* videoInfo, void* addr, s32 lsn, s32 length, DVDVideoCallback callback, s32 prio );

#define DVDVideoRead(videoInfo, addr, lsn, length)                 \
                           DVDVideoReadPrio((videoInfo), (addr), (lsn), (length), 2)
#define DVDVideoReadAsync(videoInfo, addr, lsn, length, callback)  \
                           DVDVideoReadAsyncPrio((videoInfo), (addr), (lsn), (length), (callback), 2)

s32  DVDVideoReadPhysicalPrio
                         ( DVDVideoInfo* videoInfo, DVDVideoPhysical *physical, u8 layer, s32 prio );
BOOL DVDVideoReadPhysicalAsyncPrio
                         ( DVDVideoInfo* videoInfo, DVDVideoPhysical *physical, u8 layer, DVDVideoCallback callback, s32 prio );

#define DVDVideoReadPhysical(videoInfo, physical, layer)                 \
                           DVDVideoReadPhysicalPrio((videoInfo), (physical), (layer), 2)
#define DVDVideoReadPhysicalAsync(videoInfo, physical, layer, callback)  \
                           DVDVideoReadPhysicalAsyncPrio((videoInfo), (physical), (layer), (callback), 2)

s32  DVDVideoReadCopyrightPrio
                         ( DVDVideoInfo* videoInfo, DVDVideoCopyright *copyright, u8 layer, s32 prio );
BOOL DVDVideoReadCopyrightAsyncPrio
                         ( DVDVideoInfo* videoInfo, DVDVideoCopyright *copyright, u8 layer, DVDVideoCallback callback, s32 prio );

#define DVDVideoReadCopyright(videoInfo, copyright, layer)                 \
                           DVDVideoReadCopyrightPrio((videoInfo), (copyright), (layer), 2)
#define DVDVideoReadCopyrightAsync(videoInfo, copyright, layer, callback)  \
                           DVDVideoReadCopyrightAsyncPrio((videoInfo), (copyright), (layer), (callback), 2)

s32  DVDVideoReadDiscKeyPrio
                         ( DVDVideoInfo* videoInfo, DVDVideoDiscKey *discKey, u8 layer, s32 prio );
BOOL DVDVideoReadDiscKeyAsyncPrio
                         ( DVDVideoInfo* videoInfo, DVDVideoDiscKey *discKey, u8 layer, DVDVideoCallback callback, s32 prio );

#define DVDVideoReadDiscKey(videoInfo, discKey, layer)                 \
                           DVDVideoReadDiscKeyPrio((videoInfo), (discKey), (layer), 2)
#define DVDVideoReadDiscKeyAsync(videoInfo, discKey, layer, callback)  \
                           DVDVideoReadDiscKeyAsyncPrio((videoInfo), (discKey), (layer), (callback), 2)

s32  DVDVideoReportKeyPrio
                         ( DVDVideoInfo* videoInfo, DVDVideoContentKey *contentKey, s32 lsn, s32 prio );
BOOL DVDVideoReportKeyAsyncPrio
                         ( DVDVideoInfo* videoInfo, DVDVideoContentKey *contentKey, s32 lsn, DVDVideoCallback callback, s32 prio );

#define DVDVideoReportKey(videoInfo, contentKey, lsn)                 \
                          DVDVideoReportKeyPrio((videoInfo), (contentKey), (lsn), 2)
#define DVDVideoReportKeyAsync(videoInfo, contentKey, lsn, callback)  \
                               DVDVideoReportKeyAsyncPrio((videoInfo), (contentKey), (lsn), (callback), 2)

void DVDVideoSetEmuError(s32 error);
void DVDVideoClearEmuError(void);

#ifdef __cplusplus
}
#endif

#endif  // __DVDVIDEO_H__
