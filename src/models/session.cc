
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#include <guidemyride/models/session.h>

using guidemyride::models::Session;

namespace guidemyride::models {

Session::Session(const uint64_t ttl) : mTTL(ttl) {};
Session::Session(const std::string &session_id, const uint64_t ttl) {};

Session Session::get(const std::string_view session_id, TransactionBase &txn) {
    throw std::logic_error("Not implemented!");
}

const std::string &Session::getSessionID(void) const { return mSessionID; }
std::string &Session::operator[](const std::string &key) { return mData[key]; }

void Session::commit(TransactionBase &txn) {
    throw std::logic_error("Not implemented");
};

} // namespace guidemyride::models
