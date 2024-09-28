find_package(GTest 1.15 QUIET)

set(LIBGMR_TEST_SOURCES
    test_session.cc
    test_connection.cc
    test_connection_pool.cc
)

if (NOT GTest_Found)
    message(STATUS "GTest not found, downloading")
    include(FetchContent)
    FetchContent_Declare(
        GTest 
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG	v1.15.2
    )
    FetchContent_MakeAvailable(GTest)
endif()

add_executable(libgmr_tests_runner ${LIBGMR_TEST_SOURCES})
target_include_directories(libgmr_tests_runner PRIVATE ${LIBGMR_INCLUDE_DIR})
target_link_libraries(libgmr_tests_runner PRIVATE GTest::gtest 
                                                  GTest::gtest_main 
                                                  GTest::gmock 
                                                  GTest::gmock_main
                                                  guidemyride)

add_test(NAME libgmr_tests_runner COMMAND libgmr_tests_runner)
