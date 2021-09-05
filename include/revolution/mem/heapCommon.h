/*---------------------------------------------------------------------------*
  Project:     MEM library
  File:        heapCommon.h
  Programmers: Takano Makoto

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/
#ifndef MEM_HEAPCOMMON_H__
#define MEM_HEAPCOMMON_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <revolution/types.h>
#include <revolution/os.h>
#include <revolution/mem/list.h>


/* ========================================================================
    �}�N���萔
   ======================================================================== */

// �����ȃq�[�v�n���h��
#define MEM_HEAP_INVALID_HANDLE      NULL

// �q�[�v���烁���������蓖�Ă�Ƃ��̃f�t�H���g�̃A���C�����g�T�C�Y
#define MEM_HEAP_DEFAULT_ALIGNMENT   4


/* ------------------------------------------------------------------------
    �t�B���֌W
   ------------------------------------------------------------------------ */

// �������m�ێ��Ƀ�������0�ŃN���A
#define MEM_HEAP_OPT_0_CLEAR         (1 << 0)

// �q�[�v�쐬���E�������m�ہE������Ƀ������[�U
#define MEM_HEAP_OPT_DEBUG_FILL      (1 << 1)

// �r������̗L��
#define MEM_HEAP_OPT_THREAD_SAFE     (1 << 2)


/* ------------------------------------------------------------------------
    �q�[�v�`�F�b�N�֌W
   ------------------------------------------------------------------------ */
//  ���̃r�b�g�������Ă���ƃG���[�o��
#define MEM_HEAP_ERROR_PRINT         (1 << 0)



// �g���q�[�v�̃V�O�l�`��
#define MEMi_EXPHEAP_SIGNATURE       ('EXPH')
// �t���[���q�[�v�̃V�O�l�`��
#define MEMi_FRMHEAP_SIGNATURE       ('FRMH')
// ���j�b�g�q�[�v�̃V�O�l�`��
#define MEMi_UNTHEAP_SIGNATURE       ('UNTH')

/* ========================================================================
    enum�萔
   ======================================================================== */

typedef enum
{
    MEM_HEAP_TYPE_EXP,      // �g���q�[�v
    MEM_HEAP_TYPE_FRM,      // �t���[���q�[�v
    MEM_HEAP_TYPE_UNIT,     // ���j�b�g�q�[�v
    MEM_HEAP_TYPE_UNKNOWN   // ���m�̃q�[�v�n���h��
}
MEMHeapType;

enum 
{
    MEM_HEAP_FILL_NOUSE,    // �f�o�b�O�t�B�����g�p��
    MEM_HEAP_FILL_ALLOC,    // �f�o�b�O�t�B���m�ێ�
    MEM_HEAP_FILL_FREE,     // �f�o�b�O�t�B�������
    
    MEM_HEAP_FILL_MAX
};



/* =======================================================================
    �^��`
   ======================================================================== */

typedef struct MEMiHeapHead MEMiHeapHead;

// �q�[�v���ʃw�b�_
struct MEMiHeapHead
{
    u32       signature;
    
    MEMLink   link;
    MEMList   childList;
    
    void*     heapStart;      // �q�[�v�擪�A�h���X
    void*     heapEnd;        // �q�[�v����(+1)�A�h���X
    OSMutex   mutex;          // �X���b�h�Ԃł̔r���p
    
    union                     // ����
    {
        u32       val;
        struct
        {
            u32   _reserved : 24;
            u32   optFlag   :  8; // �I�v�V�����t���O
        }
        fields;
    }
    attribute;
};


typedef MEMiHeapHead* MEMHeapHandle;   // �q�[�v�̃n���h����\���^


/* =======================================================================
    �֐��v���g�^�C�v
   ======================================================================== */

MEMHeapHandle    MEMFindContainHeap( const void* memBlock );

MEMHeapHandle    MEMFindParentHeap( MEMHeapHandle heap );


/* ========================================================================
    �C�����C���֐�
   ======================================================================== */

/*---------------------------------------------------------------------------*
  Name:         MEMGetHeapStartAddress

  Description:  �q�[�v�����p���郁�����̈�̊J�n�A�h���X���擾���܂��B

  Arguments:    heap:  �q�[�v�n���h���B

  Returns:      �q�[�v�����p���郁�����̈�̊J�n�A�h���X��Ԃ��܂��B
 *---------------------------------------------------------------------------*/
static inline void*
MEMGetHeapStartAddress( MEMHeapHandle heap )
{
    return (void*)heap;
}

/*---------------------------------------------------------------------------*
  Name:         MEMGetHeapEndAddress

  Description:  �q�[�v�����p���郁�����̈�̏I���A�h���X +1 ���擾���܂��B

  Arguments:    heap:  �q�[�v�n���h���B

  Returns:      �q�[�v�����p���郁�����̈�̏I���A�h���X +1 ��Ԃ��܂��B
 *---------------------------------------------------------------------------*/
static inline void*
MEMGetHeapEndAddress( MEMHeapHandle heap )
{
    return heap->heapEnd;
}

