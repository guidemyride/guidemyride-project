
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(GTest REQUIRED)
include(GoogleTest)

set(TEST_SOURCES
    models/driver.test.cc
    models/session.test.cc

    utils/hash.test.cc
)

add_executable(gmr-common-unit-tests ${TEST_SOURCES})
target_link_libraries(gmr-common-unit-tests
    PUBLIC
        GTest::gtest
        GTest::gtest_main

        guidemyride::guidemyride
)

gtest_discover_tests(gmr-common-unit-tests
    WORKING_DIRECTORY
        ${CMAKE_CURRENT_LIST_DIR}
    TEST_PREFIX
        libs::common::unit::
)
