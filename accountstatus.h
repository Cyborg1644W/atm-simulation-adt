#ifndef ACCOUNTSTATUS_H
#define ACCOUNTSTATUS_H

#include "account.h"

bool isLocked(const Account& acc){
    if(acc.status == AccountStatus::LOCKED){
        return true;
    } else {
        return false;
    }
}

bool isTerminated(const Account& acc){
    if(acc.status == AccountStatus::TERMINATED){
        return true;
    } else {
        return false;
    }
}

void lockAccount(Account& acc){
    acc.status = AccountStatus::LOCKED;
}

void terminateAccount(Account& acc){
    acc.status = AccountStatus::TERMINATED;
}

#endif