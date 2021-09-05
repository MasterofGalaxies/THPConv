/*****************************************************************************
**
**  Name:       vdp_int.h
**
**  Description:VDP internal header file
**
**  Copyright (c) 2004-2005, BROADCOM Inc., All Rights Reserved.
**  BROADCOM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef VDP_INT_H
#define VDP_INT_H

#include <private/bte/stack/vdp_api.h>

/*****************************************************************************
**  Constants
*****************************************************************************/

/* Number of attributes in VDP SDP record. */
#define VDP_NUM_ATTR            4

/* Number of protocol elements in protocol element list. */
#define VDP_NUM_PROTO_ELEMS     2

/*****************************************************************************
**  Type definitions
*****************************************************************************/

/* Control block used by VDP_FindService(). */
typedef struct 
{
    tVDP_FIND_CBACK     *p_cback;       /* pointer to application callback */
    tSDP_DISCOVERY_DB   *p_db;          /* pointer to discovery database */
    UINT16              service_uuid;   /* service UUID of search */
} tVDP_FIND_CB;

typedef struct
{
    tVDP_FIND_CB    find;   /* find service control block */
    UINT8           trace_level;
} tVDP_CB;


#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
** Main Control Block
*******************************************************************************/
#if VDP_DYNAMIC_MEMORY == FALSE
VDP_API extern tVDP_CB  vdp_cb;
#else
VDP_API extern tVDP_CB *vdp_cb_ptr;
#define vdp_cb (*vdp_cb_ptr)
#endif

#ifdef __cplusplus
}
#endif

#endif /* VDP_INT_H */
