//
// Created by Quinn on 9/27/2025.
//

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(string acountNum, string HolderName, double bal)
:BankAccount(acountNum, HolderName, bal, "Savings") {
    intrestRate = 0.0;
}

void SavingsAccount::calculateIntrest() {
    this->deposit(this->intrestRate);
}
