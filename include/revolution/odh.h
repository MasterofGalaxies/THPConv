/*---------------------------------------------------------------------------*
  Project:     Revolution ODH library
  File:        odh.h

  Copyright (C)2006 Nintendo  All Rights Reserved.
 
  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/

#ifndef __ODH_H__
#define __ODH_H__

#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------------------------------
//	Prototypes
//----------------------------------------------------------------------------

/********************************************************************
	ODHEncodexxx - xxx形式をODHに圧縮する

	引数：
		src : 画像データのバッファ
		dst : ODHデータを入れるバッファ
		limit: ODHデータのバッファサイズ
		quality: 画質(0-100)
		work: ワークエリア(width*height*3)必要
	返り値：
		圧縮(ODH)サイズ 0で失敗
/********************************************************************/

extern int ODHEncodeRGB565(unsigned char *,unsigned char *,int,int,int,int,unsigned char *);
extern int ODHEncodeRGBA8(unsigned char *,unsigned char *,int,int,int,int,unsigned char *);
extern int ODHEncodeY8U8V8(unsigned char *,unsigned char *,int,int,int,int,unsigned char *);

/********************************************************************
	ODHDecodexxx - ODHデータをxxx形式で展開する

	引数：
		src : ODHデータの入ったバッファ
		dst : 展開した結果を入れるバッファ
		work: ワークエリア(width*height*3)必要
	返り値：
		画像の縦横の大きさ	(height<<16)|width 0で失敗
/********************************************************************/

extern int ODHDecodeRGB565(unsigned char *,unsigned char *,unsigned char *);
extern int ODHDecodeRGBA8(unsigned char *,unsigned char *,unsigned char *);
extern int ODHDecodeY8U8V8(unsigned char *,unsigned char *,unsigned char *);

#ifdef __cplusplus
}
#endif

#endif // __ODH_H__ 
