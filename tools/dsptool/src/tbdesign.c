/*---------------------------------------------------------------------------*
  Project: Revolution DSPADPCM dynamic link library
  File:    tbdesign.c

  Copyright (C)1998-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  
 *---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "Nxadpcm.h"
#include "tbdesign.h"
#include "endian.h"
#include "types.h"

#define  IN_BUFFER_SIZE   1024

/*--------------------------------------------------------------------------*/
void adpcmCoefTableDesign
(
    s16         *input_,
    u32         nsamples,
    ADPCMINFO   *cxt
)
{
    double  thresh          = 10.0;
    int     order           = ORDER;
    int     refine_iter     = 2;
    int     frame_size      = SAMPLES_PER_FRAME;
    int     log2_tablesize;
    int     inoffset, insize;
    s16     *calc_buffer, *in_buffer;
    double  *ac, *ref, e2, **a, coef;
    double  **codebook, **training;
    double  *dir;
    
    s32 nframes, aframecnt, framecnt, samplecnt;
    s32 i, j, d;
    s32 actual_size, n_entries;
    s32 *indx;
    s32 overflow = 0;

    s16 *input = input_;
    s16 *inputBuffer;

    s16 *coeftable = (u16*)cxt;

    nframes = ( nsamples + frame_size - 1 ) / frame_size;

    for (log2_tablesize = 1; (1 << log2_tablesize) < 8; ++log2_tablesize)
      {}

    // Initialize codebook storage
    codebook = (double **) malloc((1 << log2_tablesize) * sizeof(double *));

    for (i = 0; i < (1 << log2_tablesize); i++)
        codebook[i] = (double *) malloc((order + 1) * sizeof(double));
    
    // Splitting direction
    dir = (double *) malloc((order + 1) * sizeof(double));

    in_buffer = (s16 *)malloc(IN_BUFFER_SIZE * frame_size * sizeof(s16));
    
    calc_buffer = (s16 *) malloc(2 * frame_size * sizeof(s16));

    for (i = 0; i < 2 * frame_size; i++)
        calc_buffer[i] = 0;

    ac  = (double *) malloc((order + 1) * sizeof(double));
    ref = (double *) malloc((order + 1) * sizeof(double));
    
    // For matrix method
    a = (double **) malloc((order + 1) * sizeof(double *));

    for (i = 0; i <= order; i++)
        *(a+i) = (double *) malloc((order + 1) * sizeof(double));

    indx = (s32 *) malloc((order + 1) * sizeof(s32));

    // Reserve storage for the training data
    training  = (double **) malloc(nframes * sizeof(double *));
    framecnt  = 0;
    aframecnt = 0;  // active frame counter
    samplecnt = nsamples;
    
//    printf("Nframes = %d\n", nframes);
    
    while(samplecnt > 0)
    {
      
        // Read PCM data from input file
        if (samplecnt > IN_BUFFER_SIZE * frame_size)
        {
            insize      =   IN_BUFFER_SIZE * frame_size;
            samplecnt   -=  IN_BUFFER_SIZE * frame_size;
        }
        else
        {
            insize = samplecnt;
        
            for (i = 0; i < frame_size; ++i)
            {
                if (insize + i >= IN_BUFFER_SIZE * frame_size )
                    break;
                
                in_buffer[insize + i] = 0;
            }
            
            samplecnt = 0;
        }

//        fread(in_buffer, insize, sizeof(s16), infile);
  
        inputBuffer = in_buffer;

        for (i = 0; i < insize; i++)
        {
            *inputBuffer = *input;
            inputBuffer++;
            input++;
        }

        inoffset = 0;

        // Statistic data sampling Loop
        while (inoffset < insize)
        {        
            // Set up samples for calculation
            for (i = 0; i < frame_size; ++i)
              calc_buffer[i] = calc_buffer[i + frame_size];

            for (i = 0; i < frame_size; ++i)
            {
                calc_buffer[frame_size + i] = in_buffer[inoffset];
                inoffset ++;
            }

            //printf("Frame no. %d  ",framecnt); // Debug
            acvect(calc_buffer+frame_size, order, frame_size, ac);

            if (fabs(ac[0]) > thresh)
            {
                acmat(calc_buffer + frame_size, order, frame_size, a);

                // Lower-upper decomposition
                if (lud(a, order, indx, &d) == 0)
                {
                    // Put solution in ac
                    lubksb(a, order, indx, ac);
                    ac[0] = 1.0;

                    // Convert to reflection coefficients - reject unstable vectors
                    if (!kfroma(ac, ref, order))
                    {
                        // The training data is stored as tap values
                        training[aframecnt] = (double *) malloc((order + 1) * sizeof(double));

                        training[aframecnt][0] = 1.0;

                        for (i = 1; i <= order; i++)
                        {
                            //Stabilize the filter

                            if (ref[i] >= 1.0)
                              ref[i] = 1.0 - TINY;
                            
                            if (ref[i] <= -1.0)
                              ref[i] = -1.0 + TINY;
                        }
                        
                        afromk(ref, training[aframecnt], order);
                    
                        //printf("a1:%f  a2:%f ", training[aframecnt][1], training[aframecnt][2]); // Debug
                        ++aframecnt;
                    }

                }  // if (lud(a, order, indx, &d)==0)

            }  // if (fabs(ac[0]) > thresh)

            ++framecnt;
            //printf("\n");  // Debug

        }  // while ( inoffset < insize )
    }  // while( samplecnt > 0 )
    
//    printf("Available frames = %d\n", aframecnt);

    // To start things off find the average auto-correlation over
    // the complete data set.
    ac[0] = 1.0;

    for (j = 1; j <= order; j++)
        ac[j] = 0;
    
    for (i = 0; i < aframecnt; i++)
    {
        rfroma(training[i], order, codebook[0]);

        for (j = 1; j <= order; j++)
            ac[j] += codebook[0][j];
    }

    for (j = 1; j <= order; j++)
        ac[j] = ac[j] / aframecnt;

    // The average model
    durbin(ac, order, ref, codebook[0], &e2);

    // Stabilize - could put this in durbin
    for (j = 1; j <= order; j++)
    {
        if (ref[j] >= 1.0)
            ref[j] = 1.0 - TINY;

        if (ref[j] <= -1.0)
            ref[j] = -1.0 + TINY;
    }

    afromk(ref, codebook[0], order);
    
    //printf("Av.  a1:%f  a2:%f\n", codebook[0][1], codebook[0][2]); // Debug 
        
    actual_size = 0;
    
    while (actual_size < log2_tablesize)
    {
        n_entries = 1<<actual_size;
        
        // Split each codebook template into
        // two - the original and a shifted version
        for (i = 0; i <= order; i++)
            dir[i] = 0;
        
        dir[order - 1] = -1.0;
        
        split(codebook, dir, order, n_entries, 0.01);

        // Iterative refinement of templates
        actual_size++;
        refine(codebook, order, 1 << actual_size, training, aframecnt, refine_iter, 0);
    }

    n_entries = 1 << actual_size;
    
    // Let's see what it looks like
//    fprintf(stdout,"order = %d  entry = %d\n",order,n_entries);
    
    for (i = 0; i < n_entries; i++)
    {
//        printf("Predictor %d : ", i);
    
        for (j = 0; j < order; ++j)
        {
            coef = - codebook[i][j + 1] * COEF_SCALING;
            
            if (coef > 0)
            {
                if (coef > 32767)
                  coeftable[i * ORDER + j] = 32767;
                else
                  coeftable[i * ORDER + j] = (s16)(coef + 0.5);
            }
            else
            {
                if (coef < -32768)
                  coeftable[i * ORDER + j] = -32768;
                else
                  coeftable[i * ORDER + j] = (s16)(coef - 0.5);
            }
            
//            printf("a%d = %f[0x%04X] ", j + 1, -codebook[i][j+1], coeftable[i*ORDER+j]);
        }

//        printf("\n");
    }
        
    
    // Free working memories
    for (i = 0; i < (1 << log2_tablesize); ++i)
      free(codebook[i]);

    for (i = 0; i < aframecnt; ++i)
      free(training[i]);
    
    for (i = 0; i <= order; i++)
      free(a[i]);

    free(codebook);
    free(training);
    free(a);
    free(in_buffer);
    free(calc_buffer);
    free(ac);
    free(ref);
    free(dir);
    free(indx);
    
  return;
}
