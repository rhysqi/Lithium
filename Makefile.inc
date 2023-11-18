# C/C++ Standard settings
CXX			= clang++-15
CXSTD		= -std=c++17 -stdlib=libc++
CXARGS		= -lX11
CXFLAGS		= -O2 -fno-strict-aliasing
CXFLAGS		+= -fstack-protector-strong

# Folder cache list
SRCS	:= src
LIB		:= lib
_PKG_	:= build/package

BUILD	:= build/

# Lib options
INDENT		= -c -fPIE

OBJS		= -c
STATIC-ARC	= llvm-ar-15 rcs

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

	@if [ ! -d "$(LIB)" ]; then \
		mkdir -p $(LIB); \
		echo "Directory $(LIB) created..."; \
	else \
		echo "Directory $(LIB) already exists."; \
	fi
