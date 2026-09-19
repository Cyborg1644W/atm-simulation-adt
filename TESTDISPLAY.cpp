#include "display.h"

using namespace std;

int main() {
    Account dummyAcc;
    dummyAcc.accNumber = 12345;
    dummyAcc.savings = 5000.0;
    dummyAcc.checking = 1500.0;

    cout << "--- withoutCard (main screen, no card) ---\n";
    withoutCard();

    cout << "\n--- withCard (transaction menu) ---\n";
    withCard();

    cout << "\n--- printEnterPinCode ---\n";
    printEnterPinCode();

    cout << "\n--- printTransactionMenu ---\n";
    printTransactionMenu();

    cout << "\n--- printBalanceInquiryMenu ---\n";
    printBalanceInquiryMenu();

    cout << "\n--- printBalanceInquiry ---\n";
    printBalanceInquiry(dummyAcc);

    cout << "\n--- printWithdrawMenu ---\n";
    printWithdrawMenu();

    cout << "\n--- printDepositMenu ---\n";
    printDepositMenu();

    cout << "\n--- printFundTransferMenu ---\n";
    printFundTransferMenu();

    cout << "\n--- printFundTransfer ---\n";
    printFundTransfer();

    cout << "\n--- printChangePinEnter ---\n";
    printChangePinEnter();

    cout << "\n--- printChangePinConfirmation ---\n";
    printChangePinConfirmation();

    cout << "\n--- printResult1 ---\n";
    printResult1(TransactionStatus::SUCCESS);

    return 0;
}
