
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

guidemyride_test_sources(
    stub.test.cc
)

guidemyride_test_libraries(
    guidemyride::driver
)

guidemyride_test_add(
    "driver"
    "Run unit tests (Driver service)"
)
