
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#ifndef GUIDEMYRIDE_POSTGRES_CONNECTION_H_
#define GUIDEMYRIDE_POSTGRES_CONNECTION_H_

#include <pqxx/connection>

#include <guidemyride/connection.h>

namespace guidemyride::connection {

/// @brief Postgres connection class
///
/// This class represents connection to the postgres database
class PostgresConnection : public IConnection {
  public:
    /// @brief Connection constructor
    ///
    /// Create postgres connection string and perform connection to the database
    PostgresConnection(const char *username, const char *password,
                       const char *dbname, const char *host, uint16_t port);

    /// @brief Return reference to the postgres connector
    pqxx::connection &getConnector() { return *mConnection; };

    /// @brief Destructor
    ///
    /// Delete postgres connection
    ~PostgresConnection() { delete mConnection; };

  private:
    pqxx::connection *mConnection; ///< Connection pointer
};

} // namespace guidemyride::connection

#endif // GUIDEMYRIDE_POSTGRES_CONNECTION_H_
