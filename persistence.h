#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include "account.h"
#include "config.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

void saveAccounts(AccountList &list) {
  std::ofstream file(ACCOUNT_FILE);
  if (!file.is_open())
    return;

  Node *current = list.getHead();
  while (current != NULL) {
    Account &a = current->data;
    file << a.accNumber << "," << a.firstName << "," << a.lastName << ","
         << a.birthday << "," << a.contact << "," << a.savings << ","
         << a.checking << "," << a.pinHash << "," << a.status << ","
         << a.failedAttempts << "\n";
    current = current->next;
  }

  file.close();
}

void loadAccounts(AccountList &list) {
  std::ifstream file(ACCOUNT_FILE);
  if (!file.is_open())
    return;

  std::string line;
  while (std::getline(file, line)) {
    if (line.empty())
      continue;

    std::stringstream ss(line);
    std::string token;

    Account a;

    std::getline(ss, token, ',');
    if (token.find_first_not_of(" \t\r\n") == std::string::npos)
      continue;

    try {
      a.accNumber = std::stoi(token);
      std::getline(ss, a.firstName, ',');
      std::getline(ss, a.lastName, ',');
      std::getline(ss, a.birthday, ',');
      std::getline(ss, a.contact, ',');
      std::getline(ss, token, ',');
      a.savings = std::stod(token);
      std::getline(ss, token, ',');
      a.checking = std::stod(token);
      std::getline(ss, token, ',');
      a.pinHash = std::stoul(token);
      std::getline(ss, token, ',');
      a.status = (AccountStatus)std::stoi(token);
      std::getline(ss, token, ',');
      a.failedAttempts = std::stoi(token);
    } catch (const std::invalid_argument &) {
      continue;
    } catch (const std::out_of_range &) {
      continue;
    }

    list.insertAccount(&a);
  }

  file.close();
}

#endif
