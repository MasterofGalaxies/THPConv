/*---------------------------------------------------------------------------*
  Project:      content API library
  File:         cnt.c

  Copyright (C) 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.15  2008/01/10 13:49:38  wada_jumpei
  Added contentRead[NAND/DVD]Modified and created CNTReadWithOffset.

  Revision 1.14  2007/11/19 02:46:10  wada_jumpei
  Added CNT_RESULT_DVD_CANCELED.

  Revision 1.13  2007/09/21 00:38:23  johnc
  Added data title support (CNTInitHandleTitle).
  Change most all functions to switch between DVD/NAND at runtime.
  This library should be backward compatible.

  Revision 1.12  2007/06/28 00:01:35  wada_jumpei
  Fixed definition argument name of CNTInitHandle

  Revision 1.11  2007/04/27 11:05:54  wada_jumpei
  Added CNTGetFSTSize

  Revision 1.10  2007/03/28 07:59:10  wada_jumpei
  Added 32 byte alignment check for memory allocator

  Revision 1.9  2006/12/12 07:52:38  wada_jumpei
  Added OSRegisterVersion and removed restriction of path length

  Revision 1.8  2006/12/06 07:36:12  wada_jumpei
  Modified error code and error message
  Added CNTTell to prevent direct access to fileinfo member

  Revision 1.7  2006/10/26 04:28:07  wada_jumpei
  Added some error code and assertion

  Revision 1.6  2006/10/01 14:49:46  wada_jumpei
  Added CNTFastOpen and removed unused header file

  Revision 1.5  2006/09/29 08:32:08  shirakae
  Added CNTConvertPathToEntrynum, CNTEntrynumIsDir

  Revision 1.4  2006/09/26 14:17:48  wada_jumpei
  Added CNTShutdown for device shutdown

  Revision 1.3  2006/08/24 06:06:23  wada_jumpei
  Added relative path support and directory access

  Revision 1.2  2006/08/10 12:15:24  wada_jumpei
  Modified error codes and added some comments

  Revision 1.1  2006/08/10 12:10:30  wada_jumpei
  Initial check in

 *---------------------------------------------------------------------------*/

#ifndef __CNT_H__
#define __CNT_H__

#include <revolution/dvd.h>
#include <revolution/arc.h>
#include <revolution/mem.h>
#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*
    Definition of constant values
 *----------------------------------------------------------------------------*/

/* ---CNT_RESULT_CODE --- */
#define CNT_RESULT_OK                0
#define CNT_RESULT_MAXFD             (-5000)
#define CNT_RESULT_ALLOC_FAILED      (-5001)
#define CNT_RESULT_READ_ERR          (-5003)
#define CNT_RESULT_CLOSE_ERR         (-5005)
#define CNT_RESULT_OUT_OF_MEMORY     (-5008)
#define CNT_RESULT_INVALID           (-5009)
#define CNT_RESULT_ACCESS            (-5010)
#define CNT_RESULT_CORRUPT           (-5011)
#define CNT_RESULT_ECC_CRIT          (-5012)
#define CNT_RESULT_AUTHENTICATION    (-5013)
#define CNT_RESULT_DVD_CANCELED      (-5014)
#define CNT_RESULT_UNKNOWN           (-5063)
#define CNT_RESULT_FATAL             (-5127)

/* --- OLD result codes (unused or unified) --- */
//#define CNT_RESULT_OPEN_ERR          (-5002)
//#define CNT_RESULT_SEEK_ERR          (-5004)
//#define CNT_RESULT_NOT_EXIST         (-5006)
//#define CNT_RESULT_NOT_ENOUGH_SPACE  (-5007)


/* --- Parametar "whence" in CNTSeek --- */
#define CNT_SEEK_SET    0   // start of the file
#define CNT_SEEK_CUR    1   // current point
#define CNT_SEEK_END    2   // end of the file (note that "offset" must be negative)


/*----------------------------------------------------------------------------*
    Definition of structures for CNT API
 *----------------------------------------------------------------------------*/

typedef enum
{
    CNT_TYPE_UNDEFINED = 0,
    CNT_TYPE_NAND      = 1,
    CNT_TYPE_DVD       = 2
} CNTType;

