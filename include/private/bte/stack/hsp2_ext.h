/*****************************************************************************
** 
**  Name:          hsp2_ext.h
**
**
**  Description:   This file contains the HSP Profile's external interface to
**                 the core stack.
**
**
**  Copyright (c) 1999-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
*****************************************************************************/


#ifndef HSP2_EXT_H
#define HSP2_EXT_H

#include <private/bte/gki.h>
#include <private/bte/stack/hsp2_int.h>

#ifdef __cplusplus
extern "C" {
#endif


/* HSP2 FSM queue execute external declaration */
extern void hsp2_fsm_execute_evt_q(tHSP2_CB *cb);

/* HSP2 timer external declaration */
extern void hsp2_process_timeout(TIMER_LIST_ENT *p_tle);

#ifdef __cplusplus
}
#endif


#endif /* HSP2_EXT_H */

