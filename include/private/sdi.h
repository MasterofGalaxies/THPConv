/*
 *               Copyright (C) 2006, BroadOn Communications Corp.
 *
 *  These coded instructions, statements, and computer programs contain
 *  unpublished  proprietary information of BroadOn Communications Corp.,
 *  and  are protected by Federal copyright law. They may not be disclosed
 *  to  third  parties or copied or duplicated in any form, in whole or in
 *  part, without the prior written consent of BroadOn Communications Corp.
 *
 */
#ifndef __SDI_H__
#define __SDI_H__

#include <private/iostypes.h>

#define SD_IOWHCREG         1
#define SD_IORHCREG         2
#define SD_IORCREG          3
#define SD_RESET            4
#define SD_IOWCREG          5
#define SD_SETCLK           6
#define SD_CMD              7 
#define SD_SET_BUS_WIDTH    8 
#define SD_IORMCREG         9 
#define SD_IOWMCREG         10
#define SD_GET_STATUS       11
#define SD_GET_OCR          12
#define SD_READ_DATA        13
#define SD_WRITE_DATA       14

/*
 * Status bits for device status query
 */
#define SD_CARD_INSERTED   0x00000001
#define SD_CARD_REMOVED    0x00000002
#define SD_CARD_WPROTECTED 0x00000004
#define SD_STATE_SUSPEND   0x00000008
#define SD_STATE_BUSY      0x00000010
#define SD_TYPE_UNKNOWN    0x00000000
#define SD_TYPE_MEMORY     0x00010000
#define SD_TYPE_SDIO       0x00020000
#define SD_TYPE_COMBO      0x00040000
#define SD_TYPE_MMC        0x00080000

/*
 * enum for response types used in command() calls
 */
typedef enum  _SDIResponse
{
    NoResponse  = 0,
    ResponseR1  = 1,
    ResponseR1b = 2,
    ResponseR2  = 3,
    ResponseR3  = 4,
    ResponseR4  = 5,
    ResponseR5  = 6,
    ResponseR6  = 7
} SDIResponse;

#define SDI_RESP_REGS 4

/* Regiter call configuration */
typedef struct _SDIReg {
    u32 reg;        /* Register Address */
    u32 blk_size;   /* Block Size       */
    u32 blk_num;    /* Number of Blocks */
    u32 width;
    u32 value;      /* writing register */
    u32 dma;        
} SDIReg;

/*
 * SDIcmd
 * 
 * Command Type Structure, used extensively by the SD card driver.
 * 
 * command:         command number 1..63 to execute.
 * commmand type:   read write.
 * response type:   see SDIResponse.
 * req_size:        for block copy.
 * 
 * Structure used to call the following function:
 * 
 * do_command (handle , int cmd, int cmd_type, 
 *           int resp_type, int req_size, int cmd_arg, int sys_addr,
 *           int blk_count, int blk_size, int dma, )
 */
 
typedef struct _SDCmd {
    u32 command;    /* command number 1..63 to execute. */
    u32 cmd_type;   /* command types */
    u32 resp_type;
    u32 cmd_arg;
    u32 blk_count;
    u32 blk_size;    
    u32 sys_addr;   /* User Buffer Address */
    u32 dma;        /* Use DMA, else memory copy */
    u32 offset;     /* SD Card Address */    
} SDCmd;

/*
 * command types
 */
#define SD_CMD_NONE         0
#define SD_READ             1
#define SD_WRITE            2
#define SD_COMMAND          3

/*
 * Command codes from the SDIO Specification 1.10.
 */
#define SDIO_CMD52          52
#define SDI0_CMD53          53


/*
 * Possible states for SDState
 */
#define SD_SELECT_NO_CARD      0
#define SD_SELECT_SELECTED     1
#define SD_SELECT_DESELECTED   2


/* 
 * error codes 
 */
#define SD_ERROR_OK         0               /* Success */
#define SD_ERROR_FAIL       0xC1000000      /* General SD Error code - to be expanded */
#define SD_ERROR_SWTIMEOUT  0xC1000001      /* Software Reset (host controller) timeout */
#define SD_ERROR_IRQ        0xC1000002      /* Unspecified IRQ Error */
#define SD_ERROR_TIMEOUT    0xC1000003      /* Command Timed Out */
#define SD_ERROR_REMOVE     0xC1000004      /* Card removed while data transfer busy */
#define SD_ERROR_BUSY       0xC1000005      /* SD Card busy with command */
#define SD_ERROR_HC         0xC1000020      /* SD Card is SDHC card */

#define SD_ERROR_EVENT      0xC2000000      /* Event Register while another has been registered */
#define SD_ERROR_EVENT_CLR  0xC2100000      /* Event Cleared */

#endif /* __SDI_H__ */

/* eof */
