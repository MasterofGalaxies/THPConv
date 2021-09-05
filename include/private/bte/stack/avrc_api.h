/*****************************************************************************
**
**  Name:       avrc_api.h
**
**  Description:Interface to AVRCP Application Programming Interface
**
**  Copyright (c) 2003-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef AVRC_API_H
#define AVRC_API_H

#include <private/bte/stack/avct_api.h>
#include <private/bte/stack/sdp_api.h>


/*****************************************************************************
**  constants
*****************************************************************************/
#define AVRC_SUB_TYPE_LEN   4

/* API function return value result codes. */
#define AVRC_SUCCESS        AVCT_SUCCESS        /* 0 Function successful */
#define AVRC_NO_RESOURCES   AVCT_NO_RESOURCES   /* 1 Not enough resources */
#define AVRC_BAD_HANDLE     AVCT_BAD_HANDLE     /* 2 Bad handle */
#define AVRC_PID_IN_USE     AVCT_PID_IN_USE     /* 3 PID already in use */
#define AVRC_NOT_OPEN       AVCT_NOT_OPEN       /* 4 Connection not open */
#define AVRC_FAIL           0x10                /* 0x10 generic failure */
#define AVRC_BAD_PARAM      0x11                /* 0x11 bad parameter   */

/* Control role. */
#define AVRC_CT_TARGET      1                     /* target  */
#define AVRC_CT_CONTROL     2                     /* controller  */

/* command type codes */
#define AVRC_CMD_CTRL       0   /* Instruct a target to perform an operation */
#define AVRC_CMD_STATUS     1   /* Check a device’s current status */
#define AVRC_CMD_SPEC_INQ   2   /* Check whether a target supports a particular
                                   control command; all operands are included */
#define AVRC_CMD_NOTIF      3   /* Used for receiving notification of a change in a device’s state */
#define AVRC_CMD_GEN_INQ    4   /* Check whether a target supports a particular
                                   control command; operands are not included */

/* response type codes */
#define AVRC_RSP_NOT_IMPL   8   /* The target does not implement the command specified
                                   by the opcode and operand,
                                   or doesn’t implement the specified subunit */
#define AVRC_RSP_ACCEPT     9   /* The target executed or is executing the command */
#define AVRC_RSP_REJ        10  /* The target implements the command specified by the
                                   opcode but cannot respond because the current state
                                   of the target doesn’t allow it */
#define AVRC_RSP_IN_TRANS   11  /* The target implements the status command but it is
                                   in a state of transition; the status command may
                                   be retried at a future time */
#define AVRC_RSP_IMPL_STBL  12  /* For specific inquiry or general inquiy commands,
                                   the target implements the command; for status
                                   commands, the target returns stable and includes
                                   the status results */
#define AVRC_RSP_CHANGED    13  /* The response frame contains a notification that the
                                   target device’s state has changed */
#define AVRC_RSP_INTERIM    15  /* For control commands, the target has accepted the
                                   request but cannot return information within 100
                                   milliseconds; for notify commands, the target accepted
                                   the command, and will notify the controller of a change
                                   of target state at a future time */

/* subunit type */
#define AVRC_SUB_MONITOR    0x00    /* Monitor */
#define AVRC_SUB_AUDIO      0x01    /* Audio */
#define AVRC_SUB_PRINTER    0x02    /* Printer */
#define AVRC_SUB_DISC       0x03    /* Disc */
#define AVRC_SUB_TAPE       0x04    /* Tape recorder/player */
#define AVRC_SUB_TUNER      0x05    /* Tuner */
#define AVRC_SUB_CA         0x06    /* CA */
#define AVRC_SUB_CAMERA     0x07    /* Camera */
#define AVRC_SUB_PANEL      0x09    /* Panel */
#define AVRC_SUB_BB         0x0A    /* Bulletin Board */
#define AVRC_SUB_CAM_STOR   0x0B    /* Camera Storage */
#define AVRC_SUB_VENDOR     0x1C    /* Vendor unique */
#define AVRC_SUB_EXT        0x1E    /* Subunit type extended to next byte */
#define AVRC_SUB_UNIT       0x1F    /* Unit */

