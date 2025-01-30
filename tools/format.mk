# Formatter
CLF		= clang-format

# Source and include config
SRCS	 = src/
SRCS	+= 

# Prefix
EXF		  = c cc cpp cxx
EXF		 += h hh hpp hxx

SRCF_	  = $(wildcard $(addprefix src/*., $(EXF)))
SRCF_	 += $(wildcard $(addprefix lib/*., $(EXF)))

INCF_	  = $(wildcard $(addprefix include/*., $(EXF)))

.PHONY: format

format:
	$(CLF) -i $(SRCF_)
	$(CLF) -i $(INCF_)