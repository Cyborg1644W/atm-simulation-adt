#include <string> 
#include <iostream>
#include <chrono> 
#include <thread>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include "transaction.h"

using namespace std; 

char ifcontinue; 

void printMainMenu(){
    head();
    printMainMenuInsertCard();
    withoutCard();
}

void printMainMenuInsertCard(){
    printMainMenu1();
    Sleep(750);
    std::system("cls");
    printMainMenu2();
    Sleep(750);
    std::system("cls");
}

void printEnterPinCode(){
    head();
    enterPinCode1();
    withCard();
}

void printTransactionMenu(){
    head();
    printTransactionMenu1(); 
    withCard();
}

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

string printMaskedInput(){ // done
    std::string pin = "";
    char ch;
    
    while ((ch = _getch()) != '\r') {
        if (ch == '\b' && !pin.empty()) {
            pin.erase(pin.length() - 1);
            std::cout << "\b \b";
        } else if (ch >= '0' && ch <= '9') {
            pin += ch;
            std::cout << '*';
        }
    }
    
    std::cout << std::endl;
    return pin;
}

void printLoadingScreen(){ // Rework
    char spinner[] = {'|', '/', '-', '\\'}; 
    
    std::cout << "Loading ";

    for (int i = 0; i < 20; ++i) {
        std::cout << spinner[i % 4] << "\b"; 
        
        std::cout.flush();
        this_thread::sleep_for(chrono::milliseconds(150));
    }

    std::cout << "Done! \n";
}

