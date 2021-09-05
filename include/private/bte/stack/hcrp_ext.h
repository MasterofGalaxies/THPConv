/*****************************************************************************
** 
**  Name:          hcrp_ext.h
**
**
**  Description:   This file contains the HCRP's external interface to
**                 the core stack.
**
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
*****************************************************************************/

#ifndef HCRP_EXT_H
#define HCRP_EXT_H

#include <private/bte/gki.h>

/* HCRP FSM execute external declaration */
extern void hcrp_process_evt(BT_HDR *p_msg);

/* HCRP timer external declaration */
extern void hcrp_process_timeout(TIMER_LIST_ENT *p_tle);

#endif /* HCRP_EXT_H */

