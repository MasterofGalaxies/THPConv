/*--------------------------------------------------------------------------*
  Project: Revolution DSPADPCM dynamic link library
  File:    tbdesign.h

  Copyright (C)2001-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
  
  $Log: not supported by cvs2svn $
  Revision 1.1  2005/11/04 06:49:54  aka
  Imported from Dolphin tree.
    
    2     03/05/26 2:28p Akagi
    Modified to use MMX/SSE (by Ohki-san@NTSC).
    
 *--------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifndef __TBDESIGN_H__
#define __TBDESIGN_H__

#include "types.h"
#include "dspadpcm.h"

#define TINY            1e-10

/* In estimate.c */
void acf(short *sig, int len, double *ac, int nlags);
int durbin(double *ac, int order, double *ref, double *taps, double *e2);
void afromk(double *ref, double *taps, int order);
int kfroma(double *taps, double *ref, int order);
void rfroma(double *a, int n, double *r);
double model_dist(double *ta, double *sa, int order);
int lud(double **a, int n, s32 *indx, s32 *d);
void lubksb(double **a, int n, s32 *indx, double b[]);
void acmat(short *in_buffer, int order, int length, double **a);
void acvect(short *in_buffer, int order, int length, double *a);

double model_dist_order2(double *ta, double *sa, int order);
void rfroma_order2(double *a, int n, double *r);

/* In codebook.c */
void split(double **codebook, double *dir, int order, int n_entries, double delta);
void refine(double **codebook, int order, int n_entries, double **training, int nframes,
            int iterations, double converge);


/* In Nxtabledesign.c */
void adpcmCoefTableDesign(
                              s16       *input,
                              u32       nsamples,
                              ADPCMINFO *coeftable
                              );

#endif // __TBDESIGN_H__
