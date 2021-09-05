/*---------------------------------------------------------------------------*
  Project:     MEM library
  File:        unitHeap.h
  Programmers: Takano Makoto

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/

#ifndef MEM_UNITHEAP_H__
#define MEM_UNITHEAP_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <revolution/types.h>
#include <revolution/mem/heapCommon.h>

/* ========================================================================
    �^��`
   ======================================================================== */

typedef struct MEMiUntHeapMBlockHead MEMiUntHeapMBlockHead;

// �������u���b�N�̃w�b�_���
struct MEMiUntHeapMBlockHead
{
    MEMiUntHeapMBlockHead*  pMBlkHdNext;    // ���u���b�N
};


typedef struct MEMiUntMBlockList MEMiUntMBlockList;

// �������u���b�N�̃��X�g
struct MEMiUntMBlockList
{
    MEMiUntHeapMBlockHead*  head;           // �擪�Ɍq����Ă��郁�����u���b�N�ւ̃|�C���^
};

typedef struct MEMiUntHeapHead MEMiUntHeapHead;

// ���j�b�g�q�[�v�̃w�b�_���
struct MEMiUntHeapHead
{
    MEMiUntMBlockList    mbFreeList;     // �t���[���X�g
    u32                  mBlkSize;       // �������u���b�N�T�C�Y
};



/* ========================================================================
    �}�N���֐�
   ======================================================================== */


/* ========================================================================
    �֐��v���g�^�C�v
   ======================================================================== */

#if defined(_DEBUG)

void        MEMiDumpUnitHeap( MEMHeapHandle heap );

// #if defined(_DEBUG)
#endif

MEMHeapHandle  MEMCreateUnitHeapEx(
                        void*           startAddress,
                        u32             heapSize,
                        u32             memBlockSize,
                        int             alignment,
                        u16             optFlag );

void*       MEMDestroyUnitHeap  ( MEMHeapHandle heap );

void*       MEMAllocFromUnitHeap( MEMHeapHandle heap );

void        MEMFreeToUnitHeap(
                        MEMHeapHandle  heap,
                        void*          memBlock );

u32         MEMCountFreeBlockForUnitHeap( MEMHeapHandle heap );

u32         MEMCalcHeapSizeForUnitHeap(
                        u32             memBlockSize,
                        u32             memBlockNum,
                        int             alignment );

/* =======================================================================
    �C�����C���֐�
   ======================================================================== */
/*---------------------------------------------------------------------------*
  Name:         MEMCreateUnitHeap

  Description:  ���j�b�g�q�[�v���쐬���܂��B

  Arguments:    startAddress:  �q�[�v�̈�̐擪�A�h���X�B
                heapSize:      �q�[�v�̈�̃T�C�Y�B
                memBlockSize:  �������u���b�N�̃T�C�Y�B

  Returns:      �֐������������ꍇ�A�쐬���ꂽ���j�b�g�q�[�v�̃n���h�����Ԃ�܂��B
                �֐������s����ƁANNS_FND_INVALID_HEAP_HANDLE ���Ԃ�܂��B
 *---------------------------------------------------------------------------*/
static inline MEMHeapHandle
MEMCreateUnitHeap(
    void*   startAddress,
    u32     heapSize,
    u32     memBlockSize
)
{
    return MEMCreateUnitHeapEx( startAddress, heapSize, memBlockSize, MEM_HEAP_DEFAULT_ALIGNMENT, 0 );
}


/*---------------------------------------------------------------------------*
  Name:         MEMGetMemBlockSizeForUnitHeap

  Description:  ���j�b�g�q�[�v�̃������u���b�N�T�C�Y���擾���܂��B

  Arguments:    heap:  ���j�b�g�q�[�v�̃n���h���B

  Returns:      ���j�b�g�q�[�v�̃������u���b�N�T�C�Y��Ԃ��܂��B
 *---------------------------------------------------------------------------*/
static inline u32
MEMGetMemBlockSizeForUnitHeap( MEMHeapHandle heap )
{
    return ( ( (const MEMiUntHeapHead*)( (const u8*)heap + sizeof(MEMiHeapHead) ) )->mBlkSize );
}


#ifdef __cplusplus
} /* extern "C" */
#endif

/* MEM_UNITHEAP_H__ */
#endif

