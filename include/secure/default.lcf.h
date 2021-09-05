/*---------------------------------------------------------------------------*
  Project:  LCF file template
  File:     default.lcf.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  Note: This file should be used only for generating LCF files.

  $Log: not supported by cvs2svn $
    
    5     4/27/00 2:50p Tian
    Changed stack back to 64K - we should reclaim DB stack via arena
    
    4     4/26/00 10:39p Tian
    Added db stack for TRK
    
    3     2/09/00 5:10p Hashida
    Aligned __ArenaLo by 32bytes.
    
    2     1/20/00 3:24p Shiki
    Fixed stack address alignment.

    1     11/03/99 2:09p Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#include <secure/boot.h>

MEMORY {
    text : origin = BOOT_APPLICATION_BASE
}
SECTIONS {
    GROUP:{
        .init    ALIGN(0x20):{}
        extab    ALIGN(0x20):{}
        extabindex  ALIGN(0x20):{}
        .text    ALIGN(0x20):{}
        .ctors   ALIGN(0x20):{}
        .dtors   ALIGN(0x20):{}
        .rodata  ALIGN(0x20):{}
        .data    ALIGN(0x20):{}
        .bss     ALIGN(0x20):{}
        .sdata   ALIGN(0x20):{}
        .sbss    ALIGN(0x20):{}
        .sdata2  ALIGN(0x20):{}
        .sbss2   ALIGN(0x20):{}
        .stack   ALIGN(0x100):{}
    } > text
    _stack_addr  = (_f_sbss2 + SIZEOF(.sbss2) + 65536 + 0x7) & ~0x7;
    _stack_end   = _f_sbss2 + SIZEOF(.sbss2);
    _db_stack_addr = (_stack_addr + 0x2000);
    _db_stack_end = _stack_addr;
    __ArenaLo = (_db_stack_addr + 0x1f) & ~0x1f;
    __ArenaHi    = BOOT_FST_BASE;
}
