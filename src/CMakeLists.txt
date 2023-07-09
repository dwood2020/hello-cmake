# ==============================================================================
# Level: /src
# ==============================================================================

target_sources(${MAIN_TARGET} PUBLIC
    "main.cpp"
)

target_include_directories(${MAIN_TARGET} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
