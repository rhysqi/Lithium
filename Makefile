include tools/config.mk
include tools/format.mk
include tools/lib.mk

PROGRAM	= Lithium

.PHONY: buildware buildware-win32 test-build
buildware-X11: check_dir shared-X11 static-X11
	$(CXX) $(SRCS) -o $(BIN)/$(PROGRAM) \

	$(LIB)/libLithium.a $(LIB)/libLithiumGraphics.a \
	$(LIB)/libLithiumFont.a $(LIB)/libLithiumParser.a \
	$(LIB)/libLithium.so $(LIB)/libLithiumGraphics.so \
	$(LIB)/libLithiumFont.so $(LIB)/libLithiumParser.so \

	$(CXSTD) $(CXLIBS) $(CXFLAGS) $(CXARGS_X11)

buildware-win32: check_dir shared-win32 static-win32
	$(CXX) $(SRCS) -o $(BIN)/$(PROGRAM) \

	$(LIB)/libLithium.a $(LIB)/libLithiumGraphics.a \
	$(LIB)/libLithiumFont.a $(LIB)/libLithiumParser.a \
	$(LIB)/libLithium.dll $(LIB)/libLithiumGraphics.dll \
	$(LIB)/libLithiumFont.dll $(LIB)/libLithiumParser.dll \

	$(CXSTD) $(CXLIBS) $(CXFLAGS) $(CXARGS_W32)

test-build-win32:
	$(CXX) $(SRCS) -o $(BIN)/$(PROGRAM) \
	$(CXSTD) $(CXARGS_W32)

test-build-X11:
	$(CXX) $(SRCS) $(LIBS_T) \
	-o $(BIN)/$(PROGRAM) \
	$(CXSTD) $(CXLIBS) $(CXFLAGS) $(CXARGS_X11)