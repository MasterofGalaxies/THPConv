/****************************************************************************
**
**  Name:       bta_hh_api.h
**
**  Function:   this file contains HID HOST side API definitions
**
**  Copyright (c) 2002-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef BTA_HH_API_H
#define BTA_HH_API_H

#include <private/bte/bta/bta_api.h>
#include <private/bte/stack/hidh_api.h>

/*****************************************************************************
**  Constants and Type Definitions
*****************************************************************************/
#ifndef BTA_HH_DEBUG
#define BTA_HH_DEBUG    FALSE
#endif

/* BTA HID Host callback events */
#define BTA_HH_ENABLE_EVT       0       /* HH enabled */
#define BTA_HH_DISABLE_EVT      1       /* HH disabled */
#define BTA_HH_OPEN_EVT         2       /* connection opened */
#define BTA_HH_CLOSE_EVT        3       /* connection closed */
#define BTA_HH_GET_RPT_EVT      4       /* BTA_HhGetReport callback */
#define BTA_HH_SET_RPT_EVT      5       /* BTA_HhSetReport callback */    
#define BTA_HH_GET_PROTO_EVT    6       /* BTA_GetProtoMode callback */
#define BTA_HH_SET_PROTO_EVT    7       /* BTA_HhSetProtoMode callback */ 
#define BTA_HH_GET_IDLE_EVT     8       /* BTA_HhGetIdle comes callback */
#define BTA_HH_SET_IDLE_EVT     9       /* BTA_HhSetIdle finish callback */ 
#define BTA_HH_GET_DSCP_EVT     10      /* Get report descripotor */    
#define BTA_HH_ADD_DEV_EVT      11      /* Add Device callback */
#define BTA_HH_RMV_DEV_EVT      12      /* remove device finished */
#define BTA_HH_VC_UNPLUG_EVT    13      /* virtually unplugged */
#define BTA_HH_API_ERR_EVT      14      /* API error is caught */
#define BTA_HH_ACL_QUEUE_INFO_EVT 15    /* ACL queue info, in response to BTA_HhGetAclQueueInfo */
typedef UINT16 tBTA_HH_EVT;

/* defined the minimum offset */
#define BTA_HH_MIN_OFFSET       L2CAP_MIN_OFFSET+1

#define BTA_HH_MAX_KNOWN        HID_HOST_MAX_DEVICES 
/* invalid device handle */
#define BTA_HH_INVALID_HANDLE   0xff

/* type of protocol mode */
#define BTA_HH_PROTO_RPT_MODE                   (0x00)
#define BTA_HH_PROTO_BOOT_MODE                  (0x01)
typedef UINT8   tBTA_HH_PROTO_MODE;

enum
{
    BTA_HH_KEYBD_RPT_ID  =               1,
    BTA_HH_MOUSE_RPT_ID
};
typedef UINT8 tBTA_HH_BOOT_RPT_ID;

/* type of devices, bit mask */
#define BTA_HH_DEVT_UNKNOWN      0x00
#define BTA_HH_DEVT_JOS          0x01           /* joy stick */   
#define BTA_HH_DEVT_GPD          0x02           /* game pad */
#define BTA_HH_DEVT_RMC          0x03           /* remote control */
#define BTA_HH_DEVT_SED          0x04           /* sensing device */
#define BTA_HH_DEVT_DGT          0x05           /* Digitizer tablet */
#define BTA_HH_DEVT_CDR          0x06           /* card reader */
#define BTA_HH_DEVT_KBD          0x10           /* keyboard */  
#define BTA_HH_DEVT_MIC          0x20           /* pointing device */
#define BTA_HH_DEVT_COM          0x30           /* Combo keyboard/pointing */
#define BTA_HH_DEVT_OTHER        0x80
typedef UINT8  tBTA_HH_DEVT;

/* key board scan code translation */
/*
 * Virtual Keys, Standard Set mapping from windows.h
 */
