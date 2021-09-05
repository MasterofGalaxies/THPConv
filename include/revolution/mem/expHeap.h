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
    定数定義
   ======================================================================== */

// メモリ確保方向
enum
{
    MEM_EXPHEAP_ALLOC_DIR_FRONT,    // 前方より確保
    MEM_EXPHEAP_ALLOC_DIR_REAR      // 後方より確保
};

// メモリ確保モード
enum
{
    /*
        この属性値がセットされていると、確保しようとしている
        メモリブロックのサイズ以上の大きさを持つ、
        最初に見つかった空き領域からメモリブロックを確保します。
    */
    MEM_EXPHEAP_ALLOC_MODE_FIRST = 0,
    
    /*
        この属性値がセットされていると、確保しようとしている
        メモリブロックのサイズに一番近いサイズの空き領域を探し、
        その空き領域からメモリブロックを確保します。
    */
    MEM_EXPHEAP_ALLOC_MODE_NEAR = 1
};


/* =======================================================================
    型定義
   ======================================================================== */

typedef struct MEMiExpHeapMBlockHead MEMiExpHeapMBlockHead;

// メモリブロックのヘッダ情報(16B)
struct MEMiExpHeapMBlockHead
{
    u16                      signature;      // シグネチャ
    union                                // 属性
    {
        u16                      val;
        struct
        {
            u16                  allocDir  : 1;   // メモリ確保方向
            u16                  alignment : 7;   // アラインメント
            u16                  groupID   : 8;   // グループID
        }
        fields;
    }
    attribute;
    
    u32                      blockSize;         // ブロックサイズ(データ領域のみ)
    
    MEMiExpHeapMBlockHead*   pMBHeadPrev;       // 前ブロック
    MEMiExpHeapMBlockHead*   pMBHeadNext;       // 次ブロック
};

typedef struct MEMiExpMBlockList MEMiExpMBlockList;

// メモリブロックのリスト
struct MEMiExpMBlockList
{
    MEMiExpHeapMBlockHead*   head;   // 先頭に繋がれているメモリブロックへのポインタ
    MEMiExpHeapMBlockHead*   tail;   // 後尾に繋がれているメモリブロックへのポインタ
};

typedef struct MEMiExpHeapHead MEMiExpHeapHead;

// 拡張ヒープのヘッダ情報
struct MEMiExpHeapHead
{
    MEMiExpMBlockList  mbFreeList;     // フリーリスト
    MEMiExpMBlockList  mbUsedList;     // 使用リスト
    
    u16                groupID;        // カレントグループID (下位8bitのみ)
    
    union                                // 属性
    {
        u16                val;
        struct
        {
            u16            _reserved          : 14;
            u16            useMarginOfAlign   :  1; // この属性値がセットされていると、アライメントの際に発生する
                                                    //  メモリの隙間を空き領域として再利用します。
            u16            allocMode          :  1; // メモリ確保モード
        }
        fields;
    }
    feature;
};


// メモリブロック毎に呼び出されるコールバック関数の型
typedef void        (*MEMHeapVisitor)( void* memBlock, MEMHeapHandle heap, u32 userParam );


/* =======================================================================
    マクロ関数
   ======================================================================== */


/* =======================================================================
    関数プロトタイプ
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
    インライン関数
   ======================================================================== */

/*---------------------------------------------------------------------------*
  Name:         MEMCreateExpHeap

  Description:  拡張ヒープを作成します。

  Arguments:    startAddress: ヒープ領域の先頭アドレス。
                size:         ヒープ領域のサイズ。

  Returns:      関数が成功した場合、作成された拡張ヒープのハンドルが返ります。
                関数が失敗すると、HEAP_INVALID_HANDLE が返ります。
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

  Description:  拡張ヒープからメモリブロックを確保します。
                メモリブロックのアライメントは4バイト固定です。

  Arguments:    heap:   拡張ヒープのハンドル。
                size:   確保するメモリブロックのサイズ(バイト単位)。

  Returns:      メモリブロックの確保が成功した場合、確保したメモリブロックへの
                ポインタが返ります。
                失敗した場合、NULLが返ります。
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

  Description:  拡張ヒープ内の割り当て可能な最大サイズを取得します。
                メモリブロックのアライメントは4バイト固定です。

  Arguments:    heap:     拡張ヒープのハンドル。

  Returns:      拡張ヒープ内の割り当て可能な最大サイズを返します(バイト単位)。
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
