/*---------------------------------------------------------------------------*
  Project:     compress/uncompress library
  File:        CXUncompression.h

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.14  2007/05/18 10:50:39  yasuh-to
  Rollback to SYSTEMMENU2_DEV_BRANCH(HEAD)

  Revision 1.11  2006/09/13 01:01:31  takano_makoto
  expand max file size.

  Revision 1.10  2006/07/14 05:23:56  takano_makoto
  Add CXUncompressAny()
  Bug fix in CXGetCompressionType()

  Revision 1.9  2006/07/06 09:19:14  takano_makoto
  インクルードガードをREVOLUTION_SDKの形式に変更

  Revision 1.8  2006/07/06 05:29:48  takano_makoto
  CXUnfilterDiffを追加

  Revision 1.7  2006/07/06 04:39:50  takano_makoto
  CXGetCompressionType, CXGetUncompressedSizeが多重定義になっていたので修正

  Revision 1.6  2006/07/06 04:13:04  takano_makoto
  CXGetCompressionType, CXGetUncompressedSizeを追加

  Revision 1.5  2006/07/05 11:14:43  takano_makoto
  インクルードガードの修正

  Revision 1.4  2006/07/05 08:13:03  takano_makoto
  コメントを修正

  Revision 1.3  2006/07/04 08:38:39  takano_makoto
  fix copyright header

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __CX_UNCOMPRESSION_H__
#define __CX_UNCOMPRESSION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <dolphin/types.h>


//---- compression type
typedef enum
{
    CX_COMPRESSION_LZ           = 0x10,     // LZ77
    CX_COMPRESSION_HUFFMAN      = 0x20,     // Huffman
    CX_COMPRESSION_RL           = 0x30,     // Run Length
    CX_COMPRESSION_LH           = 0x40,     // LH(LZ77+Huffman)
    CX_COMPRESSION_LRC          = 0x50,     // LRC(LZ77+RangeCoder)
    CX_COMPRESSION_DIFF         = 0x80,     // Differential filter

    CX_COMPRESSION_TYPE_MASK    = 0xF0,
    CX_COMPRESSION_TYPE_EX_MASK = 0xFF
}
CXCompressionType;


//----------------------------------------------------------------
// 圧縮データヘッダー
//
typedef struct
{
    u8  compType;   // 圧縮タイプ
    u8  compParam;  // 圧縮パラメータ
    u8  padding_[2];
    u32 destSize;   // 展開サイズ
}
CXCompressionHeader;


/*---------------------------------------------------------------------------*
  Name:         CXGetCompressionHeader

  Description:  圧縮データの先頭４バイトからヘッダ情報を取得します

  Arguments:    data    圧縮データの先頭４バイトのデータへのポインタ

  Returns:      None.
 *---------------------------------------------------------------------------*/
CXCompressionHeader CXGetCompressionHeader( const void *data );

/*---------------------------------------------------------------------------*
  Name:         CXGetCompressionType

  Description:  圧縮データの先頭１バイトから圧縮タイプを取得します。

  Arguments:    srcp :  compressed data address

  Returns:      compression type.
                CX_COMPREESION_LZ      : LZ77圧縮されたデータ
                CX_COMPREESION_HUFFMAN : ハフマン圧縮されたデータ
                CX_COMPREESION_RL      : ランレングス圧縮されたデータ
                CX_COMPRESSION_DIFF    : 差分フィルタで変換されたデータ
 *---------------------------------------------------------------------------*/
static inline CXCompressionType   CXGetCompressionType( const void *data )
{
    return (CXCompressionType)( *(u8*)data & 0xF0 );
}

//======================================================================
//          圧縮データ展開
//======================================================================

/*---------------------------------------------------------------------------*
  Name:         CXGetUncompressedSize

  Description:  展開後のデータサイズを取得します。
                この関数はCXで扱う全ての圧縮形式のデータに対して使用できます。

  Arguments:    srcp :  圧縮データの先頭４バイトのデータへのポインタ

  Returns:      展開後のデータサイズ
 *---------------------------------------------------------------------------*/