// structure for CNThandle
typedef struct
{
    ARCHandle           ArcHandle;
    s32                 FileDescriptor;
    MEMAllocator*       allocator;
} CNTHandleNAND;

typedef struct
{
    u32                 index;
    s32                 rootDir;
    s32                 currDir;
    u8                  reserved[24];
} CNTHandleDVD;

typedef struct
{
    union {
      CNTHandleNAND     nand;
      CNTHandleDVD      dvd;
    } as;
    u8                  type;   // CNTType

} CNTHandle;

// structure for file access
typedef struct
{
    CNTHandleNAND*      CntHandle;
    u32                 startOffset;
    u32                 length;
    s32                 readOffset;
} CNTFileInfoNAND;

typedef struct
{
    DVDFileInfo         fileInfo;
    s32                 readOffset;
} CNTFileInfoDVD;

typedef struct
{
    union {
      CNTFileInfoNAND   nand;
      CNTFileInfoDVD    dvd;
    } as;
    u8                  type;   // CNTType

} CNTFileInfo;

// structure for directory access
typedef struct
{
    u8          type;           // CNTType
    ARCHandle*  handle;         // from here, same as ARCDir (type is nand if handle is non-NULL)
    u32         entryNum;       // from here, same as DVDDir
    u32         location;
    u32         next;
} CNTDir;

typedef struct
{
    u8          type;           // CNTType
    ARCHandle*  handle;         // from here, same as ARCDir (type is nand if handle is non-NULL)
    u32         entryNum;       // from here, same as DVDDir
    BOOL        isDir;
    char*       name;
} CNTDirEntry;

/*----------------------------------------------------------------------------*
    Definition of common APIs
 *----------------------------------------------------------------------------*/

void CNTInit                          ( void );
void CNTShutdown                      ( void );

/*----------------------------------------------------------------------------*
    Definition of the APIs for NAND applications
 *----------------------------------------------------------------------------*/

// Handle access API
s32  contentInitHandleNAND            ( u32 contentIdx, CNTHandle* Cnt, MEMAllocator* allocator );
s32  contentReleaseHandleNAND         ( CNTHandleNAND* Cnt );

// File access API
s32  contentOpenNAND                  ( CNTHandleNAND* Cnt, const char* filename, CNTFileInfoNAND* cf );
s32  contentReadNAND                  ( CNTFileInfoNAND* cf, void* addr, u32 length, s32 offset );
s32  contentReadNANDModified          ( CNTFileInfoNAND* cf, void* addr, u32 length );
s32  contentSeekNAND                  ( CNTFileInfoNAND* cf, s32 offset, u32 whence );
s32  contentTellNAND                  ( CNTFileInfoNAND* cf );
u32  contentGetLengthNAND             ( CNTFileInfoNAND* cf );
s32  contentCloseNAND                 ( CNTFileInfoNAND* cf );

s32  contentFastOpenNAND              ( CNTHandleNAND* Cnt, s32 entrynum, CNTFileInfoNAND* cf );
s32  contentConvertPathToEntrynumNAND ( CNTHandleNAND* Cnt, const char* filename );

// Support directory change and relative path
s32  contentChangeDirNAND             ( CNTHandleNAND* Cnt, const char* dirName );
s32  contentGetCurrentDirNAND         ( CNTHandleNAND* Cnt, char* path, u32 maxlen );

// Directory access API
BOOL contentOpenDirNAND               ( CNTHandleNAND* Cnt, const char* dirName, ARCDir* dir );

// Get FST length
s32  contentGetFSTSizeNAND            ( u32 contentIdx, u32* size );

/*----------------------------------------------------------------------------*
    Definition of the APIs for DVD applications
 *----------------------------------------------------------------------------*/

// Handle access API
s32  contentInitHandleDVD             ( u32 contentIdx, CNTHandle* Cnt, MEMAllocator* allocator );
s32  contentReleaseHandleDVD          ( CNTHandleDVD* Cnt );

