/*---------------------------------------------------------------------------*
  Project:  Dolphin OS Boot info2 structure
  File:     OSBootInfo2.h

  Copyright 2000 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.3  2007/05/21 09:31:05  ooizumi
  Added OS_BI2_DEVICECHECKCODE_OFFSET.

  Revision 1.2  2006/06/05 09:41:08  ooizumi
  Added OS_BI2_SIMGDDR3SIZE_OFFSET.

  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    8     9/21/01 17:54 Shiki
    Added OS_BI2_COUNTRYCODE_ALL.

    7     9/14/01 1:27p Hashida
    Added country code for PAL

    6     2/05/01 2:53p Hashida
    Added a comment

    5     1/31/01 12:06a Hashida
    Added dol size limit.

    4     12/01/00 6:15p Shiki
    Added OS_BI2_PADSPEC_OFFSET.

    3     11/15/00 11:39a Hashida
    Changed to perform 8.3 check in DVD library depending on a BootInfo2
    value.
    Added a member for number of disks of the game.

    2     9/21/00 3:12p Hashida
    Added country code.

    1     3/31/00 7:46p Hashida
    Initial revision.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSBOOTINFO2_H__
#define __OSBOOTINFO2_H__

// Boot Info2 is a 8K byte structure that is loaded to himem
// (lower than FST) by apploader.
#define OS_BI2_SIZE                     0x2000      // 8K

// Since we don't know where in memory BI2 is loaded,
// we define the locations of each member by offset
// XXX keep in mind that these offset should not be changed
// XXX in the future (or should be changed with much care),
// XXX because many tools, __start, OSInit rely on these
// XXX locations and some are hard to change by simply
// XXX change these definitions.

// XXX Also keep in mind that the top two members (debug
// XXX monitor size and simulated memory size) are used
// XXX to decide where to put BI2 itself. These values
// XXX are read by apploader first and entire BI2 is read
// XXX after BI2 address is decided.
#define OS_BI2_DEBUGMONSIZE_OFFSET      0x0000
#define OS_BI2_SIMMEMSIZE_OFFSET        0x0004
#define OS_BI2_ARGOFFSET_OFFSET         0x0008
#define OS_BI2_DEBUGFLAG_OFFSET         0x000c
#define OS_BI2_TRKLOCATION_OFFSET       0x0010
#define OS_BI2_TRKSIZE_OFFSET           0x0014
#define OS_BI2_COUNTRYCODE_OFFSET       0x0018
// master tool will write this area, indicating how many disks used for the
// game;
// 1 ... sigle disk game, 2 ... two disks game, etc
#define OS_BI2_NUMDISK_OFFSET           0x001c

// if long file name is supported, non-zero should be set here. Then DVD
// library will not perform 8.3 file name check
#define OS_BI2_LONGFILENAME_OFFSET      0x0020

// if zero, use PAD library default setting.
// Otherwise, override the default setting.
#define OS_BI2_PADSPEC_OFFSET           0x0024

// Specify limit size for total size of text/data sections of dol
#define OS_BI2_DOLSIZE_LIMIT            0x0028

#define OS_BI2_SIMGDDR3SIZE_OFFSET      0x002c

#define OS_BI2_DEVICECHECKCODE_OFFSET   0x0030

#define OS_BI2_ARGSIZE_MAX              0x1000      // 4K

#define OS_BI2_COUNTRYCODE_JP           0           // Japan
#define OS_BI2_COUNTRYCODE_US           1           // US
#define OS_BI2_COUNTRYCODE_EU           2           // Europe
#define OS_BI2_COUNTRYCODE_ALL          3           // All (EXIAD16 required)

#define OS_BI2_DEVICECHECKCODE_SL       0x460A0000  // DVD SL out of range address
#define OS_BI2_DEVICECHECKCODE_DL       0x7ED40000  // DVD DL out of range address

#endif // __OSBOOTINFO2_H__

