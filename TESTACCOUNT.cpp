#include <iostream>
#include <cstdlib>
#include <ctime>
#include "account.h"

int main() {
    // Seed the random number generator so account numbers are truly randomized
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "=== BASTIONUNION ACCOUNT LIST TESTER ===\n\n";

    AccountList bankList;

    // 1. Test generating random 5-digit account numbers
    long acc1Num = bankList.generateAccountNumber();
    long acc2Num = bankList.generateAccountNumber();

    std::cout << "Generated Account #1: " << acc1Num << "\n";
    std::cout << "Generated Account #2: " << acc2Num << "\n\n";

    // 2. Create and insert Mock Account 1
    Account acc1;
    acc1.accNumber = acc1Num;
    acc1.firstName = "Alice";
    acc1.lastName = "Smith";
    acc1.savings = 10000.0;
    acc1.checking = 2500.0;

    std::cout << "Inserting Alice (" << acc1.accNumber << ")...\n";
    bankList.insertAccount(&acc1);

    // 3. Create and insert Mock Account 2
    Account acc2;
    acc2.accNumber = acc2Num;
    acc2.firstName = "Bob";
    acc2.lastName = "Jones";
    acc2.savings = 7500.0;
    acc2.checking = 1200.0;

    std::cout << "Inserting Bob (" << acc2.accNumber << ")...\n";
    bankList.insertAccount(&acc2);

    std::cout << "\n----------------------------------------\n";

    // 4. Test finding an existing account
    std::cout << "Testing search for Alice's account number (" << acc1Num << ")...\n";
    Account* foundAlice = bankList.findByAccountNumber(acc1Num);
    
    if (foundAlice != NULL) {
        std::cout << "[SUCCESS] Found account! Name: " << foundAlice->firstName 
                  << " | Savings: " << foundAlice->savings << "\n";
    } else {
        std::cout << "[ERROR] Account not found!\n";
    }

    // 5. Test searching for a non-existent account
    long fakeAcc = 99999;
    std::cout << "\nTesting search for non-existent account (" << fakeAcc << ")...\n";
    Account* foundFake = bankList.findByAccountNumber(fakeAcc);
    
    if (foundFake == NULL) {
        std::cout << "[SUCCESS] Correctly returned NULL for missing account.\n";
    } else {
        std::cout << "[ERROR] Found an account that shouldn't exist!\n";
    }

    std::cout << "\n=== TEST COMPLETE ===\n";
    return 0;
}