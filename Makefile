include Makefile.inc
# Folder list
BUILD	:= build
LIB		:= lib
_PKG_	:= build/package

.PHONY: check_dir package

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

package:
	@if [ ! -d "$(_PKG_)" ]; then \
		mkdir -p $(_PKG_); \
		echo "Directory $(_PKG_) created..."; \
	else \
		echo "Directory $(_PKG_) already exists."; \
	fi