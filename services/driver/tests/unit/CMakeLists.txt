
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(GTest REQUIRED)
include(GoogleTest)

set(TEST_SOURCES
    stub.test.cc
)

add_executable(gmr-driver-unit-tests ${TEST_SOURCES})
target_link_libraries(gmr-driver-unit-tests
    PUBLIC
        GTest::gtest
        GTest::gtest_main
        guidemyride::driver
)

gtest_discover_tests(gmr-driver-unit-tests
    WORKING_DIRECTORY
        ${CMAKE_CURRENT_LIST_DIR}
    TEST_PREFIX
        unit::
)
