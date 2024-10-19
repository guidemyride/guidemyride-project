
// SPDX-License-Identifier: MIT
// Copyright (c) 2024 nyashbox

#ifndef GUIDEMYRIDE_UTILS_HASH_H_
#define GUIDEMYRIDE_UTILS_HASH_H_

#pragma once

#include <string>

namespace guidemyride::hash {

const size_t kSaltLength = 16;  ///< Salt length (bytes)
const size_t kHashLength = 32;  ///< Hash length (bytes)
const uint8_t kIterations = 3;  ///< Iterations count
const uint8_t kParallelism = 1; ///< Parallelism
const uint32_t kMemory = 65543; ///< Memory (in KB)

/// @brief Hash string with Argon2
///
/// @param str Pointer to string
/// @param salt Pointer to salt
/// @param salt_length Salt size in bytes
/// @param hash_length Hash length in bytes
/// @param iterations Number of iterations
/// @param memory Memory usage
/// @param parallelism Number of threads and compute lanes
///
/// @return Encoded hash
std::string hash(const char *str, const char *salt,
                 size_t salt_length = kSaltLength,
                 size_t hash_length = kHashLength,
                 uint8_t iterations = kIterations, uint32_t memory = kMemory,
                 uint8_t parallelism = kParallelism);

/// @brief Generate random salt
///
/// @param len Salt length
///
/// @return salt
std::string salt(const size_t len = kSaltLength);

/// @brief Verify a string against an encoded hash string
///
/// @param str Pointer to a string that should be verified
/// @param hash encoded hash with params
///
/// @return true if verification was successful
bool verify(const char *str, const char *hash);

} // namespace guidemyride::hash

#endif // GUIDEMYRIDE_UTILS_HASH_H_
