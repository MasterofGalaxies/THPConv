/*---------------------------------------------------------------------------*
  Project: Revolution DSPADPCM dynamic link library
  File:    dspadpcm.c

  Copyright (C)1998-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  
 *---------------------------------------------------------------------------*/
#include <windows.h>
#include "types.h"
#include "dspadpcm.h"
#include "tbdesign.h"
#include "endian.h"
#include "encode.h"
#include "Nxadpcm.h"

/*---------------------------------------------------------------------------*
    DLL entry point
 *---------------------------------------------------------------------------*/
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
                                         )
{
    return TRUE;
}


/*---------------------------------------------------------------------------*
    return the number of bytes to allocate for PCM buffer to encode to ADPCM 
 *---------------------------------------------------------------------------*/
u32 getBytesForPcmBuffer(u32 samples)
{
    u32 frames = samples / 14;

    if (samples % 14)
        frames ++;

    return frames * 14 * 2;
}



/*---------------------------------------------------------------------------*
    return the number of bytes of actual PCM buffer for n samples
 *---------------------------------------------------------------------------*/
u32 getBytesForPcmSamples(u32 samples)
{
    return samples * 2;
}


/*---------------------------------------------------------------------------*
    return the number of bytes needed to encode specified number of samples
 *---------------------------------------------------------------------------*/
u32 getBytesForAdpcmBuffer(u32 samples)
{
    u32 frames = samples / 14;

    if (samples % 14)
        frames++;
    
    return (frames * 8);
}


/*---------------------------------------------------------------------------*
    return the number of bytes of actual ADPCM buffer for n samples
 *---------------------------------------------------------------------------*/
u32 getBytesForAdpcmSamples(u32 samples)
{
    u32 frames;
    u32 samplesLeft;

    frames      = samples / 14;
    samplesLeft = samples % 14;

    if (samplesLeft)
    {
        ULONG additionalBytes;

        additionalBytes = 1;                // 1 byte frame header
        additionalBytes += samplesLeft / 2; // number of even bytes

        if (samplesLeft % 2)                // 1 nibble left
            additionalBytes++;

        return (frames * 8) + additionalBytes; 
    }
    
    return (frames * 8);
}


/*---------------------------------------------------------------------------*
    return the sample number for adpcm nibble address
 *---------------------------------------------------------------------------*/
u32 getSampleForAdpcmNibble(u32 nibble)
{
        u32 frames;
        u32 nibblesLeft;

        frames          = nibble / 16;
        nibblesLeft = nibble % 16;

        return (frames * 14) + (nibblesLeft - 2);
}


/*---------------------------------------------------------------------------*
    return the number of bytes needed to encode specified number of samples
 *---------------------------------------------------------------------------*/
u32 getBytesForAdpcmInfo(void)
{
    return sizeof(ADPCMINFO);
}


/*---------------------------------------------------------------------------*
    return the nibble address for number of ADPCM samples
 *---------------------------------------------------------------------------*/
u32 getNibbleAddress(u32 samples)
{
    u32 frames;
    u32 samplesLeft;

    frames      = samples / 14;
    samplesLeft = samples % 14;

    return (frames * 16) + 2 + samplesLeft;
}


/*---------------------------------------------------------------------------*
    return the number of nibbles for n samples (includeing ADPCM header)
 *---------------------------------------------------------------------------*/
u32 getNibblesForNSamples(u32 samples)
{
    u32 frames;
    u32 samplesLeft;

    frames      = samples / 14;
    samplesLeft = samples % 14;

    if (samplesLeft)
        return (frames * 16) + samplesLeft + 2;

    return frames * 16;
}


/*---------------------------------------------------------------------------*
    encode ADPCM to user allocated buffers
 *---------------------------------------------------------------------------*/
void encode
(
    s16         *src,   // location of source samples (16bit PCM signed little endian)
    u8          *dst,   // location of destination buffer
    ADPCMINFO   *cxt,   // location of adpcm info
    u32         samples // number of samples to encode         
)
{
    adpcmCoefTableDesign(
        src,
        samples,
        cxt
        );

    encodeLoop(
        src,
        samples,
        dst,
        cxt
        );

    cxt->gain       = 0;
    cxt->pred_scale = *dst;
    cxt->yn1        = 0;
    cxt->yn2        = 0;

    return;
}


