/*---------------------------------------------------------------------------*
  Project:  Revolution THP Converting tool
  File:     THPConv.c

  Copyright (C)2002-2006 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.2  2006/12/21 07:07:22  aka
  Removed resampling code.

  Revision 1.1  2006/02/08 02:55:34  aka
  Imported from Dolphin Tree.

    
    22    03/12/24 4:20p Akagi
    Revised frame rate check.
    
    21    03/12/24 1:36p Akagi
    Removed a function copyFile().
    Changed calling from copyFile() to THPUtyCopyTHPFile().
    Added frame rate check.
    
    20    03/12/08 2:27p Akagi
    Revised 2 error messages.
    
    19    03/09/21 6:48p Akagi
    Added several file checks.
    
    18    03/09/18 10:07a Akagi
    Added option check.
    
    17    03/09/17 9:59p Akagi
    Fixed some bugs.
    
    16    03/07/03 2:58p Akagi
    Fixed 2 trivial bugs.
    
    15    03/07/03 11:09a Akagi
    Renamed some functions.
    
    14    03/07/02 4:20p Akagi
    Renamed from THPConv_main.c to THPConv.c.
    
    13    03/07/02 4:13p Akagi
    Rewrote with DolphinSDK coding style.
    
    12    03/07/02 1:02p Akagi
    Modified appendAudioData().
    
    11    03/07/01 2:55p Akagi
    Modified to divide old THPConv.exe into 2 DLLs and 1 EXE by
    Ohki-san@NTSC.
    
    10    03/07/01 9:54a Akagi
    Moved from securebuild/tools.
    
    9     02/10/16 11:28a Akagi
    JPEG & WAV file Name bug fixed. (by iRD  tsuji)
    
    8     02/05/30 2:21p Akagi
    Stop to support QuickTime MJPEG By Tsuji (IRD) 
    
    7     02/05/27 9:45a Akagi
    Modified output error messages in English, by Tsuji (IRD)
    
    6     02/05/08 2:31p Akagi
    modified [-trk] option By Tsuji (IRD)
    
    5     02/05/01 3:09p Akagi
    added JPEG files sort program. By Tsuji (IRD)
    
    4     02/03/28 11:15a Akagi
    modified by Tsuji (IRD)

    2     02/01/22 10:10a Akagi
    Add error message, when can't load "dsptools.dll" by Tsuji.
    
    1     02/01/16 4:58p Akagi
    Initial revision made by Tsuji-san (IRD).
    
  $NoKeywords: $
  
 *---------------------------------------------------------------------------*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <unistd.h>
#include <glob.h>

#include <revolution/types.h>
#include <revolution/thpfile.h>
#include <win32/thpcommon.h>
#include <win32/thpcore.h>
#include <win32/thputilities.h>
#include <win32/thpaudio.h>

//-----------------------------------------------------------------------------
// <�g�p���Ă��� THP ���C�u�����֐�>
//
// #include <win32/thputilities.h>
//
//    THPUtyConvertToUnixFmt()
//    THPUtyHeaderInit()
//    THPUtyCreateTHP()
//    THPUtyChangeAudioTrack()
//    THPUtyReadTHPFileHeader()
//    THPUtyCopyTHPFile()
//
// #include <win32/thpaudio.h>
//
//    THPAudioInit()
//    THPAudioCreateHandle()
//    THPAudioGetInfo()
//    THPAudioGetMaxFrameSamples()
//    THPAudioGetTotalSamples()
//    THPAudioQuit()
//    THPAudioFreeHandle()
//    
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//      Define
//-----------------------------------------------------------------------------
#define TMP_FILENAME "__tmp_VD"

//-----------------------------------------------------------------------------
//      Static Value
//-----------------------------------------------------------------------------
static char** jpegFilesPtr = NULL;                 // JPEG File name string array pointer
static u32    num_JPGfiles = 0;                    // number of JPG files 

static char** waveFilesPtr = NULL;                 // WAV File name string array pointer 
static u32    num_WAVfiles = 0;                    // number of WAV files

static char*  inFile  = NULL;                      // input filename
static char*  outFile = NULL;                      // output filename

static u32    pack_jpegs       = 0;                // convert jpegs files to THP flag (-j)
static u32    change_snd_data  = 0;                // change sound data flag (-c)
static u32    change_alltrack  = 0;                // change all track data flag (-s)
static u32    change_onetrack  = 0;                // change one track data flag (-trk)
static u8     change_framerate = 0;                // change framerate (-r)
static u8     change_videotype = 0;                // change videotype (-non/odd/even)
static u32    offset_mode      = 0;                // offset flag (-o)

static f32    frame_rate = 29.97F;                 // frame rate
static u32    videotype  = THP_VIDEO_NON_INTERLACE;// Video Type

static u8     trackNo = 0;                         // track # (-trk)

static u32    Convert_Verbose = 0;

//-----------------------------------------------------------------------------
//      Function
//-----------------------------------------------------------------------------
static void Usage                   ( const char* progName );
static s32  verifyWriteOverInputData( const char* fileName );
static u32  getFileNameList         ( const char *sWildcardPattern, THPFileName* filename );
static int  compare                 ( const void *arg1, const void *arg2 );
static s32  checkArguments          ( u32 argument_count, char *argv[] );
static s32  convertJPEGtoTHP        ( void );
static s32  changeAudioTrack        ( THPFileHeader* fileHeader );
static s32  appendAudioData         ( THPFileHeader* fileHeader );
static s32  changeAudioData         ( void );
static void logPrintFunc            ( const char* format, va_list argptr );

/*---------------------------------------------------------------------------*
  Name:         Usage

  Description:  �R�}���h�̎g�����̕\��

  Arguments:    progName    �v���O�������̃|�C���^

  Returns:      ����
 *---------------------------------------------------------------------------*/
