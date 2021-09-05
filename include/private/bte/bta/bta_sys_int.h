/*****************************************************************************
**
**  Name:           bta_sys_int.h
**
**  Description:    This is the private interface file for the BTA system
**                  manager.
**
**  Copyright (c) 2003-2004, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef BTA_SYS_INT_H
#define BTA_SYS_INT_H

#include <private/bte/bta/ptim.h>

/*****************************************************************************
**  Constants and data types
*****************************************************************************/



/* system manager control block */
typedef struct
{
    tBTA_SYS_REG            *reg[BTA_ID_MAX];       /* registration structures */
    tPTIM_CB                ptim_cb;                /* protocol timer list */
    BOOLEAN                 timers_disabled;        /* TRUE if sys timers disabled */
    UINT8                   task_id;                /* GKI task id */
    tBTA_SYS_CONN_CBACK     *prm_cb;                 /* role management callback registered by DM */
    tBTA_SYS_CONN_CBACK     *ppm_cb;                 /* low power management callback registered by DM */
    tBTA_SYS_CONN_CBACK     *compress_cb;            /* compress callback registered by DM */

} tBTA_SYS_CB;

/*****************************************************************************
**  Global variables
*****************************************************************************/

/* system manager control block */
#if BTA_DYNAMIC_MEMORY == FALSE
extern tBTA_SYS_CB bta_sys_cb;
#else
extern tBTA_SYS_CB *bta_sys_cb_ptr;
#define bta_sys_cb (*bta_sys_cb_ptr)
#endif


/* system manager configuration structure */
extern tBTA_SYS_CFG *p_bta_sys_cfg;

 
#endif /* BTA_SYS_INT_H */
