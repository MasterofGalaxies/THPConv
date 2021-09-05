/*--------------------------------------------------------------------------*
  Project: Revolution DSPADPCM dynamic link library
  File:    encframe.c

  Copyright (C)2001-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
  
  $Log: not supported by cvs2svn $
  Revision 1.2  2006/02/09 06:13:46  aka
  Changed copyright.

  Revision 1.1  2005/11/04 06:49:54  aka
  Imported from Dolphin tree.
    
    2     03/05/26 2:09p Akagi
    Modified to use MMX/SSE (by Ohki-san@NTSC).
    
 *--------------------------------------------------------------------------*/
#include <stdio.h>
#include "Nxadpcm.h"


/*--------------------------------------------------------------------------*/
u16 adpcmEncodeFrame(s16 *inbuffer, u8 *outbuffer, s16 *coeftable, u8 step)
{
    int i, j, k, opt, scale, optscale;
    double err, e, min, qf;
    s32 prediction[NUM_OF_COEFTABLE][SAMPLES_PER_FRAME + ORDER];
    s32 diff[SAMPLES_PER_FRAME];
    s32 quantum[NUM_OF_COEFTABLE][SAMPLES_PER_FRAME];
    s32 maxdiff, maxclip;

    u16 ps;


        min       = 1e30;
        opt       = 0;
        optscale  = 0;

        for (i = 0; i < NUM_OF_COEFTABLE; ++i)
        {
            for (k = 0; k < ORDER; ++k)
            {
                prediction[i][k] = (s32)(inbuffer[k * step]);
            }

            // Find the prediction error from predictor.
            for (j = 0; j < SAMPLES_PER_FRAME; ++j)
            {
                prediction[i][j+ORDER] = 0;
          
                for (k = 0; k < ORDER; ++k)
                {
                    prediction[i][j+ORDER] += (s32)inbuffer[(j+ORDER-k-1)*step] * (s32)coeftable[i*ORDER+k];
                }
          
                prediction[i][j+ORDER] /= COEF_SCALING;
          
                diff[j] = (s32)inbuffer[(j+ORDER)*step] - prediction[i][j+ORDER];

                if (diff[j] > 32767)
                    diff[j] = 32767;
                if (diff[j] < -32768)
                    diff[j] = -32768;
            }

       
            // Find initial range value
            maxdiff = 0;
    
            for (j = 0; j < SAMPLES_PER_FRAME; ++j)
                if (abs(diff[j]) > abs(maxdiff))
                    maxdiff = diff[j];

            for (scale = 0; scale <= MAX_SCALE; ++scale)
            {
          
                if ((maxdiff <= 7) && (maxdiff >= -8))
                    break;
          
                maxdiff /= 2;
            }

            // Prediction error with a quantizer in the loop
            scale -= 2;
        
            if (scale < -1)
                scale = -1;
      
            do
            {
                ++scale;
                maxclip = 0;
                err = 0;

                for (j = 0; j < SAMPLES_PER_FRAME; ++j)
                {
                    prediction[i][j+ORDER] = 0;
              
                    for (k = 0; k < ORDER; ++k)
                        prediction[i][j + ORDER] += (s32)prediction[i][j + ORDER - k - 1]
                                                    * (s32)(coeftable[i * ORDER + k]);
                    diff[j] = (s32)(inbuffer[(j + ORDER) * step]) * COEF_SCALING - prediction[i][j + ORDER];

                    // quantize
                    qf = (float)diff[j] / (float)((1 << scale) * COEF_SCALING);

                    if (diff[j] > 0)
                        quantum[i][j] = (s32)(qf + 0.4999999);
                    else
                        quantum[i][j] = (s32)(qf - 0.4999999);
          
                    // Clipping check      
                    if (quantum[i][j] < -8)
                    {
                        if (maxclip < -8 - quantum[i][j])
                            maxclip = -8 - quantum[i][j];
                  
                        quantum[i][j] = -8;
                    }
          
                    if (quantum[i][j] > 7)
                    {
                        if (maxclip < quantum[i][j] - 7)
                            maxclip = quantum[i][j] - 7;
                  
                        quantum[i][j] = 7;
                    }
          
                    prediction[i][j + ORDER] += quantum[i][j] * (1 << scale) * COEF_SCALING;
              
                    // rounding and cut off
                    prediction[i][j + ORDER] += ( COEF_SCALING >> 1 );
                    prediction[i][j + ORDER] >>= COEF_SCALING_BIT;

                    // clamping
                    if (prediction[i][j + ORDER] > 32767)
                        prediction[i][j + ORDER] = 32767;
                    if (prediction[i][j + ORDER] < -32768)
                        prediction[i][j + ORDER] = -32768;
              
                    e = (double)((s32)(inbuffer[(j + ORDER) * step]) - prediction[i][j + ORDER]); 
                    err += e * e;
                  //printf("0x%08X[0x%08X] ", diff[j], prediction[i][j+ORDER]);  // Debug
                }
          
                // for reducing processing time
                k = maxclip + 8;
            
                while( k > 256 )
                {
                    k >>= 1;
                    ++scale;
              
                    if (scale >= MAX_SCALE)
                        scale = MAX_SCALE - 1;
                }
          
              //printf("\n");  // Debug
            } while((scale < MAX_SCALE) && ( maxclip > MAX_CLIP )); 

            if (err < min)
            {
                opt      = i;
                min      = err;
                optscale = scale;
            }   
          //printf("Index %d : error = %e\n", i, err); // Debug

        }

#ifdef DEBUGMSG
      printf("Opt. Index = %d  error = %e  scale = %d\n", opt, min, scale); // Debug
#endif

        // Write back calculated PCM data to input buffer
        for (j = 0; j < SAMPLES_PER_FRAME; ++j)
        {
            inbuffer[(j + ORDER) * step] = (s16)(prediction[opt][j + ORDER]);
        }


        // Write header and bitstream into output buffer
        *outbuffer = (opt << 4) | (optscale & 0x0F);
        ps = *outbuffer;

        //printf("%02X ", *outbuffer);  // Debug
        ++outbuffer;
  
        for (i = 0; i < SAMPLES_PER_FRAME; i += 2)
        {
            *outbuffer = ((quantum[opt][i] & 0x0F) << 4) | (quantum[opt][i + 1] & 0x0F);
            //printf("%02X ", *outbuffer);  // Debug
            ++outbuffer;
        }

        //printf("\n");
        return(ps);
}

