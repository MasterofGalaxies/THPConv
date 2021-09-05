/*****************************************************************************
**
**  Name:       opp_int.h
**
**  File:       Object Push Profile Internal Definitions
**
**  Copyright (c) 2000-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef OPP_INT_H
#define OPP_INT_H

#include <private/bte/common/target.h>
#if (defined(OPP_CLIENT_INCLUDED) && OPP_CLIENT_INCLUDED == TRUE)
#include <private/bte/stack/opp_clnt_int.h>
#endif
#if (defined(OPP_SERVER_INCLUDED) && OPP_SERVER_INCLUDED == TRUE)
#include <private/bte/stack/opp_srvr_int.h>
#endif

/*****************************************************************************
**   Constants
*****************************************************************************/

#define OPP_UUID_LENGTH         16
#define OPP_DEFAULT_VERSION     0x0100

/* OPP Active opp obex operation (Valid in connected state) */
#define OPP_OP_NONE             0
#define OPP_OP_PULL_OBJ         1
#define OPP_OP_PUSH_OBJ         2

#define OPP_VERSION             0x0100

/*****************************************************************************
**   Type Definitions
*****************************************************************************/
typedef struct
{
    tOPP_GOEP_CBACKS    fs_cbacks;
#if (defined(OPP_SERVER_INCLUDED) && OPP_SERVER_INCLUDED == TRUE)
    tOPP_SRVR_CB        scb;
#endif
#if (defined(OPP_CLIENT_INCLUDED) && OPP_CLIENT_INCLUDED == TRUE)
    tOPP_CLNT_CB        ccb;
    tOPP_CLNT_SDP       sdpcb;
#endif
    UINT8               trace_level;
} tOPP_CB;


#ifdef __cplusplus
extern "C"
{
#endif
/*
** Define prototypes for global data
*/
#if OPP_DYNAMIC_MEMORY == FALSE
OPP_API extern tOPP_CB  opp_cb;
#else
OPP_API extern tOPP_CB *opp_cb_ptr;
#define opp_cb (*opp_cb_ptr)
#endif
extern const char opp_vcard_type[];
extern tOPP_STATUS opp_convert_obx_to_opp_status(tOBX_STATUS obx_status);

#ifdef __cplusplus
}
#endif

#endif
