/*--------------------------------------------------------------------------*
  Project: Revolution DSPADPCM dynamic link library
  File:    estimate.c

  Copyright (C)2001-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
  
  $Log: not supported by cvs2svn $
  Revision 1.1  2005/11/04 06:49:54  aka
  Imported from Dolphin tree.
    
    3     03/05/26 2:24p Akagi
    Modified to use MMX/SSE (by Ohki-san@NTSC).
  
 *--------------------------------------------------------------------------*/
#include "tbdesign.h"


/*--------------------------------------------------------------------------*/
void acf
(
    short   *sig,
    int     len,
    double  *ac,
    int     nlags
)
{
    int i, j;
    double m;

    // Calculate autocorrelation of a signal

    for (i = 0; i < nlags; i++)
    {
        m = 0;
    
        for (j = 0; j < len - i; j++)
            m = m + sig[j] * sig[j + i];
    
        ac[i] = m;
    }
}


/*--------------------------------------------------------------------------*/
int durbin
(
    double  *ac,
    int     order,
    double  *ref,
    double  *taps,
    double  *e2
)
{
    // Levinson-Durbin method for solving for the
    // Reflection coefficients from the autocorrelation coefficients.
    // Stability is checked. Return value is >0 if solution
    // is unstable. Tap values are also provided.
    
    int i, j;
    double e, m;
    int stable = 0;
    
    e = ac[0];

    taps[0] = 1.0; 

    for (i = 1; i <= order; i++ )
    {
        m = 0;
    
        for (j = 1; j < i; j++)
            m += taps[j] * ac[i - j];

        // Calculate reflection coefficient value - which is taps[i] in
        // this case.
        
        if (e > 0)
            taps[i] = -(ac[i] + m) / e;
        else 
            taps[i] = 0;

        ref[i] = taps[i];
        
        if (fabs(ref[i]) > 1.0)
            stable++;
            
        // Recalculate the tap values
        for (j = 1; j < i; j++)
            taps[j] = taps[j] + taps[i]*taps[i - j];
        
        // Calculate forward error after predictor
        e = (1 - taps[i] * taps[i]) * e;

    }

    *e2 = e;

    return stable;
}


/*--------------------------------------------------------------------------*/
void afromk
(
    double  *ref,
    double  *taps,
    int     order
)
{
    // Get the tap values from reflecion coefficients.
    int i, j;

    taps[0] = 1.0; 
    
    for (i = 1; i <= order; i++)
    {
        taps[i] = ref[i];
        
        // Recalculate the tap values
        for (j = 1; j < i; j++)
            taps[j] = taps[j] + taps[i] * taps[i - j];
        
    }
}


/*--------------------------------------------------------------------------*/
int kfroma
(
    double  *taps,
    double  *ref,
    int     order
)
{
    // Get the reflecion coefficients from the tap values.
    int     i, j;
    double  *tmp;
    int     stable = 0;
    double  den;
    
    tmp = (double *) malloc((order + 1) * sizeof(double));
    
    ref[order] = taps[order];
    
    for (i = order - 1; i > 0; i--)
    {
        for (j = 0; j <= i; j++)
        {
            den = 1 - ref[i + 1] * ref[i + 1];
            
            // Check here for unstable filter
            if (den == 0)
            {
                free(tmp);
                return 1;
            }

            tmp[j] = (taps[j] - ref[i + 1] * taps[i + 1 - j]) / den;
        }

        for (j = 0; j <= i; j++)
            taps[j] = tmp[j];

        ref[i] = tmp[i];

        if (fabs(ref[i]) > 1.0)
            stable++;
    }

    free(tmp);
    
    return stable;
}

// order =  2固定
void rfroma_order2
(
    double  *a,
    int     n,
    double  *r
)
{
    // Calculate the signal autocorrelation from the
    // model tap values. See Atal and Hanauer, Journal
    // of the Acoustical Society of America, Vol 50, 1971,
    // pp. 637-655.
    double  aa[3][3];

    aa[2][0] = 1.0;
        aa[2][1] = -a[1];
        aa[2][2] = -a[2];

        // コンパイラの最適化の影響を受けないようにするため括弧が必要
        aa[1][1] = (aa[2][1] + (aa[2][2] * aa[2][1])) / (1.0 - (aa[2][2] * aa[2][2]));


    // Now calculate the autocorrelation coefficients
    r[0] = 1.0;
        r[1] = aa[1][1] * r[0];
        r[2] = aa[2][1] * r[1] + aa[2][2] * r[0];
}

/*--------------------------------------------------------------------------*/
void rfroma
(
    double  *a,
    int     n,
    double  *r
)
{
    // Calculate the signal autocorrelation from the
    // model tap values. See Atal and Hanauer, Journal
    // of the Acoustical Society of America, Vol 50, 1971,
    // pp. 637-655.
    int     i, j;
    double  ref;
    double  aa[3][3];


    aa[n][0] = 1.0;

    for (i = 1; i <= n; i++)
        aa[n][i] = -a[i];
    
    for (i = n; i >= 1; i--)
    {
        ref = (1 - aa[i][i] * aa[i][i]);

        // Calculate the tap values for this i
        for (j = 1; j <= i - 1; j++)
            aa[i - 1][j] = (aa[i][j] + aa[i][i] * aa[i][i - j]) / ref;
    }
    
    // Now calculate the autocorrelation coefficients
    r[0] = 1.0;

    for (i = 1; i <= n; i++)
    {
        r[i] = 0;
    
        for (j = 1; j <= i; j++)
            r[i] += aa[i][j] * r[i - j];
    }
}

