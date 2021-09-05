/*---------------------------------------------------------------------------*
 *       N I N T E N D O  C O N F I D E N T I A L  P R O P R I E T A R Y
 *---------------------------------------------------------------------------*
 *
 * Project: Dolphin OS - ARAM Device Driver and API
 * File:    aram.h
 *
 * Copyright 1999, 2000 Nintendo.  All rights reserved.
 *
 * These coded instructions, statements, and computer programs contain
 * proprietary information of Nintendo of America Inc. and/or Nintendo
 * Company Ltd., and are protected by Federal copyright law.  They may
 * not be disclosed to third parties or copied or duplicated in any form,
 * in whole or in part, without the prior written consent of Nintendo.
 *
 * $Log: not supported by cvs2svn $
 * Revision 1.1.1.1  2005/12/29 06:53:27  hiratsu
 * Initial import.
 *
 * Revision 1.1.1.1  2005/05/12 02:41:06  yasuh-to
 * dolphinシースツリーから移植
 *
    
    17    11/30/01 9:48a Eugene
    Added __ARGetInterruptStatus()
    
    16    11/29/01 4:53p Eugene
    Added __ARClearInterrupt().
    
    15    11/23/01 7:45p Eugene
    Added ARClear() API and __ARClearArea() primitive. ARInit() now clears
    internal ARAM after performing size check. 
    
    14    9/20/01 6:11p Eugene
    Ooops. Accidently cut-n-pasted a static module function prototype into
    this public header file. 
    
    13    6/11/01 8:07p Tian
    Removed spurious static keyword
    
    12    5/01/01 6:44p Eugene
    Added XXXReset() functions to clear respective init flags. 
    All XXXInit() functions modified to return safely if respective init
    flags are asserted.
    
    11    4/30/01 5:54p Eugene
    Added OS-reserved area to ARAM. ARInit() now returns base address of
    user area. Developers may also query this address by using
    ARGetBaseAddress(). Also added ARCheckInit(). This will return a flag
    TRUE if ARInit() has been called, FALSE if ARInit() has never been
    called. 
    
    10    12/08/00 10:51p Eugene
    Callback registration functions now return old callback (if any).
    
    9     11/21/00 8:26p Eugene
    Oops, forgot to checkin correction to ARStartDMARead() macro definition
    (had an extraneous space...)
    
    8     9/08/00 9:03p Eugene
    
    7     5/25/00 1:27a Eugene
    Added temporary ARSetSize() function to force ARAM size config. 
    For debugging only. 
    
    
    6     5/23/00 3:40p Eugene
    Added #define for AR_STACK_INDEX_ENTRY_SIZE
    
    5     4/11/00 7:41p Eugene
    Casting warning. Ooops.
    
    4     4/11/00 7:34p Eugene
    ARGetDMAStatus() now returns a u16, which is native size of register.
    
    3     3/13/00 6:33p Eugene
    Removed size-check stuff (relocated to BS2)
    Corrected function prototypes for ARStartDMA(), ARInit(), ARFree().
    
    2     3/10/00 6:34p Eugene
    
    1     3/07/00 7:08p Eugene
    Public header file for ARAM driver/API.
 *   
 *
 * $NoKeywords: $
 *
 *---------------------------------------------------------------------------*
 *
 * Description
 * -----------
 * This is the public API definition file for the ARAM device driver. 
 * Applications or OS components which need access to the ARAM must include
 * this file.
 *
 *---------------------------------------------------------------------------*/
  
#ifndef __ARAM_H__
#define __ARAM_H__

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------*
 * Includes
 *---------------------------------------------------------------------------*/
#include <revolution/types.h>

/*---------------------------------------------------------------------------*
 * Definitions
 *---------------------------------------------------------------------------*/

#define AR_STACK_INDEX_ENTRY_SIZE   sizeof(u32)

#define ARAM_DIR_MRAM_TO_ARAM       0x00
#define ARAM_DIR_ARAM_TO_MRAM       0x01

#define AR_CLEAR_INTERNAL_ALL       0x00
#define AR_CLEAR_INTERNAL_USER      0x01
#define AR_CLEAR_EXPANSION          0x02


/*---------------------------------------------------------------------------*
 * Types/Declarations
 *---------------------------------------------------------------------------*/
typedef void (*ARCallback)(void);

 
/*---------------------------------------------------------------------------*
 * Globals
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
 * Function Prototypes
 *---------------------------------------------------------------------------*/

ARCallback  ARRegisterDMACallback   (ARCallback callback);
u32         ARGetDMAStatus          (void);
void        ARStartDMA              (u32 type, u32 mainmem_addr, u32 aram_addr, u32 length);
u32         ARInit                  (u32 *stack_index_addr, u32 num_entries);
u32         ARGetBaseAddress        (void);
BOOL        ARCheckInit             (void);
void        ARReset                 (void);
u32         ARAlloc                 (u32 length);
u32         ARFree                  (u32 *length);
u32         ARGetSize               (void);
u32         ARGetInternalSize       (void);
void        ARSetSize               (void);
void        ARClear                 (u32 flag);

void        __ARClearInterrupt      (void);
u16         __ARGetInterruptStatus  (void);

/*---------------------------------------------------------------------------*
 * Macro definitions
 *---------------------------------------------------------------------------*/

#define ARStartDMARead(mmem, aram, len)  ARStartDMA(ARAM_DIR_ARAM_TO_MRAM, mmem, aram, len)
#define ARStartDMAWrite(mmem, aram, len) ARStartDMA(ARAM_DIR_MRAM_TO_ARAM, mmem, aram, len)


#ifdef __cplusplus
}
#endif

#endif // __ARAM_H__
