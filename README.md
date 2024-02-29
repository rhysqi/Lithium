# Lithium
Text editor that using native X11 and Win32. Suitable in Unix/Unix-like environment. <br>
Good for C/C++ and Assembly language.

# Features
- File format detection (Upcoming)
- Syntax Highlighting (Upcoming)
- Custom HotKeys (Upcoming)
- Custom Themes (Upcoming)
- Custom Snippets (Upcoming)
- LLVM LSP (Upcoming)

# Supported Platform
| Platform | Version | Tier |
|  :---:  | :---: | :---: |
| FreeBSD | 14.0 | Tier A |
| LinuxMint | 21 | Tier B |
| Windows | 11 | Tier A |

- Tier A = Full Supported
- Tier B = Half Supported
- Tier C = Experimental

# Dependencies & Toolchains
- libX11
- LLVM 15.0
- gmake
- CMake 3.2x
- Windows SDK

# Build

### <b>Unix/Unix-like build</b> <br>
Makefile
```
gmake buildware
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

### <b>Windows build</b> <br>
Makefile
```
gmake buildware-win32
```
