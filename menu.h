#ifndef MENU_H
#define MENU_H

#include "auth.h"
#include "display.h"
#include "accountstatus.h"
#include "transaction.h"
#include "config.h" 
#include <iostream>

void transactionMenu(Account* currentAccount);

void mainMenu() {
    bool running = true;
    int choice; 
    
    Account* currentAccount = NULL; 

    while (running) {
            printMainMenu(); 

            if (AccountList::findByAccountNumber(int accNum) == NULL){
                registerAccount();
            } 

            else {
                currentAccount = authenticateUser();

                if(currentAccount != NULL){

                    transactionMenu(currentAccount);
                    
                    currentAccount = NULL; 
                } 
            } 
    }
}

void transactionMenu(Account* currentAccount) {
    if(currentAccount == NULL){ 
        std::cout << "Error: No Active Session Found" << std::endl;   
        return ; 
    }
    else if(canProceed(*currentAccount) == false){ 
        std::cout << "Access Denied. Your account is locked or terminated" << std::endl; 
        return; 
    }

    bool anotherTransaction = true;

    while (anotherTransaction) {
        char choice; 
        TransactionStatus status; 

        printTransactionMenu(); 
        std::cin >> choice; 

        switch(choice){ 
            case 1: {
                printBalanceInquiry(); 
                status = getBalance(*currentAccount);
                printResult(status);

                if (status == TransactionStatus::CANCELLED) {
                    std::cout << "Transaction cancelled. No changes were committed." << std::endl;
                    continue; 
                }    

                anotherTransaction = askAnotherTransaction();
                break; 
            }

            case 2: {
                printWithdraw(); 
                status = withdraw(*currentAccount);
                printResult(status);

                if (status == TransactionStatus::CANCELLED) {
                    std::cout << "Transaction cancelled. No changes were committed." << std::endl;
                    continue; 
                }       

                anotherTransaction = askAnotherTransaction();
                break; 
            }

            case 3: {
                printDeposit(); 
                status = deposit(*currentAccount);
                printResult(status);

                if (status == TransactionStatus::CANCELLED) {
                    std::cout << "Transaction cancelled. No changes were committed." << std::endl;
                    continue; 
                }    

                anotherTransaction = askAnotherTransaction();
                break;
            }

            case 4: {
                printFundTransfer(); 
                status = fundTransfer(*currentAccount);
                printResult(status);

                if (status == TransactionStatus::CANCELLED) {
                    std::cout << "Transaction cancelled. No changes were committed." << std::endl;
                    continue; 
                }    

                anotherTransaction = askAnotherTransaction();
                break; 
            }

            case 5: {
                printChangePinCode(); 
                status = changePinCode(*currentAccount);
                printResult(status);

                if (status == TransactionStatus::CANCELLED) {
                    std::cout << "Transaction cancelled. No changes were committed." << std::endl;
                    continue; 
                }    

                anotherTransaction = askAnotherTransaction();
                break;
            }

            case 6: {
                anotherTransaction = false; 
                break;
            }

            default: {
                std::cout << "Invalid choice" << std::endl;
                break; 
            }
        }
    }
}

#endif