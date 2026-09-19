#include <iostream>
#include "auth.h"
using namespace std;

int main() {
    AccountList list;

    // ---------------------------------------------------
    // TEST 1: Register a valid account — should succeed
    // ---------------------------------------------------
    AuthStatus r1 = registerAccount(list, "Juan", "Dela Cruz", "01/01/00", "09171234567", 5000, "1234");
    cout << "Register valid account: " << (r1 == AuthStatus::SUCCESS ? "PASS" : "FAIL") << endl;

    // ---------------------------------------------------
    // TEST 2: Register with an invalid name — should fail
    // ---------------------------------------------------
    AuthStatus r2 = registerAccount(list, "123", "Dela Cruz", "01/01/00", "09171234567", 5000, "1234");
    cout << "Register invalid name: " << (r2 == AuthStatus::INVALID_NAME ? "PASS" : "FAIL") << endl;

    // ---------------------------------------------------
    // TEST 3: Register with a bad birthday format — should fail
    // ---------------------------------------------------
    AuthStatus r3 = registerAccount(list, "Maria", "Santos", "01-01-00", "09171234567", 5000, "1234");
    cout << "Register invalid birthday: " << (r3 == AuthStatus::INVALID_BIRTHDAY ? "PASS" : "FAIL") << endl;

    // ---------------------------------------------------
    // TEST 4: Register with a bad contact number — should fail
    // ---------------------------------------------------
    AuthStatus r4 = registerAccount(list, "Ana", "Lopez", "01/01/00", "123", 5000, "1234");
    cout << "Register invalid contact: " << (r4 == AuthStatus::INVALID_CONTACT ? "PASS" : "FAIL") << endl;

    // ---------------------------------------------------
    // TEST 5: Register with too low a deposit — should fail
    // ---------------------------------------------------
    AuthStatus r5 = registerAccount(list, "Carlo", "Cruz", "01/01/00", "09171234567", 1000, "1234");
    cout << "Register low deposit: " << (r5 == AuthStatus::INVALID_DEPOSIT ? "PASS" : "FAIL") << endl;

    // ---------------------------------------------------
    // TEST 6: Register with a bad PIN format — should fail
    // ---------------------------------------------------
    AuthStatus r6 = registerAccount(list, "Liza", "Torres", "01/01/00", "09171234567", 5000, "12");
    cout << "Register invalid pin format: " << (r6 == AuthStatus::INVALID_PIN_FORMAT ? "PASS" : "FAIL") << endl;

    // ---------------------------------------------------
    // Register a real account to test login against
    // ---------------------------------------------------
    AuthStatus r7 = registerAccount(list, "Pedro", "Reyes", "05/05/00", "09175551234", 6000, "5678");
    cout << "Register account for login test: " << (r7 == AuthStatus::SUCCESS ? "PASS" : "FAIL") << endl;

    // Find Pedro's actual generated account number so we can log in as him
    // (search a wide range since numbers are randomly generated)
    int pedroAccNum = -1;
    for (int i = 10000; i <= 99999; i++) {
        Account* found = list.findByAccountNumber(i);
        if (found != NULL && found->firstName == "Pedro") {
            pedroAccNum = i;
            break;
        }
    }   
    cout << "Found Pedro's account number: " << (pedroAccNum != -1 ? "PASS" : "FAIL") << endl;

    // ---------------------------------------------------
    // TEST 8: Login with WRONG account number — should fail
    // ---------------------------------------------------
    Account* loggedIn1 = nullptr;
    AuthStatus l1 = login(list, 99999, "5678", loggedIn1);
    cout << "Login nonexistent account: " << (l1 == AuthStatus::ACCOUNT_NOT_FOUND ? "PASS" : "FAIL") << endl;

    // ---------------------------------------------------
    // TEST 9: Login with correct account number but WRONG pin — should fail
    // ---------------------------------------------------
    Account* loggedIn2 = nullptr;
    AuthStatus l2 = login(list, pedroAccNum, "0000", loggedIn2);
    cout << "Login wrong pin: " << (l2 == AuthStatus::WRONG_PIN ? "PASS" : "FAIL") << endl;

    // ---------------------------------------------------
    // TEST 10: Login with correct account number AND correct pin — should succeed
    // ---------------------------------------------------
    Account* loggedIn3 = nullptr;
    AuthStatus l3 = login(list, pedroAccNum, "5678", loggedIn3);
    cout << "Login correct credentials: " << (l3 == AuthStatus::SUCCESS ? "PASS" : "FAIL") << endl;
    cout << "loggedInAccount is set correctly: " << (loggedIn3 != nullptr && loggedIn3->firstName == "Pedro" ? "PASS" : "FAIL") << endl;

    return 0;
}