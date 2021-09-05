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
  �C���N���[�h�K�[�h��REVOLUTION_SDK�̌`���ɕύX

  Revision 1.8  2006/07/06 05:29:48  takano_makoto
  CXUnfilterDiff��ǉ�

  Revision 1.7  2006/07/06 04:39:50  takano_makoto
  CXGetCompressionType, CXGetUncompressedSize�����d��`�ɂȂ��Ă����̂ŏC��

  Revision 1.6  2006/07/06 04:13:04  takano_makoto
  CXGetCompressionType, CXGetUncompressedSize��ǉ�

  Revision 1.5  2006/07/05 11:14:43  takano_makoto
  �C���N���[�h�K�[�h�̏C��

  Revision 1.4  2006/07/05 08:13:03  takano_makoto
  �R�����g���C��

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
// ���k�f�[�^�w�b�_�[
//
typedef struct
{
    u8  compType;   // ���k�^�C�v
    u8  compParam;  // ���k�p�����[�^
    u8  padding_[2];
    u32 destSize;   // �W�J�T�C�Y
}
CXCompressionHeader;


/*---------------------------------------------------------------------------*
  Name:         CXGetCompressionHeader

  Description:  ���k�f�[�^�̐擪�S�o�C�g����w�b�_�����擾���܂�

  Arguments:    data    ���k�f�[�^�̐擪�S�o�C�g�̃f�[�^�ւ̃|�C���^

  Returns:      None.
 *---------------------------------------------------------------------------*/
CXCompressionHeader CXGetCompressionHeader( const void *data );

/*---------------------------------------------------------------------------*
  Name:         CXGetCompressionType

  Description:  ���k�f�[�^�̐擪�P�o�C�g���爳�k�^�C�v���擾���܂��B

  Arguments:    srcp :  compressed data address

  Returns:      compression type.
                CX_COMPREESION_LZ      : LZ77���k���ꂽ�f�[�^
                CX_COMPREESION_HUFFMAN : �n�t�}�����k���ꂽ�f�[�^
                CX_COMPREESION_RL      : ���������O�X���k���ꂽ�f�[�^
                CX_COMPRESSION_DIFF    : �����t�B���^�ŕϊ����ꂽ�f�[�^
 *---------------------------------------------------------------------------*/
static inline CXCompressionType   CXGetCompressionType( const void *data )
{
    return (CXCompressionType)( *(u8*)data & 0xF0 );
}

//======================================================================
//          ���k�f�[�^�W�J
//======================================================================

/*---------------------------------------------------------------------------*
  Name:         CXGetUncompressedSize

  Description:  �W�J��̃f�[�^�T�C�Y���擾���܂��B
                ���̊֐���CX�ň����S�Ă̈��k�`���̃f�[�^�ɑ΂��Ďg�p�ł��܂��B

  Arguments:    srcp :  ���k�f�[�^�̐擪�S�o�C�g�̃f�[�^�ւ̃|�C���^

  Returns:      �W�J��̃f�[�^�T�C�Y
 *---------------------------------------------------------------------------*/
u32 CXGetUncompressedSize( const void *srcp );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressAny

  Description:  �f�[�^�w�b�_���爳�k�^�C�v�𔻕ʂ��āA
                �K���ȓW�J���������s���܂��B
                ���ׂĂ̈��k��ނ̓W�J�����������N����܂��̂ŁA
                ����̈��k�t�H�[�}�b�g�ȊO�g�p���Ă��Ȃ��ꍇ�ɂ�
                ���k��ʖ��̊֐������s���������悢��������܂���B

  Arguments:    srcp    �\�[�X�A�h���X
                destp   �f�X�e�B�l�[�V�����A�h���X

  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXUncompressAny( const void* srcp, void* destp );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressRL

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
                *destp  �f�X�e�B�l�[�V�����A�h���X

  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXUncompressRL( const void *srcp, void *destp );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressLZ
  
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
                *destp  �f�X�e�B�l�[�V�����A�h���X
  
  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXUncompressLZ( const void *srcp, void *destp );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressHuffman
  
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
                *destp  �f�X�e�B�l�[�V�����A�h���X

  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXUncompressHuffman( const void *srcp, void *destp );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressLH

  Description:  LZ-Huffman�������k�̓W�J
  
  Arguments:    *srcp   �\�[�X�A�h���X
                *destp  �f�X�e�B�l�[�V�����A�h���X
                *work   ���[�N�o�b�t�@
                        CX_UNCOMPRESS_LH_WORK_SIZE���̃T�C�Y���K�v(2176B)

  Returns:      None.
 *---------------------------------------------------------------------------*/
#define CX_UNCOMPRESS_LH_WORK_SIZE      ((1 << 11) + (1 << 7))
void CXUncompressLH( const u8* srcp, u8* dstp, void* work );


/*---------------------------------------------------------------------------*
  Name:         CXUncompressLRC

  Description:  LZ-RangeCoder�������k�̓W�J
  
  Arguments:    *srcp   �\�[�X�A�h���X
                *destp  �f�X�e�B�l�[�V�����A�h���X
                *work   ���[�N�o�b�t�@
                        CX_UNCOMPRESS_LRC_WORK_SIZE���̃T�C�Y���K�v(36864B)

  Returns:      None.
 *---------------------------------------------------------------------------*/
#define CX_UNCOMPRESS_LRC_WORK_SIZE      (((1 << 12) + (1 << 9)) * 8)
void CXUncompressLRC( const u8* srcp, u8* dstp, void* work );


/*---------------------------------------------------------------------------*
  Name:         CXUnfilterDiff

  Description:  �����t�B���^�ϊ��̕��� �W�������W�J
  
    �E�����t�B���^�𕜌����A8bit�P�ʂŏ������݂܂��B
    �EVRAM�ɒ��ړW�J���邱�Ƃ͂ł��܂���B
    �E���k�f�[�^�̃T�C�Y��4�̔{���ɂȂ�Ȃ������ꍇ��
      �o���邾��0�ŋl�߂Ē������ĉ������B
    �E�\�[�X�A�h���X��4Byte���E�ɍ��킹�ĉ������B

  Arguments:    *srcp   �\�[�X�A�h���X
                *destp  �f�X�e�B�l�[�V�����A�h���X

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
