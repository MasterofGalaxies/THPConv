/*---------------------------------------------------------------------------*
  Project:  SC library
  File:     scprivate.h

  Copyright 2006 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.43  2007/09/04 12:40:49  yasuh-to
  Deleted include of include/revolution/sc/SCDvd.h

  Revision 1.42  2007/02/22 05:19:59  tojo
  Added new item "SC_ITEM_ID_BT_CMPDEV_INFO".

  Revision 1.41  2007/01/23 02:41:08  ooizumi
  Moved functions used by boot-IRD to <secure/SCBootIRD.h>.

  Revision 1.40  2006/11/17 05:26:13  kawaset
  Strengthened simple address ID check.

  Revision 1.39  2006/10/30 10:30:05  kawaset
  Added Free/Installed Channel App Count.

  Revision 1.38  2006/10/24 04:54:47  kawaset
  Added WCFlags.

  Revision 1.37  2006/10/23 12:55:59  kawaset
  Added EULA, ConfigDone2. Moved SetSoundMode, SetProgressiveMode, SetEuRgb60Mode, GetWpad*, and SetWpad* to private.

  Revision 1.36  2006/10/11 05:28:46  kawaset
  Added rating OFLC_MA15.

  Revision 1.35  2006/09/28 10:53:06  kawaset
  Added SCGet/SetUpdateType().

  Revision 1.34  2006/09/20 12:37:47  kawaset
  Added SC_NET_CONTENT_RESTRICTION_MASK_NEWS.

  Revision 1.33  2006/09/13 07:37:01  kawaset
  Added SCGet/SetConfigDoneFlag().

  Revision 1.32  2006/09/13 04:17:26  kawaset
  Added LED brightness level.

  Revision 1.31  2006/09/06 16:13:26  ooizumi
  Added drive saving mode setting for devkit.

  Revision 1.30  2006/09/05 07:34:36  kawaset
  Added __SCClearConfBuf().

  Revision 1.29  2006/09/05 05:17:56  kawaset
  Changed SCParentalControlInfo.

  Revision 1.28  2006/09/04 02:27:33  kawaset
  Added SCGetProductAreaString().

  Revision 1.27  2006/08/29 04:59:15  kawaset
  (none)

  Revision 1.26  2006/08/29 01:03:21  kawaset
  Added SimpleAddress, NetContentRestrictions, and WCRestriction.

  Revision 1.25  2006/08/22 04:47:03  kawaset
  Added owner nickname.

  Revision 1.24  2006/08/22 01:02:07  kawaset
  Moved SCBtDeviceInfoArray.

  Revision 1.23  2006/08/16 02:50:34  ooizumi
  Added SCGetProductVideoMode and SCGetProductGameRegion.

  Revision 1.22  2006/08/09 12:40:07  kawaset
  Added comment.

  Revision 1.21  2006/08/08 12:42:08  kawaset
  Added SCGetWpadMotorMode, SCGetWpadSensorBarPosition, SCGetWpadSpeakerVolume, SCSetWpadMotorMode, SCSetWpadSensorBarPosition, and SCSetWpadSpeakerVolume.
  Deleted SCEmuSetAspectRatio and SCEmuSetLanguage.

  Revision 1.20  2006/07/25 04:52:45  kawaset
  Added MP Channel.

  Revision 1.19  2006/07/24 00:57:22  kawaset
  Added BtDpdSensibility.

  Revision 1.18  2006/07/21 12:02:21  ooizumi
  Added new country code for devkit.

  Revision 1.17  2006/07/19 13:23:12  kawaset
  Added test version of production information API.

  Revision 1.16  2006/06/21 11:28:43  kawaset
  Supported DVD movie region, WWW parental control, and product information file emulation.

  Revision 1.15  2006/06/07 06:26:45  ooizumi
  Added NDEV settings.
  - video mode ... NTSC/PAL
  - country code ... JP/US/EU

  Revision 1.14  2006/06/06 07:24:26  kawaset
  Added DVD player.

  Revision 1.13  2006/06/05 13:42:49  tojo
  Modified SCBtDeviceInfoArray.

  Revision 1.12  2006/06/05 10:34:23  kawaset
  Added BtDeviceInfoArray.

  Revision 1.11  2006/06/05 03:00:36  ooizumi
  Added boot mode for devkit.

  Revision 1.10  2006/06/01 11:08:34  kawaset
  Deleted timezone.

  Revision 1.9  2006/05/30 12:08:58  ooizumi
  Added counter bias to set OS time.

  Revision 1.8  2006/05/29 01:02:46  kawaset
  Full model change.

  Revision 1.7  2006/02/09 09:25:27  kawaset
  Changed prototype.

  Revision 1.6  2006/02/09 07:27:18  kawaset
  Moved SCType defines from <revolution/sc.h>.

  Revision 1.5  2006/02/09 02:01:17  kawaset
  Changed SCParentalControlInfo

  Revision 1.4  2006/02/09 01:54:05  kawaset
  Changed SCParentalControlInfo

  Revision 1.3  2006/02/09 01:25:08  kawaset
  Added missing prototypes.

  Revision 1.2  2006/02/07 01:12:16  kawaset
  Moved SCFind*Conf, SCReplace*Conf from scCommoni.h to scprivate.h

  Revision 1.1  2006/02/03 12:57:03  kawaset
  Initial check-in.


  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __SCPRIVATE_H__
#define __SCPRIVATE_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <revolution/sc.h>

//////////////////////////////////////////////////////////////////////
// How to add new SC item:
//
// 1. Insert a new SC item ID, which is the enum definition,
//    to this file (SCItemID).
//    Note that SC_ITEM_ID_MAX_PLUS1 must be the last one.
//    The order doesn't matter.
//    Because at application run time, the item name string is looked up
//    and reference table (from ID to item) is generated by library.
//
// 2. Open build/libraries/sc/src/scsystem.c and add item definition
//    in NameAndIDTbl[].
//    Be sure not to use the existing item name.
//    The definition order doesn't matter either.
//
// 3. Implement SCGet*() and SCSet*() for the new SC item.
//    Open build/libraries/src/scapi.c and add them.
//
// 4. Finally, add function prototypes to the header.
//    What file to add? It's depend on API disclosure level:
//
//    A. Completely private
//         - include/private/scprivate.h (this file)
//
//    B. Public to some limited developers
//         - create new file include/revolution/sc/SC*.h
//           and distribute it to them.
//
//    C. Public to all developers
//         - create include/revolution/sc/SC*.h
//           or add to existing header files.
//         - if need, edit include/revolution/sc.h to
//           add typedefs and/or #include <revoluton/sc/SC*.h>
//           directive.

typedef enum {
    // The order doesn't matter.
    // At runtime, reference table is generated dynamically.

    // Class IPL: general preference
    SC_ITEM_ID_IPL_COUNTER_BIAS,
    SC_ITEM_ID_IPL_ASPECT_RATIO,
    SC_ITEM_ID_IPL_AUTORUN_MODE,
    SC_ITEM_ID_IPL_CONFIG_DONE,
    SC_ITEM_ID_IPL_CONFIG_DONE2,
    SC_ITEM_ID_IPL_DISPLAY_OFFSET_H,
    SC_ITEM_ID_IPL_EURGB60_MODE,
    SC_ITEM_ID_IPL_EULA,
    SC_ITEM_ID_IPL_FREE_CHANNEL_APP_COUNT,
    SC_ITEM_ID_IPL_IDLE_MODE,
    SC_ITEM_ID_IPL_INSTALLED_CHANNEL_APP_COUNT,
    SC_ITEM_ID_IPL_LANGUAGE,
    SC_ITEM_ID_IPL_OWNER_NICKNAME,
    SC_ITEM_ID_IPL_PARENTAL_CONTROL,
    SC_ITEM_ID_IPL_PROGRESSIVE_MODE,
    SC_ITEM_ID_IPL_SCREEN_SAVER_MODE,
    SC_ITEM_ID_IPL_SIMPLE_ADDRESS,
    SC_ITEM_ID_IPL_SOUND_MODE,
    SC_ITEM_ID_IPL_UPDATE_TYPE,
//    SC_ITEM_ID_IPL_TIMEZONE_EMU, // 060601 deleted

    // Class NET: network
    SC_ITEM_ID_NET_CONFIG,
    SC_ITEM_ID_NET_CONTENT_RESTRICTIONS,
    SC_ITEM_ID_NET_PROFILE,
    SC_ITEM_ID_NET_WC_RESTRICTION,
    SC_ITEM_ID_NET_WC_FLAGS,

    // Class DEV: devkit
    SC_ITEM_ID_DEV_BOOT_MODE,
    SC_ITEM_ID_DEV_VIDEO_MODE,
    SC_ITEM_ID_DEV_COUNTRY_CODE,
    SC_ITEM_ID_DEV_DRIVESAVING_MODE,

    // Class BT: wireless controller
    SC_ITEM_ID_BT_DEVICE_INFO,
    SC_ITEM_ID_BT_CMPDEV_INFO,
    SC_ITEM_ID_BT_DPD_SENSIBILITY,
    SC_ITEM_ID_BT_SPEAKER_VOLUME,
    SC_ITEM_ID_BT_MOTOR_MODE,
    SC_ITEM_ID_BT_SENSOR_BAR_POSITION,

    // Class DVD: DVD player
    SC_ITEM_ID_DVD_CONFIG,

    // Class WWW: web browser
    SC_ITEM_ID_WWW_RESTRICTION,

    // Insert new classes here...


    //////////////////////////////////////////////////////////////////////
    // DO NOT ADD ENUMS BELOW THIS LINE !!!!
    // SC_ITEM_ID_MAX_PLUS1 must be the last enum.
    //////////////////////////////////////////////////////////////////////
    SC_ITEM_ID_MAX_PLUS1
} SCItemID;


//////////////////////////////////////////////////////////////////////

typedef u8 SCType;
// 0x00 and 0x20 are used in build/libraries/sc/include/scCommoni.h
#define SC_TYPE_BYTE_ARRAY     ((SCType)0x40)
#define SC_TYPE_U8             ((SCType)0x60)
#define SC_TYPE_S8             SC_TYPE_U8
#define SC_TYPE_U16            ((SCType)0x80)
#define SC_TYPE_S16            SC_TYPE_U16
#define SC_TYPE_U32            ((SCType)0xa0)
#define SC_TYPE_S32            SC_TYPE_U32
#define SC_TYPE_U64            ((SCType)0xc0)
#define SC_TYPE_S64            SC_TYPE_U64
#define SC_TYPE_BOOL           ((SCType)0xe0) // data = 1 Byte

//////////////////////////////////////////////////////////////////////

extern u32 SCGetCounterBias(void);
extern BOOL SCSetCounterBias(u32 bias);

// 060601 deleted
// extern BOOL SCSetTimeZone(const SCTimeZoneInfo *tz);

extern BOOL SCSetSoundMode(u8 mode);
extern BOOL SCSetProgressiveMode(u8 mode);
extern BOOL SCSetEuRgb60Mode(u8 mode);

extern BOOL SCSetLanguage(u8 language);

#define SC_DISPLAY_OFFSET_H_DEFAULT 0
#define SC_DISPLAY_OFFSET_H_MIN     (-32)
#define SC_DISPLAY_OFFSET_H_MAX     32

extern s8 SCGetDisplayOffsetH(void);
extern BOOL SCSetDisplayOffsetH(s8 offset);

extern BOOL SCSetAspectRatio(u8 ratio);

#define SC_SCREEN_SAVER_MODE_OFF     0u
#define SC_SCREEN_SAVER_MODE_ON      1u
#define SC_SCREEN_SAVER_MODE_DEFAULT SC_SCREEN_SAVER_MODE_ON

extern u8 SCGetScreenSaverMode(void);
extern BOOL SCSetScreenSaverMode(u8 mode);

#define SC_AUTORUN_MODE_OFF         0u
#define SC_AUTORUN_MODE_ON          1u
#define SC_AUTORUN_MODE_DEFAULT     SC_AUTORUN_MODE_OFF

extern u8 SCGetAutorunMode(void);
extern BOOL SCSetAutorunMode(u8 mode);

// before SDK 2.1 patch1 and older
// #define SC_PARENTAL_CONTROL_REGION_ZERO     0u
// 
// #define SC_PARENTAL_CONTROL_RATING_DEFAULT  20u
// 
// #define SC_PARENTAL_CONTROL_PASSWORD_LENGTH 4
// #define SC_PARENTAL_CONTROL_PASSWORD_DEFAULT "0000"
// 
// typedef struct {
//   u8    region;
//   u8    rating;
//   char  password[SC_PARENTAL_CONTROL_PASSWORD_LENGTH];
// } SCParentalControlInfo;

// after SDK 2.2
#define SC_PARENTAL_CONTROL_FLAG_USE            0x80
#define SC_PARENTAL_CONTROL_FLAG_ENABLE_RP      0x40
#define SC_PARENTAL_CONTROL_FLAG_ESRB_NOTICE    0x20
#define SC_PARENTAL_CONTROL_FLAG_RESERVED4      0x10
#define SC_PARENTAL_CONTROL_FLAG_RESERVED3      0x08
#define SC_PARENTAL_CONTROL_FLAG_RESERVED2      0x04
#define SC_PARENTAL_CONTROL_FLAG_RESERVED1      0x02
#define SC_PARENTAL_CONTROL_FLAG_RESERVED0      0x01

#define SC_PARENTAL_CONTROL_OGN_CERO            0
#define SC_PARENTAL_CONTROL_OGN_ESRB            1
#define SC_PARENTAL_CONTROL_OGN_RESERVED2       2
#define SC_PARENTAL_CONTROL_OGN_USK             3
#define SC_PARENTAL_CONTROL_OGN_PEGI_GENERAL    4
#define SC_PARENTAL_CONTROL_OGN_PEGI_FINLAND    5
#define SC_PARENTAL_CONTROL_OGN_PEGI_PORTUGAL   6
#define SC_PARENTAL_CONTROL_OGN_PEGI_BBFC       7
#define SC_PARENTAL_CONTROL_OGN_OFLC            8
#define SC_PARENTAL_CONTROL_OGN_GRB             9
#define SC_PARENTAL_CONTROL_OGN_RESERVED10      10
#define SC_PARENTAL_CONTROL_OGN_RESERVED11      11
#define SC_PARENTAL_CONTROL_OGN_RESERVED12      12
#define SC_PARENTAL_CONTROL_OGN_RESERVED13      13
#define SC_PARENTAL_CONTROL_OGN_RESERVED14      14
#define SC_PARENTAL_CONTROL_OGN_RESERVED15      15

#define SC_PARENTAL_CONTROL_OGN_MAX             16

#define SC_PARENTAL_CONTROL_RATING_OFLC_MA15    15
#define SC_PARENTAL_CONTROL_RATING_OFLC_M       14
#define SC_PARENTAL_CONTROL_RATING_OFLC_PG      7
#define SC_PARENTAL_CONTROL_RATING_OFLC_G       0

#define SC_PARENTAL_CONTROL_RATING_GRB_18       18
#define SC_PARENTAL_CONTROL_RATING_GRB_15       15
#define SC_PARENTAL_CONTROL_RATING_GRB_12       12
#define SC_PARENTAL_CONTROL_RATING_GRB_ALL      0

#define SC_PARENTAL_CONTROL_PASSWORD_LENGTH     4
#define SC_PARENTAL_CONTROL_PASSWORD_DEFAULT    "0000"

#define SC_PARENTAL_CONTROL_SECRET_ANSWER_LENGTH_MIN 6
#define SC_PARENTAL_CONTROL_SECRET_ANSWER_LENGTH_MAX 32

typedef struct {
    u8      flags;
    u8      ogn;
    u8      rating;
    char    password[SC_PARENTAL_CONTROL_PASSWORD_LENGTH]; // fixed length, not zero-terminated
    u8      secretQuestion;
    u16     secretAnswer[SC_PARENTAL_CONTROL_SECRET_ANSWER_LENGTH_MAX]; // not zero-terminated
    u16     secretAnswerLength;
} SCParentalControlInfo;

extern BOOL SCGetParentalControl(SCParentalControlInfo *info);
extern BOOL SCSetParentalControl(const SCParentalControlInfo *info);

#define SC_IDLE_MODE_OFF         0u
#define SC_IDLE_MODE_ON          1u
#define SC_IDLE_MODE_DEFAULT     SC_IDLE_MODE_OFF

#define SC_IDLE_MODE_LED_OFF       0u
#define SC_IDLE_MODE_LED_ON_DARK   1u
#define SC_IDLE_MODE_LED_ON_BRIGHT 2u
#define SC_IDLE_MODE_LED_ON        SC_IDLE_MODE_LED_ON_DARK
#define SC_IDLE_MODE_LED_DEFAULT   SC_IDLE_MODE_LED_ON_DARK

typedef struct {
  u8    mode;
  u8    led;
} SCIdleModeInfo;

extern BOOL SCGetIdleMode(SCIdleModeInfo *info);
extern BOOL SCSetIdleMode(const SCIdleModeInfo *info);

extern BOOL SCSetWwwRestriction(BOOL flag);

#define SC_OWNER_NICKNAME_LENGTH_MAX   10
typedef struct {
    u16 name[SC_OWNER_NICKNAME_LENGTH_MAX]; // not zero-terminated
    u16 length;
} SCOwnerNickNameInfo;

extern BOOL SCGetOwnerNickName(SCOwnerNickNameInfo *info);

extern BOOL SCSetOwnerNickName(const SCOwnerNickNameInfo *info);

#define SC_PRODUCT_AREA_UNKNOWN        (-1)
#define SC_PRODUCT_AREA_JPN            0     // Japan
#define SC_PRODUCT_AREA_USA            1     // North America
#define SC_PRODUCT_AREA_EUR            2     // Europe
#define SC_PRODUCT_AREA_AUS            3     // Australia
#define SC_PRODUCT_AREA_BRA            4     // Brazil
#define SC_PRODUCT_AREA_TWN            5     // Taiwan
#define SC_PRODUCT_AREA_KOR            6     // Korea
#define SC_PRODUCT_AREA_HKG            7     // Hong Kong
#define SC_PRODUCT_AREA_ASI            8     // Southeast Asia
#define SC_PRODUCT_AREA_LTN            9     // Central and South America
#define SC_PRODUCT_AREA_SAF            10    // South Africa
#define SC_PRODUCT_AREA_CHN            11    // China

extern s8   SCGetProductArea(void);

#define SC_PRODUCT_INFO_AREA_LENGTH                     3       // "JPN", "USA", ...
extern BOOL SCGetProductAreaString(char *buf, u32 bufSize);

#define SC_PRODUCT_INFO_MODEL_LENGTH                    16      // "RVL-001(JPN)" + spare 4
extern char *SCGetProductModel(void);

#define SC_PRODUCT_INFO_CODE_LENGTH                     5       // "LJH" + spare 2
extern char *SCGetProductCode(void);

extern BOOL SCGetProductSN(u32 *serNo);

#define SC_PRODUCT_INFO_SERNO_LENGTH                    10      // 8 + spare 2
extern BOOL SCGetProductSNString(char *buf, u32 bufSize);

extern BOOL SCGetProductMPChan(u32 *chan);

#define SC_PRODUCT_INFO_MP_CHAN_LENGTH                  8       // "0xXXXX" + spare 2
extern BOOL SCGetProductMPChanString(char *buf, u32 bufSize);

#define SC_PRODUCT_VIDEO_MODE_UNKNOWN  (-1)
#define SC_PRODUCT_VIDEO_MODE_NTSC     0
#define SC_PRODUCT_VIDEO_MODE_PAL      1
#define SC_PRODUCT_VIDEO_MODE_MPAL     2

extern s8   SCGetProductVideoMode(void);

#define SC_PRODUCT_GAME_REGION_UNKNOWN  (-1)
#define SC_PRODUCT_GAME_REGION_JP       0
#define SC_PRODUCT_GAME_REGION_US       1
#define SC_PRODUCT_GAME_REGION_EU       2
#define SC_PRODUCT_GAME_REGION_ALL      3   // diag (disc app) or all (nand app)
#define SC_PRODUCT_GAME_REGION_KR       4
#define SC_PRODUCT_GAME_REGION_CN       5

extern s8   SCGetProductGameRegion(void);

#define SC_SIMPLE_ADDRESS_ID_COUNTRY_SHIFT      24
#define SC_SIMPLE_ADDRESS_ID_REGION_SHIFT       16
#define SC_SIMPLE_ADDRESS_ID_COUNTRY_MASK       (0xff<<SC_SIMPLE_ADDRESS_ID_COUNTRY_SHIFT)
#define SC_SIMPLE_ADDRESS_ID_REGION_MASK        (0xff<<SC_SIMPLE_ADDRESS_ID_REGION_SHIFT)
#define SC_SIMPLE_ADDRESS_ID_RESERVED_MASK      (0x0000ffff)

#define SC_SIMPLE_ADDRESS_ID_NOT_DEFINED        (0xffffffff)
#define SC_SIMPLE_ADDRESS_ID_COUNTRY_UNDEFINED  (0x00<<SC_SIMPLE_ADDRESS_ID_COUNTRY_SHIFT)
#define SC_SIMPLE_ADDRESS_ID_COUNTRY_UNDEFINED2 (0xff<<SC_SIMPLE_ADDRESS_ID_COUNTRY_SHIFT)
#define SC_SIMPLE_ADDRESS_ID_REGION_UNDEFINED   (0x00<<SC_SIMPLE_ADDRESS_ID_REGION_SHIFT)
#define SC_SIMPLE_ADDRESS_ID_REGION_UNDEFINED2  (0xff<<SC_SIMPLE_ADDRESS_ID_REGION_SHIFT)

extern u32        SCGetSimpleAddressID(void);
extern const u16* SCGetSimpleAddressCountryName(u8 language);
extern const u16* SCGetSimpleAddressRegionName(u8 language);
extern u16        SCGetSimpleAddressLatitude(void);
extern u16        SCGetSimpleAddressLongitude(void);

#define SC_SIMPLE_ADDRESS_NUM_LANGUAGES (16)
#define SC_SIMPLE_ADDRESS_NAME_LENGTH (64)

typedef struct
{
        u32 id;
        u16 countryName[SC_SIMPLE_ADDRESS_NUM_LANGUAGES][SC_SIMPLE_ADDRESS_NAME_LENGTH];
        u16 regionName [SC_SIMPLE_ADDRESS_NUM_LANGUAGES][SC_SIMPLE_ADDRESS_NAME_LENGTH];
        u16 latitude;
        u16 longitude;
} SCSimpleAddress;

extern BOOL SCGetSimpleAddressData(SCSimpleAddress* pData);

extern BOOL SCSetSimpleAddressData(const SCSimpleAddress* pData);

#define SC_NET_CONTENT_RESTRICTION_MASK_NEWS          0x00000001
#define SC_NET_CONTENT_RESTRICTION_MASK_NWC24_MESSAGE 0x00000002
#define SC_NET_CONTENT_RESTRICTION_MASK_SHOPPING      0x00000004

extern u32  SCGetNetContentRestrictions(void);
extern BOOL SCSetNetContentRestrictions(u32 restrictions);

extern BOOL SCGetWCRestriction(void);
extern BOOL SCSetWCRestriction(BOOL flag);

extern BOOL SCGetConfigDoneFlag(void);
extern BOOL SCSetConfigDoneFlag(BOOL flag);

extern BOOL SCGetConfigDoneFlag2(void);
extern BOOL SCSetConfigDoneFlag2(BOOL flag);

#define SC_UPDATE_TYPE_NONE     0u
#define SC_UPDATE_TYPE_DISC     1u
#define SC_UPDATE_TYPE_NET      2u

extern u8   SCGetUpdateType(void);
extern BOOL SCSetUpdateType(u8 type);

extern BOOL SCGetEULA(void);
extern BOOL SCSetEULA(BOOL flag);

#define SC_WC_FLAG_USE 0x00000001

extern u32 SCGetWCFlags(void);
extern BOOL SCSetWCFlags(u32 flags);

extern BOOL SCGetFreeChannelAppCount(u32 *countp);

// SetFree/GetInstalled/SetInstalled APIs are reserved for Sysmenu.
extern BOOL SCSetFreeChannelAppCount(u32 count);
extern BOOL SCGetInstalledChannelAppCount(u32 *countp);
extern BOOL SCSetInstalledChannelAppCount(u32 count);

//////////////////////////////////////////////////////////////////////

extern u8 *__SCGetConfBuf(void);
extern u32 __SCGetConfBufSize(void);
extern void __SCDumpConfBuf(void);
extern void __SCClearConfBuf(void);

#ifdef __cplusplus
}
#endif

#endif // __SCPRIVATE_H__
