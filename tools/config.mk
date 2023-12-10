# C/C++ Standard settings
CXX			=	clang++15
CXSTD		=	-std=c++17 -stdlib=libc++

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

CXFLAGS		+=	-Wpedantic
CXFLAGS		+=	-v

CXLIBS		=	-I/usr/local/include -L/usr/local/lib
CXLIBS		+=	-I/usr/include -L/usr/lib

CXARGS		=	-lX11

# Folder cache list
LIB			:= lib
_PKG_		:= build/package

BUILD		= build
BIN			= bin

# Lib options
INDENT_RUN	= -c -fPIE
SHARED		= -shared -o

STATIC-ARC	= llvm-ar15 rcsU

.PHONY: check_dir package

package:
	@if [ ! -d "$(_PKG_)" ]; then \
		mkdir -p $(_PKG_); \
		echo "Directory $(_PKG_) created..."; \
	else \
		echo "Directory $(_PKG_) already exists."; \
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
