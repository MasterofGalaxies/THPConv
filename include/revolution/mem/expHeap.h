/*---------------------------------------------------------------------------*
  Project:     MEM library
  File:        expHeap.h
  Programmers: Takano Makoto

  Copyright (C)2005-2007 Nintendo  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/

#ifndef MEM_EXPHEAP_H__
#define MEM_EXPHEAP_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <revolution/mem/heapCommon.h>

/* =======================================================================
    �萔��`
   ======================================================================== */

// �������m�ە���
enum
{
    MEM_EXPHEAP_ALLOC_DIR_FRONT,    // �O�����m��
    MEM_EXPHEAP_ALLOC_DIR_REAR      // ������m��
};

// �������m�ۃ��[�h
enum
{
    /*
        ���̑����l���Z�b�g����Ă���ƁA�m�ۂ��悤�Ƃ��Ă���
        �������u���b�N�̃T�C�Y�ȏ�̑傫�������A
        �ŏ��Ɍ��������󂫗̈悩�烁�����u���b�N���m�ۂ��܂��B
    */
    MEM_EXPHEAP_ALLOC_MODE_FIRST = 0,
    
    /*
        ���̑����l���Z�b�g����Ă���ƁA�m�ۂ��悤�Ƃ��Ă���
        �������u���b�N�̃T�C�Y�Ɉ�ԋ߂��T�C�Y�̋󂫗̈��T���A
        ���̋󂫗̈悩�烁�����u���b�N���m�ۂ��܂��B
    */
    MEM_EXPHEAP_ALLOC_MODE_NEAR = 1
};


/* =======================================================================
    �^��`
   ======================================================================== */

typedef struct MEMiExpHeapMBlockHead MEMiExpHeapMBlockHead;

// �������u���b�N�̃w�b�_���(16B)
struct MEMiExpHeapMBlockHead
{
    u16                      signature;      // �V�O�l�`��
    union                                // ����
    {
        u16                      val;
        struct
        {
            u16                  allocDir  : 1;   // �������m�ە���
            u16                  alignment : 7;   // �A���C�������g
            u16                  groupID   : 8;   // �O���[�vID
        }
        fields;
    }
    attribute;
    
    u32                      blockSize;         // �u���b�N�T�C�Y(�f�[�^�̈�̂�)
    
    MEMiExpHeapMBlockHead*   pMBHeadPrev;       // �O�u���b�N
    MEMiExpHeapMBlockHead*   pMBHeadNext;       // ���u���b�N
};

typedef struct MEMiExpMBlockList MEMiExpMBlockList;

// �������u���b�N�̃��X�g
struct MEMiExpMBlockList
{
    MEMiExpHeapMBlockHead*   head;   // �擪�Ɍq����Ă��郁�����u���b�N�ւ̃|�C���^
    MEMiExpHeapMBlockHead*   tail;   // ����Ɍq����Ă��郁�����u���b�N�ւ̃|�C���^
};

typedef struct MEMiExpHeapHead MEMiExpHeapHead;

// �g���q�[�v�̃w�b�_���
struct MEMiExpHeapHead
{
    MEMiExpMBlockList  mbFreeList;     // �t���[���X�g
    MEMiExpMBlockList  mbUsedList;     // �g�p���X�g
    
    u16                groupID;        // �J�����g�O���[�vID (����8bit�̂�)
    
    union                                // ����
    {
        u16                val;
        struct
        {
            u16            _reserved          : 14;
            u16            useMarginOfAlign   :  1; // ���̑����l���Z�b�g����Ă���ƁA�A���C�����g�̍ۂɔ�������
                                                    //  �������̌��Ԃ��󂫗̈�Ƃ��čė��p���܂��B
            u16            allocMode          :  1; // �������m�ۃ��[�h
        }
        fields;
    }
    feature;
};


// �������u���b�N���ɌĂяo�����R�[���o�b�N�֐��̌^
typedef void        (*MEMHeapVisitor)( void* memBlock, MEMHeapHandle heap, u32 userParam );


/* =======================================================================
    �}�N���֐�
   ======================================================================== */


/* =======================================================================
    �֐��v���g�^�C�v
   ======================================================================== */

#if defined(_DEBUG)

void        MEMiDumpExpHeap( MEMHeapHandle heap );


// #if defined(_DEBUG)
#endif


MEMHeapHandle  MEMCreateExpHeapEx(
                        void*       startAddress,
                        u32         size,
                        u16         optFlag );

void*       MEMDestroyExpHeap( MEMHeapHandle heap );

void*       MEMAllocFromExpHeapEx(
                        MEMHeapHandle heap,
                        u32           size,
                        int           alignment );

u32         MEMResizeForMBlockExpHeap(
                        MEMHeapHandle     heap,
                        void*             memBlock,
                        u32               size );

