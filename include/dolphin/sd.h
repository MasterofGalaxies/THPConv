/*---------------------------------------------------------------------------*
  Project:  Dolphin SD Card API
  File:     sd.h

  Copyright 2003 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
    
    1     03/11/10 16:05 Mitu

 *---------------------------------------------------------------------------*/
/*
** Copyright (c) 2000-2002 Matsushita Electric Industrial Co., Ltd.
** All Rights Reserved.
*/

#ifndef __SD_H__
#define __SD_H__

//#include <dolphin/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DOLPHIN_SDFS

/*
 * �^�錾
 */
typedef char CHAR;					/* �L�����N�^�^ 				*/
typedef int INT16;					/* 16�r�b�g						*/
typedef long INT32;					/* 32�r�b�g						*/
typedef unsigned char UCHAR;		/* ���������L�����N�^�^ 		*/
typedef unsigned short UINT16;		/* ��������16�r�b�g				*/
typedef unsigned long UINT32;		/* ��������32�r�b�g				*/

#include <dolphin/sd/fs_confdef.h>
#include <dolphin/sd/fs_config.h>
#include <dolphin/sd/fs_def.h>
#include <dolphin/sd/fs_type.h>
#include <dolphin/sd/fs_fsio.h>
#include <dolphin/sd/sd_com.h>					// For dolphin SD*

/*-------------------------------------
�J�[�h�G���[�R�[�h
-------------------------------------*/
#define	CARD_NORMAL				0		//	����I��
#define	CARD_ERR_COMMAND		0x0001	//	CMD�G���[
#define	CARD_ERR_CRC			0x0002	//	CRC�G���[
#define	CARD_ERR_END			0x0004	//	���s�G���[
#define	CARD_ERR_R2_STATUS		0x0008	//	R2 Status Error
#define	CARD_ERR_EXI_ATTACH		0x0090	//	�O���g���f�o�C�X�ڑ��G���[
#define	CARD_ERR_EXI_LOCK		0x00A0	//	EXI device lock error
#define	CARD_ERR_EXI_SELECT		0x00B0	//	EXI device select error
#define	CARD_ERR_EXI_DETACH		0x00C0	//	EXI device detach error
#define	CARD_ERR_EXI_UNLOCK		0x00D0	//	EXI device unlock error
#define	CARD_ERR_EXI_DESELECT	0x00E0	//	EXI device deselect error
#define	CARD_ERR_EXI_TRANS		0x00F0	//	EXI�]���G���[
#define	CARD_ERR_ADDRESS		0x0100	//	�A�h���X�G���[
#define	CARD_ERR_WRITE			0x0200	//	Data Rejected due to a Write Error
#define	CARD_ERR_WP				0x0400	//	WriteProtect�ɂ�鏑�����݃G���[
#define	CARD_ERR_PARAM			0x1000	//	�R�}���h�p�����[�^�G���[
#define	CARD_ERR_TIMEOUT		0x4000	//	�J�[�h�A�N�Z�X Timeout �G���[
#define	CARD_ERR_RESET			0x8000	//	�������J�[�h���Z�b�g�R�}���h��1.5�b�^�C���A�E�g�G���[

/*
 * SD Low level error code
 */
#define	SD_LOW_NORMAL			CARD_NORMAL			//	����I��
#define	SD_LOW_ERR_COMMAND		CARD_ERR_COMMAND	//	CMD�G���[
#define	SD_LOW_ERR_CRC			CARD_ERR_CRC		//	CRC�G���[
#define	SD_LOW_ERR_END			CARD_ERR_END		//	���s�G���[
#define	SD_LOW_ERR_R2_STATUS	CARD_ERR_R2_STATUS	//	R2 Status Error
#define	SD_LOW_ERR_EXI_ATTACH	CARD_ERR_EXI_ATTACH	//	�O���g���f�o�C�X�ڑ��G���[
#define	SD_LOW_ERR_EXI_LOCK		CARD_ERR_EXI_LOCK	//	EXI device lock error
#define	SD_LOW_ERR_EXI_SELECT	CARD_ERR_EXI_SELECT	//	EXI device select error
#define	SD_LOW_ERR_EXI_DETACH	CARD_ERR_EXI_DETACH	//	EXI device detach error
#define	SD_LOW_ERR_EXI_UNLOCK	CARD_ERR_EXI_UNLOCK	//	EXI device unlock error
#define	SD_LOW_ERR_EXI_DESELECT	CARD_ERR_EXI_DESELECT	//	EXI device deselect error
#define	SD_LOW_ERR_EXI_TRANS	CARD_ERR_EXI_TRANS	//	EXI�]���G���[
#define	SD_LOW_ERR_ADDRESS		CARD_ERR_ADDRESS	//	�A�h���X�G���[
#define	SD_LOW_ERR_WRITE		CARD_ERR_WRITE		//	Data Rejected due to a Write Error
#define	SD_LOW_ERR_WP			CARD_ERR_WP			//	WriteProtect�ɂ�鏑�����݃G���[
#define	SD_LOW_ERR_PARAM		CARD_ERR_PARAM		//	�R�}���h�p�����[�^�G���[
#define	SD_LOW_ERR_TIMEOUT		CARD_ERR_TIMEOUT	//	�J�[�h�A�N�Z�X Timeout �G���[
#define	SD_LOW_ERR_RESET		CARD_ERR_RESET		//	�������J�[�h���Z�b�g�R�}���h��1.5�b�^�C���A�E�g�G���[

/*
 * SD_*** �ɒ�`���Ȃ���
 */

/* �f�o�C�X��� */
#define SDDrive 			FS_DRIVE
/* �t�@�C���V�X�e����� */
#define SDFs				FS_FS
/* �t�@�C����� */
#define SDFile				FS_FILE
/* �f�B���N�g����� */
#define SDDir				FS_DIR
/* �f�B���N�g���G���g����� */
#define SDEntry				FS_ENTRY
/* ���s���ʒʒm��� */
#define SDInfo				FS_INFO
/* �f�B���N�g���G���g����� */
#define SDDirent			FS_DIRENT



#ifdef __cplusplus
}
#endif

#endif  // __SD_H__

