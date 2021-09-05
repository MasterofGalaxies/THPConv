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
//          ���k�f�[�^�W�J
//======================================================================

/*---------------------------------------------------------------------------*
  Name:         CXSecureUncompressAny

  Description:  �f�[�^�w�b�_���爳�k�^�C�v�𔻕ʂ��āA
                �K���ȓW�J���������s���܂��B
                ���ׂĂ̈��k��ނ̓W�J�����������N����܂��̂ŁA
                ����̈��k�t�H�[�}�b�g�ȊO�g�p���Ă��Ȃ��ꍇ�ɂ�
                ���k��ʖ��̊֐������s���������悢��������܂���B

  Arguments:    srcp    �\�[�X�A�h���X
                srcSize �\�[�X�f�[�^�T�C�Y
                destp   �f�X�e�B�l�[�V�����A�h���X

  Returns:      �ϊ��ɐ��������ꍇ�� 0
                ���s�����ꍇ�ɂ͕��̃G���[�R�[�h
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressAny( const void* srcp, u32 srcSize, void* destp );


/*---------------------------------------------------------------------------*
  Name:         CXSecureUncompressRL

  Description:  ���������O�X���k�f�[�^�W�������W�J

  �E���������O�X���k�f�[�^��W�J���A8bit�P�ʂŏ������݂܂��B
  �E�\�[�X�A�h���X��4Byte���E�ɍ��킹�ĉ������B

  �E�f�[�^�w�b�_
      u32 :4                  �\��
          compType:4          ���k�^�C�v�i = 3�j
          destSize:24         �W�J��̃f�[�^�T�C�Y
  
  �E�t���O�f�[�^�t�H�[�}�b�g
      u8  length:7            �W�J�f�[�^�� - 1�i�����k���j
                              �W�J�f�[�^�� - 3�i�A����3Byte�ȏ㎞�݈̂��k�j
          flag:1              �i0, 1�j = �i�����k�f�[�^, ���k�f�[�^�j
  
  Arguments:    *srcp   �\�[�X�A�h���X
                srcSize �\�[�X�f�[�^�T�C�Y
                *destp  �f�X�e�B�l�[�V�����A�h���X

  Returns:      �ϊ��ɐ��������ꍇ�� 0
                ���s�����ꍇ�ɂ͕��̃G���[�R�[�h
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressRL( const void *srcp, u32 srcSize, void *destp );


/*---------------------------------------------------------------------------*
  Name:         CXSecureUncompressLZ
  
  Description:  �k�y�V�V���k�f�[�^�W�������W�J
  
  �ELZ77���k�f�[�^��W�J���A8bit�P�ʂŏ������݂܂��B
  �E�\�[�X�A�h���X��4Byte���E�ɍ��킹�ĉ������B
  
  �E�f�[�^�w�b�_
      u32 :4                  �\��
          compType:4          ���k�^�C�v�i = 1�j
          destSize:24         �W�J��̃f�[�^�T�C�Y
  
  �E�t���O�f�[�^�t�H�[�}�b�g
      u8  flags               ���k�^�����k�t���O
                              �i0, 1�j = �i�����k�f�[�^, ���k�f�[�^�j
  �E�R�[�h�f�[�^�t�H�[�}�b�g�iBig Endian�j
      u16 length:4            �W�J�f�[�^�� - 3�i��v��3Byte�ȏ㎞�݈̂��k�j
          offset:12           ��v�f�[�^�I�t�Z�b�g - 1
  
  Arguments:    *srcp   �\�[�X�A�h���X
                srcSize �\�[�X�f�[�^�T�C�Y
                *destp  �f�X�e�B�l�[�V�����A�h���X
  
  Returns:      �ϊ��ɐ��������ꍇ�� 0
                ���s�����ꍇ�ɂ͕��̃G���[�R�[�h
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressLZ( const void *srcp, u32 srcSize, void *destp );


/*---------------------------------------------------------------------------*
  Name:         CXSecureUncompressHuffman
  
  Description:  �n�t�}�����k�f�[�^�W�J
  
  �E�n�t�}�����k�f�[�^��W�J���A32bit�P�ʂŏ������݂܂��B
  �E�\�[�X�A�h���X��4Byte���E�ɍ��킹�ĉ������B
  �E�f�X�e�B�l�[�V�����A�h���X��4Byte���E�ɍ��킹�Ă��������B
  �E�W�J��̃o�b�t�@�T�C�Y��4Byte�̔{���������p�ӂ��Ă�������
  
  �E�f�[�^�w�b�_
      u32 bitSize:4           �P�f�[�^�E�r�b�g�T�C�Y�i�ʏ� 4|8�j
          compType:4          ���k�^�C�v�i = 2�j
          destSize:24         �W�J��̃f�[�^�T�C�Y
  
  �E�c���[�e�[�u��
      u8           treeSize        �c���[�e�[�u���T�C�Y/2 - 1
      TreeNodeData nodeRoot        ���[�g�m�[�h
  
      TreeNodeData nodeLeft        ���[�g���m�[�h
      TreeNodeData nodeRight       ���[�g�E�m�[�h
  
      TreeNodeData nodeLeftLeft    �����m�[�h
      TreeNodeData nodeLeftRight   ���E�m�[�h
  
      TreeNodeData nodeRightLeft   �E���m�[�h
      TreeNodeData nodeRightRight  �E�E�m�[�h
  
              �E
              �E
  
    ���̌�Ɉ��k�f�[�^�{��
  
  �ETreeNodeData�\����
      u8  nodeNextOffset:6    ���m�[�h�f�[�^�ւ̃I�t�Z�b�g - 1�i2Byte�P�ʁj
          rightEndFlag:1      �E�m�[�h�I���t���O
          leftEndzflag:1      ���m�[�h�I���t���O
                              �I���t���O���Z�b�g����Ă���ꍇ
                              ���m�[�h�Ƀf�[�^������
  
  Arguments:    *srcp   �\�[�X�A�h���X
                srcSize �\�[�X�f�[�^�T�C�Y
                *destp  �f�X�e�B�l�[�V�����A�h���X

  Returns:      �ϊ��ɐ��������ꍇ�� 0
                ���s�����ꍇ�ɂ͕��̃G���[�R�[�h
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressHuffman( const void *srcp, u32 srcSize, void *destp );

/*---------------------------------------------------------------------------*
  Name:         CXUncompressLH

  Description:  LZ-Huffman�������k�̓W�J
  
  Arguments:    *srcp   �\�[�X�A�h���X
                srcSize �\�[�X�T�C�Y
                *destp  �f�X�e�B�l�[�V�����A�h���X
                *work   ���[�N�o�b�t�@
                        CX_UNCOMPRESS_LH_WORK_SIZE���̃T�C�Y���K�v(2176B)

  Returns:      None.
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressLH( const u8* srcp, u32 srcSize, u8* dstp, void* work );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressLRC

  Description:  LZ-RangeCoder�������k�̓W�J
  
  Arguments:    *srcp   �\�[�X�A�h���X
                srcSize �\�[�X�T�C�Y
                *destp  �f�X�e�B�l�[�V�����A�h���X
                *work   ���[�N�o�b�t�@
                        CX_UNCOMPRESS_LRC_WORK_SIZE���̃T�C�Y���K�v(36864B)

  Returns:      None.
 *---------------------------------------------------------------------------*/
