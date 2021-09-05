/*---------------------------------------------------------------------------*
  Project:  Revolution OS - WPAD 
  File:     wpadTrain.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.2.1  2007/02/14 02:33:29  tojo
  Initial check-in.

  Revision 1.1  2006/12/12 07:58:19  tojo
  initial check-in.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __WPAD_TRAIN_H__
#define __WPAD_TRAIN_H__

#include <revolution/wpad.h> 

#ifdef __cplusplus
extern "C" {
#endif

typedef struct WPADTRStatus
{
    u16       button;               // Or-ed WPAD_BUTTON_* bits
    s16       accX;                 // -WPAD_ACC_RESO/2 <= accX < WPAD_ACC_RESO/2
    s16       accY;                 // -WPAD_ACC_RESO/2 <= accY < WPAD_ACC_RESO/2
    s16       accZ;                 // -WPAD_ACC_RESO/2 <= accZ < WPAD_ACC_RESO/2
    DPDObject obj[WPAD_DPD_MAX_OBJECTS];

    u8        dev;                  // one of WPAD_DEV_* number
    s8        err;                  // one of WPAD_ERR_* number

    u16       trButton;             // Or-ed WPAD_CL_BUTTON * bits
    u8        brake;                // 0 <= brake  < 256
    u8        mascon;               // 0 <= mascon < 256
} WPADTRStatus;


#define WPAD_DEV_TRAIN               16
// data format of Core + Train
#define WPAD_FMT_TRAIN               10    // buttons, train

#ifdef __cplusplus
}
#endif
#endif // __WPAD_TRAIN_H__
