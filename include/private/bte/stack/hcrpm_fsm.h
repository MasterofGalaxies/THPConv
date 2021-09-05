/******************************************************************************
**
**   File Name:  hcrpm_fsm.h
**
** Description:  This file contains definitions used by the Multi-Client Server
**               HCRP State Machine.
**
**
**  Copyright (c) 2002-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
******************************************************************************/
#ifndef HCRPM_FSM_H
#define HCRPM_FSM_H

#include <private/bte/common/target.h>

/* Main FSM States for each client instance (Only accessed if HCRPM is regsitered */
enum
{
    /* Multi-Client Server States */
    HCRPM_FSM_OFF_ST = 0xff,
    HCRPM_FSM_IDLE_ST = 0,
    HCRPM_FSM_W4_OPEN_ST,
    HCRPM_FSM_OPEN_ST,
    HCRPM_FSM_W4_CLOSE_ST
};
typedef UINT8 tHCRPM_FSM_STATE;


/* Main FSM Events */
enum
{
    HCRPM_FSM_NULL_EVT = 0,         /* Ignored events are redirected to null event  */
    HCRPM_FSM_SEND_DATA_API_EVT,    /* Sent by HCRPM_SendData API function to
                                       send data to the client/server               */
    HCRPM_FSM_RCV_DATA_EVT,         /* Sent by GAP callback when data is received   */
    HCRPM_FSM_RCV_READY_API_EVT,    /* Sent by HCRPM_RcvReady API to update credits */
    HCRPM_FSM_RCV_CMD_EVT,          /* Received a peer command on the control
                                       channel. This event handles the credit,
                                       vendor specific, LPT status, 1284ID,
                                       notification registration, and hard/soft
                                       reset command/response events.               */
    HCRPM_FSM_DATA_CHAN_OPN_EVT,    /* Sent by GAP cback when data channel is open  */
    HCRPM_FSM_CTRL_CHAN_OPN_EVT,    /* Sent by GAP cback when ctrl channel is open  */
    HCRPM_FSM_GAP_CHAN_CLS_EVT,     /* Sent by GAP cback if data, ctrl chan is clsd */
    HCRPM_FSM_CLOSING_TOUT_EVT,     /* Timer expiration in HCRPM_FSM_W4_CLOSE_ST    */
    HCRPM_FSM_DATA_CONGESTED_EVT,   /* Data Channel is congested                    */
    HCRPM_FSM_SOFT_RESET_EVT,       /* Soft reset event occured                     */
    HCRPM_FSM_PROTO_RSP_API_EVT,    /* Sent by HCRPM_SendProtoRsp() to respond to a
                                        peer device's protocol request              */
    HCRPM_FSM_OPENING_TOUT_EVT,     /* Timer expired in the HCRPM_FSM_W4_OPEN_ST
                                       state                                        */
    HCRPM_FSM_HARD_RESET_EVT,       /* Hard reset event occured                     */
    HCRPM_FSM_SET_MODE_API_EVT,     /* Sent by HCRPM_SetMode() when mode is public
                                       or private online                            */
    HCRPM_FSM_REG_SERVER_API_EVT,   /* Sent by API to register HCRP                 */
    HCRPM_FSM_DEREGISTER_API_EVT,   /* Sent by API to deregister HCRP               */
    HCRPM_FSM_REG_UPDATE_API_EVT    /* Registration update API called               */

    /* Notification Substate Events (server) */
#if HCRP_NOTIFICATION_INCLUDED == TRUE
    /* Need a comma to complete the table syntax -> */ ,
    HCRPM_FSM_NOTIF_API_EVT,        /* Sent by HCRPM_SendNotification() to send a
                                       notification event to the client             */
    HCRPM_FSM_NOTIF_OPEN_EVT,       /* Sent by GAP cback when notif channel is open */
    HCRPM_FSM_NOTIF_CLOSE_IND_EVT,  /* Sent by GAP cback when the notification
                                       channel has been closed                      */
    HCRPM_FSM_NOTIF_SDP_CMPL_EVT    /* Successful service discovery                 */
#endif
};
typedef UINT8 tHCRPM_FSM_EVT;


#if HCRP_FSM_DEBUG == TRUE
extern const char *hcrpm_status_str[];
/* Prints out the string associated with the return status */
#define HCRPMSTATUS(x)    (((x) == HCRPM_SUCCESS) ? "HCRPM_SUCCESS" : hcrpm_status_str[(x) - HCRPM_ERR_GRP])
#endif

#endif /* HCRPM_FSM_H */
