
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#ifndef GUIDEMYRIDE_TRANSACTION_H_
#define GUIDEMYRIDE_TRANSACTION_H_

#pragma once

#include <string_view>

#include <guidemyride/transaction/params.h>
#include <guidemyride/transaction/result.h>

namespace guidemyride::transaction {

class TransactionBase {
  public:
    virtual void commit();

    virtual Result *exec(const std::string_view &stmt, Params params);

    virtual Result *exec(const std::string_view &stmt);

    virtual void rollback();

    virtual ~TransactionBase() = default;
};

} // namespace guidemyride::transaction

#endif // GUIDEMYRIDE_MODELS_TRANSACTION_H_
