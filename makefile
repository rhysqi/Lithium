include tools/config.mk
include tools/core.mk
include tools/lib.mk
include tools/setup.mk

build:
	@echo $(FreeBSD_Core)
	@echo $(FreeBSD_LIB)
	