
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(libpqxx REQUIRED)
find_package(argon2 REQUIRED)

set(LIBGMR_SOURCES
    utils/hash.cc
)

if (LIBGMR_BUILD_SHARED OR BUILD_SHARED_LIBS)
    add_library(guidemyride SHARED ${LIBGMR_SOURCES})
else()
    add_library(guidemyride STATIC ${LIBGMR_SOURCES})
endif()

target_link_libraries(guidemyride PUBLIC libpqxx::pqxx 
                                         argon2::argon2)
target_include_directories(guidemyride PUBLIC ${LIBGMR_INCLUDE_DIR})
