
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

include(CTest)
enable_testing()

if (GMR_COMMON_BUILD_UNIT_TESTS)
    add_subdirectory(unit)
endif()

if (GMR_COMMON_BUILD_INTEGRATION_TESTS)
    add_subdirectory(integration)
endif()