u32 CXGetUncompressedSize( const void *srcp );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressAny

  Description:  データヘッダから圧縮タイプを判別して、
                適当な展開処理を実行します。
                すべての圧縮種類の展開処理がリンクされますので、
                特定の圧縮フォーマット以外使用していない場合には
                圧縮種別毎の関数を実行した方がよいかもしれません。

  Arguments:    srcp    ソースアドレス
                destp   デスティネーションアドレス

  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXUncompressAny( const void* srcp, void* destp );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressRL

  Description:  ランレングス圧縮データ８ｂｉｔ展開

  ・ランレングス圧縮データを展開し、8bit単位で書き込みます。
  ・ソースアドレスは4Byte境界に合わせて下さい。

  ・データヘッダ
      u32 :4                  予約
          compType:4          圧縮タイプ（ = 3）
          destSize:24         展開後のデータサイズ
  
  ・フラグデータフォーマット
      u8  length:7            展開データ長 - 1（無圧縮時）
                              展開データ長 - 3（連続長3Byte以上時のみ圧縮）
          flag:1              （0, 1） = （無圧縮データ, 圧縮データ）
  
  Arguments:    *srcp   ソースアドレス
                *destp  デスティネーションアドレス

  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXUncompressRL( const void *srcp, void *destp );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressLZ
  
  Description:  ＬＺ７７圧縮データ８ｂｉｔ展開
  
  ・LZ77圧縮データを展開し、8bit単位で書き込みます。
  ・ソースアドレスは4Byte境界に合わせて下さい。
  
  ・データヘッダ
      u32 :4                  予約
          compType:4          圧縮タイプ（ = 1）
          destSize:24         展開後のデータサイズ
  
  ・フラグデータフォーマット
      u8  flags               圧縮／無圧縮フラグ
                              （0, 1） = （無圧縮データ, 圧縮データ）
  ・コードデータフォーマット（Big Endian）
      u16 length:4            展開データ長 - 3（一致長3Byte以上時のみ圧縮）
          offset:12           一致データオフセット - 1
  
  Arguments:    *srcp   ソースアドレス
                *destp  デスティネーションアドレス
  
  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXUncompressLZ( const void *srcp, void *destp );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressHuffman
  
  Description:  ハフマン圧縮データ展開
  
  ・ハフマン圧縮データを展開し、32bit単位で書き込みます。
  ・ソースアドレスは4Byte境界に合わせて下さい。
  ・デスティネーションアドレスは4Byte境界に合わせてください。
  ・展開先のバッファサイズは4Byteの倍数分だけ用意してください
  
  ・データヘッダ
      u32 bitSize:4           １データ・ビットサイズ（通常 4|8）
          compType:4          圧縮タイプ（ = 2）
          destSize:24         展開後のデータサイズ
  
  ・ツリーテーブル
      u8           treeSize        ツリーテーブルサイズ/2 - 1
      TreeNodeData nodeRoot        ルートノード
  
      TreeNodeData nodeLeft        ルート左ノード
      TreeNodeData nodeRight       ルート右ノード
  
      TreeNodeData nodeLeftLeft    左左ノード
      TreeNodeData nodeLeftRight   左右ノード
  
      TreeNodeData nodeRightLeft   右左ノード
      TreeNodeData nodeRightRight  右右ノード
  
              ・
              ・
  
    この後に圧縮データ本体
  
  ・TreeNodeData構造体
      u8  nodeNextOffset:6    次ノードデータへのオフセット - 1（2Byte単位）
          rightEndFlag:1      右ノード終了フラグ
          leftEndzflag:1      左ノード終了フラグ
                              終了フラグがセットされている場合
                              次ノードにデータがある
  
  Arguments:    *srcp   ソースアドレス
                *destp  デスティネーションアドレス

  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXUncompressHuffman( const void *srcp, void *destp );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressLH

  Description:  LZ-Huffman複合圧縮の展開
  
  Arguments:    *srcp   ソースアドレス
                *destp  デスティネーションアドレス
                *work   ワークバッファ
                        CX_UNCOMPRESS_LH_WORK_SIZE分のサイズが必要(2176B)

  Returns:      None.
 *---------------------------------------------------------------------------*/
#define CX_UNCOMPRESS_LH_WORK_SIZE      ((1 << 11) + (1 << 7))
void CXUncompressLH( const u8* srcp, u8* dstp, void* work );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressLRC

  Description:  LZ-RangeCoder複合圧縮の展開
  
  Arguments:    *srcp   ソースアドレス
                *destp  デスティネーションアドレス
                *work   ワークバッファ
                        CX_UNCOMPRESS_LRC_WORK_SIZE分のサイズが必要(36864B)

  Returns:      None.
 *---------------------------------------------------------------------------*/
#define CX_UNCOMPRESS_LRC_WORK_SIZE      (((1 << 12) + (1 << 9)) * 8)
void CXUncompressLRC( const u8* srcp, u8* dstp, void* work );


/*---------------------------------------------------------------------------*
  Name:         CXUnfilterDiff

  Description:  差分フィルタ変換の復元 ８ｂｉｔ展開
  
    ・差分フィルタを復元し、8bit単位で書き込みます。
    ・VRAMに直接展開することはできません。
    ・圧縮データのサイズが4の倍数にならなかった場合は
      出来るだけ0で詰めて調整して下さい。
    ・ソースアドレスは4Byte境界に合わせて下さい。

  Arguments:    *srcp   ソースアドレス
                *destp  デスティネーションアドレス

  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXUnfilterDiff( register const void *srcp, register void *destp );


//================================================================================


/*---------------------------------------------------------------------------*
  Name:         CXiUncompressBackward

  Description:  Uncompress special archive for module compression

  Arguments:    bottom      = Bottom adrs of packed archive + 1
                bottom[-12] = offset for top    of compressed data
                                 inp_top = bottom + bottom[-12]
                bottom[ -8] = offset for bottom of compressed data
                                 inp     = bottom + bottom[ -8]
                bottom[ -4] = offset for bottom of original data
                                 outp    = bottom + bottom[ -4]
  
                typedef struct
                {
                    int         bufferTop;
                    int         compressBottom;
                    int         originalBottom;
                }   CompFooter;

  Returns:      None.
 *---------------------------------------------------------------------------*/
// !!!! Coded in libraries/init/ARM9/crt0.c
// void CXiUncompressBackward( void *bottom );




#ifdef __cplusplus
} /* extern "C" */
#endif

/* __CX_UNCOMPRESSION_H__ */
#endif
