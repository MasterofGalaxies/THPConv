/*---------------------------------------------------------------------------*
  Project:     compress/uncompress library
  File:        CXStreamingUncompression.h

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.15  2007/05/30 04:19:52  takano_makoto
  add CXiInitUncompContextXXFront()

  Revision 1.14  2007/05/18 10:50:39  yasuh-to
  Rollback to SYSTEMMENU2_DEV_BRANCH(HEAD)

  Revision 1.11  2006/07/27 07:40:19  takano_makoto
  Add const modifier to CXIsFinishedUncompXXX parameter.

  Revision 1.10  2006/07/27 04:25:12  takano_makoto
  Change Condition of CXIsFinishedUncompXXX()

  Revision 1.9  2006/07/27 04:12:14  takano_makoto
  Change Interface of CXInitUncompContextXXX()
  Change Parameter type u8* to void*

  Revision 1.8  2006/07/12 01:11:41  takano_makoto
  fix comment

  Revision 1.7  2006/07/10 08:38:17  takano_makoto
  ストリーミング展開の完了判定用にCXIsFinishedUncompXXX()を追加
  CXReadUncompXXX()にヘッダ部分も含めたデータを渡すように仕様を変更
  (インターフェイス簡略化の為)

  Revision 1.6  2006/07/06 09:19:14  takano_makoto
  インクルードガードをREVOLUTION_SDKの形式に変更

  Revision 1.5  2006/07/06 04:40:14  takano_makoto
  RL8, LZ8を RL, LZに修正

  Revision 1.4  2006/07/05 11:14:43  takano_makoto
  インクルードガードの修正

  Revision 1.3  2006/07/05 08:13:36  takano_makoto
  コメントを修正
  16bitアクセス関数にしか必要のなかったコンテキストメンバを削除

  Revision 1.2  2006/07/04 08:26:20  takano_makoto
  プレフィックスをDS版から変更

  $NoKeywords: $
 *---------------------------------------------------------------------------*/


#ifndef __CX_STREAMING_UNCOMPRESSION_STREAM_H__
#define __CX_STREAMING_UNCOMPRESSION_STREAM_H__

#include <dolphin/types.h>
#include <revolution/os.h> // ASSERT用

