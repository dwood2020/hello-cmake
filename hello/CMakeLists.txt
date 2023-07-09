# ==============================================================================
# Level: /hello
# ==============================================================================


add_library(${LIB_HELLO_TARGET} STATIC)
target_sources(${LIB_HELLO_TARGET} PRIVATE
    "src/HelloClass.cpp"
)

target_include_directories(${LIB_HELLO_TARGET} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

