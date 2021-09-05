#ident "$Id: ioserrno.h,v 1.3 2006-03-05 10:59:35 orest Exp $"
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
#ifndef __IOSERRNO_H__
#define __IOSERRNO_H__

#define IOS_ERROR_OK                     0
#define IOS_ERROR_ACCESS                -1
#define IOS_ERROR_EXISTS                -2
#define IOS_ERROR_INTR                  -3
#define IOS_ERROR_INVALID               -4
#define IOS_ERROR_MAX                   -5
#define IOS_ERROR_NOEXISTS              -6
#define IOS_ERROR_QEMPTY                -7
#define IOS_ERROR_QFULL                 -8
#define IOS_ERROR_UNKNOWN               -9
#define IOS_ERROR_NOTREADY             -10
#define IOS_ERROR_ECC                  -11
#define IOS_ERROR_ECC_CRIT             -12
#define IOS_ERROR_BADBLOCK             -13

#define IOS_ERROR_INVALID_OBJTYPE      -14
#define IOS_ERROR_INVALID_RNG          -15
#define IOS_ERROR_INVALID_FLAG         -16
#define IOS_ERROR_INVALID_FORMAT       -17
#define IOS_ERROR_INVALID_VERSION      -18
#define IOS_ERROR_INVALID_SIGNER       -19
#define IOS_ERROR_FAIL_CHECKVALUE      -20
#define IOS_ERROR_FAIL_INTERNAL        -21
#define IOS_ERROR_FAIL_ALLOC           -22
#define IOS_ERROR_INVALID_SIZE         -23

#endif /*__IOSERRNO_H__*/
