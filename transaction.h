#include <iostream> 
#include <string> 
#include "Account.h"

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
    ACCOUNT_TERMINATED,
    REGISTRATION_SUCCESS,
    CARD_ALREADY_LINKED
};

BalanceInquiry getBalance(Account& acc) { //used for receipt, balance checking and etc. 
    return { acc.savings, acc.current };
}



