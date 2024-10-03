
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#include <guidemyride/postgres_connection.h>

using namespace guidemyride::connection;

PostgresConnection::PostgresConnection(const char *user, const char *password,
                                       const char *dbname, const char *host,
                                       uint16_t port) {
    std::string connectionString =
        std::format("host={} port={} dbname={} user={} password={}", host, port,
                    dbname, user, password);

    try {
        mConnection = new pqxx::connection(connectionString);
    } catch (const std::exception e) {
        throw;
    }
}
