#include <string> 
#include <iostream>

using namespace std; 

char ifcontinue; 

void printMainMenu(){

}

void printTransactionMenu(){
    std::cout << "[1] Balance Inquiry" << std::endl; 
    std::cout << "[2] Withdraw" << std::endl;
    std::cout << "[3] Deposit" << std::endl;
    std::cout << "[4] Fund Transfer" << std::endl;
    std::cout << "[5] Change Pin Code" << std::endl;
    std::cout << "[0] Exit" << std::endl;
}

void printLoadingScreen(){

}


void printMaskedInput(){

}

void printResult(){

}

void withCard(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < WITHDRAW FUNDS        FUND TRANSFER > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < BALANCE INQUIRY           PAY BILLS > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < ACCOUNT SETTINGS        RETURN CARD > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|  [RECEIPT]                              [CARD SLOT]   |" << endl;
    cout << "|  .-------.                              .---------.   |" << endl;
    cout << "|  |=======|                              | [=====] |   |" << endl;
    cout << "|  '-------'                              '-| _._ |-'   |" << endl;
    cout << "|                                           ||BU ||     |" << endl;
    cout << "|           [1]  [2]  [3]   [CANCEL]        '-----'     |" << endl;
    cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << endl;
    cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << endl;
    cout << "|           [*]  [0]  [#]                               |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|               [CASH DISPENSER]                        |" << endl;
    cout << "|           .----------------------.                    |" << endl;
    cout << "|           |======================|                    |" << endl;
    cout << "|           '----------------------'                    |" << endl;
    cout << "+=======================================================+" << endl;
}

void withoutCard(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < WITHDRAW FUNDS        FUND TRANSFER > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < BALANCE INQUIRY           PAY BILLS > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < ACCOUNT SETTINGS        RETURN CARD > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|  [RECEIPT]                              [CARD SLOT]   |" << endl;
    cout << "|  .-------.                              .---------.   |" << endl;
    cout << "|  |=======|                              | [=====] |   |" << endl;
    cout << "|  '-------'                              '---------'   |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|           [1]  [2]  [3]   [CANCEL]                    |" << endl;
    cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << endl;
    cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << endl;
    cout << "|           [*]  [0]  [#]                               |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|               [CASH DISPENSER]                        |" << endl;
    cout << "|           .----------------------.                    |" << endl;
    cout << "|           |======================|                    |" << endl;
    cout << "|           '----------------------'                    |" << endl;
    cout << "+=======================================================+" << endl;
}

void withPinCard(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |         PLEASE ENTER YOUR PIN           |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |       * * * _                           |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < CANCEL                  PROCEED (O) > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|  [RECEIPT]                              [CARD SLOT]   |" << endl;
    cout << "|  .-------.                              .---------.   |" << endl;
    cout << "|  |=======|                              | [=====] |   |" << endl;
    cout << "|  '-------'                              '-| _._ |-'   |" << endl;
    cout << "|                                           ||BU ||     |" << endl;
    cout << "|           [1]  [2]  [3]   [CANCEL]        '-----'     |" << endl;
    cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << endl;
    cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << endl;
    cout << "|           [*]  [0]  [#]                               |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|               [CASH DISPENSER]                        |" << endl;
    cout << "|           .----------------------.                    |" << endl;
    cout << "|           |======================|                    |" << endl;
    cout << "|           '----------------------'                    |" << endl;
    cout << "+=======================================================+" << endl;
}

void printBalanceInquiry(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |             BALANCE INQUIRY             |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      | Account No.:                            |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      | Current Savings:                        |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      | Available:                              |      |" << endl;
    cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|  [RECEIPT]                              [CARD SLOT]   |" << endl;
    cout << "|  .-------.                              .---------.   |" << endl;
    cout << "|  |=======|                              | [=====] |   |" << endl;
    cout << "|  '-------'                              '-| _._ |-'   |" << endl;
    cout << "|                                           ||BU ||     |" << endl;
    cout << "|           [1]  [2]  [3]   [CANCEL]        '-----'     |" << endl;
    cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << endl;
    cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << endl;
    cout << "|           [*]  [0]  [#]                               |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|               [CASH DISPENSER]                        |" << endl;
    cout << "|           .----------------------.                    |" << endl;
    cout << "|           |======================|                    |" << endl;
    cout << "|           '----------------------'                    |" << endl;
    cout << "+=======================================================+" << endl;
}

