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

/*
 *  $Id: sdio_api.h,v 1.3 2006-04-24 20:32:18 cnguyen Exp $
 */

#ifndef _SDIO_API_H_
#define _SDIO_API_H_

typedef IOSError (*SDCallbackFunc) (IOSError ret, void *ctxt);

typedef struct _SDDev {
    int  SDDevFd;
    u32   SDDevFunc;
    char *SDDevName;
    u32  SDDevSlot;
    u32  SDDevRca;
    u32  SDBlockLen;
    u32  SDSectorSize;
    u32  SDSectorNum;
    u32  SDDevSize;
    u32  SDState;
} SDDev;

typedef struct _SDDev * SDDevHandle;

typedef struct _SDDevConfig {
    u8  SDDevSlot;
    u8  SDDevFunc;
    u8  SDDevManufacturer;
    u8  SDDevType;
} SDDevConfig;

/*
typedef enum _CardState {
    SD_STATE_RESET,
    SD_STATE_ENABLE, 
    SD_STATE_DISABLE, 
    SD_STATE_SUSPEND,
    SD_STATE_RESUME
} CardState;
*/

typedef enum {
    SD_REG_RCA = 3,
    SD_REG_CSD = 9,
    SD_REG_CID = 10,
    SD_REG_CS  = 13,	/* Card Status */
    SD_CMD16_BLK_L = 16,
    SD_CMD17_BLK_RD = 17,
    SD_CMD18_MBLK_RD = 18,
    SD_CMD24_BLK_WR = 24,
    SD_CMD25_MBLK_WR = 25,    
    SD_REG_OCR = 41,
    SD_REG_SCR = 51,
    SD_REG_ACMD = 55
} SDRegType;

typedef enum _BusWidth {
    SD_BW_1BIT,
    SD_BW_4BIT
} BusWidth;

#define MAX_SLOTS      4
#define MAX_FUNCS      8
#define DEF_BLOCK_SIZE 64
#define MAX_BLOCK_SIZE 256

/*
 * Device interrupt bits
 */
#define COMMAND_COMPLETE     0x00000001
#define TRANSFER_COMPLETE    0x00000002
#define BLOCK_GAP_EVENT      0x00000004
#define DMA_INTERRUPT        0x00000008
#define BUFFER_WRITE_READY   0x00000010
#define BUFFER_READ_READY    0x00000020
#define CARD_INSERTION       0x00000040
#define CARD_REMOVAL         0x00000080
#define CARD_INTERRUPT       0x00000100
#define ERROR_INTERRUPT      0x00008000

/*
 * Device error bits.
 */
#define COMMAND_TIMEOUT       0x00000001
#define COMMAND_CRC_ERROR     0x00000002
#define COMMAND_END_BIT_ERROR 0x00000004
#define COMMAND_INDEX_ERROR   0x00000008
#define DATA_TIMEOUT_ERROR    0x00000010
#define DATA_CRC_ERROR        0x00000020
#define DATA_END_BIT_ERROR    0x00000040
#define CURRENT_LIMIT_ERROR   0x00000080
#define AUTO_CMD12_ERROR      0x00000100
#define VENDOR_ERROR_1        0x00001000
#define VENDOR_ERROR_2        0x00002000
#define VENDOR_ERROR_3        0x00004000
#define VENDOR_ERROR_4        0x00008000

/*
 * Status bits for device status query
 */
#define SD_CARD_INSERTED      0x00000001
#define SD_CARD_REMOVED       0x00000002
#define SD_CARD_WPROTECTED    0x00000004
#define SD_STATE_SUSPEND      0x00000008

#define SD_TYPE_MEMORY        0x00010000
#define SD_TYPE_SDIO          0x00020000
#define SD_TYPE_COMBO         0x00040000
#define SD_TYPE_MMC           0x00080000

/*
 * ISD_AttachDevice 
 *
 * Attach and register this device driver with SDIO host driver.
 *
 * This function attaches and registers this device driver with the
 * SDIO host driver. The host driver uses the input device
 * configuration structure to bind this device driver to the specified
 * class of device.  The host driver will allocate necessary resources
 * for this driver registration and returns a handle to the
 * caller. This device handle should be used in all subsequent calls.
 *
 * When a card is inserted into a host controller slot, all the issues
 * to do with card insertion, such as insertion/removal interrupt,
 * device probe, clock and power level establishment, are handled by
 * the host driver. The host driver can call the device driver
 * callback for certain event (i.e., card removal) if such callback
 * routine is registered.
 *
 * devCfg points to a structure that contains device configuration
 * information such as manufacturer id, application id, device type,
 * number of functions, etc.
 */
extern IOSError ISD_AttachDevice(SDDevConfig *devCfg, SDDevHandle *fd);

/*
 * IOS_ERROR_SDIO_ERR
 *
 * Detach and unregister the device driver from the SDIO host driver.
 *
 * This function simply detaches and unregisters the device driver
 * from the SDIO host driver. It will also free up all allocated
 * resources in the device attach call.
 *
 * After this call, the device handle is invalid and cannot be
 * re-used. Another device attach (IDS_AttachDevice) call is needed to
 * re-access the card. The host driver will invisibly handle issues
 * regarding with putting the card into power-save mode.
 */
