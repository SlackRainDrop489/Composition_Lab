//
// Created by Quinn on 9/27/2025.
//

#ifndef INHERITANCE_LAB_CHECKINGACCOUNT_H
#define INHERITANCE_LAB_CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
private:
    double transactionFee;

public:
    CheckingAccount(string acountNum, string HolderName, double bal);

    double withdraw(double amount) override;
};


#endif //INHERITANCE_LAB_CHECKINGACCOUNT_H