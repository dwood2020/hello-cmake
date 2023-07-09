# ==============================================================================
# Project top-level file: /
# ==============================================================================

cmake_minimum_required(VERSION 3.15)

# set up the project
project(hello-cmake 
    VERSION 1.0
    DESCRIPTION "Minimal project to get started with CMake."
    LANGUAGES C CXX
)

# specify C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(MAIN_TARGET ${CMAKE_PROJECT_NAME})
set(LIB_HELLO_TARGET hello)
set(LIB_IUP_TARGET iup)


add_executable(${MAIN_TARGET})
add_subdirectory(src)

