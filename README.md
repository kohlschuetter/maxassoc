# maxassoc

A little program to override the maximum number of stations that can associate with an Android phone when tethering (sharing the data connection over WiFi).

## Limitations

This is pretty much a working hack at this point.
The maximum number of stations is hard-coded to 32.

## Supported Devices

Currently, only Broadcom chipsets are supported (and not all of them will work).

Tested working on:

* Sony Xperia Z2 running Android 4.4

## Installation

Modify the Makefile to point to the right cross-compiler and Android sources.

## License

maxassoc

Copyright (c) 2017 Christian Kohlschütter

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
