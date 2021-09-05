/*****************************************************************************
**
**  Name:           bta_dm_co.h
**
**  Description:    This is the interface file for device mananger callout
**                  functions.
**
**  Copyright (c) 2006, Widcomm Inc., All Rights Reserved.
**  Widcomm Bluetooth Core. Proprietary and confidential.
**
*****************************************************************************/
#ifndef BTA_DM_CO_H
#define BTA_DM_CO_H

#include <private/bte/bta/bta_sys.h>


/*****************************************************************************
**  Function Declarations
*****************************************************************************/

/*******************************************************************************
**
** Function         bta_dm_co_get_compress_memory
**
** Description      This callout function is executed by DM to get memory for compression

** Parameters       id  -  BTA SYS ID
**                  memory_p - memory return by callout
**                  memory_size - memory size
**
** Returns          TRUE for success, FALSE for fail.
**
*******************************************************************************/
BTA_API extern BOOLEAN bta_dm_co_get_compress_memory(tBTA_SYS_ID id, UINT8 **memory_p, UINT32 *memory_size);

#endif

