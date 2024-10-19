#include <format>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <guidemyride/utils/hash.h>

using namespace guidemyride;

// Precomputed hash for string "test" (salt: "saltsalt")
std::string test_hash = "$argon2id$v=19$m=1024,t=1,p=1$c2FsdHNhbHQ$65qovm+"
                        "V3yS0jAXpESboyWEiNu+OWaUo9NSeZQ7hH0g";

TEST(Hash, genSalt) {
    auto regex = std::format("[a-zA-Z0-9]{{{}}}", hash::kSaltLength);
    std::string salt = hash::salt();

    EXPECT_THAT(salt, testing::MatchesRegex(regex));
}

TEST(Hash, hash) {
    const char *salt = "saltsalt";

    auto pwhash = hash::hash("test", salt, 8, hash::kHashLength, 1, 1024,
                             hash::kParallelism);

    EXPECT_EQ(pwhash, test_hash);
}

TEST(Hash, validateHash) {
    EXPECT_TRUE(hash::verify("test", test_hash.data()));
    EXPECT_FALSE(hash::verify("bad", test_hash.data()));
}
