/*---------------------------------------------------------------------------*
  Project: Revolution RVA
  File   : vi_rva.h

  Copyright 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __VI_RVA_H__
#define __VI_RVA_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _VIOverDrive
{
	VI_ODV_L1   = 0,
    VI_ODV_L2   = 1,
    VI_ODV_L3   = 2,
    VI_ODV_L4   = 3,
    VI_ODV_L5   = 4,
    VI_ODV_L6   = 5
} VIOverDrive;


void VISetRGBOverDrive( VIOverDrive level );
void VISetRVAMode( void ); // set Mode


#ifdef __cplusplus
}
#endif

#endif __VI_RVA_H__
