/*---------------------------------------------------------------------------*
  Project:     MEM library
  File:        list.h
  Programmers: Takano Makoto

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/

#ifndef MEM_LIST_H__
#define MEM_LIST_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <stddef.h>
#include <revolution/types.h>


/*---------------------------------------------------------------------------*
  Name:         MEMLink

  Description:  双方向リンクリストのノード構造体です。この構造体をリスト構造
                で繋ぎたい構造体のメンバとして格納します。
 *---------------------------------------------------------------------------*/
typedef struct
{
    void*       prevObject;     // 前に繋がれているオブジェクトへのポインタ。
    void*       nextObject;     // 次に繋がれているオブジェクトへのポインタ。

} MEMLink;


/*---------------------------------------------------------------------------*
  Name:         MEMList

  Description:  双方向リンクリスト構造体です。
 *---------------------------------------------------------------------------*/
typedef struct 
{
    void*       headObject;     // 先頭に繋がれているオブジェクトへのポインタ。
    void*       tailObject;     // 後尾に繋がれているオブジェクトへのポインタ。
    u16         numObjects;     // リストに繋がれているオブジェクトの個数。
    u16         offset;         // NNSFndLink型の構造体メンバのオフセット。

} MEMList;


/*---------------------------------------------------------------------------*
  Name:         MEM_INIT_LIST

  Description:  リスト構造体を初期化するためのマクロです。実際の初期化には、
                MEMInitList()関数により行われます。

                このマクロでは、指定された構造体名とLink型メンバ変数名から、
                offsetofマクロを使ってオフセットを求め、InitList関数に渡して
                います。

  Arguments:    list:       リンク構造体へのポインタ。
                structName: リストに繋げたいオブジェクトの構造体名。
                linkName:   このオブジェクトのリンクに使用されるLink型
                            のメンバ変数名。

  Returns:      なし。
 *---------------------------------------------------------------------------*/

#define MEM_INIT_LIST(list, structName, linkName) \
           MEMInitList(list, offsetof(structName, linkName))


/*---------------------------------------------------------------------------*
    関数プロトタイプ。

 *---------------------------------------------------------------------------*/

void    MEMInitList(
                MEMList*              list,
                u16                   offset);

void    MEMAppendListObject(
                MEMList*              list,
                void*                 object);

void    MEMPrependListObject(
                MEMList*              list,
                void*                 object);

void    MEMInsertListObject(
                MEMList*              list,
                void*                 target,
                void*                 object);

void    MEMRemoveListObject(
                MEMList*              list,
                void*                 object);

void*   MEMGetNextListObject(
                MEMList*              list,
                void*                 object);

void*   MEMGetPrevListObject(
                MEMList*              list,
                void*                 object);

void*   MEMGetNthListObject(
                MEMList*              list,
                u16                   index);


#ifdef __cplusplus
} /* extern "C" */
#endif

/* MEM_LIST_H__ */
#endif
