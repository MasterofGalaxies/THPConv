###############################################################################
# Makefile for Revolution THP Audio Library
#
# Copyright (C)2003-2006 Nintendo  All Rights Reserved.
#
# These coded instructions, statements, and computer programs contain
# proprietary information of Nintendo of America Inc. and/or Nintendo
# Company Ltd., and are protected by Federal copyright law.  They may
# not be disclosed to third parties or copied or duplicated in any form,
# in whole or in part, without the prior written consent of Nintendo.
#
#  $Log: not supported by cvs2svn $
#  Revision 1.1  2006/02/08 02:53:42  aka
#  Imported from Dolphin Tree.
#
#   
#   1     03/07/07 10:51a Akagi
#   Initial checkin. 
#   
#  $NoKeywords: $
#
###############################################################################

all:	buildthpaudio

buildthpaudio:
		@chmod u+x buildscript
		@echo =======Building thpaudio LIB===========
		@./buildscript
		@echo ===========================================

clean:
		@chmod u+x buildscript
		@echo =======Cleaning thpaudio LIB===========
		@./buildscript /CLEAN
		@echo ===========================================


MODULENAME	= thpaudio
X86		= TRUE

include $(REVOLUTION_SDK_ROOT)/build/buildtools/commondefs

include $(REVOLUTION_SDK_ROOT)/build/buildtools/modulerules
