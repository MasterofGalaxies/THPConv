###############################################################################
# Makefile for THPConv
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
#  Revision 1.1  2006/02/08 02:55:21  aka
#  Imported from Dolphin Tree.
#
#   
#   2     03/09/15 6:34p Akagi
#   
#   1     03/07/01 2:47p Akagi
#   Initial checkin. Modified to divide old THPConv.exe into 2 LIBs and 1
#   EXE by Ohki-san@NTSC.
#
#  $NoKeywords: $
#
###############################################################################

all:	buildTHPConv

buildTHPConv:
		@chmod u+x buildscript
		@echo ===========Building THPConv================
		@./buildscript
		@echo ===========================================

clean:
		@chmod u+x buildscript
		@echo ===========Cleaning THPConv================
		@./buildscript /CLEAN
		@echo ===========================================


MODULENAME	= THPConv
X86		= TRUE

include $(REVOLUTION_SDK_ROOT)/build/buildtools/commondefs

include $(REVOLUTION_SDK_ROOT)/build/buildtools/modulerules
