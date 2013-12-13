iSightDefender
==============

Prevent the iSight on your 2007 or 2008 MacBook from turning on without the green indicator light also turning on.

To build iSightDefender, you first need to install the Mac OS X 10.6 SDK. If you're building this on a machine running Mac OS X 10.6, it should already be installed. If you're not building on a machine running 10.6, then you may need to download a version of Xcode which contains the `MacOSX10.6.sdk` and install it in the appropriate `SDKs` directory. On OS X 10.9 (Mavericks), the `SDKs` directory is inside the `Xcode.app` application bundle. Typically, this will be:

    /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/

If you are using Xcode 5 to build, you will need to change the compiler to the system default.

Once the iSightDefender.kext is built, you can install it with `kextutil`.
