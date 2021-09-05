/*--------------------------------------------------------------------------*
  Project: Revolution DSPADPCM dynamic link library
  File:    Nxadpcm.h

  Copyright (C)2001-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
  
  $Log: not supported by cvs2svn $
  Revision 1.1  2005/11/04 06:49:54  aka
  Imported from Dolphin tree.
    
    2     03/05/26 2:26p Akagi
    Modified to use MMX/SSE (by Ohki-san@NTSC).
    
 *--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "types.h"


#ifndef __NXADPCM_H__
#define __NXADPCM_H__

//#define DEBUGMSG
//#define STEREO_FORMAT_SUPPORT

#define SAMPLES_PER_FRAME               14
#define NIBBLES_PER_FRAME               16
#define BYTES_PER_FRAME                 8

#define ORDER                           2
#define MAX_LEVEL                       8
#define MAX_SCALE                       12
#define MAX_CLIP                        1

#define MAX_NUM_OF_COEFTABLE            8
#define NUM_OF_COEFTABLE                8
//#define NUM_OF_COEFTABLE              4
#define COEF_SCALING_BIT                11
#define COEF_SCALING                    2048


#define MAX_CHANNELS                    2

/*--------------------------------------------------------------------------*/

typedef struct
{
    u32 length;
    u32 ncoefs;
    u32 srate;
    u8  extension[4];
    
} NXADPCMHEADER;

/*--------------------------------------------------------------------------*/
/* Nxadpcm.c */
int adpcmReadFileHeader(FILE          *adpcmfile,
                        NXADPCMHEADER *h,
                        s16           *coeftable);
int adpcmWriteFileHeader(FILE          *adpcmfile,
                         NXADPCMHEADER *h,
                         s16           *coeftable);


/* Nxencodeframe.c */
u16  adpcmEncodeFrame(s16 *inbuffer,
                      u8  *outbuffer,
                      s16 *coeftable,
                      u8  step);

u16  adpcmEncodeFrame_SSE(s16 *inbuffer,
                      u8  *outbuffer,
                      s16 *coeftable,
                      u8  step);

/* Nxdecodeframe.c */
void adpcmDecodeFrame(u8  *aramaddr,
                      s16 *outbuffer,
                      s16 *coeftable,
                      u8  step,
                      u32 loopStart);


#endif // __NXADPCM_H__
