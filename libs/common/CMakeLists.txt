
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

cmake_minimum_required(VERSION 3.25.1)

# test options 
option(GMR_COMMON_BUILD_UNIT_TESTS "Build unit tests" OFF)
option(GMR_COMMON_BUILD_INTEGRATION_TESTS "Build integration tests" OFF)

# build options
option(GMR_COMMON_BUILD_SHARED "Build shared library" OFF)

set(GMR_COMMON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src)
add_subdirectory(tests)
