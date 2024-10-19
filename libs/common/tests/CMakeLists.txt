
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

if (LIBGMR_BUILD_UNIT_TESTS)
    add_subdirectory(unit)
endif()

if(LIBGMR_BUILD_INTEGRATION_TESTS)
    add_subdirectory(integration)
endif()
