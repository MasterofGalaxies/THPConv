/*---------------------------------------------------------------------------*
  Project:  Revolution THP Utilities Library
  File:     thputilities.c

  Copyright (C)2002-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2006/02/08 02:57:09  aka
  Imported from Dolphin Tree.

    
    15    03/12/24 3:00p Akagi
    Revised a commnet.
    
    14    03/12/24 1:58p Akagi
    Added THPUtyCopyTHPFile().
    
    13    03/12/10 10:17a Akagi
    Revised THP version in THPUtyReadTHPFileHeader().
    
    12    03/09/21 6:44p Akagi
    Added THP file check during reading THPHeader.
    
    11    03/09/15 5:56p Akagi
    Renamed all functions from THPCONVXXXX to THPUtyXXXX.
    Added some comments.
    
    10    03/07/03 11:04a Akagi
    Renamed some functions.
    
    9     03/07/01 2:34p Akagi
    Modified to divide old THPConv.exe into 2 LIBs and 1 EXE by
    Ohki-san@NTSC.
    
    8     03/07/01 2:26p Akagi
    Moved from build/tools/THPConv/src.
    
    7     03/07/01 9:54a Akagi
    Moved from securebuild/tools.
    
    6     02/10/16 11:28a Akagi
    JPEG & WAV file Name bug fixed. (by iRD  tsuji)
    
    5     02/05/08 2:31p Akagi
    modified [-trk] option By Tsuji (IRD)
    
    1     02/01/16 4:59p Akagi
    Initial revision made by Tsuji-san (IRD).
    
  $NoKeywords: $
  
 *---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <byteswap.h>

#include <revolution/types.h>
#include <revolution/thpfile.h>
#include <win32/thpcommon.h>
#include <win32/thpcore.h>
#include <win32/thputilities.h>
#include <win32/thpaudio.h>

//-----------------------------------------------------------------------------
// Local Functions
//-----------------------------------------------------------------------------
static s32 THPUtyWriteVideoOneFrame( FILE* thpFp, THPFileName*     fileName,
                                                  THPImageStatus*  imageStatus );
static s32 THPUtyWriteAudioOneFrame( FILE* thpFp, THPFileHeader*   fileHeader,
                                                  THPAudioHandle** audioHandleList,
                                                  u32              frameSize,
                                                  u32              frameNum );
static s32 THPUtyCopyVideoFrame    ( FILE* thpFp, FILE*            videoTHPFp,
                                                  THPFileHeader*   videoFileHeader,
                                                  u32*             videoCompSize );

/*---------------------------------------------------------------------------*
 *---------------------------------------------------------------------------*
 *                              Utility Functions                            *
 *---------------------------------------------------------------------------*
 *---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*
  Name:         THPUtyConvertToUnixFmt

  Description:  fmtで指定されたUnix形式のパスをDOS形式に変換する。
                fmtで指定したバッファを上書きする点に注意。
                
  Arguments:    fmt         変換する文字列のポインタ
                
  Returns:      無し
 *---------------------------------------------------------------------------*/
