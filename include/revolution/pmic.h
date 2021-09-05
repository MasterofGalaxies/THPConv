/*---------------------------------------------------------------------------*
  Project:  Revolution PMIC library
  File:     pmic.h

  Copyright (C)2008 Nintendo  All Rights Reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1  2008/01/22 02:43:20  aka
  initial check-in.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __PMIC_H__
#define __PMIC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution.h>

/*---------------------------------------------------------------------------*
   definitions
 *---------------------------------------------------------------------------*/

// Working area size on MEM2 which P-MIC lib uses.
#define PMIC_MEM2_WORK               32768 // 32KB

//
// Returns
//

typedef enum
{
    PMIC_ERR_OK                 =   0,    // OK / no error
    
    PMIC_ERR_INVALID_ARGUMENTS  =  -1,    // invalide arguments
    
    PMIC_ERR_NO_DEVICE          =  -2,    // P-MIC is not inserted.
    PMIC_ERR_INVALID_DEVICE     =  -3,    // Non P-MIC device is inserted.

    PMIC_ERR_INVALID_STATE      =  -4,    // Can't execute on current state.
    PMIC_ERR_NOT_OPENED         =  -5,    // P-MIC is not ready (opened).
    PMIC_ERR_BUSY               =  -6,    // Please re-call later.
    
    PMIC_ERR_USB_ERROR          =  -7,    // Error is occured during USB transaction.
    
    PMIC_ERR_FATAL              =  -100   // Unrecoverable error is occured.
    
} PMIC_ERR;

//
// Source Rate
//

typedef enum
{
    PMIC_FREQ_32KHz = 0,
    PMIC_FREQ_48KHz
    
} PMIC_FREQ;
    
//
// Callbacks
//

typedef void (*PMICCallback) ( PMIC_ERR result, void* arg );

/*---------------------------------------------------------------------------*
   P-MIC fundamental functions
 *---------------------------------------------------------------------------*/

PMIC_ERR         PMICInit                   ( void* mem2 );
PMIC_ERR         PMICQuit                   ( void );

PMIC_ERR         PMICProbe                  ( void );

PMIC_ERR         PMICOpenAsync              ( PMICCallback cb, void* arg );
PMIC_ERR         PMICOpen                   ( void );

PMIC_ERR         PMICCloseAsync             ( PMICCallback cb, void* arg );
PMIC_ERR         PMICClose                  ( void );
    
PMIC_ERR         PMICStartAsync             ( PMICCallback cb, void* arg );
PMIC_ERR         PMICStart                  ( void );

PMIC_ERR         PMICStopAsync              ( PMICCallback cb, void* arg );
PMIC_ERR         PMICStop                   ( void );

void             PMICSetFirm                ( void* firm, s32 size );

/*---------------------------------------------------------------------------*
   P-MIC data transfer functions
 *---------------------------------------------------------------------------*/

s32              PMICGetReadableSamples     ( void );
s32              PMICRead                   ( s16* buffer, s32 samples );
    
s32              PMICGetWritableSamples     ( void );
s32              PMICWrite                  ( s16* buffer, s32 samples );

/*---------------------------------------------------------------------------*
   P-MIC data convert functions
 *---------------------------------------------------------------------------*/

s32              PMICChangeRate             ( s16*       input,
                                              s32        samples,
                                              PMIC_FREQ  freq,
                                              s16*       output,
                                              BOOL       init );

/*---------------------------------------------------------------------------*
   P-MIC setting functions
 *---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
   P-MIC utility (for VOIP) functions
 *---------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif // __PMIC_H__
