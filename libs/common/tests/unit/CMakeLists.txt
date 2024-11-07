
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(GTest 1.15 REQUIRED)

set(GMR_COMMON_UNIT_SOURCES
    models/driver.test.cc
    models/session.test.cc
    utils/hash.test.cc
)

add_executable(gmr_common_unit_runner 
    ${GMR_COMMON_UNIT_SOURCES}
)
target_link_libraries(gmr_common_unit_runner 
    PRIVATE 
        GTest::gtest 
        GTest::gtest_main 
        GTest::gmock
        GTest::gmock_main
        guidemyride::guidemyride
)

add_test(
    NAME "Run unit tests (Common)" 
    COMMAND gmr_common_unit_runner
)
