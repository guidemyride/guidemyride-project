
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(argon2 REQUIRED)

set(GMR_COMMON_SOURCES
    utils/hash.cc
)

if (GMR_COMMON_BUILD_SHARED OR BUILD_SHARED_LIBS)
    add_library(guidemyride SHARED ${GMR_COMMON_SOURCES})
else()
    add_library(guidemyride STATIC ${GMR_COMMON_SOURCES})
endif()

add_library(guidemyride::guidemyride ALIAS guidemyride)
add_library(guidemyride::libguidemyride ALIAS guidemyride)

target_link_libraries(guidemyride 
    PUBLIC
        argon2::argon2)

target_include_directories(guidemyride PUBLIC ${GMR_COMMON_INCLUDE_DIR})
