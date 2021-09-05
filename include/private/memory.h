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
#ifndef __MEMORY_H__
#define __MEMORY_H__

#ifdef __IOP__

#define CHECK_READABLE_BUFFER(ptr, size, dstMask) \
    if ((rv = __iosCheckMemoryRegion((ptr), (size), IOS_READ, (dstMask))) != IOS_ERROR_OK) { \
        goto end; \
    } else

#define CHECK_WRITABLE_BUFFER(ptr, size, dstMask) \
    if ((rv = __iosCheckMemoryRegion((ptr), (size), IOS_WRITE, (dstMask))) != IOS_ERROR_OK) { \
        goto end; \
    } else

#else

#define CHECK_READABLE_BUFFER(ptr, size, dstMask) 
#define CHECK_WRITABLE_BUFFER(ptr, size, dstMask)

#endif

IOSError __iosSetMemAccess(u32 cc, u32 sc, u32 pid, void *ptr, u32 bytes);
IOSError __iosCheckMemoryRegion(const void *ptr, u32 size, u32 dir, u32 dstMask);
void __iosInitSdram(void);
IOSHeapId iosCreateHeap(void *ptr, u32 size);
IOSError iosDestroyHeap(IOSHeapId id);
IOSError iosFree(IOSHeapId id, void *ptr);
void * iosAlloc(IOSHeapId id, u32 size);
void * iosAllocAligned(IOSHeapId id, u32 size, u32 align);
void L1IInvalidate(void *ptr, u32 bytes);
void L1DInvalidate(void *ptr, u32 bytes);
void L1Invalidate(void *ptr, u32 bytes);

#endif /*__MEMORY_H__*/
