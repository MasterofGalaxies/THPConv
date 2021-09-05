/*---------------------------------------------------------------------------*
  Project:      MDM API
  File:         mdm.h

  Copyright 2000 Nintendo.      All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.      They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/05/12 02:41:07  yasuh-to
  dolphinシースツリーから移植

    
    7     04/06/25 16:56 Ueno_kyu
    Added MDM_ERR_DIALNO_TOOLONG.
    
    6     6/23/04 13:36 Shiki
    Added const to MDMInit() countryCode argument.

    5     04/06/22 17:41 Ueno_kyu
    Added MDMHangUpAsync() and modem status.

    3     03/03/03 10:44 Ikedae

    2     03/03/03 9:31 Ikedae
    removed MDM_CC_JAPAN and MDM_CC_US

    1     02/03/13 8:51 Ikedae

        6.        1/15/02 9:14a ikedae
        Added MDM_ERR_PROHIBITED
        Removed MDM_ERR_ALREADYINITIALIZED

        5.        3/26/01 2:20p ikedae
        Added MDM_CB_RING

        4.        2/21/01 3:55p ikedae
        Removed MDMDestroy from header

        3.        2/06/01 2:40p ikedae
        Added MDMRecvSync etc.

        2         1/24/01 1:17p ikedae
        Modified MDMGetStatus

        1         9/12/00 1:17p Shiki
        Initial check-in.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/


#pragma once

#ifndef __MDM_H__
#define __MDM_H__

// public structure

typedef void (*MDMCallback)(s32 para);

// pointers should be 32byte alligned whenever possible, for better performance.
// size also to be multiply of 32 byte

enum
{
        MDM_DIAL_TONE = 1,
        MDM_DIAL_PULSE_10,
        MDM_DIAL_PULSE_20
};

#define MDM_OK                  1
#define MDM_CONNEXANT   1

enum {
        MDM_CN_V90 = 1,
        MDM_CN_V34,
        MDM_CN_V32B,
        MDM_CN_V22B,
        MDM_CN_PIAFS
        };

enum {
        MDM_EC_V42 = 1,
        MDM_EC_MNP,
        MDM_EC_DIRECT
        };

enum {
        MDM_CM_V42B = 1,
        MDM_CM_MNP5,
        MDM_CM_NONE,
        MDM_CM_BOTH
        };

enum {
        MDM_WT_IGNORETONE = 1,
        MDM_WT_WAITTONE
        };

typedef struct MDM_CONNECTSTAT
{
        s32 dtespeed;
        s32 txspeed;
        s32 rxspeed;
        u8 modulation[5];
        u8 protocol[5];
        u8 compress[5];
} MDM_CONNECTSTAT;

// MDM API error code (negative value)
#define MDM_ERR_NOMODEM                 -1
#define MDM_ERR_NOSUCHMODE              -2
#define MDM_ERR_STATE                   -3
#define MDM_ERR_SENDBUSY                -4
#define MDM_ERR_RECVBUSY                -5
#define MDM_ERR_ATERROR                 -6
#define MDM_ERR_NOTCONNECTED    -7
// #define MDM_ERR_ALREADYINITIALIZED   -8              // 2002.1.15版より削除
#define MDM_ERR_PROHIBITED              -8
#define MDM_ERR_DIALNO_TOOLONG          -9


// modem status register        (for MDMGetRawStatus)
#define MDM_MSR_DCD             0x80
#define MDM_MSR_RI              0x40
#define MDM_MSR_DSR             0x20
#define MDM_MSR_CTS             0x10
#define MDM_MSR_DDCD    0x08
#define MDM_MSR_DRI             0x04
#define MDM_MSR_DDSR    0x02
#define MDM_MSR_DCTS    0x01

// modem status
enum {
        MDM_STATUS_NOTINITIALIZED = 0,
        MDM_STATUS_NOTCONNECTED,
        MDM_STATUS_DIALING,
        MDM_STATUS_CONNECTED,
        MDM_STATUS_MORIBUND,
        MDM_STATUS_SHUTDOWN
        };

// modem callback parameter
enum {
        MDM_CB_NODIALTONE = 0,
        MDM_CB_NOCARRIER,
        MDM_CB_BUSY,
        MDM_CB_CONNECT,
        MDM_CB_RING,
        MDM_CB_NOANSWER,
        MDM_CB_DELAYED,
        MDM_CB_BLACKLISTED
        };


// error status register        (for MDMGetESR)
#define MDM_ESR_DATARXUNR       0x80
#define MDM_ESR_DATARXOVR       0x40
#define MDM_ESR_DATATXUNR       0x20
#define MDM_ESR_DATATXOVR       0x10
#define MDM_ESR_ATRXUNR         0x08
#define MDM_ESR_ATRXOVR         0x04
#define MDM_ESR_ATTXUNR         0x02
#define MDM_ESR_ATTXOVR         0x01

#ifdef __cplusplus
extern "C" {
#endif
extern s32      MDMInit(const char* countrycode);

extern s32      MDMDial(char *dialstr, s32 dialmode, MDMCallback cb);
extern s32      MDMAnswer(MDMCallback cb);       // answer to the RING
extern void     MDMHangUp(void);
extern void     MDMHangUpAsync(MDMCallback cb);

extern s32      MDMChangeThreshold(s32 txth, s32 rxth);
extern void     MDMSetFWT(s32 fwt);

extern s32      MDMSend(u8 *buf, s32 len, MDMCallback sndCallback);
extern BOOL     MDMSendBusy(void);

extern s32      MDMRecv(u8 *buf, s32 maxlen, MDMCallback rcvCallback);
extern s32      MDMRecvSync(u8 *buf);

extern s32      MDMGetStatus(MDM_CONNECTSTAT *stat);

extern s32      MDMConnectMode(s32 mode);
extern s32      MDMErrorCorrectMode(s32 mode);
extern s32      MDMCompressMode(s32 mode);
extern s32      MDMWaitToneMode(s32 mode);

// for better independecy from the specific modem model, AT command should not
// be issued as possible

// some CONNEXANT modem specific procedures are from here
extern s32      MDMATCommand   (char *atcmd);
extern BOOL     MDMATBusy(void);
extern u8       MDMGetRawStatus (void);       // represent LED of usual modem
                                                                        // this status should not be used for flow
                                                                        // control etc.
extern u8       MDMGetESR(void);
extern s32      MDMGetLibraryVersion(void);
#ifdef __cplusplus
}
#endif

#define MDM_DATAFIFOSIZE                512
#define MDM_DEFAULT_RXTH                480
#define MDM_DEFAULT_TXTH                33              // 32 + 1       because FIFOCOUNT < THRESHOLD

#endif // __MDM_H__
