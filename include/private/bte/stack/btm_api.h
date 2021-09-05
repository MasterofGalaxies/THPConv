/*****************************************************************************
**
**  Name:          btm_api.h
**
**  Description:   This file contains the Bluetooth Manager (BTM) API function
**                 external definitions.
**
**                 The BTM consists of several management entities:
**                      1. Device Control - controls the local device
**                      2. Device Discovery - manages inquiries, discover database
**                      3. ACL Channels - manages ACL connections
**                      4. SCO Channels - manages SCO connections
**                      5. Security - manages all security functionality
**                      6. Power Management - manages park, sniff, hold, etc. (optional)
**
**  Copyright (c) 1999-2005, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
******************************************************************************/
#ifndef BTM_API_H
#define BTM_API_H

#include <private/bte/common/target.h>
#include <private/bte/stack/sdp_api.h>
#include <private/bte/stack/hcidefs.h>

/*****************************************************************************
**  DEVICE CONTROL and COMMON
*****************************************************************************/
/*****************************
**  Device Control Constants
******************************/
/* Maximum number of bytes allowed for vendor specific command parameters */
#define BTM_MAX_VENDOR_SPECIFIC_LEN  HCI_COMMAND_SIZE

/* BTM application return status codes */
enum
{
    BTM_SUCCESS = 0,                    /* Command succeeded                 */
    BTM_CMD_STARTED,                    /* Command started OK.               */
    BTM_BUSY,                           /* Device busy with another command  */
    BTM_NO_RESOURCES,                   /* No resources to issue command     */
    BTM_MODE_UNSUPPORTED,               /* Request for 1 or more unsupported modes */
    BTM_ILLEGAL_VALUE,                  /* Illegal parameter value           */
    BTM_WRONG_MODE,                     /* Device in wrong mode for request  */
    BTM_UNKNOWN_ADDR,                   /* Unknown remote BD address         */
    BTM_DEVICE_TIMEOUT,                 /* Device timeout                    */
    BTM_BAD_VALUE_RET,                  /* A bad value was received from HCI */
    BTM_ERR_PROCESSING,                 /* HCI returned error                */
    BTM_NOT_AUTHORIZED,                 /* Authorization failed              */
    BTM_DEV_RESET,                      /* Device has been reset             */
    BTM_CMD_STORED,                     /* request is stored in control block */
    BTM_ILLEGAL_ACTION                  /* state machine gets illegal command */
};
typedef UINT8 tBTM_STATUS;

/*************************
**  Device Control Types
**************************/
/* Device name of peer (may be truncated to save space in BTM database) */
typedef UINT8 tBTM_BD_NAME[BTM_MAX_REM_BD_NAME_LEN + 1];

/* Structure returned with local version information */
typedef struct
{
    UINT8       hci_version;
    UINT16      hci_revision;
    UINT8       lmp_version;
    UINT16      manufacturer;
    UINT16      lmp_subversion;
} tBTM_VERSION_INFO;

/* Structure returned with Vendor Specific Command complete callback */
typedef struct
{
    UINT16  opcode;
    UINT16  param_len;
    UINT8   param_buf[BTM_MAX_VENDOR_SPECIFIC_LEN];
} tBTM_VSC_CMPL;

/**************************************************
**  Device Control and General Callback Functions
***************************************************/
/* Callback function for when device status changes. Appl must poll for
** what the new state is (BTM_IsDeviceUp). The event occurs whenever the stack
** has detected that the controller status has changed. This asynchronous event
** is enabled/disabled by calling BTM_RegisterForDeviceStatusNotif().
*/
enum
{
    BTM_DEV_STATUS_UP,
    BTM_DEV_STATUS_DOWN,
    BTM_DEV_STATUS_CMD_TOUT
};

typedef UINT8 tBTM_DEV_STATUS;


typedef void (tBTM_DEV_STATUS_CB) (tBTM_DEV_STATUS status);


/* Callback function for when a vendor specific event occurs. The length and 
** array of returned parameter bytes are included. This asynchronous event
** is enabled/disabled by calling BTM_RegisterForVSEvents().
*/
typedef void (tBTM_VS_EVT_CB) (UINT8 len, UINT8 *p);


/* General callback function for notifying an application that a synchronous
** BTM function is complete. The pointer contains the address of any returned data.
*/
typedef void (tBTM_CMPL_CB) (void *p1);

/* Callback for apps to check connection and inquiry filters.
** Parameters are the BD Address of remote and the Dev Class of remote.
** If the app returns none zero, the connection or inquiry result will be dropped.
*/
typedef UINT8 (tBTM_FILTER_CB) (BD_ADDR bd_addr, DEV_CLASS dc);


/*****************************************************************************
**  DEVICE DISCOVERY - Inquiry, Remote Name, Discovery, Class of Device
*****************************************************************************/
/*******************************
**  Device Discovery Constants
********************************/
/* Discoverable modes */
#define BTM_NON_DISCOVERABLE        0
#define BTM_LIMITED_DISCOVERABLE    1
#define BTM_GENERAL_DISCOVERABLE    2

/* Connectable modes */
#define BTM_NON_CONNECTABLE         0
#define BTM_CONNECTABLE             1

/* Inquiry modes */
#define BTM_GENERAL_INQUIRY         0
#define BTM_LIMITED_INQUIRY         1

/* Define scan types */
#define BTM_SCAN_TYPE_STANDARD      0
#define BTM_SCAN_TYPE_INTERLACED    1       /* 1.2 devices only */

/* Define inquiry results mode */
#define BTM_INQ_RESULT_STANDARD     0
#define BTM_INQ_RESULT_WITH_RSSI    1

#define BTM_INQ_RES_IGNORE_RSSI     0x7f    /* RSSI value not supplied (ignore it) */

/* BTM_IsInquiryActive return values (Bit Mask) */
#define BTM_INQUIRY_INACTIVE        0x0     /* no inquiry in progress */
#define BTM_LIMITED_INQUIRY_ACTIVE  0x1     /* a limited inquiry is in progress */
#define BTM_GENERAL_INQUIRY_ACTIVE  0x2     /* a general inquiry is in progress */
#define BTM_PERIODIC_INQUIRY_ACTIVE 0x4     /* a periodic inquiry is active */

/* Inquiry Filter Condition types (see tBTM_INQ_PARMS) */
#define BTM_CLR_INQUIRY_FILTER          0                   /* Inquiry Filtering is turned off */
#define BTM_FILTER_COND_DEVICE_CLASS    HCI_FILTER_COND_DEVICE_CLASS /* Filter on device class */
#define BTM_FILTER_COND_BD_ADDR         HCI_FILTER_COND_BD_ADDR /* Filter on device addr */

/* State of the remote name retrieval during inquiry operations.
** Used in the tBTM_INQ_INFO structure, and returned in the
** BTM_InqDbRead, BTM_InqDbFirst, and BTM_InqDbNext functions.
** The name field is valid when the state returned is
** BTM_INQ_RMT_NAME_DONE */
#define BTM_INQ_RMT_NAME_EMPTY      0
#define BTM_INQ_RMT_NAME_PENDING    1
#define BTM_INQ_RMT_NAME_DONE       2
#define BTM_INQ_RMT_NAME_FAILED     3

/*********************************
 *** Class of Device constants ***
 *********************************/
#define BTM_FORMAT_TYPE_1   0x00

/****************************
** minor device class field
*****************************/

/* 0x00 is used as unclassified for all minor device classes */
#define COD_MINOR_UNCLASSIFIED          0x00

/* minor device class field for Computer Major Class */
/* #define COD_MINOR_UNCLASSIFIED       0x00    */
#define COD_MINOR_DESKTOP_WORKSTATION   0x04
#define COD_MINOR_SERVER_COMPUTER       0x08
#define COD_MINOR_LAPTOP                0x0C
#define COD_MINOR_HANDHELD_PC_PDA       0x10    /* clam shell */
#define COD_MINOR_PALM_SIZE_PC_PDA      0x14
#define COD_MINOR_WEARABLE_COMPUTER     0x18    /* watch sized */

/* minor device class field for Phone Major Class */
/* #define COD_MINOR_UNCLASSIFIED       0x00    */
#define COD_MINOR_CELLULAR              0x04
#define COD_MINOR_CORDLESS              0x08
#define COD_MINOR_SMART_PHONE           0x0C
#define COD_MINOR_WIRED_MDM_V_GTWY      0x10 /* wired modem or voice gatway */
#define COD_MINOR_ISDN_ACCESS           0x14

/* minor device class field for LAN Access Point Major Class */
/* Load Factor Field bit 5-7 */
#define COD_MINOR_FULLY_AVAILABLE       0x00
#define COD_MINOR_1_17_UTILIZED         0x20
#define COD_MINOR_17_33_UTILIZED        0x40
#define COD_MINOR_33_50_UTILIZED        0x60
#define COD_MINOR_50_67_UTILIZED        0x80
#define COD_MINOR_67_83_UTILIZED        0xA0
#define COD_MINOR_83_99_UTILIZED        0xC0
#define COD_MINOR_NO_SERVICE_AVAILABLE  0xE0
/* sub-Field bit 2-4 */
/* #define COD_MINOR_UNCLASSIFIED       0x00    */

/* minor device class field for Audio/Video Major Class */
/* #define COD_MINOR_UNCLASSIFIED       0x00    */
#define COD_MINOR_CONFM_HEADSET         0x04
#define COD_MINOR_CONFM_HANDSFREE       0x08
#define COD_MINOR_MICROPHONE            0x10
#define COD_MINOR_LOUDSPEAKER           0x14
#define COD_MINOR_HEADPHONES            0x18
#define COD_MINOR_PORTABLE_AUDIO        0x1C
#define COD_MINOR_CAR_AUDIO             0x20
#define COD_MINOR_SET_TOP_BOX           0x24
#define COD_MINOR_HIFI_AUDIO            0x28
#define COD_MINOR_VCR                   0x2C
#define COD_MINOR_VIDEO_CAMERA          0x30
#define COD_MINOR_CAMCORDER             0x34
#define COD_MINOR_VIDEO_MONITOR         0x38
#define COD_MINOR_VIDDISP_LDSPKR        0x3C
#define COD_MINOR_VIDEO_CONFERENCING    0x40
#define COD_MINOR_GAMING_TOY            0x48

/* minor device class field for Peripheral Major Class */
/* Bits 6-7 independently specify mouse, keyboard, or combo mouse/keyboard */
#define COD_MINOR_KEYBOARD              0x40
#define COD_MINOR_POINTING              0x80
#define COD_MINOR_COMBO                 0xC0
/* Bits 2-5 OR'd with selection from bits 6-7 */
/* #define COD_MINOR_UNCLASSIFIED       0x00    */
#define COD_MINOR_JOYSTICK              0x04
#define COD_MINOR_GAMEPAD               0x08
#define COD_MINOR_REMOTE_CONTROL        0x0C
#define COD_MINOR_SENSING_DEVICE        0x10
#define COD_MINOR_DIGITIZING_TABLET     0x14
#define COD_MINOR_CARD_READER           0x18    /* e.g. SIM card reader */

/* minor device class field for Imaging Major Class */
/* Bits 5-7 independently specify display, camera, scanner, or printer */
#define COD_MINOR_DISPLAY               0x10
#define COD_MINOR_CAMERA                0x20
#define COD_MINOR_SCANNER               0x40
#define COD_MINOR_PRINTER               0x80
/* Bits 2-3 Reserved */
/* #define COD_MINOR_UNCLASSIFIED       0x00    */

/***************************
** major device class field
****************************/
#define COD_MAJOR_MISCELLANEOUS         0x00
#define COD_MAJOR_COMPUTER              0x01
#define COD_MAJOR_PHONE                 0x02
#define COD_MAJOR_LAN_ACCESS_PT         0x03
#define COD_MAJOR_AUDIO                 0x04
#define COD_MAJOR_PERIPHERAL            0x05
#define COD_MAJOR_IMAGING               0x06
#define COD_MAJOR_UNCLASSIFIED          0x1F

/***************************
** service class fields
****************************/
#define COD_SERVICE_LMTD_DISCOVER       0x0020
#define COD_SERVICE_POSITIONING         0x0100
#define COD_SERVICE_NETWORKING          0x0200
#define COD_SERVICE_RENDERING           0x0400
#define COD_SERVICE_CAPTURING           0x0800
#define COD_SERVICE_OBJ_TRANSFER        0x1000
#define COD_SERVICE_AUDIO               0x2000
#define COD_SERVICE_TELEPHONY           0x4000
#define COD_SERVICE_INFORMATION         0x8000