/* opcodes */
#define AVRC_OP_UNIT_INFO   0x30    /* Report unit information */
#define AVRC_OP_SUB_INFO    0x31    /* Report subunit information */
#define AVRC_OP_VENDOR      0x00    /* Vendor-dependent commands */
#define AVRC_OP_PASS_THRU   0x7C    /* panel subunit opcode */

/* company id's */
#define AVRC_CO_BROADCOM    0x00001018

/* state flag for pass through command */
#define AVRC_STATE_PRESS    0
#define AVRC_STATE_RELEASE  1

/* operation id list for pass through command */
#define AVRC_ID_SELECT      0x00    /* select */
#define AVRC_ID_UP          0x01    /* up */
#define AVRC_ID_DOWN        0x02    /* down */
#define AVRC_ID_LEFT        0x03    /* left */
#define AVRC_ID_RIGHT       0x04    /* right */
#define AVRC_ID_RIGHT_UP    0x05    /* right-up */
#define AVRC_ID_RIGHT_DOWN  0x06    /* right-down */
#define AVRC_ID_LEFT_UP     0x07    /* left-up */
#define AVRC_ID_LEFT_DOWN   0x08    /* left-down */
#define AVRC_ID_ROOT_MENU   0x09    /* root menu */
#define AVRC_ID_SETUP_MENU  0x0A    /* setup menu */
#define AVRC_ID_CONT_MENU   0x0B    /* contents menu */
#define AVRC_ID_FAV_MENU    0x0C    /* favorite menu */
#define AVRC_ID_EXIT        0x0D    /* exit */
#define AVRC_ID_0           0x20    /* 0 */
#define AVRC_ID_1           0x21    /* 1 */
#define AVRC_ID_2           0x22    /* 2 */
#define AVRC_ID_3           0x23    /* 3 */
#define AVRC_ID_4           0x24    /* 4 */
#define AVRC_ID_5           0x25    /* 5 */
#define AVRC_ID_6           0x26    /* 6 */
#define AVRC_ID_7           0x27    /* 7 */
#define AVRC_ID_8           0x28    /* 8 */
#define AVRC_ID_9           0x29    /* 9 */
#define AVRC_ID_DOT         0x2A    /* dot */
#define AVRC_ID_ENTER       0x2B    /* enter */
#define AVRC_ID_CLEAR       0x2C    /* clear */
#define AVRC_ID_CHAN_UP     0x30    /* channel up */
#define AVRC_ID_CHAN_DOWN   0x31    /* channel down */
#define AVRC_ID_PREV_CHAN   0x32    /* previous channel */
#define AVRC_ID_SOUND_SEL   0x33    /* sound select */
#define AVRC_ID_INPUT_SEL   0x34    /* input select */
#define AVRC_ID_DISP_INFO   0x35    /* display information */
#define AVRC_ID_HELP        0x36    /* help */
#define AVRC_ID_PAGE_UP     0x37    /* page up */
#define AVRC_ID_PAGE_DOWN   0x38    /* page down */
#define AVRC_ID_POWER       0x40    /* power */
#define AVRC_ID_VOL_UP      0x41    /* volume up */
#define AVRC_ID_VOL_DOWN    0x42    /* volume down */
#define AVRC_ID_MUTE        0x43    /* mute */
#define AVRC_ID_PLAY        0x44    /* play */
#define AVRC_ID_STOP        0x45    /* stop */
#define AVRC_ID_PAUSE       0x46    /* pause */
#define AVRC_ID_RECORD      0x47    /* record */
#define AVRC_ID_REWIND      0x48    /* rewind */
#define AVRC_ID_FAST_FOR    0x49    /* fast forward */
#define AVRC_ID_EJECT       0x4A    /* eject */
#define AVRC_ID_FORWARD     0x4B    /* forward */
#define AVRC_ID_BACKWARD    0x4C    /* backward */
#define AVRC_ID_ANGLE       0x50    /* angle */
#define AVRC_ID_SUBPICT     0x51    /* subpicture */
#define AVRC_ID_F1          0x71    /* F1 */
#define AVRC_ID_F2          0x72    /* F2 */
#define AVRC_ID_F3          0x73    /* F3 */
#define AVRC_ID_F4          0x74    /* F4 */
#define AVRC_ID_F5          0x75    /* F5 */
#define AVRC_ID_VENDOR      0x7E    /* vendor unique */

