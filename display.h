#include <string> 
#include <iostream>
#include <chrono> 
<<<<<<< Updated upstream
=======
#include <thread>
#include <iomanip>
#include "transaction.h"
>>>>>>> Stashed changes

using namespace std; 

char ifcontinue; 

void head();
void withCard();
void withoutCard();
void printMainMenu1();
void printMainMenu2();
void enterPinCode1();
void printTransactionMenu1();
void printBalanceInquiryMenu1();
void printBalanceInquiry1(Account waw);
void printDepositMenu1();
void printEnterAmount();
void printWithdrawMenu1();
void printFundTransferMenu1();
void printFundTransfer1();
void printChangePinCode1();
void printResult1(TransactionStatus status);
bool askAnotherTransaction();
void printMainMenuInsertCard();

void printMainMenu(){

<<<<<<< Updated upstream
=======
void printMainMenuInsertCard(){
    printMainMenu1();
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::system("clear");
    printMainMenu2();
    std::this_thread::sleep_for(std::chrono::milliseconds(750));
    std::system("clear");
}

void printEnterPinCode(){
    head();
    enterPinCode1();
    withCard();
>>>>>>> Stashed changes
}

void printTransactionMenu(){
    std::cout << "[1] Balance Inquiry" << std::endl; 
    std::cout << "[2] Withdraw" << std::endl;
    std::cout << "[3] Deposit" << std::endl;
    std::cout << "[4] Fund Transfer" << std::endl;
    std::cout << "[5] Change Pin Code" << std::endl;
    std::cout << "[0] Exit" << std::endl;
}

<<<<<<< Updated upstream
void printLoadingScreen(){
=======
void printBalanceInquiryMenu(){
    head();
    printBalanceInquiryMenu1();
    withCard();
}

void printBalanceInquiry(Account acc){
    head();
    printBalanceInquiry1(acc);
    withCard();
}

void printDepositMenu(){
    head();
    printDepositMenu1();
    withCard();
}

void printDeposit(){
    head();
    printEnterAmount();
    withCard();
}

void printWithdrawMenu(){
    head();
    printWithdrawMenu1();
    withCard();
}

void printWithdraw(){
    head();
    printEnterAmount();
    withCard();
}

void printFundTransferMenu(){
    head();
    printFundTransferMenu1();
    withCard();
}

void printFundTransfer(){
    head();
    printFundTransfer1();
    withCard();
}

void printChangePinEnter(){
    head();
    printEnterPinCode();
    withCard();
}

void printChangePinConfirmation(){
    head();
    printChangePinCode1(); 
    withCard();
}

void printResult(TransactionStatus status){
    head();
    printResult1(status);
    askAnotherTransaction();
    withCard();
}

string printMaskedInput() { // simplified
    std::string pin = "";
    std::cin >> pin;
    return pin;
}

void printLoadingScreen(){ // Rework
>>>>>>> Stashed changes
    char spinner[] = {'|', '/', '-', '\\'}; 
    
    cout << "Loading ";

    for (int i = 0; i < 20; ++i) {
        cout << spinner[i % 4] << "\b"; 
        
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(150));
    }

    cout << "Done! \n";
}


void printMaskedInput(){

}

void printResult(){

}

void withCard(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
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

void withoutCard(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
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
    cout << "|  '-------'                              '---------'   |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|           [1]  [2]  [3]   [CANCEL]                    |" << endl;
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

void withPinCard(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |         PLEASE ENTER YOUR PIN           |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |       * * * _                           |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < CANCEL                  PROCEED (O) > | [ ]  |" << endl;
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

void printBalanceInquiry(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |             BALANCE INQUIRY             |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      | Account No.:                            |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      | Current Savings:                        |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      | Available:                              |      |" << endl;
    cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
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

void printWithdraw(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |                WITHDRAW                 |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < SAVINGS                               | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < CURRENT                               | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < FAST CASH                             | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
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

void printDeposit(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |                 DEPOSIT                 |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < SAVINGS                               | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < CURRENT                               | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
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

<<<<<<< Updated upstream
void printFundTransfer(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |              FUND TRANSFER              |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | Account Number:                         | [ ]  |" << endl;
    cout << "|      | Account Name:                           |      |" << endl;
    cout << "|  [ ] | Amount:                                 | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |              __________                 | [ ]  |" << endl;
    cout << "|      |               Pin Code                  |      |" << endl;
    cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
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
=======
void printBalanceInquiry1(Account waw){// Done lagay account variable 
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |             BALANCE INQUIRY             |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      | Account No.: " << std::left << std::setw(25) << waw.accNumber << "|      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      | Current Savings: " << std::left << std::setw(21) << waw.savings << "|      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      | Available: " << std::left << std::setw(27) << waw.savings << "|      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
>>>>>>> Stashed changes
}

void printChangePinCode(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |             CHANGE PIN CODE             |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | Enter Pin Code:                         | [ ]  |" << endl;
    cout << "|      | New Pin Code:                           |      |" << endl;
    cout << "|  [ ] | New Pin Code (Confirmation):            | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
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

bool askAnotherTransaction(){ 
    std::cout << "Would you like to have another transaction?" << std::endl; 
    std::cout << "[y] Yes" << std::endl;
    std::cout << "[n] No" << std::endl;
    std::cin >> ifcontinue; 

<<<<<<< Updated upstream
    if(ifcontinue == 'y'){
        return true;
    } 
    else {
        return false; 
=======
    while (true) {
        std::cin >> ifcontinue;
        if (ifcontinue == '7') {
            return true;
        } else if (ifcontinue == '8') { 
            return false; 
        } else {
            std::cout << "Invalid input. Please press 7 for YES or 8 for NO: ";
        }
>>>>>>> Stashed changes
    }
}