/* class of device field macros */
#define COD_FORMAT_TYPE(u8, pd)         {u8  = pd[2]&0x03;}
#define COD_MINOR_CLASS(u8, pd)         {u8  = pd[2]&0xFC;}
#define COD_MAJOR_CLASS(u8, pd)         {u8  = pd[1]&0x1F;}
#define COD_SERVICE_CLASS(u16, pd)      {u16 = pd[0]; u16<<=8; u16 += pd[1]&0xE0;}

/* to set the fields (assumes that format type is always 0) */
#define FIELDS_TO_COD(pd, mn, mj, sv) {pd[2] = mn; pd[1] =              \
                                       mj+ (sv&COD_SERVICE_CLASS_LO_B); \
                                       pd[0] = sv >> 8;}

/* the COD masks */
#define COD_FORMAT_TYPE_MASK      0x03
#define COD_MINOR_CLASS_MASK      0xFC
#define COD_MAJOR_CLASS_MASK      0x1F
#define COD_SERVICE_CLASS_LO_B    0x00E0
#define COD_SERVICE_CLASS_MASK    0xFFE0

/***************************
**  Device Discovery Types
****************************/
/* Definitions of the parameters passed to BTM_StartInquiry and
** BTM_SetPeriodicInquiryMode.
*/
typedef struct              /* contains the two device class condition fields */
{
    DEV_CLASS       dev_class;
    DEV_CLASS       dev_class_mask;
} tBTM_COD_COND;


typedef union               /* contains the inquiry filter condition */
{
    BD_ADDR         bdaddr_cond;
    tBTM_COD_COND   cod_cond;
} tBTM_INQ_FILT_COND;


typedef struct              /* contains the parameters passed to the inquiry functions */
{
    UINT8   mode;                       /* general or limited */
    UINT8   duration;                   /* duration of the inquiry (1.28 sec increments) */
    UINT8   max_resps;                  /* maximum number of responses to return */
    UINT8   filter_cond_type;           /* new devices, BD ADDR, COD, or No filtering */
    tBTM_INQ_FILT_COND  filter_cond;    /* filter value based on filter cond type */
} tBTM_INQ_PARMS;


/* These are the fields returned in each device's response to the inquiry.  It
** is returned in the results callback if registered.
*/ 
typedef struct
{
    UINT16      clock_offset;
    BD_ADDR     remote_bd_addr;
    DEV_CLASS   dev_class;
    UINT8       page_scan_rep_mode;
    UINT8       page_scan_per_mode;
    UINT8       page_scan_mode;
    INT8        rssi;       /* Set to BTM_INQ_RES_IGNORE_RSSI if  not valid */
} tBTM_INQ_RESULTS;


/* This is the inquiry response information held in its database by BTM, and available
** to applications via BTM_InqDbRead, BTM_InqDbFirst, and BTM_InqDbNext.
*/
typedef struct
{
    tBTM_INQ_RESULTS    results;

    BOOLEAN             appl_knows_rem_name;    /* set by application if it knows the remote name of the peer device.
                                                   This is later used by application to determine if remote name request is 
                                                   required to be done. Having the flag here avoid duplicate store of inquiry results */


#if (BTM_INQ_GET_REMOTE_NAME == TRUE)
    UINT16          remote_name_len;
    tBTM_BD_NAME    remote_name;
    UINT8           remote_name_state;
#endif
} tBTM_INQ_INFO;


/* Structure returned with inquiry complete callback */
typedef struct
{
    tBTM_STATUS status;
    UINT8       num_resp;       /* Number of results from the current inquiry */
} tBTM_INQUIRY_CMPL;


/* Structure returned with remote name  request */
typedef struct
{
    UINT16      status;
    UINT16      length;
    BD_NAME     remote_bd_name;
} tBTM_REMOTE_DEV_NAME;

/****************************************
**  Device Discovery Callback Functions
*****************************************/
/* Callback function for asynchronous notifications when the BTM inquiry DB
** changes. First param is inquiry database, second is if added to or removed
** from the inquiry database.
*/
typedef void (tBTM_INQ_DB_CHANGE_CB) (void *p1, BOOLEAN is_new);


/*****************************************************************************
**  ACL CHANNEL MANAGEMENT
*****************************************************************************/
/******************
**  ACL Constants
*******************/

/* ACL modes */
#define BTM_ACL_MODE_NORMAL     HCI_MODE_ACTIVE
#define BTM_ACL_MODE_HOLD       HCI_MODE_HOLD
#define BTM_ACL_MODE_SNIFF      HCI_MODE_SNIFF
#define BTM_ACL_MODE_PARK       HCI_MODE_PARK

/* Returned with structure in role switch callback (tBTM_ROLE_SWITCH_CMPL) */
#define BTM_ROLE_MASTER         HCI_ROLE_MASTER
#define BTM_ROLE_SLAVE          HCI_ROLE_SLAVE
#define BTM_ROLE_UNDEFINED      0xff     /* undefined value (error status) */

/* ACL Packet Types */
#define BTM_ACL_PKT_TYPES_MASK_DM1      HCI_PKT_TYPES_MASK_DM1
#define BTM_ACL_PKT_TYPES_MASK_DH1      HCI_PKT_TYPES_MASK_DH1
#define BTM_ACL_PKT_TYPES_MASK_DM3      HCI_PKT_TYPES_MASK_DM3
#define BTM_ACL_PKT_TYPES_MASK_DH3      HCI_PKT_TYPES_MASK_DH3
#define BTM_ACL_PKT_TYPES_MASK_DM5      HCI_PKT_TYPES_MASK_DM5
#define BTM_ACL_PKT_TYPES_MASK_DH5      HCI_PKT_TYPES_MASK_DH5
#define BTM_ACL_PKT_TYPES_MASK_NO_2_DH1 HCI_PKT_TYPES_MASK_NO_2_DH1
#define BTM_ACL_PKT_TYPES_MASK_NO_3_DH1 HCI_PKT_TYPES_MASK_NO_3_DH1
#define BTM_ACL_PKT_TYPES_MASK_NO_2_DH3 HCI_PKT_TYPES_MASK_NO_2_DH3
#define BTM_ACL_PKT_TYPES_MASK_NO_3_DH3 HCI_PKT_TYPES_MASK_NO_3_DH3
#define BTM_ACL_PKT_TYPES_MASK_NO_2_DH5 HCI_PKT_TYPES_MASK_NO_2_DH5
#define BTM_ACL_PKT_TYPES_MASK_NO_3_DH5 HCI_PKT_TYPES_MASK_NO_3_DH5

/***************
**  ACL Types
****************/

/* Structure returned with link policy information (in tBTM_CMPL_CB callback function)
** in response to BTM_ReadLinkPolicy call.
*/
typedef struct
{
    tBTM_STATUS status;
    UINT8       hci_status;
    BD_ADDR     rem_bda;
    UINT16      settings;
} tBTM_LNK_POLICY_RESULTS;

/* Structure returned with Role Switch information (in tBTM_CMPL_CB callback function)
** in response to BTM_SwitchRole call.
*/
typedef struct
{
    UINT8   hci_status;     /* HCI status returned with the event */
    UINT8   role;           /* BTM_ROLE_MASTER or BTM_ROLE_SLAVE */
    BD_ADDR remote_bd_addr; /* Remote BD addr involved with the switch */
} tBTM_ROLE_SWITCH_CMPL;


/* Structure returned with QoS information (in tBTM_CMPL_CB callback function)
** in response to BTM_SetQoS call.
*/
typedef struct
{
    FLOW_SPEC flow;
    UINT16 handle;
    UINT8 status;
} tBTM_QOS_SETUP_CMPL;


/* Structure returned with read RSSI event (in tBTM_CMPL_CB callback function)
** in response to BTM_ReadRSSI call.
*/
typedef struct
{
    tBTM_STATUS status;
    UINT8       hci_status;
    INT8        rssi;
    BD_ADDR     rem_bda;
} tBTM_RSSI_RESULTS;

/* Structure returned with read link quality event (in tBTM_CMPL_CB callback function)
** in response to BTM_ReadLinkQuality call.
*/
typedef struct
{
    tBTM_STATUS status;
    UINT8       hci_status;
    UINT8       link_quality;
    BD_ADDR     rem_bda;
} tBTM_LINK_QUALITY_RESULTS;


enum
{
    BTM_BL_CONN_EVT,
    BTM_BL_DISCN_EVT,
    BTM_BL_UPDATE_EVT
};
typedef UINT8 tBTM_BL_EVENT;
typedef UINT16 tBTM_BL_EVENT_MASK;

#define BTM_BL_CONN_MASK        0x0001
#define BTM_BL_DISCN_MASK       0x0002
#define BTM_BL_UPDATE_MASK      0x0004

/* the data type associated with BTM_BL_CONN_EVT */
typedef struct
{
    tBTM_BL_EVENT   event;      /* The event reported. */
    BD_ADDR_PTR     p_bda;      /* The address of the newly connected device */
    DEV_CLASS_PTR   p_dc;       /* The device class */
    BD_NAME_PTR     p_bdn;      /* The device name */
    UINT8          *p_features; /* The remote device's supported features */
} tBTM_BL_CONN_DATA;

/* the data type associated with BTM_BL_DISCN_EVT */
typedef struct
{
    tBTM_BL_EVENT   event;  /* The event reported. */
    BD_ADDR_PTR     p_bda;  /* The address of the disconnected device */
} tBTM_BL_DISCN_DATA;

/* the data type associated with BTM_BL_UPDATE_EVT */
typedef struct
{
    tBTM_BL_EVENT   event;  /* The event reported. */
    UINT8           busy_level;/* when paging or inquiring, level is 10.
                                * Otherwise, the number of ACL links. */
} tBTM_BL_UPDATE_DATA;

typedef union
{
    tBTM_BL_EVENT           event;  /* The event reported. */
    tBTM_BL_CONN_DATA       conn;   /* The data associated with BTM_BL_CONN_EVT */
    tBTM_BL_DISCN_DATA      discn;  /* The data associated with BTM_BL_DISCN_EVT */
    tBTM_BL_UPDATE_DATA     update; /* The data associated with BTM_BL_UPDATE_EVT */
} tBTM_BL_EVENT_DATA;

/* Callback function for notifications when the BTM busy level
** changes. 
*/
typedef void (tBTM_BL_CHANGE_CB) (tBTM_BL_EVENT_DATA *p_data);

/***************************
**  ACL Callback Functions
****************************/
/* Callback function for notifications when the BTM ACL connection DB
** changes. First param is BD address, second is if added or removed.
** Registered through BTM_AclRegisterForChanges call.
*/
typedef void (tBTM_ACL_DB_CHANGE_CB) (BD_ADDR p_bda, DEV_CLASS p_dc,
                                      BD_NAME p_bdn, BD_FEATURES features,
                                      BOOLEAN is_new);

/*****************************************************************************
**  SCO CHANNEL MANAGEMENT
*****************************************************************************/
/******************
**  SCO Constants
*******************/

/* Define an invalid SCO index and an invalid HCI handle */
#define BTM_INVALID_SCO_INDEX       0xFFFF
#define BTM_INVALID_HCI_HANDLE      0xFFFF

/* Define an invalid SCO disconnect reason */
#define BTM_INVALID_SCO_DISC_REASON 0xFFFF

/* Define SCO packet types used in APIs */
#define BTM_SCO_PKT_TYPES_MASK_HV1  HCI_ESCO_PKT_TYPES_MASK_HV1
#define BTM_SCO_PKT_TYPES_MASK_HV2  HCI_ESCO_PKT_TYPES_MASK_HV2
#define BTM_SCO_PKT_TYPES_MASK_HV3  HCI_ESCO_PKT_TYPES_MASK_HV3
#define BTM_SCO_PKT_TYPES_MASK_EV3  HCI_ESCO_PKT_TYPES_MASK_EV3
#define BTM_SCO_PKT_TYPES_MASK_EV4  HCI_ESCO_PKT_TYPES_MASK_EV4
#define BTM_SCO_PKT_TYPES_MASK_EV5  HCI_ESCO_PKT_TYPES_MASK_EV5
#define BTM_SCO_PKT_TYPES_MASK_NO_2_EV3  HCI_ESCO_PKT_TYPES_MASK_NO_2_EV3
#define BTM_SCO_PKT_TYPES_MASK_NO_3_EV3  HCI_ESCO_PKT_TYPES_MASK_NO_3_EV3
#define BTM_SCO_PKT_TYPES_MASK_NO_2_EV5  HCI_ESCO_PKT_TYPES_MASK_NO_2_EV5
#define BTM_SCO_PKT_TYPES_MASK_NO_3_EV5  HCI_ESCO_PKT_TYPES_MASK_NO_3_EV5

