# ==============================================================================
# Project top-level file: /
# ==============================================================================

cmake_minimum_required(VERSION 3.15)

# Set up the project and specify the C++ standard.
project(hello-cmake 
    VERSION 1.0
    DESCRIPTION "Minimal project to get started with CMake."
    LANGUAGES C CXX
)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Introduce the targets.
set(MAIN_TARGET ${CMAKE_PROJECT_NAME})
set(LIB_HELLO_TARGET hello)
set(LIB_IUP_TARGET iup)


add_subdirectory(main)
add_subdirectory(hello)

target_link_libraries(${MAIN_TARGET} PRIVATE ${LIB_HELLO_TARGET})

