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
    マクロ定数
   ======================================================================== */

// 無効なヒープハンドル
#define MEM_HEAP_INVALID_HANDLE      NULL

// ヒープからメモリを割り当てるときのデフォルトのアライメントサイズ
#define MEM_HEAP_DEFAULT_ALIGNMENT   4


/* ------------------------------------------------------------------------
    フィル関係
   ------------------------------------------------------------------------ */

// メモリ確保時にメモリを0でクリア
#define MEM_HEAP_OPT_0_CLEAR         (1 << 0)

// ヒープ作成時・メモリ確保・解放時にメモリ充填
#define MEM_HEAP_OPT_DEBUG_FILL      (1 << 1)

// 排他制御の有無
#define MEM_HEAP_OPT_THREAD_SAFE     (1 << 2)


/* ------------------------------------------------------------------------
    ヒープチェック関係
   ------------------------------------------------------------------------ */
//  このビットが立っているとエラー出力
#define MEM_HEAP_ERROR_PRINT         (1 << 0)



// 拡張ヒープのシグネチャ
#define MEMi_EXPHEAP_SIGNATURE       ('EXPH')
// フレームヒープのシグネチャ
#define MEMi_FRMHEAP_SIGNATURE       ('FRMH')
// ユニットヒープのシグネチャ
#define MEMi_UNTHEAP_SIGNATURE       ('UNTH')

/* ========================================================================
    enum定数
   ======================================================================== */

typedef enum
{
    MEM_HEAP_TYPE_EXP,      // 拡張ヒープ
    MEM_HEAP_TYPE_FRM,      // フレームヒープ
    MEM_HEAP_TYPE_UNIT,     // ユニットヒープ
    MEM_HEAP_TYPE_UNKNOWN   // 未知のヒープハンドル
}
MEMHeapType;

enum 
{
    MEM_HEAP_FILL_NOUSE,    // デバッグフィル未使用時
    MEM_HEAP_FILL_ALLOC,    // デバッグフィル確保時
    MEM_HEAP_FILL_FREE,     // デバッグフィル解放時
    
    MEM_HEAP_FILL_MAX
};



/* =======================================================================
    型定義
   ======================================================================== */

typedef struct MEMiHeapHead MEMiHeapHead;

// ヒープ共通ヘッダ
struct MEMiHeapHead
{
    u32       signature;
    
    MEMLink   link;
    MEMList   childList;
    
    void*     heapStart;      // ヒープ先頭アドレス
    void*     heapEnd;        // ヒープ末尾(+1)アドレス
    OSMutex   mutex;          // スレッド間での排他用
    
    union                     // 属性
    {
        u32       val;
        struct
        {
            u32   _reserved : 24;
            u32   optFlag   :  8; // オプションフラグ
        }
        fields;
    }
    attribute;
};


typedef MEMiHeapHead* MEMHeapHandle;   // ヒープのハンドルを表す型


/* =======================================================================
    関数プロトタイプ
   ======================================================================== */

MEMHeapHandle    MEMFindContainHeap( const void* memBlock );

MEMHeapHandle    MEMFindParentHeap( MEMHeapHandle heap );


/* ========================================================================
    インライン関数
   ======================================================================== */

/*---------------------------------------------------------------------------*
  Name:         MEMGetHeapStartAddress

  Description:  ヒープが利用するメモリ領域の開始アドレスを取得します。

  Arguments:    heap:  ヒープハンドル。

  Returns:      ヒープが利用するメモリ領域の開始アドレスを返します。
 *---------------------------------------------------------------------------*/
static inline void*
MEMGetHeapStartAddress( MEMHeapHandle heap )
{
    return (void*)heap;
}

/*---------------------------------------------------------------------------*
  Name:         MEMGetHeapEndAddress

  Description:  ヒープが利用するメモリ領域の終了アドレス +1 を取得します。

  Arguments:    heap:  ヒープハンドル。

  Returns:      ヒープが利用するメモリ領域の終了アドレス +1 を返します。
 *---------------------------------------------------------------------------*/
static inline void*
MEMGetHeapEndAddress( MEMHeapHandle heap )
{
    return heap->heapEnd;
}

/*---------------------------------------------------------------------------*
  Name:         MEMGetHeapTotalUsableSize

  Description:  ヒープに割り当てられているメモリサイズを取得します。
                ヘッダは含みません。

  Arguments:    heap:  ヒープハンドル。

  Returns:      ヒープに割り当てられているメモリサイズを返します。ヘッダは含みません。
 *---------------------------------------------------------------------------*/
static inline s32
MEMGetHeapTotalUsableSize( MEMHeapHandle heap )
{
    return ((s32)(heap->heapEnd) - (s32)(heap->heapStart));
}

/*---------------------------------------------------------------------------*
  Name:         MemGetHeapTotalSize

  Description:  ヒープに割り当てられているメモリサイズ(ヘッダ部分も含む全体のメモリサイズ)
                を取得します。

  Arguments:    heap    ヒープハンドル。

  Returns:      ヒープに割り当てられているメモリサイズ(ヘッダ部分も含む全体のメモリサイズ)
                を返します。
 *---------------------------------------------------------------------------*/
static inline s32
MEMGetHeapTotalSize( MEMHeapHandle heap )
{
    return ((s32)(heap->heapEnd) - (s32)(heap));
}


/*---------------------------------------------------------------------------*
  Name:         MEMGetHeapType

  Description:  ヒープハンドルがどの種類のヒープであるかを取得します。

  Arguments:    heap:  ヒープハンドル。

  Returns:      ヒープハンドルからヒープの種別を取得します。
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

  Description:  ヒープハンドルが拡張ヒープのものであるかどうかを判定します。

  Arguments:    heap    ヒープハンドル。

  Returns:      拡張ヒープであれば 真 を返します。
                それ以外の場合には偽を返します。
 *---------------------------------------------------------------------------*/
static inline BOOL
MEMIsExpHeap( MEMHeapHandle heap )
{
    return ( heap->signature == MEMi_EXPHEAP_SIGNATURE );
}


/*---------------------------------------------------------------------------*
  Name:         MEMIsFrmHeap

  Description:  ヒープハンドルがフレームヒープのものであるかどうかを判定します。

  Arguments:    heap    ヒープハンドル。

  Returns:      フレームヒープであれば 真 を返します。
                それ以外の場合には偽を返します。
 *---------------------------------------------------------------------------*/
static inline BOOL
MEMIsFrmHeap( MEMHeapHandle heap )
{
    return ( heap->signature == MEMi_FRMHEAP_SIGNATURE );
}


/*---------------------------------------------------------------------------*
  Name:         MEMIsUnitHeap

  Description:  ヒープハンドルがユニットヒープのものであるかどうかを判定します。

  Arguments:    heap    ヒープハンドル。

  Returns:      ユニットヒープであれば 真 を返します。
                それ以外の場合には偽を返します。
 *---------------------------------------------------------------------------*/
static inline BOOL
MEMIsUnitHeap( MEMHeapHandle heap )
{
    return ( heap->signature == MEMi_UNTHEAP_SIGNATURE );
}



/* =======================================================================
    デバッグ用関数
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

