#ifndef SECURITY_H
#define SECURITY_H

#include <string>

class SecurityManager {
private:
    // 1. Encapsulated State: The secret seed is hidden from the rest of the program
    static const unsigned long HASH_SEED = 5123;

public:
    // 2. Public Interface: The rest of the system can only access these methods
    static unsigned long hashPin(const std::string &rawInput) {
        unsigned long hash = HASH_SEED;
        for(char c : rawInput) {
            hash = (hash << 3) ^ c;
        }
        return hash; 
    }

    static bool verifyPin(const std::string &rawInput, unsigned long storedHash) {
        return hashPin(rawInput) == storedHash;
    }
};

#endif