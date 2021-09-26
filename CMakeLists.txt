# top-level file
# ==============

cmake_minimum_required(VERSION 3.15)

# setting up a project
project(hello-cmake VERSION 1.0
        DESCRIPTION "CMake learning project"
        LANGUAGES C CXX)

# specify C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(TARGET_NAME ${CMAKE_PROJECT_NAME})

# set helloclass "module" path
set (HELLO_PATH hello)


add_executable(${TARGET_NAME} hello.cpp)

add_subdirectory(${HELLO_PATH})


# TODO: use find_library to add third-party libs.
# TODO: Find out how this works. 
#find_library(IUP_LIBRARY 
#        NAMES ${CMAKE_STATIC_LIBRARY_PREFIX}iup${CMAKE_STATIC_LIBRARY_SUFFIX} 
#        HINTS ${CMAKE_SOURCE_DIR}/lib/iup)



target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib/include)


# NOTE This does not work
#set(IUP_LIBRARY_PATH ${CMAKE_SOURCE_DIR}/lib/iup/libiup.a)
#target_link_libraries(${TARGET_NAME} PUBLIC ${IUP_LIBRARY})


add_library(IUP_LIBRARY STATIC IMPORTED)
set_target_properties(IUP_LIBRARY PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/iup/libiup.a)

target_link_libraries(${TARGET_NAME} PUBLIC IUP_LIBRARY)


# these work
target_link_libraries(${TARGET_NAME} PUBLIC gdi32)
target_link_libraries(${TARGET_NAME} PUBLIC comdlg32)
target_link_libraries(${TARGET_NAME} PUBLIC comctl32)
target_link_libraries(${TARGET_NAME} PUBLIC uuid)
target_link_libraries(${TARGET_NAME} PUBLIC oleaut32)
target_link_libraries(${TARGET_NAME} PUBLIC ole32)

