include Makefile.inc

# File and header list
SRCS	= lithium.cc

LIBS	= src/lib

buildware: check_dir
	

.PHONY: shared static
static: check_dir
	$(CXX) -c $(LIBS)/Lt-Core.cc -o $(BUILD)/Lt-Core.o $(CXSTD) $(CXLIBS) $(CXFLAGS)
	$(CXX) -c $(LIBS)/Lt-Component.cc -o $(BUILD)/Lt-Comp.o $(CXSTD) $(CXLIBS) $(CXFLAGS)
	$(CXX) -c $(LIBS)/Lt-Parser.cc -o $(BUILD)/Lt-Parser.o $(CXSTD) $(CXLIBS) $(CXFLAGS)

	$(STATIC-ARC) $(LIB)/libLithium.a $(wildcard $(BUILD)/*.o) 

shared: check_dir
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Core.cc -o $(BUILD)/Lt-Core.o $(CXSTD) $(CXLIBS) $(CXFLAGS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Component.cc -o $(BUILD)/Lt-Comp.o $(CXSTD) $(CXLIBS) $(CXFLAGS)
	$(CXX) $(INDENT_RUN) $(LIBS)/Lt-Parser.cc -o $(BUILD)/Lt-Parser.o $(CXSTD) $(CXLIBS) $(CXFLAGS)

	$(CXX) $(SHARED) $(LIB)/libLithium.so $(wildcard $(BUILD)/*.o) $(CXSTD) $(CXLIBS) $(CXFLAGS)
	