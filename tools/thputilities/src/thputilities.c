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

  Description:  fmt�Ŏw�肳�ꂽUnix�`���̃p�X��DOS�`���ɕϊ�����B
                fmt�Ŏw�肵���o�b�t�@���㏑������_�ɒ��ӁB
                
  Arguments:    fmt         �ϊ����镶����̃|�C���^
                
  Returns:      ����
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

  Description:  32bit float�l��Endian��ϊ�����B

  Arguments:    data        Endian��ϊ�����float�̒l
                
  Returns:      Endian��ϊ�����float�l
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

  Description:  32Byte�A���C�����g�ɂȂ�悤�t�@�C����NULL���o�͂���B
                
  Arguments:    op          �o�͐�̃t�@�C���|�C���^
                bytes       ���O�ɏo�͂����f�[�^�̃T�C�Y
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���o�͎��s
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

  Description:  u32�^��data���A�G���f�B�A����ϊ����Aop�Ŏw�肵���t�@�C���ɏo�͂���B
                
  Arguments:    op          �o�͐�̃t�@�C���|�C���^
                data        �o�͂���u32�^�̒l
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���o�͎��s
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

  Description:  f32�^��data���A�G���f�B�A����ϊ����Aop�Ŏw�肵���t�@�C���ɏo�͂���B
                
  Arguments:    op          �o�͐�̃t�@�C���|�C���^
                data        �o�͂���f32�^�̒l
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���o�͎��s
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

  Description:  THPHeader�\���̂�����������B
                
  Arguments:    header      THPHeader�\���̂̃|�C���^
                
  Returns:      ����
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

  Description:  THPHeader�\���̂�op�Ŏw�肵���t�@�C���ɏo�͂���B
                
  Arguments:    op          �o�͐�̃t�@�C���|�C���^
                header      �o�͂���THPHeader�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���o�͎��s
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

  Description:  THPFrameCompInfo�\���̂�op�Ŏw�肵���t�@�C���ɏo�͂���B
                
  Arguments:    op          �o�͐�̃t�@�C���|�C���^
                compinfo    �o�͂���THPFrameCompInfo�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���o�͎��s
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

  Description:  THPVideoInfo�\���̂�op�Ŏw�肵���t�@�C���ɏo�͂���B
                
  Arguments:    op          �o�͐�̃t�@�C���|�C���^
                videoinfo   �o�͂���THPVideoInfo�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���o�͎��s
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

  Description:  THPAudioInfo�\���̂�op�Ŏw�肵���t�@�C���ɏo�͂���B
                
  Arguments:    op          �o�͐�̃t�@�C���|�C���^
                audioinfo   �o�͂���THPAudioInfo�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���o�͎��s
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

  Description:  THPFrameHeader�\���̂�op�Ŏw�肵���t�@�C���ɏo�͂���B
                
  Arguments:    op             �o�͐�̃t�@�C���|�C���^
                frameCompInfo  THPFrameCompInfo�\���̂̃|�C���^
                frameHeader    �o�͂���THPFrameHeader�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���o�͎��s
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

  Description:  �\����THPVideoInfo,THPAudioinfo��op�Ŏw�肵���t�@�C���ɏo�͂���B
                
  Arguments:    op            �o�͐�̃t�@�C���|�C���^
                compinfo      THPFrameCompInfo�\���̂̃|�C���^
                videoinfo     �o�͂���THPVideoInfo�\���̂̃|�C���^
                audioinfo     �o�͂���THPAudioInfo�\���̂̃|�C���^
                compinfosize  �R�|�[�l���g�T�C�Y�̊i�[��̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���o�͎��s
                THP_ERROR_DATA     �f�[�^�s��
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

  Description:  THPFileHeader�\���̂�op�Ŏw�肵���t�@�C���ɏo�͂���B
                
  Arguments:    op            �o�͐�̃t�@�C���|�C���^
                fileHeader    �o�͂���THPFileHeader�\���̂̃|�C���^
                compInfoSize  �R�|�[�l���g�T�C�Y�̊i�[��̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���o�͎��s
                THP_ERROR_DATA     �f�[�^�s��
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

  Description:  ip�Ŏw�肵��THP�t�@�C������THPHeader�\���̂�ǂݍ��ށB
                ���炩���ߓǂݍ��݈ʒu��THPHeader�̈ʒu�ɂ��Ă����K�v������B
                
  Arguments:    ip          THP�t�@�C���̃t�@�C���|�C���^
                header      THPHeader�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���ǂݍ��ݎ��s
                THP_ERROR_THPFILE  THP�t�@�C���s��
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
    
    // magic �̃`�F�b�N
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

  Description:  ip�Ŏw�肵��THP�t�@�C������THPFrameCompInfo�\���̂�ǂݍ��ށB
                ���炩���ߓǂݍ��݈ʒu��THPFrameCompInfo�̈ʒu�ɂ��Ă����K�v������B
                
  Arguments:    ip          THP�t�@�C���̃t�@�C���|�C���^
                compinfo    THPFrameCompInfo�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���ǂݍ��ݎ��s
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

  Description:  ip�Ŏw�肵��THP�t�@�C������THPVideoInfo�\���̂�ǂݍ��ށB
                ���炩���ߓǂݍ��݈ʒu��THPVideoInfo�̈ʒu�ɂ��Ă����K�v������B
                
  Arguments:    ip          THP�t�@�C���̃t�@�C���|�C���^
                videoinfo   THPVideoInfo�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���ǂݍ��ݎ��s
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

  Description:  ip�Ŏw�肵��Ver1.0�ȑO��THP�t�@�C������THPVideoInfo�\���̂�ǂݍ���
                ���炩���ߓǂݍ��݈ʒu��THPVideoInfo�̈ʒu�ɂ��Ă����K�v������B
                
  Arguments:    ip          Ver1.0�ȑO��THP�t�@�C���̃t�@�C���|�C���^
                videoinfo   THPVideoInfo�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���ǂݍ��ݎ��s
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

  Description:  ip�Ŏw�肵��THP�t�@�C������THPAudioInfo�\���̂�ǂݍ��ށB
                ���炩���ߓǂݍ��݈ʒu��THPAudioInfo�̈ʒu�ɂ��Ă����K�v������B
                
  Arguments:    ip          THP�t�@�C���̃t�@�C���|�C���^
                audioinfo   THPAudioInfo�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���ǂݍ��ݎ��s
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

  Description:  ip�Ŏw�肵��Ver1.0�ȑO��THP�t�@�C������THPAudioInfo�\���̂�ǂݍ��ށB
                ���炩���ߓǂݍ��݈ʒu��THPAudioInfo�̈ʒu�ɂ��Ă����K�v������B
                
  Arguments:    ip          Ver1.0�ȑO��THP�t�@�C���̃t�@�C���|�C���^
                audioinfo   THPAudioInfo�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���ǂݍ��ݎ��s
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

  Description:  ip�Ŏw�肵��THP�t�@�C������THPFrameHeader�\���̂�ǂݍ��ށB
                ���炩���ߓǂݍ��݈ʒu��THPFrameHeader�ʒu�ɂ��Ă����K�v������B
                
  Arguments:    ip            THP�t�@�C���̃t�@�C���|�C���^
                frameHeader   THPFrameHeader�\���̂̃|�C���^
                componentNum  THP�t�@�C���Ɋ܂܂��R���|�[�l���g�̐�
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���ǂݍ��ݎ��s
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

  Description:  ip�Ŏw�肵��THP�t�@�C������THPFileHeader�\���̂�ǂݍ��ށB
                ���炩���ߓǂݍ��݈ʒu��THPFileHeader�ʒu�ɂ��Ă����K�v������B
                
  Arguments:    ip          THP�t�@�C���̃t�@�C���|�C���^
                fileHeader  THPFileHeader�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR     ����I��
                THP_ERROR_FILEIO      �t�@�C���ǂݍ��ݎ��s
                THP_ERROR_THPFILE     THP�t�@�C���s��
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

  Description:  fileHeader�̏��Ɋ�Â��ATHP�t�@�C���𐶐�����B

  Arguments:    op               �o�͐�̃t�@�C���|�C���^
                fileFlag         ���̓f�[�^�̃^�C�v���w�肷��t���O
                filePtr          fileFlag�ɉ��������̓f�[�^�̃|�C���^
                fileHeader       THPFileHeader�\���̂̃|�C���^�B
                audioHandleList  THPAudioHandle�\���̂̃|�C���^�̃��X�g
                
  Returns:      THP_ERROR_NOERROR     ����I��
                THP_ERROR_FILEIO      �t�@�C���ǂݏ������s
                THP_ERROR_JPEGFILE    JPEG�t�@�C���s��
                THP_ERROR_THPFILE     THP�t�@�C���s��
                THP_ERROR_DATA        �f�[�^�s��
                THP_ERROR_FATAL       �������m�ێ��s
 *---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*

   - fileFlag

     fileFlag = THP_CREATETHP_FILEFLAG_JPEGS :
        filePtr��THPFileName�\���̂̔z��Ŏw�肳�ꂽJPEG�t�@�C���̃��X�g�B
        filePtr�Ŏw�肵��JPEG�t�@�C����THP�`���ɕϊ����ATHP�t�@�C�����쐬����B
        headerHeader.header.numFrames�Ŏw�肵�����̃��X�g�̕K�v������B

     fileFlag = THP_CREATETHP_FILEFLAG_THP :
        filePtr�͓���THP�t�@�C���̃t�@�C���|�C���^�B

   - fileHeader
   
     �Ăяo���O�Ɉȉ��̃����o��ݒ肵�Ă����K�v������B
     (����ȊO�̃����o�͂��̊֐��Őݒ肳���B)
     
        [THPHeader]
        fileHeader->header.magic
        fileHeader->header.version
        fileHeader->header.frameRate
        fileHeader->header.numFrames
        fileHeader->header.compInfoDataOffsets
        fileHeader->header.offsetDataOffsets (�I�t�Z�b�g���g���ꍇ��0�ȊO�̒l��ݒ肵�Ă���)
        
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

      audioHandleList�Ŏw�肳�ꂽ������WAV�t�@�C���́A�G���R�[�h���ꂽ��A�r�f�I�f�[�^�ƃC
      ���^�[���[�u����ATHP�t�@�C���ɏo�͂����B
      �w�肳�ꂽTHPAudioHandle�\���̂�THPAudioCreateHandle�ŃI�[�v���ς݂̕K�v������B
      audioInfo.sndNumTracks���̃��X�g�ł���K�v������B
      �I�[�f�B�I��ϊ����Ȃ��ꍇ��NULL���w�肷��B
      
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
    // THPFileHeader�̏�����
    //
    
    rtn = THPUtyWriteTHPFileHeader(op, fileHeader, &compInfoSize);
    if (rtn != THP_ERROR_NOERROR)
    {
        THPPrintError("\aERROR : Can't write THPFileHeader (%ld)\n", __LINE__);
        error = rtn;
        goto ERROR_END;
    }
    
    // �I���W�i��THP�t�@�C���̃w�b�_�[�Ǎ���(�I�[�f�B�I�f�[�^�̒ǉ��E�ύX��)
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
    // �I�t�Z�b�g�f�[�^�̏�����
    //
    // ���ӁFframeOffsetData�́A2�t���[���ڂ���ŏI�t���[���̍Ō�܂ł̃I�t�Z�b�g�̔z��
    //       �����A�����̓s����A�z���1�t���[���ڂ���p�ӂ���B�������ݎ��ɂ�2�t���[��
    //       �ڂ���Ƃ��邱�ƁB
    
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
        // �I�t�Z�b�g�l�̃_�~�[���C�g�B���ۂ̃I�t�Z�b�g�l�̏������݂͍Ō�ɁB
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
    // �e�t���[���f�[�^�̏�����
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
    // �ŏI�t���[����THPFrameHeader.frameSizeNext�̍X�V
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
    // THPFileHeader�̍X�V
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
    // ��1�t���[����THPFrameHeader.frameSizePrevious�̍X�V
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
    // �I�t�Z�b�g�f�[�^�̏�����
    //
    
    if (fileHeader->header.offsetDataOffsets)
    {
        THPPrintLog("START: Write THP Offset Data.\n");
        THPPrint("  << Put Offset Data >>\n");
        
        // frameOffsetData�́AmovidData�̐擪����̃I�t�Z�b�g�Ȃ̂ŁA�l�𒲐�����B
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

  Description:  iop�Ŏw�肳�ꂽTHP�t�@�C���̃I�[�f�B�I�g���b�N��audioHandleList�Ŏw�肳�ꂽ
                �I�[�f�B�I�ɓ���ւ���B
                
  Arguments:    iop              �I�[�f�B�I�����ւ���THP�t�@�C���̃t�@�C���|�C���^
                fileHeader       THP�w�b�_�����i�[����THPFileHeader�\���̂̃|�C���^
                audioHandleList  ����ւ���I�[�f�B�I�̃n���h���̃|�C���^�̃��X�g
                                 �z�񐔂�fileHeader.audioInfo.sndNumTracks�K�v�ŁA����ւ�
                                 ���s��Ȃ��g���b�N�ɑΉ�����z��ɂ�NULL���i�[���Ă����B
                
  Returns:      THP_ERROR_NOERROR     ����I��
                THP_ERROR_FILEIO      �t�@�C���ǂݏ������s
                THP_ERROR_THPFILE     THP�t�@�C���s��
 *---------------------------------------------------------------------------*/
s32 THPUtyChangeAudioTrack(FILE* iop, THPFileHeader*   fileHeader,
                                      THPAudioHandle** audioHandleList)
{
    s32  rtn;
    s32  error = THP_ERROR_NOERROR;
    u32  i;
    u32  frameHeaderSize;

    // �I�[�f�B�I�g���b�N�̗L�����`�F�b�N
    if ((fileHeader->audioInfo.sndChannels == 0) || (fileHeader->audioInfo.sndFrequency == 0))
    {
        THPPrintError("\aERROR : This file doesn't have audio data (%ld)\n", __LINE__);
        error = THP_ERROR_THPFILE;
        goto ERROR_END;
    }
    
    // ��1�t���[���ֈړ�
    rtn = fseek(iop, fileHeader->header.movieDataOffsets, SEEK_SET);
    if (rtn != 0)
    {
        THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
        error = THP_ERROR_FILEIO;
        goto ERROR_END;
    }

    // �t���[���w�b�_�̃T�C�Y���擾
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
    // �e�t���[���̃I�[�f�B�I�f�[�^�������ւ���
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

        // ���݂̃t�@�C���ʒu���擾
        framePos = ftell(iop);
        if (framePos == -1)
        {
            THPPrintError("\aERROR : ftell error (%ld)\n", __LINE__);
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
        
        // THPFrameHeader���擾
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
                    
                    // �r�f�I�f�[�^�̓X�L�b�v
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
                    
                    // �I�[�f�B�I�f�[�^�͏㏑��
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

        // ���̃t���[���ֈړ�
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

  Description:  ip �Ŏw�肳�ꂽ THP �t�@�C���� op �ɃR�s�[����

  Arguments:    ip          �R�s�[���� THP �t�@�C���̃t�@�C���|�C���^
                fileHeader  THPFileHeader �\���̂̃|�C���^
                op          �R�s�[��� THP �t�@�C���̃t�@�C���|�C���^
                
  Returns:      THP_ERROR_NOERROR     ����I��
                THP_ERROR_FILEIO      �t�@�C���ǂݏ������s
                THP_ERROR_DATA        �f�[�^�s��
                THP_ERROR_FATAL       �������m�ێ��s
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
    // �R�s�[���� THP �t�@�C���̃o�[�W������ 1.10 �ȍ~�̏ꍇ
    //
    
    if (fileHeader->header.version > 0x10000)
    {
        u32  file_size;
        u32  read_size;
        u32  wrote_size = 0;
        
        // �e���|�����o�b�t�@���m��
        tmp_buffer = (u8*)THPMalloc(THPUTY_COPY_SIZE);
        if (tmp_buffer == NULL)
        {
            THPPrintError("\aERROR : Can't allocate memory (%ld Bytes) (%ld)\n",
                          THPUTY_COPY_SIZE, __LINE__);
            error = THP_ERROR_FATAL;
            goto ERROR_END;
        }

        // �t�@�C���T�C�Y�擾
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

        // �t�@�C�������̂܂܃R�s�[
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
    // �R�s�[���� THP �t�@�C���̃o�[�W������ 1.00 �ȑO�̏ꍇ
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
        
        // �t�@�C���|�C���^���ŏ��̃t���[���f�[�^�Ɉړ�
        rtn = fseek(ip, fileHeader->header.movieDataOffsets, SEEK_SET);
        if (rtn != 0)
        {
            THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__); 
            error = THP_ERROR_FILEIO;
            goto ERROR_END;
        }
    
        //
        // THPFileHeader �̏�����
        //
        rtn = THPUtyWriteTHPFileHeader(op, fileHeader, &compinfo_size);
        if (rtn != THP_ERROR_NOERROR)
        {
            THPPrintError("\aERROR : Can't write THPFileHeader (%ld)\n", __LINE__);
            error = rtn;
            goto ERROR_END;
        }
        
        //
        // �I�t�Z�b�g�l�̃_�~�[���C�g�B���ۂ̃I�t�Z�b�g�l�̏������݂͍Ō�ɁB
        //
        // ���ӁF�I�t�Z�b�g�f�[�^�́A2 �t���[���ڂ���ŏI�t���[���̍Ō�܂ł̃I�t�Z�b�g�̔z
        //       �񂾂��A�����̓s����A�z��� 1 �t���[���ڂ���p�ӂ���B�������ݎ��ɂ� 2 �t
        //       ���[���ڂ���Ƃ��邱�ƁB
        //

        // �t���[�����擾
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
        // �e�t���[���f�[�^�̏�����
        //

        // �p�f�B���O�p�f�[�^��������
        memset(zero_buffer, 0, sizeof(zero_buffer));

        // �� 1 �t���[���̋��T�C�Y���擾
        old_size = fileHeader->header.firstFrameSize;

        for (ii = 0; ii < num_frames; ii++)
        {
            // �I�t�Z�b�g���̎擾
            frame_offsets[ii] = (u32)ftell(op);
            if (frame_offsets[ii] == 0xFFFFFFFF)
            {
                THPPrintError("\aERROR : ftell error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }

            // �ǂݍ��ݗ̈�̊m��
            tmp_buffer = THPMalloc(old_size + THPUTY_MAX_PADDING_SIZE);
            if (tmp_buffer == NULL)
            {
                THPPrintError("\aERROR : Can't allocate memory (%ld Bytes) (%ld)\n",
                              (old_size + THPUTY_MAX_PADDING_SIZE), __LINE__);
                error = THP_ERROR_FATAL;
                goto ERROR_END;
            }

            // �t���[���f�[�^�̓ǂݍ���
            rtn = fread(tmp_buffer, old_size, 1, ip);
            if (rtn != 1)
            {
                THPPrintError("\aERROR : fread error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }

            // �p�f�B���O�����ł̃t���[���T�C�Y���擾
            frame_header = (THPFrameHeader *)tmp_buffer;
            frame_size   = sizeof(u32) * (2 + fileHeader->frameCompInfo.numComponents);
            for (jj = 0; jj < fileHeader->frameCompInfo.numComponents; jj++)
            {
                frame_size += bswap_32(frame_header->comp[jj]);
            }

            // ���t���[���̃T�C�Y���擾
            old_size = bswap_32(frame_header->frameSizeNext);

            // �t���[���w�b�_�[�̍X�V (1) - frameSizePrevious
            frame_header->frameSizePrevious = bswap_32(prev_size);
            
            // �t���[���f�[�^�̏�������
            rtn = fwrite(tmp_buffer,  frame_size, 1, op);
            if (rtn != 1)
            {
                THPPrintError("\aERROR : fwrite error (%ld)\n", __LINE__);
                error = THP_ERROR_FILEIO;
                goto ERROR_END;
            }
            
            // �ăp�f�B���O
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
            
            // �ǂݍ��ݗ̈�̉��
            THPFree(tmp_buffer);
            tmp_buffer = NULL;

            // �t���[���w�b�_�[�̍X�V (2) - frameSizeNext
            if (ii != 0)
            {
                tmp_loc = ftell(op);

                // �t�@�C���|�C���^��O�t���[���f�[�^�̐擪�֊����߂�
                rtn = fseek(op, frame_offsets[ii - 1], SEEK_SET);
                if (rtn != 0)
                {
                    THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
                    error = THP_ERROR_FILEIO;
                    goto ERROR_END;
                }
                
                // �J�����g�t���[���̃T�C�Y���������� (frameSizeNext �͐擪)
                rtn = THPUtyPutU32(op, frame_size);
                if (rtn != THP_ERROR_NOERROR)
                {
                    THPPrintError("\aERROR : Can't write frameSizeNext (%ld)\n", __LINE__);
                    error = rtn;
                    goto ERROR_END;
                }
                
                // �t�@�C���|�C���^�����t���[���f�[�^�̍Ō�ɖ߂�
                rtn = fseek(op, tmp_loc, SEEK_SET);
                if (rtn != 0)
                {
                    THPPrintError("\aERROR : fseek error (%ld)\n", __LINE__);
                    error = THP_ERROR_FILEIO;
                    goto ERROR_END;
                }
            }
            
            // �T�C�Y�̌p��
            prev_size = frame_size;

            // first �T�C�Y�̍X�V -> THPHeader.firstFrameSize �ɔ��f
            if (ii == 0)
            {
                first_size = frame_size;
            }

            // max �T�C�Y�̍X�V -> THPHeader.bufSize �ɔ��f
            if (frame_size > max_size)
            {
                max_size = frame_size;
            }

            // total �T�C�Y�̍X�V -> THPHeader.movieDataSize �ɔ��f
            total_size += frame_size;
        }
        
        //
        // �� 1 �t���[���� THPFrameHeader.frameSizePrevious �̍X�V
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
        // �ŏI�t���[���� THPFrameHeader.frameSizeNext �̍X�V
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
        // THPHeader �̍X�V
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
        // �I�t�Z�b�g�f�[�^�̏�������
        //
        
        if (fileHeader->header.offsetDataOffsets)
        {
            THPPrint("  << Put Offset Data >>\n");
            
            // �e�t���[���̃I�t�Z�b�g�f�[�^�́A�� 1 �t���[������̃I�t�Z�b�g�l
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

  Description:  fileName�Ŏw�肳�ꂽJPEG�t�@�C����ǂݍ��݁ATHP�`���ɕϊ����AthpFp�Ŏw��
                ���ꂽ�t�@�C���ɏo�͂���B
                
  Arguments:    thpFp        �o�͂���THP�t�@�C���̃t�@�C���|�C���^
                fileName     �ϊ�����JPEG�t�@�C���̃t�@�C����
                imageStatus  �ϊ��摜�̏����i�[����THPImageStatus�\���̂̃|�C���^
                
  Returns:      THP_ERROR_NOERROR     ����I��
                THP_ERROR_FILEIO      �t�@�C���ǂݏ������s
                THP_ERROR_JPEGFILE    JPEG�t�@�C���s��
                THP_ERROR_FATAL       �������m�ێ��s
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

  Description:  audioHandleList�Ŏw�肳�ꂽ�����̃I�[�f�B�I��1�t���[�����G���R�[�h���āA
                thpFp�Ŏw�肳�ꂽ�t�@�C���ɏo�͂���B
                audioHandleList�̔z���NULL�̗v�f�́AframeSize�������V�[�N����B
                
  Arguments:    thpFp            �o�͂���THP�t�@�C���̃t�@�C���|�C���^
                fileHeader       THPFileHeader�\���̂̃|�C���^
                audioHandleList  THPAudioHandle�̃|�C���^�z��
                                 �z�񐔂�fileHeader.audioInfo.sndNumTracks�̕K�v������B
                frameSize        1�t���[�����̃I�[�f�B�I�̃T�C�Y
                frameNum         �t���[���ԍ�
                
  Returns:      THP_ERROR_NOERROR  ����I��
                THP_ERROR_FILEIO   �t�@�C���o�͎��s
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

  Description:  videoTHPFp�Ŏw�肳�ꂽTHP�t�@�C������r�f�I�f�[�^��thpFp�Ŏw�肳�ꂽ�t�@�C
                ���ɃR�s�[����B

  Arguments:    thpFp            �r�f�I�f�[�^�̃R�s�[��̃t�@�C���|�C���^
                videoTHPFp       �r�f�I�f�[�^�̃R�s�[���̃t�@�C���|�C���^
                videoFileHeader  �R�s�[����THP�t�@�C���̃w�b�_
                videoCompSize    �R�s�[�����r�f�I�f�[�^�̃T�C�Y���i�[�����̃|�C���^
                
  Returns:      THP_ERROR_NOERROR     ����I��
                THP_ERROR_FILEIO      �t�@�C���ǂݏ������s
                THP_ERROR_THPFILE     THP�t�@�C���s��
                THP_ERROR_FATAL       �������m�ێ��s
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