static void Usage(const char* progName)
{
    fprintf(stderr, "usage: %s [-OPTIONS]\n", progName);
    fprintf(stderr, "\n");
    fprintf(stderr, "  <<JPEGs -> THP>>\n");
    fprintf(stderr, "  -j   [*.jpg]               # some JPEGs are packed into one file\n");
    fprintf(stderr, "  -d   [file.thp]            # output THP file name\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  <SubOptions>\n");
    fprintf(stderr, "  -s   [file.wav] [file.wav] [file.wav] ...\n");
    fprintf(stderr, "                             # input WAV file names\n");
    fprintf(stderr, "  -o                         # put offset data in THP\n");
    fprintf(stderr, "  -r   [f32 number]          # set FrameRate (default is 29.97)\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  (THP Video Type)\n");
    fprintf(stderr, "  -non                       # default Video Type NON  Interlace\n");
    fprintf(stderr, "  -odd                       # set     Video Type ODD  Interlace\n");
    fprintf(stderr, "  -even                      # set     Video Type EVEN Interlace\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  -v                         # verbose mode\n");
    fprintf(stderr, "  -h                         # show this usage\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  ------------------------------------------------------------------\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  <<Change THP sound file Data>>\n");
    fprintf(stderr, "  -c   [file.thp]            # input THP file name\n");
    fprintf(stderr, "  -s   [file.wav] [file.wav] [file.wav] ...\n");
    fprintf(stderr, "                             # input WAV file names\n");
    fprintf(stderr, "  -trk [u8 track No.] [file.wav] \n");
    fprintf(stderr, "                             # change Track No.[0... ] & input WAV file name\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  <SubOptions>\n");
    fprintf(stderr, "  -d   [file.thp]            # output THP file name\n");
    fprintf(stderr, "  -o                         # put offset data in THP\n");
    fprintf(stderr, "  -r   [f32 number]          # set FrameRate (default is 29.97)\n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  (THP Video Type)\n");
    fprintf(stderr, "  -non                       # default Video Type NON  Interlace \n");
    fprintf(stderr, "  -odd                       # set     Video Type ODD  Interlace \n");
    fprintf(stderr, "  -even                      # set     Video Type EVEN Interlace \n");
    fprintf(stderr, "\n");
    fprintf(stderr, "  -v                         # verbose mode\n");
    fprintf(stderr, "  -h                         # show this usage\n");
    fprintf(stderr, "\n");
}

/*---------------------------------------------------------------------------*
  Name:         verifyWriteOverInputData

  Description:  ���̓t�@�C���̏㏑���̊m�F

  Arguments:    fileName    �t�@�C�����̃|�C���^
                
  Returns:      TRUE        �㏑������
                FALSE       �㏑���s����
 *---------------------------------------------------------------------------*/
static s32 verifyWriteOverInputData(const char* fileName)
{
    char  answer    = 0;
    u8    loop_flag = 1;
    
    while (loop_flag)
    {            
        printf("\a>Overwrite the inputfile[%s] by OutputData ? [Y/N] ", fileName);
        answer = toupper(getchar());
        
        if (answer == 'Y')
        {        
            loop_flag = 0;
        }
        else if (answer == 'N')
        {
            printf("\a\n Please try using [-d] option.\n");
            return FALSE;
        }
        else
        {
            // Loop //
        }
    }
    
    return TRUE;
}

/*---------------------------------------------------------------------------*
  Name:         getFileNameList

  Description:  sWildcardPattern �Ƀ}�b�`����t�@�C�������������āA�S�� filename �Ɋi�[����B
                ���炩���� filename �̃o�b�t�@���m�ۂ��Ă����K�v������B

  Arguments:    sWildcardPattern  ���C���h�J�[�h���܂ރt�@�C����
                filename          �t�@�C�������i�[����o�b�t�@
                
  Returns:      �t�@�C����
 *---------------------------------------------------------------------------*/
static u32 getFileNameList(const char *sWildcardPattern, THPFileName* filename)
{
    u32              f_count;
    glob_t           files;
    
    if (glob(sWildcardPattern, 0, NULL, &files))
    {
        return 0;
    }
    
    if (filename)
    {
        for (f_count = 0; f_count < files.gl_pathc; ++f_count)
        {
            strcpy(filename[f_count].name, files.gl_pathv[f_count]);
            
            struct stat file;
            stat(files.gl_pathv[f_count], &file);
            filename[f_count].fileSize = file.st_size;
        }
    }
    else
    {
        f_count = files.gl_pathc;
    }
    
    globfree(&files);
    
    if (filename != NULL)
    {
        qsort(filename, f_count, sizeof(THPFileName), compare);
    }
    
    return f_count++;
}

/*---------------------------------------------------------------------------*
  Name:         compare

  Description:  qsort() �Ɏw�肷���r�֐�

  Arguments:    arg1, arg2  ��r����v�f
                
  Returns:      ���̒l      arg1 < arg2 �̏ꍇ
                0           arg1 = arg2 �̏ꍇ
                ���̒l      arg1 > arg2 �̏ꍇ
 *---------------------------------------------------------------------------*/
static int compare(const void *arg1, const void *arg2)
{
    // 2�̕�������Ō�܂Ŕ�r
    return strcmp(((THPFileName *)arg1)->name, ((THPFileName *)arg2)->name);
}

/*---------------------------------------------------------------------------*
  Name:         checkArguments

  Description:  �����̃`�F�b�N

  Arguments:    argument_count  �����̐�
                argv            �����̕�����̔z��
                
  Returns:      TRUE        ����I��
                FALSE       �G���[�I��
                (������ "-h" �̏ꍇ�͑� exit(0) ����)
 *---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*
  [�t���O]

  <�K�{>
  
  -j �I�v�V���� : �A�� JPEG �t�@�C��(�Q) ���� THP �t�@�C�����쐬
    �A�� JPEG �t�@�C���w��t���O   pack_jpegs           : 0    -> 1
    �A�� JPEG �t�@�C���̃t�@�C���� jpegFilesPtr         : NULL -> XXXX
    �A�� JPEG �t�@�C���̐�         num_JPGfiles         : 0    -> XX

  -c �I�v�V���� : ���� THP �t�@�C���̉����f�[�^�������ւ�
    ���� THP �t�@�C���w��t���O    change_snd_data      : 0    -> 1
    ���� THP �t�@�C���̃t�@�C����  inFile               : NULL -> XXXX

  *** -j �� -c �͔r�� ***

  <���K�{>
  
  -d �I�v�V����
    �o�� THP �t�@�C����            outFile              : NULL -> XXXX

  *** -j �w�莞�͕K�{ / -c �w�莞�͖����Ă��悢 ***
  
  -s �I�v�V����
    ���� WAV �t�@�C���w��t���O    change_alltrack      : 0    -> 1
    ���� WAV �t�@�C���̃t�@�C����  waveFilesPtr         : NULL -> XXXX
    ���� WAV �t�@�C���̐�          num_WAVfiles         : 0    -> XX

  *** -j �w�莞�͖����Ă��悢 ***
  
  -trk �I�v�V����
    �����g���b�N�̓���ւ��t���O   change_onetrack      : 0    -> 1
    ����ւ� WAV �t�@�C����        waveFilesPtr         : NULL -> XXXX
    ����ւ��g���b�N�ԍ�           trackNo              : 0    -> XX

  *** -j �w�莞�͖��� / -c �w�莞�� -s �� -trk �͔r���Ȃ���ǂ��炩�K�{ ***

  <���̑�>
  
  -r �I�v�V����
    �t���[�����[�g�w��t���O       change_framerate     : 0    -> 1
    �t���[�����[�g                 frame_rate           : 29.97f -> XXXXXX

  -o �I�v�V����
    �I�t�Z�b�g�e�[�u���쐬�t���O   offset_mode          : 0    -> 1

  -non/odd/even �I�v�V����
    �\���J�n�t�B�[���h�w��t���O   change_videotype     : 0    -> 1
    �w��t�B�[���h                 videotype            : THP_VIDEO_NON_INTERLACE -> XXXXX
    
  *** -trk �w�莞�͖��� ***
  
  -v �I�v�V����
    �璷���[�h�t���O               Convert_Verbose      : 0    -> 1

 *---------------------------------------------------------------------------*/

