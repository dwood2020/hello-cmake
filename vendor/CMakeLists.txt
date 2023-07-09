# ==============================================================================
# Level: /vendor
# ==============================================================================

# Define IUP target
# -----------------
# 
add_library(${LIB_IUP_TARGET} STATIC IMPORTED GLOBAL)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    if (CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
        set_target_properties(${LIB_IUP_TARGET} PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/iup/include
            IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/iup/lib/windows-x64/mingw/libiup.a
            INTERFACE_LINK_LIBRARIES "gdi32;comdlg32;comctl32;uuid;oleaut32;ole32"
        )
    elseif(CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
        set_target_properties(${LIB_IUP_TARGET} PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/iup/include
            IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/iup/lib/linux-x64/libiup.a
            INTERFACE_LINK_LIBRARIES dl
        )
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set_target_properties(${LIB_IUP_TARGET} PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/iup/include
        IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/iup/lib/windows-x64/msvc/iup.lib
        INTERFACE_LINK_LIBRARIES "ole32;comctl32"
        INTERFACE_COMPILE_DEFINITIONS "/NODEFAULTLIB:LIBCMT"    # Avoid LNK4098
    )
endif()
