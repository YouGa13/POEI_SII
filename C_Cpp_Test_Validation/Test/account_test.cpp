#include <stdlib.h>

#include "gtest/gtest.h"

extern "C" {
    #include "../Account.h"
}

Account listAccount[MAX_ACCOUNT];
int numAccounts;

TEST(AccountTest, create_account_id_negatif) {
    bool result = create_account(-1, 0);
    EXPECT_FALSE(result);
    EXPECT_EQ(numAccounts, 0);
    EXPECT_EQ(errno, EINVAL);
}

TEST(AccountTest, CreateAccount_id_too_large) {
    bool result = create_account(MAX_ACCOUNT, 9);
    EXPECT_FALSE(result);
    EXPECT_EQ(numAccounts, 0);
    EXPECT_EQ(errno, EINVAL);
}

TEST(AccountTest, CreateAccount_balance_negatif) {
    bool result = create_account(0, -1);
    EXPECT_FALSE(result);
    EXPECT_EQ(numAccounts, 0);
    EXPECT_EQ(errno, EPERM);
}


TEST(AccountTest, Create_Account_valid) {
    bool result = create_account(0, 150);
    EXPECT_TRUE(result);
    EXPECT_EQ(listAccount[0].id, 0);
    EXPECT_EQ(listAccount[0].balance, 150);
    EXPECT_EQ(numAccounts, 1);

    bool result2 = create_account(1, 450);
    EXPECT_TRUE(result2);
    EXPECT_EQ(listAccount[1].id, 1);
    EXPECT_EQ(listAccount[1].balance, 450);
    EXPECT_EQ(numAccounts, 2);
}

TEST(AccountTest, Get_Account_valid) {
    Account* result = get_account(1);
    ASSERT_TRUE(result != nullptr);
    EXPECT_EQ(result->id, 1);
    EXPECT_DOUBLE_EQ(result->balance, 450.0);
}

TEST(AccountTest, Get_Account_Inconnu) {
    Account* result = get_account(5);
    EXPECT_EQ(result, nullptr);
    Account* result2 = get_account(6);
    EXPECT_EQ(result2, nullptr);
}

TEST(UserTest, Create_Account_Id_Duplication) {
    bool result = create_account(1, 9);
    EXPECT_FALSE(result);
    EXPECT_EQ(numAccounts, 2);
}

TEST(UserTest, Create_Account_Not_Enough_Space) {
    for (int i = 2; i < MAX_ACCOUNT; i++) {
        bool result = create_account(i, i);
        EXPECT_EQ(numAccounts, i + 1);
        EXPECT_TRUE(result);
    }
    bool result = create_account(78, 500);
    EXPECT_FALSE(result);
    EXPECT_EQ(errno, ENOMEM);
    EXPECT_EQ(numAccounts, MAX_ACCOUNT);
}

TEST(AccountTest, Withdraw_Too_much) {
    Account* account = get_account(0);
    ASSERT_TRUE(account != nullptr);
    bool result = withdraw(account, 300);
    EXPECT_FALSE(result);
    EXPECT_EQ(errno, EPERM);
}

TEST(AccountTest, Withdraw_Normal) {
    Account* account = get_account(0);
    ASSERT_TRUE(account != nullptr);
    bool result = withdraw(account, 100);
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(account->balance, 50.0);
}


TEST(AccountTest, Deposit_Normal) {
    Account* account = get_account(0);
    ASSERT_TRUE(account != nullptr);
    bool result = deposit(account, 100);
    EXPECT_TRUE(result);
    EXPECT_DOUBLE_EQ(account->balance, 150.0);
}

TEST(AccountTest, Pointeur_null_withdraw_deposit) {
    bool result = deposit(NULL, 100);
    EXPECT_FALSE(result);
    EXPECT_EQ(errno, EINVAL);
    bool result2 = withdraw(NULL, 100);
    EXPECT_FALSE(result);
    EXPECT_EQ(errno, EINVAL);
}