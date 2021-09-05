#ident "$Id: iosresclt.h,v 1.8 2006-05-12 00:22:24 orest Exp $"
/*
 *               Copyright (C) 2005, BroadOn Communications Corp.
 *
 *  These coded instructions, statements, and computer programs contain
 *  unpublished  proprietary information of BroadOn Communications Corp.,
 *  and  are protected by Federal copyright law. They may not be disclosed
 *  to  third  parties or copied or duplicated in any form, in whole or in
 *  part, without the prior written consent of BroadOn Communications Corp.
 *
 */
#ifndef __IOS_RESCLT_H__
#define __IOS_RESCLT_H__

#include <private/iosrestypes.h>

/* Non-blocking API 
 * XXX - There will be minor naming and other changes to the following.
 *       No real change in functionality.
 */


typedef IOSError (*IOSIpcCb) (IOSError ret, void *ctxt);


IOSError
IPCCltInit(void);

IOSError 
IOS_OpenAsync(
        const char *path, 
        u32         flags, 
        IOSIpcCb    cb,
        void       *ctxt);
IOSFd 
IOS_Open(
        const char *path, 
        u32         flags);

IOSError 
IOS_CloseAsync(
        IOSFd     fd, 
        IOSIpcCb  cb,
        void     *ctxt);
IOSError 
IOS_Close(
        IOSFd     fd);

/*
    buf needs to be aligned(32) and multiple of 32 bytes 
*/
IOSError 
IOS_ReadAsync(
        IOSFd     fd, 
        void     *buf, 
        u32       count, 
        IOSIpcCb  cb,
        void     *ctxt);
IOSError
IOS_Read(
        IOSFd     fd,
        void     *buf,
        u32       count);

/*
    buf needs to be aligned(32) and multiple of 32 bytes 
*/
IOSError 
IOS_WriteAsync(
        IOSFd     fd, 
        void     *buf, 
        u32       count, 
        IOSIpcCb  cb,
        void     *ctxt);
IOSError
IOS_Write(
        IOSFd     fd,
        void     *buf,
        u32       count);

IOSError 
IOS_SeekAsync(
        IOSFd     fd, 
        s32       offset, 
        u32       whence, 
        IOSIpcCb  cb,
        void     *ctxt);
IOSError
IOS_Seek(
        IOSFd     fd,
        s32       offset,
        u32       whence);

/*
    input, output need to be aligned(32) and multiple of 32 bytes 
*/
IOSError 
IOS_IoctlAsync(
        IOSFd     fd, 
        s32       cmd,
        void     *input, 
        u32       inputLen,
        void     *output, 
        u32       outputLen,
        IOSIpcCb  cb,
        void     *ctxt);
IOSError
IOS_Ioctl(
        IOSFd     fd,
        s32       cmd,
        void     *input,
        u32       inputLen,
        void     *output,
        u32       outputLen);

/*
    vector and vector's entries need to be aligned(32) and multiple of 32 bytes 
*/
IOSError 
IOS_IoctlvAsync(
        IOSFd        fd, 
        s32          cmd,
        u32          readCount,
        u32          writeCount,
        IOSIoVector *vect,
        IOSIpcCb     cb,
        void        *ctxt);
IOSError
IOS_Ioctlv(
        IOSFd        fd,
        s32          cmd,
        u32          readCount,
        u32          writeCount,
        IOSIoVector *vect);
IOSError
IOS_IoctlvReboot(
        IOSFd        fd,
        s32          cmd,
        u32          readCount,
        u32          writeCount,
        IOSIoVector *vect);

#endif /* __IOS_RESCLT_H__ */
