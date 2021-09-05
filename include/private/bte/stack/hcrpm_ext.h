/*****************************************************************************
** 
**  Name:          hcrp_ext.h
**
**
**  Description:   This file contains the HCRPM's external interface to
**                 the core stack.
**
**
**  Copyright (c) 2002-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
*****************************************************************************/
#ifndef HCRPM_EXT_H
#define HCRPM_EXT_H

#include <private/bte/gki.h>

/* HCRPM FSM execute external declaration */
extern void hcrpm_process_evt(BT_HDR *p_msg);

/* HCRP timer external declaration */
extern void hcrpm_process_timeout(TIMER_LIST_ENT *p_tle);

#endif /* HCRPM_EXT_H */
