#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <cstdlib> 
#include <string>
 
struct Account {
    long accNumber;
    std::string cardId;
    std::string firstName;
    std::string lastName;
    char middleInitial;
    std::string birthday;
    std::string contact;
    double savings;
    double checking;
    unsigned long pinHash;
    int status;
};

struct Node {
    Account data;
    Node *next;
    
    // Accepts an Account object by value and copies it
    Node(Account x) : data(x), next(NULL) {} 
};

class AccountList {
private:
    Node * head;

public:
    AccountList() {
        head = NULL;
    }

    ~AccountList() {
        Node *p;
        while(head != NULL) {
            p = head;
            head = head->next;
            delete p;
        }
    }
    
    void insertAccount(Account* newAcc);
    Account* findByAccountNumber(long accNum);
    long generateAccountNumber(); // Matches name in test file
};

void AccountList::insertAccount(Account* newAcc) {
    Node *p, *q, *newNode;
    p = q = head;
    
    // Dereference newAcc (*) to pass the Account object to the Node constructor
    newNode = new Node(*newAcc);

    while (p != NULL && p->data.accNumber < newAcc->accNumber) {
        q = p;
        p = p->next;
    }

    if (p == head) {
        head = newNode;
    } else {
        q->next = newNode;
    }
    newNode->next = p;
}

Account* AccountList::findByAccountNumber(long accNum) {
    Node *current = head;

    while (current != NULL && accNum != current->data.accNumber) {
        current = current->next;
    }
    
    if (current == NULL) {
        return NULL;
    }
    return &(current->data);
}

// Matches the exact name declared in the class and test file
long AccountList::generateAccountNumber() {
    long randomAccNum;
    
    do {
        randomAccNum = 10000 + (rand() % 90000);
    } while (findByAccountNumber(randomAccNum) != NULL);

    return randomAccNum;
}

#endif