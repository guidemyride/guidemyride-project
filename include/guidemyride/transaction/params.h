
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#ifndef GUIDEMYRIDE_TRANSACTION_PARAMS_H_
#define GUIDEMYRIDE_TRANSACTION_PARAMS_H_

#pragma once

namespace guidemyride::transaction {

class Params {
  public:
    template <typename... Args>
    constexpr Params(Args &&...args){
        // TODO: add some implementation here
    };

    ~Params() = default;
};

} // namespace guidemyride::transaction

#endif // GUIDEMYRIDE_TRANSACTION_PARAMS_H_
