CC ?= $(CROSS_COMPILE)gcc
CFLAGS ?= -Wall -O2 -flto

C_FILES = $(wildcard tools/THPConv/src/*.c) $(wildcard tools/thpcore/src/*.c) $(wildcard tools/thputilities/src/*.c) $(wildcard tools/thpaudio/src/*.c) $(wildcard tools/dsptool/src/*.c)

TARGET = THPConv.exe

all: $(TARGET)

clean:
	rm $(TARGET)

$(TARGET): $(C_FILES)
	$(CC) $(CFLAGS) -I include -I tools/thpaudio/include -o $@ $(C_FILES)