#define BTA_HH_VK_LBUTTON        0x01           /* left mouse */
#define BTA_HH_VK_RBUTTON        0x02           /* right mouse */
#define BTA_HH_VK_MBUTTON        0x04           /* Middle mouse button */

#define BTA_HH_VK_BACK           0x08           /* same as ASCII */
#define BTA_HH_VK_TAB            0x09
#define BTA_HH_VK_RETURN         0x0D
#define BTA_HH_VK_ESCAPE         0x1B
#define BTA_HH_VK_SPACE          0x20

/* Windows Virtual Keys Standard Set */
#define BTA_HH_VK_PRIOR          0x21            
#define BTA_HH_VK_NEXT           0x22
#define BTA_HH_VK_END            0x23
#define BTA_HH_VK_HOME           0x24
#define BTA_HH_VK_LEFT           0x25
#define BTA_HH_VK_UP             0x26
#define BTA_HH_VK_RIGHT          0x27
#define BTA_HH_VK_DOWN           0x28
#define BTA_HH_VK_SELECT         0x29
#define BTA_HH_VK_INSERT         0x2D
#define BTA_HH_VK_DELETE         0x2E
#define BTA_HH_VK_HELP           0x2F

#define BTA_HH_VK_QUOTE          0x62           /* " */
#define BTA_HH_VK_MULTIPLY       0x6A           /* * */ 
#define BTA_HH_VK_ADD            0x6B           /* + */
#define BTA_HH_VK_SUBTRACT       0x6D           /* - */
#define BTA_HH_VK_DECIMAL        0x6E           /* . */
#define BTA_HH_VK_DIVIDE         0x6F           /* / */

#define BTA_HH_VK_SEMICOLON      0xBA           /* ; */
#define BTA_HH_VK_EQUAL          0xBB           /* = */
#define BTA_HH_VK_COMMA          0xBC           /* , */
#define BTA_HH_VK_MINUS          0xBD           /* - */
#define BTA_HH_VK_PERIOD         0xBE           /* . */
#define BTA_HH_VK_SLASH          0xBF           /* / */
#define BTA_HH_VK_BACKQUOTE      0xC0           /* ` */

#define BTA_HH_VK_LBRACKET       0xDB           /* < */    
#define BTA_HH_VK_BACKSLASH      0xDC           /* \ */
#define BTA_HH_VK_RBRACKET       0xDD           /* > */
#define BTA_HH_VK_APOSTROPHE     0xDE           /* ' */

#define BTA_HH_VK_F1             0x70           /* VK_F1 */

/* BTA_HH_VK_0 thru BTA_HH_VK_9 are the same as ASCII '0' thru '9' (0x30 - 0x39) */
/* BTA_HH_VK_A thru BTA_HH_VK_Z are the same as ASCII 'A' thru 'Z' (0x41 - 0x5A) */

enum
{
    BTA_HH_OK,
    BTA_HH_HS_HID_NOT_READY,    /* handshake error : device not ready */
    BTA_HH_HS_INVALID_RPT_ID,   /* handshake error : invalid report ID */
    BTA_HH_HS_TRANS_NOT_SPT,    /* handshake error : transaction not spt */    
    BTA_HH_HS_INVALID_PARAM,    /* handshake error : invalid paremter */    
    BTA_HH_HS_ERROR,            /* handshake error : unspecified HS error */
    BTA_HH_ERR,                 /* general BTA HH error */
    BTA_HH_ERR_SDP,             /* SDP error */
    BTA_HH_ERR_PROTO,           /* SET_Protocol error, 
                                    only used in BTA_HH_OPEN_EVT callback */
    BTA_HH_ERR_DB_FULL,         /* device database full error, used in 
                                   BTA_HH_OPEN_EVT/BTA_HH_ADD_DEV_EVT */
    BTA_HH_ERR_TOD_UNSPT,       /* type of device not supported */
    BTA_HH_ERR_NO_RES,          /* out of system resources */
    BTA_HH_ERR_AUTH_FAILED,     /* authentication fail */
	BTA_HH_ERR_HDL
};
typedef UINT8 tBTA_HH_STATUS;


