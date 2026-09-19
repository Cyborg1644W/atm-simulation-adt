# ATM Terminal Simulation (CC 212/211L)

A C++ ATM terminal simulation implementing Abstract Data Type (ADT) Linked Lists, encrypted PIN authentication, and physical hardware validation using a USB flash drive.

## Core Architecture
* **In-Memory Database:** Utilizes a custom ADT Linked List to manage account nodes dynamically in RAM. Each node stores the Account Number, Full Name (First, Last, MI), Birthday, Contact, Savings Balance, Checking Balance, and Hashed PIN.
* **Hardware Authentication (Physical ATM Card):** Requires a removable USB Flash Drive to act as the physical ATM card. The system dynamically polls drive letters (`D:\` through `Z:\`) to detect the presence of the `pin.code` file.
* **Mathematical PIN Encryption:** Secures user PINs using a one-way mathematical hash algorithm. Raw PINs are never stored in memory or written to disk.

## System Features

### Main Menu & Registration
* **Hardware Pre-Check:** Automatically scans the inserted USB. If an account already exists on the flash drive, registration is blocked.
* **Automated Account Creation:** Generates a unique 5-digit Account Number.
* **Deposit Constraints:** Enforces a minimum initial deposit of 5,000 PHP directly into the Savings account.
* **Card Issuance:** Automatically generates the physical `pin.code` file on the inserted flash drive upon successful enrollment.

### Login & Security
* **3-Strike Lockout:** Tracks invalid PIN attempts. If the user enters an incorrect PIN 3 times, the terminal locks and terminates the session to prevent brute-force attacks.
* **Masked Keystrokes:** Custom console listener (`_getch()`) masks PIN entry with `*` and enforces 4-to-6 digit input constraints.

### Transaction Module
* **Balance Inquiry:** Displays Account Number, Current Savings Balance, and Available Balance (calculating the 500 PHP maintaining balance threshold).
* **Withdrawal (Savings, Checking, Fast Cash):** Validates sufficient funds before deduction. Prevents Savings withdrawals from dropping below the 5,000 PHP maintaining balance. Fast Cash provides rapid, pre-defined withdrawal amounts.
* **Deposit (Savings & Current):** Directs deposited funds to the user's selected account type.
* **Fund Transfer:** 
  * Validates destination account existence via Linked List traversal.
  * Displays the recipient's name for user confirmation before moving funds.
  * Requires the sender to re-enter their PIN to authorize the final transfer.
* **Change PIN:** Requires old PIN validation. Implements a double-confirmation prompt for the new PIN, updates the active Linked List node, and physically overwrites the `pin.code` file on the flash drive.

## Prerequisites
* C++17 Compiler (GCC/Clang/MSVC)
* Windows OS (Required for `<conio.h>` masked PIN input implementation)
* A removable USB Flash Drive (for card simulation)

## Compilation & Execution

1. Clone the repository to your local machine:
  ```bash
      rm -rf atm-simulation-adt
      git clone https://github.com/Cyborg1644W/atm-simulation-adt.git
      cd atm-simulation-adt
```


## File Structure
```
atm_system/
├── config.h
├── account.h
├── accountstatus.h     
├── validation.h
├── security.h
├── persistence.h
├── auth.h
├── transactions.h
├── display.h
├── menu.h
└── main.cpp```

