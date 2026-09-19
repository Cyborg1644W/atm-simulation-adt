// #include <iostream>
// #include <thread>
// #include <chrono>
// #include <iomanip>

// using namespace std; 

// int space = 31; 

// struct Account{
//     double savingsBalance = 10;
//     double currentBalance;
// };


// void tinapay(){
//     cout << "+=======================================================+" << endl;
//     cout << "|                                                       |" << endl;
//     cout << "|                     BASTION UNION                     |" << endl;
//     cout << "|                                                       |" << endl;
//     cout << "|-------------------------------------------------------|" << endl;

// }

// void withCard(){
//     cout << "|                                                       |" << endl;
//     cout << "|                                                       |" << endl;
//     cout << "|  [RECEIPT]                              [CARD SLOT]   |" << endl;
//     cout << "|  .-------.                              .---------.   |" << endl;
//     cout << "|  |=======|                              | [=====] |   |" << endl;
//     cout << "|  '-------'                              '-| _._ |-'   |" << endl;
//     cout << "|                                           ||BU ||     |" << endl;
//     cout << "|           [1]  [2]  [3]   [CANCEL]        '-----'     |" << endl;
//     cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << endl;
//     cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << endl;
//     cout << "|           [*]  [0]  [#]                               |" << endl;
//     cout << "|                                                       |" << endl;
//     cout << "|               [CASH DISPENSER]                        |" << endl;
//     cout << "|           .----------------------.                    |" << endl;
//     cout << "|           |======================|                    |" << endl;
//     cout << "|           '----------------------'                    |" << endl;
//     cout << "+=======================================================+" << endl;
// }

// void printBalanceInquiry(Account waw){
//     cout << "|      +-----------------------------------------+      |" << endl;
//     cout << "|      |             BALANCE INQUIRY             |      |" << endl;
//     cout << "|      |                                         |      |" << endl;   
//     cout << "|      | Account No.: " << waw.savingsBalance << setw(33) << "|      |" << endl;
//     cout << "|  [ ] |                                         | [ ]  |" << endl;
//     cout << "|      | Current Savings: " << waw.savingsBalance << setw(29) << "|      |" << endl;
//     cout << "|  [ ] |                                         | [ ]  |" << endl;
//     cout << "|      | Available: " << waw.savingsBalance << setw(35) << "|      |" << endl;
//     cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
//     cout << "|      |                                         |      |" << endl;
//     cout << "|      +-----------------------------------------+      |" << endl;
// }



// void printBalanceInquiry(Account waw){
//     cout << "|      +-----------------------------------------+      |" << endl;
//     cout << "|      |             BALANCE INQUIRY             |      |" << endl;
//     cout << "|      |                                         |      |" << endl;
//     cout << "|  [ ] |                                         | [ ]  |" << endl;
//     cout << "|      | Account No.: " << setw(33) << "|      |" << endl;
//     cout << "|  [ ] |                                         | [ ]  |" << endl;
//     cout << "|      | Current Savings: " << waw.savingsBalance << setw(29) << "|      |" << endl;
//     cout << "|  [ ] |                                         | [ ]  |" << endl;
//     cout << "|      | Available: " << waw.savingsBalance << setw(35) << "|      |" << endl;
//     cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
//     cout << "|      |                                         |      |" << endl;
//     cout << "|      +-----------------------------------------+      |" << endl;
// }

// void testing(){
//     cout << "|      +-----------------------------------------+      |" << endl;
//     cout << "|      |                                         |      |" << endl;
//     cout << "|      |                                         |      |" << endl;   
//     cout << "|      |                                         |      |" << endl;
//     cout << "|  [ ] |                                         | [ ]  |" << endl;
//     cout << "|      |                                         |      |" << endl;
//     cout << "|  [ ] |                                         | [ ]  |" << endl;
//     cout << "|      |                                         |      |" << endl;
//     cout << "|  [ ] |                                         | [ ]  |" << endl;
//     cout << "|      |                                         |      |" << endl;
//     cout << "|      +-----------------------------------------+      |" << endl;
// }
// int main(){
//     Account woah; 
//     tinapay();
//     printBalanceInquiry(woah);
//     withCard();
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <conio.h>

