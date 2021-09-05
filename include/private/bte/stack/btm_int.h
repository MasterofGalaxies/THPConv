/*****************************************************************************
**
**  Name:          btm_int.h
**
**  Description:   this file contains the main Bluetooth Manager (BTM)
**                 internal definitions.
**
**  Copyright (c) 1999-2005, Broadcom Corp., All Rights Reserved
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
******************************************************************************/
#ifndef BTM_INT_H
#define BTM_INT_H

#include <private/bte/common/target.h>
#include <private/bte/gki.h>
#include <private/bte/stack/hcidefs.h>

#if RFCOMM_INCLUDED == TRUE
#include <private/bte/stack/rfcdefs.h>
#endif

#include <private/bte/stack/btm_api.h>

#if BTM_MAX_LOC_BD_NAME_LEN > 0
typedef char tBTM_LOC_BD_NAME[BTM_MAX_LOC_BD_NAME_LEN + 1];
#endif

/* Definitions for Server Channel Number (SCN) management
*/
#define BTM_MAX_SCN      PORT_MAX_RFC_PORTS

/* Define masks for supported and exception 2.0 ACL packet types
*/
#define BTM_ACL_SUPPORTED_PKTS_MASK      (HCI_PKT_TYPES_MASK_DM1        | \
                                          HCI_PKT_TYPES_MASK_DH1        | \
                                          HCI_PKT_TYPES_MASK_DM3        | \
                                          HCI_PKT_TYPES_MASK_DH3        | \
                                          HCI_PKT_TYPES_MASK_DM5        | \
                                          HCI_PKT_TYPES_MASK_DH5)

#define BTM_ACL_EXCEPTION_PKTS_MASK      (HCI_PKT_TYPES_MASK_NO_2_DH1   | \
                                          HCI_PKT_TYPES_MASK_NO_3_DH1   | \
                                          HCI_PKT_TYPES_MASK_NO_2_DH3   | \
                                          HCI_PKT_TYPES_MASK_NO_3_DH3   | \
                                          HCI_PKT_TYPES_MASK_NO_2_DH5   | \
                                          HCI_PKT_TYPES_MASK_NO_3_DH5)

/* Define a Macro that returns TRUE if the chipset is Broadcom 2035 based on hci revision */
#define BTM_IS_BRCM_2035() ((((btm_cb.devcb.local_version.manufacturer) == LMP_COMPID_BROADCOM) &&   \
                            ((btm_cb.devcb.local_version.hci_version) < HCI_PROTO_VERSION_2_0)) ? TRUE : FALSE)

/* Define the ACL Management control structure
*/
typedef struct
{
    UINT16          hci_handle;
    UINT16          pkt_types_mask;
    UINT16          restore_pkt_types;  /* when coming in/out of SCO connection restore the packet types */
    UINT16          clock_offset;
    BD_ADDR         remote_addr;
    DEV_CLASS       remote_dc;
    BD_NAME         remote_name;

    UINT16          manufacturer;
    UINT16          lmp_subversion;
    UINT16          link_super_tout;
    BD_FEATURES     features;           /* Features suported by the device    */
    UINT8           lmp_version;

    BOOLEAN         in_use;
    UINT8           link_role;

#define BTM_ACL_SWITCH_STATE_IDLE               0
#define BTM_ACL_SWITCH_STATE_MODE_CHANGE        1
#define BTM_ACL_SWITCH_STATE_ENCRYPTION_OFF     2
#define BTM_ACL_SWITCH_STATE_SWITCHING          3
#define BTM_ACL_SWITCH_STATE_ENCRYPTION_ON      4
#define BTM_ACL_SWITCH_STATE_IN_PROGRESS        5

    UINT8           switch_role_state;          
#if BTM_PWR_MGR_INCLUDED == FALSE
    UINT8           mode;
#endif /* BTM_PWR_MGR_INCLUDED */
} tACL_CONN;

/*****************************************************
** TIMER Definitions
******************************************************/
#define TT_DEV_RESET     1
#define TT_DEV_RLN       2
#define TT_DEV_RLNKP     4              /* Read Link Policy Settings */