void        MEMFreeToExpHeap( MEMHeapHandle heap, void* memBlock );

u32         MEMGetTotalFreeSizeForExpHeap( MEMHeapHandle heap );

u32         MEMGetAllocatableSizeForExpHeapEx( MEMHeapHandle heap, int alignment );

BOOL        MEMiIsEmptyExpHeap( MEMHeapHandle heap );

u16         MEMSetAllocModeForExpHeap( MEMHeapHandle heap, u16 mode );
u16         MEMGetAllocModeForExpHeap( MEMHeapHandle heap );

BOOL        MEMUseMarginOfAlignmentForExpHeap( MEMHeapHandle heap, BOOL reuse );

u16         MEMSetGroupIDForExpHeap( MEMHeapHandle heap, u16 groupID );
u16         MEMGetGroupIDForExpHeap( MEMHeapHandle heap );

void        MEMVisitAllocatedForExpHeap(
                        MEMHeapHandle    heap,
                        MEMHeapVisitor   visitor,
                        u32              userParam );


u32         MEMGetSizeForMBlockExpHeap( const void* memBlock );

u16         MEMGetGroupIDForMBlockExpHeap( const void* memBlock );

u16         MEMGetAllocDirForMBlockExpHeap( const void* memBlock );

u32         MEMAdjustExpHeap( MEMHeapHandle heap );


/* =======================================================================
    �C�����C���֐�
   ======================================================================== */

/*---------------------------------------------------------------------------*
  Name:         MEMCreateExpHeap

  Description:  �g���q�[�v���쐬���܂��B

  Arguments:    startAddress: �q�[�v�̈�̐擪�A�h���X�B
                size:         �q�[�v�̈�̃T�C�Y�B

  Returns:      �֐������������ꍇ�A�쐬���ꂽ�g���q�[�v�̃n���h�����Ԃ�܂��B
                �֐������s����ƁAHEAP_INVALID_HANDLE ���Ԃ�܂��B
 *---------------------------------------------------------------------------*/
static inline MEMHeapHandle
MEMCreateExpHeap(
    void*   startAddress,
    u32     size
)
{
    return MEMCreateExpHeapEx( startAddress, size, 0 );
}


/*---------------------------------------------------------------------------*
  Name:         MEMAllocFromExpHeap

  Description:  �g���q�[�v���烁�����u���b�N���m�ۂ��܂��B
                �������u���b�N�̃A���C�����g��4�o�C�g�Œ�ł��B

  Arguments:    heap:   �g���q�[�v�̃n���h���B
                size:   �m�ۂ��郁�����u���b�N�̃T�C�Y(�o�C�g�P��)�B

  Returns:      �������u���b�N�̊m�ۂ����������ꍇ�A�m�ۂ����������u���b�N�ւ�
                �|�C���^���Ԃ�܂��B
                ���s�����ꍇ�ANULL���Ԃ�܂��B
 *---------------------------------------------------------------------------*/
static inline void*
MEMAllocFromExpHeap(
    MEMHeapHandle    heap,
    u32              size
)
{
    return MEMAllocFromExpHeapEx( heap, size, MEM_HEAP_DEFAULT_ALIGNMENT );
}

/*---------------------------------------------------------------------------*
  Name:         MEMGetAllocatableSizeForExpHeap

  Description:  �g���q�[�v���̊��蓖�ĉ\�ȍő�T�C�Y���擾���܂��B
                �������u���b�N�̃A���C�����g��4�o�C�g�Œ�ł��B

  Arguments:    heap:     �g���q�[�v�̃n���h���B

  Returns:      �g���q�[�v���̊��蓖�ĉ\�ȍő�T�C�Y��Ԃ��܂�(�o�C�g�P��)�B
 *---------------------------------------------------------------------------*/
static inline u32
MEMGetAllocatableSizeForExpHeap( MEMHeapHandle heap )
{
    return MEMGetAllocatableSizeForExpHeapEx( heap, MEM_HEAP_DEFAULT_ALIGNMENT );
}



#if ! defined(_DEBUG)

#define     MEMCheckExpHeap( heap, optFlag )                      (TRUE)
#define     MEMCheckForMBlockExpHeap( memBlock, heap, optFlag )   (TRUE)

// #if ! defined(_DEBUG)
#else

BOOL        MEMCheckExpHeap( MEMHeapHandle heap, u32 optFlag );

BOOL        MEMCheckForMBlockExpHeap(
                    const void*       memBlock,
                    MEMHeapHandle     heap,
                    u32               optFlag );

// #if defined(_DEBUG)
#endif



#ifdef __cplusplus
} /* extern "C" */
#endif

/* MEM_EXPHEAP_H__ */
#endif
