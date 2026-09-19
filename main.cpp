#include <iostream>
#include "account.h"

int main() {
    AccountList accounts;

    Account demoAccount(
        accounts.generateAccountNumber(),
        "Demo",
        "User",
        "01/01/00",
        "09171234567",
        5000.0,
        0.0,
        0,
        ACTIVE
    );

    accounts.insertAccount(&demoAccount);

    Account *found = accounts.findByAccountNumber(demoAccount.accNumber);
    if (found == NULL) {
        std::cout << "Account insert failed.\n";
        return 1;
    }

    std::cout << "Created account " << found->accNumber << " for "
              << found->firstName << " " << found->lastName << ".\n";

    return 0;
}
