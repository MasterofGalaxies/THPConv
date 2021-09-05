///////////////////////////////////////////////////////////////////////////////
//
// File:        cpg_api.h
//
// Description: This file contains the interface for the Cell Phone GUI IEL.
//
//
//  Copyright (c) 2003-2004, WIDCOMM Inc., All Rights Reserved.
//  WIDCOMM Bluetooth Core. Proprietary and confidential.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _CPG_API_H
#define _CPG_API_H

#define BT_API              __declspec(dllexport)

#define CPG_UP_EVENT        (0x1000)
#define CPG_DOWN_EVENT      (0x1001)
#define CPG_LEFT_EVENT      (0x1002)
#define CPG_RIGHT_EVENT     (0x1003)
#define CPG_OK_EVENT        (0x1004)
#define CPG_CANCEL_EVENT    (0x1005)
#define CPG_ONE_EVENT       (0x1006)
#define CPG_TWO_EVENT       (0x1007)
#define CPG_THREE_EVENT     (0x1008)
#define CPG_FOUR_EVENT      (0x1009)
#define CPG_FIVE_EVENT      (0x1010)
#define CPG_SIX_EVENT       (0x1011)
#define CPG_SEVEN_EVENT     (0x1012)
#define CPG_EIGHT_EVENT     (0x1013)
#define CPG_NINE_EVENT      (0x1014)
#define CPG_ZERO_EVENT      (0x1015)
#define CPG_POUND_EVENT     (0x1016)
#define CPG_STAR_EVENT      (0x1017)


#ifdef __cplusplus
extern "C" {
#endif
typedef void tCPG_event_callback(int event, int data);

BT_API extern void CPG_set_event_cback(tCPG_event_callback *p_cback);

BT_API extern void CPG_set_top_menu(int menu);

BT_API extern int  CPG_add_menu(char *str);
BT_API extern int  CPG_remove_menu(int menu);

BT_API extern int  CPG_add_menu_item(int menu, char *str);
BT_API extern int  CPG_remove_menu_item(int menu, int item);

BT_API extern void CPG_make_menu_link(int menu, int item, int link);
BT_API extern void CPG_make_menu_event(int menu, int item, int event);

BT_API extern int  CPG_new_event();

#ifdef __cplusplus
}
#endif


#endif // _CG_API_H
