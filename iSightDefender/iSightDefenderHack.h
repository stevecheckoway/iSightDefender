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

#ifndef ISIGHT_DEFENDER_HACK_H
#define ISIGHT_DEFENDER_HACK_H

#include <IOKit/usb/IOUSBDevice.h>

class iSightDefenderHack : public IOUSBDevice
{
    OSDeclareDefaultStructors(iSightDefenderHack);

public:
    virtual IOReturn DeviceRequest(IOUSBDevRequest	*request,
                                   IOUSBCompletion	*completion = 0);
    virtual IOReturn DeviceRequest(IOUSBDevRequestDesc *request,
                                   IOUSBCompletion *completion = 0);
    virtual IOReturn DeviceRequest(IOUSBDevRequest	*request,
                                   UInt32 noDataTimeout,
                                   UInt32 completionTimeout,
                                   IOUSBCompletion	*completion = 0);
    virtual IOReturn DeviceRequest(IOUSBDevRequestDesc	*request,
                                   UInt32 noDataTimeout,
                                   UInt32 completionTimeout,
                                   IOUSBCompletion	*completion = 0);
};

#endif
