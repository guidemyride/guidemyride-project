
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(GTest 1.15 REQUIRED)

set(GMR_COMMON_INTEGRATION_SOURCES
    models/driver.test.cc
    models/session.test.cc
)

add_executable(gmr_common_integration_runner 
        ${GMR_COMMON_INTEGRATION_SOURCES}
)
target_link_libraries(gmr_common_integration_runner 
    PRIVATE 
        GTest::gtest
        GTest::gtest_main
        GTest::gmock
        GTest::gmock_main
        guidemyride::guidemyride
)

add_test(NAME "Run integration tests (Common)" 
         COMMAND gmr_common_integration_runner)
