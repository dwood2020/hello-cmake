# ==============================================================================
# Level: /main
# ==============================================================================

add_executable(${MAIN_TARGET})
target_sources(${MAIN_TARGET} PRIVATE
    "src/main.cpp"
)

target_include_directories(${MAIN_TARGET} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${MAIN_TARGET} PRIVATE hello::base)