/* Define the Device Management control structure
*/
typedef struct
{
    tBTM_DEV_STATUS_CB  *p_dev_status_cb;   /* Device status change callback        */
    tBTM_VS_EVT_CB      *p_vend_spec_cb;    /* Register for vendor specific events  */

    tBTM_CMPL_CB        *p_stored_link_key_cmpl_cb;   /* Read/Write/Delete stored link key    */

    TIMER_LIST_ENT       reset_timer;
    tBTM_CMPL_CB        *p_reset_cmpl_cb;   /* Callback function to be called       */
                                            /* when startup of the device is done   */
    TIMER_LIST_ENT       rln_timer;
    tBTM_CMPL_CB        *p_rln_cmpl_cb;     /* Callback function to be called when  */
                                            /* read local name function complete    */
    TIMER_LIST_ENT       rlinkp_timer;
    tBTM_CMPL_CB        *p_rlinkp_cmpl_cb;  /* Callback function to be called when  */
                                            /* read link policy function completes  */
    TIMER_LIST_ENT       rssi_timer;
    tBTM_CMPL_CB        *p_rssi_cmpl_cb;    /* Callback function to be called when  */
                                            /* read rssi function completes         */
    TIMER_LIST_ENT       lnk_quality_timer;
    tBTM_CMPL_CB        *p_lnk_qual_cmpl_cb;/* Callback function to be called when  */
                                            /* read link quality function completes */
    TIMER_LIST_ENT       qossu_timer;
    tBTM_CMPL_CB        *p_qossu_cmpl_cb;   /* Callback function to be called when  */
                                            /* qos setup function completes         */
    tBTM_CMPL_CB        *p_vsc_cmpl_cb;     /* Callback function to be called when  */
                                            /* vendor specific command complete     */

    tBTM_ROLE_SWITCH_CMPL switch_role_ref_data;
    tBTM_CMPL_CB        *p_switch_role_cb;  /* Callback function to be called when  */
                                            /* requested switch role is completed   */

    BD_ADDR              local_addr;        /* BD_ADDR of the local device          */
    tBTM_VERSION_INFO    local_version;     /* Local Version Information            */
    BD_FEATURES          local_features;    /* Local features bit mask              */
    DEV_CLASS            dev_class;         /* Local device class                   */
    UINT16               page_timeout;      /* Current page timeout (in ms)         */

#define BTM_DEV_STATE_WAIT_RESET_CMPLT  0
#define BTM_DEV_STATE_WAIT_AFTER_RESET  1
#define BTM_DEV_STATE_WAIT_HCI_BUF_SIZE 2
#define BTM_DEV_STATE_WAIT_VERSION      3
#define BTM_DEV_STATE_WAIT_FEATURES     4
#define BTM_DEV_STATE_READY             5

    UINT8                state;
    UINT8                retry_count;       /* Number of retries                    */
    BOOLEAN              vsc_busy;          /* TRUE if busy w/ vendor specific cmd  */
} tBTM_DEVCB;

#define BTM_DISCVRY_USE_REM_ADDR    2   /* used for tBTM_DISCOVERY_VAR_ST.disc_active in the case where it does not use inq db */
/* Define the service discovery database area
*/
typedef struct
{
    TIMER_LIST_ENT disc_timer_ent;  /* the timer for discovery timeout */

    UINT16         num_uuid_filters;           /* Number of UUIds to filter    */
    tSDP_UUID      uuid_filters[SDP_MAX_UUID_FILTERS]; /* UUIDs to filter      */
    UINT16         num_attr_filters;           /* Number of attribute filters  */
    UINT16         attr_filters[SDP_MAX_ATTR_FILTERS]; /* Attributes to filter */

    tBTM_INQ_INFO  *p_cur_ii;       /* pointer to the current entry in the discovery database */
    tBTM_CMPL_CB   *p_disc_cmpl_cb; /* the callback routine for discovery complete */

        /*******************************************/
        /* IMPORTANT - this array MUST be aligned   */
        /* so leave the pointer just before it      */
        /*******************************************/

    UINT8          btm_db_area[BTM_DISCOVERY_DB_SIZE]; /* Discovery database */
    UINT8          disc_active;     /* if discovery is in progress */
} tBTM_DISCOVERY_VAR_ST;


/* Define the structures and constants used for inquiry
*/

/* Definitions of limits for inquiries */
#define BTM_PER_INQ_MIN_MAX_PERIOD      HCI_PER_INQ_MIN_MAX_PERIOD
#define BTM_PER_INQ_MAX_MAX_PERIOD      HCI_PER_INQ_MAX_MAX_PERIOD
#define BTM_PER_INQ_MIN_MIN_PERIOD      HCI_PER_INQ_MIN_MIN_PERIOD
#define BTM_PER_INQ_MAX_MIN_PERIOD      HCI_PER_INQ_MAX_MIN_PERIOD
#define BTM_MAX_INQUIRY_LENGTH          HCI_MAX_INQUIRY_LENGTH
#define BTM_MIN_INQUIRY_LEN             0x01

#if BTM_USE_INQ_RESULTS_FILTER == TRUE
typedef struct
{
    UINT32          inq_count;          /* Used for determining if a response has already been      */
                                        /* received for the current inquiry operation. (We do not   */
                                        /* want to flood the caller with multiple responses from    */
                                        /* the same device.                                         */
    BD_ADDR         bd_addr;
} tINQ_BDADDR;
#endif

typedef struct
{
    UINT32          time_of_resp;
    UINT32          inq_count;          /* "timestamps" the entry with a particular inquiry count   */
                                        /* Used for determining if a response has already been      */
                                        /* received for the current inquiry operation. (We do not   */
                                        /* want to flood the caller with multiple responses from    */
                                        /* the same device.                                         */
    tBTM_INQ_INFO   inq_info;
    BOOLEAN         in_use;

#if (BTM_INQ_AGE_BY_COUNT > 0)
    UINT8       not_found_count_down;
#endif
} tINQ_DB_ENT;

