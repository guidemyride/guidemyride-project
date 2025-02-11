
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

set(GMR_PASSENGER_SOURCES
    controllers/stub_method.cc
)

add_library(passenger OBJECT ${GMR_PASSENGER_SOURCES})
add_library(guidemyride::passenger ALIAS passenger)

target_link_libraries(passenger
    PRIVATE
        guidemyride::protos
        guidemyride::guidemyride
)

add_executable(gmr-passengerd 
    $<TARGET_OBJECTS:guidemyride::passenger>
    passengerd.cc
)
target_link_libraries(gmr-passengerd
    PRIVATE
        guidemyride::protos
        guidemyride::guidemyride

        guidemyride::passenger
)

install(TARGETS gmr-passengerd 
    RUNTIME 
    DESTINATION 
        bin
    COMPONENT
        passengerd
)

cpack_add_component(passengerd
    DISPLAY_NAME
        "GuideMyRide - Passenger Service"
)
