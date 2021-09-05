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
 * $Id Exp $
 */

#ifndef _SD_API_H_
#define _SD_API_H_

#include <private/sdio_api.h>

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

#define IOS_ERROR_SD_NOCARD	-51 /* No card or card type is inserted */
#define IOS_ERROR_SD_ERR	-52 /* Not SD card, may be SDIO card */


/*
 * ISD_InitCard
 * 
 * This function initializes the SD Memory Card driver.
 */
extern IOSError ISD_InitCard (void);

 

/*
 * ISD_ProbeCard
 * 
 * This function probes the SD slot number to see if there is a SD Memory Card inserted. 
 * RETURN VALUES:
 * If there is a SD memory card inserted in the slot, IOS_ERROR_OK is returned. 
 * Otherwise, a negative error code is returned:
 * IOS_ERROR_INVALID	Invalid argument (not valid slot number)
 * IOS_ERROR_SD_NOCARD	No card or card type is inserted
 * IOS_ERROR_SD_ERR		Any other SD specific failure - Card inserted but not SD type
 * 
 */

extern IOSError ISD_ProbeCard (u32 slotNo);

/*
 * ISD_MountCard
 * 
 * Before an SD Memory Card can be accessed, application needs to mount the card. 
 * After it is used, the Card must be unmounted before it can be removed from the SD slot.  
 * The mount function will return the handle (fd) to the inserted Card. 
 * This handle must be used in all subsequent calls to the SD/SDIO driver. 
 */
extern IOSError ISD_MountCard (u32 slotNo, SDDevHandle *fd);

/*
 * ISD_UnmountCard
 * 
 * Once the card is unmounted, the device handle fd is no longer valid.
 */
extern IOSError ISD_UnmountCard (SDDevHandle fd);


/*
 * #define  SD_REG_RCA 3
#define  SD_REG_CSD 9
#define  SD_REG_CID 10
#define  SD_REG_OCR 41
#define  SD_REG_SCR 51
*/
/*
 * Based on the register type, retrieve the corresponding register info into the 
 * register buffer of buffer length. For SD card, the following registers can be retrieved: 
 * SD_REG_CID, SD_REG_CSD, SD_REG_SCR, SD_REG_OCR, and SD_REG_RCA.
 */
extern IOSError ISD_ReadCardRegister (SDDevHandle fd, u32 regType, u32 *regBuf, u32 bufLen);

/* 
 * ISD_GetCardSize
 * 
 * This function calculates and returns the total size (in bytes), the number of sectors, 
 * and the sector size of the specified SD Card. The sector size is specific to each SD Card 
 * type and should be a multiple of 512 bytes.
 */
extern IOSError ISD_GetCardSize (SDDevHandle fd, u32 *totalSize, u32 *totalSectors, u32 *sectorSize);


/* 
 * These functions either read data from or write data to a designated block on the SD Memory Card. 
 * For single block operation, these functions use CMD17 for read and CMD24 for write. 
 * For multi-block operation, CMD18 and CMD25 are used for read and write operation, respectively. 
 */
extern IOSError ISD_ReadBlock (SDDevHandle fd, u32 offset, u32 *data, u32 length);
extern IOSError ISD_WriteBlock (SDDevHandle fd, u32 offset, u32 data, u32 length);
extern IOSError ISD_ReadBlockAsync (SDDevHandle fd, u32 offset, u32 *data, u32 length, SDCallbackFunc handler, void *arg);
extern IOSError ISD_WriteBlockAsync (SDDevHandle fd, u32 offset, u32 data, u32 length, SDCallbackFunc handler, void *arg);
extern IOSError ISD_ReadMultiBlock (SDDevHandle fd, u32 offset, u32 *data, u32 length);
extern IOSError ISD_WriteMultiBlock (SDDevHandle fd, u32 offset, u32 data, u32 length);
extern IOSError ISD_ReadMultiBlockAsync (SDDevHandle fd, u32 offset, u32 *data, u32 length, SDCallbackFunc handler, void *arg);
extern IOSError ISD_WriteMultiBlockAsync (SDDevHandle fd, u32 offset, u32 data, u32 length, SDCallbackFunc handler, void *arg);

/* 
 * These functions either read data from or write data to a designated sector on the SD Memory Card. 
 */
extern IOSError ISD_ReadSector (SDDevHandle fd, u32 sector, u32 *data, u32 length);
extern IOSError ISD_WriteSector (SDDevHandle fd, u32 sector, u32 data, u32 length);
extern IOSError ISD_ReadSectorAsync (SDDevHandle fd, u32 sector, u32 *data, u32 length, SDCallbackFunc handler, void *arg);
extern IOSError ISD_WriteSectorAsync (SDDevHandle fd, u32 sector, u32 data, u32 length, SDCallbackFunc handler, void *arg);

extern IOSError ISD_EraseSector (SDDevHandle fd, u32 sector);
extern IOSError ISD_EraseAllSectors (SDDevHandle fd);
extern IOSError ISD_EraseSectorAsync (SDDevHandle fd, u32 sector, SDCallbackFunc handler, void *arg);
extern IOSError ISD_EraseAllSectorsAsync (SDDevHandle fd, SDCallbackFunc handler, void *arg);

/* --- some temp bringup external ref --- */
extern IOSError sduCommand (IOSFd fd, 
                u32 command, 
                u32 cmd_type, 
                u32 resp_type,  
                u32 cmd_arg, 
                u32 sys_addr,
                u32 blk_count,
                u32 blk_size,
                u32 dma,                    
                u32 *resp,
                SDCallbackFunc cb, 
                void *arg);
extern IOSError sduStatus(SDDevHandle fd, u32 *devStatus);
extern IOSError sduDatabuswidth(SDDevHandle fd, u32 buswidth);   
extern IOSError sduClockSet(IOSFd ifd, u32 newclk);
/* --- end of temp external ref (to be removed) */

IOSError ISD_GetCardSize (SDDevHandle fd, u32 *totalSize, u32 *totalSectors, u32 *sectorSize);
#endif /* _SD_API_H_ */

/* eof */
