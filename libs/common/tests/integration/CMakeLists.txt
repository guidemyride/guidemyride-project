
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(GTest REQUIRED)
include(GoogleTest)

set(TEST_SOURCES
    models/driver.test.cc
    models/session.test.cc
)

add_executable(gmr-common-integration-tests ${TEST_SOURCES})
target_link_libraries(gmr-common-integration-tests
    PUBLIC
        GTest::gtest
        GTest::gtest_main

        guidemyride::guidemyride
)

gtest_discover_tests(gmr-common-integration-tests
    WORKING_DIRECTORY
        ${CMAKE_CURRENT_LIST_DIR}
    TEST_PREFIX
        integration::
)
