#include "auth.h"
#include "display.h"
#include "session.h"
#include "accountstatus.h"
#include "transaction.h"
#include "config.h" 
#include <iostream>

void mainMenu() {
    bool running = true;

    int choice; 

    while (running) {
            printMainMenu(); 
            std::cout << "Input: " << std::endl; 
            std::cin >> choice; 

            if (choice == 1){
                registerAccount();
            } 
            else if (choice == 2){
                bool loginSuccess = login();

                if(loginSuccess == true){
                    transactionMenu();
                } 
            } 
            else if (choice == 3){
                running = false;
            }
            else{
                std::cout << "Invalid Input" << std::endl; 
            }
    }
}

void transactionMenu() {
    Account* currentAcc = getActiveAccount(); // from session.h

    if(isSessionActive() == false){ //session.h 
        std::cout << "Error: No Active Session Found" << std::endl;   
        return ; 
    }
    else if(canProceed(*currentAcc) == false){ //accountstatus.h 
        std::cout << "Access Denied. Your account is locked or terminated" << std::endl; 
        return; 
    }

    bool anotherTransaction = true;

    // TODO: Outer loop for "another transaction?"
    while (anotherTransaction) {
        int choice; 
        TransactionStatus status; 

        printTransactionMenu(); 
        std::cin >> choice; 

        switch(choice){ //placeholder for now (arguments)
            case 1: {
            printBalanceInquiry(); 
            status = getBalance(*currentAcc);
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
            status = withdraw(*currentAcc);
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
            status = deposit(*currentAcc);
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
            status = fundTransfer(*currentAcc);
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
            status = changePinCode(*currentAcc);
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

            default: 
            std::cout << "Invalid choice" << std::endl;
            break; 
        }
    }
    endSession(); //session.h
}