/*---------------------------------------------------------------------------*
  Name:         MEMGetHeapTotalUsableSize

  Description:  �q�[�v�Ɋ��蓖�Ă��Ă��郁�����T�C�Y���擾���܂��B
                �w�b�_�͊܂݂܂���B

  Arguments:    heap:  �q�[�v�n���h���B

  Returns:      �q�[�v�Ɋ��蓖�Ă��Ă��郁�����T�C�Y��Ԃ��܂��B�w�b�_�͊܂݂܂���B
 *---------------------------------------------------------------------------*/
static inline s32
MEMGetHeapTotalUsableSize( MEMHeapHandle heap )
{
    return ((s32)(heap->heapEnd) - (s32)(heap->heapStart));
}

/*---------------------------------------------------------------------------*
  Name:         MemGetHeapTotalSize

  Description:  �q�[�v�Ɋ��蓖�Ă��Ă��郁�����T�C�Y(�w�b�_�������܂ޑS�̂̃������T�C�Y)
                ���擾���܂��B

  Arguments:    heap    �q�[�v�n���h���B

  Returns:      �q�[�v�Ɋ��蓖�Ă��Ă��郁�����T�C�Y(�w�b�_�������܂ޑS�̂̃������T�C�Y)
                ��Ԃ��܂��B
 *---------------------------------------------------------------------------*/
static inline s32
MEMGetHeapTotalSize( MEMHeapHandle heap )
{
    return ((s32)(heap->heapEnd) - (s32)(heap));
}


/*---------------------------------------------------------------------------*
  Name:         MEMGetHeapType

  Description:  �q�[�v�n���h�����ǂ̎�ނ̃q�[�v�ł��邩���擾���܂��B

  Arguments:    heap:  �q�[�v�n���h���B

  Returns:      �q�[�v�n���h������q�[�v�̎�ʂ��擾���܂��B
 *---------------------------------------------------------------------------*/
static inline MEMHeapType
MEMGetHeapType( MEMHeapHandle heap )
{
    switch ( heap->signature )
    {
    case MEMi_EXPHEAP_SIGNATURE:    return MEM_HEAP_TYPE_EXP;
    case MEMi_FRMHEAP_SIGNATURE:    return MEM_HEAP_TYPE_FRM;
    case MEMi_UNTHEAP_SIGNATURE:    return MEM_HEAP_TYPE_UNIT;
    default:                        return MEM_HEAP_TYPE_UNKNOWN;
    }
}


/*---------------------------------------------------------------------------*
  Name:         MEMIsExpHeap

  Description:  �q�[�v�n���h�����g���q�[�v�̂��̂ł��邩�ǂ����𔻒肵�܂��B

  Arguments:    heap    �q�[�v�n���h���B

  Returns:      �g���q�[�v�ł���� �^ ��Ԃ��܂��B
                ����ȊO�̏ꍇ�ɂ͋U��Ԃ��܂��B
 *---------------------------------------------------------------------------*/
static inline BOOL
MEMIsExpHeap( MEMHeapHandle heap )
{
    return ( heap->signature == MEMi_EXPHEAP_SIGNATURE );
}


/*---------------------------------------------------------------------------*
  Name:         MEMIsFrmHeap

  Description:  �q�[�v�n���h�����t���[���q�[�v�̂��̂ł��邩�ǂ����𔻒肵�܂��B

  Arguments:    heap    �q�[�v�n���h���B

  Returns:      �t���[���q�[�v�ł���� �^ ��Ԃ��܂��B
                ����ȊO�̏ꍇ�ɂ͋U��Ԃ��܂��B
 *---------------------------------------------------------------------------*/
static inline BOOL
MEMIsFrmHeap( MEMHeapHandle heap )
{
    return ( heap->signature == MEMi_FRMHEAP_SIGNATURE );
}


/*---------------------------------------------------------------------------*
  Name:         MEMIsUnitHeap

  Description:  �q�[�v�n���h�������j�b�g�q�[�v�̂��̂ł��邩�ǂ����𔻒肵�܂��B

  Arguments:    heap    �q�[�v�n���h���B

  Returns:      ���j�b�g�q�[�v�ł���� �^ ��Ԃ��܂��B
                ����ȊO�̏ꍇ�ɂ͋U��Ԃ��܂��B
 *---------------------------------------------------------------------------*/
static inline BOOL
MEMIsUnitHeap( MEMHeapHandle heap )
{
    return ( heap->signature == MEMi_UNTHEAP_SIGNATURE );
}



/* =======================================================================
    �f�o�b�O�p�֐�
   ======================================================================== */
#if ! defined(_DEBUG)

#define   MEMDumpHeap( heap )                  ((void)0)
#define   MEMSetFillValForHeap( type, val )    (0)
#define   MEMGetFillValForHeap( type )         (0)

#else

void      MEMDumpHeap( MEMHeapHandle heap );

u32       MEMSetFillValForHeap( int type, u32 val );

u32       MEMGetFillValForHeap( int type );

#endif


#ifdef __cplusplus
} /* extern "C" */
#endif

/* MEM_HEAPCOMMON_H__ */
#endif

