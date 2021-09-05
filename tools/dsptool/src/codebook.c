/*--------------------------------------------------------------------------*
  Project: Revolution DSPADPCM dynamic link library
  File:    codebook.c

  Copyright (C)2001-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
  
  $Log: not supported by cvs2svn $
  Revision 1.1  2005/11/04 06:49:54  aka
  Imported from Dolphin tree.
    
    2     03/05/26 1:44p Akagi
    Modified to use MMX/SSE (by Ohki-san@NTSC).
  
 *--------------------------------------------------------------------------*/
#include "tbdesign.h"


/*--------------------------------------------------------------------------*/
void split
(
    double  **codebook,
    double  *dir,
    int     order,
    int     n_entries,
    double  delta
)
{
    // Double the size of the codebook by splitting each entry
    // along the direction 'dir'
    int i, j;

    for (i = 0; i < n_entries; i++)
        for (j = 0; j <= order; j++)
            codebook[i + n_entries][j] = codebook[i][j] + delta * dir[j];
}


/*--------------------------------------------------------------------------*/
void refine
(
    double  **codebook,
    int     order,
    int     n_entries,
    double  **training,
    int     nframes,
    int     iterations,
    double  converge
)
{
    // Standard Lloyd algorithm for iterative refinement of the codebook
    int     i, j, tv, iter, ne;
    int     *count;
    double  **centroids;
    double  *ac;
    double  e2, min, dist;
    
    centroids = (double **) malloc(n_entries * sizeof(double *));

    for (i = 0; i < n_entries; i++)
        centroids[i] = (double *) malloc((order + 1) * sizeof(double));

    count   = (int *) malloc(n_entries * sizeof(int));
    ac      = (double *) malloc((order+1) * sizeof(double));
    
    for (iter = 0; iter < iterations; iter++)
    {
        // Go through each training vector and find the nearest neighbour
        for (j = 0; j < n_entries; j++)
        {
            count[j] = 0;

            for (i = 0; i <= order; i++)
                centroids[j][i] = 0.0;
        }
        
        
        for (tv = 0; tv < nframes; tv++)
        {
            ne  = 0;
            min = 1e30;
            
            for (i = 0; i < n_entries; i++)
            {
#if 0
                dist = model_dist(codebook[i], training[tv], order);
#else
                dist = model_dist_order2(codebook[i], training[tv], order);
#endif
            
                if (dist<min)
                {
                    min = dist;
                    ne = i;
                }
            }

            // Add the autocorrelation of this training vector to the centroid
            count[ne] += 1;
            
            rfroma(training[tv], order, ac);
            
            for (i = 0; i <= order; i++)
                centroids[ne][i] += ac[i];
        }

        // Get the average
        for (i = 0; i < n_entries; i++)
            if (count[i] > 0)
                for (j = 0; j <= order; j++)
                    centroids[i][j] = centroids[i][j] / count[i];

        // Redefine the codebook
        for (i = 0; i < n_entries; i++)
        {
            durbin(centroids[i], order, ac, codebook[i], &e2);

            // Stabilize - could put this in durbin
            for (j = 1; j <= order; j++)
            {
                if (ac[j] >= 1.0)
                    ac[j] = 1.0 - TINY;

                if (ac[j] <= -1.0)
                    ac[j] = -1.0 + TINY;
            }

            afromk(ac, codebook[i], order);
        }
                
    }

    free(count);
    
    for (i = 0; i < n_entries; i++)
        free(centroids[i]);

    free(centroids);
    free(ac);
}
