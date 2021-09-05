###############################################################################
# Makefile for Revolution THP Core Library
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
#  Revision 1.1  2006/02/08 02:56:32  aka
#  Imported from Dolphin Tree.
#
#   
#   2     03/09/15 1:20p Akagi
#   
#   1     03/07/01 1:39p Akagi
#   Initial checkin. Modified to divide old THPConv.exe into 2 LIBs and 1
#   EXE by Ohki-san@NTSC.
#
#  $NoKeywords: $
#
###############################################################################

all:	buildthpcore

buildthpcore:
		@chmod u+x buildscript
		@echo =========Building thpcore LIB==============
		@./buildscript
		@echo ===========================================

clean:
		@chmod u+x buildscript
		@echo =========Cleaning thpcore LIB==============
		@./buildscript /CLEAN
		@echo ===========================================


MODULENAME	= thpcore
X86		= TRUE

include $(REVOLUTION_SDK_ROOT)/build/buildtools/commondefs

include $(REVOLUTION_SDK_ROOT)/build/buildtools/modulerules