s32 CXSecureUncompressLRC( const u8* srcp, u32 srcSize, u8* dstp, void* work );



/*---------------------------------------------------------------------------*
  Name:         CXSecureUnfilterDiff

  Description:  �����t�B���^�ϊ��̕��� �W�������W�J
  
    �E�����t�B���^�𕜌����A8bit�P�ʂŏ������݂܂��B
    �EVRAM�ɒ��ړW�J���邱�Ƃ͂ł��܂���B
    �E���k�f�[�^�̃T�C�Y��4�̔{���ɂȂ�Ȃ������ꍇ��
      �o���邾��0�ŋl�߂Ē������ĉ������B
    �E�\�[�X�A�h���X��4Byte���E�ɍ��킹�ĉ������B

  Arguments:    *srcp   �\�[�X�A�h���X
                srcSize �\�[�X�T�C�Y
                *destp  �f�X�e�B�l�[�V�����A�h���X

  Returns:      �ϊ��ɐ��������ꍇ�� 0
                ���s�����ꍇ�ɂ͕��̃G���[�R�[�h
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

  Returns:      �G���[�R�[�h
 *---------------------------------------------------------------------------*/
// !!!! Coded in libraries/init/ARM9/crt0.c
// void CXiUncompressBackward( void *bottom );




#ifdef __cplusplus
} /* extern "C" */
#endif

/* __CX_SECURE_UNCOMPRESSION_H__ */
#endif
