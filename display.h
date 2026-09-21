#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <iostream>
#include <iomanip>
#include <functional>
#include "transaction.h"
#include "account.h"
#include "config.h"

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
    #define CLEAR_SCREEN() std::system("cls")
    #define SLEEP_MS(ms) Sleep(ms)
    inline int getch() { return _getch(); }
#else
    #include <chrono>
    #include <thread>
    #include <termios.h>
    #include <unistd.h>
    #define CLEAR_SCREEN() std::system("clear")
    #define SLEEP_MS(ms) std::this_thread::sleep_for(std::chrono::milliseconds(ms))
    
    // Cross-platform getch for macOS/Linux
    inline int getch() {
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
#endif

char ifcontinue;

void head();
void withCard();
void withoutCard();
void printMainMenu1();
void printMainMenu2();
void enterPinCode1(const std::string& currentPin = "");
void printTransactionMenu1();
void printBalanceInquiryMenu1();
void printBalanceInquiry1(Account waw);
void printDepositMenu1();
void printEnterAmount(const std::string& amountStr = "");
void printWithdrawMenu1();
void printFundTransferMenu1();
void printFundTransfer1(const std::string& accStr = "", const std::string& amountStr = "", int step = 0);
void printChangePinCode1(const std::string& oldPin = "", const std::string& newPin = "", const std::string& confirmPin = "", int step = 0);
void printResult1(TransactionStatus status);
bool askAnotherTransaction();
void printMainMenuInsertCard();
void printEnterPinCode(const std::string& currentPin = "");

void printMainMenu(){
    head();
    printMainMenuInsertCard();
    withoutCard();
}

void printMainMenuInsertCard(){
    printMainMenu1();
    SLEEP_MS(750);
    CLEAR_SCREEN();
    printMainMenu2();
    SLEEP_MS(750);
    CLEAR_SCREEN();
}

void printEnterPinCode(const std::string& currentPin){
    head();
    enterPinCode1(currentPin);
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

void printDeposit(const std::string& amountStr){
    head();
    printEnterAmount(amountStr);
    withCard();
}

void printWithdrawMenu(){
    head();
    printWithdrawMenu1();
    withCard();
}

void printWithdraw(const std::string& amountStr){
    head();
    printEnterAmount(amountStr);
    withCard();
}

void printFundTransferMenu(){
    head();
    printFundTransferMenu1();
    withCard();
}

void printFundTransfer(const std::string& accStr, const std::string& amountStr, int step){
    head();
    printFundTransfer1(accStr, amountStr, step);
    withCard();
}

void printChangePinEnter(){
    head();
    printEnterPinCode();
    withCard();
}

void printChangePinConfirmation(const std::string& oldPin, const std::string& newPin, const std::string& confirmPin, int step){
    head();
    printChangePinCode1(oldPin, newPin, confirmPin, step); 
    withCard();
}

void printResult(TransactionStatus status){
    head();
    printResult1(status);
    askAnotherTransaction();
    withCard();
}

// Unified Real-Time Input Loop
std::string getRealTimeInput(std::function<void(const std::string&)> drawFunction, bool masked = false) {
    std::string input = "";
    while (true) {
        CLEAR_SCREEN();
        if (masked) {
            std::string mask = "";
            for (size_t i = 0; i < input.length(); ++i) mask += "*";
            drawFunction(mask);
        } else {
            drawFunction(input);
        }
        
        int ch = getch();
        
        if (ch == '\r' || ch == '\n') {
            break;
        } else if (ch == '\b' || ch == 127) { // 127 is usually backspace/delete on mac
            if (!input.empty()) {
                input.erase(input.length() - 1);
            }
        } else if (ch >= 32 && ch <= 126) { // Printable ascii only
            input += static_cast<char>(ch);
        }
    }
    return input;
}

void printLoadingScreen(){
    char spinner[] = {'|', '/', '-', '\\'};
    std::cout << "Loading ";
    for (int i = 0; i < 20; ++i) {
        std::cout << spinner[i % 4] << "\b";
        std::cout.flush();
        SLEEP_MS(150);
    }
    std::cout << "Done! \n";
}

void printMainMenu1(){
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

void printMainMenu2(){
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

void printTransactionMenu1(){
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [1] | < BALANCE INQUIRY          CHANGE PIN > | [5]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [2] | < WITHDRAW                 LOGOUT     > | [7]  |" << std::endl; 
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [3] | < DEPOSIT                  CANCEL     > | [6]  |" << std::endl; 
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [4] | < FUND TRANSFER                         | [8]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void head(){
    CLEAR_SCREEN();
    std::cout << "+=======================================================+" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|                     BASTION UNION                     |" << std::endl;
    std::cout << "|                                                       |" << std::endl;
    std::cout << "|-------------------------------------------------------|" << std::endl;
}

void withCard(){
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

void withoutCard(){
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

void enterPinCode1(const std::string& currentPin){
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |         PLEASE ENTER YOUR PIN           |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    
    std::string line = "              " + currentPin + "_";
    while (line.length() < 39) line += " ";
    std::cout << "|      | " << line << " |      |" << std::endl;
    
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] | < CANCEL                  PROCEED (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printBalanceInquiryMenu1(){
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |             BALANCE INQUIRY             |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [1] | < SAVINGS                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [2] | < CURRENT                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printBalanceInquiry1(Account waw){
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |             BALANCE INQUIRY             |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      | Account No.: " << std::left << std::setw(25) << waw.accNumber << "|      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      | Current Savings: " << std::left << std::setw(21) << waw.savings << "|      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      | Available: " << std::left << std::setw(27) << (waw.savings - MAINTAINING_BALANCE) << "|      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printWithdrawMenu1(){
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |                WITHDRAW                 |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [1] | < SAVINGS                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [2] | < CURRENT                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printEnterAmount(const std::string& amountStr){
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |     PLEASE ENTER THE DESIRED AMOUNT     |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    
    std::string line = "             _" + amountStr + "_";
    while (line.length() < 39) line += " ";
    if (line.length() > 39) line = line.substr(0, 39);
    
    std::cout << "|      | " << line << " |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printDepositMenu1(){
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |                 DEPOSIT                 |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [1] | < SAVINGS                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [2] | < CURRENT                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printFundTransferMenu1(){
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |              FUND TRANSER               |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [1] | < SAVINGS                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [2] | < CURRENT                               | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printFundTransfer1(const std::string& accStr, const std::string& amountStr, int step){
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |              FUND TRANSFER              |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    
    std::string accLine = "Account Number: " + accStr + (step == 0 ? "_" : "");
    while(accLine.length() < 39) accLine += " ";
    std::cout << "|  [ ] | " << accLine << " | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    
    std::string amtLine = "Amount: " + amountStr + (step == 1 ? "_" : "");
    while(amtLine.length() < 39) amtLine += " ";
    std::cout << "|  [ ] | " << amtLine << " | [ ]  |" << std::endl;
    
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printChangePinCode1(const std::string& oldPin, const std::string& newPin, const std::string& confirmPin, int step){
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
    std::cout << "|      |             CHANGE PIN CODE             |      |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;

    std::string oldPinLine = "Old Pin Code: " + oldPin + (step == 0 ? "_" : "");
    while(oldPinLine.length() < 39) oldPinLine += " ";
    std::cout << "|  [ ] | " << oldPinLine << " | [ ]  |" << std::endl;
    
    std::string newPinLine = "New Pin Code: " + newPin + (step == 1 ? "_" : "");
    while(newPinLine.length() < 39) newPinLine += " ";
    std::cout << "|  [ ] | " << newPinLine << " | [ ]  |" << std::endl;
    
    std::string confirmPinLine = "New Pin Code (Confirm): " + confirmPin + (step == 2 ? "_" : "");
    while(confirmPinLine.length() < 39) confirmPinLine += " ";
    std::cout << "|      | " << confirmPinLine << " |      |" << std::endl;
    
    std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << std::endl;
    std::cout << "|      |                                         |      |" << std::endl;
    std::cout << "|      +-----------------------------------------+      |" << std::endl;
}

void printResult1(TransactionStatus status){
    std::string message;

    switch(status){
        case TransactionStatus::SUCCESS:                   { message = "TRANSACTION SUCCESSFUL"; break; }
        case TransactionStatus::FAILED:                    { message = "TRANSACTION FAILED"; break; }
        case TransactionStatus::INSUFFICIENT_FUNDS:        { message = "TRANSACTION FAILED: INSUFFICIENT FUNDS"; break; }
        case TransactionStatus::BELOW_MAINTAINING_BALANCE: { message = "TRANSACTION FAILED: INSUFFICIENT BALANCE"; break; }
        case TransactionStatus::INVALID_AMOUNT:            { message = "TRANSACTION FAILED: INVALID AMOUNT"; break; }
        case TransactionStatus::RECIPIENT_NOT_FOUND:       { message = "TRANSACTION FAILED: RECIPIENT NOT FOUND"; break; }
        case TransactionStatus::PIN_MISMATCH:              { message = "PIN DO NOT MATCH"; break; }
        case TransactionStatus::INVALID_PIN:               { message = "INCORRECT PIN"; break; }
        case TransactionStatus::INVALID_PIN_FORMAT:        { message = "INVALID PIN FORMAT"; break; }
        case TransactionStatus::PIN_REUSED:                { message = "PIN CANNOT BE REUSED"; break; }
        case TransactionStatus::CANCELLED:                 { message = "TRANSACTION CANCELLED"; break; }
        case TransactionStatus::ACCOUNT_LOCKED:            { message = "ACCOUNT IS LOCKED"; break; }
        case TransactionStatus::ACCOUNT_TERMINATED:        { message = "ACCOUNT IS TERMINATED"; break; }
        case TransactionStatus::REGISTRATION_SUCCESS:      { message = "REGISTRATION SUCCESSFUL. ATM CARD LINKED"; break; }
        case TransactionStatus::CARD_ALREADY_LINKED:       { message = "YOUR ATM CARD ALREADY HAS AN ACCOUNT"; break; }
        default:                                           { message = "UNKNOWN TRANSACTION ERROR"; break; }
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
        char ifcontinue = getch();
        if (ifcontinue == 'y' || ifcontinue == 'Y' || ifcontinue == '7') { // Added 7 as it aligns with right buttons
            return true;
        } else if (ifcontinue == 'n' || ifcontinue == 'N' || ifcontinue == '8') {
            return false;
        }
    }
}

#endif