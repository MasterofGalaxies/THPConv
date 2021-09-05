/*---------------------------------------------------------------------------*
  Project:  header for darch for Revolution
  File:     darch.h

  Copyright (C) 2007 Nintendo All rights reserved.

  These coded instructions, statements, and computer programs contain
  proprietary information of Nintendo of America Inc. and/or Nintendo
  Company Ltd., and are protected by Federal copyright law.  They may
  not be disclosed to third parties or copied or duplicated in any form,
  in whole or in part, without the prior written consent of Nintendo.

  $Log: not supported by cvs2svn $
  Revision 1.1.4.1  2007/10/10 02:57:11  nakano_yoshinobu
  (none)

  Revision 1.3  2007/10/04 04:21:33  nakano_yoshinobu
  Renamed arguments of DARCHCreate().

  Revision 1.2  2007/08/29 12:07:32  nakano_yoshinobu
  Added DARCHGetArcSize().
  Removed functions about DarchWorkBuffer.

  Revision 1.1  2007/05/31 08:40:41  ooizumi
  Initial check-in.

  $NoKeywords: $
 *---------------------------------------------------------------------------*/

#ifndef __DARCH_H__
#define __DARCH_H__

#include <revolution/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define END_OF_PATH(ptr)        \
           ( ((ptr)[0] == '\0') || ( ((ptr)[0] == '/') && ((ptr)[1] == '\0') ) )
           

typedef struct
{
    const char* pathName;                             // file path name
    void* fileStart;                                  // pointer to file data buffer
    u32   length;                                     // file size
        
} DARCHFileInfo;

u32 DARCHGetArcSize(const DARCHFileInfo* fileInfo, const u32 fileInfoNum);
BOOL DARCHCreate(void* arcStart, u32 arcSize, const DARCHFileInfo* fileInfo, const u32 fileInfoNum);

#ifdef __cplusplus
}
#endif

#endif  // __DARCH_H__