typedef struct
{
    tBTM_CMPL_CB *p_remname_cmpl_cb;

#define BTM_EXT_RMT_NAME_TIMEOUT    40
#define BTM_INQ_RMT_NAME_TIMEOUT    61
#define BTM_SEC_RMT_NAME_TIMEOUT    30  /* Timeout when getting remote name during security */
    TIMER_LIST_ENT  rmt_name_timer_ent;

    UINT16           discoverable_mode;
    UINT16           connectable_mode;
    UINT16           page_scan_window;
    UINT16           page_scan_period;
    UINT16           inq_scan_window;
    UINT16           inq_scan_period;
    UINT16           inq_scan_type;
    UINT16           page_scan_type;        /* current page scan type */

    BD_ADDR          remname_bda;           /* Name of bd addr for active remote name request */
#define BTM_RMT_NAME_INACTIVE       0
#define BTM_RMT_NAME_EXT            0x1     /* Initiated through API */
#define BTM_RMT_NAME_SEC            0x2     /* Initiated internally by security manager */
#define BTM_RMT_NAME_INQ            0x4     /* Remote name initiated internally by inquiry */
    UINT8            remname_active;        /* Origin of the request for remote name */

#if BTM_INQUIRY_INCLUDED == TRUE
    tBTM_CMPL_CB    *p_inq_cmpl_cb;
    tBTM_CMPL_CB    *p_inq_results_cb;
    tBTM_CMPL_CB    *p_inqfilter_cmpl_cb;   /* Called (if not NULL) after inquiry filter completed */
    tBTM_INQ_DB_CHANGE_CB *p_inq_change_cb; /* Inquiry database changed callback    */
    UINT32           inq_counter;           /* Counter incremented each time an inquiry completes */
                                            /* Used for determining whether or not duplicate devices */
                                            /* have responded to the same inquiry */
    TIMER_LIST_ENT   inq_timer_ent;
#if BTM_USE_INQ_RESULTS_FILTER == TRUE
    tINQ_BDADDR     *p_bd_db;               /* Pointer to memory that holds bdaddrs */
    UINT16           num_bd_entries;        /* Number of entries in database */
    UINT16           max_bd_entries;        /* Maximum number of entries that can be stored */
#endif
    tINQ_DB_ENT      inq_db[BTM_INQ_DB_SIZE];
    tBTM_INQ_PARMS   inqparms;              /* Contains the parameters for the current inquiry */
    tBTM_INQUIRY_CMPL inq_cmpl_info;        /* Status and number of responses from the last inquiry */

    UINT16           per_min_delay;         /* Current periodic minimum delay */
    UINT16           per_max_delay;         /* Current periodic maximum delay */
    BOOLEAN          inqfilt_active;
    UINT8            pending_filt_complete_event; /* to take care of btm_event_filter_complete corresponding to */
                                                  /* inquiry that has been cancelled*/
    UINT8            inqfilt_type;          /* Contains the inquiry filter type (BD ADDR, COD, or Clear) */

#define BTM_INQ_INACTIVE_STATE      0
#define BTM_INQ_CLR_FILT_STATE      1   /* Currently clearing the inquiry filter preceeding the inquiry request */
                                        /* (bypassed if filtering is not used)                                  */
#define BTM_INQ_SET_FILT_STATE      2   /* Sets the new filter (or turns off filtering) in this state */
#define BTM_INQ_ACTIVE_STATE        3   /* Actual inquiry or periodic inquiry is in progress */
#define BTM_INQ_REMNAME_STATE       4   /* Remote name requests are active  */

    UINT8            state;             /* Current state that the inquiry process is in */
    UINT8            inq_active;        /* Bit Mask indicating type of inquiry is active */
#endif /* BTM_INQUIRY_INCLUDED == TRUE */
} tBTM_INQUIRY_VAR_ST;

/* The MSB of the clock offset field indicates that the offset is valid if TRUE */
#define BTM_CLOCK_OFFSET_VALID      0x8000

/* Define the structures needed by security management
*/

#define BTM_SEC_INVALID_HANDLE  0xFFFF

typedef UINT8 *BTM_BD_NAME_PTR;                        /* Pointer to Device name */

/* Security callback is called by this unit when security 
**   procedures are completed.  Parameters are
**              BD Address of remote
**              Result of the operation
*/
typedef tBTM_SEC_CBACK tBTM_SEC_CALLBACK;

typedef void (tBTM_SCO_IND_CBACK) (UINT16 sco_inx) ;

/* MACROs to convert from SCO packet types mask to ESCO and back */
#define BTM_SCO_PKT_TYPE_MASK   (   HCI_PKT_TYPES_MASK_HV1      \
                                 |  HCI_PKT_TYPES_MASK_HV2      \
                                 |  HCI_PKT_TYPES_MASK_HV3)

/* Mask defining only the SCO types of an esco packet type */
#define BTM_ESCO_PKT_TYPE_MASK  (   HCI_ESCO_PKT_TYPES_MASK_HV1 \
                                 |  HCI_ESCO_PKT_TYPES_MASK_HV2 \
                                 |  HCI_ESCO_PKT_TYPES_MASK_HV3)

#define BTM_SCO_2_ESCO(scotype)  ((UINT16)(((scotype) & BTM_SCO_PKT_TYPE_MASK) >> 5))
#define BTM_ESCO_2_SCO(escotype) ((UINT16)(((escotype) & BTM_ESCO_PKT_TYPE_MASK) << 5))

/* Define masks for supported and exception 2.0 SCO packet types
*/
#define BTM_SCO_SUPPORTED_PKTS_MASK      (HCI_ESCO_PKT_TYPES_MASK_HV1       | \
                                          HCI_ESCO_PKT_TYPES_MASK_HV2       | \
                                          HCI_ESCO_PKT_TYPES_MASK_HV3       | \
                                          HCI_ESCO_PKT_TYPES_MASK_EV3       | \
                                          HCI_ESCO_PKT_TYPES_MASK_EV4       | \
                                          HCI_ESCO_PKT_TYPES_MASK_EV5)

