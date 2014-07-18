/*
 *  SDMMD_Connection_Class.c
 *  SDMMobileDevice
 *
 * Copyright (c) 2014, Sam Marshall
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
 * 		in the documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Sam Marshall nor the names of its contributors may be used to endorse or promote products derived from this
 * 		software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _SDM_MD_CONNECTION_CLASS_C_
#define _SDM_MD_CONNECTION_CLASS_C_

#include "SDMMD_Connection_Class.h"
#include "SDMMD_Connection_Internal.h"

#if __SDM_CORE_LIB
#include <SDMCore/Core.h>
#else
#include "Core.h"
#endif

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

static Boolean SDMMD_AMConnectionRefEqual(CFTypeRef cf1, CFTypeRef cf2) {
	SDMMD_AMConnectionRef connection1 = (SDMMD_AMConnectionRef)cf1;
	SDMMD_AMConnectionRef connection2 = (SDMMD_AMConnectionRef)cf2;
	
	return (connection1->ivars.socket == connection2->ivars.socket);
}

static CFStringRef SDMMD_AMConnectionRefCopyFormattingDesc(CFTypeRef cf, CFDictionaryRef formatOpts) {
	SDMMD_AMConnectionRef connection = (SDMMD_AMConnectionRef)cf;
	return CFStringCreateWithFormat(CFGetAllocator(connection), NULL, CFSTR("<SDMMD_AMConnectionRef %p>{socket = %d}"), connection, connection->ivars.socket);
}

static CFStringRef SDMMD_AMConnectionRefCopyDebugDesc(CFTypeRef cf) {
	SDMMD_AMConnectionRef connection = (SDMMD_AMConnectionRef)cf;
	return CFStringCreateWithFormat(CFGetAllocator(connection), NULL, CFSTR("<SDMMD_AMConnectionRef %p>{socket = %d}"), connection, connection->ivars.socket);
}

static void SDMMD_AMConnectionRefFinalize(CFTypeRef cf) {
	SDMMD_AMConnectionRef connection = (SDMMD_AMConnectionRef)cf;
	Safe(SSL_free,connection->ivars.ssl);
	connection->ivars.ssl = NULL;
}

static CFTypeID _kSDMMD_AMConnectionRefID = _kCFRuntimeNotATypeID;

static CFRuntimeClass _kSDMMD_AMConnectionRefClass = {0};

void SDMMD_AMConnectionRefClassInitialize(void) {
	_kSDMMD_AMConnectionRefClass.version = 0;
	_kSDMMD_AMConnectionRefClass.className = "SDMMD_AMConnectionRef";
	_kSDMMD_AMConnectionRefClass.init = NULL;
	_kSDMMD_AMConnectionRefClass.copy = NULL;
	_kSDMMD_AMConnectionRefClass.finalize = SDMMD_AMConnectionRefFinalize;
	_kSDMMD_AMConnectionRefClass.equal = SDMMD_AMConnectionRefEqual;
	_kSDMMD_AMConnectionRefClass.hash = NULL;
	_kSDMMD_AMConnectionRefClass.copyFormattingDesc = SDMMD_AMConnectionRefCopyFormattingDesc;
	_kSDMMD_AMConnectionRefClass.copyDebugDesc = SDMMD_AMConnectionRefCopyDebugDesc;
	_kSDMMD_AMConnectionRefClass.reclaim = NULL;
	_kSDMMD_AMConnectionRefID = _CFRuntimeRegisterClass((const CFRuntimeClass * const)&_kSDMMD_AMConnectionRefClass);
}

CFTypeID SDMMD_AMConnectionRefGetTypeID(void) {
	return _kSDMMD_AMConnectionRefID;
}

SDMMD_AMConnectionRef SDMMD_AMConnectionCreateEmpty() {
	uint32_t extra = sizeof(AMConnectionClassBody);
	SDMMD_AMConnectionRef device = (SDMMD_AMConnectionRef)_CFRuntimeCreateInstance(kCFAllocatorDefault, _kSDMMD_AMConnectionRefID, extra, NULL);
	return device;
}

#endif