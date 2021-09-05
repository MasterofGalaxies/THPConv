/*---------------------------------------------------------------------------*
  Project:      NAND flash logging module
  File:         nandlogging.h
  Programmer:   HIRATSU Daisuke

  Copyright (C) 2007 Nintendo  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2007/04/11 07:56:43  hiratsu
  Initial check-in.

 *---------------------------------------------------------------------------*/


#ifndef __NANDLOGGING_H__
#define __NANDLOGGING_H__

#include <revolution/os.h>

#ifdef __cplusplus
extern "C" {
#endif


#define NAND_LOG_LINESIZE     256        // bytes
#define NAND_LOG_FILESIZE     (16*1024)  // 1 FS block size
#define NAND_LOG_LINES        (NAND_LOG_FILESIZE/NAND_LOG_LINESIZE)
#define NAND_LOG_FILENAME     "nanderr.log"
#define NAND_LOG_DIR          "/shared2/test2/"
#define NAND_LOG_TMPDIR       "/tmp/"
#define NAND_LOG_FILEPATH     NAND_LOG_DIR NAND_LOG_FILENAME
#define NAND_LOG_TMPFILEPATH  NAND_LOG_TMPDIR NAND_LOG_FILENAME

typedef void (*NANDLoggingCallback)(BOOL result);

BOOL NANDLoggingPrepareFile    (u8 workBuf[NAND_LOG_FILESIZE]);
BOOL NANDLoggingAddMessage     (                        const char *fmt, ...);
BOOL NANDLoggingAddMessageAsync(NANDLoggingCallback cb, const char *fmt, ...);


#ifdef __cplusplus
}
#endif


#endif // end of __NANDLOGGING_H__
