
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#ifndef GUIDEMYRIDE_MODELS_DRIVER_H_
#define GUIDEMYRIDE_MODELS_DRIVER_H_

#pragma once

#include <guidemyride/models/session.h>
#include <guidemyride/transaction/transaction.h>

using guidemyride::transaction::TransactionBase;

namespace guidemyride::models {

class Driver {
  public:
    Driver(const std::string &fullname, const std::string &password,
           const std::string &phone);

    template <typename T>
    static Driver get(const T &value, TransactionBase &txn,
                      const std::string_view field);

    template <typename T>
    static bool verifyPassword(const T &value, const std::string_view pass,
                               TransactionBase &txn,
                               const std::string_view field);

    template <typename T>
    static void updatePassword(const T &value, const std::string_view pass,
                               TransactionBase &txn,
                               const std::string_view field);

    const std::string &getFullname(void) const;
    const std::string &getPhoneNumber(void) const;
    const std::string &getPassword(void) const;

    static void init(TransactionBase &txn);
    operator Session() const;
    void commit(TransactionBase &txn);

  private:
    Driver(const uint32_t id, const std::string &fullname,
           const std::string &password, const std::string &phone);

    uint32_t mId = 0;
    std::string mFullname;
    std::string mPassword;
    std::string mPhone;
};

} // namespace guidemyride::models

#endif // GUIDEMYRIDE_MODELS_DRIVER_H_
