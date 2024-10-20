
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(libpqxx REQUIRED)
find_package(argon2 REQUIRED)

set(GMR_COMMON_SOURCES
    utils/hash.cc
)

if (GMR_COMMON_BUILD_SHARED OR BUILD_SHARED_LIBS)
    add_library(guidemyride SHARED ${GMR_COMMON_SOURCES})
else()
    add_library(guidemyride STATIC ${GMR_COMMON_SOURCES})
endif()

target_link_libraries(guidemyride PUBLIC libpqxx::pqxx 
                                         argon2::argon2)

target_include_directories(guidemyride PUBLIC ${GMR_COMMON_INCLUDE_DIR})
