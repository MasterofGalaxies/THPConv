#ident "$Id: iosrestypes.h,v 1.5 2006-08-11 09:29:43 yasumoto_yoshitaka Exp $"
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
#ifndef __IOS_RESTYPES_H__
#define __IOS_RESTYPES_H__


/* Definitions of messages that should be handled by resource managers */
#define IOS_OPEN     1
#define IOS_CLOSE    2
#define IOS_READ     3
#define IOS_WRITE    4
#define IOS_SEEK     5
#define IOS_IOCTL    6
#define IOS_IOCTLV   7

/*
 * Useful for code which wishes to define additional message types
 * that go in a Resource Manager queue.
 */
#define MAX_RM_MESG_NUM 5

typedef u32 IOSUid;
typedef u16 IOSGid;
typedef u32 IOSResourceHandle;

/* Definitions of structs used for different types of requests 
 * sent to the resource manager.
 */
#ifdef  __MWERKS__
#pragma warn_padding off
#endif
typedef struct {
    u8 *path;
    u32 flags;
    IOSUid uid; 
    IOSGid gid;
} IOSResourceOpen;
#ifdef  __MWERKS__
#pragma warn_padding reset
#endif

typedef struct {
    u8 *outPtr;
    u32 outLen;
} IOSResourceRead;

typedef struct {
    u8 *inPtr;
    u32 inLen;
} IOSResourceWrite;

typedef struct {
    s32 offset;
    u32 whence;
} IOSResourceSeek;

typedef struct {
    u32 cmd;
    u8 *inPtr;
    u32 inLen;
    u8 *outPtr;
    u32 outLen;
} IOSResourceIoctl;

typedef struct {
    u8 *base;
    u32 length;
} IOSIoVector;

typedef struct {
    u32 cmd;
    u32 readCount;
    u32 writeCount;
    IOSIoVector *vector;
} IOSResourceIoctlv;


typedef struct {
    /* Notes: changing the size of cmd from u32 may break DI code - CSA */
    u32 cmd;            /* Identifies request as Open, Read, Write, etc */
    s32 status;         /* return status */
    IOSResourceHandle handle; /* Identifies caller to RM. */
    union {               /* Request based on kind of cmd */
        IOSResourceOpen open;
        IOSResourceRead read;
        IOSResourceWrite write;
        IOSResourceSeek seek;
        IOSResourceIoctl ioctl;
        IOSResourceIoctlv ioctlv;
    } args;
} IOSResourceRequest;

/* Resource manager API */
IOSError IOS_RegisterResourceManager(char *path, IOSMessageQueueId mq);

IOSError IOS_ResourceRespond(IOSResourceRequest *response, IOSError status);


#endif /* __IOS_RESTYPES_H__ */
