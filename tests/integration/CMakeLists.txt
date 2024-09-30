
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(GTest 1.15 REQUIRED)

set(LIBGMR_INTEGRATION_SOURCES
    test_postgres_connection.cc
)

add_executable(libgmr_integration_runner ${LIBGMR_INTEGRATION_SOURCES})
target_include_directories(libgmr_tests_runner PRIVATE ${LIBGMR_INCLUDE_DIR})
target_link_libraries(libgmr_integration_runner PRIVATE GTest::gtest
                                                        GTest::gtest_main
                                                        GTest::gmock
                                                        GTest::gmock_main
                                                        guidemyride)

add_test(NAME "Run integration tests" COMMAND libgmr_integration_runner)
