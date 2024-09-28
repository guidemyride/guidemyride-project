#ifndef GUIDEMYRIDE_TESTS_MOCK_CONNECTION_H
#define GUIDEMYRIDE_TESTS_MOCK_CONNECTION_H

#pragma once

#include <guidemyride/connection.h>

using namespace guidemyride::connection;
class MockConnection : public IConnection {
  public:
    bool isLocked = false;

    void lock() override { isLocked = true; };
    void unlock() override { isLocked = false; };
};
#endif
