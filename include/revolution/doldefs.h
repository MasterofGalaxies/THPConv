/*---------------------------------------------------------------------------*
  Project:  Dolphin
  File:     doldefs.h

  Copyright 2002 Nintendo.  All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.1.1  2005/05/12 02:41:06  yasuh-to
  dolphinシースツリーから移植

    
    4     8/30/02 10:28 Shiki
    Defined DOLPHIN_LIB_CC.

    3     8/07/02 21:41 Shiki
    Revised.

    2     8/07/02 20:55 Shiki
    Revised.

    1     8/07/02 20:06 Shiki
    Initial check-in.
  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __DOLDEFS_H__
#define __DOLDEFS_H__

#ifdef __cplusplus
extern "C" {
#endif

#define DOLPHIN_DEF_STR(X)      DOLPHIN_DEF_VAL(X)
#define DOLPHIN_DEF_VAL(X)      #X
#define DOLPHIN_DEF_CAT(X,Y)    X ## Y

#if defined(__MWERKS__)
#define DOLPHIN_LIB_CC          DOLPHIN_DEF_STR(__MWERKS__)
#else if defined(__SN__)
#define DOLPHIN_LIB_CC          DOLPHIN_DEF_STR(__GNUC__) ## "." DOLPHIN_DEF_STR(__GNUC_MINOR__)
#endif

#ifdef _DEBUG
#define DOLPHIN_LIB_VERSION(lib)    \
    const char* __ ## lib ## Version = "<< Dolphin SDK - " #lib "\tdebug build: " __DATE__ " " __TIME__ " (" DOLPHIN_LIB_CC ") >>"
#else
#define DOLPHIN_LIB_VERSION(lib)    \
    const char* __ ## lib ## Version = "<< Dolphin SDK - " #lib "\trelease build: " __DATE__ " " __TIME__ " (" DOLPHIN_LIB_CC ") >>"
#endif

#ifdef __cplusplus
}
#endif

#endif  // __DOLDEFS_H__
