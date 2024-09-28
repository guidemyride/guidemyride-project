
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#ifndef GUIDEMYRIDE_SESSION_H_
#define GUIDEMYRIDE_SESSION_H_

#pragma once

#include <chrono>
#include <map>

namespace guidemyride::session {

using namespace std::chrono_literals;

class Session {
  public:
    using Seconds = std::chrono::seconds;
    using Entry = std::pair<const std::string, std::string>;

    Session() = default;
    Session(std::initializer_list<Entry> entries) : mValues(entries) {};

    std::string &operator[](const char *key) { return mValues[key]; };

    void setExpire(Seconds expire) { this->mExpire = expire; };
    Seconds getExpire(void) const { return this->mExpire; };

    ~Session() = default;

  private:
    // Make session non-expiring by default
    Seconds mExpire = 0s;

    std::map<std::string, std::string> mValues;
};

} // namespace guidemyride::session

#endif // GUIDEMYRIDE_SESSION_H_