#define BTM_SCO_EXCEPTION_PKTS_MASK      (HCI_ESCO_PKT_TYPES_MASK_NO_2_EV3  | \
                                          HCI_ESCO_PKT_TYPES_MASK_NO_3_EV3  | \
                                          HCI_ESCO_PKT_TYPES_MASK_NO_2_EV5  | \
                                          HCI_ESCO_PKT_TYPES_MASK_NO_3_EV5)


/* Define the structure that contains (e)SCO data */
typedef struct
{
    tBTM_ESCO_CBACK    *p_esco_cback;   /* Callback for eSCO events     */
    tBTM_ESCO_PARAMS    setup;
    tBTM_ESCO_DATA      data;           /* Connection complete information */
    UINT8               hci_status;
} tBTM_ESCO_INFO;

/* Define the structure used for SCO Management
*/
typedef struct
{
    tBTM_SCO_CB     *p_conn_cb;         /* Callback for when connected  */
    tBTM_SCO_CB     *p_disc_cb;         /* Callback for when disconnect */
    UINT16           state;             /* The state of the SCO link    */
    UINT16           hci_handle;        /* HCI Handle                   */
    BOOLEAN          is_orig;           /* TRUE if the originator       */
    BOOLEAN          rem_bd_known;      /* TRUE if remote BD addr known */
    tBTM_ESCO_INFO   esco;              /* Current settings             */
} tSCO_CONN;

/* SCO Management control block */
typedef struct
{
    tBTM_SCO_IND_CBACK  *app_sco_ind_cb;
    tSCO_CONN            sco_db[BTM_MAX_SCO_LINKS];
    BD_ADDR              xfer_addr;
    UINT16               sco_disc_reason;
    tBTM_ESCO_PARAMS     def_esco_parms;
    BOOLEAN              esco_supported;    /* TRUE if 1.2 cntlr AND supports eSCO links */
    tBTM_SCO_TYPE        desired_sco_mode;
    tBTM_SCO_TYPE        xfer_sco_type;
} tSCO_CB;


#if BTM_SCO_INCLUDED == TRUE
extern void     btm_set_sco_ind_cback( tBTM_SCO_IND_CBACK *sco_ind_cb );
extern void     btm_accept_sco_link(UINT16 sco_inx, tBTM_ESCO_PARAMS *p_setup,
                                    tBTM_SCO_CB *p_conn_cb, tBTM_SCO_CB *p_disc_cb);
extern void     btm_reject_sco_link(UINT16 sco_inx );
#else
#define btm_accept_sco_link(sco_inx, p_setup, p_conn_cb, p_disc_cb)
#define btm_reject_sco_link(sco_inx)
#define btm_set_sco_ind_cback(sco_ind_cb)
#endif

/*
** Define structure for Security Service Record.
** A record exists for each service registered with the Security Manager 
*/
typedef struct
{
    UINT32          mx_proto_id;        /* Service runs over this multiplexer protocol */
    UINT32          orig_mx_chan_id;    /* Channel on the multiplexer protocol    */
    UINT32          term_mx_chan_id;    /* Channel on the multiplexer protocol    */
    UINT16          psm;                /* L2CAP PSM value */

#define BTM_SEC_IN_USE      0x80

    UINT8           security_flags;     /* Bitmap of required security features */
    UINT8           service_id;         /* Passed in authorization callback */
#if BTM_SEC_SERVICE_NAME_LEN > 0
    UINT8           orig_service_name[BTM_SEC_SERVICE_NAME_LEN + 1];
    UINT8           term_service_name[BTM_SEC_SERVICE_NAME_LEN + 1];
#endif
} tBTM_SEC_SERV_REC;

/*
** Define structure for Security Device Record.
** A record exists for each device authenticated with this device
*/
typedef struct
{
    tBTM_SEC_SERV_REC   *p_cur_service;
    tBTM_SEC_CALLBACK   *p_callback;
    void                *p_ref_data;
    UINT32               timestamp;         /* Timestamp of the last connection   */
    UINT32               trusted_mask[BTM_SEC_SERVICE_ARRAY_INDEX];  /* Bitwise OR of trusted services     */
    UINT16               hci_handle;        /* Handle to connection when exists   */
    UINT16               clock_offset;
    BD_ADDR              bd_addr;           /* BD_ADDR of the device              */
    DEV_CLASS            dev_class;         /* DEV_CLASS of the device            */
    LINK_KEY             link_key;          /* Device link key                    */

#define BTM_SEC_AUTHORIZED      0x01
#define BTM_SEC_AUTHENTICATED   0x02
#define BTM_SEC_ENCRYPTED       0x04
#define BTM_SEC_NAME_KNOWN      0x08
#define BTM_SEC_LINK_KEY_KNOWN  0x10

    tBTM_BD_NAME    sec_bd_name;        /* User friendly name of the device. (may be truncated to save space in dev_rec table) */
    UINT8           sec_flags;          /* Current device security state      */
    BD_FEATURES     features;           /* Features suported by the device    */

#define BTM_SEC_STATE_IDLE              0
#define BTM_SEC_STATE_AUTHENTICATING    1
#define BTM_SEC_STATE_ENCRYPTING        2
#define BTM_SEC_STATE_GETTING_NAME      3
#define BTM_SEC_STATE_AUTHORIZING       4
#define BTM_SEC_STATE_DISCONNECTING     5

    UINT8       sec_state;              /* Operating state                    */
    BOOLEAN     is_originator;          /* TRUE if device is originating connection */
    UINT8       security_required;      /* Security required for connection   */
    BOOLEAN     link_key_not_sent;      /* link key notification has not been sent waiting for name */
    UINT8       link_key_type;          /* Type of key used in pairing   */
    BOOLEAN     link_key_changed;       /* Changed link key during current connection */
    BOOLEAN     sec_acl_connected;      /* Used wfor dedicated bonding; indicates connection complete */
} tBTM_SEC_DEV_REC;


