
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

set(GMR_DRIVER_SOURCES
    controllers/stub_method.cc
)

add_library(driver OBJECT ${GMR_DRIVER_SOURCES})
add_library(guidemyride::driver ALIAS driver)

target_link_libraries(driver
    PRIVATE
        guidemyride::protos
        guidemyride::guidemyride
)

add_executable(gmr-driverd $<TARGET_OBJECTS:guidemyride::driver> driverd.cc)
target_link_libraries(gmr-driverd
    PUBLIC
        guidemyride::protos
        guidemyride::guidemyride
)

install(TARGETS gmr-driverd 
    RUNTIME 
    DESTINATION 
        bin
    COMPONENT
        driverd 
)

cpack_add_component(driverd
    DISPLAY_NAME
        "GuideMyRide - Driver Service"
)
