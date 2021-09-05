/*---------------------------------------------------------------------------*
  Project:     compress/uncompress library
  File:        CXSecureUncompression.h

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.5  2007/05/30 04:20:25  takano_makoto
  small fix.

  Revision 1.4  2007/05/18 10:50:39  yasuh-to
  Rollback to SYSTEMMENU2_DEV_BRANCH(HEAD)

  Revision 1.1.2.1  2006/12/06 09:55:16  yasuh-to
  initial commit

  Revision 1.1  2006/12/04 13:34:46  takano_makoto
  Initial update.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __CX_SECURE_UNCOMPRESSION_H__
#define __CX_SECURE_UNCOMPRESSION_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <dolphin/types.h>
#include <revolution/cx/CXUncompression.h>

#define CX_ERR_SUCCESS              0
#define CX_ERR_UNSUPPORTED          -1
#define CX_ERR_SRC_SHORTAGE         -2
#define CX_ERR_SRC_REMAINDER        -3
#define CX_ERR_DEST_OVERRUN         -4
#define CX_ERR_ILLEGAL_TABLE        -5

//======================================================================
//          圧縮データ展開
//======================================================================

/*---------------------------------------------------------------------------*
  Name:         CXSecureUncompressAny

  Description:  データヘッダから圧縮タイプを判別して、
                適当な展開処理を実行します。
                すべての圧縮種類の展開処理がリンクされますので、
                特定の圧縮フォーマット以外使用していない場合には
                圧縮種別毎の関数を実行した方がよいかもしれません。

  Arguments:    srcp    ソースアドレス
                srcSize ソースデータサイズ
                destp   デスティネーションアドレス

  Returns:      変換に成功した場合は 0
                失敗した場合には負のエラーコード
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressAny( const void* srcp, u32 srcSize, void* destp );


/*---------------------------------------------------------------------------*
  Name:         CXSecureUncompressRL

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
                srcSize ソースデータサイズ
                *destp  デスティネーションアドレス

  Returns:      変換に成功した場合は 0
                失敗した場合には負のエラーコード
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressRL( const void *srcp, u32 srcSize, void *destp );


/*---------------------------------------------------------------------------*
  Name:         CXSecureUncompressLZ
  
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
                srcSize ソースデータサイズ
                *destp  デスティネーションアドレス
  
  Returns:      変換に成功した場合は 0
                失敗した場合には負のエラーコード
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressLZ( const void *srcp, u32 srcSize, void *destp );


/*---------------------------------------------------------------------------*
  Name:         CXSecureUncompressHuffman
  
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
                srcSize ソースデータサイズ
                *destp  デスティネーションアドレス

  Returns:      変換に成功した場合は 0
                失敗した場合には負のエラーコード
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressHuffman( const void *srcp, u32 srcSize, void *destp );

/*---------------------------------------------------------------------------*
  Name:         CXUncompressLH

  Description:  LZ-Huffman複合圧縮の展開
  
  Arguments:    *srcp   ソースアドレス
                srcSize ソースサイズ
                *destp  デスティネーションアドレス
                *work   ワークバッファ
                        CX_UNCOMPRESS_LH_WORK_SIZE分のサイズが必要(2176B)

  Returns:      None.
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressLH( const u8* srcp, u32 srcSize, u8* dstp, void* work );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressLRC

  Description:  LZ-RangeCoder複合圧縮の展開
  
  Arguments:    *srcp   ソースアドレス
                srcSize ソースサイズ
                *destp  デスティネーションアドレス
                *work   ワークバッファ
                        CX_UNCOMPRESS_LRC_WORK_SIZE分のサイズが必要(36864B)

  Returns:      None.
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressLRC( const u8* srcp, u32 srcSize, u8* dstp, void* work );



/*---------------------------------------------------------------------------*
  Name:         CXSecureUnfilterDiff

  Description:  差分フィルタ変換の復元 ８ｂｉｔ展開
  
    ・差分フィルタを復元し、8bit単位で書き込みます。
    ・VRAMに直接展開することはできません。
    ・圧縮データのサイズが4の倍数にならなかった場合は
      出来るだけ0で詰めて調整して下さい。
    ・ソースアドレスは4Byte境界に合わせて下さい。

  Arguments:    *srcp   ソースアドレス
                srcSize ソースサイズ
                *destp  デスティネーションアドレス

  Returns:      変換に成功した場合は 0
                失敗した場合には負のエラーコード
 *---------------------------------------------------------------------------*/
s32 CXSecureUnfilterDiff( register const void *srcp, u32 srcSize, register void *destp );



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

  Returns:      エラーコード
 *---------------------------------------------------------------------------*/
// !!!! Coded in libraries/init/ARM9/crt0.c
// void CXiUncompressBackward( void *bottom );




#ifdef __cplusplus
} /* extern "C" */
#endif

/* __CX_SECURE_UNCOMPRESSION_H__ */
#endif