void THPUtyConvertToUnixFmt(char* fmt)
{
    char*  fmt_start = fmt;
    char   temp[256];
    char*  temp_ptr = temp;
    
    strcpy(temp_ptr, fmt); 
    
    if (temp_ptr == NULL)
    {
        return;
    }
    
    while (*temp_ptr != '\0')
    {
        if ((*temp_ptr == '/') && (*(temp_ptr + 1) == '/'))
        {
            *fmt       = *(temp_ptr + 2);
            *(fmt + 1) = ':';
            *(fmt + 2) = '\\';
            fmt += 3;
            temp_ptr += 3;
        }
        else if ((*temp_ptr == '.') && (*(temp_ptr + 1) == '.') && (*(temp_ptr + 2) == '/'))
        {
            *fmt       = '.';
            *(fmt + 1) = '.';
            *(fmt + 2) = '\\';
            fmt += 3;
            temp_ptr += 3;
        }
        else if (*temp_ptr == '/')
        {
            *(fmt) = '\\';
            fmt++;
            temp_ptr++;
        }
        else
        {
            *fmt = *temp_ptr;
            fmt++;
            temp_ptr++;
        }
    }
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyReverseEndianF32

  Description:  32bit float値のEndianを変換する。

  Arguments:    data        Endianを変換するfloatの値
                
  Returns:      Endianを変換したfloat値
 *---------------------------------------------------------------------------*/
f32 THPUtyReverseEndianF32(f32 data)
{
    u8*  src = (u8 *)&data;
    f32  result;
    u8*  r = (u8*)&result;
    
    r[3] = src[0];
    r[2] = src[1];
    r[1] = src[2];
    r[0] = src[3];
    
    return(result);
} 

/*---------------------------------------------------------------------------*
  Name:         THPUtyWritePad32

  Description:  32ByteアライメントになるようファイルにNULLを出力する。
                
  Arguments:    op          出力先のファイルポインタ
                bytes       直前に出力したデータのサイズ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル出力失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyWritePad32(FILE* op, u32 bytes)
{
    u32     remainder = 32 - (bytes & ((u32)31));
    u8      val = 0;
    u8      buffer[32];
    size_t  ret;
    
    // no real remainder
    if (remainder == 32)
    {
        return THP_ERROR_NOERROR;
    }
    
    THPPrintLog("Adding %ld pad bytes\n", remainder);
    
    memset(buffer, 0, sizeof(buffer));
    
    ret = fwrite(buffer, remainder, 1, op);
    if (ret != 1)
    {
        THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyPutU32

  Description:  u32型のdataを、エンディアンを変換し、opで指定したファイルに出力する。
                
  Arguments:    op          出力先のファイルポインタ
                data        出力するu32型の値
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル出力失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyPutU32(FILE *op, u32 data)
{
    s32  rtn;
    u8   buffer[4];
    
    buffer[0] = (u8)(data >> 24);
    buffer[1] = (u8)(data >> 16);
    buffer[2] = (u8)(data >>  8);
    buffer[3] = (u8)(data >>  0);
    rtn = fwrite(buffer, 4, 1, op);
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyPutF32

  Description:  f32型のdataを、エンディアンを変換し、opで指定したファイルに出力する。
                
  Arguments:    op          出力先のファイルポインタ
                data        出力するf32型の値
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル出力失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyPutF32(FILE *op, f32 data)
{
    u32  data_u32;
    
    memcpy(&data_u32, &data, 4);
    
    return THPUtyPutU32(op, data_u32);
}

/*---------------------------------------------------------------------------*
 *---------------------------------------------------------------------------*
 *                         THP File Write Functions                          *
 *---------------------------------------------------------------------------*
 *---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*
  Name:         THPUtyHeaderInit

  Description:  THPHeader構造体を初期化する。
                
  Arguments:    header      THPHeader構造体のポインタ
                
  Returns:      無し
 *---------------------------------------------------------------------------*/
void THPUtyHeaderInit(THPHeader* header)
{
    header->magic[0]                    = 'T';
    header->magic[1]                    = 'H';
    header->magic[2]                    = 'P';
    header->magic[3]                    = '\0';
    header->version                     = THP_VERSION;
    header->bufSize                     = 0;
    header->audioMaxSamples             = 0;
    header->frameRate                   = 0.0F;      
    header->numFrames                   = 0;            // total of frames
    header->firstFrameSize              = 0;
    header->movieDataSize               = 0;
    header->compInfoDataOffsets         = 0;
    header->offsetDataOffsets           = 0;
    header->movieDataOffsets            = 0;
    header->finalFrameDataOffsets       = 0;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyWriteTHPHeader

  Description:  THPHeader構造体をopで指定したファイルに出力する。
                
  Arguments:    op          出力先のファイルポインタ
                header      出力するTHPHeader構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル出力失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyWriteTHPHeader(FILE *op, THPHeader *header)
{
    s32  rtn;
    
    rtn = fwrite(header->magic, 4, 1, op);
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    if ((rtn = THPUtyPutU32(op, header->version)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, header->bufSize)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, header->audioMaxSamples)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutF32(op, header->frameRate)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, header->numFrames)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, header->firstFrameSize)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, header->movieDataSize)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, header->compInfoDataOffsets)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, header->offsetDataOffsets)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, header->movieDataOffsets)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, header->finalFrameDataOffsets)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyWriteTHPFrameCompInfo

  Description:  THPFrameCompInfo構造体をopで指定したファイルに出力する。
                
  Arguments:    op          出力先のファイルポインタ
                compinfo    出力するTHPFrameCompInfo構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル出力失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyWriteTHPFrameCompInfo(FILE *op, THPFrameCompInfo *compinfo)
{
    s32  rtn;
    
    if ((rtn = THPUtyPutU32(op, compinfo->numComponents)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    
    rtn = fwrite(compinfo->frameComp, THP_COMP_MAX, 1, op);
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyWriteTHPVideoInfo

  Description:  THPVideoInfo構造体をopで指定したファイルに出力する。
                
  Arguments:    op          出力先のファイルポインタ
                videoinfo   出力するTHPVideoInfo構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル出力失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyWriteTHPVideoInfo(FILE *op, THPVideoInfo *videoinfo)
{
    s32  rtn;
    
    if ((rtn = THPUtyPutU32(op, videoinfo->xSize)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, videoinfo->ySize)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, videoinfo->videoType)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyWriteTHPAudioInfo

  Description:  THPAudioInfo構造体をopで指定したファイルに出力する。
                
  Arguments:    op          出力先のファイルポインタ
                audioinfo   出力するTHPAudioInfo構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル出力失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyWriteTHPAudioInfo(FILE *op, THPAudioInfo *audioinfo)
{
    s32  rtn;
    
    if ((rtn = THPUtyPutU32(op, audioinfo->sndChannels)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, audioinfo->sndFrequency)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, audioinfo->sndNumSamples)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, audioinfo->sndNumTracks)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyWriteTHPFrameHeader

  Description:  THPFrameHeader構造体をopで指定したファイルに出力する。
                
  Arguments:    op             出力先のファイルポインタ
                frameCompInfo  THPFrameCompInfo構造体のポインタ
                frameHeader    出力するTHPFrameHeader構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル出力失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyWriteTHPFrameHeader(FILE* op, THPFrameCompInfo* frameCompInfo,
                                        THPFrameHeader*   frameHeader)
{
    u32  i;
    s32  rtn;
    
    if ((rtn = THPUtyPutU32(op, frameHeader->frameSizeNext)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    if ((rtn = THPUtyPutU32(op, frameHeader->frameSizePrevious)) != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    for (i = 0; i < frameCompInfo->numComponents; i++)
    {
        if ((rtn = THPUtyPutU32(op, frameHeader->comp[i])) != THP_ERROR_NOERROR)
        {
            return rtn;
        }
    }
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyWriteTHPComponentsInfo

  Description:  構造体THPVideoInfo,THPAudioinfoをopで指定したファイルに出力する。
                
  Arguments:    op            出力先のファイルポインタ
                compinfo      THPFrameCompInfo構造体のポインタ
                videoinfo     出力するTHPVideoInfo構造体のポインタ
                audioinfo     出力するTHPAudioInfo構造体のポインタ
                compinfosize  コポーネントサイズの格納先のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル出力失敗
                THP_ERROR_DATA     データ不正
 *---------------------------------------------------------------------------*/
s32 THPUtyWriteTHPComponentsInfo(FILE* op, THPFrameCompInfo* compinfo,
                                           THPVideoInfo*     videoinfo,
                                           THPAudioInfo*     audioinfo,
                                           s32*              compinfosize)
{
    u32  i;
    s32  size = 0;
    s32  rtn;
    
    for (i = 0; i < compinfo->numComponents; i++)
    {
        switch (compinfo->frameComp[i])
        {
            case THP_VIDEO_COMP: 
                rtn = THPUtyWriteTHPVideoInfo(op, videoinfo);
                if (rtn != THP_ERROR_NOERROR)
                {
                    return rtn;
                }
                size += sizeof(THPVideoInfo);
                break;
                
            case THP_AUDIO_COMP:    
                rtn = THPUtyWriteTHPAudioInfo(op, audioinfo);
                if (rtn != THP_ERROR_NOERROR)
                {
                    return rtn;
                }
                size += sizeof(THPAudioInfo);
                break;
                
            case THP_NOCOMP_COMP:
                THPPrintError("\aERROR : Strange numComponents (%ld)\n", __LINE__);
                return THP_ERROR_DATA;
                break;
                
            default:
                THPPrintError("\aERROR : Unsupported Components (%ld)\n", __LINE__);
                return THP_ERROR_DATA;
                break;
        }
    }
    
    if (compinfosize != NULL)
    {
        *compinfosize = size;
    }
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyWriteTHPFileHeader

  Description:  THPFileHeader構造体をopで指定したファイルに出力する。
                
  Arguments:    op            出力先のファイルポインタ
                fileHeader    出力するTHPFileHeader構造体のポインタ
                compInfoSize  コポーネントサイズの格納先のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル出力失敗
                THP_ERROR_DATA     データ不正
 *---------------------------------------------------------------------------*/
s32 THPUtyWriteTHPFileHeader(FILE* op, THPFileHeader* fileHeader, s32* compInfoSize)
{
    s32  rtn;
    
    rtn = fseek(op, 0, SEEK_SET);
    if (rtn != 0)
    {
        THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    // Write THPHeader, THPFrameCompInfo, THPVideoInfo, THPAudioInfo(Update after Convert)
    
    rtn = THPUtyWriteTHPHeader(op, &fileHeader->header);
    if (rtn != THP_ERROR_NOERROR)
    {
        return rtn;;
    }
    
    rtn = fseek(op, fileHeader->header.compInfoDataOffsets, SEEK_SET);
    if (rtn != 0)
    {
        THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    rtn = THPUtyWriteTHPFrameCompInfo(op, &fileHeader->frameCompInfo);
    if (rtn != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    
    rtn = THPUtyWriteTHPComponentsInfo(op,
                                       &fileHeader->frameCompInfo,
                                       &fileHeader->videoInfo,
                                       &fileHeader->audioInfo,
                                       compInfoSize);
    if (rtn != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
 *---------------------------------------------------------------------------*
 *                       THP File Read Functions                             *
 *---------------------------------------------------------------------------*
 *---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*
  Name:         THPUtyReadTHPHeader

  Description:  ipで指定したTHPファイルからTHPHeader構造体を読み込む。
                あらかじめ読み込み位置をTHPHeaderの位置にしておく必要がある。
                
  Arguments:    ip          THPファイルのファイルポインタ
                header      THPHeader構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル読み込み失敗
                THP_ERROR_THPFILE  THPファイル不正
 *---------------------------------------------------------------------------*/
s32 THPUtyReadTHPHeader(FILE *ip, THPHeader *header)
{
    s32  rtn;
    
    rtn = fread(header, sizeof(THPHeader), 1, ip);
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fread error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    // magic のチェック
    if (memcmp(header->magic, "THP\0", 4))
    {
        THPPrintError("\aERROR : this will not be a THP file (%ld)\n", __LINE__);
        return THP_ERROR_THPFILE;
    }
    
    // Reverse Endian
    header->version               = bswap_32(header->version);
    header->bufSize               = bswap_32(header->bufSize);
    header->audioMaxSamples       = bswap_32(header->audioMaxSamples);
    header->frameRate             = THPUtyReverseEndianF32(header->frameRate);
    header->numFrames             = bswap_32(header->numFrames);
    header->firstFrameSize        = bswap_32(header->firstFrameSize);
    header->movieDataSize         = bswap_32(header->movieDataSize);
    header->compInfoDataOffsets   = bswap_32(header->compInfoDataOffsets);
    header->offsetDataOffsets     = bswap_32(header->offsetDataOffsets);
    header->movieDataOffsets      = bswap_32(header->movieDataOffsets);
    header->finalFrameDataOffsets = bswap_32(header->finalFrameDataOffsets);
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyReadTHPFrameCompInfo

  Description:  ipで指定したTHPファイルからTHPFrameCompInfo構造体を読み込む。
                あらかじめ読み込み位置をTHPFrameCompInfoの位置にしておく必要がある。
                
  Arguments:    ip          THPファイルのファイルポインタ
                compinfo    THPFrameCompInfo構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル読み込み失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyReadTHPFrameCompInfo(FILE *ip, THPFrameCompInfo *compinfo)
{
    s32  rtn;
    
    rtn = fread(compinfo, sizeof(THPFrameCompInfo), 1, ip);
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fread error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    // Reverse Endian
    compinfo->numComponents = bswap_32(compinfo->numComponents);
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyReadTHPVideoInfo

  Description:  ipで指定したTHPファイルからTHPVideoInfo構造体を読み込む。
                あらかじめ読み込み位置をTHPVideoInfoの位置にしておく必要がある。
                
  Arguments:    ip          THPファイルのファイルポインタ
                videoinfo   THPVideoInfo構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル読み込み失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyReadTHPVideoInfo(FILE *ip, THPVideoInfo *videoinfo)
{
    s32  rtn;
    
    rtn = fread(videoinfo, sizeof(THPVideoInfo), 1, ip);
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fread error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    // Reverse Endian
    videoinfo->xSize     = bswap_32(videoinfo->xSize);
    videoinfo->ySize     = bswap_32(videoinfo->ySize);
    videoinfo->videoType = bswap_32(videoinfo->videoType);
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyReadTHPVideoInfoOld

  Description:  ipで指定したVer1.0以前のTHPファイルからTHPVideoInfo構造体を読み込む
                あらかじめ読み込み位置をTHPVideoInfoの位置にしておく必要がある。
                
  Arguments:    ip          Ver1.0以前のTHPファイルのファイルポインタ
                videoinfo   THPVideoInfo構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル読み込み失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyReadTHPVideoInfoOld(FILE *ip, THPVideoInfo *videoinfo)
{
    s32              rtn;
    THPVideoInfoOld  videoinfoOld;
    
    rtn = fread(&videoinfoOld, sizeof(THPVideoInfoOld), 1, ip);
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fread error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    // Reverse Endian
    videoinfo->xSize     = bswap_32(videoinfoOld.xSize);
    videoinfo->ySize     = bswap_32(videoinfoOld.ySize);
    videoinfo->videoType = THP_VIDEO_NON_INTERLACE;
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyReadTHPAudioInfo

  Description:  ipで指定したTHPファイルからTHPAudioInfo構造体を読み込む。
                あらかじめ読み込み位置をTHPAudioInfoの位置にしておく必要がある。
                
  Arguments:    ip          THPファイルのファイルポインタ
                audioinfo   THPAudioInfo構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル読み込み失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyReadTHPAudioInfo(FILE *ip, THPAudioInfo *audioinfo)
{
    s32  rtn;
    
    rtn = fread(audioinfo, sizeof(THPAudioInfo), 1, ip);
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fread error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    // Reverse Endian
    audioinfo->sndChannels   = bswap_32(audioinfo->sndChannels);
    audioinfo->sndFrequency  = bswap_32(audioinfo->sndFrequency);
    audioinfo->sndNumSamples = bswap_32(audioinfo->sndNumSamples);
    audioinfo->sndNumTracks  = bswap_32(audioinfo->sndNumTracks);
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyReadTHPAudioInfoOld

  Description:  ipで指定したVer1.0以前のTHPファイルからTHPAudioInfo構造体を読み込む。
                あらかじめ読み込み位置をTHPAudioInfoの位置にしておく必要がある。
                
  Arguments:    ip          Ver1.0以前のTHPファイルのファイルポインタ
                audioinfo   THPAudioInfo構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル読み込み失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyReadTHPAudioInfoOld(FILE *ip, THPAudioInfo *audioinfo)
{
    s32              rtn;
    THPAudioInfoOld  audioinfoOld;
    
    rtn = fread(&audioinfoOld, sizeof(THPAudioInfoOld), 1, ip);
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fread error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    // Reverse Endian
    audioinfo->sndChannels   = bswap_32(audioinfoOld.sndChannels);
    audioinfo->sndFrequency  = bswap_32(audioinfoOld.sndFrequency);
    audioinfo->sndNumSamples = bswap_32(audioinfoOld.sndNumSamples);
    audioinfo->sndNumTracks  = 1;
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyReadTHPFrameHeader

  Description:  ipで指定したTHPファイルからTHPFrameHeader構造体を読み込む。
                あらかじめ読み込み位置をTHPFrameHeader位置にしておく必要がある。
                
  Arguments:    ip            THPファイルのファイルポインタ
                frameHeader   THPFrameHeader構造体のポインタ
                componentNum  THPファイルに含まれるコンポーネントの数
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル読み込み失敗
 *---------------------------------------------------------------------------*/
s32 THPUtyReadTHPFrameHeader(FILE* ip, THPFrameHeader* frameHeader, s32 componentNum)
{
    s32     rtn;
    size_t  readSize;
    
    readSize = componentNum * sizeof(u32) + sizeof(u32) * 2;
    rtn = fread(frameHeader, readSize, 1,ip);
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fread error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    // Reverse Endian
    frameHeader->frameSizeNext     = bswap_32(frameHeader->frameSizeNext);
    frameHeader->frameSizePrevious = bswap_32(frameHeader->frameSizePrevious);
    {
        s32  i;
        for (i = 0; i < componentNum; i++)
        {
            frameHeader->comp[i] = bswap_32(frameHeader->comp[i]);
        }
    }
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyReadTHPFileHeader

  Description:  ipで指定したTHPファイルからTHPFileHeader構造体を読み込む。
                あらかじめ読み込み位置をTHPFileHeader位置にしておく必要がある。
                
  Arguments:    ip          THPファイルのファイルポインタ
                fileHeader  THPFileHeader構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR     正常終了
                THP_ERROR_FILEIO      ファイル読み込み失敗
                THP_ERROR_THPFILE     THPファイル不正
 *---------------------------------------------------------------------------*/
s32 THPUtyReadTHPFileHeader(FILE* ip, THPFileHeader* fileHeader)
{
    s32  rtn;
    u32  i;
    
    // Seek THPHeader Offset
    rtn = fseek(ip, 0, SEEK_SET);
    if (rtn != 0)
    {
        THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    // Read THPHeader
    rtn = THPUtyReadTHPHeader(ip, &fileHeader->header);
    if (rtn != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    
    // Seek THPFrameCompInfo Offset
    rtn = fseek(ip, fileHeader->header.compInfoDataOffsets, SEEK_SET);
    if (rtn != 0)
    {
        THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
        return THP_ERROR_FILEIO;
    }
    
    // Read THPFrameCompInfo
    rtn = THPUtyReadTHPFrameCompInfo(ip, &fileHeader->frameCompInfo);
    if (rtn != THP_ERROR_NOERROR)
    {
        return rtn;
    }
    
    // Read THPVideoInfo/THPAudioInfo
    for (i = 0; i < fileHeader->frameCompInfo.numComponents; i++)
    {
        switch (fileHeader->frameCompInfo.frameComp[i])
        {
            
            case THP_VIDEO_COMP: // THPVideoInfo
                if (fileHeader->header.version > 0x10000)
                {
                    // Ver 1.1 or later
                    rtn = THPUtyReadTHPVideoInfo(ip, &fileHeader->videoInfo);
                }
                else
                {
                    // Ver1.0
                    rtn = THPUtyReadTHPVideoInfoOld(ip, &fileHeader->videoInfo);
                }
                if (rtn != THP_ERROR_NOERROR)
                {
                    return rtn;
                }
                break;
                
            case THP_AUDIO_COMP: //THPAudioInfo
                if (fileHeader->header.version > 0x10000)
                {
                    // Ver 1.1 or later
                    rtn = THPUtyReadTHPAudioInfo(ip, &fileHeader->audioInfo);
                }
                else
                {
                    // Ver1.0
                    rtn = THPUtyReadTHPAudioInfoOld(ip, &fileHeader->audioInfo);
                }
                if (rtn != THP_ERROR_NOERROR)
                {
                    return rtn;
                }
                break;
                
            case THP_NOCOMP_COMP:
                THPPrintError("\aERROR : Strange numComponents (%ld)\n", __LINE__);
                return THP_ERROR_THPFILE;
                break;
                
            default:
                THPPrintError("\aERROR : Unsupported Components (%ld)\n", __LINE__);
                return THP_ERROR_THPFILE;
                break;
        }
    }
    
    return THP_ERROR_NOERROR;
}

/*---------------------------------------------------------------------------*
 *---------------------------------------------------------------------------*
 *                   THP File Manipulating Functions                         *
 *---------------------------------------------------------------------------*
 *---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*
  Name:         THPUtyCreateTHP

  Description:  fileHeaderの情報に基づき、THPファイルを生成する。

  Arguments:    op               出力先のファイルポインタ
                fileFlag         入力データのタイプを指定するフラグ
                filePtr          fileFlagに応じた入力データのポインタ
                fileHeader       THPFileHeader構造体のポインタ。
                audioHandleList  THPAudioHandle構造体のポインタのリスト
                
  Returns:      THP_ERROR_NOERROR     正常終了
                THP_ERROR_FILEIO      ファイル読み書き失敗
                THP_ERROR_JPEGFILE    JPEGファイル不正
                THP_ERROR_THPFILE     THPファイル不正
                THP_ERROR_DATA        データ不正
                THP_ERROR_FATAL       メモリ確保失敗
 *---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*

   - fileFlag

     fileFlag = THP_CREATETHP_FILEFLAG_JPEGS :
        filePtrはTHPFileName構造体の配列で指定されたJPEGファイルのリスト。
        filePtrで指定したJPEGファイルをTHP形式に変換し、THPファイルを作成する。
        headerHeader.header.numFramesで指定した数のリストの必要がある。

     fileFlag = THP_CREATETHP_FILEFLAG_THP :
        filePtrは入力THPファイルのファイルポインタ。

   - fileHeader
   
     呼び出し前に以下のメンバを設定しておく必要がある。
     (それ以外のメンバはこの関数で設定される。)
     
        [THPHeader]
        fileHeader->header.magic
        fileHeader->header.version
        fileHeader->header.frameRate
        fileHeader->header.numFrames
        fileHeader->header.compInfoDataOffsets
        fileHeader->header.offsetDataOffsets (オフセットを使う場合は0以外の値を設定しておく)
        
        [THPFrameCompInfo]
        fileHeader->frameCompInfo.frameComp[]
        fileHeader->frameCompInfo.numComponents
        
        [THPVideoInfo]
        fileHeader->videoInfo.videoType
        
        [THPAudioInfo]
        fileHeader->audioInfo.sndChannels
        fileHeader->audioInfo.sndFrequency
        fileHeader->audioInfo.sndNumSamples
        fileHeader->audioInfo.sndNumTracks
        
   - audioHandleList

      audioHandleListで指定された複数のWAVファイルは、エンコードされた後、ビデオデータとイ
      ンターリーブされ、THPファイルに出力される。
      指定されたTHPAudioHandle構造体はTHPAudioCreateHandleでオープン済みの必要がある。
      audioInfo.sndNumTracks数のリストである必要がある。
      オーディオを変換しない場合はNULLを指定する。
      
 *---------------------------------------------------------------------------*/
s32 THPUtyCreateTHP(FILE* op, s32              fileFlag,
                              void*            filePtr,
                              THPFileHeader*   fileHeader,
                              THPAudioHandle** audioHandleList)
{
    s32             rtn;
    s32             compInfoSize;
    u32             i, compCnt;
    THPFrameHeader  frameHeader;
    u32*            frameOffsetData = NULL;
    u32             frameHeaderSize;
    u32             frameSize;
    u32             frameSizeMax = 0;
    s32             frameSizeFirst = 0;
    s32             frameSizePrevious = 0;
    s32             movieDataSize = 0;
    u32             xSize, ySize;
    u8              tempZero[32];
    s32             error = THP_ERROR_NOERROR;
    u32             NumFrames = fileHeader->header.numFrames;
    THPImageStatus  imageStatus;
    THPFileHeader   videoFileHeader;
    FILE*           videoTHPFp;
    
    switch (fileHeader->videoInfo.videoType)
    {
        case THP_VIDEO_NON_INTERLACE:
            THPPrintLog("Video Type: [Non-interlace]\n");
            break;
        case THP_VIDEO_ODD_INTERLACE:
            THPPrintLog("Video Type: [Interlace ODD start]\n");
            break;
        case THP_VIDEO_EVEN_INTERLACE:
            THPPrintLog("Video Type: [Interlace EVEN start]\n");
            break;
    }

    //
    // THPFileHeaderの書込み
    //
    
    rtn = THPUtyWriteTHPFileHeader(op, fileHeader, &compInfoSize);
    if (rtn != THP_ERROR_NOERROR)
    {
        THPPrintError("\aERROR : Can't write THPFileHeader (%ld)\n", __LINE__);
        error = rtn;
        goto ERROR_END;
    }
    
    // オリジナルTHPファイルのヘッダー読込み(オーディオデータの追加・変更時)
    if (fileFlag == THP_CREATETHP_FILEFLAG_THP)
    {
        videoTHPFp = (FILE*)filePtr;
        rtn = THPUtyReadTHPFileHeader(videoTHPFp, &videoFileHeader);
        if (rtn != THP_ERROR_NOERROR)
        {
            THPPrintError("\aERROR : Can't read THPFileHeader (%ld)\n", __LINE__);
            error = rtn;
            goto ERROR_END;
        }
        
        // Seek movie data top
        rtn = fseek(videoTHPFp, videoFileHeader.header.movieDataOffsets, SEEK_SET);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
    }

    //
    // オフセットデータの書込み
    //
    // 注意：frameOffsetDataは、2フレーム目から最終フレームの最後までのオフセットの配列
    //       だが、処理の都合上、配列は1フレーム目から用意する。書き込み時には2フレーム
    //       目からとすること。
    
    frameOffsetData = (u32*)THPMalloc(sizeof(u32) * (NumFrames + 1));
    if (frameOffsetData == NULL)
    {
        THPPrintError("\aERROR : Can't allocate memory (%ld Bytes) (%ld)\n",
                      sizeof(u32) * (NumFrames + 1), __LINE__);
        error = THP_ERROR_FATAL;
        goto ERROR_END;
    }
    
    if (fileHeader->header.offsetDataOffsets)
    {
        // オフセット値のダミーライト。実際のオフセット値の書き込みは最後に。
        fileHeader->header.offsetDataOffsets
            = sizeof(THPFrameCompInfo)
              + fileHeader->header.compInfoDataOffsets + compInfoSize;
        rtn = fwrite(frameOffsetData, sizeof(u32) * NumFrames, 1, op);
        if (rtn != 1)
        {
            THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
    }
    
    //
    // 各フレームデータの書込み
    //
    
    memset(tempZero, 0, sizeof(tempZero));
    
    frameHeaderSize =
        sizeof(u32) * fileHeader->frameCompInfo.numComponents + sizeof(u32) * 2;

    THPPrintLog("START: Write THP Frame Datas.\n");
    if (THPVerboseFlag == 0)
    {
        THPPrint("  << THP Packing START >>\r");
    }
    else
    {
        THPPrint("  << THP Packing START >>\n");
    }
    
    for (i = 0; i < NumFrames; i++)
    {
        s32  currPos;
        
        if (THPVerboseFlag == 0)
        {
            THPPrint("  Now Packing: No.%5ld/%5ld\r", i, NumFrames);
        }
        else
        {
            THPPrint("  Now Packing: No.%5ld/%5ld\n", i, NumFrames);
        }
        
        frameSize = frameHeaderSize;
        
        frameOffsetData[i] = (u32)ftell(op);
        if (frameOffsetData[i] == 0xFFFFFFFF)
        {
            THPPrintError("\aERROR : ftell error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        frameHeader.frameSizePrevious = frameSizePrevious;
        
        rtn = fseek(op, frameHeaderSize, SEEK_CUR);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        for (compCnt = 0; compCnt < fileHeader->frameCompInfo.numComponents; compCnt++)
        {
            
            // Write Frame
            switch (fileHeader->frameCompInfo.frameComp[compCnt])
            {
                case THP_VIDEO_COMP: // Write Video Component
                    
                    if (fileFlag == THP_CREATETHP_FILEFLAG_JPEGS)
                    {
                        THPFileName* fileNameList = (THPFileName*)filePtr;
                        
                        rtn = THPUtyWriteVideoOneFrame(op, &fileNameList[i], &imageStatus);
                        if (rtn != THP_ERROR_NOERROR)
                        {
                            THPPrintError("\aERROR : Can't write video data (%ld)\n",
                                          __LINE__);
                            error = rtn;
                            goto ERROR_END;
                        }
                        
                        // Check Image Format
                        if (i == 0)
                        {
                            xSize = imageStatus.xSize;
                            ySize = imageStatus.ySize;
                        }
                        else if ((xSize != imageStatus.xSize) || (ySize != imageStatus.ySize))
                        {
                            THPPrintError("\aERROR : Invalid x/y size (%ld)\n", __LINE__);
                            THPPrintError("        All frames must have the same xsize\n");
                            THPPrintError("        and ysize with the 1st frame!!\n");
                            error = THP_ERROR_DATA;
                            goto ERROR_END;
                        }
                        frameHeader.comp[compCnt] = imageStatus.imageSize;
                        frameSize += imageStatus.imageSize;
                    }
                    else if (fileFlag == THP_CREATETHP_FILEFLAG_THP)
                    {
                        u32  videoFrameSize;
                        
                        rtn = THPUtyCopyVideoFrame(op,
                                                   videoTHPFp,
                                                   &videoFileHeader,
                                                   &videoFrameSize);
                        if (rtn != THP_ERROR_NOERROR)
                        {
                            THPPrintError("\aERROR : Can't write video data (%ld)\n",
                                          __LINE__);
                            error = rtn;
                            goto ERROR_END;
                        }
                        frameHeader.comp[compCnt] = videoFrameSize;
                        frameSize += videoFrameSize;
                    }
                    
                    break;
                    
                case THP_AUDIO_COMP: // Write Audio Component

                    if (audioHandleList == NULL)
                    {
                        THPPrintError("\aERROR : Input audio file is not specified (%ld)\n",
                                      __LINE__);
                        error = THP_ERROR_DATA;
                        goto ERROR_END;
                    }
                    
                    frameHeader.comp[compCnt] = THPAudioGetFrameSize(audioHandleList[0], i);
                    
                    rtn = THPUtyWriteAudioOneFrame(op,
                                                   fileHeader,
                                                   audioHandleList,
                                                   frameHeader.comp[compCnt],
                                                   i);
                    if (rtn != THP_ERROR_NOERROR)
                    {
                        THPPrintError("\aERROR : Can't write audio data (%ld)\n", __LINE__);
                        error = rtn;
                        goto ERROR_END;
                    }
                    
                    frameSize +=
                        frameHeader.comp[compCnt] * fileHeader->audioInfo.sndNumTracks;
                    
                    break;
                
                case THP_NOCOMP_COMP:
                    THPPrintError("\aERROR : Strange numComponents (%ld)\n", __LINE__);
                    error = THP_ERROR_DATA;
                    goto ERROR_END;
                    break;
                    
                default:
                    THPPrintError("\aERROR : Unsupported Components (%ld)\n", __LINE__);
                    error = THP_ERROR_DATA;
                    goto ERROR_END;
                    break;
            }
        }

        // 32Byte alignment
        if (frameSize % 32)
        {
            u32  remain = 32 - (frameSize % 32);
            rtn = fwrite(tempZero, remain, 1, op);
            if (rtn != 1)
            {
                THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }
            frameSize += remain;
        }
        
        // Get Current file position
        currPos = ftell(op);
        if (currPos == -1)
        {
            THPPrintError("\aERROR : ftell error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        rtn = fseek(op, frameOffsetData[i], SEEK_SET);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        rtn = THPUtyWriteTHPFrameHeader(op, &fileHeader->frameCompInfo, &frameHeader);
        if (rtn != THP_ERROR_NOERROR)
        {
            THPPrintError("\aERROR : Can't write THPFrameHeader (%ld)\n", __LINE__);
            error = rtn;
            goto ERROR_END;
        }
        
        if (i == 0)
        {
            frameSizeFirst = frameSize;
        }
        else
        {
            // Update Previous THPFrameHeader.frameSizeNext
            rtn = fseek(op, frameOffsetData[i - 1], SEEK_SET);
            if (rtn != 0)
            {
                THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }
            rtn = THPUtyPutU32(op, frameSize);
            if (rtn != THP_ERROR_NOERROR)
            {
                THPPrintError("\aERROR : Can't write frameSizeNext (%ld)\n", __LINE__);
                error = rtn;
                goto ERROR_END;
            }
        }
        
        // Seek next frame top
        rtn = fseek(op, currPos, SEEK_SET);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        if (frameSize > frameSizeMax)
        {
            frameSizeMax = frameSize;
        }
        frameSizePrevious  = frameSize;
        movieDataSize     += frameSize;
    }

    THPPrint("  << THP Packing END >>      \n");
    THPPrintLog("END  : Write THP Frame Datas.\n");

    //
    // 最終フレームのTHPFrameHeader.frameSizeNextの更新
    //
    
    rtn = fseek(op, frameOffsetData[NumFrames - 1], SEEK_SET);
    if (rtn != 0)
    {
        THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
        error = THP_ERROR_FILEIO;
        goto ERROR_END;
    }
    
    rtn = THPUtyPutU32(op, frameSizeFirst);
    if (rtn != THP_ERROR_NOERROR)
    {
        THPPrintError("\aERROR : Can't write frameSizeNext (%ld)\n", __LINE__);
        error = rtn;
        goto ERROR_END;
    }
    
    //
    // THPFileHeaderの更新
    //
    
    // Setup THPHeader
    fileHeader->header.version               = THP_VERSION;
    fileHeader->header.bufSize               = frameSizeMax;
    fileHeader->header.firstFrameSize        = frameSizeFirst;
    fileHeader->header.movieDataSize         = movieDataSize;
    fileHeader->header.finalFrameDataOffsets = frameOffsetData[NumFrames -1];
    fileHeader->header.movieDataOffsets      = frameOffsetData[0];
    
    // Setup THPVideoInfo
    if (fileFlag == THP_CREATETHP_FILEFLAG_JPEGS)
    {
        fileHeader->videoInfo.xSize = imageStatus.xSize;
        fileHeader->videoInfo.ySize = imageStatus.ySize;
    }
    
    // Update THPHeader, THFrameCompInfo, THPVideoInfo, THPAudioInfo
    rtn = THPUtyWriteTHPFileHeader(op, fileHeader, NULL);
    if (rtn != THP_ERROR_NOERROR)
    {
        THPPrintError("\aERROR : Can't write THPFileHeader (%ld)\n", __LINE__);
        error = rtn;
        goto ERROR_END;
    }
    
    //
    // 第1フレームのTHPFrameHeader.frameSizePreviousの更新
    //
    
    rtn = fseek(op, fileHeader->header.movieDataOffsets + sizeof(u32), SEEK_SET);
    if (rtn != 0)
    {
        THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
        error = THP_ERROR_FILEIO;
        goto ERROR_END;
    }
    rtn = THPUtyPutU32(op, frameSize);
    if (rtn != THP_ERROR_NOERROR)
    {
        THPPrintError("\aERROR : Can't write frameSizePrevious (%ld)\n", __LINE__);
        error = rtn;
        goto ERROR_END;
    }
    
    //
    // オフセットデータの書込み
    //
    
    if (fileHeader->header.offsetDataOffsets)
    {
        THPPrintLog("START: Write THP Offset Data.\n");
        THPPrint("  << Put Offset Data >>\n");
        
        // frameOffsetDataは、movidDataの先頭からのオフセットなので、値を調整する。
        for (i = 1; i < NumFrames; i++)
        {
            frameOffsetData[i]
                = bswap_32(frameOffsetData[i] - frameOffsetData[0]);
        }
        frameOffsetData[NumFrames] = bswap_32(movieDataSize);
        
        // Update THPFrameOffsetData
        rtn = fseek(op, fileHeader->header.offsetDataOffsets, SEEK_SET);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        rtn = fwrite(&frameOffsetData[1], sizeof(u32) * NumFrames, 1, op);
        if (rtn != 1)
        {
            THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        THPPrintLog("END  : Write THP Offset Data.\n");
    }
    
ERROR_END:
    
    if (frameOffsetData != NULL)
    {
        THPFree(frameOffsetData);
        frameOffsetData = NULL;
    }
    
    return error;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyChangeAudioTrack

  Description:  iopで指定されたTHPファイルのオーディオトラックをaudioHandleListで指定された
                オーディオに入れ替える。
                
  Arguments:    iop              オーディオを入れ替えるTHPファイルのファイルポインタ
                fileHeader       THPヘッダ情報を格納したTHPFileHeader構造体のポインタ
                audioHandleList  入れ替えるオーディオのハンドルのポインタのリスト
                                 配列数はfileHeader.audioInfo.sndNumTracks個必要で、入れ替え
                                 を行わないトラックに対応する配列にはNULLを格納しておく。
                
  Returns:      THP_ERROR_NOERROR     正常終了
                THP_ERROR_FILEIO      ファイル読み書き失敗
                THP_ERROR_THPFILE     THPファイル不正
 *---------------------------------------------------------------------------*/
s32 THPUtyChangeAudioTrack(FILE* iop, THPFileHeader*   fileHeader,
                                      THPAudioHandle** audioHandleList)
{
    s32  rtn;
    s32  error = THP_ERROR_NOERROR;
    u32  i;
    u32  frameHeaderSize;

    // オーディオトラックの有無をチェック
    if ((fileHeader->audioInfo.sndChannels == 0) || (fileHeader->audioInfo.sndFrequency == 0))
    {
        THPPrintError("\aERROR : This file doesn't have audio data (%ld)\n", __LINE__);
        error = THP_ERROR_THPFILE;
        goto ERROR_END;
    }
    
    // 第1フレームへ移動
    rtn = fseek(iop, fileHeader->header.movieDataOffsets, SEEK_SET);
    if (rtn != 0)
    {
        THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
        error = THP_ERROR_FILEIO;
        goto ERROR_END;
    }

    // フレームヘッダのサイズを取得
    frameHeaderSize
        = sizeof(u32) * fileHeader->frameCompInfo.numComponents + sizeof(u32) * 2;
    
    THPPrintLog("START: Write THP Frame Datas.\n");
    if (THPVerboseFlag == 0)
    {
        THPPrint("  << THP Restructuring START >>\r");
    }
    else
    {
        THPPrint("  << THP Restructuring START >>\n");
    }
    
    //
    // 各フレームのオーディオデータを差し替える
    //
    
    for (i = 0; i < fileHeader->header.numFrames; i++)
    {
        THPFrameHeader  frameHeader;
        u32             compCnt;
        s32             framePos;
        u32             frameSize;

        if (THPVerboseFlag == 0)
        {
            THPPrint("  Now Restructuring: No.%5ld/%5ld\r", i, fileHeader->header.numFrames);
        }
        else
        {
            THPPrint("  Now Restructuring: No.%5ld/%5ld\n", i, fileHeader->header.numFrames);
        }

        // 現在のファイル位置を取得
        framePos = ftell(iop);
        if (framePos == -1)
        {
            THPPrintError("\aERROR : ftell error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        // THPFrameHeaderを取得
        rtn = THPUtyReadTHPFrameHeader(iop,
                                       &frameHeader,
                                       fileHeader->frameCompInfo.numComponents);
        if (rtn != THP_ERROR_NOERROR)
        {
            THPPrintError("\aERROR : Can't read THPFrameHeader (%ld)\n", __LINE__);
            error = rtn;
            goto ERROR_END;
        }
        
        frameSize = frameHeaderSize;
        
        for (compCnt = 0; compCnt < fileHeader->frameCompInfo.numComponents; compCnt++)
        {
            
            switch (fileHeader->frameCompInfo.frameComp[compCnt])
            {
                case THP_VIDEO_COMP:
                    
                    // ビデオデータはスキップ
                    rtn = fseek(iop, frameHeader.comp[compCnt], SEEK_CUR);
                    if (rtn != 0)
                    {
                        THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
                        error = THP_ERROR_FILEIO;
                        goto ERROR_END;
                    }
                    frameSize += frameHeader.comp[compCnt];
                    break;
                    
                case THP_AUDIO_COMP:
                    
                    // オーディオデータは上書き
                    rtn = THPUtyWriteAudioOneFrame(iop,
                                                   fileHeader,
                                                   audioHandleList,
                                                   frameHeader.comp[compCnt],
                                                   i);
                    if (rtn != THP_ERROR_NOERROR)
                    {
                        THPPrintError("\aERROR : Can't write audio data (%ld)\n", __LINE__);
                        error = rtn;
                        goto ERROR_END;
                    }
                    frameSize +=
                        frameHeader.comp[compCnt] * fileHeader->audioInfo.sndNumTracks;
                    break;
                
                case THP_NOCOMP_COMP:
                    THPPrintError("\aERROR : Strange numComponents (%ld)\n", __LINE__);
                    error = THP_ERROR_THPFILE;
                    goto ERROR_END;
                    break;
                    
                default:
                    THPPrintError("\aERROR : Unsupported Components (%ld)\n", __LINE__);
                    error = THP_ERROR_THPFILE;
                    goto ERROR_END;
                    break;
            }
        }

        // 次のフレームへ移動
        frameSize = (frameSize + 31) & ~31;
        rtn = fseek(iop, framePos + frameSize, SEEK_SET);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
    }

    THPPrint("  << THP Restructuring END >>      \n");
    THPPrintLog("END  : Write THP Frame Datas.\n");
    
ERROR_END:
    
    return error;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyCopyTHPFile

  Description:  ip で指定された THP ファイルを op にコピーする

  Arguments:    ip          コピー元の THP ファイルのファイルポインタ
                fileHeader  THPFileHeader 構造体のポインタ
                op          コピー先の THP ファイルのファイルポインタ
                
  Returns:      THP_ERROR_NOERROR     正常終了
                THP_ERROR_FILEIO      ファイル読み書き失敗
                THP_ERROR_DATA        データ不正
                THP_ERROR_FATAL       メモリ確保失敗
 *---------------------------------------------------------------------------*/
#define THPUTY_COPY_SIZE         0x100000
#define THPUTY_MAX_PADDING_SIZE  32

s32 THPUtyCopyTHPFile(FILE* ip, THPFileHeader* fileHeader, FILE* op)
{
    s32  rtn;
    s32  error = THP_ERROR_NOERROR;
    u8*  tmp_buffer = NULL;
    u32* frame_offsets = NULL;
    
    //
    // コピー元の THP ファイルのバージョンが 1.10 以降の場合
    //
    
    if (fileHeader->header.version > 0x10000)
    {
        u32  file_size;
        u32  read_size;
        u32  wrote_size = 0;
        
        // テンポラリバッファを確保
        tmp_buffer = (u8*)THPMalloc(THPUTY_COPY_SIZE);
        if (tmp_buffer == NULL)
        {
            THPPrintError("\aERROR : Can't allocate memory (%ld Bytes) (%ld)\n",
                          THPUTY_COPY_SIZE, __LINE__);
            error = THP_ERROR_FATAL;
            goto ERROR_END;
        }

        // ファイルサイズ取得
        rtn = fseek(ip, 0, SEEK_END);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__); 
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
    
        file_size = ftell(ip);
        if (file_size == -1L)
        {
            THPPrintError("\aERROR : ftell error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        rtn = fseek(ip, 0, SEEK_SET);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__); 
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }

        // ファイルをそのままコピー
        while (wrote_size < file_size)
        {
            if (file_size - wrote_size < THPUTY_COPY_SIZE)
            {
                read_size = file_size - wrote_size;
            }
            else
            {
                read_size = THPUTY_COPY_SIZE;
            }
            
            rtn = fread(tmp_buffer, read_size, 1, ip);
            if(rtn != 1)
            {
                THPPrintError("\aERROR : fread error (%ld)", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }
            
            rtn = fwrite(tmp_buffer, read_size, 1, op);
            if(rtn != 1)
            {
                THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }
            
            wrote_size += read_size;
        }
        
        if (fileHeader->header.offsetDataOffsets)
        {
            THPPrint("  << Put Offset Data >>\n");
        }
    }

    //
    // コピー元の THP ファイルのバージョンが 1.00 以前の場合
    //
    
    else
    {
        u32  ii, jj;
        u32  num_frames;
        s32  compinfo_size;
        u32  old_size;
        u32  frame_size;
        u32  prev_size = 0;
        u32  first_size;
        u32  max_size = 0;
        u32  total_size = 0;
        u32  remain;
        u32  tmp_loc;
        u8   zero_buffer[THPUTY_MAX_PADDING_SIZE];
        
        THPFrameHeader*  frame_header;
        
        // ファイルポインタを最初のフレームデータに移動
        rtn = fseek(ip, fileHeader->header.movieDataOffsets, SEEK_SET);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__); 
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
    
        //
        // THPFileHeader の書込み
        //
        rtn = THPUtyWriteTHPFileHeader(op, fileHeader, &compinfo_size);
        if (rtn != THP_ERROR_NOERROR)
        {
            THPPrintError("\aERROR : Can't write THPFileHeader (%ld)\n", __LINE__);
            error = rtn;
            goto ERROR_END;
        }
        
        //
        // オフセット値のダミーライト。実際のオフセット値の書き込みは最後に。
        //
        // 注意：オフセットデータは、2 フレーム目から最終フレームの最後までのオフセットの配
        //       列だが、処理の都合上、配列は 1 フレーム目から用意する。書き込み時には 2 フ
        //       レーム目からとすること。
        //

        // フレーム数取得
        num_frames = fileHeader->header.numFrames;
        
        frame_offsets = (u32*)THPMalloc(sizeof(u32) * (num_frames + 1));
        if (frame_offsets == NULL)
        {
            THPPrintError("\aERROR : Can't allocate memory (%ld Bytes) (%ld)\n",
                          sizeof(u32) * (num_frames + 1), __LINE__);
            error = THP_ERROR_FATAL;
            goto ERROR_END;
        }
        
        if (fileHeader->header.offsetDataOffsets)
        {
            fileHeader->header.offsetDataOffsets
                = fileHeader->header.compInfoDataOffsets
                + sizeof(THPFrameCompInfo)
                + compinfo_size;
            rtn = fwrite(frame_offsets, sizeof(u32) * num_frames, 1, op);
            if (rtn != 1)
            {
                THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }
        }
        
        //
        // 各フレームデータの書込み
        //

        // パディング用データを初期化
        memset(zero_buffer, 0, sizeof(zero_buffer));

        // 第 1 フレームの旧サイズを取得
        old_size = fileHeader->header.firstFrameSize;

        for (ii = 0; ii < num_frames; ii++)
        {
            // オフセット情報の取得
            frame_offsets[ii] = (u32)ftell(op);
            if (frame_offsets[ii] == 0xFFFFFFFF)
            {
                THPPrintError("\aERROR : ftell error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }

            // 読み込み領域の確保
            tmp_buffer = THPMalloc(old_size + THPUTY_MAX_PADDING_SIZE);
            if (tmp_buffer == NULL)
            {
                THPPrintError("\aERROR : Can't allocate memory (%ld Bytes) (%ld)\n",
                              (old_size + THPUTY_MAX_PADDING_SIZE), __LINE__);
                error = THP_ERROR_FATAL;
                goto ERROR_END;
            }

            // フレームデータの読み込み
            rtn = fread(tmp_buffer, old_size, 1, ip);
            if (rtn != 1)
            {
                THPPrintError("\aERROR : fread error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }

            // パディング抜きでのフレームサイズを取得
            frame_header = (THPFrameHeader *)tmp_buffer;
            frame_size   = sizeof(u32) * (2 + fileHeader->frameCompInfo.numComponents);
            for (jj = 0; jj < fileHeader->frameCompInfo.numComponents; jj++)
            {
                frame_size += bswap_32(frame_header->comp[jj]);
            }

            // 次フレームのサイズを取得
            old_size = bswap_32(frame_header->frameSizeNext);

            // フレームヘッダーの更新 (1) - frameSizePrevious
            frame_header->frameSizePrevious = bswap_32(prev_size);
            
            // フレームデータの書き込み
            rtn = fwrite(tmp_buffer,  frame_size, 1, op);
            if (rtn != 1)
            {
                THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }
            
            // 再パディング
            if (frame_size % 32)
            {
                remain = 32 - (frame_size % 32);
                rtn = fwrite(zero_buffer, remain, 1, op);
                if (rtn != 1)
                {
                    THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
                    error = THP_ERROR_FILEIO;
                    goto ERROR_END;
                }
                frame_size += remain;
            }
            
            // 読み込み領域の解放
            THPFree(tmp_buffer);
            tmp_buffer = NULL;

            // フレームヘッダーの更新 (2) - frameSizeNext
            if (ii != 0)
            {
                tmp_loc = ftell(op);

                // ファイルポインタを前フレームデータの先頭へ巻き戻し
                rtn = fseek(op, frame_offsets[ii - 1], SEEK_SET);
                if (rtn != 0)
                {
                    THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
                    error = THP_ERROR_FILEIO;
                    goto ERROR_END;
                }
                
                // カレントフレームのサイズを書き込み (frameSizeNext は先頭)
                rtn = THPUtyPutU32(op, frame_size);
                if (rtn != THP_ERROR_NOERROR)
                {
                    THPPrintError("\aERROR : Can't write frameSizeNext (%ld)\n", __LINE__);
                    error = rtn;
                    goto ERROR_END;
                }
                
                // ファイルポインタを今フレームデータの最後に戻す
                rtn = fseek(op, tmp_loc, SEEK_SET);
                if (rtn != 0)
                {
                    THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
                    error = THP_ERROR_FILEIO;
                    goto ERROR_END;
                }
            }
            
            // サイズの継承
            prev_size = frame_size;

            // first サイズの更新 -> THPHeader.firstFrameSize に反映
            if (ii == 0)
            {
                first_size = frame_size;
            }

            // max サイズの更新 -> THPHeader.bufSize に反映
            if (frame_size > max_size)
            {
                max_size = frame_size;
            }

            // total サイズの更新 -> THPHeader.movieDataSize に反映
            total_size += frame_size;
        }
        
        //
        // 第 1 フレームの THPFrameHeader.frameSizePrevious の更新
        //
        
        rtn = fseek(op, frame_offsets[0] + sizeof(u32), SEEK_SET);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        rtn = THPUtyPutU32(op, frame_size);
        if (rtn != THP_ERROR_NOERROR)
        {
            THPPrintError("\aERROR : Can't write frameSizePrevious (%ld)\n", __LINE__);
            error = rtn;
            goto ERROR_END;
        }
        
        //
        // 最終フレームの THPFrameHeader.frameSizeNext の更新
        //
        
        rtn = fseek(op, frame_offsets[num_frames - 1], SEEK_SET);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        rtn = THPUtyPutU32(op, first_size);
        if (rtn != THP_ERROR_NOERROR)
        {
            THPPrintError("\aERROR : Can't write frameSizeNext (%ld)\n", __LINE__);
            error = rtn;
            goto ERROR_END;
        }
    
        //
        // THPHeader の更新
        //
        
        fileHeader->header.version               = THP_VERSION;
        fileHeader->header.bufSize               = max_size;
        fileHeader->header.firstFrameSize        = first_size;
        fileHeader->header.movieDataSize         = total_size;
        fileHeader->header.movieDataOffsets      = frame_offsets[0];
        fileHeader->header.finalFrameDataOffsets = frame_offsets[num_frames -1];
        
        rtn = THPUtyWriteTHPFileHeader(op, fileHeader, NULL);
        if (rtn != THP_ERROR_NOERROR)
        {
            THPPrintError("\aERROR : Can't write THPFileHeader (%ld)\n", __LINE__);
            error = rtn;
            goto ERROR_END;
        }

        //
        // オフセットデータの書き込み
        //
        
        if (fileHeader->header.offsetDataOffsets)
        {
            THPPrint("  << Put Offset Data >>\n");
            
            // 各フレームのオフセットデータは、第 1 フレームからのオフセット値
            for (ii = 1; ii < num_frames; ii++)
            {
                frame_offsets[ii]
                    = bswap_32(frame_offsets[ii] - frame_offsets[0]);
            }
            frame_offsets[num_frames] = bswap_32(total_size);
            
            rtn = fseek(op, fileHeader->header.offsetDataOffsets, SEEK_SET);
            if (rtn != 0)
            {
                THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }
            
            rtn = fwrite(&frame_offsets[1], sizeof(u32) * num_frames, 1, op);
            if (rtn != 1)
            {
                THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }
        }
    }

ERROR_END:

    if (tmp_buffer)
    {
        THPFree(tmp_buffer);
    }

    if (frame_offsets)
    {
        THPFree(frame_offsets);
    }
    
    return error;
}

/*---------------------------------------------------------------------------*
 *---------------------------------------------------------------------------*
 *                             Local Functions                               *
 *---------------------------------------------------------------------------*
 *---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*
  Name:         THPUtyWriteVideoOneFrame

  Description:  fileNameで指定されたJPEGファイルを読み込み、THP形式に変換し、thpFpで指定
                されたファイルに出力する。
                
  Arguments:    thpFp        出力するTHPファイルのファイルポインタ
                fileName     変換元のJPEGファイルのファイル名
                imageStatus  変換画像の情報を格納するTHPImageStatus構造体のポインタ
                
  Returns:      THP_ERROR_NOERROR     正常終了
                THP_ERROR_FILEIO      ファイル読み書き失敗
                THP_ERROR_JPEGFILE    JPEGファイル不正
                THP_ERROR_FATAL       メモリ確保失敗
 *---------------------------------------------------------------------------*/
static s32 THPUtyWriteVideoOneFrame(FILE* thpFp, THPFileName*    fileName,
                                                 THPImageStatus* imageStatus)
{
    FILE*  jpegFp = NULL;
    u8*    jpegBuffer = NULL;
    u8*    thpBuffer = NULL;
    s32    error = THP_ERROR_NOERROR;
    s32    rtn;

    jpegBuffer = (u8*)THPMalloc(fileName->fileSize);
    if (jpegBuffer == NULL)
    {
        THPPrintError("\aERROR : Can't allocate memory (%ld Bytes) (%ld)\n",
                      fileName->fileSize, __LINE__);
        error = THP_ERROR_FATAL;
        goto ERROR_END;
    }
    
    thpBuffer = (u8*)THPMalloc(fileName->fileSize * 2);
    if (thpBuffer == NULL)
    {
        THPPrintError("\aERROR : Can't allocate memory (%ld Bytes) (%ld)\n",
                      fileName->fileSize * 2, __LINE__);
        error = THP_ERROR_FATAL;
        goto ERROR_END;
    }
    
    jpegFp = fopen(fileName->name, "r");
    if (jpegFp == NULL)
    {
        THPPrintError("\aERROR : Can't open [%s] file (%ld)\n", fileName->name, __LINE__);
        error = THP_ERROR_FILEIO;
        goto ERROR_END;
    }
    
    rtn = fread(jpegBuffer, fileName->fileSize, 1, jpegFp); 
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fread error (%ld)", __LINE__);
        error = THP_ERROR_FILEIO;
        goto ERROR_END;
    }
    
    fclose(jpegFp);
    jpegFp = NULL;
    
    rtn = THPConvertJPEG2THP(jpegBuffer, thpBuffer, fileName->fileSize, imageStatus);
    if (rtn != THP_ERROR_NOERROR)
    {
        THPPrintError("\aERROR : Can't convert [%s] file to THP (%ld)\n",
                      fileName->name, __LINE__);
        error = rtn;
        goto ERROR_END;
    }
    
    while (imageStatus->imageSize % 4)
    {
        *(thpBuffer + imageStatus->imageSize) = 0x00;
        imageStatus->imageSize++;
    }
    
    rtn = fwrite(thpBuffer, imageStatus->imageSize, 1, thpFp);
    if (rtn != 1)
    {
        THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
        error = THP_ERROR_FILEIO;
        goto ERROR_END;
    }
    
ERROR_END:
    
    if (jpegBuffer != NULL)
    {
        THPFree(jpegBuffer);
    }
    
    if (thpBuffer != NULL)
    {
        THPFree(thpBuffer);
    }

    if (jpegFp != NULL)
    {
        fclose(jpegFp);
    }
    
    return error;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyWriteAudioOneFrame

  Description:  audioHandleListで指定された複数のオーディオを1フレーム分エンコードして、
                thpFpで指定されたファイルに出力する。
                audioHandleListの配列でNULLの要素は、frameSize分だけシークする。
                
  Arguments:    thpFp            出力するTHPファイルのファイルポインタ
                fileHeader       THPFileHeader構造体のポインタ
                audioHandleList  THPAudioHandleのポインタ配列
                                 配列数はfileHeader.audioInfo.sndNumTracks個の必要がある。
                frameSize        1フレーム分のオーディオのサイズ
                frameNum         フレーム番号
                
  Returns:      THP_ERROR_NOERROR  正常終了
                THP_ERROR_FILEIO   ファイル出力失敗
 *---------------------------------------------------------------------------*/
static s32 THPUtyWriteAudioOneFrame(FILE* thpFp, THPFileHeader*   fileHeader,
                                                 THPAudioHandle** audioHandleList,
                                                 u32              frameSize,
                                                 u32              frameNum)
{
    u32  cnt;
    u32  flag;
    s32  error = THP_ERROR_NOERROR;
    
    flag = (frameNum == (fileHeader->header.numFrames - 1)) ? 1 : 0;
    
    for (cnt = 0; cnt < fileHeader->audioInfo.sndNumTracks; cnt++)
    {
        if (audioHandleList[cnt] == NULL)
        {
            u32  rtn;
            
            rtn = fseek(thpFp, frameSize, SEEK_CUR);
            if (rtn != 0)
            {
                THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }
        }
        else
        {
            if (THPAudioWriteFrame(audioHandleList[cnt], thpFp, flag) == FALSE)
            {
                THPPrintError("\aERROR : Can't convert [%s] file to THP Audio (%ld)\n",
                              audioHandleList[cnt]->audioInfo.fileName, __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }
        }
    }
    
ERROR_END:
    
    return error;
}

/*---------------------------------------------------------------------------*
  Name:         THPUtyCopyVideoFrame

  Description:  videoTHPFpで指定されたTHPファイルからビデオデータをthpFpで指定されたファイ
                ルにコピーする。

  Arguments:    thpFp            ビデオデータのコピー先のファイルポインタ
                videoTHPFp       ビデオデータのコピー元のファイルポインタ
                videoFileHeader  コピー元のTHPファイルのヘッダ
                videoCompSize    コピーしたビデオデータのサイズを格納する先のポインタ
                
  Returns:      THP_ERROR_NOERROR     正常終了
                THP_ERROR_FILEIO      ファイル読み書き失敗
                THP_ERROR_THPFILE     THPファイル不正
                THP_ERROR_FATAL       メモリ確保失敗
 *---------------------------------------------------------------------------*/
static s32 THPUtyCopyVideoFrame(FILE* thpFp, FILE*          videoTHPFp,
                                             THPFileHeader* videoFileHeader,
                                             u32*           videoCompSize)
{
    u8*             buffer = NULL;
    u32             compCnt;
    s32             rtn;
    s32             error = THP_ERROR_NOERROR;
    u32             framePos;
    u32             frameSize;
    THPFrameHeader  frameHeader;
    
    framePos = ftell(videoTHPFp);
    if (framePos == -1)
    {
        THPPrintError("\aERROR : ftell error (%ld)\n", __LINE__);
        error = THP_ERROR_FILEIO;
        goto ERROR_END;
    }
    
    rtn = THPUtyReadTHPFrameHeader(videoTHPFp,
                                   &frameHeader,
                                   videoFileHeader->frameCompInfo.numComponents);
    if (rtn != THP_ERROR_NOERROR)
    {
        THPPrintError("\aERROR : Can't read THPFrameHeader (%ld)\n", __LINE__);
        error = rtn;
        goto ERROR_END;
    }
    
    frameSize
        = sizeof(u32) * videoFileHeader->frameCompInfo.numComponents + sizeof(u32) * 2;
    
    for (compCnt = 0; compCnt < videoFileHeader->frameCompInfo.numComponents; compCnt++)
    {
        switch (videoFileHeader->frameCompInfo.frameComp[compCnt])
        {
            case THP_VIDEO_COMP:
                    
                buffer = (u8*)THPMalloc(frameHeader.comp[compCnt]);
                if (buffer == NULL)
                {
                    THPPrintError("\aERROR : Can't allocate memory (%ld Bytes) (%ld)\n",
                                  frameHeader.comp[compCnt], __LINE__);
                    error = THP_ERROR_FATAL;
                    goto ERROR_END;
                }
                    
                rtn = fread(buffer, frameHeader.comp[compCnt], 1, videoTHPFp);
                if (rtn != 1)
                {
                    THPPrintError("\aERROR : fread error (%ld)\n", __LINE__);
                    error = THP_ERROR_FILEIO;
                    goto ERROR_END;
                }
                    
                rtn = fwrite(buffer, frameHeader.comp[compCnt], 1, thpFp);
                if (rtn != 1)
                {
                    THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
                    error = THP_ERROR_FILEIO;
                    goto ERROR_END;
                }
                    
                THPFree(buffer);
                buffer = NULL;

                frameSize += frameHeader.comp[compCnt];
                if (videoCompSize != NULL)
                {
                    *videoCompSize = frameHeader.comp[compCnt];
                }
                break;
                
            case THP_AUDIO_COMP:
                frameSize +=
                    frameHeader.comp[compCnt] * videoFileHeader->audioInfo.sndNumTracks;
                break;
                
            case THP_NOCOMP_COMP:
                THPPrintError("\aERROR : Strange numComponents (%ld)\n", __LINE__);
                error = THP_ERROR_THPFILE;
                goto ERROR_END;
                break;
                
            default:
                THPPrintError("\aERROR : Unsupported Components (%ld)\n", __LINE__);
                error = THP_ERROR_THPFILE;
                goto ERROR_END;
                break;
        }
    }
    
    frameSize = (frameSize + 31) & ~31;
    
    rtn = fseek(videoTHPFp, framePos + frameSize, SEEK_SET);
    if (rtn != 0)
    {
        THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
        error = THP_ERROR_FILEIO;
        goto ERROR_END;
    }

ERROR_END:

    if (buffer != NULL)
    { 
        THPFree(buffer);
        buffer = NULL;
    }
    
    return error;
}