#define BTA_HH_VIRTUAL_CABLE           HID_VIRTUAL_CABLE        
#define BTA_HH_NORMALLY_CONNECTABLE    HID_NORMALLY_CONNECTABLE 
#define BTA_HH_RECONN_INIT             HID_RECONN_INIT          
#define BTA_HH_SDP_DISABLE             HID_SDP_DISABLE          
#define BTA_HH_BATTERY_POWER           HID_BATTERY_POWER        
#define BTA_HH_REMOTE_WAKE             HID_REMOTE_WAKE          
#define BTA_HH_SUP_TOUT_AVLBL          HID_SUP_TOUT_AVLBL       
#define BTA_HH_SEC_REQUIRED             HID_SEC_REQUIRED        
typedef UINT16 tBTA_HH_ATTR_MASK;

/* supported type of device and corresponding application ID */
typedef struct
{
    tBTA_HH_DEVT        tod;        /* type of device               */
    UINT8               app_id;     /* corresponding application ID */
}tBTA_HH_SPT_TOD;

/* configuration struct */
typedef struct 
{
    UINT8                max_devt_spt; /* max number of types of devices spt */
    tBTA_HH_SPT_TOD     *p_devt_list;  /* supported types of device list     */
	UINT16				sdp_db_size;
}tBTA_HH_CFG;

enum
{
    BTA_HH_RPTT_RESRV,      /* reserved         */
    BTA_HH_RPTT_INPUT,      /* input report     */
    BTA_HH_RPTT_OUTPUT,     /* output report    */
    BTA_HH_RPTT_FEATURE     /* feature report   */
};
typedef UINT8 tBTA_HH_RPT_TYPE;

/* HID_CONTROL operation code used in BTA_HhSendCtrl()
*/
enum
{
    BTA_HH_CTRL_NOP         = 0 + HID_PAR_CONTROL_NOP ,/* mapping from BTE */
    BTA_HH_CTRL_HARD_RESET,                            /* hard reset       */
    BTA_HH_CTRL_SOFT_RESET,                            /* soft reset       */
    BTA_HH_CTRL_SUSPEND,                               /* enter suspend    */
    BTA_HH_CTRL_EXIT_SUSPEND,                          /* exit suspend     */
    BTA_HH_CTRL_VIRTUAL_CABLE_UNPLUG                   /* virtual unplug   */
};
typedef UINT8 tBTA_HH_TRANS_CTRL_TYPE;

/* report descriptor information */
typedef tHID_DEV_DSCP_INFO tBTA_HH_DEV_DSCP_INFO;

/* callback event data for BTA_HH_OPEN_EVT */
typedef struct
{
    BD_ADDR         bda;                /* HID device bd address    */
    tBTA_HH_STATUS  status;             /* operation status         */
    UINT8           handle;             /* device handle            */
} tBTA_HH_CONN;

typedef tBTA_HH_CONN tBTA_HH_DEV_INFO;

/* callback event data */
typedef struct
{
    tBTA_HH_STATUS              status;     /* operation status         */
    UINT8                       handle;     /* device handle            */
} tBTA_HH_CBDATA;

/* callback event data */
typedef struct
{
    tBTA_HH_STATUS              status;         /* operation status         */
    UINT8                       handle;         /* device handle            */
    UINT8                       link_quality;   /* link quality (0 to 255)  */
} tBTA_HH_LINK_QUALITY;

/* parsed boot mode keyboard report */
typedef struct
{
    UINT8               this_char;          /* virtual key code     */
    BOOLEAN             caps_lock;          /* is caps locked       */
    BOOLEAN             upper;              /* is Shift key pressed */
    BOOLEAN             ctrl;               /* is Ctrl key pressed  */
    BOOLEAN             alt;                /* is Alt key pressed   */
	BOOLEAN             num_lock;           /* is Num key pressed   */
} tBTA_HH_KEYBD_RPT;

