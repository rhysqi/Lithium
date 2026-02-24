INC_PATH	=	-I/usr/local/include -I/usr/include
LIB_PATH	=	-L/usr/local/lib -L/usr/lib

LINK_ELF	=	ld.lld

LDFLAGS		=	-lX11

.PHONY: buildware-freebsd buildware-netbsd

buildware-freebsd:
	@echo "From FreeBSD"

buildware-netbsd:
	@echo "From NetBSD"
