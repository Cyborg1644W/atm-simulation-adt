#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream> 
#include <string> 
#include "account.h"

struct BalanceInquiry {
    double savings;
    double checking;
};

enum class TransactionStatus{
    SUCCESS,
    INSUFFICIENT_FUNDS,
    BELOW_MAINTAINING_BALANCE,
    INVALID_AMOUNT,
    RECIPIENT_NOT_FOUND,
    PIN_MISMATCH,
    PIN_REUSED,
    CANCELLED,
    ACCOUNT_LOCKED,
    ACCOUNT_TERMINATED
};

BalanceInquiry getBalance(Account& acc) { //used for receipt, balance checking and etc. 
    return { acc.savings, acc.checking };
}

#endif

