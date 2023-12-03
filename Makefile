include tools/config.mk
include tools/format.mk

# Files, program and header list
SRCS	= src/lithium.cc
LIBS	= src/lib
LIBS_T	= src/lib/Lt-Core.cc
LIBS_T	+= src/lib/Lt-Parser.cc
LIBS_T	+= src/lib/Lt-Component.cc

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

.PHONY: shared static
static: check_dir
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Core.cc -o $(BUILD)/Lt-Core.o $(CXFLAGS) $(CXARGS) $(CXLIBS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Component.cc -o $(BUILD)/Lt-Comp.o $(CXFLAGS) $(CXARGS) $(CXLIBS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Parser.cc -o $(BUILD)/Lt-Parser.o $(CXFLAGS) $(CXARGS) $(CXLIBS)

	$(STATIC-ARC) $(LIB)/libLithium.a $(wildcard $(BUILD)/*.o)

shared: check_dir
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Core.cc -o $(BUILD)/Lt-Core.o $(CXFLAGS) $(CXARGS) $(CXLIBS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Component.cc -o $(BUILD)/Lt-Comp.o $(CXFLAGS) $(CXARGS) $(CXLIBS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Parser.cc -o $(BUILD)/Lt-Parser.o $(CXFLAGS) $(CXARGS) $(CXLIBS)

	$(CXX) $(SHARED) $(LIB)/libLithium.so $(wildcard $(BUILD)/*.o) \
	$(CXSTD) $(CXLIBS) $(CXFLAGS) $(CXARGS)

shared-win32: check_dir
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Core.cc -o $(BUILD)/Lt-Core.o $(CXFLAGS) $(CXARGS) $(CXLIBS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Component.cc -o $(BUILD)/Lt-Comp.o $(CXFLAGS) $(CXARGS) $(CXLIBS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Parser.cc -o $(BUILD)/Lt-Parser.o $(CXFLAGS) $(CXARGS) $(CXLIBS)

	$(CXX) $(SHARED) $(LIB)/libLithium.dll $(wildcard $(BUILD)/*.o) \
	$(CXSTD) $(CXLIBS) $(CXFLAGS) $(CXARGS)

test-build-win32:
	$(CXX) $(SRCS) -o $(BIN)/$(PROGRAM) \
	$(CXSTD) -mwindows -luser32 -D_WIN32_

test-build-X11:
	$(CXX) $(SRCS) $(LIBS_T) \
	-o $(BIN)/$(PROGRAM) \
	$(CXSTD) $(CXLIBS) $(CXFLAGS) $(CXARGS) \
	-D_X11_