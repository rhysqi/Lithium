include tools/config.mk
include tools/core.mk
include tools/lib.mk
include tools/setup.mk

TARGET      ?=
BUILD_MODE  ?=	Release

ifeq ($(strip $(TARGET)),)
$(error :Target not found)
endif

OS_TARGET	:=	FreeBSD Win32 Win64
ifneq ($(filter $(TARGET), $(OS_TARGET)), $(TARGET))
$(error :Target not available)

.PHONY: buildware

buildware:
	@echo $(LIB_TARGET)
	@echo $(FreeBSD_Core)
	@echo $(FreeBSD_LIB)
	