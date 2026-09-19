#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <cstdlib>
#include <string>

enum AccountStatus { ACTIVE, LOCKED, TERMINATED };

struct Account {
    int accNumber;
    std::string firstName;
    std::string lastName;
    std::string birthday;
    std::string contact;
    double savings;
    double checking;
    unsigned long pinHash;
    int status;
    int failedAttempts;

    Account(int accNum, std::string fName, std::string lName,
            std::string bday, std::string contactNum, double sav,
            double chk, unsigned long hash, int stat)
        : accNumber(accNum), firstName(fName), lastName(lName),
          birthday(bday), contact(contactNum), savings(sav), checking(chk),
          pinHash(hash), status(stat), failedAttempts(0) {}
};

struct Node {
    Account data;
    Node *next;
    Node(Account x) : data(x), next(NULL) {}
};

class AccountList {
private:
    Node * head;
public:
    AccountList() { head = NULL; }
    ~AccountList() {
        Node *p;
        while(head != NULL) { p = head; head = head->next; delete p; }
    }
    void insertAccount(Account* newAcc);
    Account* findByAccountNumber(int accNum);
    int generateAccountNumber();
};

void AccountList::insertAccount(Account* newAcc) {
    Node *p, *q, *newNode;
    p = q = head;
    newNode = new Node(*newAcc);
    while (p != NULL && p->data.accNumber < newAcc->accNumber) { q = p; p = p->next; }
    if (p == head) { head = newNode; } else { q->next = newNode; }
    newNode->next = p;
}

Account* AccountList::findByAccountNumber(int accNum) {
    Node *current = head;
    while (current != NULL && accNum != current->data.accNumber) current = current->next;
    if (current == NULL) return NULL;
    return &(current->data);
}

int AccountList::generateAccountNumber() {
    int randomAccNum;
    do { randomAccNum = 10000 + (rand() % 90000); } while (findByAccountNumber(randomAccNum) != NULL);
    return randomAccNum;
}
#endif