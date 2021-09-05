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
	ODHEncodexxx - xxx�`����ODH�Ɉ��k����

	�����F
		src : �摜�f�[�^�̃o�b�t�@
		dst : ODH�f�[�^������o�b�t�@
		limit: ODH�f�[�^�̃o�b�t�@�T�C�Y
		quality: �掿(0-100)
		work: ���[�N�G���A(width*height*3)�K�v
	�Ԃ�l�F
		���k(ODH)�T�C�Y 0�Ŏ��s
/********************************************************************/

extern int ODHEncodeRGB565(unsigned char *,unsigned char *,int,int,int,int,unsigned char *);
extern int ODHEncodeRGBA8(unsigned char *,unsigned char *,int,int,int,int,unsigned char *);
extern int ODHEncodeY8U8V8(unsigned char *,unsigned char *,int,int,int,int,unsigned char *);

/********************************************************************
	ODHDecodexxx - ODH�f�[�^��xxx�`���œW�J����

	�����F
		src : ODH�f�[�^�̓������o�b�t�@
		dst : �W�J�������ʂ�����o�b�t�@
		work: ���[�N�G���A(width*height*3)�K�v
	�Ԃ�l�F
		�摜�̏c���̑傫��	(height<<16)|width 0�Ŏ��s
/********************************************************************/

extern int ODHDecodeRGB565(unsigned char *,unsigned char *,unsigned char *);
extern int ODHDecodeRGBA8(unsigned char *,unsigned char *,unsigned char *);
extern int ODHDecodeY8U8V8(unsigned char *,unsigned char *,unsigned char *);

#ifdef __cplusplus
}
#endif

#endif // __ODH_H__ 
