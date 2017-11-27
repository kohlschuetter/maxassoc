# maxassoc

A little program to override the maximum number of stations that can associate with an Android phone when tethering (sharing the data connection over WiFi).

## Usage

Invoke the binary without any parameters.

```
$ ./maxassoc
```

## Supported Devices

Currently, only Broadcom chipsets are supported (and not all of them may work).

Tested working on:

* Sony Xperia Z2 running Android 4.4

## Limitations

This is pretty much a working hack at this point.
It's hard-coded to set the maximum number of stations for wlan0 to 32.

## How it works

The program uses the brcm80211 wlioctl interface to send a WLC_SET_VAR command with the "maxassoc" command. That's it.

## Installation

Modify the Makefile to point to the right cross-compiler and Android sources, then run `make`.

## License

maxassoc

Copyright (c) 2017 Christian Kohlschütter

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

