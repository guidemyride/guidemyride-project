
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#include <span>

#include <guidemyride/connection.h>
#include <guidemyride/connection_pool.h>

using namespace guidemyride::connection;

ConnectionPool::ConnectionPool(std::span<IConnection *> connections) {
    mConnectionsPool.reserve(connections.size());

    for (auto &connection : connections) {
        mConnectionsQueue.push(connection);
        mConnectionsPool.push_back(connection);
        connection->mConnectionPool = this;
    }
}

ConnectionPool::ConnectionPool(std::span<IConnection> connections) {
    mConnectionsPool.reserve(connections.size());

    for (auto &connection : connections) {
        mConnectionsQueue.push(&connection);
        mConnectionsPool.push_back(&connection);
        connection.mConnectionPool = this;
    }
}

IConnection *ConnectionPool::getConnection() {
    std::unique_lock<std::mutex> lock(mConnectionsPoolMutex);

    // Wait for the free connection in connection pool
    mFreeConnectionsCV.wait(lock,
                            [this]() { return !mConnectionsQueue.empty(); });

    auto connection = mConnectionsQueue.front();
    connection->lock();

    mConnectionsQueue.pop();

    return connection;
};

void ConnectionPool::addConnection(IConnection *connection) {
    std::lock_guard<std::mutex> lock(mConnectionsPoolMutex);

    // Push connection back to the queue
    mConnectionsQueue.push(connection);

    connection->unlock();
};

ConnectionPool::~ConnectionPool() {
    std::lock_guard<std::mutex> lock(mConnectionsPoolMutex);

    for (auto &connection : mConnectionsPool)
        connection->mConnectionPool = nullptr;
}