#define BTM_SCO_LINK_ONLY_MASK  (BTM_SCO_PKT_TYPES_MASK_HV1 | \
                                 BTM_SCO_PKT_TYPES_MASK_HV2 | \
                                 BTM_SCO_PKT_TYPES_MASK_HV3)

#define BTM_ESCO_LINK_ONLY_MASK (BTM_SCO_PKT_TYPES_MASK_EV3 | \
                                 BTM_SCO_PKT_TYPES_MASK_EV4 | \
                                 BTM_SCO_PKT_TYPES_MASK_EV5)

#define BTM_SCO_LINK_ALL_PKT_MASK   (BTM_SCO_LINK_ONLY_MASK     | \
                                     BTM_ESCO_LINK_ONLY_MASK)

#define BTM_VALID_SCO_ALL_PKT_TYPE HCI_VALID_SCO_ALL_PKT_TYPE

/* Passed in BTM_CreateSco if the packet type parameter should be ignored */
#define BTM_IGNORE_SCO_PKT_TYPE     0

/***************
**  SCO Types
****************/
#define BTM_LINK_TYPE_SCO           HCI_LINK_TYPE_SCO
#define BTM_LINK_TYPE_ESCO          HCI_LINK_TYPE_ESCO
typedef UINT8 tBTM_SCO_TYPE;


/***************************
**  SCO Callback Functions
****************************/
typedef void (tBTM_SCO_CB) (UINT16 sco_inx);


/******************
**  eSCO Constants
*******************/
#define BTM_64KBITS_RATE            0x00001f40  /* 64 kbits/sec data rate */

/* Retransmission effort */
#define BTM_ESCO_RETRANS_OFF        0
#define BTM_ESCO_RETRANS_POWER      1
#define BTM_ESCO_RETRANS_QUALITY    2
#define BTM_ESCO_RETRANS_DONTCARE   0xff

/* Max Latency Don't Care */
#define BTM_ESCO_MAX_LAT_DONTCARE   0xffff

/***************
**  eSCO Types
****************/
/* tBTM_ESCO_CBACK event types */
#define BTM_ESCO_CHG_EVT        1
#define BTM_ESCO_CONN_REQ_EVT   2
typedef UINT8 tBTM_ESCO_EVT;

/* Passed into BTM_SetEScoMode() */
typedef struct
{
    UINT32 tx_bw;
    UINT32 rx_bw;
    UINT16 max_latency;
    UINT16 voice_contfmt;  /* Voice Settings or Content Format */
    UINT16 packet_types;
    UINT8  retrans_effort;
} tBTM_ESCO_PARAMS;

typedef struct
{
    UINT16 max_latency;
    UINT16 packet_types;
    UINT8  retrans_effort;
} tBTM_CHG_ESCO_PARAMS;

/* Returned by BTM_ReadEScoLinkParms() */
typedef struct
{
    UINT16  rx_pkt_len;
    UINT16  tx_pkt_len;
    BD_ADDR bd_addr;
    UINT8   link_type;  /* BTM_LINK_TYPE_SCO or BTM_LINK_TYPE_ESCO */
    UINT8   tx_interval;
    UINT8   retrans_window;
    UINT8   air_mode;
} tBTM_ESCO_DATA;

typedef struct
{
    UINT16  sco_inx;
    UINT16  rx_pkt_len;
    UINT16  tx_pkt_len;
    BD_ADDR bd_addr;
    UINT8   hci_status;
    UINT8   tx_interval;
    UINT8   retrans_window;
} tBTM_CHG_ESCO_EVT_DATA;

typedef struct
{
    UINT16        sco_inx;
    BD_ADDR       bd_addr;
    DEV_CLASS     dev_class;
    tBTM_SCO_TYPE link_type;
} tBTM_ESCO_CONN_REQ_EVT_DATA;

typedef union
{
    tBTM_CHG_ESCO_EVT_DATA      chg_evt;
    tBTM_ESCO_CONN_REQ_EVT_DATA conn_evt;
} tBTM_ESCO_EVT_DATA;

/***************************
**  eSCO Callback Functions
****************************/
typedef void (tBTM_ESCO_CBACK) (tBTM_ESCO_EVT event, tBTM_ESCO_EVT_DATA *p_data);


/*****************************************************************************
**  SECURITY MANAGEMENT
*****************************************************************************/
/*******************************
**  Security Manager Constants
********************************/

/* Security Mode (BTM_SetSecurityMode) */
#define BTM_SEC_MODE_UNDEFINED      0
#define BTM_SEC_MODE_NONE           1
#define BTM_SEC_MODE_SERVICE        2
#define BTM_SEC_MODE_LINK           3

/* Security Service Levels [bit mask] (BTM_SetSecurityLevel)
** Encryption should not be used without authentication
*/
#define BTM_SEC_NONE                0x00 /* Nothing required */
#define BTM_SEC_IN_AUTHORIZE        0x01 /* Inbound call requires authorization */
#define BTM_SEC_IN_AUTHENTICATE     0x02 /* Inbound call requires authentication */
#define BTM_SEC_IN_ENCRYPT          0x04 /* Inbound call requires encryption */
#define BTM_SEC_OUT_AUTHORIZE       0x08 /* Outbound call requires authorization */
#define BTM_SEC_OUT_AUTHENTICATE    0x10 /* Outbound call requires authentication */
#define BTM_SEC_OUT_ENCRYPT         0x20 /* Outbound call requires encryption */
#define BTM_SEC_BOND                0x40 /* Bonding */

/* PIN types */
#define BTM_PIN_TYPE_VARIABLE       HCI_PIN_TYPE_VARIABLE
#define BTM_PIN_TYPE_FIXED          HCI_PIN_TYPE_FIXED

/* Link Key types used to generate the new link key.
** returned in link key notification callback function
*/
#define BTM_LKEY_TYPE_COMBINATION   HCI_LKEY_TYPE_COMBINATION
#define BTM_LKEY_TYPE_LOCAL_UNIT    HCI_LKEY_TYPE_LOCAL_UNIT
#define BTM_LKEY_TYPE_REMOTE_UNIT   HCI_LKEY_TYPE_REMOTE_UNIT
#define BTM_LKEY_TYPE_IGNORE        0xff    /* used when event is response from
                                               hci return link keys request */

/* Protocol level security (BTM_SetSecurityLevel) */
#define BTM_SEC_PROTO_L2CAP         0
#define BTM_SEC_PROTO_SDP           1
#define BTM_SEC_PROTO_TCS           2
#define BTM_SEC_PROTO_RFCOMM        3
#define BTM_SEC_PROTO_OBEX          4
#define BTM_SEC_PROTO_BNEP          5
#define BTM_SEC_PROTO_HID           6   /* HID host     */
#define BTM_SEC_PROTO_HD            7   /* HID device   */
#define BTM_SEC_PROTO_AVDT          8

/* Determine the number of UINT32's necessary for security services */
#define BTM_SEC_ARRAY_BITS          32          /* Number of bits in each array element */
#define BTM_SEC_SERVICE_ARRAY_INDEX (((UINT32)BTM_SEC_MAX_SERVICES / BTM_SEC_ARRAY_BITS) + \
                                    (((UINT32)BTM_SEC_MAX_SERVICES % BTM_SEC_ARRAY_BITS) ? 1 : 0))

/* Security service definitions (BTM_SetSecurityLevel)
** Used for Authorization APIs
*/
#define BTM_SEC_SERVICE_SDP_SERVER      0
#define BTM_SEC_SERVICE_SERIAL_PORT     1
#define BTM_SEC_SERVICE_LAN_ACCESS      2
#define BTM_SEC_SERVICE_DUN             3
#define BTM_SEC_SERVICE_IRMC_SYNC       4
#define BTM_SEC_SERVICE_IRMC_SYNC_CMD   5
#define BTM_SEC_SERVICE_OBEX            6
#define BTM_SEC_SERVICE_OBEX_FTP        7
#define BTM_SEC_SERVICE_HEADSET         8
#define BTM_SEC_SERVICE_CORDLESS        9
#define BTM_SEC_SERVICE_INTERCOM        10
#define BTM_SEC_SERVICE_FAX             11
#define BTM_SEC_SERVICE_HEADSET_AG      12
#define BTM_SEC_SERVICE_PNP_INFO        13
#define BTM_SEC_SERVICE_GEN_NET         14
#define BTM_SEC_SERVICE_GEN_FILE        15
#define BTM_SEC_SERVICE_GEN_AUDIO       16
#define BTM_SEC_SERVICE_GEN_TEL         17
#define BTM_SEC_SERVICE_CTP_DATA        18
#define BTM_SEC_SERVICE_HCRP_CTRL       19
#define BTM_SEC_SERVICE_HCRP_DATA       20
#define BTM_SEC_SERVICE_HCRP_NOTIF      21
#define BTM_SEC_SERVICE_BPP_JOB         22
#define BTM_SEC_SERVICE_BPP_STATUS      23
#define BTM_SEC_SERVICE_BPP_REF         24
#define BTM_SEC_SERVICE_BNEP_PANU       25
#define BTM_SEC_SERVICE_BNEP_GN         26
#define BTM_SEC_SERVICE_BNEP_NAP        27
#define BTM_SEC_SERVICE_HF_HANDSFREE    28
#define BTM_SEC_SERVICE_AG_HANDSFREE    29
#define BTM_SEC_SERVICE_TE_PHONE_ACCESS 30
#define BTM_SEC_SERVICE_ME_PHONE_ACCESS 31
#define BTM_SEC_SERVICE_HID_SEC_CTRL    32
#define BTM_SEC_SERVICE_HID_NOSEC_CTRL  33
#define BTM_SEC_SERVICE_HID_INTR        34
#define BTM_SEC_SERVICE_BIP             35
#define BTM_SEC_SERVICE_BIP_REF         36
#define BTM_SEC_SERVICE_AVDTP           37
#define BTM_SEC_SERVICE_AVDTP_NOSEC     38
#define BTM_SEC_SERVICE_AVCTP           39
#define BTM_SEC_SERVICE_SAP             40

#define BTM_SEC_SERVICE_HIDD_SEC_CTRL    41
#define BTM_SEC_SERVICE_HIDD_NOSEC_CTRL  42
#define BTM_SEC_SERVICE_HIDD_INTR        43

#define BTM_SEC_SERVICE_PBAP            44

/* Update these as services are added */
#define BTM_SEC_SERVICE_FIRST_EMPTY     45
#define BTM_SEC_MAX_SERVICES            46

/************************************************************************************************
** Security Services MACROS handle array of UINT32 bits for more than 32 trusted services
*************************************************************************************************/
/* MACRO to set the security service bit mask in a bit stream */
#define BTM_SEC_SET_SERVICE(p, service)  (((UINT32 *)(p))[(((UINT32)(service)) / BTM_SEC_ARRAY_BITS)] |=  \
                                    (1 << (((UINT32)(service)) % BTM_SEC_ARRAY_BITS)))


/* MACRO to clear the security service bit mask in a bit stream */
#define BTM_SEC_CLR_SERVICE(p, service)  (((UINT32 *)(p))[(((UINT32)(service)) / BTM_SEC_ARRAY_BITS)] &=  \
                                    ~(1 << (((UINT32)(service)) % BTM_SEC_ARRAY_BITS)))

/* MACRO to check the security service bit mask in a bit stream (Returns TRUE or FALSE) */
#define BTM_SEC_IS_SERVICE_TRUSTED(p, service)    (((((UINT32 *)(p))[(((UINT32)(service)) / BTM_SEC_ARRAY_BITS)]) &   \
                                        (UINT32)((1 << (((UINT32)(service)) % BTM_SEC_ARRAY_BITS)))) ? TRUE : FALSE)

/* MACRO to copy two trusted device bitmask */
#define BTM_SEC_COPY_TRUSTED_DEVICE(p_src, p_dst)   {int trst; for (trst = 0; trst < BTM_SEC_SERVICE_ARRAY_INDEX; trst++) \
                                                        ((UINT32 *)(p_dst))[trst] = ((UINT32 *)(p_src))[trst];}

