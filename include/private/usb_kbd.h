/*---------------------------------------------------------------------------*
  Project:  Revolution USB keyboard library
  File:     usb_kbd.h

  Copyright 2007 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.5  2007/06/19 19:37:21  carlmu
  Made USBKBDCmd structure 32 bytes in size.

  Revision 1.4  2007/06/19 19:09:41  wayne.wong
  Added/modified to have both blocking and non-blocking USBKBDSetLED.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

/*
 * access to the kbd-specific USB driver
 */

#ifndef __USB_KBD_H__
#define __USB_KBD_H__

typedef enum {
  USB_KBD_SUCCESS,
  USB_KBD_ERROR,         // general unspecified error
  USB_KBD_ALREADY_INITIALIZED,
  USB_KBD_NOT_INITIALIZED,
  USB_KBD_CANNOT_OPEN_DRIVER,
  USB_KBD_INVALID_PARAMETER,
  USB_KBD_ASYNC_SETUP_FAILED
} USBKBDEc;              // keyboard driver error code

typedef u32 USBKBDId;
typedef void (*USBKBDCallback)(BOOL success, void *cbarg);

// The first n bytes (id + data) are used to make an IPC call. The last 
// two fields are used by the callback wrapper.  
//
// NOTE: kbd_lib requires that this structure size be a multiple of 32 bytes.
typedef struct _USBKBDCmd {
  USBKBDId        id;
  u8              data[20];
  USBKBDCallback  cb;
  void           *cbarg;
} USBKBDCmd;


#define USB_KBD_NUM_HID_KEY_CODES (6)

typedef struct _USBKBDReport {
  u8    modifier;
  u8    reserved;
  u8    keycode[USB_KBD_NUM_HID_KEY_CODES];
} USBKBDReport;

typedef void (*USBKBDAttachCallback)(USBKBDId id);
typedef void (*USBKBDDetachCallback)(USBKBDId id);
typedef void (*USBKBDEventCallback)(USBKBDId id, USBKBDReport *report);

USBKBDEc USBKBDInitialize(USBKBDAttachCallback attach_cb,
                          USBKBDDetachCallback detach_cb);
USBKBDEc USBKBDExit(void);
USBKBDEc USBKBDRegisterAttachCallback(USBKBDAttachCallback cb);
USBKBDEc USBKBDRegisterDetachCallback(USBKBDDetachCallback cb);
USBKBDEc USBKBDRegisterEventCallback(USBKBDEventCallback cb);
USBKBDEc USBKBDSetLED(USBKBDId id, u8 state, USBKBDCmd *buf);
USBKBDEc USBKBDSetLEDAsync(USBKBDId id, u8 state, USBKBDCmd *buf, USBKBDCallback cb, void *cbarg);

/*
USBKBDEc USBKBDDoIt(void);       // wayne - for debugging
USBKBDEc USBKBDDoItAsync(void);  // wayne - for debugging
*/

#endif  // __USB_KBD_H__
