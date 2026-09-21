#ifndef MENU_H
#define MENU_H

#include "auth.h"
#include "display.h"
#include "accountstatus.h"
#include "transaction.h"
#include "persistence.h"
#include "config.h"
#include <iostream>
#include <fstream>

void transactionMenu(Account* currentAccount, AccountList& list);

void mainMenu(AccountList& list) {
    while (true) {
        Account* currentAccount = NULL;

        // --- WAIT FOR CARD ---
        // Keep showing "Please insert card" until pin.code file is found
        while (true) {
            CLEAR_SCREEN();
            head();
            printMainMenu1();
            withoutCard();
            std::cout << "Please insert your ATM card (press ENTER to check)..." << std::endl;
            std::cin.ignore();

            std::ifstream cardFile(CARD_FILE_PATH);
            if (cardFile.good()) {
                cardFile.close();
                break;  // Card found — exit the wait loop
            }
            // No card found — loop again and show message
            CLEAR_SCREEN();
            head();
            printMainMenu2();
            withoutCard();
            std::cout << "No card detected. Please insert your ATM card." << std::endl;
            SLEEP_MS(2000);
        }

        // --- CARD DETECTED ---
        // Check if this card already has an account (has a valid accNumber inside)
        int cardAccNum = 0;
        unsigned long cardPinHash = 0;
        bool cardHasAccount = readCardFile(cardAccNum, cardPinHash)
                              && list.findByAccountNumber(cardAccNum) != NULL;

        if (!cardHasAccount) {
            // --- NEW CARD: REGISTRATION ---
            CLEAR_SCREEN();
            head();
            std::cout << "|      NEW CARD DETECTED — REGISTRATION                  |" << std::endl;
            withoutCard();

            std::string firstName, lastName, birthday, contact, pin, confirmPin;
            double deposit = 0;

            std::cout << "First Name   : "; std::cin >> firstName;   std::cin.ignore(1000, '\n');
            std::cout << "Last Name    : "; std::cin >> lastName;    std::cin.ignore(1000, '\n');
            std::cout << "Birthday (MM/DD/YY): "; std::cin >> birthday; std::cin.ignore(1000, '\n');
            std::cout << "Contact No.  : "; std::cin >> contact;    std::cin.ignore(1000, '\n');
            std::cout << "Initial Deposit (min 5000): "; std::cin >> deposit; std::cin.ignore(1000, '\n');
            std::cout << "PIN (4-6 digits): ";
            pin = getRealTimeInput([](const std::string& s){
                std::cout << "PIN (4-6 digits): " << s;
            }, true);
            std::cout << "Confirm PIN  : ";
            confirmPin = getRealTimeInput([](const std::string& s){
                std::cout << "Confirm PIN  : " << s;
            }, true);

            if (pin != confirmPin) {
                std::cout << "\nPINs do not match. Please try again." << std::endl;
                SLEEP_MS(2000);
                continue;
            }

            AuthStatus result = registerAccount(list, firstName, lastName, birthday, contact, deposit, pin);

            CLEAR_SCREEN();
            head();
            if (result == AuthStatus::SUCCESS) {
                // Find the newly created account to show the number
                int newNum = 0;
                unsigned long newHash = 0;
                readCardFile(newNum, newHash);
                std::cout << "|  Registration successful!                             |" << std::endl;
                std::cout << "|  Your Account Number: " << newNum << std::string(29, ' ') << "|" << std::endl;
                std::cout << "|  Your card (pin.code) has been written.               |" << std::endl;
                saveAccounts(list);
            } else if (result == AuthStatus::CARD_ALREADY_LINKED) {
                std::cout << "|  This card already has an account linked.             |" << std::endl;
            } else if (result == AuthStatus::INVALID_PIN_FORMAT) {
                std::cout << "|  Invalid PIN format (must be 4-6 digits).             |" << std::endl;
            } else if (result == AuthStatus::INVALID_DEPOSIT) {
                std::cout << "|  Initial deposit must be at least 5000.               |" << std::endl;
            } else {
                std::cout << "|  Registration failed. Please check your details.      |" << std::endl;
            }
            withoutCard();
            SLEEP_MS(3000);

        } else {
            // --- EXISTING CARD: LOGIN ---
            int attempts = 0;
            bool loggedIn = false;

            while (attempts < MAX_LOGIN_ATTEMPTS && !loggedIn) {
                std::string pin = getRealTimeInput([&](const std::string& input){
                    CLEAR_SCREEN();
                    printEnterPinCode(input);
                }, true);

                if (pin == CANCEL) break;

                AuthStatus result = login(list, pin, currentAccount);

                if (result == AuthStatus::SUCCESS) {
                    loggedIn = true;
                } else if (result == AuthStatus::ACCOUNT_LOCKED) {
                    CLEAR_SCREEN();
                    head();
                    std::cout << "|  Account locked after too many failed attempts.       |" << std::endl;
                    withCard();
                    SLEEP_MS(3000);
                    saveAccounts(list);
                    break;
                } else {
                    // Wrong PIN
                    attempts++;
                    CLEAR_SCREEN();
                    head();
                    std::cout << "|  Incorrect PIN. Attempts left: "
                              << (MAX_LOGIN_ATTEMPTS - attempts)
                              << std::string(20, ' ') << "|" << std::endl;
                    withCard();
                    SLEEP_MS(2000);
                }
            }

            if (loggedIn && currentAccount != NULL) {
                transactionMenu(currentAccount, list);
                saveAccounts(list);  // Save after every session
            }
        }
    }
}

