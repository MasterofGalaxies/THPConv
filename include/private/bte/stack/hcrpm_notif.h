/*****************************************************************************
** 
**    File Name:   hcrp_notif.h
**
**  Description:   This file contains the HCRP internal interfaces.
**
**
**  Copyright (c) 2001-2004 WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
*****************************************************************************/
#ifndef HCRPM_NOTIF_H
#define HCRPM_NOTIF_H

#include <private/bte/common/target.h>
#include <private/bte/gki.h>
#include <private/bte/stack/hcrpm_api.h>

/* Notification Command Definitions */
typedef struct
{
    tHCRPM_NOTIF_REG_INFO   client;      /* Client's bdaddr and context ID to notify */
    UINT16                  param_len;  /* Number of parameter bytes to follow */
    UINT16                  pdu_id;     /* Register or deregister for notifications */

#if HCRPM_MAX_NOTIF_PARAM_LEN > 0
    UINT8                   params[HCRPM_MAX_NOTIF_PARAM_LEN];
#endif
} tHCRPM_NOTIF_CMD_MSG;

/**********************************************
** Client registration control block
***********************************************/
typedef struct
{
    UINT32                keep_alive;    /* Time to keep client connection alive before shutting it down */
    TIMER_LIST_ENT        reg_te;        /* Timer that indicates when registration expires */
    tHCRPM_NOTIF_REG_INFO creg;
    BOOLEAN               is_registered;
} tHCRPM_NOTIF_CCB;

/**********************************************
** GAP notification control block information
***********************************************/
typedef struct
{
    tHCRPM_NOTIF_CCB    *p_ccb;         /* Points to the current client registration */
    TIMER_LIST_ENT       keep_alive_te; /* Keep the notification channel open this long */
    UINT32               keep_alive;    /* Time to keep client connection alive before shutting it down */
    UINT16               handle;
    UINT16               psm;
    BOOLEAN              chan_open;
} tHCRPM_NOTIF_GCB;

/**********************************************
** Notification control block information
***********************************************/
typedef struct
{
    tSDP_DISCOVERY_DB       *p_db;          /* Discovery database */
    tHCRPM_NOTIF_GCB         gcb;           /* GAP channel related information */
    tHCRPM_NOTIF_CMD_MSG     cmd;           /* Message to send to client */
    tHCRPM_NOTIF_CCB         regtbl[HCRP_MAX_NOTIF_CLIENTS];
    BOOLEAN                  in_use;        /* Notification Control block is in use? */
} tHCRPM_NOTIF_CB;

#endif /* HCRPM_NOTIF_H */

