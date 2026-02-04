# Setup project build

SETUP_TARGET	?=

BUILD_DIR		=	build
OBJECT_DIR		=	$(BUILD_DIR)/object/
LIB_DIR			=	$(BUILD_DIR)/lib/

ifeq ($(TARGET),freebsd)
SETUP_TARGET	=	setup-freebsd

else ifeq ($(TARGET),win32)
SETUP_TARGET	=	setup-win32

endif

.PHONY: setup setup-freebsd setup-win32

setup: $(SETUP_TARGET)

setup-freebsd:
	@echo "Checking build folders ..."
	@if [ ! -d $(BUILD_DIR) ]; then \
		echo "Creating build dir ..."; \
		mkdir -p $(BUILD_DIR); \
	else \
		echo "Build dir exists"; \
	fi

	@if [ ! -d $(OBJECT_DIR) ]; then \
		echo "Creating object dir ..."; \
		mkdir -p $(OBJECT_DIR); \
	else \
		echo "Object dir exists"; \
	fi

	@if [ ! -d $(LIB_DIR) ]; then \
		echo "Creating lib dir ..."; \
		mkdir -p $(LIB_DIR); \
	else \
		echo "Lib dir exists"; \
	fi

setup-win32:
	@echo "Checking build folders ..."