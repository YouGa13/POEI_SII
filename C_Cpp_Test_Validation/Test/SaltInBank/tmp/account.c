#include "Account.h"
#include <errno.h>

bool create_account(int id, double balance) {
    if ((id < 0) || (id >= MAX_ACCOUNT) || (balance < 0) || (get_account(id) != NULL)) {
            errno = EINVAL;
            return false;
    }
        else {
            Account account = { id, balance };

            listAccount[numAccounts] = account;
            numAccounts++;

            return true;
        }
}

Account* get_account(int id) {
    for (int i = 0; i < numAccounts; i++) {
        if (listAccount[i].id == id) {
            return &listAccount[i];
        }
    }
    return NULL;
}

bool withdraw(Account* account, double amount) {
    if ((account == NULL) || (account->balance <= amount)) return false;
    account->balance -= amount;
}

bool deposit(Account* account, double amount) {
    if (account == NULL) return false;
    account->balance += amount;
}
