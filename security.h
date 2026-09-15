#ifndef SECURITY_H
#define SECURITY_H

#include <string>

unsigned long hashPin(const std::string &rawInput) {
    unsigned long hash = 5123;
    for(char c : rawInput) {
        hash = (hash << 3) ^ c;
    }

    return hash; 
}

bool verifyPin(const std::string &rawInput, unsigned long storedHash) {
    unsigned long comparator = hashPin(rawInput);
    
    if (comparator == storedHash){
        return true;
    }
    return false;
}

#endif