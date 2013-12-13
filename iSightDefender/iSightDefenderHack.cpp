/*
 * Copyright (c) 2013, Stephen Checkoway <s@cs.jhu.edu>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  *  Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *  *  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 */

#include "iSightDefenderHack.h"

enum
{
    kEZUSBFirmwareLoadRequestType = USBmakebmRequestType(kUSBOut, kUSBVendor, kUSBDevice),
    kEZUSBFirmwareLoadRequest = 0xa0,
};

#define super IOUSBDevice
OSDefineMetaClassAndStructors(iSightDefenderHack, IOUSBDevice);

static bool is_firmware_load(IOUSBDevRequest *request)
{
    if (request->bmRequestType == kEZUSBFirmwareLoadRequestType
        && request->bRequest == kEZUSBFirmwareLoadRequest)
    {
        IOLog("iSightDefender blocked a reprogramming attempt\n");
        return true;
    }
    return false;
}

static bool is_firmware_load(IOUSBDevRequestDesc *request)
{
    if (request->bmRequestType == kEZUSBFirmwareLoadRequestType
        && request->bRequest == kEZUSBFirmwareLoadRequest)
    {
        IOLog("iSightDefender blocked a reprogramming attempt\n");
        return true;
    }
    return false;
}

IOReturn iSightDefenderHack::DeviceRequest(IOUSBDevRequest *request,
                                           IOUSBCompletion *completion)
{
    if (is_firmware_load(request))
        return kIOReturnUnsupported;
    return super::DeviceRequest(request, completion);
}


IOReturn iSightDefenderHack::DeviceRequest(IOUSBDevRequestDesc *request,
                                           IOUSBCompletion *completion)
{
    if (is_firmware_load(request))
        return kIOReturnUnsupported;
    return super::DeviceRequest(request, completion);
}

IOReturn iSightDefenderHack::DeviceRequest(IOUSBDevRequest *request,
                                           UInt32 noDataTimeout,
                                           UInt32 completionTimeout,
                                           IOUSBCompletion *completion)
{
    if (is_firmware_load(request))
        return kIOReturnUnsupported;
    return super::DeviceRequest(request, noDataTimeout,
                                completionTimeout, completion);
}

IOReturn iSightDefenderHack::DeviceRequest(IOUSBDevRequestDesc *request,
                                           UInt32 noDataTimeout,
                                           UInt32 completionTimeout,
                                           IOUSBCompletion *completion)
{
    if (is_firmware_load(request))
        return kIOReturnUnsupported;
    return super::DeviceRequest(request, noDataTimeout,
                                completionTimeout, completion);
}
