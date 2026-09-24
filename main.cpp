#include "account.h"
#include "menu.h"
#include "data.h"
#include <iostream>

int main() {
  AccountList list;

  loadAccounts(list);
  mainMenu(list);
  saveAccounts(list);

  return 0;
}