// enum TransactionStatus { SUCCESS, CARD_ALREADY_LINKED };

// // 1. Masked PIN Input
// std::string printMaskedInput() {
//     std::string pin = "";
//     char ch;
//     while ((ch = _getch()) != '\r') {
//         if (ch == '\b' && pin.length() > 0) {
//             pin.erase(pin.length() - 1);
//             std::cout << "\b \b";
//         } else if (ch >= '0' && ch <= '9') {
//             pin += ch;
//             std::cout << '*';
//         }
//     }
//     std::cout << "\n";
//     return pin;
// }

// // 2. Status Output
// void printResult(TransactionStatus status) {
//     if (status == SUCCESS) {
//         std::cout << "| REGISTRATION SUCCESSFUL |\n";
//     } else if (status == CARD_ALREADY_LINKED) {
//         std::cout << "| CARD ALREADY LINKED |\n";
//     }
// }

// // 3. Registration Logic
// TransactionStatus registerAccount(bool cardExists) {
//     if (cardExists) {
//         return CARD_ALREADY_LINKED; // Fails immediately if card is found
//     }

//     std::cout << "Enter PIN: ";
//     std::string pin = printMaskedInput(); // Gets masked PIN

//     return SUCCESS;
// }

// int main() {
//     // Demo 1: New card registration
//     TransactionStatus result1 = registerAccount(false);
//     printResult(result1);

//     // Demo 2: Card already registered
//     TransactionStatus result2 = registerAccount(true);
//     printResult(result2);

//     return 0;
// }

// #include <iostream>
// #include <windows.h>

// void displayA() {
//     std::cout << "|      +-----------------------------------------+      |" << std::endl;
//     std::cout << "|      |                                         |      |" << std::endl;
//     std::cout << "|      |               .---------.               |      |" << std::endl;
//     std::cout << "|  [ ] |               | [=====] |               | [ ]  |" << std::endl;
//     std::cout << "|      |               '---------'               |      |" << std::endl;
//     std::cout << "|  [ ] |                   /|\\                   | [ ]  |" << std::endl;
//     std::cout << "|      |                    |                    |      |" << std::endl;
//     std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
//     std::cout << "|      |         PLEASE INSERT YOUR CARD         |      |" << std::endl;
//     std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
//     std::cout << "|      |                                         |      |" << std::endl;
//     std::cout << "|      +-----------------------------------------+      |" << std::endl;
// }

// void displayB() {
//     std::cout << "|      +-----------------------------------------+      |" << std::endl;
//     std::cout << "|      |                                         |      |" << std::endl;
//     std::cout << "|      |               .---------.               |      |" << std::endl;
//     std::cout << "|  [ ] |               | [=====] |               | [ ]  |" << std::endl;
//     std::cout << "|      |               '---------'               |      |" << std::endl;
//     std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
//     std::cout << "|      |                   /|\\                   |      |" << std::endl;
//     std::cout << "|  [ ] |                    |                    | [ ]  |" << std::endl;
//     std::cout << "|      |         PLEASE INSERT YOUR CARD         |      |" << std::endl;
//     std::cout << "|  [ ] |                                         | [ ]  |" << std::endl;
//     std::cout << "|      |                                         |      |" << std::endl;
//     std::cout << "|      +-----------------------------------------+      |" << std::endl;
// }

// int main() {
//     while (true) {
//         displayA(); // Prints Display A
//         Sleep(750);
//         std::system("cls");
//         displayB(); // Prints Display B
//         Sleep(750);
//         std::system("cls");
//     }

//     return 0;
// }

#include <iostream>
<<<<<<< HEAD
#include <thread>
#include <chrono>
<<<<<<< Updated upstream
=======
#include <string>
>>>>>>> main
#include <iomanip>
#include <cctype>

// ==============================================================================
// CROSS-PLATFORM OS HANDLERS
// ==============================================================================
#ifdef _WIN32
    #include <conio.h>
    inline void clearScreen() {
        system("cls");
    }
