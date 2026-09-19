#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <string>
#include "account.h"
#include "transactions.h"
#include "config.h"

#ifdef _WIN32
#include <conio.h>
#endif

using namespace std;

void printMainMenu() {
    cout << "\n===== ATM MAIN MENU =====" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;
    cout << "Choice: ";
}

void printTransactionMenu() {
    cout << "\n===== TRANSACTION MENU =====" << endl;
    cout << "1. Balance Inquiry" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Fund Transfer" << endl;
    cout << "5. Change PIN" << endl;
    cout << "6. Cancel Transaction" << endl;
    cout << "7. Logout" << endl;
    cout << "Choice: ";
}

void printLoadingScreen() {
    cout << "LOADING..." << endl;
}

// Reads a PIN character by character, printing '*' for each digit typed.
// On Windows / Dev-C++ this uses conio.h's _getch() for real masking.
// On other systems (e.g. Linux, used here for testing) it falls back to
// normal input since conio.h isn't available.
string readMaskedInput() {
#ifdef _WIN32
    string input = "";
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (!input.empty()) {
                input.pop_back();
                cout << "\b \b";
            }
        } else {
            input += ch;
            cout << '*';
        }
    }
    cout << endl;
    return input;
#else
    string input;
    cin >> input;
    return input;
#endif
}

void printResult(TransactionResult result) {
    switch (result) {
        case SUCCESS:
            cout << "TRANSACTION COMPLETED. PLEASE GET YOUR CARD." << endl;
            break;
        case INSUFFICIENT_FUNDS:
            cout << "Insufficient funds / would go below maintaining balance." << endl;
            break;
        case INVALID_AMOUNT:
            cout << "Invalid amount entered." << endl;
            break;
        case CANCELLED:
            cout << "Transaction cancelled." << endl;
            break;
        case RECIPIENT_NOT_FOUND:
            cout << "Recipient account not found." << endl;
            break;
        case PIN_MISMATCH:
            cout << "Incorrect PIN." << endl;
            break;
        case PIN_REUSED:
            cout << "New PIN cannot be the same as your old PIN." << endl;
            break;
        case PIN_DO_NOT_MATCH:
            cout << "New PIN entries do not match." << endl;
            break;
        case ACCOUNT_UNAVAILABLE:
            cout << "This account is locked or closed." << endl;
            break;
    }
}

void printBalanceInquiry(Account* acc) {
    double savings, checking;
    getBalance(acc, savings, checking);
    cout << "\nAccount No.: " << acc->accNumber << endl;
    cout << "Savings:   " << savings << endl;
    cout << "Checking:  " << checking << endl;
    cout << "Available: " << (savings - MAINTAINING_BALANCE) << endl;
}

bool askAnotherTransaction() {
    string answer;
    cout << "\nWould you like to do another transaction? (Y/N): ";
    cin >> answer;
    return (answer == "Y" || answer == "y");
}

void printCardAlreadyLinked() {
    cout << "Your ATM card already has an account." << endl;
}

void printRegistrationSuccess(Account* acc) {
    cout << "\nRegistration successful!" << endl;
    cout << "Your new account number is: " << acc->accNumber << endl;
}

#endif
