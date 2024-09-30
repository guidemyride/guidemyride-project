
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(GTest 1.15 REQUIRED)

set(LIBGMR_UNIT_SOURCES
    test_session.cc
    test_connection_pool.cc
    test_connection.cc
)

add_executable(libgmr_unit_runner ${LIBGMR_UNIT_SOURCES})
target_include_directories(libgmr_unit_runner PRIVATE ${LIBGMR_INCLUDE_DIR})
target_link_libraries(libgmr_unit_runner PRIVATE GTest::gtest 
                                                 GTest::gtest_main 
                                                 GTest::gmock 
                                                 GTest::gmock_main
                                                 guidemyride)

add_test(NAME "Run unit tests" COMMAND libgmr_unit_runner)