static s32 checkArguments(u32 argument_count, char *argv[])
{
    u32  i;

    if (argument_count < 2)
    {
        Usage(argv[0]);
        exit(0);
    }
    
    // Check Options //
    for (i = 1; i < argument_count; i++)
    {
        if (argv[i][0] == '-')
        {
            u8* option = argv[i];

            //
            // -j : specify input JPEG file(s)
            //
            if (strcmp(option, "-j") == 0)
            {
                // -j (pack_jpegs = 1) �� -c (change_snd_data) �͔r��
                if (change_snd_data)
                {
                    printf("\aERROR : Can't use both [-j] and [-c] at the same time.\n");
                    return FALSE;
                }

                // -j �̎w��� 1 ��̂�
                if (pack_jpegs)
                {
                    printf("\aERROR : [-j] is specified twice.\n");
                    return FALSE;
                }
                
                // �㑱����t�@�C�����̗L�����`�F�b�N
                i++;
                if (i >= argument_count)
                {
                    printf("\aERROR : Must specify input filename after [-j].\n");
                    return FALSE;
                }
                
                jpegFilesPtr = &argv[i];
                
                // �w�� JPEG �t�@�C���̐����`�F�b�N
                while (i < argument_count && argv[i][0] != '-')
                {
                    num_JPGfiles++;
                    i++;
                }
                
                if (num_JPGfiles == 0)
                {
                    printf("\aERROR : There is no jpeg file after [-j].\n");
                    return FALSE;
                }
                
                i--;
                pack_jpegs = 1;
            }

            //
            // -c : specify input THP file
            //
            else if (strcmp(option, "-c") == 0)
            {
                // -j (pack_jpegs = 1) �� -c (change_snd_data) �͔r��
                if (pack_jpegs)
                {
                    printf("\aERROR : Can't use both [-j] and [-c] at the same time.\n");
                    return FALSE;
                }

                // -c �̎w��� 1 ��̂�
                if (change_snd_data)
                {
                    printf("\aERROR : [-c] is specified twice.\n");
                    return FALSE;
                }
                
                // �㑱����t�@�C�����̗L�����`�F�b�N
                i++;
                if (i >= argument_count || argv[i][0] == '-')
                {
                    printf("\aERROR : Must specify input filename after [-c].\n");
                    return FALSE;
                }

                // ���� THP �t�@�C�����擾
                inFile = argv[i];
                THPUtyConvertToUnixFmt(inFile);
                
                change_snd_data = 1;
            }

            //
            // -d : specify output THP file name
            //
            else if (strcmp(option, "-d") == 0)
            {
                // -d �̎w��� 1 ��̂�
                if (outFile)
                {
                    printf("\aERROR : [-d] is specified twice.\n");
                    return FALSE;
                }
                
                // �㑱����t�@�C�����̗L�����`�F�b�N
                i++;
                if (i >= argument_count || argv[i][0] == '-')
                {
                    printf("\aERROR : Must specify output THP filename after [-d].\n");
                    return FALSE;
                }

                // �o�� THP �t�@�C�����擾
                outFile = argv[i];
                THPUtyConvertToUnixFmt(outFile);
            }

            //
            // -s : specify input WAV file(s)
            //
            else if (strcmp(option, "-s") == 0)
            {
                // -s (change_alltrack = 1) �� -trk (change_onetrack) �͔r��
                if (change_onetrack)
                {
                    printf("\aERROR : Can't use both [-s] and [-trk] at the same time.\n");
                    return FALSE;
                }

                // -s �̎w��� 1 ��̂�
                if (change_alltrack)
                {
                    printf("\aERROR : [-s] is specified twice.\n");
                    return FALSE;
                }
                
                // �㑱����t�@�C�����̗L�����`�F�b�N
                i++;
                if (i >= argument_count)
                {
                    printf("\aERROR : Must specify input filename after [-s].\n");
                    return FALSE;
                }
                
                waveFilesPtr = &argv[i];
                
                // �w�� wav �t�@�C���̐����`�F�b�N
                while ((i < argument_count) && argv[i][0] != '-')
                {
                    num_WAVfiles++;
                    i++;
                }
                
                if (num_WAVfiles == 0)
                {
                    printf("\aERROR : There is no WAV file after [-s].\n");
                    return FALSE;
                }
                
                i--;
                change_alltrack = 1;
            }

            //
            // -trk : specify track number and input WAV file
            //
            else if (strcmp(option, "-trk") == 0)
            {
                // -s (change_alltrack = 1) �� -trk (change_onetrack) �͔r��
                if (change_alltrack)
                {
                    printf("\aERROR : Can't use both [-s] and [-trk] at the same time.\n");
                    return FALSE;
                }

                // -trk �̎w��� 1 ��̂�
                if (change_onetrack)
                {
                    printf("\aERROR : [-trk] is specified twice.\n");
                    return FALSE;
                }
                
                // �㑱����g���b�N�ԍ��y�уt�@�C�����̗L�����`�F�b�N
                i++;
                if (i + 1 >= argument_count)
                {
                    printf("\aERROR : Must specify trackNo and input filename after [-trk].\n");
                    return FALSE;
                }

                // �g���b�N�ԍ����擾
                if (argv[i][0] < '0' || argv[i][0] > '9')
                {
                    printf("\aERROR : Invalid trackNo.\n");
                    return FALSE;
                }
                
                trackNo = atoi(argv[i]);

                // ���� wav �t�@�C�������擾
                i++;
                if (i >= argument_count || argv[i][0] == '-')
                {
                    printf("\aERROR : Must specify trackNo and input filename after [-trk].\n");
                    return FALSE;
                }
                waveFilesPtr = &argv[i];
                THPUtyConvertToUnixFmt(waveFilesPtr[0]);
                
                change_onetrack = 1;
            }

            //
            // -r : specify frame rate
            //
            else if (strcmp(option, "-r") == 0)
            {
                // �㑱����w��t���[�����[�g�̗L�����`�F�b�N
                i++;
                if (i >= argument_count)
                {
                    printf("\aERROR : Must specify output framerate after [-r].\n");
                    return FALSE;
                }

                // �t���[�����[�g�擾
                frame_rate = (f32)atof(argv[i]);
                if (frame_rate > 59.94 ||  frame_rate < 1.0)
                {
                    printf("\aERROR : Framarate should be between 1.0 to 59.94.\n");
                    return FALSE;
                }
                
                change_framerate = 1;
            }

            //
            // -o : specify making an offset table
            //
            else if (strcmp(option, "-o") == 0)
            {
                offset_mode = 1;
            }

            //
            // -non : specify video type non-interlace
            //
            else if (strcmp(option, "-non") == 0)
            {
                if (change_videotype)
                {
                    printf("\aERROR : Already used -non/odd/even.\n");
                    return FALSE;
                }

                videotype = THP_VIDEO_NON_INTERLACE;
                change_videotype = 1;
            }

            //
            // -odd : specify video type interlace beginning from odd field
            //
            else if (strcmp(option, "-odd") == 0)
            {
                if (change_videotype)
                {
                    printf("\aERROR : Already used -non/odd/even.\n");
                    return FALSE;
                }

                videotype = THP_VIDEO_ODD_INTERLACE;
                change_videotype = 1;
            }

            //
            // -even : specify video type interlace beginning from even field
            //
            else if (strcmp(option, "-even") == 0)
            {
                if (change_videotype)
                {
                    printf("\aERROR : Already used -non/odd/even.\n");
                    return FALSE;
                }

                videotype = THP_VIDEO_EVEN_INTERLACE;
                change_videotype = 1;
            }

            //
            // -v : specify setting verbose mode
            //
            else if (strcmp(option, "-v") == 0)
            {
                Convert_Verbose = 1;
            }

            //
            // -on : old option
            //
            else if (strcmp(option, "-on") == 0)
            {
                ;
            }

            //
            // -h : specify displaying usage
            //
            else if (strcmp(option, "-h") == 0)
            {
                Usage(argv[0]);
                exit(0);
            }

            //
            // etc.
            //
            else
            {
                printf("\aERROR : Unknown option <%s>.\n", option);
                return FALSE;
            }
            
        } // if (argv[i][0] == '-')

        // invalid argument
        else
        {
            printf("\aERROR : Invalid arguments!\n");
            return FALSE;
            
        } // if (argv[i][0] == '-')
        
    } // for (i = 1; i < argument_count; i++)


    // �R���o�[�g (-j : pack_jpegs = 1) �����������ւ� (-c : change_snd_data = 1) �̂ǂ���
    // �����w�肳��Ă��邩�`�F�b�N�B
    if (!pack_jpegs && !change_snd_data)
    {
        printf("\aERROR : Must input either [-j] or [-c].\n");
        return FALSE;
    }
    
    // JPEG ���� THP �ւ̃R���o�[�g���� (-j : pack_jpegs = 1)�A�o�� THP �t�@�C�����w�肳��
    // �Ă��� (-d : outFile != NULL) ���`�F�b�N�B
    if (pack_jpegs)
    {
        if (outFile == NULL)
        {
            printf("\aERROR : Must specify output THP filename [-d] [file.thp].\n");
            return FALSE;
        }
    }
    
    // THP �̉����f�[�^�����ւ����� (-c : change_snd_data = 1)�A���� WAV �t�@�C�����w�肳��
    // �Ă��� (-s : change_alltrack = 1 or -trk : change_one_track = 1) ���`�F�b�N�B
    if (change_snd_data)
    {
        if (!change_alltrack && !change_onetrack)
        {
            printf("\aERROR : Must input [-s] [file.wav] or [-trk] [track No.] [file.wav].\n");
            return FALSE;
        }
    }

    return TRUE;
}

