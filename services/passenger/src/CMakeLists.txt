
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

set(GMR_PASSENGER_SOURCES
    passengerd.cc
)

add_executable(gmr-passengerd 
    ${GMR_PASSENGER_SOURCES}
)

target_link_libraries(gmr-authd
    PRIVATE
        guidemyride::protos
        guidemyride::libguidemyride
)
