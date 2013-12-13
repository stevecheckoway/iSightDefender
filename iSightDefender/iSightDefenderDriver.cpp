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

#include <IOKit/IOLib.h>
#include "iSightDefenderDriver.h"
#include "iSightDefenderHack.h"

static const void *iSightDefenderGetVtable(const IOUSBDevice *obj)
{
    return *(const void *const *)obj;
}

static void iSightDefenderSetVtable(IOUSBDevice *obj, const void *vtable)
{
    *(const void **)obj = vtable;
}

#define super IOService
OSDefineMetaClassAndStructors(iSightDefenderDriver, IOService);

bool iSightDefenderDriver::init(OSDictionary *propTable)
{
    bool ret = super::init(propTable);
    IOLog("iSightDefenderDriver::init() returned %s\n", ret? "true":"false");
    if (ret)
    {
        iSightDefenderHack *hack = OSTypeAlloc(iSightDefenderHack);
        miSightDefenderHackVtable = iSightDefenderGetVtable(hack);
        hack->release();
    }
    return ret;
}

void iSightDefenderDriver::free()
{
    IOLog("iSightDefenderDriver::free()\n");
    super::free();
}

bool iSightDefenderDriver::start(IOService *provider)
{
    IOLog("iSightDefenderDriver::start()\n");
    if (!super::start(provider))
        return false;
    IOUSBDevice *dev = OSDynamicCast(IOUSBDevice, provider);
    if (!dev)
    {
        IOLog("iSightDefenderDriver's provider is not IOUSBDevice: %s",
              provider->getMetaClass()->getClassName());
        return false;
    }
    mIOUSBDeviceVtable = iSightDefenderGetVtable(dev);
    iSightDefenderSetVtable(dev, miSightDefenderHackVtable);
    return true;
}

void iSightDefenderDriver::stop(IOService *provider)
{
    IOLog("iSightDefenderDriver::stop()\n");
    iSightDefenderSetVtable(OSDynamicCast(IOUSBDevice, provider),
                            mIOUSBDeviceVtable);
    super::stop(provider);
}
