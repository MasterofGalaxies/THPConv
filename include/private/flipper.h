/*---------------------------------------------------------------------------*
  Project:  Revolution
  File:     flipper.h

  Copyright 1998 - 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.6  2006/03/05 05:55:32  ooizumi
  Changed build flag.

  Revision 1.5  2006/03/01 08:14:58  hirose
  Changed address space definitions for AHB_IO_PI access environment.

  Revision 1.4  2006/02/04 13:05:45  hashida
  (none)

  Revision 1.3  2006/02/03 10:31:52  hirose
  Deleted obsoleted part.

  Revision 1.2  2006/02/03 02:02:00  hirose
  A change due to latest FDL integration.

  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    11    11/22/00 9:26p Eugene
    Revised to include either "dsp_reg.h" or "dsp_reg_b.h" depending on
    value of GX_REV define. For support of revised ARAM control registers
    (RevB flipper).
    
    10    5/10/00 2:51p Shiki
    Removed #ifndef ORCA.

    8     3/01/00 10:59a Tian
    ifdefed out all emulation code for ORCA

    7     2/29/00 4:53p Hashida
    Checked in so that DIEmu registers is only defined in SPRUCE.

    6     2/22/00 2:51p Tian
    Added trap handling for unemulated modules.

    5     1/18/00 5:42p Tian
    MINNOW_MARLIN -> MINNOW

    4     1/18/00 1:57p Tian
    Added __RealPIRegs for MINNOW_MARLIN, because some PI regs are real,
    and some are emulated.

    3     12/03/99 2:56p Hashida
    Changed the last register of VI according as the HW change.

    2     11/23/99 10:53a Hashida
    Changed the size of VI registers.

    20    11/08/99 1:23p Tian
    Added externed CP emulation registers.

    19    11/03/99 4:07p Hashida
    Fixed the size of DSP registers from 32 bits to 16 bits.

    18    11/01/99 4:14p Tian
    Updated cp_reg.h to ArtX's copy

    17    10/28/99 6:17p Tian
    Added __OSDumpCPEmuRegs

    16    10/28/99 6:03p Tian
    Added CP register emulation

    15    9/28/99 4:03p Shiki
    Added EXI stuff.

    14    9/28/99 12:32p Hashida
    Added VI reg emulation

    13    9/10/99 3:42p Shiki
    Added SI stuff.

    12    9/07/99 4:22p Hashida
    Changed the DMA buffer start address to 0xfff7f000 because the bug is
    fixed.

    11    9/03/99 5:58p Hashida
    Added vi registers.

    10    8/31/99 9:29p Hashida
    #define'd the start address of Marlin's DMA buffer.

    9     8/30/99 3:39p Shiki
    Fixed  __MEMRegs to array[] of vu16 (not vu32).

    8     8/30/99 3:21p Hashida
    Added to support Marlin

    7     8/23/99 7:17p Shiki
    Added __*Regs[] definitions.

    6     8/19/99 12:18a Hashida
    Added DI emulation

    5     8/18/99 10:36p Shiki
    Replaced __OSEmulationDSIHandler() with __OSInitEmulation().

    4     8/18/99 4:35p Shiki
    Added __OSDumpPIEmuRegs() declaration.

    3     8/18/99 4:17p Shiki
    Added PI stuff.

    2     8/18/99 12:24a Shiki
    Added Flipper module emulation stuff.

    1     8/17/99 12:17a Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __FLIPPER_H__
#define __FLIPPER_H__


#include <private/dsp_reg_b.h>

#include <private/io_reg.h>
#include <private/mem_reg.h>
#include <private/pi_reg.h>
#include <private/vi_reg.h>
#include <private/cp_reg.h>
#include <private/acr_ppc_reg.h>

#include <revolution/os.h>

#define REAL_PI_REGSP_PI        PI_REGSP_PI

vu16 __CPRegs [CP_NUM_REGS]             : OS_BASE_UNCACHED + PI_REGSP_CP;
vu16 __VIRegs [VI_HBS656 + 1]           : OS_BASE_UNCACHED + PI_REGSP_VI;
vu32 __PIRegs [(PI_REG_CHIPID / 4) + 1] : OS_BASE_UNCACHED + PI_REGSP_PI;
vu16 __MEMRegs[MEM_REG_UNUSED_63 + 1]   : OS_BASE_UNCACHED + PI_REGSP_MEM;
vu16 __DSPRegs[DSP_REG_UNUSED_31 + 1]   : OS_BASE_UNCACHED + PI_REGSP_DSP;


#if defined(HOLLYWOOD_REV) && !defined(NO_AHBPI_DSEA)
// Register access via AHB_IO_PI route
vu32 __DIRegs [DI_REG_UNUSED_15  + 1]   : OS_BASE_UNCACHED + AIP_DI_BASE;
vu32 __SIRegs [SI_REG_UNUSED_63  + 1]   : OS_BASE_UNCACHED + AIP_SI_BASE;
vu32 __EXIRegs[EXI_REG_UNUSED_15 + 1]   : OS_BASE_UNCACHED + AIP_EXI_BASE;
vu32 __AIRegs [AI_REG_UNUSED_7   + 1]   : OS_BASE_UNCACHED + AIP_AI_BASE;
#else
// Conventional PI register space (PI direct access to IO)
vu32 __DIRegs [DI_REG_UNUSED_15  + 1]   : OS_BASE_UNCACHED + IO_BASE_DI;
vu32 __SIRegs [SI_REG_UNUSED_63  + 1]   : OS_BASE_UNCACHED + IO_BASE_SI;
vu32 __EXIRegs[EXI_REG_UNUSED_15 + 1]   : OS_BASE_UNCACHED + IO_BASE_EXI;
vu32 __AIRegs [AI_REG_UNUSED_7   + 1]   : OS_BASE_UNCACHED + IO_BASE_AI;
#endif


// the PI is mostly emulated except for a few things
// The AMC EXI driver also relies on this variable, as it needs access to real
// PI registers, even if they are partially emulated.
vu32 __RealPIRegs [(PI_REG_CHIPID / 4) + 1] : OS_BASE_UNCACHED + REAL_PI_REGSP_PI;


#endif  // __FLIPPER_H__
