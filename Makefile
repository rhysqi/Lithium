CC		= clang++15
CXFLAGS	= -O2 -fno-strict-aliasing -fstack-protector-strong
CXSTD	= -std=c++17 -stdlib=libc++
CXARGS	= -lX11

BUILD	:= build
LIB		:= lib

.PHONY: buildware check_dir

buildware: check_dir

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

	