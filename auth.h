#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <fstream>
#include "account.h"
#include "accountstatus.h"
#include "security.h"
#include "validation.h"
#include "config.h"

enum class AuthStatus {
    SUCCESS,
    INVALID_NAME,
    INVALID_BIRTHDAY,
    INVALID_CONTACT,
    INVALID_DEPOSIT,
    INVALID_PIN_FORMAT,
    ACCOUNT_NOT_FOUND,
    WRONG_PIN,
    LOCKED_OUT,
    ACCOUNT_LOCKED,
    ACCOUNT_TERMINATED,
    CARD_ALREADY_LINKED,
    CARD_WRITE_FAILED
};

// Write accNumber and pinHash into the pin.code file on the flash drive
bool writeCardFile(int accNumber, unsigned long pinHash) {
    std::ofstream file(CARD_FILE_PATH);
    if (!file.is_open()) return false;
    file << accNumber << "\n" << pinHash << "\n";
    file.close();
    return true;
}

// Read accNumber and pinHash from the pin.code file
// Returns false if file doesn't exist or is unreadable
bool readCardFile(int& accNumber, unsigned long& pinHash) {
    std::ifstream file(CARD_FILE_PATH);
    if (!file.is_open()) return false;
    file >> accNumber >> pinHash;
    file.close();
    return true;
}

// Check if the card already has an account linked to it
bool cardIsLinked(AccountList& list) {
    int accNum = 0;
    unsigned long pinHash = 0;
    if (!readCardFile(accNum, pinHash)) return false;
    return list.findByAccountNumber(accNum) != NULL;
}

AuthStatus registerAccount(AccountList& list,
    const std::string& firstName, const std::string& lastName, const std::string& birthday,
    const std::string& contact, double initialDeposit, const std::string& pin) {

    // Check if the card already has an account
    if (cardIsLinked(list)) return AuthStatus::CARD_ALREADY_LINKED;

    if (!isValidName(firstName))        return AuthStatus::INVALID_NAME;
    if (!isValidName(lastName))         return AuthStatus::INVALID_NAME;
    if (!isValidBirthday(birthday))     return AuthStatus::INVALID_BIRTHDAY;
    if (!isValidContact(contact))       return AuthStatus::INVALID_CONTACT;
    if (!isValidDeposit(initialDeposit)) return AuthStatus::INVALID_DEPOSIT;
    if (!isValidPinFormat(pin))         return AuthStatus::INVALID_PIN_FORMAT;

    unsigned long hashedPin = SecurityManager::hashPin(pin);
    int accountNum = list.generateAccountNumber();

    Account newAcc(accountNum, firstName, lastName, birthday, contact, initialDeposit, 0, hashedPin, ACTIVE);
    list.insertAccount(&newAcc);

    // Write account number and hashed PIN to the flash drive (pin.code)
    if (!writeCardFile(accountNum, hashedPin)) return AuthStatus::CARD_WRITE_FAILED;

    return AuthStatus::SUCCESS;
}

AuthStatus login(AccountList& list, const std::string& pin, Account*& loggedInAccount) {
    // Read card file to get the account number
    int accNum = 0;
    unsigned long cardPinHash = 0;
    if (!readCardFile(accNum, cardPinHash)) return AuthStatus::ACCOUNT_NOT_FOUND;

    // Find account in list using the number from the card
    Account* acc = list.findByAccountNumber(accNum);
    if (acc == NULL) return AuthStatus::ACCOUNT_NOT_FOUND;

    if (isLocked(*acc))     return AuthStatus::ACCOUNT_LOCKED;
    if (isTerminated(*acc)) return AuthStatus::ACCOUNT_TERMINATED;

    // Verify PIN against the list's stored hash
    if (!SecurityManager::verifyPin(pin, acc->pinHash)) {
        acc->failedAttempts++;
        if (acc->failedAttempts >= MAX_LOGIN_ATTEMPTS) {
            lockAccount(*acc);
            return AuthStatus::ACCOUNT_LOCKED;
        }
        return AuthStatus::WRONG_PIN;
    }

    acc->failedAttempts = 0;
    loggedInAccount = acc;
    return AuthStatus::SUCCESS;
}

#endif