#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
#include <cctype>
#include "account.h"
#include "security.h"
#include "config.h"

bool isValidDeposit(double amount){
    return amount >= MIN_DEPOSIT; 
}

#endif