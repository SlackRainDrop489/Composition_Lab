//
// Created by Quinn on 9/27/2025.
//

#include "SavingsAccount.h"

// Constructor for SavingsAccount
SavingsAccount::SavingsAccount(string acountNum, string HolderName, double bal)
:BankAccount(acountNum, HolderName, bal, "Savings") {
    intrestRate = 0.0;
}

// CalculateIntrest method for SavingsAccount
void SavingsAccount::calculateIntrest() {
    this->deposit(this->intrestRate);
}
