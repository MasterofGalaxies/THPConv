###############################################################################
# Makefile for DSPADPCM dynamic link library
#
# Copyright (C)2005-2006 Nintendo  All Rights Reserved.
#
# These coded instructions, statements, and computer programs contain
# proprietary information of Nintendo of America Inc. and/or Nintendo
# Company Ltd., and are protected by Federal copyright law.  They may
# not be disclosed to third parties or copied or duplicated in any form,
# in whole or in part, without the prior written consent of Nintendo.
#
#  $Log: not supported by cvs2svn $
#  Revision 1.5  2006/02/09 07:52:12  yasuh-to
#  Added permission setting.
#
#  Revision 1.4  2006/02/09 04:59:16  aka
#  Changed copyright.
#
#  Revision 1.3  2006/02/08 02:08:07  mitu
#  changed for VC++.NET 2003
#
#  Revision 1.2  2005/11/04 06:52:20  aka
#  Modified for Revolution.
#
#  Revision 1.1  2005/11/04 06:49:45  aka
#  Created.
#
###############################################################################

all:	builddsptool

builddsptool:
		@chmod u+x buildscript
		@echo ===========Building DSP-ADPCM DLL==========
		@./buildscript
		@echo ===========================================

clean:
		@chmod u+x buildscript
		@echo ===========Cleaning DSP-ADPCM DLL==========
		@./buildscript /CLEAN
		@echo ===========================================


MODULENAME	= dsptool
X86		= TRUE

include $(REVOLUTION_SDK_ROOT)/build/buildtools/commondefs

include $(REVOLUTION_SDK_ROOT)/build/buildtools/modulerules
