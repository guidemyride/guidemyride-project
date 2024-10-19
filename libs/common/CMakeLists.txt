
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

cmake_minimum_required(VERSION 3.25.1)

# test options 
option(LIBGMR_BUILD_UNIT_TESTS "Build unit tests" OFF)
option(LIBGMR_BUILD_INTEGRATION_TESTS "Build integration tests" OFF)

# build options
option(LIBGMR_BUILD_SHARED "Build shared library" OFF)

set(LIBGMR_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src)

# Include tests
if(LIBGMR_BUILD_UNIT_TESTS OR LIBGMR_BUILD_INTEGRATION_TESTS)
    include(CTest)
    enable_testing()

    add_subdirectory(tests)
endif()
