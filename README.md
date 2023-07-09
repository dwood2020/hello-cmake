# hello-cmake
---

Minimal project to get started with CMake.

### Currently covers:   
- one executable target
- one library target
- third-party library ("imported" lib) - uses the IUP library: <https://www.tecgraf.puc-rio.br/iup/> - see [IUP_LICENSE.md](vendor/iup/IUP_LICENSE.md)
- subdirectories

--- 
### Usage
For simplicity, 64-bit IUP binary libs are included in this repo for Windows and Linux.

#### Windows - MinGW
```
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build . -j
```

#### Windows - MSVC / Visual Studio
```
mkdir build
cd build
cmake -G "Visual Studio 17 2022" -A x64 ..
cmake --build .
```

#### Linux - GCC
```
mkdir build
cd build
cmake -G "Unix Makefiles" ..
cmake --build . -j
```





