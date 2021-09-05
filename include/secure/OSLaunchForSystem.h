/*---------------------------------------------------------------------------*
  Project:      Launch NAND application and handling
  File:         OSLaunchForSystem.h

  Copyright (C) 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.3  2007/06/20 12:12:56  wada_jumpei
  Modified to check firmware's existence before launching NAND app

  Revision 1.2  2007/06/19 09:36:06  wada_jumpei
  Made __OSGetValidTicketIndex instead of copying ESMisc::GetValidTicketIndex

  Revision 1.1  2007/04/20 13:13:43  wada_jumpei
  Added non-limited version new launch functions for system

 *---------------------------------------------------------------------------*/

#ifndef __OSLAUNCHFORSYSTEM_H__
#define __OSLAUNCHFORSYSTEM_H__

#include <private/OSLaunchTitle.h>
#include <secure/estypes.h>

#ifdef __cplusplus
extern "C" {
#endif

void __OSLaunchTitlevForSystem(OSTitleId titleId, u32 LaunchCode, char* const argv[]);
void __OSLaunchTitlelForSystem(OSTitleId titleId, u32 LaunchCode, const char* arg0, .../*, (char*)NULL */);
s32  __OSGetValidTicketIndex( ESTicketView* ticketViewList, u32 numTickets );
BOOL __OSCheckTmdCountryCode(ESTmdView* tmd);
BOOL __OSCheckCompanyCode(ESTitleId titleId, BOOL diskApp);

#ifdef __cplusplus
}
#endif

#endif // __OSLAUNCHFORSYSTEM_H__