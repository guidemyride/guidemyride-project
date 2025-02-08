
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

set(GMR_AUTH_SOURCES
    controllers/stub_method.cc
)

add_library(auth-obj OBJECT ${GMR_AUTH_SOURCES})
add_library(guidemyride::auth ALIAS auth-obj)

target_link_libraries(auth-obj
    PUBLIC
        guidemyride::protos
        guidemyride::guidemyride
)

add_executable(gmr-authd $<TARGET_OBJECTS:guidemyride::auth> authd.cc)
target_link_libraries(gmr-authd
    PUBLIC 
        guidemyride::protos
        guidemyride::guidemyride
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
