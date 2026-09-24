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
    ACCOUNT_LOCKED,
    ACCOUNT_TERMINATED,
    CARD_ALREADY_LINKED,
    CARD_WRITE_FAILED
};

// Write accNumber and pinHash on the flash drive
bool writeCardFile(int accNumber, unsigned long pinHash) {
    std::ofstream file(CARD_FILE_PATH);
    if (!file.is_open()) return false;
    file << accNumber << "\n" << pinHash << "\n";
    file.close();
    return true;
}

// Read the account number from the card file.
bool readCardFile(int& accNumber) {
    std::ifstream file(CARD_FILE_PATH);
    if (!file.is_open()) return false;
    file >> accNumber;
    file.close();
    return true;
}

// Check if the card already has an account linked to it
bool cardIsLinked(AccountList& list) {
    int accNum = 0;
    if (!readCardFile(accNum)) return false;
    return list.findByAccountNumber(accNum) != NULL;
}

AuthStatus registerAccount(AccountList& list,
    const std::string& firstName, const std::string& lastName, const std::string& birthday,
    const std::string& contact, double initialDeposit, const std::string& pin) {

    // Check if the card already has an account
    if (cardIsLinked(list)) return AuthStatus::CARD_ALREADY_LINKED;

    if (!isValidName(firstName)) return AuthStatus::INVALID_NAME;
    if (!isValidName(lastName)) return AuthStatus::INVALID_NAME;
    if (!isValidBirthday(birthday)) return AuthStatus::INVALID_BIRTHDAY;
    if (!isValidContact(contact)) return AuthStatus::INVALID_CONTACT;
    if (!isValidInitialDeposit(initialDeposit)) return AuthStatus::INVALID_DEPOSIT;
    if (!isValidPinFormat(pin)) return AuthStatus::INVALID_PIN_FORMAT;

    unsigned long hashedPin = SecurityManager::hashPin(pin);
    int accountNum = list.generateAccountNumber();

    Account newAcc(accountNum, firstName, lastName, birthday, contact, initialDeposit, 0, hashedPin, ACTIVE);
    list.insertAccount(&newAcc);

    // write accNum and hash (card / flashdrive)
    if (!writeCardFile(accountNum, hashedPin)) return AuthStatus::CARD_WRITE_FAILED;

    return AuthStatus::SUCCESS;
}

AuthStatus login(AccountList& list, const std::string& pin, Account*& loggedInAccount) {
    // read card file
    int accNum = 0;
    if (!readCardFile(accNum)) return AuthStatus::ACCOUNT_NOT_FOUND;

    // find acc (accNum)
    Account* acc = list.findByAccountNumber(accNum);
    if (acc == NULL) return AuthStatus::ACCOUNT_NOT_FOUND;

    if (isLocked(*acc))     return AuthStatus::ACCOUNT_LOCKED;
    if (isTerminated(*acc)) return AuthStatus::ACCOUNT_TERMINATED;

    // if pass is incorrect
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
