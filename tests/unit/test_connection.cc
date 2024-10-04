#include <gtest/gtest.h>

#include <guidemyride/connections/connection.h>

#include "mock_connection.h"

TEST(Connection, connectionGuard) {
    auto connection = MockConnection();

    // Use separate scope
    {
        ConnectionGuard lock(connection);

        EXPECT_TRUE(connection.isLocked)
            << "ConnectionGuard should lock the connection";
    }

    EXPECT_FALSE(connection.isLocked)
        << "When leaving the scope, ConnectionGuard should release the "
           "connection";
}