/* parsed boot mode mouse report */
typedef struct
{
    UINT8               mouse_button;       /* mouse button is clicked   */
    INT8                delta_x;            /* displacement x            */
    INT8                delta_y;            /* displacement y            */
}tBTA_HH_MICE_RPT;

/* parsed Boot report */
typedef struct
{
    tBTA_HH_BOOT_RPT_ID dev_type;           /* type of device report */
    union
    {
        tBTA_HH_KEYBD_RPT   keybd_rpt;      /* keyboard report      */
        tBTA_HH_MICE_RPT    mice_rpt;       /* mouse report         */
    }                   data_rpt;           
} tBTA_HH_BOOT_RPT;

/* handshake data */
typedef struct
{
    tBTA_HH_STATUS  status;                 /* handshake status */
    UINT8           handle;                 /* device handle    */
    union
    {
        tBTA_HH_PROTO_MODE      proto_mode; /* GET_PROTO_EVT :protocol mode */
        BT_HDR                  rpt_data;   /* GET_RPT_EVT   : report data  */
        UINT8                   idle_rate;  /* GET_IDLE_EVT  : idle rate    */
    }               rsp_data;

}tBTA_HH_HSDATA;


/* queue info */
typedef struct
{
    UINT8 handle;                   /* device handle */
    UINT16 num_queued;              /* Number of buffers queued by l2cap */
    UINT16 num_not_acked;           /* Number of buffers queued in baseband (sent to baseband, but have not received 'number of packets complete event') */
} tBTA_HH_ACL_QUEUE;

/* Data for BTA_HH_ACL_QUEUE_INFO_EVT */
typedef struct
{
    UINT16 num_avail_buffs;         /* Number of available ACL buffers */
    UINT16 num_buffs;               /* Number of ACL buffers that the controller can handle */
    UINT16 num_links;               /* Number of active links */
    tBTA_HH_ACL_QUEUE queue_info[MAX_L2CAP_LINKS];  /* Array of queue info */
} tBTA_HH_ACL_QUEUE_INFO;

/* union of data associated with HD callback */
typedef union
{
	tBTA_HH_DEV_INFO		dev_info;			/* BTA_HH_ADD_DEV_EVT, BTA_HH_RMV_DEV_EVT	*/
    tBTA_HH_CONN            conn;               /* BTA_HH_OPEN_EVT      */
    tBTA_HH_CBDATA          dev_status;         /* BTA_HH_CLOSE_EVT, 
                                                   BTA_HH_SET_PROTO_EVT
                                                   BTA_HH_SET_RPT_EVT
                                                   BTA_HH_SET_IDLE_EVT  */

    tBTA_HH_STATUS          status;             /* BTA_HH_ENABLE_EVT */
    tBTA_HH_DEV_DSCP_INFO   dscp_info;          /* BTA_HH_GET_DSCP_EVT */
    tBTA_HH_HSDATA          hs_data;            /* GET_ transaction callback
                                                   BTA_HH_GET_RPT_EVT           
                                                   BTA_HH_GET_PROTO_EVT 
                                                   BTA_HH_GET_IDLE_EVT */
    tBTA_HH_ACL_QUEUE_INFO  acl_queue_info;     /* BTA_HH_ACL_QUEUE_INFO_EVT */
} tBTA_HH;

/* BTA HH callback function */
typedef void (tBTA_HH_CBACK) (tBTA_HH_EVT event, tBTA_HH *p_data); 