void printMainMenu1(){ // done 
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      |               .---------.               |      |" << std::endl;
    std::cout << "|  [ ] |               | [=====] |               | [ ]  |" << std::endl;
    std::cout << "|      |               '---------'               |      |" << std::endl;
    std::cout << "|  [ ] |                   /|\\                   | [ ]  |" << std::endl;
    std::cout << "|      |                    |                    |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |         PLEASE INSERT YOUR CARD         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printMainMenu2(){ // done 
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      |               .---------.               |      |" << std::endl;
    std::cout << "|  [ ] |               | [=====] |               | [ ]  |" << std::endl;
    std::cout << "|      |               '---------'               |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                   /|\\                   |      |" << std::endl;
    std::cout << "|  [ ] |                    |                    | [ ]  |" << std::endl;
    std::cout << "|      |         PLEASE INSERT YOUR CARD         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printTransactionMenu1(){ // Done!
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [1] | < BALANCE INQUIRY          CHANGE PIN > | [5]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [2] | < WITHDRAW                              | [6]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [3] | < DEPOSIT                               | [7]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [4] | < FUND TRANSFER                         | [8]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void head(){ // Done
    std::cout << "+=======================================================+" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|                     BASTION UNION                     |" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|-------------------------------------------------------|" << std::endl;
}

void withCard(){ // Done
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|  [RECEIPT]                              [CARD SLOT]   |" << std::endl;
    std::cout << "|  .-------.                              .---------.   |" << std::endl;
    std::cout << "|  |=======|                              | [=====] |   |" << std::endl;
    std::cout << "|  '-------'                              '-| _._ |-'   |" << std::endl;
    std::cout << "|                                           ||BU ||     |" << std::endl;
    std::cout << "|           [1]  [2]  [3]   [CANCEL]        '-----'     |" << std::endl;
    std::cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << std::endl;
    std::cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << std::endl;
    std::cout << "|           [*]  [0]  [#]                               |" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|               [CASH DISPENSER]                        |" << std::endl;
    std::cout << "|           .----------------------.                    |" << std::endl;
    std::cout << "|           |======================|                    |" << std::endl;
    std::cout << "|           '----------------------'                    |" << std::endl;
    std::cout << "+=======================================================+" << std::endl;
}

void withoutCard(){ // Done
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|  [RECEIPT]                              [CARD SLOT]   |" << std::endl;
    std::cout << "|  .-------.                              .---------.   |" << std::endl;
    std::cout << "|  |=======|                              | [=====] |   |" << std::endl;
    std::cout << "|  '-------'                              '---------'   |" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|           [1]  [2]  [3]   [CANCEL]                    |" << std::endl;
    std::cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << std::endl;
    std::cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << std::endl;
    std::cout << "|           [*]  [0]  [#]                               |" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|               [CASH DISPENSER]                        |" << std::endl;
    std::cout << "|           .----------------------.                    |" << std::endl;
    std::cout << "|           |======================|                    |" << std::endl;
    std::cout << "|           '----------------------'                    |" << std::endl;
    std::cout << "+=======================================================+" << std::endl;
}

void enterPinCode1(){ // Done
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |         PLEASE ENTER YOUR PIN           |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |       * * * _                           |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | < CANCEL                  PROCEED (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printBalanceInquiryMenu1(){ // done
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |             BALANCE INQUIRY             |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | < SAVINGS                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | < CURRENT                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printBalanceInquiry1(Account waw){// Done lagay account variable 
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |             BALANCE INQUIRY             |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      | Account No.: " << std::left << std::setw(25) << waw.accountNumber << "|      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      | Current Savings: " << std::left << std::setw(21) << waw.savingsBalance << "|      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      | Available: " << std::left << std::setw(27) << waw.savingsBalance << "|      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printWithdrawMenu1(){ // Done! printing withdraw choices
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |                WITHDRAW                 |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | < SAVINGS                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | < CURRENT                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printEnterAmount(){ // Done! for the user input 
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |     PLEASE ENTER THE DESIRED AMOUNT     |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |             ______________              |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printDepositMenu1(){ // done!
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |                 DEPOSIT                 |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | < SAVINGS                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | < CURRENT                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printFundTransferMenu1(){ // Done! printing withdraw choices
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |              FUND TRANSER               |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | < SAVINGS                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | < CURRENT                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printFundTransfer1(){ // done
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |              FUND TRANSFER              |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | Account Number:                         | [ ]  |" << std::endl;
    std::cout << "|      | Account Name:                           |      |" << std::endl;
    std::cout << "|  [ ] | Amount:                                 | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printChangePinCode1(){// done
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |             CHANGE PIN CODE             |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | New Pin Code:                           | [ ]  |" << std::endl;
    std::cout << "|      | New Pin Code (Confirmation):            |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printResult1(TransactionStatus status){
    std::string message; 

    switch(status){
        case TransactionStatus::SUCCESS: {message = "TRANSACTION SUCCESSFUL"; break;}; 
        case TransactionStatus::INSUFFICIENT_FUNDS: {message = "TRANSACTION FAILED: INSUFFICIENT FUNDS"; break;}; 
        case TransactionStatus::BELOW_MAINTAINING_BALANCE: {message = "TRANSACTION FAILED: INSUFFICIENT BALANCE"; break;}; 
        case TransactionStatus::INVALID_AMOUNT: {message = "TRANSACTION FAILED: INVALID AMOUNT"; break;};
        case TransactionStatus::RECIPIENT_NOT_FOUND: {message = "TRANSACTION FAILED: RECIPIENT NOT FOUND"; break;}; 
        case TransactionStatus::PIN_MISMATCH: {message = "INCORRECT PIN CODE"; break;};
        case TransactionStatus::PIN_REUSED: {message = "PIN CANNOT BE REUSED"; break;}; 
        case TransactionStatus::CANCELLED: {message = "TRANSACTION CANCELLED"; break;};
        case TransactionStatus::ACCOUNT_LOCKED: {message = "ACCOUNT IS LOCKED"; break;}; 
        case TransactionStatus::ACCOUNT_TERMINATED: {message = "ACCOUNT IS TERMINATED"; break;};
        case TransactionStatus::REGISTRATION_SUCCESS: {message = "REGISTRATION SUCCESSFUL. ATM CARD LINKED TO YOUR ACCOUNT"; break;};
        case TransactionStatus::CARD_ALREADY_LINKED: {message = "YOUR ATM CARD ALREADY HAS AN ACCOUNT"; break;};
        default: {message = "UNKNOWN TRANSACTION ERROR"; break;};
    }
    
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | " << std::left << std::setw(39) << message << " | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
}

bool askAnotherTransaction(){ 
    std::cout << "|  [ ] |           Another transaction?          | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                   YES > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                    NO > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "Would you like to have another transaction? " << std::endl; 

    while (true) {
        ifcontinue = _getch();
        if (ifcontinue == '7') {
            return true;
        } else if (ifcontinue == '8') { 
            return false; 
        }
    }
}

