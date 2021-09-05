/*---------------------------------------------------------------------------*
  Project:  Dolphin OS Boot info3 structure
  File:     OSBootInfo3.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.6  2007/11/08 04:46:47  ooizumi
  Added fingerPrint to OSBootInfo3.

  Revision 1.5  2006/09/23 07:18:00  ooizumi
  Updated.

  Revision 1.4  2006/09/14 08:18:56  ooizumi
  Fixed typo.

  Revision 1.3  2006/08/05 06:35:46  ooizumi
  Added OS_BI3_COUNTRYCODE_[JP|US|EU].

  Revision 1.2  2006/07/22 02:20:42  ooizumi
  Added OS_BI3_PARENTALCONTROL_PRESENT.

  Revision 1.1  2006/07/21 13:01:05  ooizumi
  Added OSBootInfo3 structure.


  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSBOOTINFO3_H__
#define __OSBOOTINFO3_H__

// Boot Info3 is a 8K byte structure
#define OS_BI3_SIZE                     0x2000      // 8K

typedef struct
{
  u32 countryCode;
  u32 numberOfGameDisk;
  u8  reserved0[8];
  u8  parentalControlInfo[16];
  u8  reserved1[7648];
  u8  fingerPrint[256];
  u8  reserved2[252];
  u32 magic;
} OSBootInfo3;

#define OS_BI3_MAGIC                    0xc3f81a8e

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
#define OS_BI3_COUNTRYCODE_OFFSET        0x0000      //  4 bytes
#define OS_BI3_NUMDISK_OFFSET            0x0004      //  4 bytes
#define OS_BI3_PARENTALCONTROL_OFFSET    0x0010      // 16 bytes

#define OS_BI3_FINGERPRINT_OFFSET        0x1E00      // 256 bytes

#define OS_BI3_COUNTRYCODE_JP            0           // Japan
#define OS_BI3_COUNTRYCODE_US            1           // US
#define OS_BI3_COUNTRYCODE_EU            2           // Europe
#define OS_BI3_COUNTRYCODE_ALL           3           // All (only for boot-IRD)
#define OS_BI3_COUNTRYCODE_KR            4           // Korea
#define OS_BI3_COUNTRYCODE_CN            5           // China

#define OS_BI3_PARENTALCONTROL_CERO      0           // CERO
#define OS_BI3_PARENTALCONTROL_ESRB      1           // ESRB
#define OS_BI3_PARENTALCONTROL_BBFC      2           // BBFC
#define OS_BI3_PARENTALCONTROL_USK       3           // USK
#define OS_BI3_PARENTALCONTROL_PEGI_GEN  4           // PEGI general
#define OS_BI3_PARENTALCONTROL_PEGI_FIN  5           // PEGI Finland
#define OS_BI3_PARENTALCONTROL_PEGI_PRT  6           // PEGI Portugal
#define OS_BI3_PARENTALCONTROL_PEGI_BBFC 7           // PEGI and BBFC Great Briten
#define OS_BI3_PARENTALCONTROL_OFLC      8           // OFLC
#define OS_BI3_PARENTALCONTROL_GRB       9           // GRB

#define OS_BI3_PARENTALCONTROL_NOTPRESENT   0x80
//#define OS_BI3_PARENTALCONTROL_ENABLE_RP    0x40
#define OS_BI3_PARENTALCONTROL_PENDING      0x40
#define OS_BI3_PARENTALCONTROL_ESRB_NOTICE  0x20
#define OS_BI3_PARENTALCONTROL_RATING_MASK  0x1F

#endif // __OSBOOTINFO3_H__

