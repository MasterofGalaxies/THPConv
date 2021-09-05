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
  �C���N���[�h�K�[�h��REVOLUTION_SDK�̌`���ɕύX

  Revision 1.4  2006/07/05 11:14:34  takano_makoto
  MI_LZ_COMPRESS_WORK_SIZE �� CX_LZ_COMPRESS_WORK_SIZE�ɕύX
  �C���N���[�h�K�[�h�̏C��

  Revision 1.3  2006/07/04 13:19:40  takano_makoto
  LZ���k�����[�N�o�b�t�@���g�p���������łɕύX

  Revision 1.2  2006/07/04 08:25:25  takano_makoto
  �v���t�B�b�N�X��DS�ł���ύX

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

  Description:  LZ77���k���s�Ȃ��֐�

  Arguments:    srcp            ���k���f�[�^�ւ̃|�C���^
                size            ���k���f�[�^�T�C�Y
                dstp            ���k��f�[�^�ւ̃|�C���^
                                ���k���f�[�^�����傫���T�C�Y�̃o�b�t�@���K�v�ł��B
                work            ���k�p�ꎞ�o�b�t�@
                                CX_LZ_COMPRESS_WORK_SIZE ���̗̈悪�K�v�ł��B

  Returns:      ���k��̃f�[�^�T�C�Y�B
                ���k��̃f�[�^�����k�O�����傫���Ȃ�ꍇ�ɂ͈��k�𒆒f��0��Ԃ��܂��B
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

  Description:  ���������O�X���k���s�Ȃ��֐�

  Arguments:    srcp            ���k���f�[�^�ւ̃|�C���^
                size            ���k���f�[�^�T�C�Y
                dstp            ���k��f�[�^�ւ̃|�C���^
                                ���k���f�[�^�����傫���T�C�Y�̃o�b�t�@���K�v�ł��B

  Returns:      ���k��̃f�[�^�T�C�Y�B
                ���k��̃f�[�^�����k�O�����傫���Ȃ�ꍇ�ɂ͈��k�𒆒f��0��Ԃ��܂��B
 *---------------------------------------------------------------------------*/
u32 CXCompressRL( const u8 *srcp, u32 size, u8 *dstp );


#define CX_HUFFMAN_COMPRESS_WORK_SIZE   ( 12288 + 512 + 1536 )


/*---------------------------------------------------------------------------*
  Name:         CXCompressHuffman

  Description:  �n�t�}�����k���s�Ȃ��֐�

  Arguments:    srcp            ���k���f�[�^�ւ̃|�C���^
                size            ���k���f�[�^�T�C�Y
                dstp            ���k��f�[�^�ւ̃|�C���^
                                ���k���f�[�^�����傫���T�C�Y�̃o�b�t�@���K�v�ł��B
                huffBitSize     �������r�b�g��
                work            ���k�p���[�N�o�b�t�@ CX_HUFFMAN_COMPRESS_WORK_SIZE ���̃T�C�Y���K�v

  Returns:      ���k��̃f�[�^�T�C�Y�B
                ���k��̃f�[�^�����k�O�����傫���Ȃ�ꍇ�ɂ͈��k�𒆒f��0��Ԃ��܂��B
 *---------------------------------------------------------------------------*/
u32 CXCompressHuffman( const u8 *srcp, u32 size, u8 *dstp, u8 huffBitSize, void *work );


#ifdef __cplusplus
} /* extern "C" */
#endif

/* __CX_COMPRESS_H__ */
#endif
