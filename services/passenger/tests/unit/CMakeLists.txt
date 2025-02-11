
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(GTest REQUIRED)
include(GoogleTest)

set(TEST_SOURCES
    stub.test.cc
)

add_executable(gmr-passenger-unit-tests ${TEST_SOURCES})
target_link_libraries(gmr-passenger-unit-tests
    PUBLIC
        GTest::gtest
        GTest::gtest_main

        guidemyride::protos
        guidemyride::guidemyride

        guidemyride::passenger
)

gtest_discover_tests(gmr-passenger-unit-tests
    WORKING_DIRECTORY
        ${CMAKE_CURRENT_LIST_DIR}
    TEST_PREFIX
        unit::
)
