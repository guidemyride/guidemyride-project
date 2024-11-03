
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

set(GMR_DRIVER_SOURCES
    driverd.cc
)

add_executable(gmr-driverd 
    ${GMR_DRIVER_SOURCES}
)

target_link_libraries(gmr-driverd
    PRIVATE
        guidemyride::protos
        guidemyride::libguidemyride
)