/* Following bits can be provided by host in the trusted_mask array */
/* 0..31 bits of mask[0] (Least Significant Word) */
#define BTM_SEC_TRUST_SDP_SERVER        (1 << BTM_SEC_SERVICE_SDP_SERVER)
#define BTM_SEC_TRUST_SERIAL_PORT       (1 << BTM_SEC_SERVICE_SERIAL_PORT)
#define BTM_SEC_TRUST_LAN_ACCESS        (1 << BTM_SEC_SERVICE_LAN_ACCESS)
#define BTM_SEC_TRUST_DUN               (1 << BTM_SEC_SERVICE_DUN)
#define BTM_SEC_TRUST_IRMC_SYNC         (1 << BTM_SEC_SERVICE_IRMC_SYNC)
#define BTM_SEC_TRUST_IRMC_SYNC_CMD     (1 << BTM_SEC_SERVICE_IRMC_SYNC_CMD)
#define BTM_SEC_TRUST_OBEX              (1 << BTM_SEC_SERVICE_OBEX)
#define BTM_SEC_TRUST_OBEX_FTP          (1 << BTM_SEC_SERVICE_OBEX_FTP)
#define BTM_SEC_TRUST_HEADSET           (1 << BTM_SEC_SERVICE_HEADSET)
#define BTM_SEC_TRUST_CORDLESS          (1 << BTM_SEC_SERVICE_CORDLESS)
#define BTM_SEC_TRUST_INTERCOM          (1 << BTM_SEC_SERVICE_INTERCOM)
#define BTM_SEC_TRUST_FAX               (1 << BTM_SEC_SERVICE_FAX)
#define BTM_SEC_TRUST_HEADSET_AG        (1 << BTM_SEC_SERVICE_HEADSET_AG)
#define BTM_SEC_TRUST_PNP_INFO          (1 << BTM_SEC_SERVICE_PNP_INFO)
#define BTM_SEC_TRUST_GEN_NET           (1 << BTM_SEC_SERVICE_GEN_NET)
#define BTM_SEC_TRUST_GEN_FILE          (1 << BTM_SEC_SERVICE_GEN_FILE)
#define BTM_SEC_TRUST_GEN_AUDIO         (1 << BTM_SEC_SERVICE_GEN_AUDIO)
#define BTM_SEC_TRUST_GEN_TEL           (1 << BTM_SEC_SERVICE_GEN_TEL)
#define BTM_SEC_TRUST_CTP_DATA          (1 << BTM_SEC_SERVICE_CTP_DATA)
#define BTM_SEC_TRUST_HCRP_CTRL         (1 << BTM_SEC_SERVICE_HCRP_CTRL)
#define BTM_SEC_TRUST_HCRP_DATA         (1 << BTM_SEC_SERVICE_HCRP_DATA)
#define BTM_SEC_TRUST_HCRP_NOTIF        (1 << BTM_SEC_SERVICE_HCRP_NOTIF)
#define BTM_SEC_TRUST_BPP_JOB           (1 << BTM_SEC_SERVICE_JOB)
#define BTM_SEC_TRUST_BPP_STATUS        (1 << BTM_SEC_SERVICE_STATUS)
#define BTM_SEC_TRUST_BPP_REF           (1 << BTM_SEC_SERVICE_REF)
#define BTM_SEC_TRUST_BNEP_PANU         (1 << BTM_SEC_SERVICE_BNEP_PANU)
#define BTM_SEC_TRUST_BNEP_GN           (1 << BTM_SEC_SERVICE_BNEP_GN)
#define BTM_SEC_TRUST_BNEP_NAP          (1 << BTM_SEC_SERVICE_BNEP_NAP)
#define BTM_SEC_TRUST_HFP_HF            (1 << BTM_SEC_SERVICE_HF_HANDSFREE)
#define BTM_SEC_TRUST_HFP_AG            (1 << BTM_SEC_SERVICE_AG_HANDSFREE)
#define BTM_SEC_TRUST_TE_PHONE_ACCESS   (1 << BTM_SEC_SERVICE_TE_PHONE_ACCESS)
#define BTM_SEC_TRUST_ME_PHONE_ACCESS   (1 << BTM_SEC_SERVICE_ME_PHONE_ACCESS)

/* 0..31 bits of mask[1] (Most Significant Word) */
#define BTM_SEC_TRUST_HID_CTRL          (1 << BTM_SEC_SERVICE_HID_CTRL)
#define BTM_SEC_TRUST_HID_NOSEC_CTRL    (1 << BTM_SEC_SERVICE_HID_NOSEC_CTRL)
#define BTM_SEC_TRUST_HID_INTR          (1 << BTM_SEC_SERVICE_HID_INTR)

#define BTM_SEC_TRUST_HIDD_CTRL          (1 << BTM_SEC_SERVICE_HIDD_SEC_CTRL)
#define BTM_SEC_TRUST_HIDD_NOSEC_CTRL    (1 << BTM_SEC_SERVICE_HIDD_NOSEC_CTRL)
#define BTM_SEC_TRUST_HIDD_INTR          (1 << BTM_SEC_SERVICE_HIDD_INTR)

#define BTM_SEC_TRUST_BIP               (1 << BTM_SEC_SERVICE_BIP)
#define BTM_SEC_TRUST_BIP_REF           (1 << BTM_SEC_SERVICE_BIP_REF)
#define BTM_SEC_TRUST_AVDTP             (1 << BTM_SEC_SERVICE_AVDTP)
#define BTM_SEC_TRUST_AVCTP             (1 << BTM_SEC_SERVICE_AVCTP)

#define BTM_SEC_TRUST_ALL               0xFFFFFFFF  /* for each array element */

/****************************************
**  Security Manager Callback Functions
*****************************************/
/* Authorize device for service.  Parameters are
**              BD Address of remote
**              Device Class of remote
**              BD Name of remote
**              Service name
**              Service Id (NULL - unknown service or unused
**                                 [BTM_SEC_SERVICE_NAME_LEN set to 0])
**              Is originator of the connection
**              Result of the operation
*/
typedef UINT8 (tBTM_AUTHORIZE_CALLBACK) (BD_ADDR bd_addr, DEV_CLASS dev_class,
                                         tBTM_BD_NAME bd_name, UINT8 *service_name,
                                         UINT8 service_id, BOOLEAN is_originator);

/* Get PIN for the connection.  Parameters are
**              BD Address of remote
**              Device Class of remote
**              BD Name of remote 
*/
typedef UINT8 (tBTM_PIN_CALLBACK) (BD_ADDR bd_addr, DEV_CLASS dev_class,
                                   tBTM_BD_NAME bd_name);

/* Get Link Key for the connection.  Parameters are
**              BD Address of remote
**              Link Key
*/
typedef UINT8 (tBTM_LINK_KEY_REQ_CALLBACK) (BD_ADDR bd_addr, LINK_KEY key);

/* New Link Key for the connection.  Parameters are
**              BD Address of remote
**              Link Key
**              Key Type: Combination, Local Unit, or Remote Unit
*/
typedef UINT8 (tBTM_LINK_KEY_CALLBACK) (BD_ADDR bd_addr, DEV_CLASS dev_class,
                                        tBTM_BD_NAME bd_name, LINK_KEY key,
                                        UINT8 key_type);


/* Remote Name Resolved.  Parameters are
**              BD Address of remote
**              BD Name of remote
*/
typedef void (tBTM_RMT_NAME_CALLBACK) (BD_ADDR bd_addr, DEV_CLASS dc,
                                       tBTM_BD_NAME bd_name);


/* Authentication complete for the connection.  Parameters are
**              BD Address of remote
**              Device Class of remote
**              BD Name of remote 
**
*/
typedef UINT8 (tBTM_AUTH_COMPLETE_CALLBACK) (BD_ADDR bd_addr, DEV_CLASS dev_class,
                                             tBTM_BD_NAME bd_name, int result);

/* Operation abort.  Called by the stack when link goes down during.  Pin code 
** request or authorization.  Parameters are
**              BD Address of remote
**
*/
typedef UINT8 (tBTM_ABORT_CALLBACK) (BD_ADDR bd_addr, DEV_CLASS dev_class,
                                     tBTM_BD_NAME bd_name);

typedef void (tBTM_MKEY_CALLBACK) (BD_ADDR bd_addr, UINT8 status, UINT8 key_flag) ;

/* Encryption enabled/disabled complete: Optionally passed with BTM_SetEncryption. 
** Parameters are
**              BD Address of remote
**              optional data passed in by BTM_SetEncryption
**              tBTM_STATUS - result of the operation
*/
typedef void (tBTM_SEC_CBACK) (BD_ADDR bd_addr, void *p_ref_data, tBTM_STATUS result);


/***************************
**  Security Manager Types
****************************/
/* Structure that applications use to register with BTM_SecRegister */
typedef struct
{
    tBTM_AUTHORIZE_CALLBACK     *p_authorize_callback;
    tBTM_PIN_CALLBACK           *p_pin_callback;
    tBTM_LINK_KEY_CALLBACK      *p_link_key_callback;
    tBTM_LINK_KEY_REQ_CALLBACK  *p_link_key_req_callback;
    tBTM_AUTH_COMPLETE_CALLBACK *p_auth_complete_callback;
    tBTM_ABORT_CALLBACK         *p_abort_callback;
} tBTM_APPL_INFO;


/*****************************************************************************
**  POWER MANAGEMENT
*****************************************************************************/
/****************************
**  Power Manager Constants
*****************************/
/* BTM Power manager status codes */
enum
{
    BTM_PM_STS_ACTIVE = HCI_MODE_ACTIVE,
    BTM_PM_STS_HOLD   = HCI_MODE_HOLD,
    BTM_PM_STS_SNIFF  = HCI_MODE_SNIFF,
    BTM_PM_STS_PARK   = HCI_MODE_PARK,
    BTM_PM_STS_PENDING,   /* when waiting for status from controller */
    BTM_PM_STS_ERROR   /* when HCI command status returns error */
};
typedef UINT8 tBTM_PM_STATUS;

/* BTM Power manager modes */
enum
{
    BTM_PM_MD_ACTIVE = BTM_PM_STS_ACTIVE,
    BTM_PM_MD_HOLD   = BTM_PM_STS_HOLD,
    BTM_PM_MD_SNIFF  = BTM_PM_STS_SNIFF,
    BTM_PM_MD_PARK   = BTM_PM_STS_PARK,
    BTM_PM_MD_FORCE  = 0x10 /* OR this to force ACL link to a certain mode */
};
typedef UINT8 tBTM_PM_MODE;

#define BTM_PM_SET_ONLY_ID  0x80

/* Operation codes */
#define BTM_PM_REG_SET      1 /* The module wants to set the desired power mode */
#define BTM_PM_REG_NOTIF    2 /* The module wants to receive mode change event */
#define BTM_PM_DEREG        4 /* The module does not want to involve with PM anymore */

/************************
**  Power Manager Types
*************************/
typedef struct
{
    UINT16          max;
    UINT16          min;
    UINT16          attempt;
    UINT16          timeout;
    tBTM_PM_MODE    mode;
} tBTM_PM_PWR_MD;

/*************************************
**  Power Manager Callback Functions
**************************************/
typedef void (tBTM_PM_STATUS_CBACK) (BD_ADDR p_bda, tBTM_PM_STATUS status,
                                     UINT16 value, UINT8 hci_status);


/************************
**  Stored Linkkey Types
*************************/
#define BTM_CB_EVT_RETURN_LINK_KEYS         1
#define BTM_CB_EVT_READ_STORED_LINK_KEYS    2
#define BTM_CB_EVT_WRITE_STORED_LINK_KEYS   3
#define BTM_CB_EVT_DELETE_STORED_LINK_KEYS  4

typedef struct
{
    UINT8          event;

} tBTM_STORED_LINK_KEYS_EVT;


typedef struct
{
    UINT8          event;
    UINT8          num_keys;

} tBTM_RETURN_LINK_KEYS_EVT;


typedef struct 
{
    BD_ADDR         bd_addr;
    LINK_KEY        link_key;

} tBTM_BD_ADDR_LINK_KEY_PAIR;


typedef struct
{
    UINT8          event;
    UINT8          status;
    UINT16         max_keys;
    UINT16         read_keys;

} tBTM_READ_STORED_LINK_KEY_COMPLETE;


typedef struct
{
    UINT8          event;
    UINT8          status;
    UINT8          num_keys;

} tBTM_WRITE_STORED_LINK_KEY_COMPLETE;


typedef struct
{
    UINT8          event;
    UINT8          status;
    UINT16         num_keys;

} tBTM_DELETE_STORED_LINK_KEY_COMPLETE;


/*****************************************************************************
**  EXTERNAL FUNCTION DECLARATIONS
*****************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
**  DEVICE CONTROL and COMMON FUNCTIONS
*****************************************************************************/

