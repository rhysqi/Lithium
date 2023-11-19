# Lithium
Text editor that using native X11. Suitable in Unix/Unix-like environment. <br>
Good for C/C++ and Assembly language.

# Features
- File format detection
- Syntax Highlighting
- Custom HotKeys
- Custom Themes
- Snippets
- LLVM LSP

# Tested Platform
- [x] FreeBSD 12
- [x] LinuxMint 21

# Dependencies & Toolchains
- libX11
- LLVM 15.0
- gmake
- CMake 3.2x

# Build

Makefile
```
make buildware
```

CMake
```
mkdir build
cd build
cmake ..
make
```


