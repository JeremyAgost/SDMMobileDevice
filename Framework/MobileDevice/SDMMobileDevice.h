/*
 *  SDMMobileDevice.h
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

#ifndef _SDM_MOBILE_DEVICE_H_
#define _SDM_MOBILE_DEVICE_H_

#if __SDM_MD_LIB

/* Headers should be accessed from the exported path */
#include <SDMMobileDevice/SDMMD_Initialize.h>

#include <SDMMobileDevice/SDMMD_Functions.h>
#include <SDMMobileDevice/SDMMD_AMDevice.h>
#include <SDMMobileDevice/SDMMD_AppleFileConduit.h>
#include <SDMMobileDevice/SDMMD_Error.h>
#include <SDMMobileDevice/SDMMD_MCP.h>
#include <SDMMobileDevice/SDMMD_USBMuxListener.h>
#include <SDMMobileDevice/SDMMD_Applications.h>
#include <SDMMobileDevice/SDMMD_Notification.h>

#if !__SDM_MD_Skip_Debugger
#include <SDMMobileDevice/SDMMD_Debugger.h>
#endif

#else

#include "SDMMD_Initialize.h"

#include "SDMMD_Functions.h"
#include "SDMMD_AMDevice.h"
#include "SDMMD_AppleFileConduit.h"
#include "SDMMD_Error.h"
#include "SDMMD_MCP.h"
#include "SDMMD_USBMuxListener.h"
#include "SDMMD_Applications.h"
#include "SDMMD_Notification.h"

#if !__SDM_MD_Skip_Debugger
#include "SDMMD_Debugger.h"
#endif

#endif

#endif