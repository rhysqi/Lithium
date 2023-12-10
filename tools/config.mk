# C/C++ Standard settings
CXX			=	clang++15
CXSTD		=	-std=c++20 -stdlib=libc++

CXFLAGS		=	-O3 -flto
CXFLAGS		+=	-fstack-protector-strong -fvectorize -fslp-vectorize \
				-fstrict-enums -fsplit-lto-unit -fsplit-lto-unit \
				-fstrict-float-cast-overflow -fstrict-vtable-pointers -fsplit-stack\
				-fconvergent-functions -fenable-matrix

CXFLAGS		+=	-fno-fixed-point -fno-strict-aliasing -fno-exception \
				-fno-spell-checking -fno-rtti -fno-rtti-data -fno-access-control \
				-fno-addrsig -fno-gnu-inline-asm

CXFLAGS		+=	-mstack-arg-probe -mstackrealign -msoft-float -mno-lvi-cfi \
				-mlvi-cfi -mlvi-hardening

CXFLAGS		+=	-Wall -Wno-pedantic
CXFLAGS		+=	-v -H

# X11
CXLIBS_X11	=	-I/usr/local/include -L/usr/local/lib
CXLIBS_X11	+=	-I/usr/include -L/usr/lib

CXARGS_X11	=	-lX11 -D_X11

# W32
CXARGS_W32	=	-mwindows -D_WIN32 \
				-luser32 -lGdi32

# Folder cache list
LIB			:= lib
PKG			:= build/package

BUILD		= build
BIN			= bin

.PHONY: check_dir package

package:
	@if [ ! -d "$(PKG)" ]; then \
		mkdir -p $(PKG); \
		echo "Directory $(PKG) created..."; \
	else \
		echo "Directory $(PKG) already exists."; \
	fi

check_dir:
	@if [ ! -d "$(BUILD)" ]; then \
		mkdir -p $(BUILD); \
		echo "Directory $(BUILD) created..."; \
	else \
		echo "Directory $(BUILD) already exists."; \
	fi

	@if [ ! -d "$(BIN)" ]; then \
		mkdir -p $(BIN); \
		echo "Directory $(BIN) created..."; \
	else \
		echo "Directory $(BIN) already exists."; \
	fi

	@if [ ! -d "$(LIB)" ]; then \
		mkdir -p $(LIB); \
		echo "Directory $(LIB) created..."; \
	else \
		echo "Directory $(LIB) already exists."; \
	fi
