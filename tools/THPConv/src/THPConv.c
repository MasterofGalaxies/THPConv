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
// <使用している THP ライブラリ関数>
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

  Description:  コマンドの使い方の表示

  Arguments:    progName    プログラム名のポインタ

  Returns:      無し
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

  Description:  入力ファイルの上書きの確認

  Arguments:    fileName    ファイル名のポインタ
                
  Returns:      TRUE        上書き許可
                FALSE       上書き不許可
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

  Description:  sWildcardPattern にマッチするファイル名を検索して、全て filename に格納する。
                あらかじめ filename のバッファを確保しておく必要がある。

  Arguments:    sWildcardPattern  ワイルドカードを含むファイル名
                filename          ファイル名を格納するバッファ
                
  Returns:      ファイル数
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

  Description:  qsort() に指定する比較関数

  Arguments:    arg1, arg2  比較する要素
                
  Returns:      負の値      arg1 < arg2 の場合
                0           arg1 = arg2 の場合
                正の値      arg1 > arg2 の場合
 *---------------------------------------------------------------------------*/
static int compare(const void *arg1, const void *arg2)
{
    // 2つの文字列を最後まで比較
    return strcmp(((THPFileName *)arg1)->name, ((THPFileName *)arg2)->name);
}

/*---------------------------------------------------------------------------*
  Name:         checkArguments

  Description:  引数のチェック

  Arguments:    argument_count  引数の数
                argv            引数の文字列の配列
                
  Returns:      TRUE        正常終了
                FALSE       エラー終了
                (引数が "-h" の場合は即 exit(0) する)
 *---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*
  [フラグ]

  <必須>
  
  -j オプション : 連番 JPEG ファイル(群) から THP ファイルを作成
    連番 JPEG ファイル指定フラグ   pack_jpegs           : 0    -> 1
    連番 JPEG ファイルのファイル名 jpegFilesPtr         : NULL -> XXXX
    連番 JPEG ファイルの数         num_JPGfiles         : 0    -> XX

  -c オプション : 既存 THP ファイルの音声データを差し替え
    入力 THP ファイル指定フラグ    change_snd_data      : 0    -> 1
    入力 THP ファイルのファイル名  inFile               : NULL -> XXXX

  *** -j と -c は排他 ***

  <準必須>
  
  -d オプション
    出力 THP ファイル名            outFile              : NULL -> XXXX

  *** -j 指定時は必須 / -c 指定時は無くてもよい ***
  
  -s オプション
    入力 WAV ファイル指定フラグ    change_alltrack      : 0    -> 1
    入力 WAV ファイルのファイル名  waveFilesPtr         : NULL -> XXXX
    入力 WAV ファイルの数          num_WAVfiles         : 0    -> XX

  *** -j 指定時は無くてもよい ***
  
  -trk オプション
    音声トラックの入れ替えフラグ   change_onetrack      : 0    -> 1
    入れ替え WAV ファイル名        waveFilesPtr         : NULL -> XXXX
    入れ替えトラック番号           trackNo              : 0    -> XX

  *** -j 指定時は無効 / -c 指定時は -s と -trk は排他ながらどちらか必須 ***

  <その他>
  
  -r オプション
    フレームレート指定フラグ       change_framerate     : 0    -> 1
    フレームレート                 frame_rate           : 29.97f -> XXXXXX

  -o オプション
    オフセットテーブル作成フラグ   offset_mode          : 0    -> 1

  -non/odd/even オプション
    表示開始フィールド指定フラグ   change_videotype     : 0    -> 1
    指定フィールド                 videotype            : THP_VIDEO_NON_INTERLACE -> XXXXX
    
  *** -trk 指定時は無効 ***
  
  -v オプション
    冗長モードフラグ               Convert_Verbose      : 0    -> 1

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
                // -j (pack_jpegs = 1) と -c (change_snd_data) は排他
                if (change_snd_data)
                {
                    printf("\aERROR : Can't use both [-j] and [-c] at the same time.\n");
                    return FALSE;
                }

                // -j の指定は 1 回のみ
                if (pack_jpegs)
                {
                    printf("\aERROR : [-j] is specified twice.\n");
                    return FALSE;
                }
                
                // 後続するファイル名の有無をチェック
                i++;
                if (i >= argument_count)
                {
                    printf("\aERROR : Must specify input filename after [-j].\n");
                    return FALSE;
                }
                
                jpegFilesPtr = &argv[i];
                
                // 指定 JPEG ファイルの数をチェック
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
                // -j (pack_jpegs = 1) と -c (change_snd_data) は排他
                if (pack_jpegs)
                {
                    printf("\aERROR : Can't use both [-j] and [-c] at the same time.\n");
                    return FALSE;
                }

                // -c の指定は 1 回のみ
                if (change_snd_data)
                {
                    printf("\aERROR : [-c] is specified twice.\n");
                    return FALSE;
                }
                
                // 後続するファイル名の有無をチェック
                i++;
                if (i >= argument_count || argv[i][0] == '-')
                {
                    printf("\aERROR : Must specify input filename after [-c].\n");
                    return FALSE;
                }

                // 入力 THP ファイル名取得
                inFile = argv[i];
                THPUtyConvertToUnixFmt(inFile);
                
                change_snd_data = 1;
            }

            //
            // -d : specify output THP file name
            //
            else if (strcmp(option, "-d") == 0)
            {
                // -d の指定は 1 回のみ
                if (outFile)
                {
                    printf("\aERROR : [-d] is specified twice.\n");
                    return FALSE;
                }
                
                // 後続するファイル名の有無をチェック
                i++;
                if (i >= argument_count || argv[i][0] == '-')
                {
                    printf("\aERROR : Must specify output THP filename after [-d].\n");
                    return FALSE;
                }

                // 出力 THP ファイル名取得
                outFile = argv[i];
                THPUtyConvertToUnixFmt(outFile);
            }

            //
            // -s : specify input WAV file(s)
            //
            else if (strcmp(option, "-s") == 0)
            {
                // -s (change_alltrack = 1) と -trk (change_onetrack) は排他
                if (change_onetrack)
                {
                    printf("\aERROR : Can't use both [-s] and [-trk] at the same time.\n");
                    return FALSE;
                }

                // -s の指定は 1 回のみ
                if (change_alltrack)
                {
                    printf("\aERROR : [-s] is specified twice.\n");
                    return FALSE;
                }
                
                // 後続するファイル名の有無をチェック
                i++;
                if (i >= argument_count)
                {
                    printf("\aERROR : Must specify input filename after [-s].\n");
                    return FALSE;
                }
                
                waveFilesPtr = &argv[i];
                
                // 指定 wav ファイルの数をチェック
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
                // -s (change_alltrack = 1) と -trk (change_onetrack) は排他
                if (change_alltrack)
                {
                    printf("\aERROR : Can't use both [-s] and [-trk] at the same time.\n");
                    return FALSE;
                }

                // -trk の指定は 1 回のみ
                if (change_onetrack)
                {
                    printf("\aERROR : [-trk] is specified twice.\n");
                    return FALSE;
                }
                
                // 後続するトラック番号及びファイル名の有無をチェック
                i++;
                if (i + 1 >= argument_count)
                {
                    printf("\aERROR : Must specify trackNo and input filename after [-trk].\n");
                    return FALSE;
                }

                // トラック番号を取得
                if (argv[i][0] < '0' || argv[i][0] > '9')
                {
                    printf("\aERROR : Invalid trackNo.\n");
                    return FALSE;
                }
                
                trackNo = atoi(argv[i]);

                // 入力 wav ファイル名を取得
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
                // 後続する指定フレームレートの有無をチェック
                i++;
                if (i >= argument_count)
                {
                    printf("\aERROR : Must specify output framerate after [-r].\n");
                    return FALSE;
                }

                // フレームレート取得
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


    // コンバート (-j : pack_jpegs = 1) か音声差し替え (-c : change_snd_data = 1) のどちら
    // かが指定されているかチェック。
    if (!pack_jpegs && !change_snd_data)
    {
        printf("\aERROR : Must input either [-j] or [-c].\n");
        return FALSE;
    }
    
    // JPEG から THP へのコンバート時に (-j : pack_jpegs = 1)、出力 THP ファイルが指定され
    // ている (-d : outFile != NULL) かチェック。
    if (pack_jpegs)
    {
        if (outFile == NULL)
        {
            printf("\aERROR : Must specify output THP filename [-d] [file.thp].\n");
            return FALSE;
        }
    }
    
    // THP の音声データ差し替え時に (-c : change_snd_data = 1)、入力 WAV ファイルが指定され
    // ている (-s : change_alltrack = 1 or -trk : change_one_track = 1) かチェック。
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

  Description:  連番 JPEG ファイルを THP データに変換

  Arguments:    無し
                
  Returns:      TRUE        正常終了
                FALSE       エラー終了
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
    // JPEG ファイルリストの作成
    //
    if (num_JPGfiles == 1)
    {
        // 1 個 JPEG ファイルもしくはワイルドカード指定の場合
        
        THPUtyConvertToUnixFmt(jpegFilesPtr[0]);

        // JPEG ファイル数を確認
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

        // JPEG ファイル名保存
        getFileNameList(jpegFilesPtr[0], jpegFileList);
    }
    
    else
    {
        // 複数 JPEG ファイル指定の場合
        
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

            // JPEG ファイル名保存
            strcpy(jpegFileList[cnt].name, jpegFilesPtr[cnt]);
            THPUtyConvertToUnixFmt(jpegFileList[cnt].name);
            
            // 拡張子の確認
            nameLen = strlen(jpegFileList[cnt].name);
            ext = jpegFileList[cnt].name + nameLen;
            if ((nameLen < 4 || strcasecmp(ext - 4, ".jpg")) &&
                (nameLen < 5 || strcasecmp(ext - 5, ".jpeg")))
            {
                printf("\aERROR : Please input filename is [***.jpg] or [***.jpeg].\n");
                error = FALSE;
                goto ERROR_END;
            }
            
            // JPEG ファイルのサイズ取得
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
    
    // THPHeader 設定
    THPUtyHeaderInit(&fileHeader.header);
    fileHeader.header.frameRate           = frame_rate;
    fileHeader.header.numFrames           = num_JPGfiles;
    fileHeader.header.compInfoDataOffsets = sizeof(THPHeader);
    fileHeader.header.offsetDataOffsets   = offset_mode;
    
    // THPFrameCompInfo 設定
    fileHeader.frameCompInfo.frameComp[0] = THP_VIDEO_COMP;
    fileHeader.frameCompInfo.numComponents = 1;
    for (cnt = 1; cnt < THP_COMP_MAX; cnt++)
    {
        fileHeader.frameCompInfo.frameComp[cnt] = THP_NOCOMP_COMP;
    }
    
    // THPVideoInfo 設定
    fileHeader.videoInfo.videoType = videotype;
    
    // オーディオデータのエンコード設定
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

        // WAV ファイルリスト作成
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
            
            // WAV ファイルのチャンネル数をチェック
            if (audioHandle[0]->audioInfo.channel != subAudioInfo.sndChannels)
            {
                printf("\aERROR : Channels of [%s] is %d (!= %d).\n",
                       waveFilesPtr[cnt],
                       subAudioInfo.sndChannels,
                       audioHandle[0]->audioInfo.channel);                       
                error = FALSE;
                goto ERROR_END;
            }
            
            // WAV ファイルの再生周波数をチェック
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
        
        // THPHeader 更新
        fileHeader.header.audioMaxSamples
            = THPAudioGetMaxFrameSamples(audioHandle[0], num_JPGfiles);
                                                                        
        // THPAudioInfo 更新
        fileHeader.audioInfo.sndNumTracks  = num_WAVfiles;
        fileHeader.audioInfo.sndNumSamples = THPAudioGetTotalSamples(audioHandle[0],
                                                                     num_JPGfiles);
        
        // THPFrameCompInfo 更新
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
    
    // 連番 JPEG を THP にコンバート
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

  Description:  THP ファイル内の既在オーディオトラックの差し替え

  Arguments:    fileHeader  THP ファイルのヘッダのポインタ
                
  Returns:      TRUE        正常終了
                FALSE       エラー終了
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

    // THP ファイルにオーディオトラックが存在するかチェック
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
    
    // THP ファイルのチャンネル数と再生周波数のチェック
    if (fileHeader->audioInfo.sndChannels == 0 || fileHeader->audioInfo.sndFrequency == 0)
    {
        printf("\aERROR : [%s] doesn't have a Sound Data!\n", inFile);
        error = FALSE;
        goto ERROR_END;
    }

    // THP ファイルのトラック数のチェック
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
        
    // THPAudioHandle 設定
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
    
    // 追加オーディオデータの情報取得
    rtn = THPAudioGetInfo(audioHandle[trackNo], &audioInfo);
    if (rtn == FALSE)
    {
        printf("\aERROR : Fail to execute THPAudioGetInfo().\n");
        error = FALSE;
        goto ERROR_END;
    }

    // チャンネル数をチェック
    if (fileHeader->audioInfo.sndChannels != audioInfo.sndChannels )
    {
        printf("\aERROR : Channels of [%s] is %d (!= %d).\n",
               waveFilesPtr[0],
               audioInfo.sndChannels,
               fileHeader->audioInfo.sndChannels);
        error = FALSE;
        goto ERROR_END;
    }
    
    // 再生周波数をチェック
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
    
    // 入力 THP ファイルのオープン
    inTHPFp = fopen(inFile, "r");
    if (inTHPFp == NULL)
    {
        printf("\aERROR : Can't open [%s].\n", inFile);
        error = FALSE;
        goto ERROR_END;
    }
    
    // 出力 THP ファイルのオープン
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
    
    // 入力 THP ファイルを出力 THP ファイルにコピーする。
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

    // オーディオトラックの差し替え
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
    
    // 上書き時 -> 一時ファイルをリネーム
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

  Description:  オーディオデータがない場合は、追加する。
                オーディオデータがある場合は、既存のオーディオデータを差し替える。
                (-s オプション時)
                
  Arguments:    fileHeader  ファイルヘッダのポインタ                
                
  Returns:      TRUE        正常終了
                FALSE       エラー終了
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
    
    // 入力 THP ファイルのオープン
    inTHPFp = fopen(inFile, "r");
    if (inTHPFp == NULL)
    {
        printf("\aERROR : Can't open [%s].\n", inFile);
        error = FALSE;
        goto ERROR_END;
    }
    
    // 出力 THP ファイルのオープン
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
        
    // THPAudioInfo (トラック数 sndNumTracks) 更新
    fileHeader->audioInfo.sndNumTracks = num_WAVfiles;
    
    audioHandle = (THPAudioHandle**)malloc(sizeof(THPAudioHandle*) * num_WAVfiles);
    if (audioHandle == NULL)
    {
        printf("\aERROR : Can't alloc memory.\n");
        error = FALSE;
        goto ERROR_END;
    }
    
    // WAV ファイルリスト作成
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
        
        // WAV ファイルのチャンネル数をチェック
        if (audioHandle[0]->audioInfo.channel != subAudioInfo.sndChannels)
        {
            printf("\aERROR : Channels of [%s] is %d (!= %d).\n",
                   waveFilesPtr[cnt],
                   subAudioInfo.sndChannels,
                   audioHandle[0]->audioInfo.channel);
            error = FALSE;
            goto ERROR_END;
        }
        
        // WAV ファイルの再生周波数をチェック
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
    
    // THPHeader 更新
    fileHeader->header.audioMaxSamples
        = THPAudioGetMaxFrameSamples(audioHandle[0], fileHeader->header.numFrames);
    
    // THPAudioInfo 更新
    fileHeader->audioInfo.sndNumTracks = num_WAVfiles;
    fileHeader->audioInfo.sndNumSamples
        = THPAudioGetTotalSamples(audioHandle[0], fileHeader->header.numFrames);
                                                                  
    // THPFrameCompInfo 更新
    if (fileHeader->frameCompInfo.frameComp[1] == THP_NOCOMP_COMP)
    {
        fileHeader->frameCompInfo.numComponents++;
        fileHeader->frameCompInfo.frameComp[1] = THP_AUDIO_COMP;
    }
    
    // THP データにオーディオデータ追加／THP データのオーディオデータ差し替え
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
    
    // 上書き時 -> 一時ファイルをリネーム
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

  Description:  オーディオデータの追加または差し替え
                
  Arguments:    無し
                
  Returns:      TRUE        正常終了
                FALSE       エラー終了
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

    // 入力 THP ファイルのオープン
    inTHPFp = fopen(inFile, "r");
    if (inTHPFp == NULL)
    {
        printf("\aERROR : Can't open [%s].\n", inFile);
        error = FALSE;
        goto ERROR_END;
    }
    
    // 入力 THP ファイルの THPFileHeader を読み取り
    rtn = THPUtyReadTHPFileHeader(inTHPFp, &fileHeader);
    if (rtn != THP_ERROR_NOERROR)
    {
        printf("\aERROR : Can't read THPHeader of [%s].\n", inFile);
        fclose(inTHPFp);
        error = FALSE;
        goto ERROR_END;
    }
    
    fclose(inTHPFp);
    
    // オーディオデータの追加／差し替え
    if (change_onetrack)
    {
        // 特定トラックのオーディオデータを差し替える場合 (-trk)
        
        if (Convert_Verbose)
        {
            printf("Replace audio data of one track.\n");
        }
        
        // -o/-r/-non/-odd/-even は無視
        
        error = changeAudioTrack(&fileHeader);

    }
    else
    {
        // 全トラックのオーディオデータを追加／差し替える場合 (-s)
        
        if (Convert_Verbose)
        {
            printf("Append/Replace audio data of all tracks.\n");
        }
        
        // フレームレート更新 (-r)
        if (change_framerate)
        {
            fileHeader.header.frameRate = frame_rate;
        }
        
        // オフセットテーブルの有無更新 (-o)
        if (offset_mode)
        {
            fileHeader.header.offsetDataOffsets = offset_mode;
        }
        
        // 表示開始フィールドの指定更新 (-non/odd/even)
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

  Description:  メッセージ、ログ、エラーを出力する。
                
  Arguments:    ...
                
  Returns:      無し
 *---------------------------------------------------------------------------*/
static void logPrintFunc(const char* format, va_list argptr)
{
    vfprintf(stdout, format, argptr);
}

/*---------------------------------------------------------------------------*
  Name:         main

  Description:  THPConvメイン
                
  Arguments:    (Usage() 参照)
                
  Returns:      0           正常終了
                1           エラー終了
 *---------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
    s32  error = 0;
    
    // THP ライブラリがメッセージを出力する為の関数をフック
    THPPrintFunc      = logPrintFunc;
    THPPrintLogFunc   = logPrintFunc;
    THPPrintErrorFunc = logPrintFunc;

    // 引数のチェック
    error = checkArguments(argc, argv);

    // THP ライブラリに冗長 (Verbose) モードフラグをセット
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
    
    // THP 作成
    if (pack_jpegs)
    {
        // JPEG から THP へのコンバート (-j)
        
        if (Convert_Verbose)
        {
            printf("Convert from JPEGs to THP...\n");
        }
        
        error = convertJPEGtoTHP();
    }
    
    else if (change_snd_data)
    {
        // 既存 THP に対するオーディオデータの追加／差し替え (-c)
        
        if (Convert_Verbose)
        {
            printf("Append/Replace audio data...\n");
        }
        
        // 上書き確認
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
