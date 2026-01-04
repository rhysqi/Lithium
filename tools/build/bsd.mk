LIB_FreeBSD	=	lib/freebsd

INC_PATH	=	-I/usr/local/include -I/usr/include
LIB_PATH	=	-L/usr/local/lib -L/usr/lib

LINK_ELF	=	ld.lld

LDFLAGS		=	-lX11

buildware-bsd:
	
.PHONY: buildware-bsd