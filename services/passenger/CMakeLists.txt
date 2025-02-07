
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

cmake_minimum_required(VERSION 3.25.1)

# test options
option(GMR_PASSENGER_BUILD_UNIT_TESTS "Build unit tests" OFF)
option(GMR_PASSENGER_BUILD_INTEGRATION_TESTS "Build integration tests" OFF)

add_subdirectory(src)
add_subdirectory(tests)
