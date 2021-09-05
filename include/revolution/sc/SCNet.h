/*---------------------------------------------------------------------------*
  Project:  SC library
  File:     SCNet.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __SCNET_H__
#define __SCNET_H__

#include <revolution/sc.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef IP_ALEN
#define IP_ALEN 4
#endif

#define SC_NET_SIZE_SSID                    32
#define SC_NET_USBAP_NICKNAME_LENGTH    11
#define SC_NET_PPPOE_SERVICENAME_LENGTH 128
#define SC_NET_PPPOE_USERNAME_LENGTH 256
#define SC_NET_PPPOE_PASSWORD_LENGTH 256
enum
{
    SC_NET_LINK_TYPE_AUTO               = 0x00,
    SC_NET_LINK_TYPE_10BASE_T           = 0x01,
    SC_NET_LINK_TYPE_100BASE_TX         = 0x02          /* half-duplexは不要? USB-Etherにあわせる*/
} SCNetLinkType;

enum
{
    SC_NET_PRIVACY_MODE_NONE            = 0x0000,       /* 暗号化なし */
    SC_NET_PRIVACY_MODE_WEP40           = 0x0001,       /* WEP ( RC4 40bit ) 暗号 */
    SC_NET_PRIVACY_MODE_WEP104          = 0x0002,       /* WEP ( RC4 104bit ) 暗号 */
    SC_NET_PRIVACY_MODE_TKIP            = 0x0004,       /* WPA-PSK ( TKIP ) 暗号 */
    SC_NET_PRIVACY_MODE_AES             = 0x0005        /* WPA-PSK ( AES ) 暗号 */
} SCNetPrivacyMode;

enum
{
    SC_NET_CONF_METHOD_MANUAL           = 0x00,
    SC_NET_CONF_METHOD_USBAP            = 0x01,
    SC_NET_CONF_METHOD_AOSS             = 0x02,
    SC_NET_CONF_METHOD_RAKURAKU         = 0x03,
    SC_NET_CONF_METHOD_SIMPLECONFIG     = 0x04
} SCNetConfMethod;

typedef struct SCNetPrivacy
{
    u16     mode;               /* SCNetPrivacyMode */
    union
    {
        struct
        {
            u16     keyId;
            u8      key[ 4 ][ 5 ];
        } wep40;
        struct
        {
            u16     keyId;
            u8      key[ 4 ][ 13 ];
        } wep104;
        struct
        {
            u16     keyLen;
            u8      key[ 64 ];
        } tkip;
        struct
        {
            u16     keyLen;
            u8      key[ 64 ];
        } aes;
    };
} SCNetPrivacy;

typedef struct SCNetAossConfig_
{
    struct
    {
        u16     keyId;
        u8      key[ 4 ][ 5 ];
        u16     ssidLength;
        u8      ssid[ SC_NET_SIZE_SSID ];
    } wep40;
    struct
    {
        u16     keyId;
        u8      key[ 4 ][ 13 ];
        u16     ssidLength;
        u8      ssid[ SC_NET_SIZE_SSID ];
    } wep104;
    struct
    {
        u16     keyLen;
        u8      key[ 64 ];
        u16     ssidLength;
        u8      ssid[ SC_NET_SIZE_SSID ];
    } tkip;
    struct
    {
        u16     keyLen;
        u8      key[ 64 ];
        u16     ssidLength;
        u8      ssid[ SC_NET_SIZE_SSID ];
    } aes;
} SCNetAossConfig;

typedef struct SCNetApConfig_
{
    SCNetPrivacy   privacy;
    u16         ssidLength;
    u8          ssid[ SC_NET_SIZE_SSID ];
} SCNetApConfig;

typedef struct SCNetUsbapConfig_
{
    u16     nickname[ SC_NET_USBAP_NICKNAME_LENGTH ];  /* ニックネームは保存する？ */
} SCNetUsbapConfig;


#define SC_NET_FLAG_IS_WIRED           0x01;
#define SC_NET_FLAG_USE_DHCP_ADDR      0x02;
#define SC_NET_FLAG_USE_DHCP_DNS       0x04;
#define SC_NET_FLAG_USE_PPPOE          0x08;
#define SC_NET_FLAG_USE_PROXY          0x10;
#define SC_NET_FLAG_USE_PMTU_RECOVER   0x20; /* する? */
#define SC_NET_FLAG_ENABLE             0x80; 

#define SC_NET_PROXYNAME_LENGTH 256
#define SC_NET_NO_PROXY_LENGTH 1024
#define SC_NET_AUTOMATIC_PROXY_LENGTH 256

typedef struct SCNetProfile_
{
    u8              flags;
    
    struct
    {
        u8      addr[IP_ALEN];          /* フィールドが0なら自動取得とする? */
        u8      netmask[IP_ALEN];       /* cidrで格納? */
        u8      gateway[IP_ALEN];       /*                                  */
        u8      dns1[IP_ALEN];          /* フィールドが0なら自動取得とする? */
        u8      dns2[IP_ALEN];          /*                                  */
    } ip;
    
    struct
    {
        struct
        {
            char    server[ SC_NET_PROXYNAME_LENGTH ];
            u16     port;
        } http, https, ftp;
        struct
        {
            char     servers[ SC_NET_NO_PROXY_LENGTH];
            BOOL     isEnabled;
        } no;
        struct
        {
            BOOL isEnabled1_1;
            BOOL isAutomaticEnabled;
            char automatic[ SC_NET_AUTOMATIC_PROXY_LENGTH ];
        } browser;
    } proxy;
    
    struct
    {
        u8          servicename[ SC_NET_PPPOE_SERVICENAME_LENGTH ];
        u8          username[ SC_NET_PPPOE_USERNAME_LENGTH ];
        u8          password[ SC_NET_PPPOE_PASSWORD_LENGTH ];
    } pppoe;
    
    union
    {
        struct
        {
            u8              linkType;       /* 値だけ格納しておく？ */
        } wired;
        struct
        {
            u16             rateset;        /* 値だけ格納しておく？ */
            u8              configMethod;   /* SCNetConfMethod */
            union
            {
                SCNetApConfig          manual;
                SCNetUsbapConfig       usbap;
                SCNetAossConfig        aoss;
                SCNetApConfig          rakuraku;
            } config;
        } wireless;
    };
} SCNetProfile;

#define SC_NET_SELECT_NONE         0x00
#define SC_NET_SELECT_WIRELESS     0x01
#define SC_NET_SELECT_WIRED        0x02
#define SC_NET_PROFILE_COUNT 3

typedef struct SCNetConfig_
{
    u8          selectedMedia;
    SCNetProfile  profiles[ SC_NET_PROFILE_COUNT ];
} SCNetConfig;



//////////////////////////////////////////////////////////////////////
// For now, the strucure sizes are not fixed.
// So, they can be passed via external variables.

extern u32 __SCNetConfigSize = sizeof(SCNetConfig);
extern u32 __SCNetProfileSize = sizeof(SCNetProfile);

extern BOOL SCGetNetConfig(SCNetConfig *info);
extern BOOL SCSetNetConfig(const SCNetConfig *info);
extern BOOL SCGetNetProfile(SCNetProfile *info);
extern BOOL SCSetNetProfile(const SCNetProfile *info);

#ifdef __cplusplus
}
#endif

#endif // __SCNET_H__
