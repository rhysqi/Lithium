include tools/config.mk
include tools/format.mk
include tools/lib.mk

PROGRAM	= Lithium

.PHONY: buildware buildware-win32 test-build
buildware-X11: check_dir shared static
	$(CXX) $(SRCS) -o $(BIN)/$(PROGRAM) \
	$(LIB)/libLithium.a \
	$(LIB)/libLithium.so \
	$(CXSTD) $(CXLIBS) $(CXFLAGS) $(CXARGS)

buildware-win32: check_dir shared static-win32
	$(CXX) $(SRCS) -o $(BIN)/$(PROGRAM) \
	$(LIB)/libLithium.a \
	$(LIB)/libLithium.dll \
	$(CXSTD) $(CXLIBS) $(CXFLAGS) $(CXARGS)

test-build-win32:
	$(CXX) $(SRCS) -o $(BIN)/$(PROGRAM) \
	$(CXSTD) -mwindows -luser32 -D_WIN32

test-build-X11:
	$(CXX) $(SRCS) $(LIBS_T) \
	-o $(BIN)/$(PROGRAM) \
	$(CXSTD) $(CXLIBS) $(CXFLAGS) $(CXARGS) \
	-D_X11