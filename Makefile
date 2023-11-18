include Makefile.inc

# Files, program and header list
SRCS	= $(wildcard src/*.cc)
LIBS	= src/lib
PROGRAM	= Lithium

buildware: check_dir shared static
	$(CXX) $(SRCS) -o $(BIN)/$(PROGRAM) \
	$(LIB)/libLithium.a \
	$(LIB)/libLithium.so \
	$(CXSTD) $(CXLIBS) $(CXFLAGS) $(CXARGS)

.PHONY: shared static check_lib
static: check_dir
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Core.cc -o $(BUILD)/Lt-Core.o $(CXFLAGS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Component.cc -o $(BUILD)/Lt-Comp.o $(CXFLAGS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Parser.cc -o $(BUILD)/Lt-Parser.o $(CXFLAGS)

	$(STATIC-ARC) $(LIB)/libLithium.a $(wildcard $(BUILD)/*.o)

shared: check_dir
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Core.cc -o $(BUILD)/Lt-Core.o $(CXFLAGS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Component.cc -o $(BUILD)/Lt-Comp.o $(CXFLAGS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Parser.cc -o $(BUILD)/Lt-Parser.o $(CXFLAGS)

	$(CXX) $(SHARED) $(LIB)/libLithium.so $(wildcard $(BUILD)/*.o) \
	$(CXSTD) $(CXLIBS) $(CXFLAGS)
