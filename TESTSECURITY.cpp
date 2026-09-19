#include <iostream>
#include "security.h"

int main() {
    std::string correctPin = "1234";
    unsigned long storedHash = SecurityManager::hashPin(correctPin);

    // TODO: print the hash value so you can visually confirm it's not "1234"
    std::cout << "Stored hash: " << storedHash << std::endl;

    // TODO: test correct PIN — should print PASS
    if (SecurityManager::verifyPin("1234", storedHash)) {
        std::cout << "Correct PIN test: PASS" << std::endl;
    } else {
        std::cout << "Correct PIN test: FAIL" << std::endl;
    }

    // TODO: test wrong PIN — should print PASS (meaning it correctly rejected it)
    if (!SecurityManager::verifyPin("4321", storedHash)) {
        std::cout << "Wrong PIN test: PASS" << std::endl;
    } else {
        std::cout << "Wrong PIN test: FAIL" << std::endl;
    }

    return 0;
}