/*---------------------------------------------------------------------------*
  Name:         convertJPEGtoTHP

  Description:  �A�� JPEG �t�@�C���� THP �f�[�^�ɕϊ�

  Arguments:    ����
                
  Returns:      TRUE        ����I��
                FALSE       �G���[�I��
 *---------------------------------------------------------------------------*/
static s32 convertJPEGtoTHP(void)
{
    s32               rtn;
    s32               error = TRUE;
    u32               cnt;
    FILE*             thpFp = NULL;
    THPFileName*      jpegFileList = NULL;
    THPAudioHandle**  audioHandle = NULL;
    THPFileHeader     fileHeader;

    //
    // JPEG �t�@�C�����X�g�̍쐬
    //
    if (num_JPGfiles == 1)
    {
        // 1 �� JPEG �t�@�C���������̓��C���h�J�[�h�w��̏ꍇ
        
        THPUtyConvertToUnixFmt(jpegFilesPtr[0]);

        // JPEG �t�@�C�������m�F
        num_JPGfiles = getFileNameList(jpegFilesPtr[0], NULL);
        if (num_JPGfiles == 0)
        {
            printf("\aERROR : There is no jpeg files. Input right argument.\n");
            error = FALSE;
            goto ERROR_END;
        }
        
        jpegFileList = (THPFileName*)malloc(sizeof(THPFileName) * num_JPGfiles);
        if (jpegFileList == NULL)
        {
            printf("\aERROR : Can't alloc memory.\n");
            error = FALSE;
            goto ERROR_END;
        }

        // JPEG �t�@�C�����ۑ�
        getFileNameList(jpegFilesPtr[0], jpegFileList);
    }
    
    else
    {
        // ���� JPEG �t�@�C���w��̏ꍇ
        
        jpegFileList = (THPFileName*)malloc(sizeof(THPFileName) * num_JPGfiles); 
        if (jpegFileList == NULL)
        {
            printf("\aERROR : Can't alloc memory.\n");
            error = FALSE;
            goto ERROR_END;
        }
        
        for (cnt = 0; cnt < num_JPGfiles; cnt++)
        {
            struct stat  statBuf;
            char         *ext;
            size_t       nameLen;

            // JPEG �t�@�C�����ۑ�
            strcpy(jpegFileList[cnt].name, jpegFilesPtr[cnt]);
            THPUtyConvertToUnixFmt(jpegFileList[cnt].name);
            
            // �g���q�̊m�F
            nameLen = strlen(jpegFileList[cnt].name);
            ext = jpegFileList[cnt].name + nameLen;
            if ((nameLen < 4 || strcasecmp(ext - 4, ".jpg")) &&
                (nameLen < 5 || strcasecmp(ext - 5, ".jpeg")))
            {
                printf("\aERROR : Please input filename is [***.jpg] or [***.jpeg].\n");
                error = FALSE;
                goto ERROR_END;
            }
            
            // JPEG �t�@�C���̃T�C�Y�擾
            rtn = stat(jpegFileList[cnt].name, &statBuf);
            if (rtn != 0)
            {
                printf("\aERROR : Can't get JPEG file status!\n");
                error = FALSE;
                goto ERROR_END;
            }
            
            jpegFileList[cnt].fileSize = statBuf.st_size;
        }
    }
    
    if (Convert_Verbose)
    {
        printf("Total Frames = %ld\n", num_JPGfiles);
        printf("Frame Rate   = %f\n",  frame_rate);
    }
    
    // THPHeader �ݒ�
    THPUtyHeaderInit(&fileHeader.header);
    fileHeader.header.frameRate           = frame_rate;
    fileHeader.header.numFrames           = num_JPGfiles;
    fileHeader.header.compInfoDataOffsets = sizeof(THPHeader);
    fileHeader.header.offsetDataOffsets   = offset_mode;
    
    // THPFrameCompInfo �ݒ�
    fileHeader.frameCompInfo.frameComp[0] = THP_VIDEO_COMP;
    fileHeader.frameCompInfo.numComponents = 1;
    for (cnt = 1; cnt < THP_COMP_MAX; cnt++)
    {
        fileHeader.frameCompInfo.frameComp[cnt] = THP_NOCOMP_COMP;
    }
    
    // THPVideoInfo �ݒ�
    fileHeader.videoInfo.videoType = videotype;
    
    // �I�[�f�B�I�f�[�^�̃G���R�[�h�ݒ�
    if (change_alltrack)
    {
        if (Convert_Verbose)
        {
            printf("START: Audio Initializing.\n");
        }
        
        if (THPAudioInit() == FALSE)
        {
            printf("\aERROR : Fail to execute THPAudioInit().\n");
            error = FALSE;
            goto ERROR_END;
        }

        audioHandle = (THPAudioHandle**)malloc(sizeof(THPAudioHandle*) * num_WAVfiles);
        if (audioHandle == NULL)
        {
            printf("\aERROR : Can't alloc memory.\n");
            error = FALSE;
            goto ERROR_END;
        }

        // WAV �t�@�C�����X�g�쐬
        for (cnt = 0; cnt < num_WAVfiles; cnt++)
        {
            THPUtyConvertToUnixFmt(waveFilesPtr[cnt]);
            
            audioHandle[cnt] = THPAudioCreateHandle(waveFilesPtr[cnt], frame_rate);
            if (audioHandle[cnt] == NULL)
            {
                printf("\aERROR : Fail to execute THPAudioCreateHandle().\n");
                error = FALSE;
                goto ERROR_END;
            }
        }
        
        // Main Sound
        rtn = THPAudioGetInfo(audioHandle[0], &fileHeader.audioInfo);
        if (rtn == FALSE)
        {
            printf("\aERROR : Fail to execute THPAudioGetInfo().\n");
            error = FALSE;
            goto ERROR_END;
        }
        
        if (Convert_Verbose)
        {               
            printf("    [AudioData]:(%2ld Tracks)\n", num_WAVfiles);
            printf("     >> Channels  = %ld\n", fileHeader.audioInfo.sndChannels);
            printf("     >> Frequency = %ld\n", fileHeader.audioInfo.sndFrequency);
            printf("    <+> Track%02d <= [%s]\n", 0, waveFilesPtr[0]);
        }
        
        // Sub Sound
        for (cnt = 1; cnt < num_WAVfiles; cnt++)
        {
            THPAudioInfo  subAudioInfo;
            
            rtn = THPAudioGetInfo(audioHandle[cnt], &subAudioInfo);
            if (rtn == FALSE)
            {
                printf("\aERROR : Fail to execute THPAudioGetInfo().\n");
                error = FALSE;
                goto ERROR_END;
            }
            
            // WAV �t�@�C���̃`�����l�������`�F�b�N
            if (audioHandle[0]->audioInfo.channel != subAudioInfo.sndChannels)
            {
                printf("\aERROR : Channels of [%s] is %d (!= %d).\n",
                       waveFilesPtr[cnt],
                       subAudioInfo.sndChannels,
                       audioHandle[0]->audioInfo.channel);                       
                error = FALSE;
                goto ERROR_END;
            }
            
            // WAV �t�@�C���̍Đ����g�����`�F�b�N
            if (audioHandle[0]->audioInfo.frequency != subAudioInfo.sndFrequency)
            {
                printf("\aERROR : Frequency of [%s] is %d (!= %d).\n",
                       waveFilesPtr[cnt],
                       subAudioInfo.sndFrequency,
                       audioHandle[0]->audioInfo.frequency);
                error = FALSE;
                goto ERROR_END;
            }
            
            if (Convert_Verbose)
            {
                printf("    <+> Track%02d <= [%s]\n", cnt, waveFilesPtr[cnt]);
            }
        }
        
        if (Convert_Verbose)
        {
            printf("END  : Audio Initializing.\n");
        }
        
        // THPHeader �X�V
        fileHeader.header.audioMaxSamples
            = THPAudioGetMaxFrameSamples(audioHandle[0], num_JPGfiles);
                                                                        
        // THPAudioInfo �X�V
        fileHeader.audioInfo.sndNumTracks  = num_WAVfiles;
        fileHeader.audioInfo.sndNumSamples = THPAudioGetTotalSamples(audioHandle[0],
                                                                     num_JPGfiles);
        
        // THPFrameCompInfo �X�V
        fileHeader.frameCompInfo.frameComp[1] = THP_AUDIO_COMP;
        fileHeader.frameCompInfo.numComponents++;
    }
    
    // Open Output File
    thpFp = fopen(outFile, "w");
    if (thpFp == NULL)
    {
        THPPrintError("\aERROR : Can't output [%s].\n", outFile);
        THPPrintError("          Please input valid directory & file name.\n");
        error = FALSE;
        goto ERROR_END;
    }
    
    // �A�� JPEG �� THP �ɃR���o�[�g
    rtn = THPUtyCreateTHP(thpFp, THP_CREATETHP_FILEFLAG_JPEGS,
                                 (void*)jpegFileList,
                                 &fileHeader,
                                 audioHandle);
    if (rtn != THP_ERROR_NOERROR)
    {
        printf("\aERROR : Fail to execute THPUtyCreateTHP().\n");
        error = FALSE;
        goto ERROR_END;
    }
    
ERROR_END:
    
    if (audioHandle)
    {
        THPAudioQuit();
        for (cnt = 0; cnt < num_WAVfiles; cnt++)
        {
            if (audioHandle[cnt] != NULL)
            {
                THPAudioFreeHandle(audioHandle[cnt]);
            }
        }
        free(audioHandle);
    }
    
    if (jpegFileList != NULL)
    {
        free(jpegFileList);
    }
    
    if (thpFp != NULL)
    {
        fclose(thpFp);
    }
    
    return error;
}

