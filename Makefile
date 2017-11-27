SYSROOT = /opt/android/sysroot
CROSS_COMPILE = /opt/android/arm-eabi-4.6/bin/arm-eabi-

INCLUDE = -I./src -I $(SYSROOT)/usr/include

CFLAGS = -g -O2 $(INCLUDE) -fpic -fno-short-enums -Wall
LDFLAGS = -L/opt/android/sysroot/usr/lib -pie -nostdlib -rpath /system/lib -lc --dynamic-linker /system/bin/linker \
	  -x --strip-debug

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld

TARGET = maxassoc

SOURCES = \
	src/*.c \

OBJECTS = $(shell echo $(SOURCES) | sed -e 's|\.c|\.o|g')

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJECTS)

