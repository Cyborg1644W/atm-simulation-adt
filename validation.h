#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
#include "account.h"
#include "security.h"
#include "config.h"

bool isWholeAmount(double amount) {
    return amount == static_cast<int>(amount);
}

bool isValidCashAmount(double amount) {
    return amount >= 100 && isWholeAmount(amount) && static_cast<int>(amount) % 100 == 0;
}

bool isValidInitialDeposit(double amount){
    return amount >= MIN_DEPOSIT && isValidCashAmount(amount);
}

bool isValidDeposit(double amount){
    return isValidCashAmount(amount);
}

bool hasSufficientBalance(Account& acc, double amount, AccountType type) {
    if (amount <= 0.0) {
        return false;
    }
    double current = 0.0;
    if (type == AccountType::SAVINGS) {
        current = acc.savings;
    } else {
        current = acc.checking;
    }
    if ((current - amount) >= MAINTAINING_BALANCE) {
        return true;
    } else {
        return false;
    }
}

bool isValidPinFormat(const std::string& input) {
    if (input.length() != 4 && input.length() != 6  ){
        return false; 
    }
    for (char c : input){
        if(c < '0' ||c > '9'){
            return false;
        }
    }
    return true; 
}

bool isPinReused(const std::string& newPin, const Account& acc) {
    return SecurityManager::hashPin(newPin) == acc.pinHash;
}

bool isValidName(const std::string& input) {
    if(input.empty() == true){
        return false; 
    }
    for(char c : input){
       if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || c == '-')) {
            return false;
        }
    }
    return true; 
}

bool isValidBirthday(const std::string& input) {
    if(input.length() != 8){
        return false; 
    }
    if(input[2] != '/' || input[5] != '/'){
        return false; 
    }
    for(int i = 0; i <= 7; i++){
        if(i == 2 || i == 5){
            continue; 
        }
        if(input[i] < '0' ||input[i] > '9'){ 
            return false; 
        }
    }
    return true;
}

bool isValidContact(const std::string& input) {
    if(input.length() != 11){
        return false;
    }
    for(char c : input){
        if(c < '0' ||c > '9'){
            return false;
        }
    }
    return true;
}
#endif