/*---------------------------------------------------------------------------*
  Name:         changeAudioTrack

  Description:  THP �t�@�C�����̊��݃I�[�f�B�I�g���b�N�̍����ւ�

  Arguments:    fileHeader  THP �t�@�C���̃w�b�_�̃|�C���^
                
  Returns:      TRUE        ����I��
                FALSE       �G���[�I��
 *---------------------------------------------------------------------------*/
static s32 changeAudioTrack(THPFileHeader* fileHeader)
{
    s32              rtn;
    s32              error = TRUE;
    u32              cnt;
    //u32              adjustFrequency;
    char             tmpFilename[PATH_MAX];
    char*            fileName = NULL;
    FILE*            outTHPFp = NULL;
    FILE*            inTHPFp = NULL; 
    THPAudioHandle** audioHandle = NULL;
    THPAudioInfo     audioInfo;

    // THP �t�@�C���ɃI�[�f�B�I�g���b�N�����݂��邩�`�F�b�N
    for (cnt = 0; cnt < fileHeader->frameCompInfo.numComponents; cnt++)
    {
        if (fileHeader->frameCompInfo.frameComp[cnt] == THP_AUDIO_COMP)
        {
            break;
        }
    }
    
    if (cnt >= fileHeader->frameCompInfo.numComponents)
    {
        printf("\aERROR : [%s] doesn't have a Sound Data!\n", inFile);
        error = FALSE;
        goto ERROR_END;
    }
    
    // THP �t�@�C���̃`�����l�����ƍĐ����g���̃`�F�b�N
    if (fileHeader->audioInfo.sndChannels == 0 || fileHeader->audioInfo.sndFrequency == 0)
    {
        printf("\aERROR : [%s] doesn't have a Sound Data!\n", inFile);
        error = FALSE;
        goto ERROR_END;
    }

    // THP �t�@�C���̃g���b�N���̃`�F�b�N
    if (trackNo >= fileHeader->audioInfo.sndNumTracks)
    {
        printf("\aERROR : Must input [u8 track No.] < %d.\n",
               fileHeader->audioInfo.sndNumTracks);
        error = FALSE;
        goto ERROR_END;
    }
    
    if (Convert_Verbose)
    {
        printf("START: Audio Initializing.\n");
    }
        
    // THPAudioHandle �ݒ�
    audioHandle = (THPAudioHandle**)malloc(sizeof(THPAudioHandle*)
                                           * fileHeader->audioInfo.sndNumTracks);
    if (audioHandle == NULL)
    {
        printf("\aERROR : Can't alloc memory.\n");
        error = FALSE;
        goto ERROR_END;
    }
    
    for (cnt = 0; cnt < fileHeader->audioInfo.sndNumTracks; cnt++)
    {
        audioHandle[cnt] = NULL;
    }
    
    THPUtyConvertToUnixFmt(waveFilesPtr[0]);
    
    audioHandle[trackNo] = THPAudioCreateHandle(waveFilesPtr[0],
                                                fileHeader->header.frameRate);
    if (audioHandle[trackNo] == NULL)
    {
        printf("\aERROR : Fail to execute THPAudioCreateHandle().\n");
        error = FALSE;
        goto ERROR_END;
    }
    
    // �ǉ��I�[�f�B�I�f�[�^�̏��擾
    rtn = THPAudioGetInfo(audioHandle[trackNo], &audioInfo);
    if (rtn == FALSE)
    {
        printf("\aERROR : Fail to execute THPAudioGetInfo().\n");
        error = FALSE;
        goto ERROR_END;
    }

    // �`�����l�������`�F�b�N
    if (fileHeader->audioInfo.sndChannels != audioInfo.sndChannels )
    {
        printf("\aERROR : Channels of [%s] is %d (!= %d).\n",
               waveFilesPtr[0],
               audioInfo.sndChannels,
               fileHeader->audioInfo.sndChannels);
        error = FALSE;
        goto ERROR_END;
    }
    
    // �Đ����g�����`�F�b�N
    if (fileHeader->audioInfo.sndFrequency != audioInfo.sndFrequency)
    {
        printf("\aERROR : Frequency of [%s] is %d (!= %d).\n",
               waveFilesPtr[0],
               audioInfo.sndFrequency,
               fileHeader->audioInfo.sndFrequency);
        error = FALSE;
        goto ERROR_END;
    }
    
    if (Convert_Verbose)
    {
        printf("    [AudioData]:(%2ld Tracks)\n", fileHeader->audioInfo.sndNumTracks);
        printf("     >> Channels  = %ld\n", fileHeader->audioInfo.sndChannels);
        printf("     >> Frequency = %ld\n", fileHeader->audioInfo.sndFrequency);
        printf("    <+> Track%02d <= [%s]\n", trackNo, waveFilesPtr[0]);

        printf("END  : Audio Initializing.\n");
    }
    
    // ���� THP �t�@�C���̃I�[�v��
    inTHPFp = fopen(inFile, "r");
    if (inTHPFp == NULL)
    {
        printf("\aERROR : Can't open [%s].\n", inFile);
        error = FALSE;
        goto ERROR_END;
    }
    
    // �o�� THP �t�@�C���̃I�[�v��
    if (outFile != NULL)
    {
        fileName = outFile;
    }
    else
    {
        size_t pathlen;
        char *lastslash = strrchr(inFile, '/');
        if (lastslash)
        {
            pathlen = lastslash - inFile + 1;
            memcpy(tmpFilename, inFile, pathlen);
        }
        else
        {
            getcwd(tmpFilename, PATH_MAX);
            pathlen = strlen(tmpFilename);
            tmpFilename[pathlen] = '/';
            ++pathlen;
        }
        
        strncpy(tmpFilename + pathlen, TMP_FILENAME, PATH_MAX - pathlen);
        
        fileName = tmpFilename;
    }
    
    outTHPFp = fopen(fileName, "w+");
    if (outTHPFp == NULL)
    {
        printf("\aERROR : Can't open [%s].\n", fileName);
        error = FALSE;
        goto ERROR_END;
    }
    
    // ���� THP �t�@�C�����o�� THP �t�@�C���ɃR�s�[����B
    rtn = THPUtyCopyTHPFile(inTHPFp, fileHeader, outTHPFp);
    if (rtn != THP_ERROR_NOERROR)
    {
        printf("\aERROR : Fail to execute THPUtyCopyTHPFile().\n");
        error = FALSE;
        goto ERROR_END;
    }

    rtn = fseek(outTHPFp, 0, SEEK_SET);
    if (rtn != 0)
    {
        THPPrintError("\aERROR : Can't rewind output THP file.\n");
        error = FALSE;
        goto ERROR_END;
    }

    // �I�[�f�B�I�g���b�N�̍����ւ�
    rtn = THPUtyChangeAudioTrack(outTHPFp, fileHeader, audioHandle);
    if (rtn != THP_ERROR_NOERROR)
    {
        printf("\aERROR : Fail to execute THPUtyChangeAudioTrack().\n");
        error = FALSE;
        goto ERROR_END;
    }

ERROR_END:
    
    if (audioHandle)
    {
        for (cnt = 0; cnt < fileHeader->audioInfo.sndNumTracks; cnt++)
        {
            if (audioHandle[cnt] != NULL)
            {
                THPAudioFreeHandle(audioHandle[cnt]);
            }
        }
        free(audioHandle);
    }
    
    if (inTHPFp != NULL)
    {
        fclose(inTHPFp);
    }
    
    if (outTHPFp != NULL)
    {
        fclose(outTHPFp);
    }
    
    // �㏑���� -> �ꎞ�t�@�C�������l�[��
    if (outFile == NULL)
    {
        if (error == TRUE)
        {
            if (remove(inFile) == -1)
            {
                printf("\aERROR : Can't remove old THP file[%s].\n", inFile);
            }
            
            if (rename(fileName, inFile))
            {
                printf("\aERROR : Can't rename THP file[%s -> %s].\n", fileName, inFile);
            }
        }
        else
        {
            if (fileName)
            {
                if (remove(fileName) == -1)
                {
                    printf("\aERROR : Can't remove temporary THP file[%s].\n", fileName);
                }
            }
        }
    }
    
    return error;
}

