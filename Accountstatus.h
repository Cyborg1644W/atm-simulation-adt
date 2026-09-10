#ifndef ACCOUNTSTATUS_H
#define ACCOUNTSTATUS_H

#include <iostream> 
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

bool isActive(const Account& acc){
    if(acc.status == AccountStatus::ACTIVE){
        return true;
    } else {
        return false;
    }
}

bool lockAccount(const Account& acc){
    if(acc.status == AccountStatus::LOCKED){
        return true;
    } else {
        return false;
    }
}

bool terminateAccount(const Account& acc){
    if(acc.status == AccountStatus::TERMINATED){
        return true;
    } else {
        return false;
    }
}

bool canProceed(const Account& acc){
    if(acc.status == AccountStatus::TERMINATED){
        std::cout << "Access Denied. This account has been terminated"; 
        return false;
    }

    if(acc.status == AccountStatus::LOCKED){
        std::cout << "Access Denied. This account is locked"; 
        return false; 
    }
}

#endif 