/*******************************************************************************
**
** Function         BTM_SetAfhChannels
**
** Description      This function is called to disable channels
**
** Returns          status
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetAfhChannels (UINT8 first, UINT8 last);

/*******************************************************************************
**
** Function         BTM_SetAfhChannelAssessment
**
** Description      This function is called to set the channel assessment mode on or off
**
** Returns          status
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetAfhChannelAssessment (BOOLEAN enable_or_disable);

/*******************************************************************************
**
** Function         BTM_DeviceReset
**
** Description      This function is called to reset the controller.The Callback function
**                  if provided is called when startup of the device has 
**                  completed.
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_DeviceReset (tBTM_CMPL_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_IsDeviceUp
**
** Description      This function is called to check if the device is up.
**
** Returns          TRUE if device is up, else FALSE
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_IsDeviceUp (void);


/*******************************************************************************
**
** Function         BTM_SetLocalDeviceName
**
** Description      This function is called to set the local device name.
**
** Returns          BTM_CMD_STARTED if successful, otherwise an error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetLocalDeviceName (char *p_name);


/*******************************************************************************
**
** Function         BTM_SetDeviceClass
**
** Description      This function is called to set the local device class
**
** Returns          BTM_SUCCESS if successful, otherwise an error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS  BTM_SetDeviceClass (DEV_CLASS dev_class);


/*******************************************************************************
**
** Function         BTM_ReadLocalDeviceName
**
** Description      This function is called to read the local device name.
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise an error
**                  Callback contains pointer to name, or NULL if read failed.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ReadLocalDeviceName (tBTM_CMPL_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_ReadLocalVersion
**
** Description      This function is called to read the local device version
**
** Returns          BTM_SUCCESS if successful, otherwise an error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ReadLocalVersion (tBTM_VERSION_INFO *p_vers);


/*******************************************************************************
**
** Function         BTM_ReadLocalDeviceAddr
**
** Description      This function is called to read the local device address
**
** Returns          BTM_SUCCESS
**                  Callback returns the local device address
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ReadLocalDeviceAddr (tBTM_CMPL_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_ReadDeviceClass
**
** Description      This function is called to read the local device class
**
** Returns          pointer to the device class
**
*******************************************************************************/
BTM_API extern UINT8 *BTM_ReadDeviceClass (void);


/*******************************************************************************
**
** Function         BTM_ReadLocalFeatures
**
** Description      This function is called to read the local features
**
** Returns          pointer to the local features string
**
*******************************************************************************/
BTM_API extern UINT8 *BTM_ReadLocalFeatures (void);


