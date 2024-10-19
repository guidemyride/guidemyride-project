
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#include <random>

#include <argon2.h>

#include <guidemyride/utils/hash.h>

using namespace guidemyride;

std::string hash::salt(const size_t len) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "abcdefghijklmnopqrstuvwxyz"
                           "0123456789";

    const size_t charsetSize = sizeof(charset) - 2;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, charsetSize);

    std::string salt;
    salt.reserve(len);

    for (int i = 0; i < len; i++)
        salt += charset[dis(gen)];

    return salt;
}

std::string hash::hash(const char *str, const char *salt, size_t salt_length,
                       size_t hash_length, uint8_t iterations, uint32_t memory,
                       uint8_t parallelism) {

    std::string hash;
    size_t hashSize = argon2_encodedlen(iterations, memory, parallelism,
                                        strlen(salt), hash_length, Argon2_id);
    hash.resize(hashSize - 1);
    int res = argon2id_hash_encoded(iterations, memory, parallelism, str,
                                    std::strlen(str), salt, std::strlen(salt),
                                    hash_length, hash.data(), hashSize);

    if (res != ARGON2_OK)
        throw std::runtime_error(argon2_error_message(res));

    return hash;
};

bool hash::verify(const char *str, const char *hash) {
    int res = argon2id_verify(hash, str, std::strlen(str));

    return (res == ARGON2_OK);
}
