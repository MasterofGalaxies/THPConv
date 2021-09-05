/*---------------------------------------------------------------------------*
  Project:  Revolution WFSDEV library
  File:     wfsdev.h

  Copyright 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.3  2008/01/10 12:21:01  ueno
  Modified error code of WFSDEVSetServer().

  Revision 1.2  2007/12/26 08:01:47  ueno
  Removed WFSDEVStartup().
  Added WFSDEVSetServer().

  Revision 1.1  2007/12/11 11:55:50  ueno
  Add WFSDEVInit() and WFSDEVStartup().


*---------------------------------------------------------------------------*/

#ifndef __WFSDEV_H__
#define __WFSDEV_H__

#include <revolution.h>

#ifdef __cplusplus
extern "C" {
#endif

// ---------------------------------------------------------------------
// WFSDEV error codes
// ---------------------------------------------------------------------
typedef enum {
    WFSDEV_RESULT_OK                      =    0,
    WFSDEV_RESULT_INVALID                 =   -3,
    WFSDEV_RESULT_LIB_ALREADY_INITIALIZED =   -6,
    WFSDEV_RESULT_FATAL_ERROR             =   -128

} WFSDEVResult;

//--------------------------------------------------------------------------------------------------------------
// WFSDEVInit
//--------------------------------------------------------------------------------------------------------------
WFSDEVResult WFSDEVInit(void* heap, u32 heapSize);
// Arguments:
// ----------
// heap      .. Points to a workspace buffer used for communication with the WFSDEV server.
//              Must be 32 byte aligned.
//              Must be in MEM2.
// heapSize  .. The size of the workspace buffer.
//              Must be a multiple of 32 bytes.
//
// Return Values:
// --------------
//      WFSDEV_RESULT_OK                      .. WFSDEV has been successfully initialized
//      WFSDEV_RESULT_LIB_ALREADY_INITIALIZED .. WFSDEV library has already been initialized.
//      WFSDEV_RESULT_INVALID                 .. The input parameters are invalid
//
// Description:
// ------------
// Initialize the WFSDEV library.

//--------------------------------------------------------------------------------------------------------------
// WFSDEVSetServer
//--------------------------------------------------------------------------------------------------------------
WFSDEVResult WFSDEVSetServer(char *pServerIP);
// Arguments: none.
// Return Values:
//      WFSDEV_RESULT_OK                      .. WFS emulation has been successfully started.
//      WFSDEV_RESULT_INVALID                 .. The input parameters are invalid
//
// Description:
// Set the IP address of WFSDEV server.
// Note WFSInit() will start connecting to the server specified in WFSDEVSetServer().


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif //define __WFSDEV_H__
