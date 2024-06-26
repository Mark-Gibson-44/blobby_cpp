cmake_minimum_required(VERSION 3.1)

project(Blobby VERSION 1.0)
set(Blobby_VERSION 0.1)

enable_language(CXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CPP_COMPILER g++)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 20)

set(BUILDTIME_CONFIG_DIR)
set(SANITIZER_TYPES NONE UBSAN_ASAN TSAN)

set(DISABLE_RUNTIME_WARNINGS No     CACHE BOOL "Disable runtime warnings")
set(WARNINGS_AS_ERRORS Yes     CACHE BOOL "Warnings as errors")
set(ENABLE_SANITIZERS  UBSAN_ASAN     CACHE BOOL "Build with a sanitizer")

SET(BASEPATH "${CMAKE_SOURCE_DIR}")

if(UNIX)
    set(CPP_EXTRA_WARNINGS         No       CACHE BOOL "Add -Wextra warnings for g++")
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "CMake Build Configuration" FORCE)
endif()

add_subdirectory(blobby)


