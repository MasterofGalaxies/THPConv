/*--------------------------------------------------------------------------*
  Project: Revolution DSPADPCM dynamic link library
  File:    endian.c

  Copyright (C)2001-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
  
  $Log: not supported by cvs2svn $
  
 *--------------------------------------------------------------------------*/
#include "types.h"

/*--------------------------------------------------------------------------*/
u16 reverse_endian_16(u16 data)
{
    return (u16)(((data & 0x00FF) << 8) | ((data & 0xFF00) >> 8));
}

/*--------------------------------------------------------------------------*/
u32 reverse_endian_32(u32 x)
{
    return(
            ((x >> 24) & 0x000000ff) |
            ((x >> 8)  & 0x0000ff00) |
            ((x << 8)  & 0x00ff0000) |
            ((x << 24) & 0xff000000) 
          );
} 


/*--------------------------------------------------------------------------*/
void reverse_buffer_16(u16 *p, int samples)
{
    u16 *data;
    int count;

    data    = p;
    count   = samples;

    while (samples)
    {
        *data = reverse_endian_16(*data);

        data++;
        samples--;
    }
}
