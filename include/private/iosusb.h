/*
 *               Copyright (C) 2005, BroadOn Communications Corp.
 *
 *  These coded instructions, statements, and computer programs contain
 *  unpublished  proprietary information of BroadOn Communications Corp.,
 *  and  are protected by Federal copyright law. They may not be disclosed
 *  to  third  parties or copied or duplicated in any form, in whole or in
 *  part, without the prior written consent of BroadOn Communications Corp.
 *
 */
#ifndef __IOS_USB_H__
#define __IOS_USB_H__
#ifdef __cplusplus
extern "C" {
#endif
#define ISO_PACKETS_MAX 8
typedef struct IsoTransfer {
    void *buf;          /* Beginning of buffer. */
    u8   numPackets;    /* Valid range: [1, 8] */
    u16 *packets; /* packet size/ status word + transfer size */
} IsoTransfer;

typedef void (*USBCallbackFunc)(IOSError err, void *cbArg);
typedef void (*USBIsoCallbackFunc)(IOSError err, IsoTransfer *xfer, void
        *cbArg);

IOSError IUSB_OpenLib(void);
IOSError IUSB_CloseLib(void);

/*
   Device ID to be used as did in IUSB_OpenDeviceIdsAsync():
 */
#define  IUSB_DEV_OHCI_0    "oh0"
#define  IUSB_DEV_OHCI_1    "oh1"
#define  IUSB_DEV_EHCI      "ehc"

IOSError IUSB_OpenDeviceIds(const char *did, u16 vid, u16 pid, IOSFd *fd);
//IOSError IUSB_OpenDeviceIdsAsync(const char *did, u16 vid, u16 pid, IOSFd *fd,
IOSError IUSB_OpenDeviceIdsAsync(const char *did, u16 vid, u16 pid, 
                               USBCallbackFunc cb, void *cbArg);

IOSError IUSB_CloseDevice(IOSFd fd);
IOSError IUSB_CloseDeviceAsync(IOSFd fd, USBCallbackFunc cb, void *cbArg);

/*
  buffer referenced by buf address must be aligned(32) and multiple of 32 bytes
 */
IOSError IUSB_GetAsciiStr(IOSFd fd, u8 ep, u16 index, u16 langId,
                          char *buf, u16 buflen);
IOSError IUSB_GetAsciiStrAsync(IOSFd fd, u8 ep, u16 index, u16 langId,
                               char *buf, u16 buflen, USBCallbackFunc cb, 
                               void *cbArg);

IOSError IUSB_GetDevDescr(IOSFd fd, USB_DevDescr *des); 
IOSError IUSB_GetDevDescrAsync(IOSFd fd, USB_DevDescr *des, 
                               USBCallbackFunc cb, void *cbArg);

/*
  buffer referenced by buf address must be aligned(32) and multiple of 32 bytes
 */
IOSError IUSB_ReadCtrlMsg(IOSFd fd, u8 reqType, u8 request, u16 value,
                          u16 index, u16 buflen, char *buf); 
IOSError IUSB_ReadCtrlMsgAsync(IOSFd fd, u8 reqType, u8 request, u16 value,
                               u16 index, u16 buflen, char *buf, 
                               USBCallbackFunc cb, void *cbArg);

IOSError IUSB_WriteCtrlMsg(IOSFd fd, u8 reqType, u8 request, u16 value,
                           u16 index, u16 buflen, char *buf); 
IOSError IUSB_WriteCtrlMsgAsync(IOSFd fd, u8 reqType, u8 request, u16 value,
                                u16 index, u16 buflen, char *buf, 
                                USBCallbackFunc cb, void *cbArg);

/*
  buffer referenced by buf address must be aligned(32) and multiple of 32 bytes
 */

IOSError IUSB_ReadIntrMsg(IOSFd fd, u32 ep, u32 buflen, char *buf); 
IOSError IUSB_ReadIntrMsgAsync(IOSFd fd, u32 ep, u32 buflen, char *buf, 
                               USBCallbackFunc cb, void *cbArg);

IOSError IUSB_WriteIntrMsg(IOSFd fd, u32 ep, u32 buflen, char *buf); 
IOSError IUSB_WriteIntrMsgAsync(IOSFd fd, u32 ep, u32 buflen, char *buf, 
                                USBCallbackFunc cb, void *cbArg);
/*
  buffer referenced by buf address must be aligned(32) and multiple of 32 bytes
 */

IOSError IUSB_ReadBlkMsg(IOSFd fd, u32 ep, u32 buflen, char *buf); 
IOSError IUSB_ReadBlkMsgAsync(IOSFd fd, u32 ep, u32 buflen, char *buf, 
                               USBCallbackFunc cb, void *cbArg);

IOSError IUSB_WriteBlkMsg(IOSFd fd, u32 ep, u32 buflen, char *buf); 
IOSError IUSB_WriteBlkMsgAsync(IOSFd fd, u32 ep, u32 buflen, char *buf, 
                                USBCallbackFunc cb, void *cbArg);


IOSError IUSB_SuspendDevice(IOSFd fd);
IOSError IUSB_ResumeDevice(IOSFd fd);
IOSError IUSB_ResetDevice(IOSFd fd);
IOSError IUSB_GetDeviceList(const char *path, USBDeviceInfo *deviceList,
        u8 maxDev, u8 deviceClass, u8 *numDev);
IOSError IUSB_GetRhDesca(IOSFd fd, u32 *desca);
IOSError IUSB_GetRhPortStatus(IOSFd fd, u8 port, u32 *stat);
IOSError IUSB_SetRhPortStatus(IOSFd fd, u8 port, u32 stat);
IOSError IUSB_DeviceRemovalNotifyAsync(IOSFd fd, IOSIpcCb cb, void *cbArg);
IOSError IUSB_IsoMsgAsync(IOSFd fd, u8 ep, IsoTransfer *xfer,
        USBIsoCallbackFunc cb, void *cbArg);
IOSError IUSB_DeviceInsertionNotifyAsync(const char *path, u16 vid, u16 pid, 
        USBCallbackFunc cb, void *cbArg);
IOSError IUSB_DeviceClassInsertionNotifyAsync(const char *path, u8 devClass,
        USBCallbackFunc cb, void *cbArg);

#ifdef  __cplusplus
}
#endif
#endif /* __IOS_USB_H__ */
