#include <stdlib.h>
#include "gtest/gtest.h"

extern "C" {
#include "../Bank.h"
}

User listUser[MAX_USER];
int numUsers;
Account listAccount[MAX_ACCOUNT];
int numAccounts;

class CreateBankTest : public ::testing::TestWithParam<std::tuple<User*,
    int*, Account*, int* >> {};
TEST_P(CreateBankTest, CreateBanq_null) {
    User *userList = std::get<0>(GetParam());
    int* numUser_ptr = std::get<1>(GetParam());
    Account* accountList = std::get<2>(GetParam());
    int* numAccount_ptr = std::get<3>(GetParam());
    Bank* result = create_bank(userList, numUser_ptr, accountList, numAccount_ptr);
    EXPECT_EQ(nullptr, result);
}

INSTANTIATE_TEST_SUITE_P(
    CreateBankTests, CreateBankTest,
    ::testing::Values(
        std::make_tuple(nullptr, &numUsers, listAccount, &numAccounts),
        std::make_tuple(listUser, nullptr, listAccount, &numAccounts),
        std::make_tuple(listUser, &numUsers, nullptr, &numAccounts),
        std::make_tuple(listUser, &numUsers, listAccount, nullptr)
    )
);

TEST(BanqTest, CreateBanq_null_user) {
    Bank* result = create_bank(NULL, &numUsers, listAccount, &numAccounts);
    EXPECT_EQ(result, nullptr);
}

TEST(BanqTest, CreateBanq_null_numUsers) {
    Bank* result = create_bank(listUser, NULL, listAccount, &numAccounts);
    EXPECT_EQ(result, nullptr);
}

TEST(BanqTest, CreateBanq_null_listAccount) {
    Bank* result = create_bank(listUser, &numUsers, NULL, &numAccounts);
    EXPECT_EQ(result, nullptr);
}

TEST(BanqTest, CreateBanq_null_numAccounts) {
    Bank* result = create_bank(listUser, &numUsers, listAccount,NULL);
    EXPECT_EQ(result, nullptr);
}


TEST(BanqTest, CreateBanq_valid) {
    Bank* result = create_bank(listUser, &numUsers, listAccount, &numAccounts);
    EXPECT_TRUE(result != nullptr);
    EXPECT_EQ(result->accounts, listAccount);
    EXPECT_EQ(result->num_users, &numUsers);
    EXPECT_EQ(result->users, listUser);
    EXPECT_EQ(result->num_accounts, &numAccounts);
}
