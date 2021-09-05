/*---------------------------------------------------------------------------*
  Project:  Dolphin OS Timer API
  File:     OSTimer.h

  Copyright 1998, 1999 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/12/29 06:53:28  hiratsu
  Initial import.

  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    2     8/12/02 15:24 Shiki
    Clean up.

    1     3/16/00 7:01p Shiki
    Initial check-in (moved from os.h).

    13    3/14/00 2:44p Shiki
    Added ASSERTMSGn() macros.

    12    3/01/00 3:29p Tian
    Cleaned up clock rate settings.  They were wrong for GEKKO.

    11    2/15/00 6:03p Shiki
    Revised OS_CONSOLE_* define names.

    10    2/01/00 1:50p Shiki
    Added OS_CONSOLE_DEVELOPMENT1 define name.

    9     1/18/00 6:22p Shiki
      Included <dolphin/os/OSMutex.h>.

    8     1/18/00 5:46p Tian
    MINNOW_MARLIN -> MINNOW

    7     1/18/00 3:29p Shiki
    Included <dolphin/os/OSMessage.h>.

    6     1/18/00 1:57p Tian
    Changed the address translation macros for MINNOW_MARLIN to enable FIFO
    emulation.  Because ORs/ANDs are used, we sacrifice some safety.

    5     1/18/00 10:43a Shiki
    Implemented basic thread API.

    4     1/10/00 2:43p Hashida
    Changed so that OSTicksToMicroseconds and OSMicrosecondsToTicks macros
    works with 33MHz busclock systems.

    3     12/16/99 2:52p Tian
    New core/bus speeds for Gekko + Spruce

    2     12/15/99 3:08p Shiki
    Added OS_*_CLOCK defines for MINNOW.

    17    10/07/99 4:13p Shiki
    Added Idle Function API section.

    16    8/23/99 7:18p Shiki
    Added OS_BASE_CACHED and  OS_BASE_UNCACHED.

    15    8/02/99 2:20p Shiki
    Included OSInterrupt.h

    14    99/07/27 4:51p Shiki
    Added function versions of address translation APIs.

    13    99/07/27 3:43p Shiki
    Revised OSTicksToNanoseconds() and  OSNanosecondsToTicks().

    12    99/07/27 3:16p Shiki
    Fixed time-cycle conversion macros.

    11    99/07/12 9:37p Shiki
    Included OSError.h

    10    99/07/12 3:24p Shiki
    Cleanup. Removed EPPC specific OSReport() and OSPanic() declarations.

    9     6/04/99 3:02p Tianli01
    Cleanup.  Added rounding macros, OSTicksToCycles.

    8     5/25/99 5:28p Shiki
    Added the following line:
    #include <dolphin/os/OSAlloc.h>

    7     5/19/99 5:13p Shiki
    Renamed Halt() to OSHalt().

    6     5/19/99 4:20p Shiki
    Cleaned up address translation macros.

    5     5/18/99 5:06p Shiki
    Fixed address translation macros.

    4     5/11/99 4:42p Shiki
    Refreshed include tree.

    2     5/03/99 5:26p Tianli01
    PPC->EPPC

    1     4/30/99 12:49p Tianli01

    10    4/21/99 4:12p Tianli01
    Added OSGetConsoleType.  Changed OSInterruptLevel to BOOL.  Cleaned up
    Interrupt interface.

    9     4/19/99 5:04p Shiki
    Revised real-time clock API related definitions.

    8     7/15/99 3:46p Shiki
    1. Cleaned up ASSERT stuff
    2. Moved to _DEBUG (avoid DEBUG)

    7     4/15/99 2:45p Tianli01
    Removed OS_BASE_CLOCK (it should have been OS_BUS_CLOCK).  Added
    ASSERTs for PPC.

    6     4/13/99 5:48p Tianli01
    Rearranged.  Added stopwatch APIs.

    5     4/12/99 7:45p Tianli01
    Deleted OSEvent stuff.  Move to DEBUG for consistency (avoid NDEBUG).
    Fixed Halt/OSPanic for PPC target

    4     4/01/99 7:53p Tianli01
    Added OSTimer interfaces.  Fixed time base constants for Arthur.

    3     3/31/99 6:10p Tianli01
    Added arena APIs (not implemented) , address translation constants for
    assembly code, PPC OSReport APIs (only relevant for Arthur board).

    2     3/26/99 2:06p Tianli01
    Broke up into more header files (OSContext.h, OSEmu.h, OSException.h),
    cleaned up, address translation macros added.

    1     3/04/99 2:22p Tianli01
    Initial checkin to new tree

    5     12/18/98 11:28a Shiki
    Removed declaration of  __OSLoadContext2()

    4     12/18/98 9:25a Shiki
    Fixed definition of OSContext for Gecko

    3     12/17/98 9:04a Shiki
    Fixed ASSERT macro

    2     12/16/98 8:54p Shiki
    1. Used OSContext for windows stack environment instead of jmp_buf
       to support __OSWinCall() API
    2. Added the __cdecl modifiers to inline assembler functions

    1     12/15/98 10:08p Shiki

  Change History:
    12/15/1998  Shiki Okasaka   1. Added __OSRaiseException() and
                                   __OSRaiseInterrupt()
                                2. Revised __OSMach structure
    12/12/1998  Shiki Okasaka   Added OSSwitchStack()
    12/11/1998  Shiki Okasaka   1. Moved bEnabled member from __OSMach to
                                   OSContext
                                2. Fixed OSTime from u64 to s64
    12/10/1998  Shiki Okasaka   Revised to refrect the coding guidelines
    12/07/1998  Shiki Okasaka   Included <types.h>
    12/06/1998  Shiki Okasaka   1. Revised __OSInitMach not to time-out
                                   but to take data pointer
                                2. Added OSClearContext()
    12/05/1998  Shiki Okasaka   1. Fixed __OSMach to keep stack bottom
                                2. Revised __OSInitMach to time-out
                                3. Revised OSSaveContext()
    12/03/1998  Shiki Okasaka   1. Added interrupt time-out
                                2. Fixed OSSaveContext()
    12/02/1998  Shiki Okasaka   2nd Edition
    11/28/1998  Shiki Okasaka   Created

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __OSTIMER_H__
#define __OSTIMER_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __DOLPHIN_RC__
#include <revolution/types.h>
#endif  // __DOLPHIN_RC__

/*---------------------------------------------------------------------------*
    Timer API
 *---------------------------------------------------------------------------*/

typedef void    (*OSTimerCallback)  ( void );

// Timer modes
#define         OS_TIMER_PERIODIC   1
#define         OS_TIMER_ONE_SHOT   2

OSTimerCallback OSSetTimerCallback  ( OSTimerCallback cb );
void            OSInitTimer         ( OSTick time, u32 mode );
void            OSStartTimer        ( void );
void            OSStopTimer         ( void );

#ifdef __cplusplus
}
#endif

#endif  // __OSTIMER_H__