void printWithdraw(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |                WITHDRAW                 |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < SAVINGS                               | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < CURRENT                               | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < FAST CASH                             | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|  [RECEIPT]                              [CARD SLOT]   |" << endl;
    cout << "|  .-------.                              .---------.   |" << endl;
    cout << "|  |=======|                              | [=====] |   |" << endl;
    cout << "|  '-------'                              '-| _._ |-'   |" << endl;
    cout << "|                                           ||BU ||     |" << endl;
    cout << "|           [1]  [2]  [3]   [CANCEL]        '-----'     |" << endl;
    cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << endl;
    cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << endl;
    cout << "|           [*]  [0]  [#]                               |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|               [CASH DISPENSER]                        |" << endl;
    cout << "|           .----------------------.                    |" << endl;
    cout << "|           |======================|                    |" << endl;
    cout << "|           '----------------------'                    |" << endl;
    cout << "+=======================================================+" << endl;
}

void printDeposit(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |                 DEPOSIT                 |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < SAVINGS                               | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | < CURRENT                               | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|  [RECEIPT]                              [CARD SLOT]   |" << endl;
    cout << "|  .-------.                              .---------.   |" << endl;
    cout << "|  |=======|                              | [=====] |   |" << endl;
    cout << "|  '-------'                              '-| _._ |-'   |" << endl;
    cout << "|                                           ||BU ||     |" << endl;
    cout << "|           [1]  [2]  [3]   [CANCEL]        '-----'     |" << endl;
    cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << endl;
    cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << endl;
    cout << "|           [*]  [0]  [#]                               |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|               [CASH DISPENSER]                        |" << endl;
    cout << "|           .----------------------.                    |" << endl;
    cout << "|           |======================|                    |" << endl;
    cout << "|           '----------------------'                    |" << endl;
    cout << "+=======================================================+" << endl;
}

void printFundTransfer(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |              FUND TRANSFER              |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | Account Number:                         | [ ]  |" << endl;
    cout << "|      | Account Name:                           |      |" << endl;
    cout << "|  [ ] | Amount:                                 | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |              __________                 | [ ]  |" << endl;
    cout << "|      |               Pin Code                  |      |" << endl;
    cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|  [RECEIPT]                              [CARD SLOT]   |" << endl;
    cout << "|  .-------.                              .---------.   |" << endl;
    cout << "|  |=======|                              | [=====] |   |" << endl;
    cout << "|  '-------'                              '-| _._ |-'   |" << endl;
    cout << "|                                           ||BU ||     |" << endl;
    cout << "|           [1]  [2]  [3]   [CANCEL]        '-----'     |" << endl;
    cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << endl;
    cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << endl;
    cout << "|           [*]  [0]  [#]                               |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|               [CASH DISPENSER]                        |" << endl;
    cout << "|           .----------------------.                    |" << endl;
    cout << "|           |======================|                    |" << endl;
    cout << "|           '----------------------'                    |" << endl;
    cout << "+=======================================================+" << endl;
}

void printChangePinCode(){
    cout << "+=======================================================+" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                     BASTION UNION                     |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|-------------------------------------------------------|" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|      |             CHANGE PIN CODE             |      |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] | Enter Pin Code:                         | [ ]  |" << endl;
    cout << "|      | New Pin Code:                           |      |" << endl;
    cout << "|  [ ] | New Pin Code (Confirmation):            | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                                         | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|  [ ] |                            CANCEL (O) > | [ ]  |" << endl;
    cout << "|      |                                         |      |" << endl;
    cout << "|      +-----------------------------------------+      |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|  [RECEIPT]                              [CARD SLOT]   |" << endl;
    cout << "|  .-------.                              .---------.   |" << endl;
    cout << "|  |=======|                              | [=====] |   |" << endl;
    cout << "|  '-------'                              '-| _._ |-'   |" << endl;
    cout << "|                                           ||BU ||     |" << endl;
    cout << "|           [1]  [2]  [3]   [CANCEL]        '-----'     |" << endl;
    cout << "|           [4]  [5]  [6]   [CLEAR ]                    |" << endl;
    cout << "|           [7]  [8]  [9]   [ENTER ]                    |" << endl;
    cout << "|           [*]  [0]  [#]                               |" << endl;
    cout << "|                                                       |" << endl;
    cout << "|               [CASH DISPENSER]                        |" << endl;
    cout << "|           .----------------------.                    |" << endl;
    cout << "|           |======================|                    |" << endl;
    cout << "|           '----------------------'                    |" << endl;
    cout << "+=======================================================+" << endl;
}

bool askAnotherTransaction(){ 
    std::cout << "Would you like to have another transaction?" << std::endl; 
    std::cout << "[y] Yes" << std::endl;
    std::cout << "[n] No" << std::endl;
    std::cin >> ifcontinue; 

    if(ifcontinue == 'y'){
        return true;
    } 
    else {
        return false; 
    }
}


