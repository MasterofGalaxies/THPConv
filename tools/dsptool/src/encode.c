/*--------------------------------------------------------------------------*
  Project: Revolution DSPADPCM dynamic link library
  File:    encode.c

  Copyright (C)2003-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
  
  $Log: not supported by cvs2svn $
  Revision 1.1  2005/11/04 06:49:54  aka
  Imported from Dolphin tree.
    
    3     03/05/26 2:18p Akagi
    Modified to use MMX/SSE (by Ohki-san@NTSC).
    
 *--------------------------------------------------------------------------*/

#include "types.h"
#include "Nxadpcm.h"
#include "endian.h"
#include "dspadpcm.h"

#define  BUFFER_SIZE        1024
#define  ADPCM_BUFFER_SIZE  BYTES_PER_FRAME * BUFFER_SIZE
#define  PCM_BUFFER_SIZE    SAMPLES_PER_FRAME * BUFFER_SIZE
#define  ARAM_BUFFER_SIZE  BUFFER_SIZE * BYTES_PER_FRAME
#define  DMEM_BUFFER_SIZE  BUFFER_SIZE * SAMPLES_PER_FRAME

#define MMX_FLAG        0x00800000
#define SSE_FLAG        0x02000000


static int check_SSE(void)
{
        int     flag = 0;

        _asm {

                // EFLAGSのIDビットを変更できるか試してCPUID命令が使えるか調べる
                // i486以降であればつかえるが、i386は使えない。
                pushfd;
                pop                     eax;                            // eax = EFLAGS;
                xor                     eax, 00200000h;
                push            eax;
                popfd;
                pushfd;
                pop                     ebx;
                cmp                     eax, ebx;
                jne                     CHECK_END;                      // Not support CPUID

                // cpuidでeaxに指定できる最大値の取得
                mov                     eax, 0;
                cpuid;
                cmp                     eax, 1;                         // CPUIDにeax = 1が指定できるかどうかチェック
                jl                      CHECK_END;

                // Family/Model/Stepping/Featureの取得
                mov                     eax, 1;
                cpuid;
                // MMX/SSEのチェック
                test            edx, MMX_FLAG;          // Check MMX
                jz                      CHECK_END;
                test            edx, SSE_FLAG;          // Check SSE
                jz                      CHECK_END;
                mov                     flag, 1;
                
CHECK_END:              
        }
        return flag;
}


void
encodeLoop
(
    s16         *input_,
    u32         samples,
    u8          *dst,
    ADPCMINFO   *cxt
)
{
    int i,j,framecnt;
    u32 outoffset, inoffset, insize;
    u16 ps;
    s16 *pcmbuffer;
    u8  *adpcmbuffer;
//    u8  *arambuffer;
//    s16 *dmembuffer;
    s16 *input;
//    s16 *dest;
//    u32 count;
        u16 (*adpcmEncodeFrameFuncPtr)(s16*, u8*, s16*, u8);
        

    s16 *coeftable = (s16*)cxt;
        s16     coef[16];

        if(check_SSE()){
                adpcmEncodeFrameFuncPtr = adpcmEncodeFrame_SSE;
                for(i = 0; i < NUM_OF_COEFTABLE; i++){
                        coef[i * 2 + 0] = coeftable[i * 2 + 1];
                        coef[i * 2 + 1] = coeftable[i * 2 + 0];
                }
                coeftable = coef;
        } else {
                adpcmEncodeFrameFuncPtr = adpcmEncodeFrame;
        }

    adpcmbuffer     = (u8*)        malloc(ADPCM_BUFFER_SIZE + BYTES_PER_FRAME);
    pcmbuffer       = (s16*)       malloc((PCM_BUFFER_SIZE+ORDER*MAX_CHANNELS)*sizeof(s16));
    //arambuffer      = (u8*)        malloc(ARAM_BUFFER_SIZE * sizeof(u8));
    //dmembuffer      = (s16*)       malloc((DMEM_BUFFER_SIZE+ORDER*MAX_CHANNELS)*sizeof(s16));
    
    input = input_;

    for ( i = 0 ; i < ORDER ; ++i )
        pcmbuffer[i + PCM_BUFFER_SIZE] = 0;

    framecnt = 0;

    while(samples > 0)
    {
        outoffset = 0;
        
        // Move last samples to head
        for ( i = 0 ; i < ORDER; i++ )
            pcmbuffer[i] = pcmbuffer[i + PCM_BUFFER_SIZE];
        
        // Read PCM data from input file
        if (samples > PCM_BUFFER_SIZE )
        {
            insize = PCM_BUFFER_SIZE;
            samples -= PCM_BUFFER_SIZE;
        }
        else
        {
            insize = samples;
        
            for ( j = 0 ; j < SAMPLES_PER_FRAME ; ++j )
            {
                if ( insize + j >= PCM_BUFFER_SIZE )
                    break;
            
                pcmbuffer[ORDER + insize + j] = 0;
            }
            
            samples = 0;
        }

//        fread(pcmbuffer+ORDER, insize, sizeof(s16), input_handle);
                
        {
            s16 *p;
            u32 i;

            p = pcmbuffer+ORDER;

            for (i = 0; i < insize; i++)
            {
                *p = *input;
                input++;
                p++;
            }
        }

        inoffset = 0;
        
        // Encoding Loop
        while ( inoffset < insize )
        {
            ps = adpcmEncodeFrameFuncPtr(
                        pcmbuffer + inoffset,
                        adpcmbuffer + outoffset,
                        coeftable,
                        1
                        );
            outoffset += BYTES_PER_FRAME;
            inoffset  += SAMPLES_PER_FRAME;
            
            if (framecnt == 0)
                cxt->pred_scale = ps;

            ++framecnt;
        }

        // Write output adpcm samples into file
//        fwrite(adpcmbuffer, outoffset, sizeof(u8), output_handle);
        
        {
            u8 *p;
            u32 zz;

            p = adpcmbuffer;
            zz = outoffset;

            while (zz)
            {
                *dst = *p;

                dst++;
                p++;
                zz--;
            }
        }
    }


    free(pcmbuffer);
    free(adpcmbuffer);

    
    return;

} // end encodeLoop()
