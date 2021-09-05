/*---------------------------------------------------------------------------*
  Project:     compress/uncompress library
  File:        CXCompression.h

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.8  2007/05/18 10:50:39  yasuh-to
  Rollback to SYSTEMMENU2_DEV_BRANCH(HEAD)

  Revision 1.5  2006/07/06 09:19:14  takano_makoto
  インクルードガードをREVOLUTION_SDKの形式に変更

  Revision 1.4  2006/07/05 11:14:34  takano_makoto
  MI_LZ_COMPRESS_WORK_SIZE を CX_LZ_COMPRESS_WORK_SIZEに変更
  インクルードガードの修正

  Revision 1.3  2006/07/04 13:19:40  takano_makoto
  LZ圧縮をワークバッファを使用した高速版に変更

  Revision 1.2  2006/07/04 08:25:25  takano_makoto
  プレフィックスをDS版から変更

  $NoKeywords: $
 *---------------------------------------------------------------------------*/


#ifndef __CX_COMPRESS_H__
#define __CX_COMPRESS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <dolphin/types.h>


#define CX_LZ_COMPRESS_WORK_SIZE   ( (4096 + 256 + 256) * sizeof(s16) )

/*---------------------------------------------------------------------------*
  Name:         CXCompressLZ

  Description:  LZ77圧縮を行なう関数

  Arguments:    srcp            圧縮元データへのポインタ
                size            圧縮元データサイズ
                dstp            圧縮先データへのポインタ
                                圧縮元データよりも大きいサイズのバッファが必要です。
                work            圧縮用一時バッファ
                                CX_LZ_COMPRESS_WORK_SIZE 分の領域が必要です。

  Returns:      圧縮後のデータサイズ。
                圧縮後のデータが圧縮前よりも大きくなる場合には圧縮を中断し0を返します。
 *---------------------------------------------------------------------------*/
u32 CXCompressLZImpl(const u8 *srcp, u32 size, u8 *dstp, void *work, BOOL exFormat);

inline u32 CXCompressLZEx(const u8 *srcp, u32 size, u8 *dstp, void* work)
{
    return CXCompressLZImpl( srcp, size, dstp, work, TRUE );
}
inline u32 CXCompressLZ(const u8 *srcp, u32 size, u8 *dstp, void *work)
{
    return CXCompressLZImpl( srcp, size, dstp, work, FALSE );
}


/*---------------------------------------------------------------------------*
  Name:         CXCompressRL

  Description:  ランレングス圧縮を行なう関数

  Arguments:    srcp            圧縮元データへのポインタ
                size            圧縮元データサイズ
                dstp            圧縮先データへのポインタ
                                圧縮元データよりも大きいサイズのバッファが必要です。

  Returns:      圧縮後のデータサイズ。
                圧縮後のデータが圧縮前よりも大きくなる場合には圧縮を中断し0を返します。
 *---------------------------------------------------------------------------*/
u32 CXCompressRL( const u8 *srcp, u32 size, u8 *dstp );


#define CX_HUFFMAN_COMPRESS_WORK_SIZE   ( 12288 + 512 + 1536 )


/*---------------------------------------------------------------------------*
  Name:         CXCompressHuffman

  Description:  ハフマン圧縮を行なう関数

  Arguments:    srcp            圧縮元データへのポインタ
                size            圧縮元データサイズ
                dstp            圧縮先データへのポインタ
                                圧縮元データよりも大きいサイズのバッファが必要です。
                huffBitSize     符号化ビット数
                work            圧縮用ワークバッファ CX_HUFFMAN_COMPRESS_WORK_SIZE 分のサイズが必要

  Returns:      圧縮後のデータサイズ。
                圧縮後のデータが圧縮前よりも大きくなる場合には圧縮を中断し0を返します。
 *---------------------------------------------------------------------------*/
u32 CXCompressHuffman( const u8 *srcp, u32 size, u8 *dstp, u8 huffBitSize, void *work );


#ifdef __cplusplus
} /* extern "C" */
#endif

/* __CX_COMPRESS_H__ */
#endif
