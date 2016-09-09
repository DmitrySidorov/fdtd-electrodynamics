cmake_minimum_required(VERSION 3.0)

project (FDTD)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

include("${PROJECT_SOURCE_DIR}/modules/macro.cmake")
include("${PROJECT_SOURCE_DIR}/modules/vars.cmake")
include("${PROJECT_SOURCE_DIR}/modules/configure.cmake")
include("${PROJECT_SOURCE_DIR}/modules/package.cmake")

add_subdirectory(src)

# the ADDITIONAL_MAKE_CLEAN_FILES_LIST grows anywhere during configuration process
SET_DIRECTORY_PROPERTIES(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${ADDITIONAL_MAKE_CLEAN_FILES_LIST}")
