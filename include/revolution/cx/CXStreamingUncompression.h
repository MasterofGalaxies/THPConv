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
  �X�g���[�~���O�W�J�̊�������p��CXIsFinishedUncompXXX()��ǉ�
  CXReadUncompXXX()�Ƀw�b�_�������܂߂��f�[�^��n���悤�Ɏd�l��ύX
  (�C���^�[�t�F�C�X�ȗ����̈�)

  Revision 1.6  2006/07/06 09:19:14  takano_makoto
  �C���N���[�h�K�[�h��REVOLUTION_SDK�̌`���ɕύX

  Revision 1.5  2006/07/06 04:40:14  takano_makoto
  RL8, LZ8�� RL, LZ�ɏC��

  Revision 1.4  2006/07/05 11:14:43  takano_makoto
  �C���N���[�h�K�[�h�̏C��

  Revision 1.3  2006/07/05 08:13:36  takano_makoto
  �R�����g���C��
  16bit�A�N�Z�X�֐��ɂ����K�v�̂Ȃ������R���e�L�X�g�����o���폜

  Revision 1.2  2006/07/04 08:26:20  takano_makoto
  �v���t�B�b�N�X��DS�ł���ύX

  $NoKeywords: $
 *---------------------------------------------------------------------------*/


#ifndef __CX_STREAMING_UNCOMPRESSION_STREAM_H__
#define __CX_STREAMING_UNCOMPRESSION_STREAM_H__

#include <dolphin/types.h>
#include <revolution/os.h> // ASSERT�p

#ifdef __cplusplus
extern "C" {
#endif


typedef struct
{
    u8 *destp;                         // �������ݐ�|�C���^          4B
    s32 destCount;                     // �c�菑�����݃T�C�Y          4B
    s32 forceDestCount;                // �����I�ɓW�J��T�C�Y��ݒ�  4B
    u16 length;                        // �A���������ݎc��T�C�Y      2B
    u8  flags;                         // ���k�t���O                  1B
    u8  headerSize;                    // �ǂݍ��ݓr���̃w�b�_�T�C�Y  1B
                                       //                         �v 16B
}
CXUncompContextRL;


typedef struct
{
    u8 *destp;                         // �������ݐ�|�C���^              4B
    s32 destCount;                     // �c�菑�����݃T�C�Y              4B
    s32 forceDestCount;                // �����I�ɓW�J��T�C�Y��ݒ�      4B
    s32 length;                        // �A���������ݎc�蒷              4B
    u8  lengthFlg;                     // length�擾�σt���O              1B
    u8  flags;                         // ���k�t���O                      1B
    u8  flagIndex;                     // �J�����g���k�t���O�C���f�b�N�X  1B
    u8  headerSize;                    // �ǂݍ��ݓr���̃w�b�_�T�C�Y      1B
    u8  exFormat;                      // LZ77���k�g���I�v�V����          1B
    u8  padding_[3];                   //                                 3B
                                       //                             �v 24B
}
CXUncompContextLZ;


typedef struct
{
    u8 *destp;                         // �������ݐ�|�C���^                     4B
    s32 destCount;                     // �c�菑�����݃T�C�Y                     4B
    s32 forceDestCount;                // �����I�ɓW�J��T�C�Y��ݒ�             4B
    u8 *treep;                         // �n�t�}�������e�[�u���A�J�����g�|�C���^ 4B
    u32 srcTmp;                        // �ǂݍ��ݓr���̃f�[�^                   4B
    u32 destTmp;                       // �������r���̃f�[�^                     4B
    s16 treeSize;                      // �n�t�}�������e�[�u���T�C�Y             2B
    u8  srcTmpCnt;                     // �ǂݍ��ݓr���̃f�[�^�T�C�Y             1B
    u8  destTmpCnt;                    // �������ς̃r�b�g��                     1B
    u8  bitSize;                       // �������r�b�g�T�C�Y                     1B
    u8  headerSize;                    // �ǂݍ��ݓr���̃w�b�_�T�C�Y             1B
    u8  padding_[2];                   //                                        2B
    u8  tree[0x200];                   // �n�t�}�������e�[�u��                 512B  (4bit�������ł����32B�ŏ\���Ȃ̂ł���8bit���m��)
                                       //                                   �v 544B  (4bit�������̏ꍇ��60B����΂悢)
}
CXUncompContextHuffman;


typedef struct
{
    u8   *destp;                         // �������ݐ�|�C���^                 4B
    s32  destCount;                      // �c�菑�����݃T�C�Y                 4B
    s32  forceDestCount;                 // �����I�ɓW�J��T�C�Y��ݒ�         4B
    u16  huffTable9 [ 1 << (9 + 1) ];    // �n�t�}�������e�[�u��            2048B
    u16  huffTable12[ 1 << (5 + 1) ];    // �n�t�}�������e�[�u��             128B
    u16  *nodep;                         // �n�t�}���e�[�u���̒T�����m�[�h     4B
    s32  tableSize9;                     // �ǂݍ��ݓr���̃e�[�u���T�C�Y       4B
    s32  tableSize12;                    // �ǂݍ��ݓr���̃e�[�u���T�C�Y       4B
    u32  tableIdx;                       // �e�[�u���ǂݍ��݈ʒu�C���f�N�X     4B
    u32  stream;                         // �ǂݍ��ݗp�r�b�g�X�g���[��         4B
    u32  stream_len;                     // �ǂݍ��ݗp�X�g���[���̗L���r�b�g�� 4B
    u16  length;                         // LZ���k�̓ǂݎ�蒷                 2B
    s8   offset_bits;                    // �I�t�Z�b�g���̃r�b�g��           1B
    u8   headerSize;                     // �ǂݍ��ݓr���̃w�b�_�T�C�Y         1B
}                                        //                             �v  2216B
CXUncompContextLH;


typedef struct
{
    u8   *destp;                         // �������ݐ�|�C���^                 4B
    s32  destCount;                      // �c�菑�����݃T�C�Y                 4B
    s32  forceDestCount;                 // �����I�ɓW�J��T�C�Y��ݒ�         4B
    u32  freq9    [ 1 << 9  ];           // code�f�[�^�p�x�e�[�u��          2048B
    u32  low_cnt9 [ 1 << 9  ];           // code�f�[�^low_cnt�e�[�u��       2048B
    u32  freq12   [ 1 << 12 ];           // offset�f�[�^�p�x�e�[�u��       16384B
    u32  low_cnt12[ 1 << 12 ];           // offset�f�[�^low_cnt�e�[�u��    16384B
    u32  total9;                         // code�f�[�^total�l                  4B
    u32  total12;                        // offset�f�[�^total�l                4B
    u32  range;                          // �����W�R�[�_range���              4B
    u32  code;                           // �����W�R�[�_code���               4B
    u32  low;                            // �����W�R�[�_low���                4B
    u32  carry_cnt;                      // �����W�R�[�_�L�����[����           4B
    u8   carry;                          // �����W�R�[�_�L�����[���           1B
    u8   codeLen;                        // �����W�R�[�_�K�v�R�[�h��           1B
    u16  length;                         // LZ���k�̓ǂݎ�蒷                 2B
    
    u8   headerSize;                     // �ǂݍ��ݓr���̃w�b�_�T�C�Y         1B
    u8   padding_[3];                    //                                    3B
}                                        //                             �v 36908B
CXUncompContextLRC;

/*---------------------------------------------------------------------------*
  Name        : CXInitUncompContextRL

  Description : ���������O�X���k�f�[�^�̃X�g���[�~���O�W�J�R���e�L�X�g��
                �������B

  Arguments   : context     ���������O�X�W�J�R���e�L�X�g�ւ̃|�C���^
                dest        �W�J��A�h���X

  Returns     : �W�J��̃f�[�^�T�C�Y���擾�ł��܂��B

 *---------------------------------------------------------------------------*/
void CXInitUncompContextRL( CXUncompContextRL          *context, 
                            void                       *dest );


/*---------------------------------------------------------------------------*
  Name        : CXInitUncompContextLZ

  Description : LZ���k�f�[�^�̃X�g���[�~���O�W�J�R���e�L�X�g���������B

  Arguments   : context     LZ�W�J�R���e�L�X�g�ւ̃|�C���^
                dest        �W�J��A�h���X

 *---------------------------------------------------------------------------*/
void CXInitUncompContextLZ( CXUncompContextLZ          *context,
                            void                       *dest );

/*---------------------------------------------------------------------------*
  Name        : CXInitUncompContextHuffman

  Description : �n�t�}�����k�f�[�^�̃X�g���[�~���O�W�J�R���e�L�X�g���������B

  Arguments   : context     �n�t�}���W�J�R���e�L�X�g�ւ̃|�C���^
                dest        �W�J��A�h���X

 *---------------------------------------------------------------------------*/
void CXInitUncompContextHuffman( CXUncompContextHuffman    *context, 
                                 void                      *dest );


/*---------------------------------------------------------------------------*
  Name:         CXInitUncompContextLH

  Description:  LZ�n�t�}���������k�f�[�^�̃X�g���[�~���O�W�J�R���e�L�X�g��������

  Arguments:    context �W�J�R���e�L�X�g�ւ̃|�C���^
                dest    �W�J��A�h���X

  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXInitUncompContextLH( CXUncompContextLH * context, void* dest );



/*---------------------------------------------------------------------------*
  Name:         CXInitUncompContextLRC

  Description:  LZ�����W�R�[�_�������k�f�[�^�̃X�g���[�~���O�W�J�R���e�L�X�g��������

  Arguments:    context �W�J�R���e�L�X�g�ւ̃|�C���^
                dest    �W�J��A�h���X

  Returns:      None.
 *---------------------------------------------------------------------------*/
void CXInitUncompContextLRC( CXUncompContextLRC * context, void* dest );


/*---------------------------------------------------------------------------*
  Name        : CXReadUncompRL

  Description : ���������O�X���k�f�[�^���X�g���[�~���O�W�J����֐��B

  Arguments   : context ���������O�X�W�J�R���e�L�X�g�ւ̃|�C���^
                data    �����f�[�^�ւ̃|�C���^
                len     �f�[�^�T�C�Y

  Returns     : �c��W�J�f�[�^�T�C�Y�B

 *---------------------------------------------------------------------------*/
s32 CXReadUncompRL( CXUncompContextRL *context, const void *data, u32 len );

/*---------------------------------------------------------------------------*
  Name        : CXReadUncompLZ

  Description : LZ���k�f�[�^���X�g���[�~���O�W�J����֐�

  Arguments   : context LZ�W�J�R���e�L�X�g�ւ̃|�C���^
                data    �����f�[�^�ւ̃|�C���^
                len     �f�[�^�T�C�Y

  Returns     : �c��W�J�f�[�^�T�C�Y�B

 *---------------------------------------------------------------------------*/
s32 CXReadUncompLZ( CXUncompContextLZ *context, const void *data, u32 len );

/*---------------------------------------------------------------------------*
  Name        : CXReadUncompHuffman

  Description : �n�t�}�����k�f�[�^���X�g���[�~���O�W�J����֐�

  Arguments   : context �n�t�}���W�J�R���e�L�X�g�ւ̃|�C���^
                data    �����f�[�^�ւ̃|�C���^
                len     �f�[�^�T�C�Y

  Returns     : �c��W�J�f�[�^�T�C�Y�B

 *---------------------------------------------------------------------------*/
s32 CXReadUncompHuffman( CXUncompContextHuffman *context, const void *data, u32 len );


/*---------------------------------------------------------------------------*
  Name:         CXReadUncompLH

  Description:  LZ-�n�t�}���������k�f�[�^���X�g���[�~���O�W�J����֐�

  Arguments:    *context �W�J�R���e�L�X�g�ւ̃|�C���^
                data     �f�[�^�ւ̃|�C���^
                len      �f�[�^�T�C�Y

  Returns:      �c��W�J�f�[�^�T�C�Y
 *---------------------------------------------------------------------------*/
s32 CXReadUncompLH( CXUncompContextLH *context, const void* data, u32 len );


/*---------------------------------------------------------------------------*
  Name:         CXReadUncompLRC

  Description:  LZ-�����W�R�[�_�������k�f�[�^���X�g���[�~���O�W�J����֐�

  Arguments:    *context �W�J�R���e�L�X�g�ւ̃|�C���^
                data     �f�[�^�ւ̃|�C���^
                len      �f�[�^�T�C�Y

  Returns:      �c��W�J�f�[�^�T�C�Y
 *---------------------------------------------------------------------------*/
s32 CXReadUncompLRC( CXUncompContextLRC *context, const void* data, u32 len );


/*---------------------------------------------------------------------------*
  Name:         CXIsFinishedUncompRL

  Description:  ���������O�X���k�̃X�g���[�~���O�W�J���������Ă��邩�ǂ����𔻒肷��֐�

  Arguments:    *context ���������O�X�W�J�R���e�L�X�g�ւ̃|�C���^

  Returns:      �W�J���������Ă���ꍇ�ɂ�                 TRUE
                �܂��ǂݍ��ނׂ��f�[�^���c���Ă���ꍇ�ɂ� FALSE
 *---------------------------------------------------------------------------*/
static inline BOOL CXIsFinishedUncompRL( const CXUncompContextRL *context )
{
    return (context->destCount > 0 || context->headerSize > 0)? FALSE : TRUE;
}


/*---------------------------------------------------------------------------*
  Name:         CXIsFinishedUncompLZ

  Description:  LZ���k�̃X�g���[�~���O�W�J���������Ă��邩�ǂ����𔻒肷��֐�

  Arguments:    *context LZ�W�J�R���e�L�X�g�ւ̃|�C���^

  Returns:      �W�J���������Ă���ꍇ�ɂ�                 TRUE
                �܂��ǂݍ��ނׂ��f�[�^���c���Ă���ꍇ�ɂ� FALSE
 *---------------------------------------------------------------------------*/
static inline BOOL CXIsFinishedUncompLZ( const CXUncompContextLZ *context )
{
    return (context->destCount > 0 || context->headerSize > 0)? FALSE : TRUE;
}


/*---------------------------------------------------------------------------*
  Name:         CXIsFinishedUncompHuffman

  Description:  �n�t�}�����k�̃X�g���[�~���O�W�J���������Ă��邩�ǂ����𔻒肷��֐�

  Arguments:    *context �n�t�}���W�J�R���e�L�X�g�ւ̃|�C���^

  Returns:      �W�J���������Ă���ꍇ�ɂ�                 TRUE
                �܂��ǂݍ��ނׂ��f�[�^���c���Ă���ꍇ�ɂ� FALSE
 *---------------------------------------------------------------------------*/
static inline BOOL CXIsFinishedUncompHuffman( const CXUncompContextHuffman *context )
{
    return (context->destCount > 0 || context->headerSize > 0)? FALSE : TRUE;
}


/*---------------------------------------------------------------------------*
  Name:         CXIsFinishedUncompLH

  Description:  LZ-�n�t�}���������k�̃X�g���[�~���O�W�J���������Ă��邩�ǂ����𔻒肷��֐�

  Arguments:    *context �W�J�R���e�L�X�g�ւ̃|�C���^

  Returns:      �W�J���������Ă���ꍇ�ɂ�                 TRUE
                �܂��ǂݍ��ނׂ��f�[�^���c���Ă���ꍇ�ɂ� FALSE
 *---------------------------------------------------------------------------*/
static inline BOOL CXIsFinishedUncompLH( const CXUncompContextLH *context )
{
    return (context->destCount > 0 || context->headerSize > 0)? FALSE : TRUE;
}

/*---------------------------------------------------------------------------*
  Name:         CXIsFinishedUncompLRC

  Description:  LZ-�����W�R�[�_�������k�̃X�g���[�~���O�W�J���������Ă��邩�ǂ����𔻒肷��֐�

  Arguments:    *context �W�J�R���e�L�X�g�ւ̃|�C���^

  Returns:      �W�J���������Ă���ꍇ�ɂ�                 TRUE
                �܂��ǂݍ��ނׂ��f�[�^���c���Ă���ꍇ�ɂ� FALSE
 *---------------------------------------------------------------------------*/
static inline BOOL CXIsFinishedUncompLRC( const CXUncompContextLRC *context )
{
    return (context->destCount > 0 || context->headerSize > 0)? FALSE : TRUE;
}


/*---------------------------------------------------------------------------*
  Name:         CXInitUncompContextXXFront

  Description:  ���k�f�[�^�̃X�g���[�~���O�W�J�R���e�L�X�g���������B(�W�J�T�C�Y�w��t)

  Arguments:    *context    ���������O�X�W�J�R���e�L�X�g�ւ̃|�C���^
                *dest       �W�J��A�h���X
                destSize    �W�J�T�C�Y�w��

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
