
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

find_package(libpqxx REQUIRED)

set(LIBGMR_SOURCES
    connection_pool.cc
    postgres_connection.cc
)

if (LIBGMR_BUILD_SHARED OR BUILD_SHARED_LIBS)
    add_library(guidemyride SHARED ${LIBGMR_SOURCES})
else()
    add_library(guidemyride STATIC ${LIBGMR_SOURCES})
endif()

target_link_libraries(guidemyride PUBLIC libpqxx::pqxx)
target_include_directories(guidemyride PUBLIC ${LIBGMR_INCLUDE_DIR})
