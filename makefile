include tools\config\asm-config.mk
include tools\config\clang-config.mk
include tools\config\llvm-config.mk

# x86
build-Win32-Debug:
	@$(CXX) -m32 -D_DEBUG

build-Win32-Release:
	@$(CXX) -m32

# x64
build-Win64-Debug:
	@$(CXX) -m64 -D_DEBUG

build-Win64-Release:
	@$(CXX) -m64


.PHONY:
	build-Win32-Debug build-Win32-Release
	build-Win64-Debug build-Win64-Release