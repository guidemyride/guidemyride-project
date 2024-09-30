
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

cmake_minimum_required(VERSION 3.25.1)

project(libguidemyride
        DESCRIPTION "Guide My Ride shared library"
        VERSION 0.1.0
        LANGUAGES CXX)

LIST(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CheckCompiler)

# testing options
option(LIBGMR_BUILD_UNIT_TESTS "Build unit tests" OFF)
option(LIBGMR_BUILD_INTEGRATION_TESTS "Build integration tests" OFF)

option(LIBGMR_BUILD_SHARED "Build shared library" OFF)

set(LIBGMR_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)

if(LIBGMR_BUILD_TESTS)
    include(CTest)
    enable_testing()

    add_subdirectory(tests)
endif()
