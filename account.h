#include <iostream> 
#include <string> 

enum class AccountStatus{
    ACTIVE, 
    LOCKED, 
    TERMINATED
}; 

struct Account{
    string accountNumber;
    double savingsBalance;
    double currentBalance;
};
