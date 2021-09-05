/*---------------------------------------------------------------------------*
  Project:  FA library
  File:     fa_api_async.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/

 /****************************************************************************
 [fa_api_async.h] - Header file of FA API (ASYNC)
 ****************************************************************************/
#ifndef __FA_API_ASYNC_H__
#define __FA_API_ASYNC_H__

#ifdef __cplusplus
extern "C" {
#endif

/**********************/
/* function prototype */
/**********************/
s32         FAAttachAsync       ( u8 devKind, s8 *nandPath, u32 nandFSize, FADrvTbl *drvTbl,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAMountAsync        ( s8 drive,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAUnmountAsync      ( s8 drive, u32 mode,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block);
s32         FAFormatAsync       ( s8 drive, const char *param,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FACreateAsync       ( const char *fname, s32 mode, FAFile **fp,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFopenAsync        ( const char *fname, const char *mode, FAFile **fp,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFcloseAsync       ( FAFile *fp,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFreadAsync        ( void *buff, FASizeT byte, FASizeT count, FAFile *fp, FASizeT *readSize,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFwriteAsync       ( void *buff, FASizeT byte, FASizeT count, FAFile *fp, FASizeT *writeSize,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFseekAsync        ( FAFile *fp, s32 offset, s32 origin,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFsfirstAsync      ( const char *fname, u8 attr, FADta *dtabuf,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFsnextAsync       ( FADta *dtabuf,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FARemoveAsync       ( const char *fname,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FARenameAsync       ( const char *oldName, const char *newName,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAMoveAsync         ( const char *srcName, const char *dstName,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFappendAsync      ( FAFile *fp, FASizeT byte, FASizeT *appendSize,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFadjustAsync      ( FAFile *fp,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFeofAsync         ( FAFile *fp,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFsexecAsync       ( FADta *dtabuf, s32 type, u8 attr,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FACombineAsync      ( const char *basePath, const char *addPath,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FADivideAsync       ( const char *orgPath, const char *newPath, FASizeT offset,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FACinsertAsync      ( const char *fname, u32 pos, u32 num,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FACdeleteAsync      ( const char *fname, u32 pos, u32 num,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAMkdirAsync        ( const char *dname,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FACreatedirAsync    ( const char *dname, s32 option, FADta *pDta,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FARmdirAsync        ( const char *dname,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAOpendirAsync      ( const char *dname, FADir **dd,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAClosedirAsync     ( FADir *pDir,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FASyncAsync         ( s8 drive, s32 mode,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFsyncAsync        ( FAFile *fp,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );


/***************/
/* Unicode API */
/***************/
s32         FACreateWAsync      ( const unsigned short *fname, s32 mode, FAFile **fp,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFopenWAsync       ( const unsigned short *fname, const unsigned short *mode, FAFile **fp,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFsfirstWAsync     ( const unsigned short *fname, u8 attr, FAWDta *dtabuf,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFsnextWAsync      ( FAWDta *dtabuf,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FARemoveWAsync      ( const unsigned short *fname,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FARenameWAsync      ( const unsigned short *oldName, const unsigned short *newName,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAMoveWAsync        ( const unsigned short *srcName, const unsigned short *dstName,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAFsexecWAsync      ( FAWDta *dtabuf, s32 type, u8 attr,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FACombineWAsync     ( const unsigned short *basePath, const unsigned short *addPath,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FADivideWAsync      ( const unsigned short *orgPath, const unsigned short *newPath, FASizeT offset,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FACinsertWAsync     ( const unsigned short *fname, u32 pos, u32 num,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FACdeleteWAsync     ( const unsigned short *fname, u32 pos, u32 num,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAMkdirWAsync       ( const unsigned short *dname,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FACreatedirWAsync   ( const unsigned short *dname, s32 option, FAWDta *pDta,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FARmdirWAsync       ( const unsigned short *dname,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );
s32         FAOpendirWAsync     ( const unsigned short *dname, FADir **dd,
                                  void (*FACallback)(s32 result, FACommandBlock *block), FACommandBlock *block );

#ifdef __cplusplus
}
#endif

#endif  // __FA_API_ASYNC_H__

