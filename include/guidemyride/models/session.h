
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#ifndef GUIDEMYRIDE_MODELS_SESSION_H_
#define GUIDEMYRIDE_MODELS_SESSION_H_

#pragma once

#include <map>
#include <string>

#include <guidemyride/transaction/transaction.h>
#include <guidemyride/utils/hash.h>

using guidemyride::transaction::TransactionBase;

namespace guidemyride::models {

class Session {
  public:
    Session(const uint64_t ttl = 0) : mTTL(ttl) {};

    static Session get(const std::string_view session_id,
                       TransactionBase &conn);

    const std::string &getSessionID(void) const;

    std::string &operator[](const std::string_view &key);

    void commit(TransactionBase &txn);

    ~Session() = default;

  private:
    Session(const std::string &session_id, const uint64_t ttl = 0)
        : mSessionID(session_id), mTTL(ttl) {};

    std::string mSessionID;
    std::map<std::string, std::string> mData;
    uint64_t mTTL = 0;
};

} // namespace guidemyride::models

#endif // GUIDEMYRIDE_MODELS_SESSION_H_