/*****************************************************************************
**  External Function Declarations
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
**
** Function         BTA_HhRegister
**
** Description      This function enable HID host and registers HID-Host with 
**                  lower layers.
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhEnable (tBTA_SEC sec_mask, tBTA_HH_CBACK *p_cback);

/*******************************************************************************
**
** Function         BTA_HhDeregister
**
** Description      This function is called when the host is about power down.
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhDisable(void);

/*******************************************************************************
**
** Function         BTA_HhOpen
**
** Description      This function is called to start an inquiry and read SDP 
**                  record of responding devices; connect to a device if only 
**                  one active HID device is found.
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhOpen (BD_ADDR dev_bda, tBTA_HH_PROTO_MODE mode, 
                                tBTA_SEC sec_mask);

/*******************************************************************************
**
** Function         BTA_HhClose
**
** Description      This function disconnects the device.
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhClose(UINT8 dev_handle);

/*******************************************************************************
**
** Function         BTA_HhSetProtoMode
**
** Description      This function set the protocol mode at specified HID handle
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhSetProtoMode(UINT8 handle, tBTA_HH_PROTO_MODE t_type);

/*******************************************************************************
**
** Function         BTA_HhGetProtoMode
**
** Description      This function get the protocol mode of a specified HID device.
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhGetProtoMode(UINT8 dev_handle);
/*******************************************************************************
**
** Function         BTA_HhSetReport
**
** Description      send SET_REPORT to device.
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhSetReport(UINT8 dev_handle, tBTA_HH_RPT_TYPE r_type, 
                                        BT_HDR *p_data);

/*******************************************************************************
**
** Function         BTA_HhGetReport
**
** Description      Send a GET_REPORT to HID device.              
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhGetReport(UINT8 dev_handle, tBTA_HH_RPT_TYPE r_type,  
                                    UINT8 rpt_id, UINT16 buf_size);
/*******************************************************************************
**
** Function         BTA_HhSetIdle
**
** Description      send SET_IDLE to device.
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhSetIdle(UINT8 dev_handle, UINT16 idle_rate);

/*******************************************************************************
**
** Function         BTA_HhGetIdle
**
** Description      Send a GET_IDLE to HID device.              
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhGetIdle(UINT8 dev_handle);
/*******************************************************************************
**
** Function         BTA_HhSendCtrl
**
** Description      Send HID_CONTROL request to a HID device.
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhSendCtrl(UINT8 dev_handle, 
                                   tBTA_HH_TRANS_CTRL_TYPE c_type);

/*******************************************************************************
**
** Function         BTA_HhSendData
**
** Description      Send DATA transaction to a HID device.
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhSendData(UINT8 dev_handle, BT_HDR *p_buf);

/*******************************************************************************
**
** Function         BTA_HhGetDscpInfo
**
** Description      Get report descriptor of the device
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhGetDscpInfo(UINT8 dev_handle);

/*******************************************************************************
**
** Function         BTA_HhAddDev
**
** Description      Add a virtually cabled device into HID-Host device list 
**                  to manage and assign a device handle for future API call, 
**                  host applciation call this API at start-up to initialize its 
**                  virtually cabled devices.                 
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhAddDev(BD_ADDR bda, tBTA_HH_ATTR_MASK attr_mask, 
                                 UINT8 sub_class, UINT8 app_id, 
                                 tBTA_HH_DEV_DSCP_INFO dscp_info);
/*******************************************************************************
**
** Function         BTA_HhRemoveDev
**
** Description      Remove a device from the HID host devices list.               
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhRemoveDev(UINT8 dev_handle );

/*******************************************************************************
**
** Function         BTA_HhGetAclQueueInfo
**
** Description      Get number of buffers waiting to be transmitted in the l2c
**                  xmit queues (info returned as a BTA_HH_ACL_QUEUE_INFO_EVT).               
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhGetAclQueueInfo(void);

/*******************************************************************************
**
**              Parsing Utility Functions      
**
*******************************************************************************/
/*******************************************************************************
**
** Function         BTA_HhParseBootRpt
**
** Description      This utility function parse a boot mode report.
**
** Returns          void
**
*******************************************************************************/
BTA_API extern void BTA_HhParseBootRpt(tBTA_HH_BOOT_RPT *p_data, UINT8 *p_report, 
                                       UINT16 report_len);

#ifdef __cplusplus
}
#endif

#endif  /* BTA_HH_API_H */
