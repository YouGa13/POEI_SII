#include <stdlib.h>

#include "gtest/gtest.h"

extern "C" {
#include "../User.h"
}
User listUser[MAX_USER];
int numUsers;

TEST(UserTest, CreateUser_id_negatif) {
    bool result = create_user(-1, "Test");
    EXPECT_FALSE(result);
    EXPECT_EQ(numUsers, 0);
    EXPECT_EQ(errno, EINVAL);
}

TEST(UserTest, CreateUser_id_too_large) {
    bool result = create_user(MAX_USER, "Test2");
    EXPECT_FALSE(result);
    EXPECT_EQ(numUsers, 0);
}

TEST(UserTest, CreateUser_name_too_small) {
    bool result = create_user(0, "\0");
    EXPECT_FALSE(result);
    EXPECT_EQ(numUsers, 0);
}

TEST(UserTest, CreateUser_name_too_large) {
    char* adresse = (char*)calloc(51, sizeof(char));
    bool result = create_user(0, adresse);
    EXPECT_FALSE(result);
    EXPECT_EQ(numUsers, 0);
}

TEST(UserTest, Create_User_valid) {
    bool result = create_user(0, "Alice\0");
    EXPECT_TRUE(result);

    EXPECT_STRCASENE(listUser[0].name, "Alice");
    EXPECT_EQ(listUser[0].id, 0);

    EXPECT_EQ(numUsers, 1);
}

TEST(UserTest, Get_User_ivalid) {
    User* result = get_user("Moussa");
    ASSERT_TRUE(result == nullptr);
    EXPECT_EQ(result, nullptr);
}

TEST(UserTest, Get_User_valid) {
    User* result = get_user("Alice");
    EXPECT_TRUE(&result);
}

