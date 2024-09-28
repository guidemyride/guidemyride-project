
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#ifndef GUIDEMYRIDE_CONNECTION_H_
#define GUIDEMYRIDE_CONNECTION_H_

#pragma once

#include <mutex>

#include <guidemyride/connection_pool.h>

namespace guidemyride::connection {

/// @brief Connection base class
///
/// This class should be used as a base class (inherited) and is not
/// intended to be instantiated.
class IConnection {
    friend ConnectionPool;

  public:
    /// @brief Locks connection
    ///
    /// Locks connection mutex
    virtual void lock() { mConnectionMutex.lock(); };

    /// @brief Releases connection
    ///
    /// returns connection to the pool of free connections
    virtual void release() {
        if (mConnectionPool)
            mConnectionPool->addConnection(this);
    };

    /// @brief Get connection from the pool
    ///
    /// @returns connection pool backref pointer
    virtual const ConnectionPool *getConnectionPool() {
        return mConnectionPool;
    };

    /// @brief Unlocks connection
    ///
    /// Unlocks connection mutex
    virtual void unlock() { mConnectionMutex.unlock(); };

    /// @brief Default destructor
    ///
    /// Created to prevent undefined behaviour
    virtual ~IConnection() {};

  protected:
    /// @brief Default constructor
    ///
    /// Default constructor is protected to prevent instantiation
    IConnection() = default;

    std::mutex mConnectionMutex;     ///< Mutex for locking connection
    ConnectionPool *mConnectionPool; ///< Connection pool back reference
};

/// @brief Manage locking/unlocking connection
///
/// ConnectionGuard locks connection on object creation, and release connection
/// when leaving the scope.
class ConnectionGuard {
  public:
    /// @brief Constructor
    ///
    /// Stores connection reference and locks connection.
    ///
    /// @param connection connection reference
    ConnectionGuard(IConnection &connection) : mConnection(connection) {
        connection.lock();
    };

    /// @brief Destructor
    ///
    /// Releases acquired connection.
    ~ConnectionGuard() { mConnection.unlock(); };

  private:
    IConnection &mConnection; ///< Connection reference
};

}; // namespace guidemyride::connection

#endif // GUIDEMYRIDE_CONNECTION_H_
