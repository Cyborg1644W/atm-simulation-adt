#include "account.h"
#include "menu.h"
#include "data.h"

int main() {
  AccountList list;

  loadAccounts(list);
  mainMenu(list);
  saveAccounts(list);

  return 0;
}
