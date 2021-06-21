cmake_minimum_required (VERSION 3.3)

project (bison-bug
    LANGUAGES C)

find_package (BISON REQUIRED)

# These may not exist
file (MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/src")
file (MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/bison-bug")

bison_target (BisonBugParser
    "${PROJECT_SOURCE_DIR}/src/parser.y"
    "${PROJECT_BINARY_DIR}/src/parser.y.c"
    DEFINES_FILE "${PROJECT_BINARY_DIR}/include/bison-bug/parser.y.h")

add_executable (bison-bug
    ${BISON_BisonBugParser_OUTPUTS}
    "src/driver.c"
    "src/main.c")
target_include_directories (bison-bug
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    PUBLIC $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>)

