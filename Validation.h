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
        current = acc.savingsBalance;
    } else {
        current = acc.currentBalance;
    }

    if ((current - amount) >= MAINTAINING_BALANCE) { // if above or below maintaining balance
        return true;
    } else {
        return false;
    }
}

bool isValidPinFormat(std::string& input) {
    // TODO: Implement length (4-6) and digit-only check

    if (input.length() < 4 ||input.length() > 6  ){}

    return false;
}

bool isValidPinFormat(const std::string& input) {
    // TODO: Implement length (4-6) and digit-only check
    return false;
}

bool isPinReused(const std::string& newPin, const Account& acc) {
    // TODO: Hash newPin and compare it to acc.pinHash
    return false;
}

bool isStrongPin(const std::string& pin) {
    // TODO: Reject pins where all digits are the same (e.g., "1111")
    return false;
}

// User Details Validations

bool isValidName(const std::string& input) {
    // TODO: Ensure name is not empty and contains only letters, spaces, or hyphens
    return false;
}

bool isValidBirthday(const std::string& input) {
    // TODO: Ensure format is exactly MM/DD/YY with correct slashes and digits
    return false;
}

bool isValidContact(const std::string& input) {
    // TODO: Ensure length is exactly 11 and all characters are digits
    return false;
}
#endif