/* AVRC CTRL events */
/* AVRC_OPEN_IND_EVT event is sent when the connection is successfully opened.
 * This eventis sent in response to an AVRC_Open(). */
#define AVRC_OPEN_IND_EVT       0

/* AVRC_CLOSE_IND_EVT event is sent when a connection is closed.
 * This event can result from a call to AVRC_Close() or when the peer closes
 * the connection.  It is also sent when a connection attempted through
 * AVRC_Open() fails. */
#define AVRC_CLOSE_IND_EVT      1   

/* AVRC_CONG_IND_EVT event indicates that AVCTP is congested and cannot send
 * any more messages. */
#define AVRC_CONG_IND_EVT       2

/* AVRC_UNCONG_IND_EVT event indicates that AVCTP is uncongested and ready to
 * send messages. */
#define AVRC_UNCONG_IND_EVT     3 

/* Supported categories */
#define AVRC_SUPF_CT_CAT1          0x0001      /* Category 1 */
#define AVRC_SUPF_CT_CAT2          0x0002      /* Category 2 */
#define AVRC_SUPF_CT_CAT3          0x0004      /* Category 3 */
#define AVRC_SUPF_CT_CAT4          0x0008      /* Category 4 */
#define AVRC_CATEGORY_PLAYER_RECORDER   AVRC_SUPF_CT_CAT1
#define AVRC_CATEGORY_MONITOR_AMPLIFIER AVRC_SUPF_CT_CAT2
#define AVRC_CATEGORY_TUNER             AVRC_SUPF_CT_CAT3
#define AVRC_CATEGORY_MENU              AVRC_SUPF_CT_CAT4


#define AVRC_SUPF_TG_CAT1          0x0001      /* Category 1 */
#define AVRC_SUPF_TG_CAT2          0x0002      /* Category 2 */
#define AVRC_SUPF_TG_CAT3          0x0004      /* Category 3 */
#define AVRC_SUPF_TG_CAT4          0x0008      /* Category 4 */

/*****************************************************************************
**  data type definitions
*****************************************************************************/

/* This data type is used in AVRC_FindService() to initialize the SDP database
 * to hold the result service search. */
typedef struct
{
    UINT32              db_len;  /* Length, in bytes, of the discovery database */
    tSDP_DISCOVERY_DB  *p_db;    /* Pointer to the discovery database */
    UINT16              num_attr;/* The number of attributes in p_attrs */
    UINT16             *p_attrs; /* The attributes filter. If NULL, AVRCP API sets the attribute filter
                                  * to be ATTR_ID_SERVICE_CLASS_ID_LIST, ATTR_ID_BT_PROFILE_DESC_LIST,
                                  * ATTR_ID_SUPPORTED_FEATURES, ATTR_ID_SERVICE_NAME and ATTR_ID_PROVIDER_NAME.
                                  * If not NULL, the input is taken as the filter. */
} tAVRC_SDP_DB_PARAMS;



/*
This structure contains the header parameters of an AV/C message.
*/
typedef struct {
    UINT8   ctype;          /* Command type.  */
    UINT8   subunit_type;   /* Subunit type. */
    UINT8   subunit_id;     /* Subunit ID.  This value is typically ignored in AVRCP,
                             * except for VENDOR DEPENDENT messages when the value is
                             * vendor-dependent.  Value range is 0-7. */
} tAVRC_HDR;

