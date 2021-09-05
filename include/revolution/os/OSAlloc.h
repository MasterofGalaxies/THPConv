/*---------------------------------------------------------------------------*
  Project: OS - Memory Manager
  File:    OSAlloc.h

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
  dolphin�V�[�X�c���[����ڐA

    
    7     11/01/99 6:16p Tian
    Added OSVisitAllocated to iterate over all allocated memory
    
    6     5/25/99 9:55p Shiki
    Modified OSCheckHeap()to return # of available bytes in free.

    5     5/23/99 6:59p Shiki
    Revised declaration of OSSetCurrentHeap() and OSAllocFixed().
    Added declaration of OSCheckHeap().

    4     5/21/99 7:56p Shiki
    Revised.

    3     5/11/99 4:43p Shiki
    Refreshed include tree.

    1     4/30/99 12:49p Tianli01

    3     4/22/99 6:55p Tianli01
    Removed stdlib.h

    2     3/26/99 2:07p Tianli01
    Removed OSEvent reliance.

    1     3/04/99 2:22p Tianli01
    Initial checkin to new tree

    2     2/04/99 6:02p Tianli01
    Minor indentation changes

    1     12/22/98 10:30a Tianli01
    Initial checkin - Memory manager header files

  Change History:
    12/10/1998      Tian Lim    Created

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSALLOC_H__
#define __OSALLOC_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int  OSHeapHandle;
typedef void (*OSAllocVisitor)(
                void*           obj,
                u32             size);

void*        OSInitAlloc(
                void*           arenaStart,
                void*           arenaEnd,
                int             maxHeaps);

OSHeapHandle OSCreateHeap(
                void*           start,
                void*           end);
void         OSDestroyHeap(
                OSHeapHandle    heap);
void         OSAddToHeap(
                OSHeapHandle    heap,
                void*           start,
                void*           end);

OSHeapHandle OSSetCurrentHeap(
                OSHeapHandle    heap);

void*        OSAllocFromHeap(
                OSHeapHandle    heap,
                u32             size);
void*        OSAllocFixed(
                void**          rstart,
                void**          rend);
void         OSFreeToHeap(
                OSHeapHandle    heap,
                void*           ptr);

long         OSCheckHeap(
                OSHeapHandle    heap);
void         OSDumpHeap(
                OSHeapHandle    heap);
u32          OSReferentSize(
                void*           ptr);

void         OSVisitAllocated(
                OSAllocVisitor visitor);
    

extern volatile OSHeapHandle    __OSCurrHeap;

/*---------------------------------------------------------------------------*
  Name:         OSAlloc

  Description:  Allocates /size/ bytes from current heap

  Arguments:    size        size of object to be allocated.

  Returns:      a null pointer or a pointer to the allocated space aligned
                with 32 bytes boundaries
 *---------------------------------------------------------------------------*/
#define OSAlloc(size)   OSAllocFromHeap(__OSCurrHeap, (size))

/*---------------------------------------------------------------------------*
  Name:         OSFree

  Description:  Deallocates /ptr/ to current heap.

  Arguments:    ptr         non-NULL pointer to object previously allocated
                            by OSAlloc() or OSAllocFromHeap().

  Returns:      None.
 *---------------------------------------------------------------------------*/
#define OSFree(ptr)     OSFreeToHeap(__OSCurrHeap, (ptr))

#ifdef __cplusplus
}
#endif

#endif  // __OSALLOC_H__
