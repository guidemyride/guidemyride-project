
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

set(GMR_AUTH_SOURCES
    authd.cc
)

add_executable(gmr-authd
    ${GMR_AUTH_SOURCES}
)

target_link_libraries(gmr-authd
    PRIVATE
        guidemyride::protos
        guidemyride::libguidemyride
)
