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


# Just a message to make sure the build target architecture is correct.
if (${CMAKE_SIZEOF_VOID_P} STREQUAL "4")
    message("Attempting 32-bit build.")
elseif(${CMAKE_SIZEOF_VOID_P} STREQUAL "8")
    message("Attempting 64-bit build.")
endif()

# Project-wide settings.
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # Avoid LNK4098
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:LIBCMT")
endif()



# Introduce the targets (Note that this can be done in a modular way too - see hello subdir).
set(MAIN_TARGET ${CMAKE_PROJECT_NAME})
set(LIB_IUP_TARGET iup)

# Include the subdirectories and link the lib targets to the exe target.
add_subdirectory(hello)
add_subdirectory(main)
add_subdirectory(vendor)

target_link_libraries(${MAIN_TARGET} PRIVATE ${LIB_IUP_TARGET})

