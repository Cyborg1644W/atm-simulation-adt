#ifndef MENU_H
#define MENU_H

#include "auth.h"
#include "display.h"
#include "accountstatus.h"
#include "transaction.h"
#include "data.h"
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
            SLEEP_MS(2000);
        }

        // --- CARD DETECTED ---
        // Check if this card already has an account (has a valid accNumber inside)
        int cardAccNum = 0;
        bool cardHasAccount = readCardFile(cardAccNum)
                              && list.findByAccountNumber(cardAccNum) != NULL;

        if (!cardHasAccount) {
            printRegisterScreen("", "", "", "", "", -1);
            char choice = getch();
    
            if (choice == '0' || choice == 'o' || choice == 'O') {
                continue; 
            } 

            std::string firstName, lastName, birthday, contact, depositStr, pin, confirmPin;

            firstName = getRealTimeInput([&](const std::string& input){
                printRegisterScreen(input, "", "", "", "", 0);
            });
            if (firstName == "0") continue;

            lastName = getRealTimeInput([&](const std::string& input){
                printRegisterScreen(firstName, input, "", "", "", 1);
            });
            if (lastName == "0") continue;

            birthday = getRealTimeInput([&](const std::string& input){
                printRegisterScreen(firstName, lastName, input, "", "", 2);
            });
            if (birthday == "0") continue;

            contact = getRealTimeInput([&](const std::string& input){
                printRegisterScreen(firstName, lastName, birthday, input, "", 3);
            });
            if (contact == "0") continue;

            depositStr = getRealTimeInput([&](const std::string& input){
                printRegisterScreen(firstName, lastName, birthday, contact, input, 4);
            });
            if (depositStr == "0") continue;

            printPinScreen("", 5);
            pin = getRealTimeInput([&](const std::string& input){
                printPinScreen(input, 5);
            }, true); 
            if (pin == "0") continue;

            printConfirmPinScreen(pin, "", 6);
            confirmPin = getRealTimeInput([&](const std::string& input){
                printConfirmPinScreen(pin, input, 6);
            }, true); 
            if (confirmPin == "0") continue;

            if (pin != confirmPin) {
                CLEAR_SCREEN();
                head();
                std::cout << "|  PINs do not match. Registration cancelled.   |" << std::endl;
                withoutCard();
                SLEEP_MS(2000);
                continue;
            }

            double deposit = 0;
            try { deposit = std::stod(depositStr); } catch(...) {}

            AuthStatus result = registerAccount(list, firstName, lastName, birthday, contact, deposit, pin);
    
            printAuthResult(result); 

            if (result == AuthStatus::SUCCESS) {
                int newNum = 0;
                readCardFile(newNum);
        
                printRegistrationSuccess(newNum); 
                saveAccounts(list);               
            } else {
                SLEEP_MS(3000); 
            }
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
                    accountLocked();
                    withCard();
                    SLEEP_MS(3000);
                    saveAccounts(list);
                    break;
                } else {
                    // Wrong PIN
                    attempts++;
                    CLEAR_SCREEN();
                    head();
                    incorrectAttempts(attempts);
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
                if (type == '8' || type == 'o' || type == 'O' || (type != '1' && type != '2')) {
                    status = TransactionStatus::CANCELLED;
                } else {
                    AccountType accType = type == '1' ? AccountType::SAVINGS : AccountType::CHECKING;
                    printBalanceInquiry(*currentAccount, accType);
                    getch();
                    status = TransactionStatus::SUCCESS;
                }
                printResult(status, anotherTransaction);

                if (status == TransactionStatus::CANCELLED) {
                    continue; 
                }    

                break; 
            }

            case '2': {
                printWithdrawMenu(); 
                char type = getch();
                if (type == '8' || type == 'o' || type == 'O' || (type != '1' && type != '2')) {
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
                printResult(status, anotherTransaction);

                if (status == TransactionStatus::CANCELLED) {
                    continue; 
                }       

                break; 
            }

            case '3': {
                printDepositMenu(); 
                char type = getch();
                if (type == '8' || type == 'o' || type == 'O' || (type != '1' && type != '2')) {
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
                printResult(status, anotherTransaction);

                if (status == TransactionStatus::CANCELLED) {
                    continue; 
                }    

                break;
            }

            case '5': {
                printFundTransferMenu(); 
                char type = getch();
                if (type == '8' || type == 'o' || type == 'O' || (type != '1' && type != '2')) {
                    status = TransactionStatus::CANCELLED;
                } else {
                    AccountType accType = type == '1' ? AccountType::SAVINGS : AccountType::CHECKING;
                    std::string targetAcc;
                    std::string amountStr;
                    std::string pinStr;
                    
                    targetAcc = getRealTimeInput([&](const std::string& input){
                        printFundTransfer(input, "", 0);
                    });
                    
                    amountStr = getRealTimeInput([&](const std::string& input){
                        printFundTransfer(targetAcc, input, 1);
                    });
                    
                    pinStr = getRealTimeInput([&](const std::string& input){
                        printEnterPinCode(input);
                    }, true);
                    
                    int accNum = 0;
                    try { accNum = std::stoi(targetAcc); } catch(...) {}
                    
                    double amount = 0;
                    try { amount = std::stod(amountStr); } catch(...) {}
                    
                    status = transfer(*currentAccount, list, accNum, amount, pinStr, accType);
                }
                printResult(status, anotherTransaction);

                if (status == TransactionStatus::CANCELLED) {
                    continue; 
                }    

                break; 
            }

            case '6': {
                std::string oldPin;
                std::string newPin;
                std::string confirmPin;
                
                oldPin = getRealTimeInput([&](const std::string& input){
                    std::string mask(input.size(), '*');
                    printChangePinConfirmation(mask, "", "", 0);
                }, true);
                
                newPin = getRealTimeInput([&](const std::string& input){
                    std::string oldMask(oldPin.size(), '*');
                    std::string mask(input.size(), '*');
                    printChangePinConfirmation(oldMask, mask, "", 1);
                }, true);
                
                confirmPin = getRealTimeInput([&](const std::string& input){
                    std::string oldMask(oldPin.size(), '*');
                    std::string newMask(newPin.size(), '*');
                    std::string mask(input.size(), '*');
                    printChangePinConfirmation(oldMask, newMask, mask, 2);
                }, true);
                
                status = changePin(*currentAccount, oldPin, newPin, confirmPin);
                printResult(status, anotherTransaction);

                if (status == TransactionStatus::CANCELLED) {
                    continue; 
                }    

                break;
            }

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
