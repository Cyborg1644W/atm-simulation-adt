#ifndef MENU_H
#define MENU_H

#include "auth.h"
#include "display.h"
#include "accountstatus.h"
#include "transaction.h"
#include "config.h" 
#include <iostream>

#include <iostream>
#include <fstream>

void transactionMenu(Account* currentAccount, AccountList& list);

void mainMenu(AccountList& list) {
    bool running = true;
    Account* currentAccount = NULL; 

    while (running) {
        printMainMenu(); 
        
        // Simulating the user pressing ENTER to insert card
        std::string dummy = getRealTimeInput([](const std::string& input){}, false);
        
        std::ifstream cardFile(USB_CARD_PATH);
        if (cardFile.good()) {
            // File exists - simulate reading account from USB and auto-login
            std::cout << "\nUSB Card detected! Reading account...\n";
            SLEEP_MS(1500);
            
            // For now, we mock the authentication since we just want to jump to the transaction menu
            // In a real scenario, we'd read the account number from the file.
            currentAccount = list.findByAccountNumber(12345); // Dummy account from test
            if (currentAccount != NULL) {
                transactionMenu(currentAccount, list);
            } else {
                std::cout << "Account from card not found in database.\n";
                SLEEP_MS(2000);
            }
        } else {
            // No file - proceed to registration
            std::cout << "\nNo card file found. Redirecting to new user registration...\n";
            SLEEP_MS(2000);
            
            // Call registration flow (stubbed for now)
            // registerAccount(...);
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