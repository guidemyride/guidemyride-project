
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

set(GMR_AUTH_SOURCES
    authd.cc
)

add_library(auth OBJECT ${GMR_AUTH_SOURCES})
add_library(guidemyride::auth ALIAS auth)

target_link_libraries(auth
    PRIVATE
        guidemyride::protos
        guidemyride::guidemyride
)

add_executable(gmr-authd 
    $<TARGET_OBJECTS:guidemyride::auth>
)

install(TARGETS gmr-authd 
    RUNTIME 
    DESTINATION 
        bin 
    COMPONENT 
        authd
)

cpack_add_component(authd
    DISPLAY_NAME 
        "GuideMyRide - Authentication Service"
)
