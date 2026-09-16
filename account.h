#include <iostream> 
#include <string> 
#include "transaction.h"

enum class AccountStatus{
    ACTIVE, 
    LOCKED, 
    TERMINATED
}; 

struct Account{ //placeholder for user info
    int wow; 
    int wah; 
    
};

struct BalanceInquiry{ // for getBalance 
    double savings; //placeholder for savings and current
    double current;
};
