LIB	=	lib

# Library compile target and compile mode
TARGET_LC   := $(shell echo $(TARGET) | tr A-Z a-z)
MODE_LC     := $(shell echo $(BUILD_MODE) | tr A-Z a-z)

LIB_TARGET  := $(LIB)/$(TARGET_LC)
BUILD_DIR   := build/$(TARGET_LC)/$(MODE_LC)

# FreeBSD library
FreeBSD_LIB	=	$(LIB)/$(LIB_TARGET)

# Win32 library