/*
** Define device configuration structure
*/
typedef struct
{
#if BTM_MAX_LOC_BD_NAME_LEN > 0
    tBTM_LOC_BD_NAME bd_name;                    /* local Bluetooth device name */
#endif
    BOOLEAN          pin_type;                   /* TRUE if PIN type is fixed */
    UINT8            pin_code_len;               /* Bonding information */
    PIN_CODE         pin_code;                   /* PIN CODE if pin type is fixed */
    BOOLEAN          connectable;                /* If TRUE page scan should be enabled */
    UINT8            def_inq_scan_mode;          /* ??? limited/general/none */
} tBTM_CFG;

#if BTM_PWR_MGR_INCLUDED == TRUE
enum
{
    BTM_PM_ST_ACTIVE  = BTM_PM_STS_ACTIVE,
    BTM_PM_ST_HOLD    = BTM_PM_STS_HOLD,
    BTM_PM_ST_SNIFF   = BTM_PM_STS_SNIFF,
    BTM_PM_ST_PARK    = BTM_PM_STS_PARK,
    BTM_PM_ST_PENDING = BTM_PM_STS_PENDING
};
typedef UINT8 tBTM_PM_STATE;

enum
{
    BTM_PM_SET_MODE_EVT,    /* Set power mode API is called. */
    BTM_PM_UPDATE_EVT,
    BTM_PM_RD_MODE_EVT     /* Read power mode API is called. */
};
typedef UINT8 tBTM_PM_EVENT;

typedef struct
{
    UINT16          event;
    UINT16          len;
    UINT8           link_ind;
} tBTM_PM_MSG_DATA;

typedef struct
{
    UINT8 hci_status;
    UINT8 mode;
    UINT16 interval;
} tBTM_PM_MD_CHG_DATA;

typedef struct
{
    UINT8          pm_id;      /* the entity that calls SetPowerMode API */
    tBTM_PM_PWR_MD *p_pmd;
} tBTM_PM_SET_MD_DATA;

typedef struct
{
    void        *p_data;
    UINT8        link_ind;
} tBTM_PM_SM_DATA;

typedef struct
{
    tBTM_PM_PWR_MD req_mode[BTM_MAX_PM_RECORDS]; /* the desired mode and parameters of the connection*/
    tBTM_PM_PWR_MD set_mode;  /* the mode and parameters sent down to the host controller. */
    UINT16         interval;  /* the interval from last mode change event. */
    tBTM_PM_STATE  state;     /* contains the current mode of the connection */
    BOOLEAN        chg_ind;   /* a request change indication */
} tBTM_PM_MCB;

#define BTM_PM_REC_NOT_USED 0
typedef struct
{
    tBTM_PM_STATUS_CBACK *cback;/* to notify the registered party of mode change event */
    UINT8                 mask; /* registered request mask. 0, if this entry is not used */
} tBTM_PM_RCB; 
#endif

enum
{
    BTM_BLI_ACL_UP_EVT,
    BTM_BLI_ACL_DOWN_EVT,
    BTM_BLI_PAGE_EVT,
    BTM_BLI_PAGE_DONE_EVT,
    BTM_BLI_INQ_EVT,
    BTM_BLI_INQ_DONE_EVT
};
typedef UINT8 tBTM_BLI_EVENT;

