#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
#include <cctype>
#include "account.h"
#include "security.h"
#include "config.h"

bool isValidDeposit(double amount){
    return amount >= MIN_DEPOSIT;  // if the amount is below or above 
}

bool hasSufficientBalance(Account& acc, double amount, AccountType type) {
    if (amount <= 0.0) {// if no amount
        return false;
    }

    double current = 0.0;
    if (type == AccountType::SAVINGS) { // if savings acc or current
        current = acc.savings;
    } else {
        current = acc.checking;
    }

    if ((current - amount) >= MAINTAINING_BALANCE) { // if above or below maintaining balance
        return true;
    } else {
        return false;
    }
}

bool isValidPinFormat(const std::string& input) {
    // TODO: Implement length (4-6) and digit-only check
    if (input.length() != 4 && input.length() != 6  ){
        return false; 
    }

    for (char c : input){
        if(c < '0' ||c > '9'){ // ascii based 
            return false;
        }
    }
    return true; 
}

bool isPinReused(const std::string& newPin, const Account& acc) {
    // TODO: Hash newPin and compare it to acc.pinHash
    unsigned long hashedInput = SecurityManager::hashPin(newPin); 

    if(hashedInput == acc.pinHash){
        return true; 
    } else 
        return false;
}

bool isStrongPin(const std::string& pin) {
    // TODO: Reject pins where all digits are the same (e.g., "1111")

    return false;
}

// User Details Validations

bool isValidName(const std::string& input) {
    // TODO: Ensure name is not empty and contains only letters, spaces, or hyphens
    if(input.empty() == true){
        return false; 
    }

    for(char c : input){
       if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || c == '-')) { // ascii for letters
            return false;
        }
    }
    return true; 
}

bool isValidBirthday(const std::string& input) {
    // TODO: Ensure format is exactly MM/DD/YY with correct slashes and digits
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
    // TODO: Ensure length is exactly 11 and all characters are digits
    if(input.length() != 11){
        return false;
    }

    for(char c : input){
        if(c < '0' ||c > '9'){ // ascii based 
            return false;
        }
    }
    return true;
}
#endif  