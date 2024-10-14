
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#ifndef GUIDEMYRIDE_TRANSACTION_EXCEPT_H_
#define GUIDEMYRIDE_TRANSACTION_EXCEPT_H_

#pragma once

#include <exception>

namespace guidemyride::transaction {

class TransactionException : public std::exception {};

} // namespace guidemyride::transaction

#endif // GUIDEMYRIDE_TRANSACTION_EXCEPT_H_
