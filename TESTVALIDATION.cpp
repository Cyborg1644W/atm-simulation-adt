
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Mock declarations to ensure standalone compilation for testing
enum class AccountType { SAVINGS, CURRENT };

struct Account {
    double savingsBalance = 1000.0;
    double currentBalance = 1000.0;
    string pinHash = "HASH_1234"; // Pre-hashed "1234"
};

const double MIN_DEPOSIT = 100.0;
const double MAINTAINING_BALANCE = 500.0;

// Mock hashing function
string hashPin(const string& pin) {
    return "HASH_" + pin;
}

// ==================== YOUR FUNCTIONS ====================

bool isValidDeposit(double amount){
    return amount >= MIN_DEPOSIT; 
}

bool hasSufficientBalance(Account& acc, double amount, AccountType type) {
    if (amount <= 0.0) {
        return false;
    }

    double current = 0.0;
    if (type == AccountType::SAVINGS) {
        current = acc.savingsBalance;
    } else {
        current = acc.currentBalance;
    }

    if ((current - amount) >= MAINTAINING_BALANCE) {
        return true;
    } else {
        return false;
    }
}

bool isValidPinFormat(const std::string& input) {
    if (input.length() != 4 && input.length() != 6){
        return false; 
    }

    for (char c : input){
        if(c < '0' || c > '9'){ 
            return false;
        }
    }
    return true; 
}

bool isPinReused(const std::string& newPin, const Account& acc) {
    string hashedInput = hashPin(newPin); 

    if(hashedInput == acc.pinHash){
        return true; 
    } else 
        return false;
}

bool isStrongPin(const std::string& pin) {
    if (pin.empty()) {
        return false;
    }

    for (char c : pin) {
        if (c != pin[0]) {
            return true;
        }
    }

    return false;
}

bool isValidName(const std::string& input) {
    if(input.empty() == true){
        return false; 
    }

    for(char c : input){
       if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ' || c == '-')) {
            return false;
        }
    }
    return true; 
}

bool isValidBirthday(const std::string& input) {
    if(input.length() != 8){
        return false; 
    }

    if(input[2] != '/' || input[5] != '/'){
        return false; 
    }

    for(int i = 0; i <= 7; i++){
        if(i == 2 || i == 5){
            continue; 
        }

        if(input[i] < '0' || input[i] > '9'){ 
            return false; 
        }
    }
    return true;
}

bool isValidContact(const std::string& input) {
    if(input.length() != 11){
        return false;
    }

    for(char c : input){
        if(c < '0' || c > '9'){ 
            return false;
        }
    }
    return true;
}

// ==================== TEST MAIN ====================

int main() {
    Account acc;

    cout << "=== 1. TESTING isValidDeposit ===" << endl;
    if (isValidDeposit(100.0))    cout << "Exact min deposit (100.0): PASS" << endl; else cout << "FAIL" << endl;
    if (isValidDeposit(500.0))    cout << "Above min deposit (500.0): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidDeposit(99.99))   cout << "Below min deposit (99.99): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidDeposit(-50.0))   cout << "Negative deposit (-50.0): PASS" << endl; else cout << "FAIL" << endl;

    cout << "\n=== 2. TESTING hasSufficientBalance ===" << endl;
    if (hasSufficientBalance(acc, 500.0, AccountType::SAVINGS))   cout << "Exact balance left (500.0): PASS" << endl; else cout << "FAIL" << endl;
    if (!hasSufficientBalance(acc, 500.01, AccountType::SAVINGS)) cout << "Breaches maintaining bal (500.01): PASS" << endl; else cout << "FAIL" << endl;
    if (!hasSufficientBalance(acc, 0.0, AccountType::SAVINGS))    cout << "Zero withdrawal (0.0): PASS" << endl; else cout << "FAIL" << endl;
    if (!hasSufficientBalance(acc, -100.0, AccountType::SAVINGS)) cout << "Negative withdrawal (-100.0): PASS" << endl; else cout << "FAIL" << endl;

    cout << "\n=== 3. TESTING isValidPinFormat ===" << endl;
    if (isValidPinFormat("1234"))    cout << "4-digit PIN: PASS" << endl; else cout << "FAIL" << endl;
    if (isValidPinFormat("123456"))  cout << "6-digit PIN: PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidPinFormat("123"))    cout << "3-digit PIN (too short): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidPinFormat("12345"))  cout << "5-digit PIN (invalid len): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidPinFormat("12a4"))   cout << "Contains letter (12a4): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidPinFormat("12 4"))   cout << "Contains space (12 4): PASS" << endl; else cout << "FAIL" << endl;

    cout << "\n=== 4. TESTING isPinReused ===" << endl;
    if (isPinReused("1234", acc))   cout << "Reused PIN (1234): PASS" << endl; else cout << "FAIL" << endl;
    if (!isPinReused("5678", acc))  cout << "New unique PIN (5678): PASS" << endl; else cout << "FAIL" << endl;

    cout << "\n=== 5. TESTING isStrongPin ===" << endl;
    if (!isStrongPin("1111")) cout << "Reject repeated '1111': PASS" << endl; 
    else                      cout << "Reject repeated '1111': FAIL (Need implementation)" << endl;
    if (isStrongPin("1234"))  cout << "Accept mixed digits '1234': PASS" << endl;
    else                      cout << "Accept mixed digits '1234': FAIL" << endl;

    cout << "\n=== 6. TESTING isValidName ===" << endl;
    if (isValidName("John Doe"))   cout << "Space separated name: PASS" << endl; else cout << "FAIL" << endl;
    if (isValidName("Mary-Jane"))  cout << "Hyphenated name: PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidName(""))          cout << "Empty string: PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidName("John123"))   cout << "Contains digits: PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidName("Jane@Doe"))  cout << "Contains symbols: PASS" << endl; else cout << "FAIL" << endl;

    cout << "\n=== 7. TESTING isValidBirthday ===" << endl;
    if (isValidBirthday("12/25/01"))  cout << "Valid format (12/25/01): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidBirthday("12-25-01")) cout << "Wrong slashes (12-25-01): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidBirthday("1/1/01"))   cout << "Too short (1/1/01): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidBirthday("12/25/2001")) cout << "Too long (12/25/2001): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidBirthday("AB/25/01")) cout << "Letters in month (AB/25/01): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidBirthday("12/25/E!")) cout << "Symbols at end (12/25/E!): PASS" << endl; else cout << "FAIL" << endl;

    cout << "\n=== 8. TESTING isValidContact ===" << endl;
    if (isValidContact("09123456789"))  cout << "Valid 11 digits: PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidContact("0912345678"))  cout << "Too short (10 digits): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidContact("091234567890")) cout << "Too long (12 digits): PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidContact("0912345678a")) cout << "Contains letter at end: PASS" << endl; else cout << "FAIL" << endl;
    if (!isValidContact("0912 456789")) cout << "Contains space: PASS" << endl; else cout << "FAIL" << endl;

    return 0;
}
