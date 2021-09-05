/*******************************************************************************
 * 
 *   (C) 1999, 2000 ARTX INC..  ALL RIGHTS RESERVED.  UNPUBLISHED -- RIGHTS
 *   RESERVED UNDER THE COPYRIGHT LAWS OF THE UNITED STATES.  USE OF A
 *   COPYRIGHT NOTICE IS PRECAUTIONARY ONLY AND DOES NOT IMPLY PUBLICATION
 *   OR DISCLOSURE.
 *
 *   THIS SOFTWARE CONTAINS CONFIDENTIAL INFORMATION AND TRADE SECRETS OF
 *   ARTX INC..  USE, DISCLOSURE, OR REPRODUCTION IS PROHIBITED WITHOUT
 *   THE PRIOR EXPRESS WRITTEN PERMISSION OF ARTX INC..
 *
 *                   RESTRICTED RIGHTS LEGEND
 *
 *   Use, duplication, or disclosure by the Government is subject to
 *   restrictions as set forth in subparagraph (c)(1)(ii) of the Rights
 *   in Technical Data and Computer Software clause at DFARS 252.227-7013
 *   or subparagraphs (c)(1) and (2) of Commercial Computer Software --
 *   Restricted Rights at 48 CFR 52.227-19, as applicable. 
 *
 *   ArtX Inc.
 *   3400 Hillview Ave, Bldg 5
 *   Palo Alto, CA 94304
 *
 ******************************************************************************/

#ifndef __SECRET_H__
#define __SECRET_H__

#include <revolution/types.h>

//******************************************************************************
//
//  Graphics Library hidden data types and functions.
//  
//******************************************************************************

#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
// Raster register bypass function (hidden)
//------------------------------------------------------------------------------
#ifdef _DEBUG
extern void __GXBypass (u32 reg);
extern u16 __GXReadPEReg (u32 reg);
#endif

//------------------------------------------------------------------------------
// SU texture size polling (needed for top random)
//------------------------------------------------------------------------------
extern void __GXSetSUTexRegs(void);
extern void __GXGetSUTexSize(GXTexCoordID coord, u16 *width, u16 *height);

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif // __SECRET_H__
