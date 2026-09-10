#include <iostream> 
#include <string> 

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