/* Define a structure to hold all the BTM data
*/
typedef struct
{
    tBTM_CFG    cfg;                        /* Device configuration */

    /****************************************************
    **      ACL Management
    ****************************************************/
    tACL_CONN   acl_db[MAX_L2CAP_LINKS];
#if( RFCOMM_INCLUDED==TRUE)
    UINT8       btm_scn[BTM_MAX_SCN];        /* current SCNs: TRUE if SCN is in use */
#endif
    UINT16      btm_def_link_policy;
    UINT16      btm_def_link_super_tout;

#if (defined(BTM_BUSY_LEVEL_CHANGE_INCLUDED) && BTM_BUSY_LEVEL_CHANGE_INCLUDED == TRUE)
    tBTM_BL_EVENT_MASK     bl_evt_mask;
    tBTM_BL_CHANGE_CB     *p_bl_changed_cb;    /* Callback for when Busy Level changed */
#else
    tBTM_ACL_DB_CHANGE_CB *p_acl_changed_cb;    /* Callback for when ACL DB changed */
#endif

    /****************************************************
    **      Power Management
    ****************************************************/
#if BTM_PWR_MGR_INCLUDED == TRUE
    tBTM_PM_MCB pm_mode_db[MAX_L2CAP_LINKS];   /* per ACL link */
    tBTM_PM_RCB pm_reg_db[BTM_MAX_PM_RECORDS]; /* per application/module */
    UINT8       pm_pend_link;  /* the index of acl_db, which has a pending PM cmd */
    UINT8       pm_pend_id;    /* the id pf the module, which has a pending PM cmd */
#endif /* BTM_PWR_MGR_INCLUDED == TRUE */

    /*****************************************************
    **      Device control
    *****************************************************/
    tBTM_DEVCB  devcb;
                                            /* Packet types supported by the local device */
    UINT16      btm_acl_pkt_types_supported;
    UINT16      btm_sco_pkt_types_supported;


    /*****************************************************
    **      Service discovery
    *****************************************************/
#if BTM_DISCOVERY_INCLUDED == TRUE
    tBTM_DISCOVERY_VAR_ST   btm_disc_vars;
    tSDP_DISCOVERY_DB       *p_btm_ddb;
#endif


    /*****************************************************
    **      Inquiry
    *****************************************************/
    tBTM_INQUIRY_VAR_ST     btm_inq_vars;
#if BTM_INQUIRY_INCLUDED == TRUE
    tBTM_FILTER_CB          *p_inq_filter_cb;   /* Callback that can be set if host */
                                                /* wants to verify inquiry filters */
#endif


    /*****************************************************
    **      SCO Management
    *****************************************************/
#if BTM_SCO_INCLUDED == TRUE
    tSCO_CB             sco_cb;
#endif    

#if BTM_SECURITY_INCLUDED == TRUE
    /*****************************************************
    **      Security Management
    *****************************************************/
    tBTM_APPL_INFO          api;

#define BTM_SEC_MAX_LINK_KEY_CALLBACKS  2
    tBTM_LINK_KEY_CALLBACK  *p_link_key_callback[BTM_SEC_MAX_LINK_KEY_CALLBACKS];

#define BTM_SEC_MAX_RMT_NAME_CALLBACKS  2
    tBTM_RMT_NAME_CALLBACK  *p_rmt_name_callback[BTM_SEC_MAX_RMT_NAME_CALLBACKS];

    tBTM_FILTER_CB          *p_conn_filter_cb;  /* Callback that can be set if host */
                                                /* wants to verify connectability filters*/
    tBTM_SEC_DEV_REC        *p_collided_dev_rec;
    TIMER_LIST_ENT           sec_pin_code_req_tle;
    BD_ADDR                  sec_pin_code_req_bd_addr;
    TIMER_LIST_ENT           sec_collision_tle;
    UINT32                   dev_rec_count;      /* Counter used for device record timestamp */
    UINT8                    security_mode;
    BOOLEAN                  pairing_disabled;
    BOOLEAN                  connect_only_paired;
    BOOLEAN                  security_mode_changed;  /* mode changed during bonding */
    BOOLEAN                  pin_type_changed;       /* pin type changed during bonding */
    BOOLEAN                  bond_created_connection;/* FALSE if bonding on the existing connection */
    BOOLEAN                  disconnect_after_bond_reason; /* If TRUE L2CAP disconnection is pending */
                                                          /* could not disconnect right away */
                                                          /* cause bonding was in progress */

    UINT8                    pin_code_len;  /* Bonding information */
    PIN_CODE                 pin_code;
    tBTM_SEC_SERV_REC        sec_serv_rec[BTM_SEC_MAX_SERVICE_RECORDS];
    tBTM_SEC_DEV_REC         sec_dev_rec[BTM_SEC_MAX_DEVICE_RECORDS];
    tBTM_MKEY_CALLBACK      *mkey_cback;
    BD_ADDR                  connecting_bda;
    DEV_CLASS                connecting_dc;
#endif

    UINT8                   first_disabled_channel;
    UINT8                   last_disabled_channel;

    UINT8                   acl_disc_reason;
    UINT8                   trace_level;
#if (defined(BTM_BUSY_LEVEL_CHANGE_INCLUDED) && BTM_BUSY_LEVEL_CHANGE_INCLUDED == TRUE)
    UINT8                   num_acl;    /* num of active ACL links */
    UINT8                   busy_level; /* the current busy level */
    BOOLEAN                 is_paging;  /* TRUE, if paging is in progess */
    BOOLEAN                 is_inquiry; /* TRUE, if inquiry is in progess */
#endif
} tBTM_CB;