// File access API
s32  contentOpenDVD                   ( CNTHandleDVD* Cnt, const char* filename, CNTFileInfoDVD* cf );
s32  contentReadDVD                   ( CNTFileInfoDVD* cf, void* addr, u32 length, s32 offset );
s32  contentReadDVDModified           ( CNTFileInfoDVD* cf, void* addr, u32 length );
s32  contentSeekDVD                   ( CNTFileInfoDVD* cf, s32 offset, u32 whence );
s32  contentTellDVD                   ( CNTFileInfoDVD* cf );
u32  contentGetLengthDVD              ( CNTFileInfoDVD* cf );
s32  contentCloseDVD                  ( CNTFileInfoDVD* cf );

s32  contentFastOpenDVD               ( CNTHandleDVD* Cnt, s32 entrynum, CNTFileInfoDVD* cf );
s32  contentConvertPathToEntrynumDVD  ( CNTHandleDVD* Cnt, const char* filename );

// Support directory change and relative path
s32  contentChangeDirDVD              ( CNTHandleDVD* Cnt, const char* dirName );
s32  contentGetCurrentDirDVD          ( CNTHandleDVD* Cnt,  char* path, u32 maxlen );

// Directory access API
BOOL contentOpenDirDVD                ( CNTHandleDVD* Cnt, const char* dirName, DVDDir* dir );

// Get FST length
s32  contentGetFSTSizeDVD             ( u32 contentIdx, u32* size );

/*----------------------------------------------------------------------------*
    Convert APIs by compile switch "NANDAPP"
 *----------------------------------------------------------------------------*/

#ifdef NANDAPP
#define CNTInitHandle(contentIdx, CntHandle, allocator) contentInitHandleNAND((contentIdx), (CntHandle), (allocator))
#else
#define CNTInitHandle(contentIdx, CntHandle, allocator) contentInitHandleDVD((contentIdx), (CntHandle), (allocator))
#endif
s32     CNTInitHandleTitle            ( u64 titleId, u32 contentIdx, CNTHandle* Cnt, MEMAllocator* allocator );
s32     CNTReleaseHandle              ( CNTHandle* Cnt );

s32     CNTOpen                       ( CNTHandle* Cnt, const char* filename, CNTFileInfo* cf );
s32     CNTRead                       ( CNTFileInfo* cf, void* addr, u32 length );
s32     CNTReadWithOffset             ( CNTFileInfo* cf, void* addr, u32 length, s32 offset );
s32     CNTSeek                       ( CNTFileInfo* cf, s32 offset, u32 whence );
s32     CNTTell                       ( CNTFileInfo* cf );
u32     CNTGetLength                  ( CNTFileInfo* cf );
s32     CNTClose                      ( CNTFileInfo* cf );

s32     CNTFastOpen                   ( CNTHandle* Cnt, s32 entrynum, CNTFileInfo* cf );
s32     CNTConvertPathToEntrynum      ( CNTHandle* Cnt, const char* filename );
BOOL    CNTEntrynumIsDir              ( CNTHandle* Cnt, s32 entrynum );

s32     CNTChangeDir                  ( CNTHandle* Cnt, const char* dirName );
s32     CNTGetCurrentDir              ( CNTHandle* Cnt, char* path, u32 maxlen );

BOOL    CNTOpenDir                    ( CNTHandle* Cnt, const char* dirName, CNTDir* dir );
BOOL    CNTReadDir                    ( CNTDir* dir, CNTDirEntry* dirent );
BOOL    CNTCloseDir                   ( CNTDir* dir );
u32     CNTTellDir                    ( CNTDir* dir );
void    CNTSeekDir                    ( CNTDir* dir, u32 loc );
void    CNTRewindDir                  ( CNTDir* dir );

// Get FST length
#ifdef NANDAPP
#define CNTGetFSTSize(index, size) contentGetFSTSizeNAND((index), (size))
#else // DVDDiscAPP
#define CNTGetFSTSize(index, size) contentGetFSTSizeDVD((index), (size))
#endif

#ifdef CNT_READ_BACKWARD_COMPATIBLE
#define CNTRead CNTReadWithOffset
#endif

#ifdef __cplusplus
}
#endif

#endif // end of __CNT_H__
