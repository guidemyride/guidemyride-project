
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

guidemyride_test_sources(
    stub.test.cc
)

guidemyride_test_libraries(
    guidemyride::passenger
)

guidemyride_test_add(
    "passenger"
    "Run integration tests (Passenger service)"
)
