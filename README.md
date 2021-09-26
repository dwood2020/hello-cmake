# hello-cmake
---

Minimal project to get started with CMake.

### Currently covers:   
- one executable
- subdirectories
- third-party libraries ("imported" lib) - uses the IUP library: <https://www.tecgraf.puc-rio.br/iup/> - see IUP_LICENSE.md

--- 
### Usage
This project is 64-bit only. For simplicity, IUP binary libs are included in this repo.

#### Windows - MinGW
```
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
```

#### Windows - MSVC / Visual Studio
```
mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A x64 ..
cmake --build .
```