/* This structure contains a UNIT INFO message. */
typedef struct {
    tAVRC_HDR   hdr;        /* Message header. */
    UINT32      company_id; /* Company identifier. */
    UINT8       unit_type;  /* Unit type.  Uses the same values as subunit type. */
    UINT8       unit;       /* This value is vendor dependent and typically zero.  */
} tAVRC_MSG_UNIT;

/* This structure contains a SUBUNIT INFO message. */
typedef struct {
    tAVRC_HDR   hdr;        /* Message header. */
    UINT8       subunit_type[AVRC_SUB_TYPE_LEN];
                            /* Array containing subunit type values.  */
    BOOLEAN     panel;      /* TRUE if the panel subunit type is in the 
                             * subunit_type array, FALSE otherwise. */
    UINT8       page;       /* Specifies which part of the subunit type table is
                             * returned.  For AVRCP it is typically zero.
                             * Value range is 0-7. */
} tAVRC_MSG_SUB;

/* This structure contains a VENDOR DEPENDENT message. */
typedef struct {
    tAVRC_HDR   hdr;        /* Message header. */
    UINT32      company_id; /* Company identifier. */
    UINT8      *p_data;     /* Pointer to vendor dependent data. */
    UINT8       len;        /* Length in bytes of vendor dependent data. */
} tAVRC_MSG_VENDOR;

/* PASS THROUGH message structure */
typedef struct {
    tAVRC_HDR   hdr;        /* hdr.ctype Unused.
                             * hdr.subunit_type Unused.
                             * hdr.subunit_id Unused. */
    UINT8       op_id;      /* Operation ID.  */
    UINT8       state;      /* Keypress state.  */
    UINT8      *p_data;     /* Pointer to data.  This parameter is only valid
                             * when the op_id is AVRC_ID_VENDOR.*/
    UINT8       len;        /* Length in bytes of data. This parameter is only
                             * valid when the op_id is AVRC_ID_VENDOR.*/
} tAVRC_MSG_PASS;

/* This is a union of all message type structures. */
typedef union {
    tAVRC_HDR           hdr;    /* Message header. */
    tAVRC_MSG_UNIT      unit;   /* UNIT INFO message. */
    tAVRC_MSG_SUB       sub;    /* SUBUNIT INFO message. */
    tAVRC_MSG_VENDOR    vendor; /* VENDOR DEPENDENT message. */
    tAVRC_MSG_PASS      pass;   /* PASS THROUGH message. */
} tAVRC_MSG;

/* This callback function returns service discovery information to the
 * application after the AVRC_FindService() API function is called.  The
 * implementation of this callback function must copy the p_service_name
 * and p_provider_name parameters passed to it as they are not guaranteed
 * to remain after the callback function exits. */
typedef void (tAVRC_FIND_CBACK) (BOOLEAN found, char* p_service_name,
             UINT16 service_name_len, char* p_provider_name,
             UINT16 provider_name_len, UINT16 categories);

 
/* This is the control callback function.  This function passes events
 * listed in Table 20 to the application. */
typedef void (tAVRC_CTRL_CBACK) (UINT8 handle, UINT8 event, UINT16 result,
             BD_ADDR peer_addr);


/* This is the message callback function.  It is executed when AVCTP has
 * a message packet ready for the application.  The implementation of this
 * callback function must copy the tAVRC_MSG structure passed to it as it
 * is not guaranteed to remain after the callback function exits. */
typedef void (tAVRC_MSG_CBACK) (UINT8 handle, UINT8 label, UINT8 opcode,
             tAVRC_MSG *p_msg);

