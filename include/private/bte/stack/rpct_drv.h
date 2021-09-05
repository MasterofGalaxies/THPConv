/*****************************************************************************
**
**  Name:           rpct_drv.h
**
**  Description:    This interface file provides a virtual base class for the
**                  RPCT driver modules.  It declares the common interface
**                  function structure for driver modules.  It also contains
**                  a forward declaration of each driver control block and
**                  a union of all driver control block types.
**
**  Copyright (c) 2001-2004, WIDCOMM Inc., All Rights Reserved.
**  WIDCOMM Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef RPCT_DRV_H
#define RPCT_DRV_H

/*****************************************************************************
**  Declaration of driver control blocks
*****************************************************************************/

/* forward declaration of serial driver control block */
typedef struct t_rpct_serial_cb *tpRPCT_SERIAL_CB;

/* union of all driver control block types */
typedef union {
    tpRPCT_SERIAL_CB   p_serial;       /* serial driver */
} tRPCT_DRV_CB;

/*****************************************************************************
**  Common interface function type definitions
*****************************************************************************/

/* open function */
typedef void (*tRPCT_DRV_OPEN)(tRPCT_DRV_CB cb);

/* write function */
typedef UINT16 (*tRPCT_DRV_WRITE)(tRPCT_DRV_CB cb, UINT8 *p_data, UINT16 len);

/* read function */
typedef UINT16 (*tRPCT_DRV_READ)(tRPCT_DRV_CB cb, UINT8 *p_data, UINT16 len);

/* structure of interface functions */
typedef struct {
    tRPCT_DRV_OPEN      open;
    tRPCT_DRV_WRITE     write;
    tRPCT_DRV_READ      read;
} tRPCT_DRV_IF;

#endif /* RPCT_DRV_H */
