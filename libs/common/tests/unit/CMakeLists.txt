
# SPDX-License-Identifier: MIT
# Copyright (c) 2024 nyashbox

guidemyride_test_sources(
    models/driver.test.cc
    models/session.test.cc

    utils/hash.test.cc
)

guidemyride_test_libraries(
    guidemyride::guidemyride
)

guidemyride_test_add(
    "common"
    "Run unit tests (Common library)"
)
