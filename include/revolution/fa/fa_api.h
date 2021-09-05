/*---------------------------------------------------------------------------*
  Project:  FA library
  File:     fa_api.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/

 /****************************************************************************
 [fa_api.h] - Header file of FA API
 ****************************************************************************/
#ifndef __FA_API_H__
#define __FA_API_H__

#ifdef __cplusplus
extern "C" {
#endif

/**********************/
/* function prototype */
/**********************/
s32         FAInit                  ( long config );
s32         FARegistCB              ( u8 devKind, void (*callback1)(s8 drvLetter), void (*callback2)(s8 drvLetter) );
s32         FAAttach                ( u8 devKind, s8 *nandPath, u32 nandFSize, FADrvTbl *drvTbl );
s32         FADetach                ( s8 drive );
s32         FAMount                 ( s8 drive );
s32         FAUnmount               ( s8 drive, u32 mode );
s32         FAFormat                ( s8 drive, const char *param );
FAFile*     FACreate                ( const char *fname, s32 mode);
FAFile*     FAFopen                 ( const char *fname, const char *mode );
s32         FAFclose                ( FAFile *fp );
FASizeT     FAFread                 ( void *buff, FASizeT byte, FASizeT count, FAFile *fp );
FASizeT     FAFwrite                ( void *buff, FASizeT byte, FASizeT count, FAFile *fp );
s32         FAFseek                 ( FAFile *fp, s32 offset, s32 origin );
s32         FAFsfirst               ( const char *fname, u8 attr, FADta *dtabuf );
s32         FAFsnext                ( FADta *dtabuf );
s32         FARemove                ( const char *fname );
s32         FARename                ( const char *oldName, const char *newName );
s32         FAMove                  ( const char *srcName, const char *dstName );
FASizeT     FAFappend               ( FAFile *fp, FASizeT byte );
s32         FAFadjust               ( FAFile *fp );
s32         FAFstat                 ( const char *pname, FAStat *fstat );
s32         FAFinfo                 ( FAFile *fp, FAInfo *finfo );
s32         FAFeof                  ( FAFile *fp );
s32         FAFsexec                ( FADta *dtabuf, s32 type, u8 attr );
s32         FAFlock                 ( FAFile *fp, u32 operation );
s32         FACombine               ( const char *basePath, const char *addPath );
s32         FADivide                ( const char *orgPath, const char *newPath, FASizeT offset );
s32         FACinsert               ( const char *fname, u32 pos, u32 num );
s32         FACdelete               ( const char *fname, u32 pos, u32 num );
s32         FAMkdir                 ( const char *dname );
s32         FACreatedir             ( const char *dname, s32 option, FADta *pDta );
s32         FARmdir                 ( const char *dname );
s32         FAChdir                 ( const char *dname );
s32         FAFchdir                ( FADir *pDir );
FADir*      FAOpendir               ( const char *dname );
s32         FAClosedir              ( FADir *pDir );
s32         FAChmod                 ( const char *fname, s32 attr );
s32         FAChdmod                ( const char *dname, s32 attr );
s32         FASync                  ( s8 drive, s32 mode );
s32         FAFsync                 ( FAFile *fp );
s32         FAFerror                ( FAFile *fp );
s32         FAErrnum                ( void );
s32         FADerrnum               ( s8 drive );
s32         FAGetdev                ( s8 drive, FADevInf *devInf );
s32         FASetvol                ( s8 drive, const char *vname );
s32         FAGetvol                ( s8 drive, FAVolTab *voltab );
s32         FARmvvol                ( s8 drive );
s32         FABuffering             ( s8 drive, s32 mode );
s32         FASetclstlink           ( s8 drive, s32 mode, FACluster *clstbuf );
s32         FAFsetclstlink          ( FAFile *fp, s32 mode, FAClusterFile *clstbuf );
s32         FASetupfsi              ( s8 drive, s16 mode );
s32         FASettailbuf            ( s8 drive, u32 size, FATailBuf *tailbuf );
s32         FASetvolcfg             ( s8 drive, FAVolCfg* config );
s32         FAGetvolcfg             ( s8 drive, FAVolCfg* config );
s32         FARegctx                ( void );
s32         FAUnregctx              ( void );
s32         FASetcode               ( u8 codeKind, FACharCode *pCodeset );
s32         FASetencode             ( u32 mode );
s32         FAIsWriteProtected      ( s8 drive );
void*       FAGetUserData           ( FACommandBlock *block );
s32         FASetUserData           ( FACommandBlock *block, void *userData );
OSPriority  FAGetThreadPriority     ( void );
s32         FASetThreadPriority     ( OSPriority priority );
s32         FAInitDiskManager       ( u32 config, void *param );
s32         FAOpenDisk              ( FAInitDisk *initDiskTbl, FADisk **disk );
s32         FACloseDisk             ( FADisk *disk );
s32         FAOpenPartition         ( FADisk *disk, s32 partId, FAPartition **part );
s32         FAClosePartition        ( FAPartition *part );
void        FADiskNotifyMediaEject  ( FADisk *disk );
void        FADiskNotifyMediaInsert ( FADisk *disk );

s32         FAUsbInit(void* memAddr, u32 memSize);
s32         FAUsbTerminate(void);

/***************/
/* Unicode API */
/***************/
FAFile*     FACreateW               ( const unsigned short *fname, s32 mode );
FAFile*     FAFopenW                ( const unsigned short *fname, const unsigned short *mode );
s32         FAFsfirstW              ( const unsigned short *fname, u8 attr, FAWDta *dtabuf );
s32         FAFsnextW               ( FAWDta *dtabuf );
s32         FARemoveW               ( const unsigned short *fname );
s32         FARenameW               ( const unsigned short *oldName, const unsigned short *newName );
s32         FAMoveW                 ( const unsigned short *srcName, const unsigned short *dstName );
s32         FAFstatW                ( const unsigned short *pname, FAStat *fstat );
s32         FAFsexecW               ( FAWDta *dtabuf, s32 type, u8 attr );
s32         FACombineW              ( const unsigned short *basePath, const unsigned short *addPath );
s32         FADivideW               ( const unsigned short *orgPath, const unsigned short *newPath, FASizeT offset );
s32         FACinsertW              ( const unsigned short *fname, u32 pos, u32 num );
s32         FACdeleteW              ( const unsigned short *fname, u32 pos, u32 num );
s32         FAMkdirW                ( const unsigned short *dname );
s32         FACreatedirW            ( const unsigned short *dname, s32 option, FAWDta *pDta );
s32         FARmdirW                ( const unsigned short *dname );
s32         FAChdirW                ( const unsigned short *dname );
FADir*      FAOpendirW              ( const unsigned short *dname );
s32         FAChmodW                ( const unsigned short *fname, s32 attr );
s32         FAChdmodW               ( const unsigned short *fname, s32 attr );

#ifdef __cplusplus
}
#endif

#endif  // __FA_API_H__