#ifdef __cplusplus
extern "C" {
#endif


typedef struct
{
    u8 *destp;                         // 書き込み先ポインタ          4B
    s32 destCount;                     // 残り書き込みサイズ          4B
    s32 forceDestCount;                // 強制的に展開先サイズを設定  4B
    u16 length;                        // 連続書き込み残りサイズ      2B
    u8  flags;                         // 圧縮フラグ                  1B
    u8  headerSize;                    // 読み込み途中のヘッダサイズ  1B
                                       //                         計 16B
}
CXUncompContextRL;


typedef struct
{
    u8 *destp;                         // 書き込み先ポインタ              4B
    s32 destCount;                     // 残り書き込みサイズ              4B
    s32 forceDestCount;                // 強制的に展開先サイズを設定      4B
    s32 length;                        // 連続書き込み残り長              4B
    u8  lengthFlg;                     // length取得済フラグ              1B
    u8  flags;                         // 圧縮フラグ                      1B
    u8  flagIndex;                     // カレント圧縮フラグインデックス  1B
    u8  headerSize;                    // 読み込み途中のヘッダサイズ      1B
    u8  exFormat;                      // LZ77圧縮拡張オプション          1B
    u8  padding_[3];                   //                                 3B
                                       //                             計 24B
}
CXUncompContextLZ;


typedef struct
{
    u8 *destp;                         // 書き込み先ポインタ                     4B
    s32 destCount;                     // 残り書き込みサイズ                     4B
    s32 forceDestCount;                // 強制的に展開先サイズを設定             4B
    u8 *treep;                         // ハフマン符号テーブル、カレントポインタ 4B
    u32 srcTmp;                        // 読み込み途中のデータ                   4B
    u32 destTmp;                       // 復号化途中のデータ                     4B
    s16 treeSize;                      // ハフマン符号テーブルサイズ             2B
    u8  srcTmpCnt;                     // 読み込み途中のデータサイズ             1B
    u8  destTmpCnt;                    // 復号化済のビット数                     1B
    u8  bitSize;                       // 符号化ビットサイズ                     1B
    u8  headerSize;                    // 読み込み途中のヘッダサイズ             1B
    u8  padding_[2];                   //                                        2B
    u8  tree[0x200];                   // ハフマン符号テーブル                 512B  (4bit符号化であれば32Bで十分なのですが8bit分確保)
                                       //                                   計 544B  (4bit符号化の場合は60Bあればよい)
}
CXUncompContextHuffman;


typedef struct
{
    u8   *destp;                         // 書き込み先ポインタ                 4B
    s32  destCount;                      // 残り書き込みサイズ                 4B
    s32  forceDestCount;                 // 強制的に展開先サイズを設定         4B
    u16  huffTable9 [ 1 << (9 + 1) ];    // ハフマン符号テーブル            2048B
    u16  huffTable12[ 1 << (5 + 1) ];    // ハフマン符号テーブル             128B
    u16  *nodep;                         // ハフマンテーブルの探索中ノード     4B
    s32  tableSize9;                     // 読み込み途中のテーブルサイズ       4B
    s32  tableSize12;                    // 読み込み途中のテーブルサイズ       4B
    u32  tableIdx;                       // テーブル読み込み位置インデクス     4B
    u32  stream;                         // 読み込み用ビットストリーム         4B
    u32  stream_len;                     // 読み込み用ストリームの有効ビット数 4B
    u16  length;                         // LZ圧縮の読み取り長                 2B
    s8   offset_bits;                    // オフセット情報のビット長           1B
    u8   headerSize;                     // 読み込み途中のヘッダサイズ         1B
}                                        //                             計  2216B
CXUncompContextLH;


typedef struct
{
    u8   *destp;                         // 書き込み先ポインタ                 4B
    s32  destCount;                      // 残り書き込みサイズ                 4B
    s32  forceDestCount;                 // 強制的に展開先サイズを設定         4B
    u32  freq9    [ 1 << 9  ];           // codeデータ頻度テーブル          2048B
    u32  low_cnt9 [ 1 << 9  ];           // codeデータlow_cntテーブル       2048B
    u32  freq12   [ 1 << 12 ];           // offsetデータ頻度テーブル       16384B
    u32  low_cnt12[ 1 << 12 ];           // offsetデータlow_cntテーブル    16384B
    u32  total9;                         // codeデータtotal値                  4B
    u32  total12;                        // offsetデータtotal値                4B
    u32  range;                          // レンジコーダrange状態              4B
    u32  code;                           // レンジコーダcode状態               4B
    u32  low;                            // レンジコーダlow状態                4B
    u32  carry_cnt;                      // レンジコーダキャリー桁数           4B
    u8   carry;                          // レンジコーダキャリー状態           1B
    u8   codeLen;                        // レンジコーダ必要コード長           1B
    u16  length;                         // LZ圧縮の読み取り長                 2B
    
    u8   headerSize;                     // 読み込み途中のヘッダサイズ         1B
    u8   padding_[3];                    //                                    3B
}                                        //                             計 36908B
CXUncompContextLRC;

/*---------------------------------------------------------------------------*
  Name        : CXInitUncompContextRL

  Description : ランレングス圧縮データのストリーミング展開コンテキストを
                初期化。

  Arguments   : context     ランレングス展開コンテキストへのポインタ
                dest        展開先アドレス

  Returns     : 展開後のデータサイズが取得できます。

 *---------------------------------------------------------------------------*/
void CXInitUncompContextRL( CXUncompContextRL          *context, 
                            void                       *dest );


/*---------------------------------------------------------------------------*
  Name        : CXInitUncompContextLZ

  Description : LZ圧縮データのストリーミング展開コンテキストを初期化。

  Arguments   : context     LZ展開コンテキストへのポインタ
                dest        展開先アドレス

 *---------------------------------------------------------------------------*/
void CXInitUncompContextLZ( CXUncompContextLZ          *context,
                            void                       *dest );

/*---------------------------------------------------------------------------*
  Name        : CXInitUncompContextHuffman

  Description : ハフマン圧縮データのストリーミング展開コンテキストを初期化。

  Arguments   : context     ハフマン展開コンテキストへのポインタ
                dest        展開先アドレス

 *---------------------------------------------------------------------------*/
void CXInitUncompContextHuffman( CXUncompContextHuffman    *context, 
                                 void                      *dest );


/*---------------------------------------------------------------------------*
  Name:         CXInitUncompContextLH

  Description:  LZハフマン複合圧縮データのストリーミング展開コンテキストを初期化

  Arguments:    context 展開コンテキストへのポインタ
                dest    展開先アドレス

  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXInitUncompContextLH( CXUncompContextLH * context, void* dest );



/*---------------------------------------------------------------------------*
  Name:         CXInitUncompContextLRC

  Description:  LZレンジコーダ複合圧縮データのストリーミング展開コンテキストを初期化

  Arguments:    context 展開コンテキストへのポインタ
                dest    展開先アドレス

  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXInitUncompContextLRC( CXUncompContextLRC * context, void* dest );


/*---------------------------------------------------------------------------*
  Name        : CXReadUncompRL

  Description : ランレングス圧縮データをストリーミング展開する関数。

  Arguments   : context ランレングス展開コンテキストへのポインタ
                data    続きデータへのポインタ
                len     データサイズ

  Returns     : 残り展開データサイズ。

 *---------------------------------------------------------------------------*/
s32 CXReadUncompRL( CXUncompContextRL *context, const void *data, u32 len );

/*---------------------------------------------------------------------------*
  Name        : CXReadUncompLZ

  Description : LZ圧縮データをストリーミング展開する関数

  Arguments   : context LZ展開コンテキストへのポインタ
                data    続きデータへのポインタ
                len     データサイズ

  Returns     : 残り展開データサイズ。

 *---------------------------------------------------------------------------*/
s32 CXReadUncompLZ( CXUncompContextLZ *context, const void *data, u32 len );

/*---------------------------------------------------------------------------*
  Name        : CXReadUncompHuffman

  Description : ハフマン圧縮データをストリーミング展開する関数

  Arguments   : context ハフマン展開コンテキストへのポインタ
                data    続きデータへのポインタ
                len     データサイズ

  Returns     : 残り展開データサイズ。

 *---------------------------------------------------------------------------*/
s32 CXReadUncompHuffman( CXUncompContextHuffman *context, const void *data, u32 len );


/*---------------------------------------------------------------------------*
  Name:         CXReadUncompLH

  Description:  LZ-ハフマン複合圧縮データをストリーミング展開する関数

  Arguments:    *context 展開コンテキストへのポインタ
                data     データへのポインタ
                len      データサイズ

  Returns:      残り展開データサイズ
 *---------------------------------------------------------------------------*/
s32 CXReadUncompLH( CXUncompContextLH *context, const void* data, u32 len );


/*---------------------------------------------------------------------------*
  Name:         CXReadUncompLRC

  Description:  LZ-レンジコーダ複合圧縮データをストリーミング展開する関数

  Arguments:    *context 展開コンテキストへのポインタ
                data     データへのポインタ
                len      データサイズ

  Returns:      残り展開データサイズ
 *---------------------------------------------------------------------------*/
s32 CXReadUncompLRC( CXUncompContextLRC *context, const void* data, u32 len );


/*---------------------------------------------------------------------------*
  Name:         CXIsFinishedUncompRL

  Description:  ランレングス圧縮のストリーミング展開が完了しているかどうかを判定する関数

  Arguments:    *context ランレングス展開コンテキストへのポインタ

  Returns:      展開が完了している場合には                 TRUE
                まだ読み込むべきデータが残っている場合には FALSE
 *---------------------------------------------------------------------------*/
static inline BOOL CXIsFinishedUncompRL( const CXUncompContextRL *context )
{
    return (context->destCount > 0 || context->headerSize > 0)? FALSE : TRUE;
}


/*---------------------------------------------------------------------------*
  Name:         CXIsFinishedUncompLZ

  Description:  LZ圧縮のストリーミング展開が完了しているかどうかを判定する関数

  Arguments:    *context LZ展開コンテキストへのポインタ

  Returns:      展開が完了している場合には                 TRUE
                まだ読み込むべきデータが残っている場合には FALSE
 *---------------------------------------------------------------------------*/
static inline BOOL CXIsFinishedUncompLZ( const CXUncompContextLZ *context )
{
    return (context->destCount > 0 || context->headerSize > 0)? FALSE : TRUE;
}


/*---------------------------------------------------------------------------*
  Name:         CXIsFinishedUncompHuffman

  Description:  ハフマン圧縮のストリーミング展開が完了しているかどうかを判定する関数

  Arguments:    *context ハフマン展開コンテキストへのポインタ

  Returns:      展開が完了している場合には                 TRUE
                まだ読み込むべきデータが残っている場合には FALSE
 *---------------------------------------------------------------------------*/
static inline BOOL CXIsFinishedUncompHuffman( const CXUncompContextHuffman *context )
{
    return (context->destCount > 0 || context->headerSize > 0)? FALSE : TRUE;
}


/*---------------------------------------------------------------------------*
  Name:         CXIsFinishedUncompLH

  Description:  LZ-ハフマン複合圧縮のストリーミング展開が完了しているかどうかを判定する関数

  Arguments:    *context 展開コンテキストへのポインタ

  Returns:      展開が完了している場合には                 TRUE
                まだ読み込むべきデータが残っている場合には FALSE
 *---------------------------------------------------------------------------*/
static inline BOOL CXIsFinishedUncompLH( const CXUncompContextLH *context )
{
    return (context->destCount > 0 || context->headerSize > 0)? FALSE : TRUE;
}

/*---------------------------------------------------------------------------*
  Name:         CXIsFinishedUncompLRC

  Description:  LZ-レンジコーダ複合圧縮のストリーミング展開が完了しているかどうかを判定する関数

  Arguments:    *context 展開コンテキストへのポインタ

  Returns:      展開が完了している場合には                 TRUE
                まだ読み込むべきデータが残っている場合には FALSE
 *---------------------------------------------------------------------------*/
static inline BOOL CXIsFinishedUncompLRC( const CXUncompContextLRC *context )
{
    return (context->destCount > 0 || context->headerSize > 0)? FALSE : TRUE;
}


/*---------------------------------------------------------------------------*
  Name:         CXInitUncompContextXXFront

  Description:  圧縮データのストリーミング展開コンテキストを初期化。(展開サイズ指定付)

  Arguments:    *context    ランレングス展開コンテキストへのポインタ
                *dest       展開先アドレス
                destSize    展開サイズ指定

  Returns:      None.
 *---------------------------------------------------------------------------*/
static inline void CXiInitUncompContextRLFront( CXUncompContextRL *context, void *dest, s32 destSize )
{
    ASSERT( destSize > 0 );
    CXInitUncompContextRL( context, dest );
    context->forceDestCount = destSize;
}

static inline void CXiInitUncompContextLZFront( CXUncompContextLZ *context, void *dest, s32 destSize )
{
    ASSERT( destSize > 0 );
    CXInitUncompContextLZ( context, dest );
    context->forceDestCount = destSize;
}

static inline void CXiInitUncompContextHuffmanFront( CXUncompContextHuffman *context, void *dest, s32 destSize )
{
    ASSERT( destSize > 0 );
    CXInitUncompContextHuffman( context, dest );
    context->forceDestCount = destSize;
}

static inline void CXiInitUncompContextLHFront( CXUncompContextLH *context, void *dest, s32 destSize )
{
    ASSERT( destSize > 0 );
    CXInitUncompContextLH( context, dest );
    context->forceDestCount = destSize;
}

static inline void CXiInitUncompContextLRCFront( CXUncompContextLRC *context, void *dest, s32 destSize )
{
    ASSERT( destSize > 0 );
    CXInitUncompContextLRC( context, dest );
    context->forceDestCount = destSize;
}



#ifdef __cplusplus
} /* extern "C" */
#endif

/* __CX_STREAMING_UNCOMPRESSION_STREAM_H__ */
#endif