// SSEÇ∆MMXÇégÇ¡ÇΩçÇë¨î≈
u16 adpcmEncodeFrame_SSE(s16 *inbuffer, u8 *outbuffer, s16 *coeftable, u8 step)
{
    int i, j, k, opt, scale, optscale;
    double err, e, min;
    s32 prediction[NUM_OF_COEFTABLE][SAMPLES_PER_FRAME + ORDER];
    s32 diff[SAMPLES_PER_FRAME];
    s32 quantum[NUM_OF_COEFTABLE][SAMPLES_PER_FRAME];
    s32 maxdiff, maxclip;
    u16 ps;     

        min       = 1e30;
        opt       = 0;
        optscale  = 0;


        for (i = 0; i < NUM_OF_COEFTABLE; ++i)
        {

                prediction[i][0] = (s32)(inbuffer[0]);
                prediction[i][1] = (s32)(inbuffer[1]);

                {
                        s32*    predict = &prediction[i][ORDER];
                        s16*    inbuff  = &inbuffer[0];
                        s16*    coef    = &coeftable[i * ORDER];
                        s32     min;
                        s32 max;
                        __asm {

                    // Find the prediction error from predictor.
                                xor                     esi, esi;
                                pxor            mm0, mm0;
                                lea                     eax, diff;
                                mov                     ebx, [inbuff];
                                mov                     ecx, [predict];
                                mov                     edx, [coef];
                                movd            mm4, qword ptr [edx];                   // mm1 = coef+0, coef+1
                                pshufw          mm4, mm4, 0x44;                                 // 0b0100 0100

LOOP1:
                                movq            mm2, qword ptr [ebx + esi * 2];                 // mm2 = inbuff+0 , inbuff+1
                                pshufw          mm2, mm2, 0x94;                                         // 0b1001 0100;
                                pmaddwd         mm2, mm4;
                                
                                movq            mm3, mm2;
                                psrad           mm3, 32;
                                psrld           mm3, 21;
                                paddd           mm2, mm3;
                                psrad           mm2, 11;                                                // predict/COEF_SCALING
                                movq            qword ptr [ecx + esi * 4], mm2; //

                                movd            mm1, dword ptr [ebx + esi * 2 + 4];
                                punpcklwd       mm1, mm0;                                               // mm1 = inbuffer[j]
                                pslld           mm1, 16;                                                // mm1 << 16
                                psrad           mm1, 16;                                                // mm1 >> 16 ïÑçÜägí£
                                psubd           mm1, mm2;                                               // mm1 = inbuffer - prediction
                                packssdw        mm1, mm1;                                               // 32bit->16bit(ñOòaÇ†ÇË)
                                punpcklwd       mm1, mm0;                                               // 16bit->32bit
                                pslld           mm1, 16;                                                // mm1 << 16
                                psrad           mm1, 16;                                                // mm1 >> 16 ïÑçÜägí£
                                movq            qword ptr [eax + esi * 4], mm1; // diff[j] <- mm1
                                add                     esi, 2;
                                cmp                     esi, SAMPLES_PER_FRAME;
                                jl                      LOOP1;

                        // Find initial range value
                                xor                     esi, esi;
                                pxor            mm2, mm2;
                                pxor            mm3, mm3;
LOOP2:
                                movq            mm1, qword ptr [eax + esi];             // mm1 = diff
                                packssdw        mm1, mm1;                                               // 32bit->16bit(ñOòaÇ†ÇË)
                                pminsw          mm2, mm1;                                               // mm2 = min(diff[i], diff[i+1])
                                pmaxsw          mm3, mm1;                                               // mm3 = max(diff[i], diff[i+1])
                                add                     esi, 8;
                                cmp                     esi, SAMPLES_PER_FRAME * 4;
                                jl                      LOOP2;

                                pshufw          mm4, mm2, 1;
                                pminsw          mm2, mm4;
                                pshufw          mm5, mm3, 1;
                                pmaxsw          mm3, mm5;

                                pslld           mm2, 16;
                                psrad           mm2, 16;                                                // ïÑçÜägí£
                                pslld           mm3, 16;
                                psrad           mm3, 16;                                                // ïÑçÜägí£

                                movd            dword ptr [min], mm2;
                                movd            dword ptr [max], mm3;
                                emms;                                                                           // END of use MMX
                        }
                        if(abs(min) > abs(max)){
                                maxdiff = min;
                        } else {
                                maxdiff = max;
                        }
                }

                for (scale = 0; scale <= MAX_SCALE; ++scale)
                {
                        if ((maxdiff <= 7) && (maxdiff >= -8))
                                break;
                        maxdiff /= 2;
                }
                scale -= 2;
                
                if (scale < -1)
                        scale = -1;
                
                do
                {
                        ++scale;
                        maxclip = 0;
                        err = 0;

                        for (j = 0; j < SAMPLES_PER_FRAME; ++j)
                        {
                                prediction[i][j + ORDER] = 
                                        (s32)prediction[i][j + 1] * (s32)(coeftable[i * ORDER + 1])
                                        + (s32)prediction[i][j + 0] * (s32)(coeftable[i * ORDER + 0]);
                                
                                diff[j] = (s32)(inbuffer[(j + ORDER)]) * COEF_SCALING - prediction[i][j + ORDER];
#if 0
                                diff[j] /= COEF_SCALING;
                                
                                // quantize
                                qf = (float)diff[j] / (float)(1 << scale);
                                
                                if (diff[j] > 0)
                                        quantum[i][j] = (s32)(qf + 0.4999999);
                                else
                                        quantum[i][j] = (s32)(qf - 0.4999999);
#else
                                {
                                        s32 signflag;
                                        s32 intdiff;

                                        signflag = (1 << ((scale + 11) - 1)) - 1;
                                        
                                        if(diff[j] > 0){
                                                intdiff = (diff[j] + signflag) >>  (scale + 11);
                                        } else {
                                                intdiff =  -((-diff[j] + signflag) >> (scale + 11));
                                        }
                                        
                                        quantum[i][j] = intdiff;
                                }
#endif
                                
                                // Clipping check      
                                if (quantum[i][j] < -8)
                                {
                                        if (maxclip < -8 - quantum[i][j])
                                                maxclip = -8 - quantum[i][j];
                                        
                                        quantum[i][j] = -8;
                                }
                                else if (quantum[i][j] > 7)
                                {
                                        if (maxclip < quantum[i][j] - 7)
                                                maxclip = quantum[i][j] - 7;
                                        
                                        quantum[i][j] = 7;
                                }
                                
                                prediction[i][j + ORDER] += quantum[i][j] * (1 << scale) * COEF_SCALING;
                                
                                // rounding and cut off
                                prediction[i][j + ORDER] += ( COEF_SCALING >> 1 );
                                prediction[i][j + ORDER] >>= COEF_SCALING_BIT;
                                
                                // clamping
                                if (prediction[i][j + ORDER] > 32767){
                                        prediction[i][j + ORDER] = 32767;
                                } 
                                else if (prediction[i][j + ORDER] < -32768)
                                {
                                        prediction[i][j + ORDER] = -32768;
                                }
                                
                                e = (double)((s32)(inbuffer[(j + ORDER)]) - prediction[i][j + ORDER]); 
                                err += e * e;
                                //printf("0x%08X[0x%08X] ", diff[j], prediction[i][j+ORDER]);  // Debug
                        }


                        // for reducing processing time
                        k = maxclip + 8;

                        while( k > 256 )
                        {
                                k >>= 1;
                                ++scale;
                                if (scale >= MAX_SCALE)
                                        scale = MAX_SCALE - 1;
                        }
                        
                        //printf("\n");  // Debug
                } while((scale < MAX_SCALE) && ( maxclip > MAX_CLIP )); 
                
                if (err < min)
                {
                        opt      = i;
                        min      = err;
                        optscale = scale;
                }
                //printf("Index %d : error = %e\n", i, err); // Debug
        }
        
#ifdef DEBUGMSG
        printf("Opt. Index = %d  error = %e  scale = %d\n", opt, min, scale); // Debug
#endif
        
        
        // Write back calculated PCM data to input buffer
        for (j = 0; j < SAMPLES_PER_FRAME; ++j)
        {
                inbuffer[(j + ORDER)] = (s16)(prediction[opt][j + ORDER]);
        }
        
        
        // Write header and bitstream into output buffer
        *outbuffer = (opt << 4) | (optscale & 0x0F);
        ps = *outbuffer;
        
        //printf("%02X ", *outbuffer);  // Debug
        ++outbuffer;
        
        for (i = 0; i < SAMPLES_PER_FRAME; i += 2)
        {
                *outbuffer = ((quantum[opt][i] & 0x0F) << 4) | (quantum[opt][i + 1] & 0x0F);
                //printf("%02X ", *outbuffer);  // Debug
                ++outbuffer;
        }
        
        //printf("\n");
        return(ps);
}
