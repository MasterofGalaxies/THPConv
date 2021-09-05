/*--------------------------------------------------------------------------*
  Project: Revolution DSPADPCM dynamic link library
  File:    encode.h

  Copyright (C)2003-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
  
  $Log: not supported by cvs2svn $
    
 *--------------------------------------------------------------------------*/

#ifndef __ENCODE_H__
#define __ENCODE_H__

#include "types.h"

void encodeLoop(u16*, u32, void*, ADPCMINFO*);

#endif // __ENCODE_H__
