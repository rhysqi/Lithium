# Lithium
Text editor that using native Win32 and X11. Suitable in Unix/Unix-like and Windows environment. <br>

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
| Windows | 11 | Tier A |
| FreeBSD | 14.0 | Tier A |
| LinuxMint | 21 | Tier B |

- Tier A = Supported
- Tier B = Experimental

# Dependencies & Toolchains
### Dependencies
- libX11
- Windows API

### Toolchains
- LLVM 16.0.4
- gmake
- CMake 3.2x

# Build

### <b>Windows build</b> <br>
Makefile
```
gmake buildware-win32
```

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
