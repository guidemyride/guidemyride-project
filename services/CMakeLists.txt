
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

if(GMR_BUILD_AUTH)
    add_subdirectory(auth)
endif()

if(GMR_BUILD_DRIVER)
    add_subdirectory(driver)
endif()

if(GMR_BUILD_PASSENGER)
    add_subdirectory(passenger)
endif()
