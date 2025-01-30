CC		=	clang
CXX		=	clang++

OPT_F	=	-fcrash-diagnostics  -fdirectives-only -fenable-matrix \
			-fstrict-float-cast-overflow -fstrict-vtable-pointers \
			-fstrict-enums -fsplit-lto-unit \
			-fstack-protector-strong -fvectorize

OPT_Fno	=	-fno-autolink -fno-builtin -fno-cxx-modules \
			-fno-convergent-functions -fno-courotines \
			-fno-experimental-library -fno-exceptions \
			-fno-strict-aliasing

OPT_M	=	-mavx -mavx2 -msse -msse4.2 \
			-mlvi-cfi -mlvi-hardening \
			-mstack-arg-probe -mstackrealign

OPT_Mno	=	-mno-sse2 -mno-sse3 \
			-mno-outline-atomics
			
OPT_W	=	-Wall -Wabi -WClass-convertion -WDeprecated -Wformat-security \
			-Wunused -Wuninitialized -Wextra

OPT_Wno	=	-Wno-pedantic

OPT_Wl	=	-Wl",/DYNAMICBASE:YES" \
			-Wl",/LARGEADDRESSNAME:YES"

OPT_Uni	=	-v -H

LIB_C	=	

LIB_CXX	=	
