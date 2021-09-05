/*---------------------------------------------------------------------*
Project:  tc library
File:     TCFile.h

Copyright 1998-2001 Nintendo.  All rights reserved.

These coded instructions, statements and computer programs contain
proprietary information of Nintendo of America Inc. and/or Nintendo
Company Ltd., and are protected by Federal copyright law.  They may
not be disclosed to third parties or copied or duplicated in any form,
in whole or in part, without the prior written consent of Nintendo.

Change History:

   $Log: not supported by cvs2svn $
    
    2     4/11/01 3:30p John
    Updated header for copyright and pathname.
    
    1     12/03/99 4:15p Ryan
   
  $NoKeywords: $

-----------------------------------------------------------------------*/

#ifndef __TCFILE_H__
#define __TCFILE_H__

/********************************/
#include <dolphin/types.h>

#include <charPipeline/tc/TCLayer.h>
#include <charPipeline/tc/TCPalTable.h>

/********************************/
typedef struct
{
	char      name[255];

	TCLayer*    lyColor;
	TCLayer*    lyAlpha;
  
	TCPalTable* palPtr;
	
} TCFile, *TCFilePtr;

/*>*******************************(*)*******************************<*/
void TCSetFileCacheSize	( u32 size );

void TCInstallFileReadFn( char* ext, u32 (*fileFn)( u32 rawSize, 
						  u8* rawBits, TCFile* fPtr ) );

/*>*******************************(*)*******************************<*/

#endif  // __TCFILE_H__