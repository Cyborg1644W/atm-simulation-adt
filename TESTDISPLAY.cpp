#include <iostream>
#include <thread>
#include <chrono>
<<<<<<< Updated upstream
#include <iomanip>

using namespace std; 

void withCard(){
    cout << "+=======================================================+" << endl;
    cout << "|" << setw(56) << "|" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < WITHDRAW FUNDS        FUND TRANSFER > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < BALANCE INQUIRY           PAY BILLS > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < ACCOUNT SETTINGS        RETURN CARD > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|  [RECEIPT]                              [CARD SLOT]   |" << endl;
    cout << "|  .-------.                              .---------.   |" << endl;
    cout << "|  |=======|                              | [=====] |   |" << endl;
    cout << "|  '-------'                              '-| _._ |-'   |" << endl;
    cout << "|                                           ||BU ||     |" << endl;
    cout << "|           [1]  [2]  [3]   [CANCEL]        '-----'     |" << endl;
    cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << endl;
    cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << endl;
    cout << "|           [*]  [0]  [#]                               |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|               [CASH DISPENSER]                        |" << endl;
    cout << "|           .----------------------.                    |" << endl;
    cout << "|           |======================|                    |" << endl;
    cout << "|           '----------------------'                    |" << endl;
    cout << "+=======================================================+" << endl;
}

int main(){
    withCard();
=======
#include "display.h"

using namespace std;

int main() {
    cout << "Testing Display Functions...\n\n";

    // 1. Main Menu
    cout << "\n--- Main Menu ---\n";
    printMainMenu();

    // 2. Transaction Menu
    cout << "\n--- Transaction Menu ---\n";
    printTransactionMenu();

    // 3. Balance Inquiry Menu
    cout << "\n--- Balance Inquiry Menu ---\n";
    printBalanceInquiryMenu();

    // 4. Balance Inquiry Output
    cout << "\n--- Balance Inquiry Screen ---\n";
    Account dummyAcc;
    dummyAcc.accNumber = 12345;
    dummyAcc.savings = 5000.0;
    dummyAcc.checking = 1500.0;
    printBalanceInquiry(dummyAcc);

    // 5. Deposit Menu
    cout << "\n--- Deposit Menu ---\n";
    printDepositMenu();

    // 6. Deposit Action
    cout << "\n--- Deposit Action Screen ---\n";
    printDeposit();

    // 7. Withdraw Menu
    cout << "\n--- Withdraw Menu ---\n";
    printWithdrawMenu();

    // 8. Fund Transfer
    cout << "\n--- Fund Transfer Menu ---\n";
    printFundTransferMenu();
    cout << "\n--- Fund Transfer Form ---\n";
    printFundTransfer();

    // 9. Change PIN
    cout << "\n--- Change PIN Enter ---\n";
    printChangePinEnter();
    cout << "\n--- Change PIN Confirmation ---\n";
    printChangePinConfirmation();

    // 10. Result Screens
    cout << "\n--- Success Result ---\n";
    printResult1(TransactionStatus::SUCCESS);

    cout << "\n--- Insufficient Funds Result ---\n";
    printResult1(TransactionStatus::INSUFFICIENT_FUNDS);

>>>>>>> Stashed changes
    return 0;
}