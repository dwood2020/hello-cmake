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


# add an additional include directory
target_include_directories(${TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib/include)

# add IUP as "imported" library (3rd party lib)
add_library(IUP_LIBRARY STATIC IMPORTED)

# print host system name
message("CMAKE HOST SYTEM NAME: " ${CMAKE_HOST_SYSTEM_NAME})

if (CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
        if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")                
                # IUP library for MinGW
                set_target_properties(IUP_LIBRARY PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/windows-x64/libiup.a)
                target_link_libraries(${TARGET_NAME} PUBLIC IUP_LIBRARY)

                # additional libraries required for IUP on MinGW
                target_link_libraries(${TARGET_NAME} PUBLIC gdi32)
                target_link_libraries(${TARGET_NAME} PUBLIC comdlg32)
                target_link_libraries(${TARGET_NAME} PUBLIC comctl32)
                target_link_libraries(${TARGET_NAME} PUBLIC uuid)
                target_link_libraries(${TARGET_NAME} PUBLIC oleaut32)
                target_link_libraries(${TARGET_NAME} PUBLIC ole32)

        elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
                set_target_properties(IUP_LIBRARY PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/windows-x64/iup.lib)
                target_link_libraries(${TARGET_NAME} PUBLIC IUP_LIBRARY)

                target_link_libraries(${TARGET_NAME} PUBLIC comctl32)
        endif()

elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
        # currently only GCC is supported on Linux:

        #set_target_properties(IUP_LIBRARY PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/lib/linux-x64/libiup.a)
        #target_link_libraries(${TARGET_NAME} PUBLIC IUP_LIBRARY)        

        #TODO: This is a new function (avail. since 3.13) which "should be avoided" - see into this!
        target_link_directories(${TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib/linux-x64)
        target_link_libraries(${TARGET_NAME} PUBLIC iup)

        target_link_libraries(${TARGET_NAME} PUBLIC dl)

        # includes for direct usage of GTK3 - unused
        #target_link_libraries(${TARGET_NAME} PUBLIC gtk3 gdk3)
        #target_link_libraries(${TARGET_NAME} PUBLIC gdk_pixbuf-2.0)
        #target_link_libraries(${TARGET_NAME} PUBLIC pangocairo-1.0)
        #target_link_libraries(${TARGET_NAME} PUBLIC pango-1.0)
        #target_link_libraries(${TARGET_NAME} PUBLIC cairo)
        #target_link_libraries(${TARGET_NAME} PUBLIC gobject-2.0)
        #target_link_libraries(${TARGET_NAME} PUBLIC gmodule-2.0)
        #target_link_libraries(${TARGET_NAME} PUBLIC glib-2.0)
        #target_link_libraries(${TARGET_NAME} PUBLIC Xext)
        #target_link_libraries(${TARGET_NAME} PUBLIC X11)
        #target_link_libraries(${TARGET_NAME} PUBLIC m)
endif()



