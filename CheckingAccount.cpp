//
// Created by Quinn on 9/27/2025.
//

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(string acountNum, string HolderName, double bal)
:BankAccount(acountNum, HolderName, bal, "Checking") {
    transactionFee = 0.0;
}

double CheckingAccount::withdraw(double amount) {
    double cAccountBalance = getBalance();
    double amountToWithdraw = amount + this->transactionFee;
    if (amountToWithdraw > cAccountBalance) {
        cout << "You do not have enough money in your account to withdraw that amount" << endl;
        return cAccountBalance;
    } else {
        cout << "Withdrawing $" << amountToWithdraw << " from your account" << endl;
        BankAccount::withdraw(amountToWithdraw);
    }
}
