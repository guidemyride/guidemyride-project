
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

guidemyride_test_sources(
    stub.test.cc
)

guidemyride_test_libraries(
    guidemyride::auth
)

guidemyride_test_add(
    "auth"
    "Run unit tests (Authentication service)"
)