extern IOSError ISD_DetachDevice(SDDevHandle fd);

/*
 * ISD_ResetDevice 
 *
 * Reset the specified device
 *
 * This function resets the device specified by fd by either issuing a
 * CMD0 for SD memory card or CMD52 to set the RES bit in CCCR for
 * SDIO card.
 */
extern IOSError ISD_ResetDevice(SDDevHandle fd);
extern IOSError ISD_ResetDeviceAsync(SDDevHandle fd, SDCallbackFunc handler, void *arg);

/*
 * ISD_EnableDevice, ISD_DisableDevice 
 *
 * Enable or disable the specified device
 *
 * These functions can enable or disable the device or one of its
 * functions specified by fd.
 */
extern IOSError ISD_EnableDevice(SDDevHandle fd, u32 funcId);
extern IOSError ISD_DisableDevice(SDDevHandle fd, u32 funcId);


/*
 * ISD_GetDeviceStatus  Return the status of the specified device
 *
 * Return the status of the specified device where the lower 16 bits
 * specify the current device state which could be SD_CARD_INSERTED,
 * SD_CARD_REMOVED, SD_CARD_WPROTECTED, or SD_STATE_SUSPEND and the
 * upper 16 bits specifies the device type: SD_TYPE_MEMORY,
 * SD_TYPE_SDIO, SD_TYPE_COMBO, and SD_TYPE_MMC.
 */
extern IOSError ISD_GetDeviceStatus(SDDevHandle fd, u32 *devStatus);

/*
 * ISD_SetDeviceState  Set the state of the specified device
 * 
 * Set the state of the specified device to SD_STATE_RESET,
 * SD_STATE_ENABLE, SD_STATE_DISABLE, SD_STATE_SUSPEND, or
 * SD_STATE_RESUME
 */
extern IOSError ISD_SetDeviceState(SDDevHandle fd, u8 state);

/*
 * ISD_GetDeviceRegisterInfo Get the register information for the
 * specified device based on the register type
 * 
 * Based on the register type, retrieve the corresponding register
 * info into the register buffer of buffer length. For SD card, the
 * following registers can be retrieved: SD_REG_CID, SD_REG_CSD,
 * SD_REG_SCR, SD_REG_OCR, and SD_REG_RCA.
 */
extern IOSError ISD_GetDeviceRegisterInfo(SDDevHandle fd, u32 regType, u8 *regBuf, u32 bufLen);


/*
 * ISD_ReadCCCR, ISD_WriteCCCR Read and Write the CCCR register for
 * SDIO card
 * 
 * Based on the input register address, the ReadCCCR function reads
 * and returns the 8-bit data of the CCCR in regData.  Similarly, the
 * WriteCCCR writes the input 8-bit data into the CCCR at offset
 * regAddr.
 */
extern IOSError ISD_ReadCCCR(SDDevHandle fd, u32 regAddr, u8 *regData);
extern IOSError ISD_WriteCCCR(SDDevHandle fd, u32 regAddr, u8 regData);


/*
 * ISD_ReadFBR  Read the FBR register of the specified SDIO card
 * 
 * Based on the input function id, this routine reads the 8-bit data
 * of the FBR at the given address regAddr and stores the read data in
 * regData.
 */
extern IOSError ISD_ReadFBR(SDDevHandle fd, u32 funcId, u32 regAddr, u8 *regData);

/*
 * ISD_ReadCIS Read the CIS register of the specified SDIO card for
 * the given function
 * 
 * Based on the given function, this routine reads and stores the CIS
 * register data in buffer regData of size length.
 */
extern IOSError ISD_ReadCIS(SDDevHandle fd, u32 funcId, u8 *regData, u32 length);

/*
 * ISD_QueryDeviceIntr Query the interrupt status for the specified
 * device or its function interface.
 * 
 * This function simply queries the device interrupt signals to help
 * the SDIO card.
 */
extern IOSError ISD_QueryDeviceIntr(SDDevHandle fd, u32 funcId, u8 *intrStatus);

/*
 * ISD_EnableDeviceIntr, ISD_DisableDeviceIntr Enable or disable the
 * specified device interrupt
 * 
 * These two functions simply enable or disable the device interrupt
 * signal.
 */
extern IOSError ISD_EnableDeviceIntr(SDDevHandle fd);
extern IOSError ISD_DisableDeviceIntr(SDDevHandle fd);

/*
 * ISD_RegisterDeviceIntrHandler, ISD_UnregisterDeviceIntrHandler
 * Register or unregsiter the device interrupt handler with the host
 * driver.
 * 
 * The host driver maintains a table of call-back routines and
 * executes a call-back upon receiving an interrupt from the
 * card. There are two levels of interrupt. The host controller raises
 * interrupts in response to various events: card insertion or
 * removal, command completion, command timeout and various command
 * errors.
 *
 * The host controller can also enable an interrupt from the card, and
 * it will raise an interrupt when the card raises an interrupt.  It
 * is this second interrupt for which the device driver can register a
 * callback function.
 *
 * Interrupts raised by the host controller are either handled
 * invisibly by the host driver, e.g. card insertion and removal, or
 * they are reflected in status returned through the API, e.g. success
 * or fail when the host controller receives a command completion or a
 * command error interrupt.
 *
 * SDCallbackFunc is the definition of an interrupt handler or
 * callback function. The function will be called with a bitmap giving
 * details of the event (exact definition is TBD).
 */
