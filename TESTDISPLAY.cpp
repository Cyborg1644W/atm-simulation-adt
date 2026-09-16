#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std; 

void withCard(){
    cout << "+=======================================================+" << endl;
    cout << "|" << setw(56) << "|" << endl;
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

int main(){
    withCard();
    return 0;
}