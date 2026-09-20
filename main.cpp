#include <iostream>
#include "account.h"
#include "persistence.h"
#include "menu.h"

int main() {
    AccountList list;
    loadAccounts(list);

    mainMenu(list);
    saveAccounts(list);
    
    return 0;
}
