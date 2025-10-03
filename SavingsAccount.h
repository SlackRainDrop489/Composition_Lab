//
// Created by Quinn on 9/27/2025.
//

#ifndef INHERITANCE_LAB_SAVINGSACCOUNT_H
#define INHERITANCE_LAB_SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    double intrestRate;

public:
    SavingsAccount();
    void calculateIntrest();
};


#endif //INHERITANCE_LAB_SAVINGSACCOUNT_H