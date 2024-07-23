CC		=	clang
CXX		=	clang++

OPT_F	=	-fstack-protector-strong 
OPT_F	+=	-fcrash-diagnostics -fvectorize

OPT_Fno	=	-fno-builtin -fno-convergent-functions -fno-courotines
OPT_Fno	+=	-fno-cxx-modules -fno-strict-aliasing

OPT_M	=	-mavx
OPT_M	+=	-mlvi-cfi -mlvi-hardening
OPT_M	+=	-msese -msse4.2
OPT_M	+=	--mstack-arg-probe -mstackrealign

OPT_Mno	=	-mno-sse2
OPT_Mno	+=	-mno-sse3

OPT_Wl	=	-Wl",/"
OPT_Wl	+=	-Wl",/"

LIB_C	=	
LIB_C	+=	

LIB_CXX	=	
LIB_CXX	+=	