#ifdef __cplusplus
extern "C"
{
#endif

#if BTM_DYNAMIC_MEMORY == FALSE
BTM_API extern tBTM_CB  btm_cb;
#else
BTM_API extern tBTM_CB *btm_cb_ptr;
#define btm_cb (*btm_cb_ptr)
#endif

/* Internal functions provided by btm_main.c
********************************************
*/
extern void         btm_init (void);

/* Internal functions provided by btm_inq.c
*******************************************
*/
extern tBTM_STATUS  btm_initiate_rem_name (BD_ADDR remote_bda,
                                           tBTM_INQ_INFO *p_cur,
                                           UINT8 origin, UINT32 timeout,
                                           tBTM_CMPL_CB *p_cb);

extern void         btm_process_remote_name (BD_ADDR bda, BD_NAME name, UINT16 evt_len,
                                             UINT8 hci_status);
extern void         btm_inq_rmt_name_failed(void);

#if BTM_INQUIRY_INCLUDED == TRUE
extern void         btm_clr_inq_db (BD_ADDR p_bda);
extern void         btm_inq_check_ageing(void);
extern void         btm_inq_db_init (void);
extern void         btm_process_inq_results (UINT8 *p, BOOLEAN with_rssi);
extern void         btm_process_inq_complete (UINT8 status);
extern void         btm_event_filter_complete (UINT8 *p);
#else
#define btm_inq_db_init()
#endif

/* Internal functions provided by btm_discovery.c
*************************************************
*/
#if BTM_DISCOVERY_INCLUDED == TRUE
extern void btm_discovery_db_init (void);
extern void btm_discovery_timeout(void);
extern void btm_discovery_db_reset (void);
#else
#define btm_discovery_db_init()
#define btm_discovery_db_reset()
#define btm_discovery_timeout()
#endif


/* Internal functions provided by btm_acl.c
********************************************
*/
extern void         btm_acl_init (void);
extern void         btm_acl_timeout (TIMER_LIST_ENT  *p_tle);
extern void         btm_acl_created (BD_ADDR bda, DEV_CLASS dc, BD_NAME bdn,
                                     UINT16 hci_handle, UINT8 link_role);
extern void         btm_acl_removed (BD_ADDR bda);
extern void         btm_acl_device_down (void);
extern void         btm_acl_update_busy_level (tBTM_BLI_EVENT event);
extern UINT8        btm_handle_to_acl_index (UINT16 hci_handle);
extern void         btm_read_link_policy_complete (UINT8 *p);
extern void         btm_read_rssi_complete (UINT8 *p);
extern void         btm_read_link_quality_complete (UINT8 *p);
extern tBTM_STATUS  btm_set_packet_types (tACL_CONN *p, UINT16 pkt_types);
extern void         btm_process_clk_off_comp_evt (UINT16 hci_handle, UINT16 clock_offset);
extern void         btm_acl_role_changed (UINT8 hci_status, BD_ADDR bd_addr, UINT8 new_role);
extern void         btm_acl_encrypt_change (UINT16 handle, UINT8 status, UINT8 encr_enable);
BTM_API extern UINT16       btm_get_acl_disc_reason_code (void);
BTM_API extern tBTM_STATUS  btm_remove_acl (BD_ADDR bd_addr);
extern void         btm_read_remote_features_complete (UINT8 *p);
extern void         btm_read_remote_version_complete (UINT8 *p);
extern void         btm_chg_all_acl_pkt_types (BOOLEAN entering_sco);
/* Read maximum data packet that can be sent over current connection */
extern UINT16 btm_get_max_packet_size (BD_ADDR addr);

#if BTM_PWR_MGR_INCLUDED == FALSE
extern void         btm_process_mode_change (UINT8 hci_status, UINT16 hci_handle, UINT8 mode,
                                             UINT16 interval);

/* Internal functions provided by btm_pm.c
********************************************
*/
#else
extern void btm_pm_reset(void);
extern void btm_pm_sm_alloc(UINT8 ind);
extern void btm_pm_proc_cmd_status(UINT8 status);
extern void btm_pm_proc_mode_change (UINT8 hci_status, UINT16 hci_handle, UINT8 mode,
                                     UINT16 interval);
#if BTM_SCO_INCLUDED == TRUE
extern void btm_sco_chk_pend_unpark (UINT8 hci_status, UINT16 hci_handle, UINT8 mode);
#else
#define btm_sco_chk_pend_unpark(hci_status, hci_handle, mode)
#endif /* BTM_SCO_INCLUDED */
#endif /* BTM_PWR_MGR_INCLUDED == FALSE */
extern void btm_qos_setup_complete (UINT8 status, UINT16 handle, FLOW_SPEC *p_flow);


/* Internal functions provided by btm_sco.c
********************************************
*/
extern void btm_sco_init (void);
extern void btm_sco_connected (UINT8 hci_status, BD_ADDR bda, UINT16 hci_handle,
                               tBTM_ESCO_DATA *p_esco_data);
extern void btm_esco_proc_conn_chg (UINT8 status, UINT16 handle, UINT8 tx_interval,
                                    UINT8 retrans_window, UINT16 rx_pkt_len,
                                    UINT16 tx_pkt_len);
extern void btm_sco_conn_req (BD_ADDR bda,  DEV_CLASS dev_class, UINT8 link_type);
extern void btm_sco_removed (UINT16 hci_handle, UINT8 reason);
extern void btm_sco_acl_removed (BD_ADDR bda);
extern void btm_route_sco_data (BT_HDR *p_msg);
extern BOOLEAN btm_is_sco_active (UINT16 handle);
extern void btm_remove_sco_links (BD_ADDR bda);
extern BOOLEAN btm_is_any_sco_active (void);
extern BOOLEAN btm_is_sco_active_by_bdaddr (BD_ADDR remote_bda);

extern UINT8 btm_num_sco_links_active (void);
extern tBTM_SCO_TYPE btm_read_def_esco_mode (tBTM_ESCO_PARAMS *p_parms);
/* Internal functions provided by btm_devctl.c
**********************************************
*/
extern void btm_dev_init (void);
extern void btm_dev_absent (void);
extern void btm_dev_timeout (TIMER_LIST_ENT *p_tle);
extern void btm_reset_complete (void);
extern void btm_read_local_version_complete (UINT8 *p, UINT16 evt_len);
extern void btm_read_hci_buf_size_complete (UINT8 *p, UINT16 evt_len);
extern void btm_read_local_features_complete (UINT8 *p, UINT16 evt_len);
extern void btm_read_local_name_complete (UINT8 *p, UINT16 evt_len);
extern void btm_read_local_addr_complete (UINT8 *p, UINT16 evt_len);
extern void btm_vsc_complete (UINT8 *p, UINT16 cc_opcode, UINT16 evt_len);    /* Vendor Specific Command complete evt handler */
extern void btm_inq_db_reset (void);
extern void btm_vendor_specific_evt (UINT8 *p, UINT8 evt_len);
extern UINT8 btm_get_hci_version (void);
extern void btm_read_stored_link_key_complete (UINT8 *p);
extern void btm_write_stored_link_key_complete (UINT8 *p);
extern void btm_delete_stored_link_key_complete (UINT8 *p);
extern void btm_return_link_keys_evt (tBTM_RETURN_LINK_KEYS_EVT *result);
extern void btm_report_device_status (tBTM_DEV_STATUS status);


/* Internal functions provided by btm_dev.c
**********************************************
*/
extern UINT8 btm_get_voice_coding_support (void);

#if BTM_SECURITY_INCLUDED == TRUE
extern tBTM_SEC_DEV_REC  *btm_sec_alloc_dev (BD_ADDR bd_addr);
extern void               btm_sec_free_dev (tBTM_SEC_DEV_REC *p_dev_rec);
extern tBTM_SEC_DEV_REC  *btm_find_dev (BD_ADDR bd_addr);
extern tBTM_SEC_DEV_REC  *btm_find_dev_by_handle (UINT16 handle);
#else
#define btm_find_dev(bd_addr) NULL
#endif

/* Internal functions provided by btm_sec.c
**********************************************
*/
extern tBTM_STATUS  btm_sec_l2cap_access_req (BD_ADDR bd_addr, UINT16 psm,
                                       UINT16 handle, BOOLEAN is_originator,
                                       tBTM_SEC_CALLBACK *p_callback);
extern void  btm_sec_mx_access_request (BD_ADDR bd_addr, UINT16 psm, BOOLEAN is_originator,
                                        UINT32 mx_proto_id, UINT32 mx_chan_id,
                                        tBTM_SEC_CALLBACK *p_callback, void *p_ref_data);
extern void  btm_sec_conn_req (UINT8 *bda, UINT8 *dc);
extern BTM_API UINT32 * btm_read_trusted_mask (BD_ADDR bd_addr); 

#if BTM_SECURITY_INCLUDED == TRUE
extern void  btm_sec_init (UINT8 sec_mode);
extern void  btm_sec_dev_reset (void);
extern void  btm_sec_abort_access_req (BD_ADDR bd_addr);
extern void  btm_sec_change_link_key (UINT16 handle);
extern void  btm_sec_auth_complete (UINT16 handle, UINT8 status);
extern void  btm_sec_mkey_comp_event (UINT16 handle, UINT8 status, UINT8 key_flg);
extern void  btm_sec_encrypt_change (UINT16 handle, UINT8 status, UINT8 encr_enable);
extern void  btm_sec_connected (UINT8 *bda, UINT16 handle, UINT8 status, UINT8 enc_mode);
extern tBTM_STATUS btm_sec_disconnect (UINT16 handle, UINT8 reason);
extern void  btm_sec_disconnected (UINT16 handle, UINT8 reason);
extern void  btm_sec_rmt_name_request_complete (UINT8 *bd_addr, UINT8 *bd_name, UINT8 status);
extern void  btm_sec_link_key_notification (UINT8 *p_bda, UINT8 *p_link_key, UINT8 key_type);
extern void  btm_sec_link_key_request (UINT8 *p_bda);
extern void  btm_sec_pin_code_request (UINT8 *p_bda);
extern void  btm_sec_update_clock_offset (UINT16 handle, UINT16 clock_offset);
extern BOOLEAN btm_sec_is_bonding (UINT16 handle);

#else   /* SECURITY_INCLUDED == FALSE */

#define btm_sec_init(sec_mode)
#define btm_sec_dev_reset()
#define btm_sec_abort_access_req(bd_addr)
#define btm_sec_rmt_name_request_complete(bd_addr, bd_name, status)
#define btm_sec_change_link_key (handle)
#define btm_sec_auth_complete(handle, status)
#define btm_sec_mkey_comp_event(handle, status, key_flg)
#define btm_sec_encrypt_change(handle, status, encr_enable)
#define btm_sec_connected(bda, handle, status, enc_mode)
#define btm_sec_disconnected(handle, reason)
#define btm_sec_link_key_notification(p_bda, p_link_key, key_type)
#define btm_sec_link_key_request(p_bda)
#define btm_sec_pin_code_request(p_bda)
#define btm_sec_update_clock_offset(handle, clock_offset)
#define btm_sec_is_bonding (UINT16 handle) FALSE
#endif  /* SECURITY_INCLUDED */

#ifdef __cplusplus
}
#endif

#endif

