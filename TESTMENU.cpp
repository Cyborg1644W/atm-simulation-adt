#include "menu.h"
#include "account.h"

int main() {
    Account dummyAcc;
    dummyAcc.accNumber = 12345;
    dummyAcc.savings = 5000.0;
    dummyAcc.checking = 1500.0;
    dummyAcc.pinHash = 123456;
    dummyAcc.status = ACTIVE;

    transactionMenu(&dummyAcc);
    return 0;
}
