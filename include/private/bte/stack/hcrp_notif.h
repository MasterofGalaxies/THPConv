/*****************************************************************************
** 
**    File Name:   hcrp_notif.h
**
**  Description:   This file contains the HCRP client notification internal
**                 interfaces.
**
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
*****************************************************************************/
#ifndef HCRP_NOTIF_H
#define HCRP_NOTIF_H

#include <private/bte/common/target.h>
#include <private/bte/gki.h>

enum
{
    NOTIF_OFF_STATE         = 0,    /* Notification has not been registered */
    NOTIF_REGISTERED_STATE  = 1,    /* Instance is registered */
    NOTIF_SDP_SEARCH_STATE  = 2,    /* (Server) service search is in progress */
    NOTIF_OPEN_STATE        = 3     /* Channel is open */
};
typedef UINT8 tHCRP_NOTIF_STATE;

/**********************************************
** Client notification control block information
***********************************************/
typedef struct
{
    UINT32              sdp_handle;    /* notification channel handle */
    UINT32              context_id;    /* given to server to be used for notification ID */
    TIMER_LIST_ENT      reg_te;        /* Timer that indicates when registration expires */
    UINT8               service_name_len;
    UINT8               service_name[HCRP_MAX_SERVICE_NAME_LEN + 1];
    UINT8               reg_cmd;       /* Stores a the current registration command request */
    tHCRP_NOTIF_STATE   state;
} tHCRP_NOTIF_CCB;

/**********************************************
** GAP notification control block information
***********************************************/
typedef struct
{
    tHCRP_NOTIF_CMD  cmd;       /* Message received by client */
    UINT16           handle;
    UINT16           psm;
    BOOLEAN          chan_open;
} tHCRP_NOTIF_GCB;


#endif /* HCRP_NOTIF_H */
