#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <guidemyride/connections/connection.h>
#include <guidemyride/connections/connection_pool.h>

#include "mock_connection.h"

using namespace guidemyride::connection;

const size_t kQueueCapacity = 4;

class ConnectionPoolFixture : public ::testing::Test {
  protected:
    void SetUp() override {
        for (auto &connection : connections)
            connection = new MockConnection();

        connectionPool = new ConnectionPool(connections);
    };

    void TearDown() override {
        for (auto &connection : connections)
            delete connection;

        if (connectionPool)
            delete connectionPool;
    };

    ConnectionPool *connectionPool;
    std::array<IConnection *, kQueueCapacity> connections;
};

TEST_F(ConnectionPoolFixture, getSize) {
    auto poolSize = connectionPool->getSize();

    EXPECT_EQ(poolSize, kQueueCapacity)
        << "Default queue size should be " << kQueueCapacity
        << "but received size is " << poolSize;
}

TEST_F(ConnectionPoolFixture, getConnection) {
    auto conn = connectionPool->getConnection();
    auto size = connectionPool->getSize();

    EXPECT_EQ(connectionPool->getSize(), kQueueCapacity - 1)
        << "After getting connection, queue size should be "
        << kQueueCapacity - 1 << " but received size is " << size;
}

TEST_F(ConnectionPoolFixture, addConnection) {
    auto conn = connectionPool->getConnection();

    connectionPool->addConnection(conn);
    auto size = connectionPool->getSize();

    EXPECT_EQ(size, kQueueCapacity)
        << "After releasing connection, queue size should be " << kQueueCapacity
        << " but received size is " << size;
}

TEST_F(ConnectionPoolFixture, Destructor) {
    delete connectionPool;
    connectionPool = nullptr;

    for (const auto &connection : connections)
        EXPECT_EQ(connection->getConnectionPool(), nullptr)
            << "After deleting ConnectionPool object, all connections' "
               "backref pointers should be nullptr";
}
