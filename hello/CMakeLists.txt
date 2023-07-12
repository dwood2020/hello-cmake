# ==============================================================================
# Level: /hello
# Public linkage to: hello::base
# ==============================================================================

# This file defines the library target of a static library.
# Note that the sources of this target are PRIVATE, but the include directories
# of this target are PUBLIC. This means, that the include directories are 
# propagated to the target which this target is linked to, but the sources are not.
#
# To link against this library, a public alias target is defined. This way,
# a consumer does not need to interact with the library's actual build target.

set(LIB_HELLO_TARGET hello)
add_library(${LIB_HELLO_TARGET} STATIC)
target_sources(${LIB_HELLO_TARGET} PRIVATE
    "src/HelloClass.cpp"
)

target_include_directories(${LIB_HELLO_TARGET} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Public alias target to link to.
add_library(hello::base ALIAS ${LIB_HELLO_TARGET})
