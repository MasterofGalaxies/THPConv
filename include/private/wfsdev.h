/*---------------------------------------------------------------------------*
  Project:     WFSDEV library
  File:        wfsdev.h
  Programmers: Kyu Ueno

  Copyright 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.
 *---------------------------------------------------------------------------*/


#ifndef WFSDEV_H__
#define WFSDEV_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * for debug purpose only.
 */
WFSResult WFSDebugSrvTest(const char* deviceName);
WFSResult WFSDebugCloseServerSocket(void);
WFSResult WFSDebugCloseCallbackSocket(void);

#ifdef __cplusplus
}
#endif

#endif  // WFSDEV_H__
