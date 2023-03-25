#include "gtest/gtest.h"
extern "C" {
    #include "../User.h"
}
User listUser[MAX_USER];
int numUsers = 0;
// Test the create_user function
TEST(UserTest, CreateUser) {
    // Test creating a user with a valid id and name
    EXPECT_TRUE(create_user(1, "Alice"));

    // Test creating a user with an existing id
    EXPECT_FALSE(create_user(1, "Bob"));

    // Test creating a user when the user list is full
    for (int i = 2; i <= MAX_USER; i++) {
        char name[50];
        sprintf(name, "User%d", i);
        EXPECT_TRUE(create_user(i, name));
    }
    EXPECT_FALSE(create_user(MAX_USER + 1, "ExtraUser"));
}

// Test the get_user function
TEST(UserTest, GetUser) {
    // Test getting an existing user
    User* user = get_user("Alice");
    EXPECT_TRUE(user != NULL);
    EXPECT_EQ(user->id, 1);

    // Test getting a non-existing user
    user = get_user("Charlie");
    EXPECT_TRUE(user == NULL);
}
