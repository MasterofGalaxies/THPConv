/*--------------------------------------------------------------------------*
  Project: Revolution DSPADPCM dynamic link library
  File:    endian.h

  Copyright (C)2001-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
  
  $Log: not supported by cvs2svn $
  
 *--------------------------------------------------------------------------*/

#ifndef __ENDIAN_H__
#define __ENDIAN_H__

#include "types.h"

#define NORMAL_ENDIAN   0
#define REVERSE_ENDIAN  1


u32 reverse_endian_32(u32 i);
u16 reverse_endian_16(u16 i);
void reverse_buffer_16(u16 *p, int samples);

#endif // __ENDIAN_H__
