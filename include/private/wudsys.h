/*---------------------------------------------------------------------------*
  Project:  Revolution OS - Wireless UI Driver Library
  File:     wudsys.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.41  2007/05/30 02:02:15  tojo
  Added WUDRegisterDevice(), _WUDGetDevKey(), _WUDConnect().

  Revision 1.40  2007/02/22 05:21:44  tojo
  Changed the shutdown API to send the flag of calling OSExec.

  Revision 1.39  2007/02/13 01:46:01  tojo
  Mistook to update this header file in CVS main tree
  when CVS branch tree is changed.

  Revision 1.37  2007/01/22 07:33:47  tojo
  Added WUDStartSyncSpDevice, _WUDGetDevName.
  Changed api of WUDHidConnCallback.

  Revision 1.36  2006/10/11 17:07:54  tojo
  Added busy state.

  Revision 1.35  2006/09/27 01:03:09  tojo
  (none)

  Revision 1.34  2006/09/26 07:26:41  tojo
  Added the api to cancel standard pairing.

  Revision 1.33  2006/09/19 00:44:28  tojo
  (none)

  Revision 1.32  2006/09/15 13:51:13  tojo
  Added rssi and fast sync apis.

  Revision 1.31  2006/09/15 07:37:40  tojo
  (none)

  Revision 1.30  2006/09/15 06:45:16  tojo
  (none)

  Revision 1.29  2006/09/15 05:42:08  tojo
  (none)

  Revision 1.28  2006/09/15 02:03:46  tojo
  (none)

  Revision 1.27  2006/09/14 15:57:54  tojo
  Got the stack queue status.

  Revision 1.26  2006/09/14 05:04:25  tojo
  Added WUDGetBufferStatus.

  Revision 1.25  2006/09/12 04:14:01  tojo
  Rename BD_ADDR to BTD_ADDR

  Revision 1.24  2006/09/06 02:40:25  tojo
  Implemented to control connectability.

  Revision 1.23  2006/09/02 05:55:00  tojo
  (none)

  Revision 1.22  2006/09/02 02:06:43  tojo
  (none)

  Revision 1.21  2006/09/01 06:35:30  tojo
  Exported device infos.

  Revision 1.20  2006/08/30 10:50:31  tojo
  Enabled SC completely.

  Revision 1.19  2006/08/21 04:13:05  tojo
  (none)

  Revision 1.18  2006/08/18 11:26:19  tojo
  Used SC libs.

  Revision 1.17  2006/08/14 17:58:24  tojo
  Enabled SC lib.

  Revision 1.16  2006/08/11 07:54:41  tojo
  Added some controller status.

  Revision 1.15  2006/08/02 00:55:54  tojo
  (none)

  Revision 1.14  2006/07/19 08:16:12  tojo
  Changed argument type u8 to u16 at WUDSetDisableChannel

  Revision 1.13  2006/06/30 08:51:17  tojo
  Added WUDGetAllocatedMemSize().

  Revision 1.12  2006/06/21 08:30:22  tojo
  Changed return value type of WUDInit()

  Revision 1.11  2006/06/16 08:38:41  tojo
  Added some event macros.

  Revision 1.10  2006/06/14 11:31:34  tojo
  Added WUDGetRegisteredDevNum().

  Revision 1.9  2006/06/13 11:44:17  tojo
  Added delete all link keys handler.

  Revision 1.8  2006/06/12 06:07:07  tojo
  (none)

  Revision 1.7  2006/06/03 10:01:11  tojo
  Added WUDSetSniffMode()

  Revision 1.6  2006/06/01 07:34:39  tojo
  Merged connection status block and control status block.
  Added the function to get the host address.

  Revision 1.5  2006/05/29 06:42:46  tojo
  enable SI port status events

  Revision 1.4  2006/05/25 12:58:28  tojo
  /revolution/wud.h merged into /private/wudsys.h.

  Revision 1.3  2006/05/22 13:42:29  tojo
  rename hidOpenCallback to hidConnCallback
  implement a termination process

  Revision 1.2  2006/05/22 08:31:25  tojo
  added two functions related with stored bda/link_key

  Revision 1.1  2006/05/17 05:05:26  kawaset
  Initial check-in.


  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __WUDSYS_H__
#define __WUDSYS_H__

#include <revolution/types.h> 

#ifdef __cplusplus
extern "C" {
#endif

#define INIT_SC_LIBS                    1
#define ENABLE_SC_LIBS                  1

#if ENABLE_SC_LIBS
#include <revolution/sc.h>
#include <private/SCBt.h>
#endif 


#define WUD_CHAN0                       0
#define WUD_CHAN1                       1
#define WUD_CHAN2                       2
#define WUD_CHAN3                       3

#define WUD_STATE_DISABLED              0
#define WUD_STATE_ENABLING              1
#define WUD_STATE_ENABLED               2
#define WUD_STATE_SETUP                 3
#define WUD_STATE_DISABLING             4
#define WUD_STATE_BUSY                  5

#define WUD_DISABLE_CLEAR               0     // enable all range
#define WUD_DISABLE_WIFI_CHAN_1         1
#define WUD_DISABLE_WIFI_CHAN_2         2
#define WUD_DISABLE_WIFI_CHAN_3         3
#define WUD_DISABLE_WIFI_CHAN_4         4
#define WUD_DISABLE_WIFI_CHAN_5         5
#define WUD_DISABLE_WIFI_CHAN_6         6
#define WUD_DISABLE_WIFI_CHAN_7         7
#define WUD_DISABLE_WIFI_CHAN_8         8
#define WUD_DISABLE_WIFI_CHAN_9         9
#define WUD_DISABLE_WIFI_CHAN_10        10
#define WUD_DISABLE_WIFI_CHAN_11        11
#define WUD_DISABLE_WIFI_CHAN_12        12
#define WUD_DISABLE_WIFI_CHAN_13        13
#define WUD_DISABLE_WIFI_CHAN_14        14

#define WUD_DEV_STAT_UNUSED             0
#define WUD_DEV_STAT_DISCONNECTED       1
#define WUD_DEV_STAT_CONNECTING         2
#define WUD_DEV_STAT_LINK_UP            3
#define WUD_DEV_STAT_PIN_REQ            4
#define WUD_DEV_STAT_PIN_CMPL           5
#define WUD_DEV_STAT_AUTH_CMPL          6
#define WUD_DEV_STAT_STORE_KEY          7
#define WUD_DEV_STAT_CONNECTED          8
#define WUD_DEV_STAT_SNIFF              9
#define WUD_DEV_STAT_RETRY              10
#define WUD_DEV_STAT_AUTH_FAIL          11
#define WUD_DEV_STAT_SYNC               12

#define WUD_SYNC_EVT_BUSY              -1
#define WUD_SYNC_EVT_START              0
#define WUD_SYNC_EVT_DONE               1

#define WUD_DEL_EVT_BUSY               -1
#define WUD_DEL_EVT_START               0
#define WUD_DEL_EVT_DONE                1

#define WUD_REG_NONE                    0
#define WUD_REG_EEPROM                  1
#define WUD_REG_NAND                    2
#define WUD_REG_OK                      3

#define WUD_SYNC_TYPE_NONE_TO_STD       0
#define WUD_SYNC_TYPE_NONE_TO_SMP       1
#define WUD_SYNC_TYPE_STD_TO_STD        2
#define WUD_SYNC_TYPE_SMP_TO_SMP        3
#define WUD_SYNC_TYPE_STD_TO_SMP        4
#define WUD_SYNC_TYPE_SMP_TO_STD        5

#define WUD_DEFAULT_SYNC_RSSI           -65

typedef u8 BTD_NAME[64];
typedef u8 BTD_ADDR[6];
typedef u8 LINKKEY[16];

// entry of device database
typedef struct WUDDeviceInfo
{
    BTD_NAME            bd_name;
    BTD_ADDR            bd_addr;
    LINKKEY             link_key;
    u8                  handle;
    u8                  sub_class;
    u8                  app_id;
    u8                  status;
    u8                  overwrite;
    u8                  sync_type;
    u8                  reg;
    u16                 attr_mask;
} WUDDeviceInfo;

typedef void*(*WUDAlloc)                ( u32 size );
typedef u8   (*WUDFree)                 ( void *ptr );
typedef void (*WUDSyncDeviceCallback)   ( s32 result, s32 num );
typedef void (*WUDClearDeviceCallback)  ( s32 result );
typedef void (*WUDHidRecvCallback)      ( u8 dev_handle, u8* p_rpt, u16 len );
typedef void (*WUDHidConnCallback)      ( WUDDeviceInfo *info, u8 open );
typedef void (*WUDStoredCallback)       ( void *p_data );

BOOL WUDInit                ( void );
void WUDRegisterAllocator   ( WUDAlloc alloc, WUDFree free );
u32  WUDGetAllocatedMemSize ( void );
void WUDShutdown            ( BOOL exec );
BOOL WUDSetDisableChannel   ( s8 disable );
BOOL WUDStartSyncDevice     ( void );
BOOL WUDStartFastSyncDevice ( void );
BOOL WUDCancelSyncDevice    ( void );
BOOL WUDStartSyncSimple     ( void );
BOOL WUDStartFastSyncSimple ( void );
BOOL WUDStartSyncSpDevice   ( u8 type );
BOOL WUDStopSyncSimple      ( void );
BOOL WUDStartClearDevice    ( void );
s32  WUDGetStatus           ( void );
u8   WUDGetRegisteredDevNum ( void );
u8   WUDGetTemporaryDevNum  ( void );
void WUDSetSniffMode        ( BD_ADDR bd_addr, s32 interval );
void WUDSetVisibility       ( u8 disc, u8 conn );
u8   WUDGetDiscoverable     ( void );
u8   WUDGetConnectable      ( void );
u8   WUDGetBufferStatus     ( void );
BOOL WUDIsBusy              ( void );
BOOL WUDRegisterDevice      ( u8 *addr, u8 *key, u8 *name );


WUDSyncDeviceCallback       WUDSetSyncDeviceCallback    ( WUDSyncDeviceCallback  callback );
WUDSyncDeviceCallback       WUDSetSyncSimpleCallback    ( WUDSyncDeviceCallback  callback );
WUDClearDeviceCallback      WUDSetClearDeviceCallback   ( WUDClearDeviceCallback callback );

extern BOOL                 _WUDEnableTestMode          ( void );
extern void                 _WUDStartSyncDevice         ( BD_ADDR bd_addr, u8 *bd_name );
extern void                 _WUDReadStoredDevice        ( WUDStoredCallback callback );
extern void                 _WUDDeleteStoredDevice      ( void );
extern void                 _WUDEnableSIPortStatus      ( void );
extern u8                   _WUDGetSIPortStatus         ( void );
extern u8*                  _WUDGetHostAddr             ( void );
extern u8*                  _WUDGetDevAddr              ( u8 dev_handle );
extern u8*                  _WUDGetDevName              ( u8 dev_handle );
extern u8*                  _WUDGetDevKey               ( u8 dev_handle );
extern s8                   _WUDGetSyncType             ( s8 handle );
extern u16                  _WUDGetQueuedSize           ( s8 dev_handle );
extern u16                  _WUDGetNotAckedSize         ( s8 dev_handle );
extern u8                   _WUDGetLinkNumber           ( void );

extern s8                   _WUDGetSyncRssi             ( void );
extern void                 _WUDSetSyncRssi             ( s8 rssi );

extern void                 _WUDEnableDebugMsgs         ( void );
extern void                 _WUDDisableDebugMsgs        ( void );

extern BOOL                 _WUDConnect                 ( u8 *addr, u8 *key, u8 *name );

extern WUDHidRecvCallback   WUDSetHidRecvCallback       ( WUDHidRecvCallback callback );
extern WUDHidConnCallback   WUDSetHidConnCallback       ( WUDHidConnCallback callback );

void WUDSetSyncLoopNum      ( s8 loop );

// external valiable
extern SCBtDeviceInfoArray _scArray;
extern u8                  _scFlush;


#ifdef __cplusplus
}
#endif
#endif // __WUDSYS_H__
