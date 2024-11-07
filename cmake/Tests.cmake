
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(GTest REQUIRED)

function(guidemyride_test_add TARGET DESCRIPTION)
    if (NOT DEFINED TEST_SOURCES OR TEST_SOURCES STREQUAL "")
        message(FATAL_ERROR 
            "[Guide My Ride] No test sources were defined!\n"
            "(You can define test sources with guidemyride_test_sources() macro)"
        )
    endif()

    get_filename_component(TEST_TYPE ${CMAKE_CURRENT_LIST_DIR} NAME)

    set(TEST_RUNNER
        "gmr_${TARGET}_${TEST_TYPE}_runner"
    )

    add_executable(${TEST_RUNNER}
        ${TEST_SOURCES}
    )

    target_link_libraries(${TEST_RUNNER}
        PRIVATE
            GTest::gtest
            GTest::gtest_main
            GTest::gmock
            GTest::gmock_main
            ${TEST_LIBRARIES}
    )

    add_test(
        NAME ${DESCRIPTION}
        COMMAND ${TEST_RUNNER}
    )
endfunction()

macro(guidemyride_test_sources files)
    set(TEST_SOURCES 
        ${files}
    )
endmacro()

macro(guidemyride_test_libraries libs)
    set(TEST_LIBRARIES
        ${libs}
    )
endmacro()