#else
    #include <termios.h>
    #include <unistd.h>
    
    inline void clearScreen() {
        system("clear");
    }

    // Custom POSIX implementation of _getch() for Linux/macOS
    inline char _getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
        
        old.c_lflag &= ~ICANON; // Disable line buffering
        old.c_lflag &= ~ECHO;   // Disable screen echoing
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        
        if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
            perror("read()");
        
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror("tcsetattr ~ICANON");
        
        return buf;
    }
#endif

using namespace std;

// ==============================================================================
// DISPLAY & INTERACTIVE INPUT LOGIC
// ==============================================================================

inline void drawBalanceInquiryBox(const string& accountNumber) {
    clearScreen(); // Cross-platform screen clear

    cout << "|      +-----------------------------------------+      |\n";
    cout << "|      |             BALANCE INQUIRY             |      |\n";
    cout << "|      |                                         |      |\n";
    cout << "|  [ ] |                                         | [ ]  |\n";
    cout << "|      | Account No.: " << left << setw(27) << accountNumber << "|      |\n";
    cout << "|  [ ] |                                         | [ ]  |\n";
    cout << "|      |                            CANCEL (O) > | [ ]  |\n";
    cout << "|      +-----------------------------------------+      |\n";
}

<<<<<<< HEAD
int main(){
    withCard();
=======
#include "display.h"

using namespace std;

int main() {
    cout << "Testing Display Functions...\n\n";

    // 1. Main Menu
    cout << "\n--- Main Menu ---\n";
    printMainMenu();

    // 2. Transaction Menu
    cout << "\n--- Transaction Menu ---\n";
    printTransactionMenu();

    // 3. Balance Inquiry Menu
    cout << "\n--- Balance Inquiry Menu ---\n";
    printBalanceInquiryMenu();

    // 4. Balance Inquiry Output
    cout << "\n--- Balance Inquiry Screen ---\n";
    Account dummyAcc;
    dummyAcc.accNumber = 12345;
    dummyAcc.savings = 5000.0;
    dummyAcc.checking = 1500.0;
    printBalanceInquiry(dummyAcc);

    // 5. Deposit Menu
    cout << "\n--- Deposit Menu ---\n";
    printDepositMenu();

    // 6. Deposit Action
    cout << "\n--- Deposit Action Screen ---\n";
    printDeposit();

    // 7. Withdraw Menu
    cout << "\n--- Withdraw Menu ---\n";
    printWithdrawMenu();

    // 8. Fund Transfer
    cout << "\n--- Fund Transfer Menu ---\n";
    printFundTransferMenu();
    cout << "\n--- Fund Transfer Form ---\n";
    printFundTransfer();

    // 9. Change PIN
    cout << "\n--- Change PIN Enter ---\n";
    printChangePinEnter();
    cout << "\n--- Change PIN Confirmation ---\n";
    printChangePinConfirmation();

    // 10. Result Screens
    cout << "\n--- Success Result ---\n";
    printResult1(TransactionStatus::SUCCESS);

    cout << "\n--- Insufficient Funds Result ---\n";
    printResult1(TransactionStatus::INSUFFICIENT_FUNDS);

>>>>>>> Stashed changes
=======
inline string getBoxInputInteractive() {
    string input = "";
    char ch;

    drawBalanceInquiryBox(input);

    while (true) {
        ch = _getch();

        // Check for Enter key across different OS newline standards ('\r' or '\n')
        if (ch == '\r' || ch == '\n') {
            break;
        } 
        // Check for Backspace key across different OS terminal standards ('\b' or ASCII 127)
        else if (ch == '\b' || ch == 127) {
            if (!input.empty()) {
                input.pop_back();
            }
        } 
        else if (input.length() < 15 && isalnum(static_cast<unsigned char>(ch))) { 
            input += ch;
        }

        drawBalanceInquiryBox(input);
    }

    return input;
}

int main() {
    string capturedAccountNo = getBoxInputInteractive();

    cout << "\n[System] Captured Account Number: " << capturedAccountNo << endl;

>>>>>>> main
    return 0;
}