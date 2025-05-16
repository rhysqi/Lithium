# Compiler configuration
CC		:=	clang
CXX		:=	clang++

# Compiler options for features flags
OPT_F	=	-fcrash-diagnostics  -fdirectives-only -fenable-matrix \
			-fstrict-float-cast-overflow -fstrict-vtable-pointers \
			-fstrict-enums -fsplit-lto-unit \
			-fstack-protector-strong -fvectorize

OPT_Fno	=	-fno-autolink -fno-builtin -fno-cxx-modules \
			-fno-convergent-functions -fno-coverage-mapping \
			-fno-experimental-library -fno-exceptions \
			-fno-strict-aliasing

# Compiler options for machine flags
OPT_M	=	-mavx2 -msse4.2 \
			-mlvi-cfi -mseses \
			-mstack-arg-probe -mstackrealign

OPT_Mno	=	-mno-fmv

# Compiler options for warning flags			
OPT_W	=	-Wall -Wabi -Wclass-conversion -Wdeprecated -Wformat-security \
			-Wunused -Wuninitialized -Wextra

OPT_Wno	=	-Wno-pedantic

# Compiler options for Windows linker flags
OPT_Wl	=	-Wl",/DYNAMICBASE" -Wl",/LARGEADDRESSAWARE" -Wl",/NODEFAULTLIB" \
			-Wl",/INTEGRITYCHECK" -Wl",/HIGHENTROPYVA" -Wl",/MACHINE:x64"

# Compiler options for Windows universal flags
OPT_Uni	=	-std=c++17 -v -H

OPT		=	$(OPT_F) $(OPT_Fno) $(OPT_M) $(OPT_Mno) \
			$(OPT_W) $(OPT_Wno) $(OPT_Wl) $(OPT_Uni)

# Compiler for library
C_LIB	=	$(CC) $(OPT) -c
CXX_LIB	=	$(CXX) $(OPT) -c

# Compiler for PE (Portable Executable)
C_PE	=	$(C_LIB)
CXX_PE	=	$(CXX_LIB)

# Windows LLVM linker configuration
LINK_PE	=	lld-link \
			/entry:wWinMain /subsystem:WINDOWS /integritycheck \
			/largeaddressaware /highentropyva /dynamicbase \
			/incremental:no /appcontainer:no /nodefaultlib \
			/machine:x64

# LLVM Archive configuration
LL_ARC	=	llvm-ar rsUv

# LLVM Strip configuration
LL_STP	=	llvm-strip -S