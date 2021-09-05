/*---------------------------------------------------------------------------*
  Project:  FIO(File Input/Output) protocol API for MCC
  File:     fio.h

  Copyright 2000 - 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2006/02/25 08:23:05  mitu
  1st version

    
    6     03/09/12 15:15 Shogo
    corrected #endif comment.
    
    5     8/05/02 19:40 Shiki
    Added const keywords to relevant function prototypes.

    4     6/18/01 4:29p Hashida
    Changed copyright informaiton.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __MCC_FIO_H__
#define __MCC_FIO_H__

// HEADER INCLUDE
// ================
#ifdef WIN32//host incluide here
#include <win32/dolphin.types.h>
#else
#include <revolution/types.h>

#ifndef MCC_TARGET
#define MCC_TARGET
#endif

#endif

#include <revolution/mcc.h>


#ifdef __cplusplus
extern "C" {
#endif

    // DEFINES
    // ================
    //FIOOpenMode
    #define FIO_OPEN_RDONLY         0x0001
    #define FIO_OPEN_WRONLY         0x0002
    #define FIO_OPEN_RDWR           0x0003
    #define FIO_OPEN_CREAT          0x0200
    #define FIO_OPEN_TRUNC          0x0400
    #define FIO_OPEN_EXCL           0x0800
    //FIOSeekMode
    #define FIO_SEEK_TOP            (0)
    #define FIO_SEEK_CUR            (1)
    #define FIO_SEEK_LAST           (2)
    //FIOAttribute
    #define FIO_ATTRIBUTE_DIRECTORY 0x0001
    #define FIO_ATTRIBUTE_HIDDEN    0x0002
    #define FIO_ATTRIBUTE_NORMAL    0x0004
    #define FIO_ATTRIBUTE_READONLY  0x0008
    #define FIO_ATTRIBUTE_SYSTEM    0x0010
    //other
    #define FIO_MAX_PATH            (256)
    #define FIO_INVALID_HANDLE      (0xFFFFFFFF)

    // ERROR CODE DEFINES
    // ================
    #define FIO_ERR_NOERR           0x00
    #define FIO_ERR_UNKNOWN         0xFF
    #define FIO_ERR_UNSUPPORTED     ((u32)-1)

    // FIO ERROR
    #define FIO_ERR_NO_INITIALIZE   0x80
    #define FIO_ERR_MESSAGE_FORMAT  0x81
    #define FIO_ERR_SEQUENCE_NUMBER 0x82
    #define FIO_ERR_PACKET_WRITE    0x83
    #define FIO_ERR_PACKET_READ     0x84
    #define FIO_ERR_PACKET_CODE     0x85
    #define FIO_ERR_NORESULT        0x86
    #define FIO_ERR_MCC_LEVEL       0x87
    #define FIO_ERR_TIMEOUT         0x88
    #define FIO_ERR_TOOLONG         0x89

    #define FIO_ERR_NOT_FOUND       0x90
    #define FIO_ERR_NO_MORE         0x91

    #define FIO_ERR_ASYNC_INVALIDSIZE   0xA0
    #define FIO_ERR_ASYNC_BUSY          0xA1

    #define FIO_ERR_INVALID_PARAMETER   0xB0

    // FILE ERROR
    #define FIO_ERR_EACCES  (13)
    #define FIO_ERR_EDQUOT  (122)
    #define FIO_ERR_EEXIST  (17)
    #define FIO_ERR_ENOENT  (2)
    #define FIO_ERR_ENOSPC  (28)
    #define FIO_ERR_ENFILE  (23)
    #define FIO_ERR_EROFS   (30)
    #define FIO_ERR_EBADF   (9)
    #define FIO_ERR_EIO     (5)
    #define FIO_ERR_EISDIR  (21)

    // TYPE DEFINES
    // ================
    typedef int FIOHandle;

    typedef struct{
        u16 year;
        u8  month;
        u8  day;
    } FIODate;

    typedef struct{
        u8  hour;
        u8  minute;
        u8  second;
        u8  reserved;
    } FIOTime;

    typedef struct{
        FIODate date;
        FIOTime time;
    } FIOFileTime;

    typedef struct{
        u32 fileAttributes;
        FIOFileTime creationTime;
        FIOFileTime lastAccessTime;
        FIOFileTime lastWriteTime;
        u32 fileSizeHigh;
        u32 fileSizeLow;
    } FIOStat;

    typedef struct{
        FIOStat stat;
        char filename[FIO_MAX_PATH];
    } FIOFindData;

    // FUNCTION PROTOTYPES
    // ================
    BOOL    FIOInit( MCCExiChannel exiChannel, MCCChannel chID,u8 blockSize );
    void    FIOExit( void );
    BOOL    FIOQuery( void );
    u8      FIOGetLastError( void );

    FIOHandle FIOFopen  ( const char *filename, u32 mode );
    BOOL    FIOFclose   ( FIOHandle handle );
    u32     FIOFread    ( FIOHandle handle, void *data, u32 size );
    u32     FIOFwrite   ( FIOHandle handle, const void *data, u32 size );
    u32     FIOFseek    ( FIOHandle handle, s32 offset, u32 mode );

    int     FIOFprintf  ( FIOHandle handle, const char *format, ... );

    BOOL    FIOFflush   ( FIOHandle handle );
    BOOL    FIOFstat    ( FIOHandle handle, FIOStat*stat );
    int     FIOFerror   ( FIOHandle handle );

    BOOL    FIOFindFirst( const char* filename, FIOFindData *finddata );
    BOOL    FIOFindNext ( FIOFindData *finddata );

    typedef int FIODir;
    BOOL    FIOOpenDir      ( const char* dirname, FIODir* dir );
    BOOL    FIOCloseDir     ( FIODir dir );
    s32     FIOGetDirSize   ( FIODir dir );
    s32     FIOReadDir      ( FIODir dir, FIOFindData* data, s32 numOfData );

    u32     FIOGetAsyncBufferSize( void );
    BOOL    FIOCheckAsyncDone( u32 *result );
    BOOL    FIOFreadAsync( FIOHandle handle,void* data, u32 size );
    BOOL    FIOFwriteAsync( FIOHandle handle,const void* data, u32 size );

#ifdef __cplusplus
}
#endif

#endif // __MCC_DRFP_H__
