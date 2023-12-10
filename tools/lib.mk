include tools/config.mk

# Files, program and header list
SRCS	= src/lithium.cc

LIBS	= src/lib

# Lib options
INDENT_RUN	= -c -fPIE
SHARED		= -shared -o

STATIC-ARC	= llvm-ar15 rcsU

.PHONY: shared-win32 static-win32 shared-X11 static-X11

shared-win32: check_dir
	$(CXX) $(LIBS) \
	$(INDENT_RUN) $(SHARED) \
	
	-D_X11

static-win32: check_dir
	$(CXX) $() \
	-D_X11

shared-X11: check_dir
	$(CXX) \
	-D_WIN32

static-X11: check_dir
	$(CXX) \
	-D_WIN32
	