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
bmake buildware
```

CMake
```
mkdir build
cd build
cmake -DCMAKE_C_COMPILER=/path/to/clang \
      -DCMAKE_CXX_COMPILER=/path/to/clang++ \
      ..
make
```


