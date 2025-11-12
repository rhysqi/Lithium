# Windows Config variables
# Compiler options for Windows linker flags
OPT_Wl	=	-Wl",/DYNAMICBASE" -Wl",/LARGEADDRESSAWARE" -Wl",/NODEFAULTLIB" \
			-Wl",/INTEGRITYCHECK" -Wl",/HIGHENTROPYVA" -Wl",/MACHINE:x64"

# Windows LLVM linker configuration
LINK_PE	=	lld-link \
			/entry:wWinMain /subsystem:WINDOWS /integritycheck \
			/largeaddressaware /highentropyva /dynamicbase \
			/incremental:no /appcontainer:no /nodefaultlib \
			/machine:x64

buildware-win32:
	

.PHONY: buildware-win32