/*---------------------------------------------------------------------------*
  Name:         appendAudioData

  Description:  �I�[�f�B�I�f�[�^���Ȃ��ꍇ�́A�ǉ�����B
                �I�[�f�B�I�f�[�^������ꍇ�́A�����̃I�[�f�B�I�f�[�^�������ւ���B
                (-s �I�v�V������)
                
  Arguments:    fileHeader  �t�@�C���w�b�_�̃|�C���^                
                
  Returns:      TRUE        ����I��
                FALSE       �G���[�I��
 *---------------------------------------------------------------------------*/
static s32 appendAudioData(THPFileHeader* fileHeader)
{
    s32              rtn;
    s32              error = TRUE;
    u32              cnt;
    char             tmpFilename[PATH_MAX];
    char*            fileName = NULL;
    FILE*            outTHPFp = NULL;
    FILE*            inTHPFp = NULL;
    THPAudioHandle** audioHandle = NULL;
    
    // ���� THP �t�@�C���̃I�[�v��
    inTHPFp = fopen(inFile, "r");
    if (inTHPFp == NULL)
    {
        printf("\aERROR : Can't open [%s].\n", inFile);
        error = FALSE;
        goto ERROR_END;
    }
    
    // �o�� THP �t�@�C���̃I�[�v��
    if (outFile != NULL)
    {
        fileName = outFile;
    }
    else
    {
        size_t pathlen;
        char *lastslash = strrchr(inFile, '/');
        if (lastslash)
        {
            pathlen = lastslash - inFile + 1;
            memcpy(tmpFilename, inFile, pathlen);
        }
        else
        {
            getcwd(tmpFilename, PATH_MAX);
            pathlen = strlen(tmpFilename);
            tmpFilename[pathlen] = '/';
            ++pathlen;
        }
        
        strncpy(tmpFilename + pathlen, TMP_FILENAME, PATH_MAX - pathlen);
        
        fileName = tmpFilename;
    }
    
    outTHPFp = fopen(fileName, "w");
    if (outTHPFp == NULL)
    {
        printf("\aERROR : Can't open [%s].\n", fileName);
        error = FALSE;
        goto ERROR_END;
    }
    
    if (Convert_Verbose)
    {
        printf("START: Audio Initializing.\n");
    }
        
    // THPAudioInfo (�g���b�N�� sndNumTracks) �X�V
    fileHeader->audioInfo.sndNumTracks = num_WAVfiles;
    
    audioHandle = (THPAudioHandle**)malloc(sizeof(THPAudioHandle*) * num_WAVfiles);
    if (audioHandle == NULL)
    {
        printf("\aERROR : Can't alloc memory.\n");
        error = FALSE;
        goto ERROR_END;
    }
    
    // WAV �t�@�C�����X�g�쐬
    for (cnt = 0; cnt < num_WAVfiles; cnt++)
    {
        THPUtyConvertToUnixFmt(waveFilesPtr[cnt]);
        
        audioHandle[cnt] = THPAudioCreateHandle(waveFilesPtr[cnt],
                                                fileHeader->header.frameRate);
        if (audioHandle[cnt] == NULL)
        {
            printf("\aERROR : Fail to execute THPAudioCreateHandle().\n");
            error = FALSE;
            goto ERROR_END;
        }
    }
    
    // Main Sound
    rtn = THPAudioGetInfo(audioHandle[0], &fileHeader->audioInfo);
    if (rtn == FALSE)
    {
        printf("\aERROR : Fail to execute THPAudioGetInfo().\n");
        error = FALSE;
        goto ERROR_END;
    }
        
    if (Convert_Verbose)
    {
        printf("    [AudioData]:(%2ld Tracks)\n", num_WAVfiles);
        printf("     >> Channels  = %ld\n", fileHeader->audioInfo.sndChannels);
        printf("     >> Frequency = %ld\n", fileHeader->audioInfo.sndFrequency);
        printf("    <+> Track%02d <= [%s]\n", 0, waveFilesPtr[0]);
    }

    // Sub Sound
    for (cnt = 1; cnt < num_WAVfiles; cnt++)
    {
        THPAudioInfo subAudioInfo;
        
        rtn = THPAudioGetInfo(audioHandle[cnt], &subAudioInfo);
        if (rtn == FALSE)
        {
            printf("\aERROR : Fail to execute THPAudioGetInfo().\n");
            error = FALSE;
            goto ERROR_END;
        }
        
        // WAV �t�@�C���̃`�����l�������`�F�b�N
        if (audioHandle[0]->audioInfo.channel != subAudioInfo.sndChannels)
        {
            printf("\aERROR : Channels of [%s] is %d (!= %d).\n",
                   waveFilesPtr[cnt],
                   subAudioInfo.sndChannels,
                   audioHandle[0]->audioInfo.channel);
            error = FALSE;
            goto ERROR_END;
        }
        
        // WAV �t�@�C���̍Đ����g�����`�F�b�N
        if (audioHandle[0]->audioInfo.frequency != subAudioInfo.sndFrequency)
        {
            printf("\aERROR : Frequency of [%s] is %d (!= %d).\n",
                   waveFilesPtr[cnt],
                   subAudioInfo.sndFrequency,
                   audioHandle[0]->audioInfo.frequency);
            error = FALSE;
            goto ERROR_END;
        }
        
        if (Convert_Verbose)
        {
            printf("    <+> Track%02d <= [%s]\n", cnt, waveFilesPtr[cnt]);
        }
    }
    
    if (Convert_Verbose)
    {
        printf("END  : Audio Initializing.\n");
    }
    
    // THPHeader �X�V
    fileHeader->header.audioMaxSamples
        = THPAudioGetMaxFrameSamples(audioHandle[0], fileHeader->header.numFrames);
    
    // THPAudioInfo �X�V
    fileHeader->audioInfo.sndNumTracks = num_WAVfiles;
    fileHeader->audioInfo.sndNumSamples
        = THPAudioGetTotalSamples(audioHandle[0], fileHeader->header.numFrames);
                                                                  
    // THPFrameCompInfo �X�V
    if (fileHeader->frameCompInfo.frameComp[1] == THP_NOCOMP_COMP)
    {
        fileHeader->frameCompInfo.numComponents++;
        fileHeader->frameCompInfo.frameComp[1] = THP_AUDIO_COMP;
    }
    
    // THP �f�[�^�ɃI�[�f�B�I�f�[�^�ǉ��^THP �f�[�^�̃I�[�f�B�I�f�[�^�����ւ�
    rtn = THPUtyCreateTHP(outTHPFp, THP_CREATETHP_FILEFLAG_THP,
                                    (void*)inTHPFp,
                                    fileHeader,
                                    audioHandle);
    if (rtn != THP_ERROR_NOERROR)
    {
        printf("\aERROR : Fail to execute THPUtyCreateTHP().\n");
        error = FALSE;
        goto ERROR_END;
    }
    
ERROR_END:
    
    if (audioHandle)
    {
        for (cnt = 0; cnt < num_WAVfiles; cnt++)
        {
            if (audioHandle[cnt] != NULL)
            {
                THPAudioFreeHandle(audioHandle[cnt]);
            }
        }
        free(audioHandle);
    }

    if (inTHPFp != NULL)
    {
        fclose(inTHPFp);
    }

    if (outTHPFp != NULL)
    {
        fclose(outTHPFp);
    }
    
    // �㏑���� -> �ꎞ�t�@�C�������l�[��
    if (outFile == NULL)
    {
        if (error == TRUE)
        {
            if (remove(inFile) == -1)
            {
                printf("\aERROR : Can't remove old THP file[%s].\n", inFile);
            }
            
            if (rename(fileName, inFile))
            {
                printf("\aERROR : Can't rename THP file[%s -> %s].\n", fileName, inFile);
            }
        }
        else
        {
            if (fileName)
            {
                if (remove(fileName) == -1)
                {
                    printf("\aERROR : Can't remove temporary THP file[%s].\n", fileName);
                }
            }
        }
    }
    
    return error;
}