// order =  2固定
double model_dist_order2
(
    double  *ta,
    double  *sa,
    int     order
)
{
    // Calculate the normalized model distance
    // See, Gray, et al IEEE Transacations, ASSP-28, No. 4
    // Aug. 1980, pp. 367-376.
    double  r[3], ra[3], d;

    // Calculate signal autocorrelation coefficients from
    // model sa
   rfroma_order2(sa, order, r);


    // Calculate the coefficient autocorrelations from
    // model ta
        ra[0] = ta[0] * ta[0] + ta[1] * ta[1] + ta[2] * ta[2];
        ra[1] = ta[0] * ta[1] + ta[1] * ta[2];
        ra[2] = ta[0] * ta[2];


    // Model distance
    d = r[0] * ra[0] + 2.0 * r[1] * ra[1] + 2.0 * r[2] * ra[2];
    
    return d;
}

/*--------------------------------------------------------------------------*/
double model_dist
(
    double  *ta,
    double  *sa,
    int     order
)
{
    // Calculate the normalized model distance
    // See, Gray, et al IEEE Transacations, ASSP-28, No. 4
    // Aug. 1980, pp. 367-376.
    int     i, j;
    double  r[3], ra[3], d;

    // Calculate signal autocorrelation coefficients from
    // model sa
    rfroma(sa, order, r);

    // Calculate the coefficient autocorrelations from
    // model ta
    for (i = 0; i <= order; i++)
    {
        ra[i] = 0;
    
        for (j = 0; j <= order - i; j++)
            ra[i] += ta[j] * ta[j + i];
    }

    // Model distance
    d = r[0] * ra[0];
 
    for (i = 1; i <= order; i++)
        d += 2 * r[i] * ra[i];
    return d;
}


// Non Toeplitz autocorrelation matrix

/*--------------------------------------------------------------------------*/
void acmat
(
    short   *in_buffer,
    int     order,
    int     length,
    double  **a
)
{
    int i, j, n;

    for (i = 1; i <= order; i++)
    {
        for (j = 1; j <= order; j++)
        {
            a[i][j] = 0;
        
            for (n = 0; n < length; n++)
                a[i][j] += in_buffer[n - i] * in_buffer[n - j];
        }
    }
}


/*--------------------------------------------------------------------------*/
void acvect
(
    short   *in_buffer,
    int     order,
    int     length,
    double  *a
)
{
    int i, n;

    for (i = 0; i <= order; i++)
    {
        a[i] = 0;
    
        for (n = 0; n < length; n++)
            a[i] -= in_buffer[n - i] * in_buffer[n];
    }
}


/*--------------------------------------------------------------------------*/
int lud
(
    double  **a,
    int     n,
    s32     *indx,
    s32     *d
)
{
    int     i, imax, j, k;
    double  big, dum, sum, temp;
    double  *vv;
    double  mag, pmax, pmin;
    
    vv = (double *) malloc((n + 1) * sizeof(double)); 
    *d = 1;

    for (i = 1; i <= n; i++)
    {
        big = 0.0;
    
        for (j = 1; j <= n; j++)
            if ((temp=fabs(a[i][j])) > big)
                big = temp;
        
        if (big == 0.0)
            return 1;
        
        vv[i] = 1.0 / big;
    }

    for (j = 1; j <= n; j++)
    {
        for (i = 1; i < j; i++)
        {
            sum = a[i][j];
        
            for (k = 1; k < i; k++)
                sum -= a[i][k] * a[k][j];

            a[i][j] = sum;
        }

        big = 0.0;
        
        for (i = j; i <= n; i++)
        {
            sum = a[i][j];
        
            for (k = 1; k < j; k++)
                sum -= a[i][k] * a[k][j];

            a[i][j] = sum;        
            
            if ((dum = vv[i] * fabs(sum)) >= big)
            {
                big = dum;
                imax = i;
            }            
        }

        if (j != imax)
        {
            for (k = 1; k <= n; k++)
            {
                dum = a[imax][k];
                a[imax][k] = a[j][k];
                a[j][k] = dum;
            }

            *d = -(*d);
            vv[imax] = vv[j];
        }

        indx[j] = imax;
        
        if (a[j][j] == 0.0)
             // Matrix is singular
            return 1;

        if (j != n)
        {
            dum = 1.0 / a[j][j];
            
            for (i = j + 1; i <= n; i++)
                a[i][j] *= dum;
        }
    }

    free(vv);

    // Search for maximum and minimum magnitude pivots
    pmax = 0;
    pmin = 1 / TINY;

    for (j = 1; j <= n; j++)
    {
        mag = fabs(a[j][j]);
    
        if (mag < pmin)
            pmin = mag;
        if (mag > pmax)
            pmax = mag;
    }

    // Ad hoc singularity check. If the ratio
    // of pmin/pmax is less than TINY call it singular
    if (pmin / pmax < TINY)
        return 1;
    else
        return 0;
}


/*--------------------------------------------------------------------------*/
void lubksb
(
    double  **a,
    int     n,
    s32     *indx,
    double  b[]
)
{
    int     i, ii=0, ip, j;
    double  sum;

    for (i = 1; i <= n; i++)
    {
        ip = indx[i];
        sum = b[ip];
        b[ip] = b[i];
    
        if (ii)
            for (j = ii; j <= i - 1; j++)
                sum -= a[i][j] * b[j];
        else if (sum)
            ii = i;

        b[i] = sum;
    }

    for (i = n; i >= 1; i--)
    {
        sum = b[i];
    
        for (j = i + 1; j <= n; j++)
            sum -= a[i][j] * b[j];

        b[i] = sum / a[i][i];
    }
}
