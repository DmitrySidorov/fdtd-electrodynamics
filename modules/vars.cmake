set(LANGUAGE CXX)

MESSAGE ("  CMAKE_ROOT = ${CMAKE_ROOT}")
MESSAGE ("  LANGUAGE = ${LANGUAGE}")
MESSAGE ("  PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")
MESSAGE ("  PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")

add_definitions("-g")

# compiler-specific C++11 activation 
if (CMAKE_COMPILER_IS_GNUCXX)
    execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
    if (GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
        message(STATUS "C++11 activated.")
        add_definitions("-std=gnu++11")
    elseif(GCC_VERSION VERSION_GREATER 4.3 OR GCC_VERSION VERSION_EQUAL 4.3)
        message(WARNING "C++0x activated. If you get any errors update to a compiler which fully supports C++11")
        add_definitions("-std=gnu++0x")
    else()
        message(FATAL_ERROR "${PROJECT_NAME} requires g++ 4.7 or greater.")
    endif ()
elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
else ()
    message(FATAL_ERROR "Your C++ compiler does not support C++11.")
endif ()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
MESSAGE ("  CMAKE_ARCHIVE_OUTPUT_DIRECTORY = ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
MESSAGE ("  CMAKE_LIBRARY_OUTPUT_DIRECTORY = ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
MESSAGE ("  CMAKE_RUNTIME_OUTPUT_DIRECTORY = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/modules)
MESSAGE ("  CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")


# this is required for CHECK_TYPE_SIZE, CHECK_INCLUDE_FILE etc...
if(WIN32)
    set(CMAKE_REQUIRED_FLAGS "-include windows.h")
    MESSAGE ("  CMAKE_REQUIRED_FLAGS = ${CMAKE_REQUIRED_FLAGS}")
endif(WIN32)

# TODO: append this variable anywhere to cleanup custom targets
set(ADDITIONAL_MAKE_CLEAN_FILES_LIST)
