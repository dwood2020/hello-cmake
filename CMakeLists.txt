# top-level file
# ==============

cmake_minimum_required(VERSION 3.15)

# setting up a project
project(hello-cmake VERSION 1.0
        DESCRIPTION "Minimal project to get started with CMake."
        LANGUAGES C CXX)

# specify C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(TARGET_NAME ${CMAKE_PROJECT_NAME})

# set helloclass "module" path
set (HELLO_PATH hello)

# add the executable target
add_executable(${TARGET_NAME} hello.cpp)

# add the "hello" subdirectory
add_subdirectory(${HELLO_PATH})


#find_library(IUP_LIBRARY 
#        NAMES ${CMAKE_STATIC_LIBRARY_PREFIX}iup${CMAKE_STATIC_LIBRARY_SUFFIX} 
#        HINTS ${CMAKE_SOURCE_DIR}/lib/iup)


# add an additional include directory
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib/include)

# add IUP as "imported" library (3rd party lib)
add_library(IUP_LIBRARY STATIC IMPORTED)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        # IUP library for MinGW/GCC
        set_target_properties(IUP_LIBRARY PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/iup/libiup.a)
        target_link_libraries(${TARGET_NAME} PUBLIC IUP_LIBRARY)

        # additional libraries required for IUP on MinGW/GCC
        target_link_libraries(${TARGET_NAME} PUBLIC gdi32)
        target_link_libraries(${TARGET_NAME} PUBLIC comdlg32)
        target_link_libraries(${TARGET_NAME} PUBLIC comctl32)
        target_link_libraries(${TARGET_NAME} PUBLIC uuid)
        target_link_libraries(${TARGET_NAME} PUBLIC oleaut32)
        target_link_libraries(${TARGET_NAME} PUBLIC ole32)
endif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")



