/*---------------------------------------------------------------------------*
  Project:  Dolphin Expansion Interface API
  File:     exi.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    2     11/05/99 12:17p Hashida
    Removed "temporary" comment.
    
    1     10/28/99 6:55p Hashida
    Initial revision
    
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __DBLOG_H__
#define __DBLOG_H__

#include <revolution/os.h>

/*
 * most of the following definitions are meaningless;
 * only DB_WRONLY works, DB_CREAT and DB_TRUNC are 
 * always considered to be specified.
 */
#define DB_RDONLY         0x0001
#define DB_WRONLY         0x0002
#define DB_RDWR           0x0004
#define DB_NONBLOCK       0x0008
#define DB_APPEND         0x0010
#define DB_CREAT          0x0020
#define DB_TRUNC          0x0040
#define DB_EXCL           0x0080
#define DB_SHLOCK         0x0100
#define DB_EXLOCK         0x0200

/*
 * Buffer size
 */
#define DB_BUFSIZE        (3 * 1024)

#define DB_PACKETADDR     0xfff7e040

typedef struct 
{
    u32       control;
    u32       length;
    char      fileName[32];
    u8        dataBuffer[DB_BUFSIZE];

} __DBPacket_s;

volatile __DBPacket_s __DBPacket : DB_PACKETADDR;

/*
 * definition for DB control
 */
#define DB_CONTROL_START    0x00000001
#define DB_CONTROL_APPEND   0x00000002

/*
 * low level unbuffered function calls
 */
s32 __DBOpen(char *filename, u32 flags);
s32 __DBWrite(s32 d, const void *buf, s32 nbytes);
s32 __DBClose(s32 d);

/*
 * high level block buffered function calls
 */
s32 DBLogOpen(char *filename, char* mode);
s32 DBLogWrite(s32 d, const void *buf, s32 nbytes);
s32 DBLogFlush(s32 d);
s32 DBLogClose(s32 d);

#endif  // __DBLOG_H__