/*******************************************************************************
**
** Function         BTM_RegisterForDeviceStatusNotif 
**
** Description      This function is called to register for device status
**                  change notifications.
**
** Returns          pointer to previous caller's callback function or NULL if first
**                  registration.
**
*******************************************************************************/
BTM_API extern tBTM_DEV_STATUS_CB *BTM_RegisterForDeviceStatusNotif (tBTM_DEV_STATUS_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_RegisterForVSEvents 
**
** Description      This function is called to register for vendor specific HCI
**                  events.  Only one can be registered at a time.
**                  If NULL, the events are deregistered.
**
** Returns          BTM_SUCCESS if successful, BTM_BUSY if already registered for.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_RegisterForVSEvents (tBTM_VS_EVT_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_ContinueReset 
**
** Description      Instructs stack to continue its stack initialization after
**                  an application has completed any vender specific commands
**                  sent to the controller.
**
**                  Note: This function is only called if an application 
**                      initialization function has been inserted in the reset
**                      sequence.  (BTM_APP_DEV_INIT is defined with a function).
** 
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_ContinueReset (void);


/*******************************************************************************
**
** Function         BTM_VendorSpecificCommand 
**
** Description      Send a vendor specific HCI command to the controller.
**
** Returns
**      BTM_SUCCESS         Command sent. Does not expect command complete
**                              event. (command cmpl callback param is NULL)
**      BTM_CMD_STARTED     Command sent. Waiting for command cmpl event.
**      BTM_BUSY            Command not sent. Waiting for cmd cmpl event for
**                              prior command.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_VendorSpecificCommand(UINT16 opcode,
                                                     UINT8 param_len,
                                                     UINT8 *p_param_buf,
                                                     tBTM_CMPL_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_AllocateSCN
**
** Description      Look through the Server Channel Numbers for a free one to be
**                  used with an RFCOMM connection.
**
** Returns          Allocated SCN number or 0 if none.
**
*******************************************************************************/
BTM_API extern UINT8 BTM_AllocateSCN(void);


/*******************************************************************************
**
** Function         BTM_FreeSCN
**
** Description      Free the specified SCN.
**
** Returns          TRUE if successful, FALSE if SCN is not in use or invalid
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_FreeSCN(UINT8 scn);


/*******************************************************************************
**
** Function         BTM_SetTraceLevel
**
** Description      This function sets the trace level for BTM.  If called with
**                  a value of 0xFF, it simply returns the current trace level.
**
** Returns          The new or current trace level
**
*******************************************************************************/
BTM_API extern UINT8 BTM_SetTraceLevel (UINT8 new_level);


/*******************************************************************************
**
** Function         BTM_WritePageTimeout 
**
** Description      Send HCI Wite Page Timeout.
**
** Returns
**      BTM_SUCCESS         Command sent. 
**      BTM_NO_RESOURCES    If out of resources to send the command.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_WritePageTimeout(UINT16 timeout);

/*******************************************************************************
**
** Function         BTM_WriteVoiceSettings 
**
** Description      Send HCI Write Voice Settings command.
**                  See hcidefs.h for settings bitmask values.
**
** Returns
**      BTM_SUCCESS         Command sent. 
**      BTM_NO_RESOURCES     If out of resources to send the command.
**
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_WriteVoiceSettings(UINT16 settings);

/*******************************************************************************
**
** Function         BTM_EnableTestMode 
**
** Description      Send HCI the enable device under test command.
**
**                  Note: Controller can only be taken out of this mode by 
**                      resetting the controller.
**
** Returns
**      BTM_SUCCESS         Command sent. 
**      BTM_NO_RESOURCES    If out of resources to send the command.
**
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_EnableTestMode(void);


/*****************************************************************************
**  DEVICE DISCOVERY FUNCTIONS - Inquiry, Remote Name, Discovery, Class of Device
*****************************************************************************/

/*******************************************************************************
**
** Function         BTM_SetDiscoverability
**
** Description      This function is called to set the device into or out of
**                  discoverable mode. Discoverable mode means inquiry
**                  scans are enabled.  If a value of '0' is entered for window or
**                  interval, the default values are used.
**
** Returns          BTM_SUCCESS if successful
**                  BTM_BUSY if a setting of the filter is already in progress
**                  BTM_NO_RESOURCES if couldn't get a memory pool buffer
**                  BTM_ILLEGAL_VALUE if a bad parameter was detected
**                  BTM_WRONG_MODE if the device is not up.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS  BTM_SetDiscoverability (UINT16 inq_mode, UINT16 window,
                                                    UINT16 interval);


/*******************************************************************************
**
** Function         BTM_ReadDiscoverability
**
** Description      This function is called to read the current discoverability
**                  mode of the device.
**
** Output Params:   p_window - current inquiry scan duration
**                  p_interval - current inquiry scan interval
**
** Returns          BTM_NON_DISCOVERABLE, BTM_LIMITED_DISCOVERABLE, or
**                  BTM_GENERAL_DISCOVERABLE
**
*******************************************************************************/
BTM_API extern UINT16       BTM_ReadDiscoverability (UINT16 *p_window,
                                                     UINT16 *p_interval);


/*******************************************************************************
**
** Function         BTM_SetPeriodicInquiryMode
**
** Description      This function is called to set the device periodic inquiry mode.
**                  If the duration is zero, the periodic inquiry mode is cancelled.
**
** Parameters:      p_inqparms - pointer to the inquiry information
**                      mode - GENERAL or LIMITED inquiry
**                      duration - length in 1.28 sec intervals (If '0', the inquiry is CANCELLED)
**                      max_resps - maximum amount of devices to search for before ending the inquiry
**                      filter_cond_type - BTM_CLR_INQUIRY_FILTER, BTM_FILTER_COND_DEVICE_CLASS, or
**                                         BTM_FILTER_COND_BD_ADDR
**                      filter_cond - value for the filter (based on filter_cond_type)
**
**                  max_delay - maximum amount of time between successive inquiries
**                  min_delay - minimum amount of time between successive inquiries
**                  p_results_cb - callback returning pointer to results (tBTM_INQ_RESULTS)
**
** Returns          BTM_CMD_STARTED if successfully started
**                  BTM_ILLEGAL_VALUE if a bad parameter is detected
**                  BTM_NO_RESOURCES if could not allocate a message buffer
**                  BTM_SUCCESS - if cancelling the periodic inquiry
**                  BTM_BUSY - if an inquiry is already active
**                  BTM_WRONG_MODE if the device is not up.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS  BTM_SetPeriodicInquiryMode (tBTM_INQ_PARMS *p_inqparms,
                                                        UINT16 max_delay, UINT16 min_delay,
                                                        tBTM_CMPL_CB *p_results_cb);


/*******************************************************************************
**
** Function         BTM_StartInquiry
**
** Description      This function is called to start an inquiry.
**
** Parameters:      p_inqparms - pointer to the inquiry information
**                      mode - GENERAL or LIMITED inquiry
**                      duration - length in 1.28 sec intervals (If '0', the inquiry is CANCELLED)
**                      max_resps - maximum amount of devices to search for before ending the inquiry
**                      filter_cond_type - BTM_CLR_INQUIRY_FILTER, BTM_FILTER_COND_DEVICE_CLASS, or
**                                         BTM_FILTER_COND_BD_ADDR
**                      filter_cond - value for the filter (based on filter_cond_type)
**
**                  p_results_cb   - Pointer to the callback routine which gets called
**                                upon receipt of an inquiry result. If this field is
**                                NULL, the application is not notified.
**
**                  p_cmpl_cb   - Pointer to the callback routine which gets called
**                                upon completion.  If this field is NULL, the
**                                application is not notified when completed.
** Returns          tBTM_STATUS
**                  BTM_CMD_STARTED if successfully initiated
**                  BTM_BUSY if already in progress
**                  BTM_ILLEGAL_VALUE if parameter(s) are out of range
**                  BTM_NO_RESOURCES if could not allocate resources to start the command
**                  BTM_WRONG_MODE if the device is not up.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS  BTM_StartInquiry (tBTM_INQ_PARMS *p_inqparms,
                                             tBTM_CMPL_CB *p_results_cb,
                                             tBTM_CMPL_CB *p_cmpl_cb);


/*******************************************************************************
**
** Function         BTM_IsInquiryActive
**
** Description      This function returns a bit mask of the current inquiry state
**
** Returns          BTM_INQUIRY_INACTIVE if inactive (0)
**                  BTM_LIMITED_INQUIRY_ACTIVE if a limted inquiry is active
**                  BTM_GENERAL_INQUIRY_ACTIVE if a general inquiry is active
**                  BTM_PERIODIC_INQUIRY_ACTIVE if a periodic inquiry is active
**
*******************************************************************************/
BTM_API extern UINT16 BTM_IsInquiryActive (void);


/*******************************************************************************
**
** Function         BTM_CancelInquiry
**
** Description      This function cancels an inquiry if active
**
** Returns          BTM_SUCCESS if successful
**                  BTM_NO_RESOURCES if could not allocate a message buffer
**                  BTM_WRONG_MODE if the device is not up.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_CancelInquiry(void);


/*******************************************************************************
**
** Function         BTM_CancelPeriodicInquiry
**
** Description      This function cancels a periodic inquiry
**
** Returns
**                  BTM_NO_RESOURCES if could not allocate a message buffer
**                  BTM_SUCCESS - if cancelling the periodic inquiry
**                  BTM_WRONG_MODE if the device is not up.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_CancelPeriodicInquiry(void);


/*******************************************************************************
**
** Function         BTM_SetInquiryFilterCallback
**
** Description      Host can register to be asked whenever an inquiry result 
**                  is received.  If host does not like the device no name
**                  request is issued for the device
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_SetInquiryFilterCallback(tBTM_FILTER_CB *p_callback);


/*******************************************************************************
**
** Function         BTM_SetConnectability
**
** Description      This function is called to set the device into or out of
**                  connectable mode. Discoverable mode means page scans enabled.
**
** Returns          BTM_SUCCESS if successful
**                  BTM_ILLEGAL_VALUE if a bad parameter is detected
**                  BTM_NO_RESOURCES if could not allocate a message buffer
**                  BTM_WRONG_MODE if the device is not up.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetConnectability (UINT16 page_mode, UINT16 window,
                                                  UINT16 interval);


/*******************************************************************************
**
** Function         BTM_ReadConnectability
**
** Description      This function is called to read the current discoverability
**                  mode of the device.
** Output Params    p_window - current page scan duration
**                  p_interval - current time between page scans
**
** Returns          BTM_NON_CONNECTABLE or BTM_CONNECTABLE
**
*******************************************************************************/
BTM_API extern UINT16 BTM_ReadConnectability (UINT16 *p_window, UINT16 *p_interval);


/*******************************************************************************
**
** Function         BTM_SetInquiryMode
**
** Description      This function is called to set standard or with RSSI
**                  mode of the inquiry for local device.
**
** Input Params:    BTM_INQ_RESULT_STANDARD or BTM_INQ_RESULT_WITH_RSSI
**
** Returns          BTM_SUCCESS if successful
**                  BTM_NO_RESOURCES if couldn't get a memory pool buffer
**                  BTM_ILLEGAL_VALUE if a bad parameter was detected
**                  BTM_WRONG_MODE if the device is not up.
**
*******************************************************************************/
BT_API extern tBTM_STATUS  BTM_SetInquiryMode (UINT8 mode);

/*******************************************************************************
**
** Function         BTM_SetInquiryScanType
**
** Description      This function is called to set the iquiry scan-type to
**                  standard or interlaced.
**
** Input Params:    BTM_SCAN_TYPE_STANDARD or BTM_SCAN_TYPE_INTERLACED
**
** Returns          BTM_SUCCESS if successful
**                  BTM_MODE_UNSUPPORTED if not a 1.2 device
**                  BTM_WRONG_MODE if the device is not up.
**
*******************************************************************************/
BT_API extern tBTM_STATUS BTM_SetInquiryScanType (UINT16 scan_type);

/*******************************************************************************
**
** Function         BTM_SetPageScanType
**
** Description      This function is called to set the page scan-type to
**                  standard or interlaced.
**
** Input Params:    BTM_SCAN_TYPE_STANDARD or BTM_SCAN_TYPE_INTERLACED
**
** Returns          BTM_SUCCESS if successful
**                  BTM_MODE_UNSUPPORTED if not a 1.2 device
**                  BTM_WRONG_MODE if the device is not up.
**
*******************************************************************************/

BT_API extern tBTM_STATUS BTM_SetPageScanType (UINT16 scan_type);

/*******************************************************************************
**
** Function         BTM_ReadRemoteDeviceName
**
** Description      This function initiates a remote device HCI command to the
**                  controller and calls the callback when the process has completed.
**
** Input Params:    remote_bda      - device address of name to retrieve
**                  p_cb            - callback function called when BTM_CMD_STARTED
**                                    is returned.
**                                    A pointer to tBTM_REMOTE_DEV_NAME is passed to the
**                                    callback.
**
** Returns
**                  BTM_CMD_STARTED is returned if the request was successfully sent
**                                  to HCI.
**                  BTM_BUSY if already in progress
**                  BTM_UNKNOWN_ADDR if device address is bad
**                  BTM_NO_RESOURCES if could not allocate resources to start the command
**                  BTM_WRONG_MODE if the device is not up.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS  BTM_ReadRemoteDeviceName (BD_ADDR remote_bda,
                                                      tBTM_CMPL_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_CancelRemoteDeviceName
**
** Description      This function initiates the cancel request for the specified
**                  remote device.
**
** Input Params:    None
**
** Returns
**                  BTM_CMD_STARTED is returned if the request was successfully sent
**                                  to HCI.
**                  BTM_NO_RESOURCES if could not allocate resources to start the command
**                  BTM_WRONG_MODE if there is not an active remote name request.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS  BTM_CancelRemoteDeviceName (void);

/*******************************************************************************
**
** Function         BTM_ReadRemoteVersion
**
** Description      This function is called to read a remote device's version
**
** Returns          BTM_SUCCESS if successful, otherwise an error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ReadRemoteVersion (BD_ADDR addr,
                                                  UINT8 *lmp_version,
                                                  UINT16 *manufacturer,
                                                  UINT16 *lmp_sub_version);

/*******************************************************************************
**
** Function         BTM_InqFirstResult
**
** Description      This function looks through the inquiry database for the first
**                  used entrysince the LAST inquiry. This is used in conjunction 
**                  with BTM_InqNext by applications as a way to walk through the
**                  inquiry results database.
**
** Returns          pointer to first in-use entry, or NULL if DB is empty
**
*******************************************************************************/
BTM_API extern tBTM_INQ_INFO *BTM_InqFirstResult (void);


/*******************************************************************************
**
** Function         BTM_InqNextResult
**
** Description      This function looks through the inquiry database for the next
**                  used entrysince the LAST inquiry. If the input parameter is NULL,
**                  the first entry is returned.
**
** Returns          pointer to next in-use entry, or NULL if no more found.
**
*******************************************************************************/
BTM_API extern tBTM_INQ_INFO *BTM_InqNextResult (tBTM_INQ_INFO *p_cur);


/*******************************************************************************
**
** Function         BTM_InqDbRead
**
** Description      This function looks through the inquiry database for a match
**                  based on Bluetooth Device Address. This is the application's
**                  interface to get the inquiry details of a specific BD address.
**
** Returns          pointer to entry, or NULL if not found
**
*******************************************************************************/
BTM_API extern tBTM_INQ_INFO *BTM_InqDbRead (BD_ADDR p_bda);


/*******************************************************************************
**
** Function         BTM_InqDbFirst
**
** Description      This function looks through the inquiry database for the first
**                  used entry, and returns that. This is used in conjunction with
**                  BTM_InqDbNext by applications as a way to walk through the
**                  inquiry database.
**
** Returns          pointer to first in-use entry, or NULL if DB is empty
**
*******************************************************************************/
BTM_API extern tBTM_INQ_INFO *BTM_InqDbFirst (void);


/*******************************************************************************
**
** Function         BTM_InqDbNext
**
** Description      This function looks through the inquiry database for the next
**                  used entry, and returns that.  If the input parameter is NULL,
**                  the first entry is returned.
**
** Returns          pointer to next in-use entry, or NULL if no more found.
**
*******************************************************************************/
BTM_API extern tBTM_INQ_INFO *BTM_InqDbNext (tBTM_INQ_INFO *p_cur);


/*******************************************************************************
**
** Function         BTM_ClearInqDb
**
** Description      This function is called to clear out a device or all devices
**                  from the inquiry database.
**
** Parameter        p_bda - (input) BD_ADDR ->  Address of device to clear
**                                              (NULL clears all entries)
**
** Returns          BTM_BUSY if an inquiry, get remote name, or event filter
**                          is active, otherwise BTM_SUCCESS
**
*******************************************************************************/
BTM_API extern tBTM_STATUS  BTM_ClearInqDb (BD_ADDR p_bda);


/*******************************************************************************
**
** Function         BTM_ReadNumInqDbEntries
**
** Returns          This function returns the number of entries in the inquiry database.
**
*******************************************************************************/
BTM_API extern UINT8 BTM_ReadNumInqDbEntries (void);


/*******************************************************************************
**
** Function         BTM_InquiryRegisterForChanges
**
** Description      This function is called to register a callback for when the
**                  inquiry database changes, i.e. new entry or entry deleted.
**
** Returns          BTM_SUCCESS if successful, otherwise error code
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_InquiryRegisterForChanges (tBTM_INQ_DB_CHANGE_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_StartDiscovery
**
** Description      This function is called by an application (or profile)
**                  when it wants to trigger an service discovery using the
**                  BTM's discovery database.
**
** Returns          tBTM_STATUS
**                      BTM_CMD_STARTED if the discovery was initiated
**                      BTM_BUSY if one is already in progress
**                      BTM_UNKNOWN_ADDR if no addresses are in the INQ DB
**                      BTM_ERR_PROCESSING if err initiating the command
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_StartDiscovery (tBTM_CMPL_CB *p_cmpl_cb,
                                                BD_ADDR_PTR p_rem_addr);


/*******************************************************************************
**
** Function         BTM_FindAttribute
**
** Description      This function is called by an application (or profile)
**                  when it wants to see if an attribute exists in the BTM
**                  discovery database.
**
** Returns          Pointer to matching record, or NULL
**
*******************************************************************************/
BTM_API extern tSDP_DISC_REC *BTM_FindAttribute (UINT16 attr_id,
                                                 tSDP_DISC_REC *p_start_rec);


/*******************************************************************************
**
** Function         BTM_FindService
**
** Description      This function is called by an application (or profile)
**                  when it wants to see if a service exists in the BTM
**                  discovery database.
**
** Returns          Pointer to matching record, or NULL
**
*******************************************************************************/
BTM_API extern tSDP_DISC_REC *BTM_FindService (UINT16 service_uuid,
                                               tSDP_DISC_REC *p_start_rec);


/*******************************************************************************
**
** Function         BTM_SetDiscoveryParams
**
** Description      This function is called to set the BTM default discovery parameters.
**                  These UUID and attribute filters are used during the call to
**                  BTM_StartDiscovery.
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_SetDiscoveryParams (UINT16 num_uuid, tSDP_UUID *p_uuid_list,
                                            UINT16 num_attr, UINT16 *p_attr_list);


/*****************************************************************************
**  ACL CHANNEL MANAGEMENT FUNCTIONS
*****************************************************************************/
/*******************************************************************************
**
** Function         BTM_SetLinkPolicy
**
** Description      Create and send HCI "Write Policy Set" command
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetLinkPolicy (BD_ADDR remote_bda,
                                               UINT16 *settings);


/*******************************************************************************
**
** Function         BTM_ReadLinkPolicy
**
** Description      This function is called to read the link policy settings.
**                  The address of link policy results are returned in the callback.
**                  (tBTM_LNK_POLICY_RESULTS)
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ReadLinkPolicy (BD_ADDR remote_bda,
                                                tBTM_CMPL_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_SetDefaultLinkPolicy
**
** Description      Set the default value for HCI "Write Policy Set" command
**                  to use when an ACL link is created.
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_SetDefaultLinkPolicy (UINT16 settings);


/*******************************************************************************
**
** Function         BTM_SetDefaultLinkSuperTout
**
** Description      Set the default value for HCI "Write Link Supervision Timeout"
**                  command to use when an ACL link is created.
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_SetDefaultLinkSuperTout (UINT16 timeout);


/*******************************************************************************
**
** Function         BTM_SetLinkSuperTout
**
** Description      Create and send HCI "Write Link Supervision Timeout" command
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetLinkSuperTout (BD_ADDR remote_bda,
                                                 UINT16 timeout);


/* These next APIs are available if the power manager is not compiled in */
#if BTM_PWR_MGR_INCLUDED == FALSE
/*******************************************************************************
**
** Function         BTM_SetHoldMode
**
** Description      This function is called to set a connection into hold mode.
**                  A check is made if the connection is in sniff or park mode,
**                  and if yes, the hold mode is ignored.
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetHoldMode (BD_ADDR remote_bda, UINT16 min_interval,
                                            UINT16 max_interval);


/*******************************************************************************
**
** Function         BTM_SetSniffMode
**
** Description      This function is called to set a connection into sniff mode.
**                  A check is made if the connection is already in sniff or park
**                  mode, and if yes, the sniff mode is ignored.
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetSniffMode (BD_ADDR remote_bda, UINT16 min_period,
                                             UINT16 max_period, UINT16 attempt,
                                             UINT16 timeout);


/*******************************************************************************
**
** Function         BTM_CancelSniffMode
**
** Description      This function is called to put a connection out of sniff mode.
**                  A check is made if the connection is already in sniff mode,
**                  and if not, the cancel sniff mode is ignored.
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_CancelSniffMode (BD_ADDR remote_bda);


/*******************************************************************************
**
** Function         BTM_SetParkMode
**
** Description      This function is called to set a connection into park mode.
**                  A check is made if the connection is already in sniff or park
**                  mode, and if yes, the park mode is ignored.
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetParkMode (BD_ADDR remote_bda,
                                            UINT16 beacon_min_period,
                                            UINT16 beacon_max_period);


/*******************************************************************************
**
** Function         BTM_CancelParkMode
**
** Description      This function is called to put a connection out of park mode.
**                  A check is made if the connection is already in park mode,
**                  and if not, the cancel sniff mode is ignored.
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_CancelParkMode (BD_ADDR remote_bda);


/*******************************************************************************
**
** Function         BTM_ReadAclMode
**
** Description      This returns the current mode for a specific
**                  ACL connection.
**
** Input Param      remote_bda - device address of desired ACL connection
**
** Output Param     p_mode - address where the current mode is copied into.
**                          BTM_ACL_MODE_NORMAL
**                          BTM_ACL_MODE_HOLD
**                          BTM_ACL_MODE_SNIFF
**                          BTM_ACL_MODE_PARK
**                          (valid only if return code is BTM_SUCCESS)
**
** Returns          BTM_SUCCESS if successful,
**                  BTM_UNKNOWN_ADDR if bd addr is not active or bad
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ReadAclMode (BD_ADDR remote_bda, UINT8 *p_mode);

#endif /* if BTM_PWR_MGR_INCLUDED == FALSE */


/*******************************************************************************
**
** Function         BTM_SetPacketTypes
**
** Description      This function is set the packet types used for a specific
**                  ACL connection,
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetPacketTypes (BD_ADDR remote_bda, UINT16 pkt_types);


/*******************************************************************************
**
** Function         BTM_ReadPacketTypes
**
** Description      This function is set the packet types used for the specified
**                  ACL connection,
**
** Returns          packet types supported for the connection, or 0 if no BD address
**
*******************************************************************************/
BTM_API extern UINT16 BTM_ReadPacketTypes (BD_ADDR remote_bda);


/*******************************************************************************
**
** Function         BTM_IsAclConnectionUp
**
** Description      This function is called to check if an ACL connection exists
**                  to a specific remote BD Address.
**
** Returns          TRUE if connection is up, else FALSE.
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_IsAclConnectionUp (BD_ADDR remote_bda);


/*******************************************************************************
**
** Function         BTM_GetRole
**
** Description      This function is called to get the role of the local device
**                  for the ACL connection with the specified remote device
**
** Returns          BTM_SUCCESS if connection exists.
**                  BTM_UNKNOWN_ADDR if no active link with bd addr specified
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_GetRole (BD_ADDR remote_bd_addr, UINT8 *p_role);



/*******************************************************************************
**
** Function         BTM_SwitchRole
**
** Description      This function is called to switch role between master and
**                  slave.  If role is already set it will do nothing.  If the 
**                  command was initiated, the callback function is called upon
**                  completion.
**
** Returns          BTM_SUCCESS if already in specified role.
**                  BTM_CMD_STARTED if command issued to controller.
**                  BTM_NO_RESOURCES if couldn't allocate memory to issue command
**                  BTM_UNKNOWN_ADDR if no active link with bd addr specified
**                  BTM_MODE_UNSUPPORTED if local device does not support role switching
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SwitchRole (BD_ADDR remote_bd_addr,
                                           UINT8 new_role,
                                           tBTM_CMPL_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_ReadRSSI
**
** Description      This function is called to read the link policy settings.
**                  The address of link policy results are returned in the callback.
**                  (tBTM_RSSI_RESULTS)
**
** Returns          BTM_CMD_STARTED if command issued to controller.
**                  BTM_NO_RESOURCES if couldn't allocate memory to issue command
**                  BTM_UNKNOWN_ADDR if no active link with bd addr specified
**                  BTM_BUSY if command is already in progress
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ReadRSSI (BD_ADDR remote_bda, tBTM_CMPL_CB *p_cb);

/*******************************************************************************
**
** Function         BTM_ReadLinkQuality
**
** Description      This function is called to read the link quality.
**                  The value of the link quality is returned in the callback.
**                  (tBTM_LINK_QUALITY_RESULTS)
**
** Returns          BTM_CMD_STARTED if command issued to controller.
**                  BTM_NO_RESOURCES if couldn't allocate memory to issue command
**                  BTM_UNKNOWN_ADDR if no active link with bd addr specified
**                  BTM_BUSY if command is already in progress
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ReadLinkQuality (BD_ADDR remote_bda, tBTM_CMPL_CB *p_cb);

/*******************************************************************************
**
** Function         BTM_RegBusyLevelNotif
**
** Description      This function is called to register a callback to receive
**                  busy level change events.
**
** Returns          BTM_SUCCESS if successfully registered, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_RegBusyLevelNotif (tBTM_BL_CHANGE_CB *p_cb, UINT8 *p_level,
                                                  tBTM_BL_EVENT_MASK evt_mask);

/*******************************************************************************
**
** Function         BTM_AclRegisterForChanges
**
** Description      This function is called to register a callback to receive
**                  ACL database change events, i.e. new connection or removed.
**
** Returns          BTM_SUCCESS if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_AclRegisterForChanges (tBTM_ACL_DB_CHANGE_CB *p_cb);

/*******************************************************************************
**
** Function         BTM_GetNumAclLinks
**
** Description      This function is called to count the number of 
**                  ACL links that are active.
**
** Returns          UINT16  Number of active ACL links
**
*******************************************************************************/
BTM_API extern UINT16 BTM_GetNumAclLinks (void);


/*******************************************************************************
**
** Function         BTM_ReadClockOffset
**
** Description      This returns the clock offset for a specific
**                  ACL connection.
**
** Returns          clock-offset or 0 if unknown
**
*******************************************************************************/
BTM_API extern UINT16 BTM_ReadClockOffset (BD_ADDR remote_bda);


/*******************************************************************************
**
** Function         BTM_SetQoS
**
** Description      This function is called to setup QoS
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetQoS(BD_ADDR bd, FLOW_SPEC *p_flow,
                                      tBTM_CMPL_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_GetAclBufInfo
**
** Description      Return a snapshot of number of queued ACL buffers and
**                  number of available buffers in the controller for xmit
**
** Returns          void
**
*******************************************************************************/
void BTM_GetAclBufInfo(UINT16 *p_num_avail, UINT16 *p_num_bufs, UINT16 *p_num_queued);


/*****************************************************************************
**  (e)SCO CHANNEL MANAGEMENT FUNCTIONS
*****************************************************************************/
/*******************************************************************************
**
** Function         BTM_CreateSco
**
** Description      This function is called to create an SCO connection. If the
**                  "is_orig" flag is TRUE, the connection will be originated,
**                  otherwise BTM will wait for the other side to connect.
**
** Returns          BTM_UNKNOWN_ADDR if the ACL connection is not up
**                  BTM_BUSY         if another SCO being set up to
**                                   the same BD address
**                  BTM_NO_RESOURCES if the max SCO limit has been reached
**                  BTM_CMD_STARTED  if the connection establishment is started.
**                                   In this case, "*p_sco_inx" is filled in
**                                   with the sco index used for the connection.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_CreateSco (BD_ADDR remote_bda, BOOLEAN is_orig,
                                          UINT16 pkt_types, UINT16 *p_sco_inx,
                                          tBTM_SCO_CB *p_conn_cb,
                                          tBTM_SCO_CB *p_disc_cb);


/*******************************************************************************
**
** Function         BTM_RemoveSco
**
** Description      This function is called to remove a specific SCO connection.
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_RemoveSco (UINT16 sco_inx);


/*******************************************************************************
**
** Function         BTM_SetScoPacketTypes
**
** Description      This function is called to set the packet types used for
**                  a specific SCO connection,
**
** Parameters       pkt_types - One or more of the following
**                  BTM_SCO_PKT_TYPES_MASK_HV1
**                  BTM_SCO_PKT_TYPES_MASK_HV2
**                  BTM_SCO_PKT_TYPES_MASK_HV3
**                  BTM_SCO_PKT_TYPES_MASK_EV3
**                  BTM_SCO_PKT_TYPES_MASK_EV4
**                  BTM_SCO_PKT_TYPES_MASK_EV5
**
**                  BTM_SCO_LINK_ALL_MASK   - enables all supported types
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetScoPacketTypes (UINT16 sco_inx, UINT16 pkt_types);


/*******************************************************************************
**
** Function         BTM_ReadScoPacketTypes
**
** Description      This function is read the packet types used for a specific
**                  SCO connection.
**
** Returns       One or more of the following (bitmask)
**                  BTM_SCO_PKT_TYPES_MASK_HV1
**                  BTM_SCO_PKT_TYPES_MASK_HV2
**                  BTM_SCO_PKT_TYPES_MASK_HV3
**                  BTM_SCO_PKT_TYPES_MASK_EV3
**                  BTM_SCO_PKT_TYPES_MASK_EV4
**                  BTM_SCO_PKT_TYPES_MASK_EV5
**
** Returns          packet types supported for the connection
**
*******************************************************************************/
BTM_API extern UINT16 BTM_ReadScoPacketTypes (UINT16 sco_inx);


/*******************************************************************************
**
** Function         BTM_ReadDeviceScoPacketTypes
**
** Description      This function is read the SCO packet types that
**                  the device supports.
**
** Returns          packet types supported by the device.
**
*******************************************************************************/
BTM_API extern UINT16 BTM_ReadDeviceScoPacketTypes (void);


/*******************************************************************************
**
** Function         BTM_ReadScoHandle
**
** Description      This function is used to read the HCI handle used for a specific
**                  SCO connection,
**
** Returns          handle for the connection, or 0xFFFF if invalid SCO index.
**
*******************************************************************************/
BTM_API extern UINT16 BTM_ReadScoHandle (UINT16 sco_inx);


/*******************************************************************************
**
** Function         BTM_ReadScoBdAddr
**
** Description      This function is read the remote BD Address for a specific
**                  SCO connection,
**
** Returns          pointer to BD address or NULL if not known
**
*******************************************************************************/
BTM_API extern UINT8 *BTM_ReadScoBdAddr (UINT16 sco_inx);


/*******************************************************************************
**
** Function         BTM_ReadScoDiscReason
**
** Description      This function is returns the reason why an (e)SCO connection
**                  has been removed. It contains the value until read, or until
**                  another (e)SCO connection has disconnected.
**
** Returns          HCI reason or BTM_INVALID_SCO_DISC_REASON if not set.
**
*******************************************************************************/
BTM_API extern UINT16 BTM_ReadScoDiscReason (void);


/*******************************************************************************
**
** Function         BTM_SetEScoMode
**
** Description      This function sets up the negotiated parameters for SCO or
**                  eSCO, and sets as the default mode used for calls to
**                  BTM_CreateSco.  It can be called only when there are no
**                  active (e)SCO links.                 
**
** Returns          BTM_SUCCESS if the successful.
**                  BTM_BUSY if there are one or more active (e)SCO links.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetEScoMode (tBTM_SCO_TYPE sco_mode,
                                            tBTM_ESCO_PARAMS *p_parms);

/*******************************************************************************
**
** Function         BTM_RegForEScoEvts
**
** Description      This function registers a SCO event callback with the
**                  specified instance.  It should be used to received 
**                  connection indication events and change of link parameter
**                  events.                 
**
** Returns          BTM_SUCCESS if the successful.
**                  BTM_ILLEGAL_VALUE if there is an illegal sco_inx
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_RegForEScoEvts (UINT16 sco_inx,
                                               tBTM_ESCO_CBACK *p_esco_cback);

/*******************************************************************************
**
** Function         BTM_ReadEScoLinkParms
**
** Description      This function returns the current eSCO link parameters for
**                  the specified handle.  This can be called anytime a connection
**                  is active, but is typically called after receiving the SCO
**                  opened callback.
**                  
**
** Returns          BTM_SUCCESS if returned data is valid connection.
**                  BTM_ILLEGAL_VALUE if no connection for specified sco_inx.
**                  BTM_MODE_UNSUPPORTED if local controller does not support
**                      1.2 specification.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ReadEScoLinkParms (UINT16 sco_inx,
                                                  tBTM_ESCO_DATA *p_parms);

/*******************************************************************************
**
** Function         BTM_ChangeEScoLinkParms
**
** Description      This function requests renegotiation of the parameters on
**                  the current eSCO Link.  If any of the changes are accepted
**                  by the controllers, the BTM_ESCO_CHG_EVT event is sent in
**                  the tBTM_ESCO_CBACK function with the current settings of
**                  the link. The callback is registered through the call to
**                  BTM_SetEScoMode.
**                  
**
** Returns          BTM_CMD_STARTED if command is successfully initiated.
**                  BTM_ILLEGAL_VALUE if no connection for specified sco_inx.
**                  BTM_NO_RESOURCES - not enough resources to initiate command.
**                  BTM_MODE_UNSUPPORTED if local controller does not support
**                      1.2 specification.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ChangeEScoLinkParms (UINT16 sco_inx,
                                                    tBTM_CHG_ESCO_PARAMS *p_parms);

/*******************************************************************************
**
** Function         BTM_EScoConnRsp
**
** Description      This function is called upon receipt of an (e)SCO connection
**                  request event (BTM_ESCO_CONN_REQ_EVT) to accept or reject
**                  the request. Parameters used to negotiate eSCO links.
**                  If p_parms is NULL, then values set through BTM_SetEScoMode
**                  are used.
**                  If the link type of the incoming request is SCO, then only
**                  the tx_bw, max_latency, content format, and packet_types are
**                  valid.  The hci_status parameter should be
**                  ([0x0] to accept, [0x0d..0x0f] to reject)
**                  
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_EScoConnRsp (UINT16 sco_inx, UINT8 hci_status,
                                     tBTM_ESCO_PARAMS *p_parms);


/*****************************************************************************
**  SECURITY MANAGEMENT FUNCTIONS
*****************************************************************************/
/*******************************************************************************
**
** Function         BTM_SecRegister
**
** Description      Application manager calls this function to register for 
**                  security services.  There can be one and only one application
**                  saving link keys.  BTM allows only first registration.
**
** Returns          TRUE if registered OK, else FALSE
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_SecRegister (tBTM_APPL_INFO *p_cb_info);


/*******************************************************************************
**
** Function         BTM_SecAddLinkKeyNotifyCallback
**
** Description      Profiles can register to be notified when a new Link Key 
**                  is generated per connection (up to BTM_SEC_MAX_LINK_KEY_CALLBACKS).
**
** Returns          TRUE if registered OK, else FALSE
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_SecAddLinkKeyNotifyCallback (tBTM_LINK_KEY_CALLBACK *p_callback);


/*******************************************************************************
**
** Function         BTM_SecDeleteLinkKeyNotifyCallback
**
** Description      A profile can deregister notification when a new Link Key 
**                  is generated per connection.
**
** Returns          TRUE if OK, else FALSE
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_SecDeleteLinkKeyNotifyCallback (tBTM_LINK_KEY_CALLBACK *p_callback);


/*******************************************************************************
**
** Function         BTM_SecAddRmtNameNotifyCallback
**
** Description      Profiles can register to be notified when name of the  
**                  remote device is resolved (up to BTM_SEC_MAX_RMT_NAME_CALLBACKS).
**
** Returns          TRUE if registered OK, else FALSE
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_SecAddRmtNameNotifyCallback (tBTM_RMT_NAME_CALLBACK *p_callback);


/*******************************************************************************
**
** Function         BTM_SecDeleteRmtNameNotifyCallback
**
** Description      A profile can deregister notification when a new Link Key 
**                  is generated per connection.
**
** Returns          TRUE if OK, else FALSE
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_SecDeleteRmtNameNotifyCallback (tBTM_RMT_NAME_CALLBACK *p_callback);


/*******************************************************************************
**
** Function         BTM_SecSetConnectFilterCallback
**
** Description      Host can register to be asked whenever an HCI connection 
**                  request is received.  In the registered function host 
**                  suppose to check connectibility filters.  Yes/No result 
**                  should be returned synchronously.
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_SecSetConnectFilterCallback (tBTM_FILTER_CB *p_callback);


/*******************************************************************************
**
** Function         BTM_SetSecurityMode
**
** Description      Set security mode for the device
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_SetSecurityMode (UINT8 sec_mode);


/*******************************************************************************
**
** Function         BTM_SetPinType
**
** Description      Set PIN type for the device.  
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_SetPinType (UINT8 pin_type, PIN_CODE pin_code, UINT8 pin_code_len);


/*******************************************************************************
**
** Function         BTM_SetPairableMode 
**
** Description      Enable or disable pairing
**
** Parameters       allow_pairing - (TRUE or FALSE) whether or not the device
**                      allows pairing.
**                  connect_only_paired - (TRUE or FALSE) whether or not to
**                      only allow paired devices to connect.
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_SetPairableMode (BOOLEAN allow_pairing, BOOLEAN connect_only_paired);


/*******************************************************************************
**
** Function         BTM_SetSecurityLevel
**
** Description      Register service security level with Security Manager.  Each
**                  service must register its requirements regardless of the
**                  security level that is used.  This API is called once for originators
**                  nad again for acceptors of connections.
**
** Returns          TRUE if registered OK, else FALSE
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_SetSecurityLevel (BOOLEAN is_originator, char *p_name,
                                             UINT8 service_id, UINT8 sec_level,
                                             UINT16 psm, UINT32 mx_proto_id,
                                             UINT32 mx_chan_id);


/*******************************************************************************
**
** Function         BTM_SecClrService
**
** Description      Removes specified service record(s) from the security database.
**                  All service records with the specified name are removed.
**                  Typically used only by devices with limited RAM so that it can
**                  reuse an old security service record.
**                          records (except SDP).
**
** Returns          Number of records that were freed.
**
*******************************************************************************/
BTM_API extern UINT8 BTM_SecClrService (UINT8 service_id);


/*******************************************************************************
**
** Function         BTM_SecAddDevice
**
** Description      Add/modify device.  This function will be normally called
**                  during host startup to restore all required information
**                  stored in the NVRAM.
**                  dev_class, bd_name, link_key, and features are NULL if unknown
**
** Returns          TRUE if added OK, else FALSE
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_SecAddDevice (BD_ADDR bd_addr, DEV_CLASS dev_class,
                                         BD_NAME bd_name, BD_FEATURES features,
                                         UINT32 trusted_mask[], LINK_KEY link_key);


/*******************************************************************************
**
** Function         BTM_SecDeleteDevice
**
** Description      Free resources associated with the device.
**
** Returns          TRUE if rmoved OK, FALSE if not found
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_SecDeleteDevice (BD_ADDR bd_addr);


/*******************************************************************************
**
** Function         BTM_SecUseMasterLinkKey
**
** Description      This function is called to tell master of the piconet to 
**                  switch to master link key
**
** Returns          BTM_SUCCESS if command is successully initiated
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SecUseMasterLinkKey (BOOLEAN use_master_key);


/*******************************************************************************
**
** Function         BTM_SetMasterKeyCompCback
**
** Description      This function is called to register for the master key complete
**                  status event.
**
** Parameters:      mkey_cback - callback registered with the security manager
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_SetMasterKeyCompCback(tBTM_MKEY_CALLBACK *mkey_cback );


/*******************************************************************************
**
** Function         BTM_SecGetDeviceLinkKey
**
** Description      This function is called to obtain link key for the device
**                  it returns BTM_SUCCESS if link key is available, or
**                  BTM_UNKNOWN_ADDR if Security Manager does not know about
**                  the device or device record does not contain link key info
**
** Returns          BTM_SUCCESS if successful, otherwise error code
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SecGetDeviceLinkKey (BD_ADDR bd_addr,
                                                    LINK_KEY link_key);


/*******************************************************************************
**
** Function         BTM_PINCodeReply
**
** Description      This function is called after Security Manager submitted
**                  PIN code request to the UI.
**
** Parameters:      bd_addr      - Address of the device for which PIN was requested
**                  res          - result of the operation BTM_SUCCESS if success 
**                  pin_len      - length in bytes of the PIN Code
**                  p_pin        - pointer to array with the PIN Code
**                  trusted_mask - bitwise OR of trusted services (array of UINT32)
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_PINCodeReply (BD_ADDR bd_addr, UINT8 res, UINT8 pin_len,
                                      UINT8 *p_pin, UINT32 trusted_mask[]);


/*******************************************************************************
**
** Function         BTM_DeviceAuthorized
**
** Description      This function is called after Security Manager submitted
**                  authorization request to the UI.
**
** Parameters:      bd_addr     - Address of the device for which PIN was requested
**                  res         - result of the operation BTM_SUCCESS if success 
**
** Returns          void
**
*******************************************************************************/
BTM_API extern void BTM_DeviceAuthorized (BD_ADDR bd_addr, UINT8 res,
                                          UINT32 trusted_mask[]);


/*******************************************************************************
**
** Function         BTM_SecBond
**
** Description      This function is called to perform bonding with peer device.
**
** Returns          BTM_CMD_STARTED if successfully initiated, otherwise error
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SecBond (BD_ADDR bd_addr, UINT8 pin_len,
                                        UINT8 *p_pin, UINT32 trusted_mask[]);

/*******************************************************************************
**
** Function         BTM_SetEncryption
**
** Description      This function is called to ensure that connection is 
**                  encrypted.  Should be called only on an open connection.
**                  Typically only needed for connections that first want to
**                  bring up unencrypted links, then later encrypt them.
**
** Parameters:      bd_addr       - Address of the peer device
**                  p_callback    - Pointer to callback function called if
**                                  this function returns PENDING after required
**                                  procedures are completed.  Can be set to NULL
**                                  if status is not desired.
**                  p_ref_data    - pointer to any data the caller wishes to receive
**                                  in the callback function upon completion.
*                                   can be set to NULL if not used.
**
** Returns          BTM_SUCCESS   - already encrypted
**                  BTM_PENDING   - command will be returned in the callback
**                  BTM_WRONG_MODE- connection not up.
**                  BTM_BUSY      - security procedures are currently active
**                  BTM_MODE_UNSUPPORTED - if security manager not linked in.
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetEncryption (BD_ADDR bd_addr, tBTM_SEC_CBACK *p_callback,
                               void *p_ref_data);

/*******************************************************************************
**
** Function         BTM_SecReadDevName
**
** Description      Looks for the device name in the security database for the
**                  specified BD address.
**
** Returns          Pointer to the name or NULL
**
*******************************************************************************/
BTM_API extern char *BTM_SecReadDevName (BD_ADDR bd_addr);


/*****************************************************************************
**  POWER MANAGEMENT FUNCTIONS
*****************************************************************************/
/*******************************************************************************
**
** Function         BTM_PmRegister
**
** Description      register or deregister with power manager
**
** Returns          BTM_SUCCESS if successful,
**                  BTM_NO_RESOURCES if no room to hold registration
**                  BTM_ILLEGAL_VALUE
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_PmRegister (UINT8 mask, UINT8 *p_pm_id,
                                           tBTM_PM_STATUS_CBACK *p_cb);


/*******************************************************************************
**
** Function         BTM_SetPowerMode
**
** Description      store the mode in control block or
**                  alter ACL connection behavior.
**
** Returns          BTM_SUCCESS if successful,
**                  BTM_UNKNOWN_ADDR if bd addr is not active or bad
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_SetPowerMode (UINT8 pm_id, BD_ADDR remote_bda,
                                             tBTM_PM_PWR_MD *p_mode);


/*******************************************************************************
**
** Function         BTM_ReadPowerMode
**
** Description      This returns the current mode for a specific
**                  ACL connection.
**
** Input Param      remote_bda - device address of desired ACL connection
**
** Output Param     p_mode - address where the current mode is copied into.
**                          BTM_ACL_MODE_NORMAL
**                          BTM_ACL_MODE_HOLD
**                          BTM_ACL_MODE_SNIFF
**                          BTM_ACL_MODE_PARK
**                          (valid only if return code is BTM_SUCCESS)
**
** Returns          BTM_SUCCESS if successful,
**                  BTM_UNKNOWN_ADDR if bd addr is not active or bad
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ReadPowerMode (BD_ADDR remote_bda,
                                              tBTM_PM_MODE *p_mode);


/*******************************************************************************
**
** Function         BTM_IsPowerManagerOn
**
** Description      This function is called to check if power manager is included.
**                  in the BTE version.
**
** Returns          TRUE if power manager is compiled in, otherwise FALSE.
**
*******************************************************************************/
BTM_API extern BOOLEAN BTM_IsPowerManagerOn (void);


/*******************************************************************************
**
** Function         BTM_GetHCIConnHandle
**
** Description      This function is called to get the handle for an ACL connection
**                  to a specific remote BD Address.
**
** Returns          the handle of the connection, or 0xFFFF if none.
**
*******************************************************************************/
BTM_API extern UINT16 BTM_GetHCIConnHandle (BD_ADDR remote_bda);


/*******************************************************************************
**
** Function         BTM_ReadStoredLinkKey
**
** Description      This function is called to obtain link key for the specified
**                  device from the NVRAM storage attached to the Bluetooth
**                  controller.
**
** Parameters:      bd_addr      - Address of the device 
**                  p_cb         - Call back function to be called to return
**                                 the results
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_ReadStoredLinkKey (BD_ADDR bd_addr,	tBTM_CMPL_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_WriteStoredLinkKey
**
** Description      This function is called to write link keys for the specified
**                  device addresses to the NVRAM storage attached to the Bluetooth
**                  controller.
**
** Parameters:      num_keys     - Number of link keys
**                  bd_addr      - Addresses of the devices
**                  link_key     - Link Keys to be stored
**                  p_cb         - Call back function to be called to return
**                                 the results
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_WriteStoredLinkKey (UINT8 num_keys,
                                    BD_ADDR *bd_addr,
                                    LINK_KEY *link_key,
                                    tBTM_CMPL_CB *p_cb);


/*******************************************************************************
**
** Function         BTM_DeleteStoredLinkKey
**
** Description      This function is called to delete link key for the specified
**                  device addresses from the NVRAM storage attached to the Bluetooth
**                  controller.
**
** Parameters:      bd_addr      - Addresses of the devices
**                  p_cb         - Call back function to be called to return
**                                 the results
**
*******************************************************************************/
BTM_API extern tBTM_STATUS BTM_DeleteStoredLinkKey(BD_ADDR bd_addr, tBTM_CMPL_CB *p_cb);


#ifdef __cplusplus
}
#endif

#endif /* BTM_API_H */

