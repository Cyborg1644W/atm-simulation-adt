#ifndef CONFIG_H
#define CONFIG_H

#include <string>

const double MIN_DEPOSIT = 5000.0; 
const double MAINTAINING_BALANCE = 500.0; 
const int MAX_LOGIN_ATTEMPTS = 3; 
const int ACCOUNT_NUMBER_LENGTH = 5; 
const int PIN_MIN_LENGTH = 4; 
const int PIN_MAX_LENGTH = 6;
const int STARTING_ACCOUNT_NUMBER = 1000; 

const std::string CANCEL = "0"; 
const std::string ACCOUNT_FILE = "account67.csv";

// On Windows (submission): flash drive is D:\pin.code
// On Mac (testing): uses a local file in the same folder
#ifdef _WIN32
    const std::string CARD_FILE_PATH = "D:/account2.txt";
#else
    const std::string CARD_FILE_PATH = "password.md";
#endif
enum class AccountType { SAVINGS, CHECKING };

#endif