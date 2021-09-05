/*---------------------------------------------------------------------------*
  Project:      Launch NAND application and handling
  File:         OSLaunchTitle.h

  Copyright (C) 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.7  2007/07/19 02:25:32  wada_jumpei
  Moved some APIs and definition to OSTitle.h

  Revision 1.6  2007/07/17 09:35:10  wada_jumpei
  Added OSGetTitleStatus in order to get the status of a title.
  Modified OSIsTitleInstalled to use OSGetTitleStatus.

  Revision 1.5  2007/04/25 08:31:11  ooizumi
  Modified to include <revolution/types.h>.

  Revision 1.4  2007/03/22 08:20:58  wada_jumpei
  Changed functions to get last applications' information.

  Revision 1.3  2007/03/14 09:35:28  wada_jumpei
  Added some functions to get information about last application.

  Revision 1.2  2006/12/20 01:12:50  wada_jumpei
  Added OSIsTitleInstalled.

  Revision 1.1  2006/11/29 01:50:00  wada_jumpei
  Initial check in.

 *---------------------------------------------------------------------------*/

#ifndef __OSLAUNCHTITLE_H__
#define __OSLAUNCHTITLE_H__

#include <revolution/types.h>
#include <private/OSTitle.h>

#ifdef __cplusplus
extern "C" {
#endif

void OSLaunchTitlev(OSTitleId titleId, u32 LaunchCode, char* const argv[]);
void OSLaunchTitlel(OSTitleId titleId, u32 LaunchCode, const char* arg0, .../*, (char*)NULL */);
void OSReturnToLastTitle(u32 ReturnCode);

OSTitleId    OSGetLastTitleId(void);
u8           OSGetLastAppType(void);
const char*  OSGetLastAppGamename(void);


#ifdef __cplusplus
}
#endif

#endif // __OSLAUNCHTITLE_H__