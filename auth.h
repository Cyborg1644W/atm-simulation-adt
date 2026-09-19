#ifndef AUTH_H
#define AUTH_H

#include <string>
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
    ACCOUNT_TERMINATED
};

AuthStatus registerAccount(AccountList &list,
    const std::string &firstName, const std::string &lastName, const std::string &birthday,
    const std::string &contact, double initialDeposit, const std::string &pin ) {

    if(!isValidName(firstName)) {return AuthStatus::INVALID_NAME;}
    if(!isValidName(lastName)) {return AuthStatus::INVALID_NAME;}
    if(!isValidBirthday(birthday)) {return AuthStatus::INVALID_BIRTHDAY;}
    if(!isValidContact(contact)) {return AuthStatus::INVALID_CONTACT;}
    if(!isValidDeposit(initialDeposit)) {return AuthStatus::INVALID_DEPOSIT;}
    if(!isValidPinFormat(pin)) {return AuthStatus::INVALID_PIN_FORMAT;}

    unsigned long hashedPin = SecurityManager::hashPin(pin);
    int accountNum = list.generateAccountNumber();
    Account newAcc(accountNum, firstName, lastName, birthday, contact, initialDeposit, 0, hashedPin, 0);
    list.insertAccount(&newAcc);

    return AuthStatus::SUCCESS;
}

AuthStatus login( AccountList &list, int accNumber, const std::string &pin, Account* &loggedInAccount) {
    Account *acc = list.findByAccountNumber(accNumber);
    if (acc == NULL) {
        return AuthStatus::ACCOUNT_NOT_FOUND;
    }

    if (isLocked(*acc)) {return AuthStatus::ACCOUNT_LOCKED;}
    if (isTerminated(*acc)) {return AuthStatus::ACCOUNT_TERMINATED;}

    if(!SecurityManager::verifyPin(pin, acc->pinHash)) {
        acc->failedAttempts++;
        if(acc->failedAttempts >= MAX_LOGIN_ATTEMPTS) {
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