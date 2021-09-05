/*---------------------------------------------------------------------------*
  Project:  ARAM manager for AX Demos
  File:     am.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/05/12 02:41:06  yasuh-to
  dolphinシースツリーから移植

    
    5     02/11/08 2:54p Akagi
    Decreased Zero buffer size to 256 bytes.
    
    4     8/19/02 7:11p Eugene
    Increased Zero buffer size to 1280 bytes, as needed for fully-pitched
    sounds. 
    
    3     02/08/08 19:38 Hirose
    Avoid multi-inclusion. C++ support.
    
    2     9/04/01 12:01a Eugene
    First version!
    
    1     8/31/01 2:58p Eugene
    ARAM Manager for audio tasks. Demonstration code. 
    
    1     8/29/01 12:03p Billyjack
    created
    
    2     8/17/01 10:59a Billyjack
    changed AMLoadFile() API
    
    1     8/16/01 12:24p Billyjack
    created

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __AM_H__
#define __AM_H__

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------*/
typedef void (*AMCallback)(char *path);


#define AM_STACK_ENTRIES          16
#define AM_ZEROBUFFER_BYTES      256

#define AMPushBuffered(p,b,s)           __AMPushBuffered(p,b,s,NULL,FALSE)
#define AMPushBufferedAsync(p,b,s,cb)   __AMPushBuffered(p,b,s,cb,TRUE)


void    AMInit              (u32 aramBase, u32 aramBytes);
u32     AMGetZeroBuffer     (void);
u32     AMGetReadStatus     (void);
u32     AMGetFreeSize       (void);
u32     AMGetStackPointer   (void);

void   *AMLoadFile          (char *path, u32 *length);

void    AMPop               (void);

u32     AMPush              (char *path);
u32     AMPushData          (void *buffer, u32 length);

u32   __AMPushBuffered      (char *path, void *buffer, u32 buffer_size, AMCallback callback, BOOL async_flag);

/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif // __AM_H__
