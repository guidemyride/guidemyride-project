#include <gtest/gtest.h>

#include <guidemyride/session.h>

using namespace std::chrono_literals;

class SessionFixture : public ::testing::Test {
  protected:
    void SetUp() override {};

    guidemyride::session::Session session;
};

TEST_F(SessionFixture, setExpire) {
    auto ttl = 5min;

    this->session.setExpire(ttl);

    EXPECT_EQ(this->session.getExpire(), ttl)
        << "Session TTL should be " << ttl;
}

TEST_F(SessionFixture, getExpire) {
    auto expire = this->session.getExpire();

    EXPECT_EQ(expire, 0s) << "Default expiration time should be 0 seconds!";
}

TEST_F(SessionFixture, bracesOperator) {
    this->session["key"] = "value";

    EXPECT_EQ(this->session["key"], "value")
        << "Session entry \"key\" should store \"value\"";

    std::string &value_ref = this->session["ref"];
    value_ref = "value";

    EXPECT_EQ(value_ref, this->session["ref"]);
}

TEST(Session, ConstructorInitializerList) {
    auto session =
        guidemyride::session::Session({{"key1", "value1"}, {"key2", "value2"}});

    EXPECT_EQ(session["key1"], "value1")
        << "Session entry \"key1\" should store \"value2\"";
    EXPECT_EQ(session["key2"], "value2")
        << "Session entry \"key2\" should store \"value1\"";
}