/*---------------------------------------------------------------------------*
  Name:         changeAudioData

  Description:  �I�[�f�B�I�f�[�^�̒ǉ��܂��͍����ւ�
                
  Arguments:    ����
                
  Returns:      TRUE        ����I��
                FALSE       �G���[�I��
 *---------------------------------------------------------------------------*/
static s32 changeAudioData(void)
{
    THPFileHeader fileHeader;
    FILE*         inTHPFp = NULL;
    s32           rtn;
    s32           error = TRUE;
    
    if (THPAudioInit() == FALSE)
    {
        printf("\aERROR : Fail to execute THPAudioInit().\n");
        error = FALSE;
        goto ERROR_END;
    }

    // ���� THP �t�@�C���̃I�[�v��
    inTHPFp = fopen(inFile, "r");
    if (inTHPFp == NULL)
    {
        printf("\aERROR : Can't open [%s].\n", inFile);
        error = FALSE;
        goto ERROR_END;
    }
    
    // ���� THP �t�@�C���� THPFileHeader ��ǂݎ��
    rtn = THPUtyReadTHPFileHeader(inTHPFp, &fileHeader);
    if (rtn != THP_ERROR_NOERROR)
    {
        printf("\aERROR : Can't read THPHeader of [%s].\n", inFile);
        fclose(inTHPFp);
        error = FALSE;
        goto ERROR_END;
    }
    
    fclose(inTHPFp);
    
    // �I�[�f�B�I�f�[�^�̒ǉ��^�����ւ�
    if (change_onetrack)
    {
        // ����g���b�N�̃I�[�f�B�I�f�[�^�������ւ���ꍇ (-trk)
        
        if (Convert_Verbose)
        {
            printf("Replace audio data of one track.\n");
        }
        
        // -o/-r/-non/-odd/-even �͖���
        
        error = changeAudioTrack(&fileHeader);

    }
    else
    {
        // �S�g���b�N�̃I�[�f�B�I�f�[�^��ǉ��^�����ւ���ꍇ (-s)
        
        if (Convert_Verbose)
        {
            printf("Append/Replace audio data of all tracks.\n");
        }
        
        // �t���[�����[�g�X�V (-r)
        if (change_framerate)
        {
            fileHeader.header.frameRate = frame_rate;
        }
        
        // �I�t�Z�b�g�e�[�u���̗L���X�V (-o)
        if (offset_mode)
        {
            fileHeader.header.offsetDataOffsets = offset_mode;
        }
        
        // �\���J�n�t�B�[���h�̎w��X�V (-non/odd/even)
        if (change_videotype)
        {
            fileHeader.videoInfo.videoType = videotype;
        }
        
        error = appendAudioData(&fileHeader);
    }
    
ERROR_END:

    THPAudioQuit();
    
    return error;
}

