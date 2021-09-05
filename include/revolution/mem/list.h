/*---------------------------------------------------------------------------*
  Project:     MEM library
  File:        list.h
  Programmers: Takano Makoto

  Copyright 2005 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/

#ifndef MEM_LIST_H__
#define MEM_LIST_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <stddef.h>
#include <revolution/types.h>


/*---------------------------------------------------------------------------*
  Name:         MEMLink

  Description:  �o���������N���X�g�̃m�[�h�\���̂ł��B���̍\���̂����X�g�\��
                �Ōq�������\���̂̃����o�Ƃ��Ċi�[���܂��B
 *---------------------------------------------------------------------------*/
typedef struct
{
    void*       prevObject;     // �O�Ɍq����Ă���I�u�W�F�N�g�ւ̃|�C���^�B
    void*       nextObject;     // ���Ɍq����Ă���I�u�W�F�N�g�ւ̃|�C���^�B

} MEMLink;


/*---------------------------------------------------------------------------*
  Name:         MEMList

  Description:  �o���������N���X�g�\���̂ł��B
 *---------------------------------------------------------------------------*/
typedef struct 
{
    void*       headObject;     // �擪�Ɍq����Ă���I�u�W�F�N�g�ւ̃|�C���^�B
    void*       tailObject;     // ����Ɍq����Ă���I�u�W�F�N�g�ւ̃|�C���^�B
    u16         numObjects;     // ���X�g�Ɍq����Ă���I�u�W�F�N�g�̌��B
    u16         offset;         // NNSFndLink�^�̍\���̃����o�̃I�t�Z�b�g�B

} MEMList;


/*---------------------------------------------------------------------------*
  Name:         MEM_INIT_LIST

  Description:  ���X�g�\���̂����������邽�߂̃}�N���ł��B���ۂ̏������ɂ́A
                MEMInitList()�֐��ɂ��s���܂��B

                ���̃}�N���ł́A�w�肳�ꂽ�\���̖���Link�^�����o�ϐ�������A
                offsetof�}�N�����g���ăI�t�Z�b�g�����߁AInitList�֐��ɓn����
                ���܂��B

  Arguments:    list:       �����N�\���̂ւ̃|�C���^�B
                structName: ���X�g�Ɍq�������I�u�W�F�N�g�̍\���̖��B
                linkName:   ���̃I�u�W�F�N�g�̃����N�Ɏg�p�����Link�^
                            �̃����o�ϐ����B

  Returns:      �Ȃ��B
 *---------------------------------------------------------------------------*/

#define MEM_INIT_LIST(list, structName, linkName) \
           MEMInitList(list, offsetof(structName, linkName))


/*---------------------------------------------------------------------------*
    �֐��v���g�^�C�v�B

 *---------------------------------------------------------------------------*/

void    MEMInitList(
                MEMList*              list,
                u16                   offset);

void    MEMAppendListObject(
                MEMList*              list,
                void*                 object);

void    MEMPrependListObject(
                MEMList*              list,
                void*                 object);

void    MEMInsertListObject(
                MEMList*              list,
                void*                 target,
                void*                 object);

void    MEMRemoveListObject(
                MEMList*              list,
                void*                 object);

void*   MEMGetNextListObject(
                MEMList*              list,
                void*                 object);

void*   MEMGetPrevListObject(
                MEMList*              list,
                void*                 object);

void*   MEMGetNthListObject(
                MEMList*              list,
                u16                   index);


#ifdef __cplusplus
} /* extern "C" */
#endif

/* MEM_LIST_H__ */
#endif
