
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#include <gtest/gtest.h>

#include "config.h"
#include <guidemyride/postgres_connection.h>

TEST(PostgresConnection, goodConnection) {
    EXPECT_NO_THROW(guidemyride::connection::PostgresConnection(
        POSTGRES_USERNAME, POSTGRES_PASSWORD, POSTGRES_DBNAME, POSTGRES_HOST,
        POSTGRES_PORT));
}

TEST(PostgresConnection, badConnection) {
    EXPECT_ANY_THROW(guidemyride::connection::PostgresConnection(
                         "bad", "bad", "bad", "localhost", 5432););
}
