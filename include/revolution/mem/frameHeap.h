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
    定数定義
   ======================================================================== */

#define MEM_FRMHEAP_FREE_HEAD (1 <<0)
#define MEM_FRMHEAP_FREE_TAIL (1 <<1)
#define MEM_FRMHEAP_FREE_ALL  (MEM_FRMHEAP_FREE_HEAD | MEM_FRMHEAP_FREE_TAIL)


/* =======================================================================
    型定義
   ======================================================================== */

typedef struct MEMiFrmHeapState MEMiFrmHeapState;

// 状態保存用構造体
struct MEMiFrmHeapState
{
    u32                 tagName;        // タグ名
    void*               headAllocator;  // フレームヒープの先頭位置
    void*               tailAllocator;  // フレームヒープの末尾位置
    MEMiFrmHeapState*   pPrevState;     // 1つ前の状態保存へのポインタ
};

typedef struct MEMiFrmHeapHead MEMiFrmHeapHead;

// フレームヒープのヘッダ情報
struct MEMiFrmHeapHead
{
    void*               headAllocator;  // 先頭メモリ確保ポインタ
    void*               tailAllocator;  // 末尾メモリ確保ポインタ

    MEMiFrmHeapState*   pState;         // 状態保存パラメータ
};


/* =======================================================================
    マクロ関数
   ======================================================================== */


/* =======================================================================
    関数プロトタイプ
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
    インライン関数
   ======================================================================== */

/*---------------------------------------------------------------------------*
  Name:         MEMCreateFrmHeap

  Description:  フレームヒープを作成します。

  Arguments:    startAddress: ヒープ領域の先頭アドレス。
                size:         ヒープ領域のサイズ。

  Returns:      関数が成功した場合、作成されたフレームヒープのハンドルが返ります。
                関数が失敗すると、MEM_INVALID_HEAP_HANDLE が返ります。
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

  Description:  フレームヒープからメモリブロックを確保します。
                メモリブロックのアライメントは4バイト固定です。

  Arguments:    heap:   フレームヒープのハンドル。
                size:   確保するメモリブロックのサイズ(バイト単位)。

  Returns:      メモリブロックの確保が成功した場合、確保したメモリブロックへの
                ポインタが返ります。
                失敗した場合、NULLが返ります。
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

  Description:  フレームヒープ内の割り当て可能な最大サイズを取得します。
                メモリブロックのアライメントは4バイト固定です。

  Arguments:    heap:      フレームヒープのハンドル。

  Returns:      フレームヒープ内の割り当て可能な最大サイズを返します(バイト単位)。
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
