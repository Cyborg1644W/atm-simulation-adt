#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream> 
#include <string> 
#include "account.h"
#include "config.h"
#include "validation.h"
#include "security.h"

struct BalanceInquiry {
    double savings;
    double checking;
};

enum class TransactionStatus{
    SUCCESS,
    FAILED,
    INSUFFICIENT_FUNDS,
    BELOW_MAINTAINING_BALANCE,
    INVALID_AMOUNT,
    RECIPIENT_NOT_FOUND,
    PIN_MISMATCH,
    PIN_REUSED,
    INVALID_PIN,
    INVALID_PIN_FORMAT,
    CANCELLED,
    ACCOUNT_LOCKED,
    ACCOUNT_TERMINATED,
    REGISTRATION_SUCCESS,
    CARD_ALREADY_LINKED
};

BalanceInquiry getBalance(Account& acc) { //used for receipt, balance checking and etc. 
    return { acc.savings, acc.checking };
}

inline TransactionStatus withdraw(Account& acc, double amount, AccountType type) {

    if(amount <= 0){
        return TransactionStatus::CANCELLED;
    }
    // TODO: Validate via validation.h (sufficient balance & maintaining balance)
     if(hasSufficientBalance(acc, amount, type) == false){
        return TransactionStatus::INSUFFICIENT_FUNDS;
    }
    // TODO: Mutate correct balance field based on type (Savings vs Checking)
    switch(type){
        case AccountType::SAVINGS: 
            acc.savings -= amount; 
            break; 
        case AccountType::CHECKING: 
            acc.checking -= amount; 
            break;
        default: 
            return TransactionStatus::FAILED;
    }
    
    return TransactionStatus::SUCCESS; // Change based on result
}

// 3. Deposit
inline TransactionStatus deposit(Account& acc, double amount, AccountType type) {
    // TODO: Implement cancel sentinel check
    if(amount <= 0){
        return TransactionStatus::CANCELLED;
    }

    // TODO: Validate via validation.h
    if(isValidDeposit(amount) == false){
        return TransactionStatus::INVALID_AMOUNT;
    }
    
    // TODO: Mutate savings or current balance field based on type
    switch(type){
        case AccountType::SAVINGS: 
            acc.savings += amount; 
            break; 
        case AccountType::CHECKING: 
            acc.checking += amount; 
            break;
        default: 
            return TransactionStatus::FAILED;
    }
    return TransactionStatus::SUCCESS; // Change based on result
}

// 4. Fund Transfer
inline TransactionStatus transfer(Account& senderAcc, AccountList& db, int recipientAccNum, std::string recipientName, double amount, std::string pin) {
    // TODO: Check cancel sentinel at each input step
    if (recipientAccNum == 0 || amount <= 0 || pin == "0") {
        return TransactionStatus::CANCELLED;
    }
    //TODO: Prevent transfer to own account number
    if (senderAcc.accNumber == recipientAccNum) {
        return TransactionStatus::FAILED; 
    }

    // TODO: Search recipient via account.h (return RECIPIENT_NOT_FOUND if missing)
    Account* recipient = db.findByAccountNumber(recipientAccNum);

    // TODO: Optionally verify recipient name matches
    if (recipient == NULL) {
        return TransactionStatus::RECIPIENT_NOT_FOUND;
    }
    // TODO: Verify sender PIN via security.h
    if (SecurityManager::verifyPin(pin, senderAcc.pinHash) == false) {
        return TransactionStatus::INVALID_PIN;
    }
    // TODO: Validate sender has sufficient balance
    if (hasSufficientBalance(senderAcc, amount, AccountType::SAVINGS) == false) {
        return TransactionStatus::INSUFFICIENT_FUNDS;
    }
    // TODO: Mutate both nodes' balances
    senderAcc.savings -= amount;
    recipient->savings += amount;
    
    return TransactionStatus::SUCCESS; // Change based on result
}

// 5. Change PIN
inline TransactionStatus changePin(Account& acc, std::string oldPin, std::string newPin, std::string confirmNewPin) {
    // TODO: Check cancel sentinel
    if (oldPin == "0" || newPin == "0" || confirmNewPin == "0") {
        return TransactionStatus::CANCELLED;
    }

    // TODO: Check if PIN is valid 
    if (isValidPinFormat(newPin) == false) {
        return TransactionStatus::INVALID_PIN_FORMAT;
    }
    // TODO: Verify old PIN via security.h
    if (SecurityManager::verifyPin(oldPin, acc.pinHash) == false) {
        return TransactionStatus::INVALID_PIN;
    }
    
    // TODO: Check if newPin == confirmNewPin
    if (newPin != confirmNewPin){
        return TransactionStatus::PIN_MISMATCH;
    }

    // TODO: Check isPinReused via validation.h
    if (isPinReused(newPin, acc)) {
        return TransactionStatus::PIN_REUSED;
    }
    // TODO: Hash and overwrite via security.h
    acc.pinHash = SecurityManager::hashPin(newPin);
    
    return TransactionStatus::SUCCESS; // Change based on result
}

#endif
