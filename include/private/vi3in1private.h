/*---------------------------------------------------------------------------*
  Project:  Revolution 3in1
  File:     vi3in1private.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.16  2007/05/16 05:48:16  urata
  Removed functions and enums for Arcade system.

  Revision 1.15  2007/03/22 02:24:56  urata
  Re-numberd the enum of VIOverDrive.

  Revision 1.14  2006/10/10 07:33:11  urata
  Added VISetRGBModeImm.

  Revision 1.13  2006/09/05 13:23:50  urata
  Added __VISetRevolutionModeSimple and __VISetTrapFilterImm.

  Revision 1.12  2006/07/24 05:58:21  urata
  Added __VISetRGBModeImm.

  Revision 1.11  2006/05/10 06:35:05  urata
  Renamed __VISetSTBMode to __VISetDTVMode.

  Revision 1.10  2006/04/20 11:19:02  urata
  Added __VISetCGMSClear.

  Revision 1.9  2006/04/19 08:36:25  urata
  Modified a value of the OverDrive define.

  Revision 1.8  2006/04/18 10:08:00  urata
  Defined a value to some defines.

  Revision 1.7  2006/04/07 12:33:13  urata
  Added __VISetFilter4EURGB60.

  Revision 1.6  2006/03/14 14:38:15  urata
  Added __VISetSTBMode.

  Revision 1.5  2006/03/13 12:56:31  urata
  Added __VIGetVenderID().

  Revision 1.4  2006/03/06 04:28:50  urata
  Added __VISendI2CData, __VIReceiveI2CData, VIGetI2CType for debugging I2C.
  (Moved from build/libraries/vi/include)

  Revision 1.3  2006/02/25 10:14:52  urata
  Added "Internal" functions and bitmask defines.

  Revision 1.2  2006/02/10 11:25:33  urata
  Included /include/revolution/vi/vitypes.h.

  Revision 1.1  2006/02/09 03:02:10  urata
  Initial checkin.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __VI3IN1PRIVATE_H__
#define __VI3IN1PRIVATE_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <revolution/vi/vitypes.h>
#include <revolution/vi/vi3in1types.h>

typedef enum _VITiming
{
    VI_TMG_GAME = 0,
    VI_TMG_DVD  = 1
} VITiming;

typedef enum _VIVideo
{
    VI_VMODE_NTSC   = 0,
    VI_VMODE_MPAL   = 1,
    VI_VMODE_PAL    = 2,
    VI_VMODE_RGB    = 3
} VIVideo;


typedef struct VIGammaObj
{
    u16    a[6];     
    u8   yin[7];    //Input luma
    u16 yout[7];    //Output luma(apply a gamma correction)
} VIGammaObj;


// Private function
static void __VISetVideoMode( VIVideo vmode, VIBool outsel );   // NTSC,MPAL,PAL,RGB
void __VISetCCSEL           ( VIBool ccsel );                   // Need to set "VI_ENABLE"
void __VISetOverSampling    ( VIBool os );                      // Need to set "VI_ENABLE"
void __VISetVolume          ( u8 volumeL, u8 volumeR );         // Need to set "0x8E"
void __VISetYUVSEL          ( VIBool outsel );                  // Not adapted to hot swap of VISEL0
void __VISetTiming          ( VITiming timing );
void __VISetVBICtrl         ( VIBool cgms, VIBool wss, VIBool cc );
void __VISetGammaImm        ( VIGammaObj *gamma );
void __VISetFilter4EURGB60  ( VIBool enable );
void __VISetCGMSClear       ( void );

// For IPL
void __VIInit3in1           ( VITVMode mode );
void __VISetRevolutionMode  ( void );
void __VISetDVDMode         ( void );
void __VISetLegacyMode      ( void );
void __VISetDTVMode         ( void );
void __VISet3in1Output      ( VIBool enable );
s32 __VISendI2CData         ( u8 slaveAddr, u8 *pData, s32 nBytes ) ;
s32 __VIReceiveI2CData      ( u8 slaveAddr, u8 *pData, int maxBytes );
u32   VIGetI2CType          ( void );
u32 __VIGetVenderID         ( void );
void VISetRGBModeImm        ( void );
void __VISetTrapFilterImm   ( VIBool filter );
void __VISetDACPower        ( VIBool enable );

// For Internal
void __VISetCGMS            ( void );
void __VISetWSS             ( void );
void __VISetClosedCaption   ( void );
void __VISetMacrovision     ( void );
void __VISetGamma           ( void );
void __VISetTrapFilter      ( void );
void __VISetRGBOverDrive    ( void );
void __VISetRGBModeImm      ( void );
void __VISetRevolutionModeSimple( void );


#define VI_BITMASK_CGMS             0x1
#define VI_BITMASK_WSS              0x2
#define VI_BITMASK_CLOSED_CAPTION   0x4
#define VI_BITMASK_MACROVISION      0x08
#define VI_BITMASK_GAMMA            0x10
#define VI_BITMASK_TRAP_FILTER      0x20
#define VI_BITMASK_RGB_OVERDRIVE    0x40
#define VI_BITMASK_RGB_IMM          0x80

extern volatile u32 Vdac_Flag_Changed;

#ifdef __cplusplus
}
#endif

#endif  // __VI3IN1PRIVATE_H__
