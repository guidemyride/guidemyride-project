
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

# Required versions for gnu/clang compiler 
set(LIBGMR_GNU_COMPILER_VERSION "13.0" CACHE STRING "Required g++ compiler version")
set(LIBGMR_CLANG_COMPILER_VERSION "18.0" CACHE STRING "Required clang++ compiler version")

message(STATUS "[Guide My Ride] Checking compiler version... ")
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS LIBGMR_GCC_COMPILER_VERSION)
        message(FATAL_ERROR 
            "g++ version >= ${LIBGMR_GNU_COMPILER_VERSION} required! "
            "(Found ${CMAKE_CXX_COMPILER_VERSION})"
        )
    else()
        message(STATUS "[Guide My Ride] Using g++ compiler (libstdc++)")
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # Use libc++ library 
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS LIBGMR_CLANG_COMPILER_VERSION)
        message(FATAL_ERROR 
            "clang++ version >= ${LIBGMR_CLANG_COMPILER_VERSION} required! "
            "(Found ${CMAKE_CXX_COMPILER_VERSION})"
        )
    else()
        message(STATUS "[Guide My Ride] Using clang++ compiler (libc++)")
    endif()
else()
    message(FATAL_ERROR "Only g++/clang compilers are supported!")
endif()