void transactionMenu(Account* currentAccount, AccountList& list) {
    if(currentAccount == NULL){ 
        std::cout << "Error: No Active Session Found" << std::endl;   
        return ; 
    }
    else if(isLocked(*currentAccount) || isTerminated(*currentAccount)){ 
        std::cout << "Access Denied. Your account is locked or terminated" << std::endl; 
        return; 
    }

    bool anotherTransaction = true;

    while (anotherTransaction) {
        TransactionStatus status; 

        printTransactionMenu(); 
        char choice = getch(); 

        switch(choice){ 
            case '1': {
                printBalanceInquiryMenu(); 
                char type = getch();
                if (type == '0' || type == 'o' || type == 'O') {
                    status = TransactionStatus::CANCELLED;
                } else {
                    printBalanceInquiry(*currentAccount);
                    SLEEP_MS(2000);
                    status = TransactionStatus::SUCCESS;
                }
                printResult(status);

                if (status == TransactionStatus::CANCELLED) {
                    continue; 
                }    

                anotherTransaction = askAnotherTransaction();
                break; 
            }

            case '2': {
                printWithdrawMenu(); 
                char type = getch();
                if (type == '0' || type == 'o' || type == 'O') {
                    status = TransactionStatus::CANCELLED;
                } else {
                    AccountType accType = (type == '1') ? AccountType::SAVINGS : AccountType::CHECKING;
                    std::string amountStr = getRealTimeInput([](const std::string& input){
                        printWithdraw(input);
                    });
                    
                    double amount = 0;
                    try { amount = std::stod(amountStr); } catch(...) {}
                    
                    status = withdraw(*currentAccount, amount, accType);
                }
                printResult(status);

                if (status == TransactionStatus::CANCELLED) {
                    continue; 
                }       

                anotherTransaction = askAnotherTransaction();
                break; 
            }

            case '3': {
                printDepositMenu(); 
                char type = getch();
                if (type == '0' || type == 'o' || type == 'O') {
                    status = TransactionStatus::CANCELLED;
                } else {
                    AccountType accType = (type == '1') ? AccountType::SAVINGS : AccountType::CHECKING;
                    std::string amountStr = getRealTimeInput([](const std::string& input){
                        printDeposit(input);
                    });
                    
                    double amount = 0;
                    try { amount = std::stod(amountStr); } catch(...) {}
                    
                    status = deposit(*currentAccount, amount, accType);
                }
                printResult(status);

                if (status == TransactionStatus::CANCELLED) {
                    continue; 
                }    

                anotherTransaction = askAnotherTransaction();
                break;
            }

            case '4': {
                printFundTransferMenu(); 
                char type = getch();
                if (type == '0' || type == 'o' || type == 'O') {
                    status = TransactionStatus::CANCELLED;
                } else {
                    std::string targetAcc;
                    std::string amountStr;
                    
                    targetAcc = getRealTimeInput([&](const std::string& input){
                        printFundTransfer(input, "", 0);
                    });
                    
                    amountStr = getRealTimeInput([&](const std::string& input){
                        printFundTransfer(targetAcc, input, 1);
                    });
                    
                    int accNum = 0;
                    try { accNum = std::stoi(targetAcc); } catch(...) {}
                    
                    double amount = 0;
                    try { amount = std::stod(amountStr); } catch(...) {}
                    
                    status = transfer(*currentAccount, list, accNum, "", amount, std::to_string(currentAccount->pinHash));
                }
                printResult(status);

                if (status == TransactionStatus::CANCELLED) {
                    continue; 
                }    

                anotherTransaction = askAnotherTransaction();
                break; 
            }

            case '5': {
                std::string oldPin;
                std::string newPin;
                std::string confirmPin;
                
                oldPin = getRealTimeInput([&](const std::string& input){
                    printChangePinConfirmation(input, "", "", 0);
                }, true);
                
                newPin = getRealTimeInput([&](const std::string& input){
                    printChangePinConfirmation(oldPin, input, "", 1);
                }, true);
                
                confirmPin = getRealTimeInput([&](const std::string& input){
                    printChangePinConfirmation(oldPin, newPin, input, 2);
                }, true);
                
                status = changePin(*currentAccount, oldPin, newPin, confirmPin);
                printResult(status);

                if (status == TransactionStatus::CANCELLED) {
                    continue; 
                }    

                anotherTransaction = askAnotherTransaction();
                break;
            }

            case '6': 
            case '7': {
                anotherTransaction = false; 
                break;
            }

            default: {
                break; 
            }
        }
    }
}

#endif