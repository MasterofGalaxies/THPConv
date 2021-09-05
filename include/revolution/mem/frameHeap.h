/*---------------------------------------------------------------------------*
  Project:     MEM library
  File:        frameHeap.h
  Programmers: Takano Makoto

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/

#ifndef MEM_FRAMEHEAP_H__
#define MEM_FRAMEHEAP_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <revolution/types.h>
#include <revolution/mem/heapCommon.h>

/* =======================================================================
    �萔��`
   ======================================================================== */

#define MEM_FRMHEAP_FREE_HEAD (1 <<0)
#define MEM_FRMHEAP_FREE_TAIL (1 <<1)
#define MEM_FRMHEAP_FREE_ALL  (MEM_FRMHEAP_FREE_HEAD | MEM_FRMHEAP_FREE_TAIL)


/* =======================================================================
    �^��`
   ======================================================================== */

typedef struct MEMiFrmHeapState MEMiFrmHeapState;

// ��ԕۑ��p�\����
struct MEMiFrmHeapState
{
    u32                 tagName;        // �^�O��
    void*               headAllocator;  // �t���[���q�[�v�̐擪�ʒu
    void*               tailAllocator;  // �t���[���q�[�v�̖����ʒu
    MEMiFrmHeapState*   pPrevState;     // 1�O�̏�ԕۑ��ւ̃|�C���^
};

typedef struct MEMiFrmHeapHead MEMiFrmHeapHead;

// �t���[���q�[�v�̃w�b�_���
struct MEMiFrmHeapHead
{
    void*               headAllocator;  // �擪�������m�ۃ|�C���^
    void*               tailAllocator;  // �����������m�ۃ|�C���^

    MEMiFrmHeapState*   pState;         // ��ԕۑ��p�����[�^
};


/* =======================================================================
    �}�N���֐�
   ======================================================================== */


/* =======================================================================
    �֐��v���g�^�C�v
   ======================================================================== */

void*       MEMiGetFreeStartForFrmHeap( MEMHeapHandle heap );

void*       MEMiGetFreeEndForFrmHeap  ( MEMHeapHandle heap );

#if defined(_DEBUG)

void        MEMiDumpFrmHeap( MEMHeapHandle heap );

// #if defined(_DEBUG)
#endif

MEMHeapHandle  MEMCreateFrmHeapEx(
                                void*   startAddress,
                                u32     size,
                                u16     optFlag );

void*            MEMDestroyFrmHeap( MEMHeapHandle heap );

void*            MEMAllocFromFrmHeapEx(
                                MEMHeapHandle   heap,
                                u32             size,
                                int             alignment );

void             MEMFreeToFrmHeap( MEMHeapHandle heap, int mode );

u32              MEMGetAllocatableSizeForFrmHeapEx( MEMHeapHandle heap, int alignment );

BOOL             MEMRecordStateForFrmHeap( MEMHeapHandle heap, u32 tagName );

BOOL             MEMFreeByStateToFrmHeap( MEMHeapHandle heap, u32 tagName );

u32              MEMAdjustFrmHeap( MEMHeapHandle heap );

u32              MEMResizeForMBlockFrmHeap(
                                MEMHeapHandle    heap,
                                void*            memBlock,
                                u32              newSize );


/* =======================================================================
    �C�����C���֐�
   ======================================================================== */

/*---------------------------------------------------------------------------*
  Name:         MEMCreateFrmHeap

  Description:  �t���[���q�[�v���쐬���܂��B

  Arguments:    startAddress: �q�[�v�̈�̐擪�A�h���X�B
                size:         �q�[�v�̈�̃T�C�Y�B

  Returns:      �֐������������ꍇ�A�쐬���ꂽ�t���[���q�[�v�̃n���h�����Ԃ�܂��B
                �֐������s����ƁAMEM_INVALID_HEAP_HANDLE ���Ԃ�܂��B
 *---------------------------------------------------------------------------*/
static inline MEMHeapHandle
MEMCreateFrmHeap(
    void*   startAddress,
    u32     size
)
{
    return MEMCreateFrmHeapEx( startAddress, size, 0 );
}


/*---------------------------------------------------------------------------*
  Name:         MEMAllocFromFrmHeap

  Description:  �t���[���q�[�v���烁�����u���b�N���m�ۂ��܂��B
                �������u���b�N�̃A���C�����g��4�o�C�g�Œ�ł��B

  Arguments:    heap:   �t���[���q�[�v�̃n���h���B
                size:   �m�ۂ��郁�����u���b�N�̃T�C�Y(�o�C�g�P��)�B

  Returns:      �������u���b�N�̊m�ۂ����������ꍇ�A�m�ۂ����������u���b�N�ւ�
                �|�C���^���Ԃ�܂��B
                ���s�����ꍇ�ANULL���Ԃ�܂��B
 *---------------------------------------------------------------------------*/
static inline void*
MEMAllocFromFrmHeap(
    MEMHeapHandle   heap,
    u32             size
)
{
    return MEMAllocFromFrmHeapEx( heap, size, MEM_HEAP_DEFAULT_ALIGNMENT );
}


/*---------------------------------------------------------------------------*
  Name:         MEMGetAllocatableSizeForFrmHeap

  Description:  �t���[���q�[�v���̊��蓖�ĉ\�ȍő�T�C�Y���擾���܂��B
                �������u���b�N�̃A���C�����g��4�o�C�g�Œ�ł��B

  Arguments:    heap:      �t���[���q�[�v�̃n���h���B

  Returns:      �t���[���q�[�v���̊��蓖�ĉ\�ȍő�T�C�Y��Ԃ��܂�(�o�C�g�P��)�B
 *---------------------------------------------------------------------------*/
static inline u32
MEMGetAllocatableSizeForFrmHeap( MEMHeapHandle heap )
{
    return MEMGetAllocatableSizeForFrmHeapEx( heap, MEM_HEAP_DEFAULT_ALIGNMENT );
}


#ifdef __cplusplus
} /* extern "C" */
#endif

/* MEM_FRAMEHEAP_H__ */
#endif
