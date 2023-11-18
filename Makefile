include Makefile.inc

# File and header list
SRCS	= lithium.cc

LIBS	= src/lib/
OBJ		= ${patsubst  $(LIBS)/%.cc, $(BUILD)/%.o, }


buildware: check_dir
	# $(CXX) $(OBJS) -o $(LIBS) $(CXSTD) $(CXFLAGS)
	

.PHONY: shared static
static:
	$(CXX) $(OBJS) $(LIBS) $(CXSTD) $(CXFLAGS)

shared:
	$(CXX) $(OBJS) $(LIBS) $(CXSTD) $(CXFLAGS)
