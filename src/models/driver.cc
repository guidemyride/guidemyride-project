
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#include <guidemyride/models/driver.h>
#include <guidemyride/transaction/except.h>
#include <guidemyride/transaction/transaction.h>
#include <guidemyride/utils/hash.h>

using guidemyride::transaction::TransactionException;

namespace guidemyride::models {

Driver::Driver(const std::string &fullname, const std::string &password,
               const std::string &phone)
    : Driver(0, fullname, password, phone) {};

Driver::Driver(const uint32_t id, const std::string &fullname,
               const std::string &password, const std::string &phone)
    : mFullname(fullname), mPassword(password), mPhone(phone) {};

template <typename T>
Driver Driver::get(const T &value, TransactionBase &txn,
                   const std::string_view field) {

    const char *stmt =
        "SELECT id, fullname, password, phone FROM drivers WHERE ($1 = $2)";

    try {
        auto res = txn.exec(stmt, {value});
        txn.commit();

        // TODO: should be reworked when Result class is implemented
        auto id = res[0].template as<uint32_t>();
        auto fullname = res[1].template as<std::string>();
        auto password = res[2].template as<std::string>();
        auto phone = res[3].template as<std::string>();

        return Driver(id, fullname, password, phone);
    } catch (const TransactionException &e) {
        throw;
    };
}

template <typename T>
bool Driver::verifyPassword(const T &value, const std::string_view pass,
                            TransactionBase &txn,
                            const std::string_view field) {
    const char *stmt = "SELECT password FROM drivers WHERE ($1 = $2)";

    try {
        txn.exec(stmt, {field, value});
        txn.commit();
    } catch (const std::exception &e) {
        throw;
    }
}

template <typename T>
void Driver::updatePassword(const T &value, const std::string_view pass,
                            TransactionBase &txn,
                            const std::string_view field) {

    const char *stmt = "UPDATE drivers SET password=$1 WHERE $2=$3";

    try {
        txn.exec(stmt, {pass, value});
        txn.commit();
    } catch (const TransactionException &e) {
        throw;
    }
};

const std::string &Driver::getFullname(void) const { return mFullname; }

const std::string &Driver::getPhoneNumber(void) const { return mPhone; }

const std::string &Driver::getPassword(void) const { return mPassword; }

Driver::operator Session() const {
    auto session = Session();

    session["id"] = std::to_string(mId);
    session["fullname"] = mFullname;
    session["phone"] = mPhone;

    return session;
};

void Driver::init(TransactionBase &txn) {
    const char *stmt = R"(
		CREATE TABLE IF NOT EXISTS drivers (
			id SERIAL PRIMARY KEY,
			fullname VARCHAR(255) UNIQUE NOT NULL,
			password VARCHAR(128) NOT NULL,
			phone VARCHAR(20) UNIQUE NOT NULL
		);
	)";

    try {
        txn.exec(stmt);
        txn.commit();
    } catch (const TransactionException &e) {
        throw;
    };
};

void Driver::commit(TransactionBase &txn) {
    const char *insertStmt = "INSERT INTO drivers (fullname, password, "
                             "phone) VALUES ($1, $2, $3)";
    const char *updateStmt = "UPDATE drivers SET fullname=$1, password=$2, "
                             "phone=$3 WHERE id = $4";

    try {

        // Use insert statement is user id is 0
        if (!mId) {
            txn.exec(insertStmt, {mFullname, mPassword, mPhone});
        } else {
            txn.exec(updateStmt, {mFullname, mPassword, mPhone, mId});
        }

        txn.commit();
    } catch (const TransactionException &e) {
        throw;
    }
};

} // namespace guidemyride::models
