cmake_minimum_required(VERSION 3.25.1)

project(libguidemyride
        DESCRIPTION "Guide My Ride shared library"
        VERSION 0.1.0
        LANGUAGES CXX)

# testing options
option(LIBGMR_BUILD_TESTS "Build tests" OFF)
option(LIBGMR_BUILD_SHARED "Build shared library" OFF)

set(LIBGMR_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)

if(LIBGMR_BUILD_TESTS)
    include(CTest)
    enable_testing()

    add_subdirectory(tests)
endif()
