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
    型定義
   ======================================================================== */

typedef struct MEMiUntHeapMBlockHead MEMiUntHeapMBlockHead;

// メモリブロックのヘッダ情報
struct MEMiUntHeapMBlockHead
{
    MEMiUntHeapMBlockHead*  pMBlkHdNext;    // 次ブロック
};


typedef struct MEMiUntMBlockList MEMiUntMBlockList;

// メモリブロックのリスト
struct MEMiUntMBlockList
{
    MEMiUntHeapMBlockHead*  head;           // 先頭に繋がれているメモリブロックへのポインタ
};

typedef struct MEMiUntHeapHead MEMiUntHeapHead;

// ユニットヒープのヘッダ情報
struct MEMiUntHeapHead
{
    MEMiUntMBlockList    mbFreeList;     // フリーリスト
    u32                  mBlkSize;       // メモリブロックサイズ
};



/* ========================================================================
    マクロ関数
   ======================================================================== */


/* ========================================================================
    関数プロトタイプ
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
    インライン関数
   ======================================================================== */
/*---------------------------------------------------------------------------*
  Name:         MEMCreateUnitHeap

  Description:  ユニットヒープを作成します。

  Arguments:    startAddress:  ヒープ領域の先頭アドレス。
                heapSize:      ヒープ領域のサイズ。
                memBlockSize:  メモリブロックのサイズ。

  Returns:      関数が成功した場合、作成されたユニットヒープのハンドルが返ります。
                関数が失敗すると、NNS_FND_INVALID_HEAP_HANDLE が返ります。
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

  Description:  ユニットヒープのメモリブロックサイズを取得します。

  Arguments:    heap:  ユニットヒープのハンドル。

  Returns:      ユニットヒープのメモリブロックサイズを返します。
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