typedef struct
{
    tAVRC_CTRL_CBACK    *p_ctrl_cback;  /* pointer to application control callback */
    tAVRC_MSG_CBACK     *p_msg_cback;   /* pointer to application message callback */
    UINT32              company_id;     /* the company ID  */
    UINT8               conn;           /* Connection role (Initiator/acceptor) */
    UINT8               control;        /* Control role (Control/Target) */
} tAVRC_CONN_CB;

/*****************************************************************************
**  external function declarations
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
**
** Function         AVRC_AddRecord
**
** Description      This function is called to build an AVRCP SDP record.
**                  Prior to calling this function the application must 
**                  call SDP_CreateRecord() to create an SDP record.
**
**                  Input Parameters:
**                      service_uuid:  Indicates TG(UUID_SERVCLASS_AV_REM_CTRL_TARGET)
**                                            or CT(UUID_SERVCLASS_AV_REMOTE_CONTROL)
**
**                      p_service_name:  Pointer to a null-terminated character
**                      string containing the service name.
**                      If service name is not used set this to NULL.
**
**                      p_provider_name:  Pointer to a null-terminated character
**                      string containing the provider name.
**                      If provider name is not used set this to NULL.
**
**                      categories:  Supported categories.
**
**                      sdp_handle:  SDP handle returned by SDP_CreateRecord().
**
**                  Output Parameters:
**                      None.
**
** Returns          AVRC_SUCCESS if successful.
**                  AVRC_NO_RESOURCES if not enough resources to build the SDP record.
**
******************************************************************************/
AVRC_API extern UINT16 AVRC_AddRecord(UINT16 service_uuid, char *p_service_name,
                char *p_provider_name, UINT16 categories, UINT32 sdp_handle);

/******************************************************************************
**
** Function         AVRC_FindService
**
** Description      This function is called by the application to perform service
**                  discovery and retrieve AVRCP SDP record information from a
**                  peer device.  Information is returned for the first service
**                  record found on the server that matches the service UUID.  
**                  The callback function will be executed when service discovery
**                  is complete.  There can only be one outstanding call to
**                  AVRC_FindService() at a time; the application must wait for
**                  the callback before it makes another call to the function.
**                  The application is responsible for allocating memory for the
**                  discovery database.  It is recommended that the size of the
**                  discovery database be at least 300 bytes.  The application
**                  can deallocate the memory after the callback function has
**                  executed.
**
**                  Input Parameters:
**                      service_uuid: Indicates TG(UUID_SERVCLASS_AV_REM_CTRL_TARGET)
**                                           or CT(UUID_SERVCLASS_AV_REMOTE_CONTROL)
**
**                      bd_addr:  BD address of the peer device.
**
**                      p_db:  SDP discovery database parameters.
**                      
**                      p_cback:  Pointer to the callback function.
**
**                  Output Parameters:
**                      None.
**
** Returns          AVRC_SUCCESS if successful.
**                  AVRC_BAD_PARAMS if discovery database parameters are invalid.
**                  AVRC_NO_RESOURCES if there are not enough resources to
**                                    perform the service search.
**
******************************************************************************/
AVRC_API extern UINT16 AVRC_FindService(UINT16 service_uuid, BD_ADDR bd_addr,
                tAVRC_SDP_DB_PARAMS *p_db, tAVRC_FIND_CBACK *p_cback);

