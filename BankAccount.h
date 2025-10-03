//
// Created by Quinn on 9/20/2025.
//

#ifndef OBJECTS_CLASSES_LAB_BANKACCOUNT_H
#define OBJECTS_CLASSES_LAB_BANKACCOUNT_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "Transaction.h"

using namespace std;


class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;
    string accountType;
    vector<Transaction> transactionHistory;

protected:
    void setAccountType(string AccountType);

public:
    BankAccount();

    BankAccount(string acountNum, string HolderName, double bal, string accType);

    string getAccountNumber();

    string getAccountHolderName();

    string getAccountType();

    double getBalance();

    void setAccountHolderName(string accountHoldName);

    double deposit(double amount);

    virtual double withdraw(double amount);

    BankAccount(const BankAccount& other);

    BankAccount& operator=(const BankAccount& other);

    virtual ~BankAccount();

    BankAccount& operator+=(double amount);

    BankAccount& operator-=(double amount);

    bool operator==(const BankAccount& other) const;

    bool operator<(const BankAccount& other) const;

    bool operator>(const BankAccount& other) const;

    static void printAccount(const BankAccount* account);

    static void printAllAccounts(const vector<unique_ptr<BankAccount>>& bankAccounts);

    static BankAccount createAccountFromInput(const vector<unique_ptr<BankAccount>>& bankAccounts);

    static BankAccount copyAccount(const BankAccount* account);

    static unique_ptr<BankAccount> accountCreator();
};


#endif //OBJECTS_CLASSES_LAB_BANKACCOUNT_H
