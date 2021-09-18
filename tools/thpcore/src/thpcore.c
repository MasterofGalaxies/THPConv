/*---------------------------------------------------------------------------*
  Project:  Revolution THP Core Library
  File:     thpcore.c
  
  Copyright (C)2003-2006 Nintendo  All Rights Reserved.
  
  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
  
  $Log: not supported by cvs2svn $
    
    8     03/10/10 1:19p Akagi
    Added xsize check.
    
    7     03/10/10 10:05a Akagi
    Removed outputing debug messages.
    Changed error messages outputed when necessary markers are not found.
    
    6     03/09/23 2:16p Akagi
    Removed an excessive error message.
    
    5     03/09/21 6:46p Akagi
    Added JPEG markers check.
    
    4     03/09/15 6:01p Akagi
    Changed returns from THP_ERROR_FILEFORMAT to THP_ERROR_JPEGFILE.
    
    3     03/09/15 1:23p Akagi
    Revised some bugs, and renamed a function.
    
    2     03/07/03 11:00a Akagi
    Renamed from THPCONVConvertJPG2THP_OneFrameDataMemory to
    THPCONVConvertJPG2THP.
    
    1     03/07/01 1:40p Akagi
    Initial checkin. Modified to divide old THPConv.exe into 2 LIBs and 1
    EXE by Ohki-san@NTSC.
  
  $NoKeywords: $
  
  *---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include <revolution/types.h>
#include <revolution/thpfile.h>
#include <win32/thpcommon.h>
#include <win32/thpcore.h>

//-----------------------------------------------------------------------------
//      DEFINE
//-----------------------------------------------------------------------------
enum 
{
    M_SOF0   =  0xc0,                   // those are the jfif markers...
    M_SOF1   =  0xc1,
    M_SOF2   =  0xc2,
    M_SOF3   =  0xc3,
    M_SOF5   =  0xc5,
    M_SOF6   =  0xc6,
    M_SOF7   =  0xc7,
    M_JPG    =  0xc8,
    M_SOF9   =  0xc9,
    M_SOF10  =  0xca,
    M_SOF11  =  0xcb,
    M_SOF13  =  0xcd,
    M_SOF14  =  0xce,
    M_SOF15  =  0xcf,
    
    M_DHT    =  0xc4,
    
    M_DAC    =  0xcc,
    
    M_RST0   =  0xd0,
    M_RST1   =  0xd1,
    M_RST2   =  0xd2,
    M_RST3   =  0xd3,
    M_RST4   =  0xd4,
    M_RST5   =  0xd5,
    M_RST6   =  0xd6,
    M_RST7   =  0xd7,
    
    M_SOI    =  0xd8,
    M_EOI    =  0xd9,
    M_SOS    =  0xda,
    M_DQT    =  0xdb,
    M_DNL    =  0xdc,
    M_DRI    =  0xdd,
    M_DHP    =  0xde,
    M_EXP    =  0xdf,
    
    M_APP0   =  0xe0,
    M_APP1   =  0xe1,
    M_APP2   =  0xe2,
    M_APP3   =  0xe3,
    M_APP4   =  0xe4,
    M_APP5   =  0xe5,
    M_APP6   =  0xe6,
    M_APP7   =  0xe7,
    M_APP8   =  0xe8,
    M_APP9   =  0xe9,
    M_APP10  =  0xea,
    M_APP11  =  0xeb,
    M_APP12  =  0xec,
    M_APP13  =  0xed,
    M_APP14  =  0xee,
    M_APP15  =  0xef,
    
    M_JPG0   =  0xf0,
    M_JPG13  =  0xfd,
    M_COM    =  0xfe,
    M_MARKER =  0xff,
    M_TEM    =  0x01,
    M_ERROR  =  0x100
};

#define THP_FIND_MARKER_SOI 0x0001 // 0000_0000_0000_0001
#define THP_FIND_MARKER_SOF 0x0002 // 0000_0000_0000_0010
#define THP_FIND_MARKER_SOS 0x0004 // 0000_0000_0000_0100
#define THP_FIND_MARKER_DQT 0x0008 // 0000_0000_0000_1000
#define THP_FIND_MARKER_DHT 0x0010 // 0000_0000_0001_0000
#define THP_FIND_MARKER_EOI 0x0020 // 0000_0000_0010_0000
#define THP_FIND_MARKER_ALL 0x003f // 0000_0000_0011_1111

//-----------------------------------------------------------------------------
//      Global Value
//-----------------------------------------------------------------------------
u32     THPVerboseFlag = 0;

void    (*THPPrintFunc)(const char* format, va_list argptr)      = NULL;
void    (*THPPrintErrorFunc)(const char* format, va_list argptr) = NULL;
void    (*THPPrintLogFunc)(const char* format, va_list argptr)   = NULL;

void*   (*THPMalloc)(size_t size)  = malloc;
void    (*THPFree)(void* memblock) = free;

//-----------------------------------------------------------------------------
//      THPPrint
//
//      THPPrintFuncコールバックが登録されていれば、関数を呼び出して
//      テキストを出力する
//
//      IN:     format          出力書式文字列
//              ...             可変個引数
//      RTN:    なし
//-----------------------------------------------------------------------------
void THPPrint(const char* format, ...)
{
    va_list marker;
    
    va_start(marker, format);
    
    if (THPPrintFunc != NULL)
    {
        THPPrintFunc(format, marker);
    }
    else
    {
        vfprintf(stderr, format, marker);
    }
    
    va_end(marker);
}

//-----------------------------------------------------------------------------
//      THPPrintError
//
//      THPPrintErrorFuncコールバックが登録されていれば、関数を呼び出して
//      エラーを出力する
//
//      IN:     format          出力書式文字列
//              ...             可変個引数
//      RTN:    なし
//-----------------------------------------------------------------------------
void THPPrintError(const char* format, ...)
{
    va_list marker;
    
    va_start(marker, format);
    
    if (THPPrintErrorFunc != NULL)
    {
        THPPrintErrorFunc(format, marker);
    }
    else
    {
        vfprintf(stderr, format, marker);
    }
    
    va_end(marker);
}

//-----------------------------------------------------------------------------
//      THPPrintLog
//
//      THPPringLogFuncコールバック関数が登録されていてかつ、THPVerboseFlagが0
//      でなければ、コールバック関数を呼び出し、ログを出力する。
//
//      IN:     format          出力書式文字列
//              ...             可変個引数
//      RTN:    なし
//-----------------------------------------------------------------------------
void THPPrintLog(const char* format, ...)
{
    va_list marker;
    
    if (THPVerboseFlag == 0)
    {
        return;
    }
    
    va_start(marker, format);
    
    if (THPPrintLogFunc != NULL)
    {
        THPPrintLogFunc(format, marker);
    }
    else
    {
        vfprintf(stdout, format, marker);
    }
    
    va_end(marker);
}

//-----------------------------------------------------------------------------
//      THPConvertJPEG2THP
//
//      data_ptrのJPEGデータをTHPデータに変換し、out_ptrが指すバッファに書き出す。
//
//      IN:     jpeg_ptrdata_ptr   JPEGデータが格納されているバッファ
//              thp_ptr            THPデータを出力するバッファ
//              jpeg_length        JPEGデータのサイズ
//              status             THP画像情報を格納するTHPImageStatus構造体のポインタ
//      RTN:    エラー番号
//-----------------------------------------------------------------------------
s32 THPConvertJPEG2THP(void *jpeg_ptr, void* thp_ptr, s32 jpeg_length, THPImageStatus* status)
{
    u8          buf;
    u8*         curr_addr     = (u8*)jpeg_ptr;
    u8*         end_addr      = (u8*)jpeg_ptr + jpeg_length;
    u8*         out_ptr       = (u8*)thp_ptr;
    u16         marker_find   = 0;
    u32         THPError      = THP_ERROR_NOERROR;
    BOOL        startSkipping = FALSE;
    
    while ((u32)curr_addr < (u32)end_addr)
    {
        buf = *curr_addr;
        curr_addr++;
        
        if (buf != (u8)0xFF)
        {
            *out_ptr++ = buf;
            continue;
        }
        else
        {
            buf = *curr_addr;
            curr_addr++;
            
            // remember, if the marker is good, send the 0xFF 
            if (startSkipping)
            {
                if (buf == 0)
                {
                    // found a stuffed byte, just put the real 0xFF
                    *out_ptr++ = 0xFF;
                }
                
                // RSTn Segment
                else if (buf >= M_RST0 && buf <= M_RST7)
                {
                    // remove all restart markers
                }
                
                // EOI Segment
                else if (buf == M_EOI)
                {
                    *(out_ptr + 0) = 0xFF;
                    *(out_ptr + 1) = buf;
                    out_ptr += 2;

                    marker_find |= THP_FIND_MARKER_EOI;
                    
                    break;
                }
                
                // ???? Segment
                else
                {
                    THPError = THP_ERROR_JPEGFILE;
                    THPPrintError("ERROR: Marker found after entropy-encoded section!\n");
                    break;
                }
            }
            else // check if we should start skipping.  send marker either way
            {
                // SOI Segment
                if (buf == M_SOI)
                {
                    *(out_ptr + 0) = 0xFF;
                    *(out_ptr + 1) = buf;
                    out_ptr += 2;
                    
                    marker_find |= THP_FIND_MARKER_SOI;
                }
                
                // SOF0 Segment
                else if (buf == M_SOF0)
                {
                    // parse frame header to sanity check
                    u32 xsize, ysize, components, i;
                    u32 h[3];
                    u32 v[3];
                    
                    // copy segment header
                    *(out_ptr + 0) = 0xFF;
                    *(out_ptr + 1) = buf;
                    *(out_ptr + 2) = *(curr_addr + 0);
                    *(out_ptr + 3) = *(curr_addr + 1);
                    *(out_ptr + 4) = *(curr_addr + 2);
                    curr_addr += 3;
                    out_ptr   += 5;
                    
                    // x/y size
                    ysize = ((u32)*(curr_addr + 0) << 8) + (u32)*(curr_addr + 1);
                    xsize = ((u32)*(curr_addr + 2) << 8) + (u32)*(curr_addr + 3);
                    
                    *(out_ptr + 0) = *(curr_addr + 0);
                    *(out_ptr + 1) = *(curr_addr + 1);
                    *(out_ptr + 2) = *(curr_addr + 2);
                    *(out_ptr + 3) = *(curr_addr + 3);
                    curr_addr += 4;
                    out_ptr   += 4;
                    
                    if (status)
                    {
                        status->xSize = xsize;
                        status->ySize = ysize;
                    }

                    if (xsize % 16)
                    {
                        THPError = THP_ERROR_JPEGFILE;                            
                        THPPrintError("ERROR: X resolution is not a multiple of 16! THP may not decode correctly\n");
                        break;
                    }
                    
                    if (ysize % 16)
                    {
                        THPError = THP_ERROR_JPEGFILE;
                        THPPrintError("ERROR: Y resolution is not a multiple of 16! THP may not decode correctly\n");
                        break;
                    }

                    if (xsize > 672)
                    {
                        THPError = THP_ERROR_JPEGFILE;
                        THPPrintError("ERROR: THP supports up to 672 dots in a line!\n");
                        break;
                    }
                    
                    // components
                    components = *curr_addr;
                    *out_ptr   = (u8)components;
                    curr_addr++;
                    out_ptr++;
                    
                    if (components != 3)
                    {
                        THPError = THP_ERROR_JPEGFILE;
                        THPPrintError("ERROR: THP only supports 3 components!\n");
                        break;
                    }
                    
                    for (i = 0; i < components; i++)
                    {
                        *(out_ptr + 0) = *(curr_addr + 0);
                        *(out_ptr + 1) = *(curr_addr + 1);
                        *(out_ptr + 2) = *(curr_addr + 2);
                        h[i] = *(curr_addr + 1) >> 4;
                        v[i] = *(curr_addr + 1) & 0x0F;
                        curr_addr += 3;
                        out_ptr   += 3;
                    }
                    
                    if (status)
                    {
                        for (i = 0; i < 3; i++)
                        {
                            status->h[i] = h[i];
                            status->v[i] = v[i];
                        }
                    }
                    
                    if (( h[0]/h[1] != 2 )
                        || ( h[0]/h[2] != 2 )
                        || ( v[0]/v[1] != 2 )
                        || ( v[0]/v[2] != 2))
                    {
                        THPError = THP_ERROR_JPEGFILE;
                        THPPrintError("ERROR: THP only supports 4:2:0!\n");
                        break;
                    }
                    
                    marker_find |= THP_FIND_MARKER_SOF;
                }

                // DHT Segment
                // DQT Segment
                // DRI Segment
                // SOS Segmnt
                else if (buf == M_DHT || buf == M_DQT || buf == M_DRI || buf == M_SOS)
                {
                    u32 len;

                    if (buf == M_DHT)
                    {
                        marker_find |= THP_FIND_MARKER_DHT;
                    }
                    else if (buf == M_DQT)
                    {
                        marker_find |= THP_FIND_MARKER_DQT;
                    }
                    else if (buf == M_DRI)
                    {
                    }
                    else
                    {
                        startSkipping = TRUE;
                        marker_find |= THP_FIND_MARKER_SOS;
                    }
                    
                    len = ((u32)*(curr_addr + 0) << 8) + (u32)*(curr_addr + 1);
                    
                    *(out_ptr + 0) = 0xFF;
                    *(out_ptr + 1) = buf;
                    *(out_ptr + 2) = *(curr_addr + 0);
                    *(out_ptr + 3) = *(curr_addr + 1);
                    out_ptr   += 4;
                    curr_addr += 2;
                    len       -= 2;
                    
                    memcpy(out_ptr, curr_addr, len);
                    curr_addr += len;
                    out_ptr   += len;
                }

                // APP0 - APP15
                // JPG0 - JPG13
                // COM
                else if (buf >= M_APP0 && buf <= M_COM)
                {
                    // figure out length and skip over
                    u32 len;
                    len = ((u32)*(curr_addr + 0) << 8) + (u32)*(curr_addr + 1);
                    curr_addr += len;
                }
                
                // SOF1,  SOF2,  SOF3
                // SOF5,  SOF6,  SOF7
                // JPG
                // SOF9,  SOF10, SOF11
                // DAC
                // SOF13, SOF14, SOF15
                // DNL
                // DHP
                // EXP
                else
                {
                    THPError = THP_ERROR_JPEGFILE;
                    THPPrintError("ERROR: Unsupported marker(0x%x) found!\n", buf);
                    break;
                }

            } // if (startSkipping) ... else
            
        } // if (buf != (u8)0xFF) ... else
        
    } // while ((u32)curr_addr < (u32)end_addr)
    
    if (status)
    {
        status->imageSize = (u32)out_ptr - (u32)thp_ptr;
    }
    
    if (marker_find != THP_FIND_MARKER_ALL)
    {
        if (THPError == THP_ERROR_NOERROR)
        {
            THPError = THP_ERROR_JPEGFILE;
            
            if (!(marker_find & THP_FIND_MARKER_SOI))
            {
                THPPrintError("ERROR: Marker SOI is not found!\n");
            }
            if (!(marker_find & THP_FIND_MARKER_SOF))
            {
                THPPrintError("ERROR: Marker SOF is not found!\n");
            }
            if (!(marker_find & THP_FIND_MARKER_SOS))
            {
                THPPrintError("ERROR: Marker SOS is not found!\n");
            }
            if (!(marker_find & THP_FIND_MARKER_DQT))
            {
                THPPrintError("ERROR: Marker DQT is not found!\n");
            }
            if (!(marker_find & THP_FIND_MARKER_DHT))
            {
                THPPrintError("ERROR: Marker DHT is not found!\n");
            }
            if (!(marker_find & THP_FIND_MARKER_EOI))
            {
                THPPrintError("ERROR: Marker EOI is not found!\n");
            }
        }
    }
    
    return THPError;
}

//-----------------------------------------------------------------------------
//      THPCONVGetVideoData
//
//      inFileNameで指定されたTHP中間形式のファイルをチェックして、
//      サイズを取得し、headerに指定したTHPVideoInfo構造体のxSize, ySizeに格納する
//
//      IN:     inFileName      チェックするTHP中間ファイル名
//              header          THPVideoInfo構造体
//      RTN:    エラー値
//-----------------------------------------------------------------------------
#if 0
s32 THPCONVGetVideoData(char* inFileName , THPVideoInfo *header)
{
    u8          buf;
    BOOL        startSkipping;
    BOOL        checkMarker;
    u32             THPError = 0;
    FILE*       ip;
    
    ip = fopen (inFileName, "r"); 
    if ( ip == NULL)
    {
        THPPrintError("Unable to open file %s\n", inFileName);
        return THP_ERROR_FILEIO;
    }
    
    // search for markers
    startSkipping   = FALSE;
    checkMarker     = FALSE;
    //while (r = fread (buf, 1, BUF_SIZE, fp))
    //while ((buf = fgetc(ip)) != EOF)
    while (!feof(ip))
    {
        buf = fgetc(ip);
        
        if (!checkMarker)
        {
            if (buf == (u8)0xFF)
            {
                // this tells us to look at the next char as a marker
                checkMarker = TRUE;
            }
            else
            {
            }
        }
        else
        {
            // remember, if the marker is good, send the 0xFF 
            checkMarker = FALSE;
            if (startSkipping)
            {
                if (buf == 0)
                {
                    // found a stuffed byte, just put the real 0xFF
                    THPPrintLog("<stuff>");
                    
                }
                else if (buf >= M_RST0 && buf <= M_RST7)
                {
                    THPPrintLog("RST skipped 0x%x\n", buf);
                }
                else if (buf == M_EOI)
                {
                    startSkipping = FALSE;
                    
                }
                else
                {
                    if ((buf >= M_SOF0) && (buf <= M_MARKER))
                    {
                        THPPrintError("ERROR: Marker found after entropy-encoded section!\n");
                        THPPrintError("Please re-encode JPEG file!\n");
                        
                        THPError = THP_ERROR_JPEGFILE;
                    }
                    else
                    {
                        THPPrintError("Skipping but marker is garbage! 0x%x\n", buf);
                    }
                    
                }
            }
            else    // check if we should start skipping.  send marker either way
            {
                if (buf == M_SOS)
                {
                    startSkipping = TRUE;
                }
                else if (buf == M_SOF0)
                {
                    // parse frame header to sanity check
                    u32 buf0, buf1;
                    u32 xsize, ysize, components, i;
                    u32 h[3];
                    u32 v[3];
                    
                    // check size of file
                    buf = fgetc(ip);
                    buf = fgetc(ip);
                    buf = fgetc(ip);
                    
                    // x size
                    buf0 = fgetc(ip);
                    buf1 = fgetc(ip);
                    ysize = (buf0<<8) | buf1;
                    buf0 = fgetc(ip);
                    buf1 = fgetc(ip);
                    xsize = (buf0<<8) | buf1;
                    
                    components = fgetc(ip);
                    
                    
                    THPPrintLog("%dx%dx%d ", xsize, ysize, components);
                    
                    header->xSize = xsize;
                    header->ySize = ysize;
                    
                    
                    if (xsize % 16)
                    {
                        THPError = THP_ERROR_JPEGFILE;                            
                        THPPrintError("WARNING: X resolution is not a multiple of 16! THP may not decode correctly\n");
                    }
                    
                    
                    if (ysize % 16)
                    {
                        THPError = THP_ERROR_JPEGFILE;                            
                        THPPrintError("WARNING: Y resolution is not a multiple of 16! THP may not decode correctly\n");
                    }
                    
                    
                    if (components != 3)
                    {
                        THPError = THP_ERROR_JPEGFILE;
                        THPPrintError("ERROR : Currently only support 3 components\n");
                    }
                    
                    for (i = 0; i < components; i++)
                    {
                        fgetc(ip);
                        buf = fgetc(ip);
                        h[i] = buf >> 4;
                        v[i] = buf & 15;
                        fgetc(ip);
                    }
                    if (( h[0]/h[1] == 2 ) && ( h[0]/h[2] == 2 ))
                    {
                        if (( v[0]/v[1] == 2 ) && ( v[0]/v[2] == 2 ))
                        {
                            THPPrintLog("4:2:0\n");                    // 4:2:0
                        }
                        else if (( v[0] == v[1] ) && ( v[0] == v[2] ))
                        {
                            
                            THPError = THP_ERROR_JPEGFILE;
                            THPPrintError("\n ERROR ! 4:2:2 image.  Only support 4:2:0\n");
                        }
                    }
                    else if (( h[0] == h[1] ) && ( h[0] == h[2] ))
                    {
                        if (( v[0] == v[1] ) && ( v[0] == v[2] ))
                        {
                            THPError = THP_ERROR_JPEGFILE;
                            THPPrintError("\n ERROR ! 4:4:4 image.  Only support 4:2:0\n");
                        }
                    }
                    else
                    {   
                        THPError = THP_ERROR_JPEGFILE;
                        THPPrintError("ERROR : No sub_sampling\n");
                        
                    }
                    fclose(ip);
                    return THPError;
                }
                else 
                {
                    if ( (buf >= M_DQT && buf <= M_APP15) || (buf == M_DHT) )
                    {
                        // figure out length and skip over
                        u32 len =  (((u16)fgetc(ip)) << 8)  |   ((u16)fgetc(ip));
                        len -= 2;
                        while (len--)
                        {
                            fgetc(ip);
                        }
                    }

                }                    
                
            }
        }
    }
    fclose(ip);
    return THPError;
}
#endif