/******************************************************************************
**
** Function         AVRC_Open
**
** Description      This function is called to open a connection to AVCTP. 
**                  The connection can be either an initiator or acceptor, as
**                  determined by the p_ccb->stream parameter. 
**                  The connection can be a target, a controller or for both role,
**                  as determined by the p_ccb->control parameter. 
**                  By definition, a target connection is an acceptor connection
**                  that waits for an incoming AVCTP connection from the peer. 
**                  The connection remains available to the application until
**                  the application closes it by calling AVRC_Close().  The
**                  application does not need to reopen the connection after an
**                  AVRC_CLOSE_IND_EVT is received.
**
**                  Input Parameters:
**                      p_ccb->company_id: Company Identifier.
**
**                      p_ccb->p_ctrl_cback:  Pointer to control callback function.
**
**                      p_ccb->p_msg_cback:  Pointer to message callback function.
**                      
**                      p_ccb->conn: AVCTP connection role.  This is set to
**                      AVCTP_INT for initiator connections and AVCTP_ACP
**                      for acceptor connections.
**
**                      p_ccb->control: Control role.  This is set to
**                      AVRC_CT_TARGET for target connections, AVRC_CT_CONTROL
**                      for control connections or (AVRC_CT_TARGET|AVRC_CT_CONTROL)
**                      for connections that support both roles.
**
**                      peer_addr: BD address of peer device.  This value is
**                      only used for initiator connections; for acceptor
**                      connections it can be set to NULL.
**
**                  Output Parameters:
**                      p_handle: Pointer to handle.  This parameter is only 
**                                valid if AVRC_SUCCESS is returned.
**
** Returns          AVRC_SUCCESS if successful.
**                  AVRC_NO_RESOURCES if there are not enough resources to open
**                  the connection.
**
******************************************************************************/
AVRC_API extern UINT16 AVRC_Open(UINT8 *p_handle, tAVRC_CONN_CB *p_ccb,
                                 BD_ADDR_PTR peer_addr);

/******************************************************************************
**
** Function         AVRC_Close
**
** Description      Close a connection opened with AVRC_Open().
**                  This function is called when the
**                  application is no longer using a connection.
**
**                  Input Parameters:
**                      handle: Handle of this connection.
**
**                  Output Parameters:
**                      None.
**
** Returns          AVRC_SUCCESS if successful.
**                  AVRC_BAD_HANDLE if handle is invalid.
**
******************************************************************************/
AVRC_API extern UINT16 AVRC_Close(UINT8 handle);

/******************************************************************************
**
** Function         AVRC_UnitCmd
**
** Description      Send a UNIT INFO command to the peer device.  This
**                  function can only be called for controller role connections.
**                  Any response message from the peer is passed back through
**                  the tAVRC_MSG_CBACK callback function.
**
**                  Input Parameters:
**                      handle: Handle of this connection.
**
**                      label: Transaction label.
**
**                  Output Parameters:
**                      None.
**
** Returns          AVRC_SUCCESS if successful.
**                  AVRC_BAD_HANDLE if handle is invalid.
**
******************************************************************************/
AVRC_API extern UINT16 AVRC_UnitCmd(UINT8 handle, UINT8 label);

/******************************************************************************
**
** Function         AVRC_SubCmd
**
** Description      Send a SUBUNIT INFO command to the peer device.  This
**                  function can only be called for controller role connections.
**                  Any response message from the peer is passed back through
**                  the tAVRC_MSG_CBACK callback function.
**
**                  Input Parameters:
**                      handle: Handle of this connection.
**
**                      label: Transaction label.
**
**                      page: Specifies which part of the subunit type table
**                      is requested.  For AVRCP it is typically zero.
**                      Value range is 0-7.
**
**                  Output Parameters:
**                      None.
**
** Returns          AVRC_SUCCESS if successful.
**                  AVRC_BAD_HANDLE if handle is invalid.
**
******************************************************************************/
AVRC_API extern UINT16 AVRC_SubCmd(UINT8 handle, UINT8 label, UINT8 page);


/******************************************************************************
**
** Function         AVRC_PassCmd
**
** Description      Send a PASS THROUGH command to the peer device.  This
**                  function can only be called for controller role connections.
**                  Any response message from the peer is passed back through
**                  the tAVRC_MSG_CBACK callback function.
**
**                  Input Parameters:
**                      handle: Handle of this connection.
**
**                      label: Transaction label.
**
**                      p_msg: Pointer to PASS THROUGH message structure. 
**
**                  Output Parameters:
**                      None.
**
** Returns          AVRC_SUCCESS if successful.
**                  AVRC_BAD_HANDLE if handle is invalid.
**
******************************************************************************/
AVRC_API extern UINT16 AVRC_PassCmd(UINT8 handle, UINT8 label, tAVRC_MSG_PASS *p_msg);