/*---------------------------------------------------------------------------*
    decode ADPCM sample to user specified buffer
 *---------------------------------------------------------------------------*/
void decode
(
    u8          *src,       // location of ADPCM buffer in RAM
    s16         *dst,       // location of destination buffer
    ADPCMINFO   *cxt,       // location of adpcminfo
    u32         samples     // samples to desired context
)
{
    u8  *p;
    s16 *output;
    s16 yn1, yn2;
    u32 decodedSamples;

    if (samples == 0)
        return;

    // initialize decoder 
    decodedSamples  = 0;
    yn1             = 0;
    yn2             = 0;

    p       = src;
    output  = dst;

    while (1)
    {
        int i;
        s16 nibble[SAMPLES_PER_FRAME];                 
        s16 gain, ci;       // coef index
        u8  ps;

        // frame header
        ps      = *p;
        p++;

        gain    = 1 << (ps & 0x0F);
        ci      = ps >> 4;

        for (i = 0; i < SAMPLES_PER_FRAME; i += 2)
        {
            nibble[i]       = (s16)(*p >> 4);
            nibble[i + 1]   = (s16)(*p & 0x0F);
            p++;
        }

        // fix negative value
        for (i = 0; i < SAMPLES_PER_FRAME ; i++)
            if (nibble[i] >= MAX_LEVEL)
                nibble[i] = nibble[i] - MAX_LEVEL * 2;

        // decode the samples
        for (i = 0 ; i < SAMPLES_PER_FRAME; i++)
        {
            s32 mac = (s32)nibble[i] * (s32)gain * COEF_SCALING;

            mac += (s32)yn1 * (s32)cxt->coef[ci * ORDER];
            mac += (s32)yn2 * (s32)cxt->coef[ci * ORDER + 1];

            // rounding and cut off
            mac += (COEF_SCALING >> 1);
            mac >>= COEF_SCALING_BIT;

            // clamping
            if (mac > 32767)    mac = 32767;
            if (mac < -32768)   mac = -32768;

            decodedSamples++;
            
            if(decodedSamples == samples)
                return;
            else
                *output = (s16)mac;

                        output++;

            yn2 = yn1;
            yn1 = (s16)mac;
        }
    }
}


/*---------------------------------------------------------------------------*
    get loop context at specified sample
 *---------------------------------------------------------------------------*/
void getLoopContext
(
    u8          *src,      // location of ADPCM buffer in RAM
    ADPCMINFO   *cxt,      // location of adpcminfo
    u32         samples    // samples to desired context
)
{
    u8  *p;
    s16 yn1, yn2;
    u32 decodedSamples;

    // initialize decoder 
    decodedSamples  = 0;
    yn1             = 0;
    yn2             = 0;

    p = src;

    while (1)
    {
        int i;
        s16 nibble[SAMPLES_PER_FRAME];                 
        s16 gain, ci;       // coef index
        u8  ps;

        // frame header
        ps      = *p;
        p++;

        gain    = 1 << (ps & 0x0F);
        ci      = ps >> 4;

        for (i = 0; i < SAMPLES_PER_FRAME; i += 2)
        {
            nibble[i]       = (s16)(*p >> 4);
            nibble[i + 1]   = (s16)(*p & 0x0F);
            p++;
        }

        // fix negative value
        for (i = 0; i < SAMPLES_PER_FRAME ; i++)
            if (nibble[i] >= MAX_LEVEL)
                nibble[i] = nibble[i] - MAX_LEVEL * 2;

        // decode the samples
        for (i = 0 ; i < SAMPLES_PER_FRAME; i++)
        {
            s32 mac = (s32)nibble[i] * (s32)gain * COEF_SCALING;

            mac += (s32)yn1 * (s32)cxt->coef[ci * ORDER];
            mac += (s32)yn2 * (s32)cxt->coef[ci * ORDER + 1];

            // rounding and cut off
            mac += (COEF_SCALING >> 1);
            mac >>= COEF_SCALING_BIT;

            // clamping
            if (mac > 32767)    mac = 32767;
            if (mac < -32768)   mac = -32768;

            if(decodedSamples == samples)
            {
                cxt->loop_pred_scale    = ps;
                cxt->loop_yn1           = yn1;
                cxt->loop_yn2           = yn2;
                return;
            }

            yn2 = yn1;
            yn1 = (s16)mac;

            decodedSamples++;
        }
    }
}
