
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(GTest REQUIRED)
include(GoogleTest)

set(TEST_SOURCES
    stub.test.cc
)

add_executable(gmr-driver-integration-tests ${TEST_SOURCES})
target_link_libraries(gmr-driver-integration-tests
    PUBLIC
        GTest::gtest
        GTest::gtest_main

        guidemyride::driver
        guidemyride::protos

        guidemyride::guidemyride
)

gtest_discover_Tests(gmr-driver-integration-tests
    WORKING_DIRECTORY
        ${CMAKE_CURRENT_LIST_DIR}
    TEST_PREFIX
        services::driver::integration::
)
