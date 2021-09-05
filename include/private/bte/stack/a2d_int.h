/*****************************************************************************
**
**  Name:       a2d_int.h
**
**  Description:A2DP internal header file
**
**  Copyright (c) 2002-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef A2D_INT_H
#define A2D_INT_H

#include <private/bte/stack/a2d_api.h>

/*****************************************************************************
**  Constants
*****************************************************************************/

/* Number of attributes in A2D SDP record. */
#define A2D_NUM_ATTR            5

/* Number of protocol elements in protocol element list. */
#define A2D_NUM_PROTO_ELEMS     2

/*****************************************************************************
**  Type definitions
*****************************************************************************/

/* Control block used by A2D_FindService(). */
typedef struct 
{
    tA2D_FIND_CBACK     *p_cback;       /* pointer to application callback */
    tSDP_DISCOVERY_DB   *p_db;          /* pointer to discovery database */
    UINT16              service_uuid;   /* service UUID of search */
} tA2D_FIND_CB;

typedef struct
{
    tA2D_FIND_CB    find;   /* find service control block */
    UINT8           trace_level;
    BOOLEAN         use_desc;
} tA2D_CB;


#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
** Main Control Block
*******************************************************************************/
#if A2D_DYNAMIC_MEMORY == FALSE
A2D_API extern tA2D_CB  a2d_cb;
#else
A2D_API extern tA2D_CB *a2d_cb_ptr;
#define a2d_cb (*a2d_cb_ptr)
#endif

#ifdef __cplusplus
}
#endif

#endif /* A2D_INT_H */