/*---------------------------------------------------------------------------*
  Name:         logPrintFunc

  Description:  ���b�Z�[�W�A���O�A�G���[���o�͂���B
                
  Arguments:    ...
                
  Returns:      ����
 *---------------------------------------------------------------------------*/
static void logPrintFunc(const char* format, va_list argptr)
{
    vfprintf(stdout, format, argptr);
}

/*---------------------------------------------------------------------------*
  Name:         main

  Description:  THPConv���C��
                
  Arguments:    (Usage() �Q��)
                
  Returns:      0           ����I��
                1           �G���[�I��
 *---------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    s32  error = 0;
    
    // THP ���C�u���������b�Z�[�W���o�͂���ׂ̊֐����t�b�N
    THPPrintFunc      = logPrintFunc;
    THPPrintLogFunc   = logPrintFunc;
    THPPrintErrorFunc = logPrintFunc;

    // �����̃`�F�b�N
    error = checkArguments(argc, argv);

    // THP ���C�u�����ɏ璷 (Verbose) ���[�h�t���O���Z�b�g
    THPVerboseFlag = Convert_Verbose;

    if (Convert_Verbose)
    {
        printf("Dolphin Jpegs to THP converter. Copyright 2002-2003 Nintendo.\n");
        printf("Built : %s %s\n\n", __DATE__, __TIME__);
    }
    
    if ((error == FALSE) || (argc == 1))
    {
        exit(1);
    }
    
    printf("THP file Version is %X.%X\n", THP_VERSION >> 16, THP_VERSION & 0xFFFF);
    
    // THP �쐬
    if (pack_jpegs)
    {
        // JPEG ���� THP �ւ̃R���o�[�g (-j)
        
        if (Convert_Verbose)
        {
            printf("Convert from JPEGs to THP...\n");
        }
        
        error = convertJPEGtoTHP();
    }
    
    else if (change_snd_data)
    {
        // ���� THP �ɑ΂���I�[�f�B�I�f�[�^�̒ǉ��^�����ւ� (-c)
        
        if (Convert_Verbose)
        {
            printf("Append/Replace audio data...\n");
        }
        
        // �㏑���m�F
        if (outFile == NULL)
        {
            if (verifyWriteOverInputData(inFile) == FALSE)
            {
                exit(0);
            }
        }
        
        error = changeAudioData();
    }
    
    if (error == FALSE)
    {
        printf("WARNING : Errors occurred while converting to THP.\n");
        printf("          Please check for error messages above!\n");
        
        exit(1);
    }
    else
    {
        if (outFile)
        {
            printf("Successfully generated [%s].\n", outFile);
        }
        else
        {
            printf("Successfully overwrote [%s].\n", inFile);
        }
    }
    
    exit(0);
}