extern IOSError ISD_RegisterDeviceIntrHandler(SDDevHandle fd, 
                               SDCallbackFunc handler, void *arg);
extern IOSError ISD_UnregisterDeviceIntrHandler(SDDevHandle fd);


/*
 * ISD_RegisterDeviceRemovalHandler,
 * ISD_UnregisterDeviceRemovalHandler Register or unregister the
 * device removal handler with the host driver
 * 
 * Register a call-back handler to be called if and when host driver
 * detects device removal.  Nothing is done in the case of
 * non-removable/hardwired devices.
 *
 * The host controller maintains a table of registered call-back
 * routines.  When a card removal interrupt is raised by the host
 * controller, the host driver handles the interrupt reset
 * clock/power, disable interrupts on the slot, etc - and then calls
 * the registered call-back routine, if one is registered. This gives
 * the device driver an opportunity to perform clean-up.
 */
extern IOSError ISD_RegisterDeviceRemovalHandler(SDDevHandle fd, 
                                       SDCallbackFunc handler, void *arg);
extern IOSError ISD_UnregisterDeviceRemovalHandler(SDDevHandle fd);


/*
 * ISD_RegisterDeviceErrorHandler, ISD_UnregisterDeviceErrorHandler
 * Register or unregister the device error handler with the host
 * driver/
 * 
 * Register a callback to be called if and when host driver detects
 * device error.  A typical use would be to register a call-back
 * routine in order to be informed about a command timeout or other
 * error.
 *
 * The host controller maintains a table of registered call-back
 * routines.  If an error occurs the host driver handles the error
 * interrupt - command timeout, command CRC failure, command index
 * mismatch and then calls the registered call-back routine, if one is
 * registered.  This gives the device driver an opportunity to perform
 * clean-up.
 */
extern IOSError ISD_RegisterDeviceErrorHandler(SDDevHandle fd, 
                                   SDCallbackFunc handler, void *arg);
extern IOSError ISD_UnregisterDeviceErrorHandler(SDDevHandle fd);


/*
 * ISD_ReadReg, ISD_WriteReg For SDIO card, read and write device
 * register using CMD52
 * 
 * These functions access the device registers via CMD52 for SDIO
 * cards. The size is 1 byte. The host driver executes the read or
 * writes with one or more CMD52 and handles command completion and
 * error notification.
 */
extern IOSError ISD_ReadReg(SDDevHandle fd, u32 addr, u32 *data);
extern IOSError ISD_WriteReg(SDDevHandle fd, u32 addr, u32 data);


/*
 * ISD_ReadMultiReg, ISD_WriteMultiReg For SDIO card, read and write
 * multiple device registers using CMD53.
 * 
 * These functions access the device registers via CMD53 for SDIO
 * cards. The size can be 2 or 4 bytes. The host driver is responsible
 * for setting up the command, length and address registers, and for
 * handling command completion and error notification. The operation
 * transfers 'count' bytes to/from data buffer from/to address
 * with the flag set to increment address or not.
 */
extern IOSError ISD_ReadMultiReg(SDDevHandle fd, u32 addr, 
                                 u32 count, u32 incrFlag, u32 *data, u32 dma);
extern IOSError ISD_WriteMultiReg(SDDevHandle fd, u32 addr, 
                                  u32 count, u32 incrFlag, u32 *data, u32 dma);

/*
 * ISD_GetHCRegister, ISD_SetHCRegister For SDIO card, read and write
 * controller register.
 * 
 * These functions access the host controller registers. The size is 
 * 1, 2 or 4 byte.    This API can be used to implement host controller
 * operations at a low level.
 */
extern IOSError ISD_GetHCRegister(SDDevHandle fd, u32 addr, u32 *data, u32 size);
extern IOSError ISD_SetHCRegister(SDDevHandle fd, u32 addr, u32 *data, u32 size);

/*
 * This function sets the bus width for the device (and host) to be
 * either SD_BW_1BIT or SD_BW_4BIT.  The function returns the actual
 * bus width (in busWidth) that can be configured successfully. For
 * example, the caller can request a setting of 4-bit SD mode but the
 * device can only support 1-bit mode.
 */
extern IOSError ISD_SetBusWidth (SDDevHandle fd, u32 *busWidth);

/*
 * This function sets the desired block length for the device. If
 * blockLength exceeds the maximum block length supported by the
 * device, then the maximum length is set as the default value.  Based
 * on the device interface type (memory or IO), this function
 * internally sets the corresponding block length for the
 * corresponding device. For SD Memory Card, the default block length
 * is 512 bytes.
 */
extern IOSError ISD_SetBlockLength (SDDevHandle fd, u32 blockLength);


#endif /* _SDIO_API_H_ */

/* eof */
