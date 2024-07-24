include tools\build\asm-build.mk
include tools\build\clang-build.mk
include tools\build\llvm-build.mk

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