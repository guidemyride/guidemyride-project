#ifndef GUIDEMYRIDE_TESTS_MOCK_CONNECTION_H_
#define GUIDEMYRIDE_TESTS_MOCK_CONNECTION_H_

#pragma once

#include <guidemyride/connections/connection.h>

using namespace guidemyride::connection;
class MockConnection : public IConnection {
  public:
    bool isLocked = false;

    void lock() override { isLocked = true; };
    void unlock() override { isLocked = false; };
};

#endif // GUIDEMYRIDE_TESTS_MOCK_CONNECTION_H_