/******************************************************************************
**
** Function         AVRC_PassRsp
**
** Description      Send a PASS THROUGH response to the peer device.  This
**                  function can only be called for target role connections. 
**                  This function must be called when a PASS THROUGH command
**                  message is received from the peer through the
**                  tAVRC_MSG_CBACK callback function.
**
**                  Input Parameters:
**                      handle: Handle of this connection.
**
**                      label: Transaction label.  Must be the same value as
**                      passed with the command message in the callback function.
**
**                      p_msg: Pointer to PASS THROUGH message structure.
**
**                  Output Parameters:
**                      None.
**
** Returns          AVRC_SUCCESS if successful.
**                  AVRC_BAD_HANDLE if handle is invalid.
**
******************************************************************************/
AVRC_API extern UINT16 AVRC_PassRsp(UINT8 handle, UINT8 label, tAVRC_MSG_PASS *p_msg);


/******************************************************************************
**
** Function         AVRC_VendorCmd
**
** Description      Send a VENDOR DEPENDENT command to the peer device.  This
**                  function can only be called for controller role connections.
**                  Any response message from the peer is passed back through
**                  the tAVRC_MSG_CBACK callback function.
**
**                  Input Parameters:
**                      handle: Handle of this connection.
**
**                      label: Transaction label.
**
**                      p_msg: Pointer to VENDOR DEPENDENT message structure.
**
**                  Output Parameters:
**                      None.
**
** Returns          AVRC_SUCCESS if successful.
**                  AVRC_BAD_HANDLE if handle is invalid.
**
******************************************************************************/
AVRC_API extern UINT16 AVRC_VendorCmd(UINT8  handle, UINT8  label, tAVRC_MSG_VENDOR *p_msg);


/******************************************************************************
**
** Function         AVRC_VendorRsp
**
** Description      Send a VENDOR DEPENDENT response to the peer device.  This
**                  function can only be called for target role connections.
**                  This function must be called when a VENDOR DEPENDENT
**                  command message is received from the peer through the
**                  tAVRC_MSG_CBACK callback function.
**
**                  Input Parameters:
**                      handle: Handle of this connection.
**
**                      label: Transaction label.  Must be the same value as
**                      passed with the command message in the callback function.
**
**                      p_msg: Pointer to VENDOR DEPENDENT message structure.
**
**                  Output Parameters:
**                      None.
**
** Returns          AVRC_SUCCESS if successful.
**                  AVRC_BAD_HANDLE if handle is invalid.
**
******************************************************************************/
AVRC_API extern UINT16 AVRC_VendorRsp(UINT8  handle, UINT8  label, tAVRC_MSG_VENDOR *p_msg);


/******************************************************************************
**
** Function         AVRC_SetTraceLevel
**
** Description      Sets the trace level for AVRC. If 0xff is passed, the
**                  current trace level is returned.
**
**                  Input Parameters:
**                      new_level:  The level to set the AVRC tracing to:
**                      0xff-returns the current setting.
**                      0-turns off tracing.
**                      >= 1-Errors.
**                      >= 2-Warnings.
**                      >= 3-APIs.
**                      >= 4-Events.
**                      >= 5-Debug.
**
** Returns          The new trace level or current trace level if
**                  the input parameter is 0xff.
**
******************************************************************************/
AVRC_API extern UINT8 AVRC_SetTraceLevel (UINT8 new_level);

/*******************************************************************************
**
** Function         AVRC_Init
**
** Description      This function is called at stack startup to allocate the
**                  control block (if using dynamic memory), and initializes the
**                  control block and tracing level.
**
** Returns          void
**
*******************************************************************************/
AVRC_API extern void AVRC_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* AVRC_API_H */
