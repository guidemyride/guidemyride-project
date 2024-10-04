
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#ifndef GUIDEMYRIDE_CONNECTION_POOL_H_
#define GUIDEMYRIDE_CONNECTION_POOL_H_

#pragma once

#include <condition_variable>
#include <mutex>
#include <queue>
#include <span>

namespace guidemyride::connection {

class IConnection;

/// @brief Connection pool class
///
/// This class implements object pool co
class ConnectionPool {
  public:
    /// @brief Construct pool from existing connections
    ///
    /// Initialize ConnectionPool with existing connections.
    ///
    /// @param connections span of connections
    ConnectionPool(std::span<IConnection> connections);
    ConnectionPool(std::span<IConnection *> connections);

    /// @brief Get free connection from the pool
    ///
    /// Get free connection from the pool. When connection is not required
    /// any more, it should be added back with addConnection() method.
    ///
    /// @see addConnection()
    [[nodiscard]] IConnection *getConnection();

    /// @brief Add new connection to the pool
    ///
    /// Add new connection to the free connections queue and
    /// notify thread about released connection
    ///
    /// @param connection pointer to the connection object
    void addConnection(IConnection *connection);

    /// @brief Get ammount of free connections in the pool
    ///
    /// This function returns size of the connection pool queue
    size_t getSize() { return mConnectionsQueue.size(); };

    /// @brief Destructor
    ///
    /// Removes all backref in connections
    ~ConnectionPool();

  private:
    std::mutex mConnectionsPoolMutex;            ///< Connection Pool Mutex
    std::queue<IConnection *> mConnectionsQueue; ///< Queue of free connections
    std::vector<IConnection *> mConnectionsPool; ///< All connections
    std::condition_variable mFreeConnectionsCV;  ///< Free connection condition
};

}; // namespace guidemyride::connection

#endif // GUIDEMYRIDE_CONNECTION_POOL_H_
