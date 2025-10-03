//
// Created by Quinn on 9/20/2025.
//

#include "BankAccount.h"
#include "InputValidator.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "pipelineprinting.h"
#include <iostream>
#include <limits>
#include <memory>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <random>

using FormattedTable = std::vector<std::vector<std::string>>;

string BankAccount::getAccountNumber() {
    // This will return the account number
    return accountNumber;
}

string BankAccount::getAccountHolderName() {
    // This will return the bank account holder name
    return accountHolderName;
}

string BankAccount::getAccountType() {
    return accountType;
}

double BankAccount::getBalance() {
    // This will get the bank account balance
    return balance;
}

void BankAccount::setAccountHolderName(string accountHoldName) {
    // This will set the bank account holder name
    this->accountHolderName = accountHoldName;
}

double BankAccount::deposit(double amount) {
    // This will deposit money into the bank account
    balance += amount;
    return balance;
}

double BankAccount::withdraw(double amount) {
    // This will withdraw money from the bank account
    balance -= amount;
    return balance;
}

BankAccount::BankAccount(const BankAccount &other) {
    // This is the copy constructor
    this->accountNumber = other.accountNumber;
    this->accountHolderName = other.accountHolderName;
    this->balance = other.balance;
    this->accountType = other.accountType;
}

BankAccount &BankAccount::operator=(const BankAccount &other) {
    // This is the assignment operator
    if (this == &other) {
        return *this;
    }
    this->accountNumber = other.accountNumber;
    this->accountHolderName = other.accountHolderName;
    this->balance = other.balance;
    return *this;
}

BankAccount::~BankAccount() {
    // This is the destructor
    // No manual memory management is needed, but the destructor should be virtual.
}

BankAccount &BankAccount::operator+=(double amount) {
    // This is the addition operator
    if (amount > 0) {
        balance += amount;
    }
    return *this;
}

BankAccount &BankAccount::operator-=(double amount) {
    // This is the subtraction operator
    if (balance > amount and amount > 0) {
        balance -= amount;
    }
    return *this;
}

bool BankAccount::operator==(const BankAccount &other) const {
    // This is the equality operator
    return accountNumber == other.accountNumber;
}

bool BankAccount::operator<(const BankAccount &other) const {
    // This is the less than operator
    return balance < other.balance;
}

bool BankAccount::operator>(const BankAccount &other) const {
    // This is the greater than operator
    return balance > other.balance;
}

void BankAccount::printAccount(const BankAccount *account) {
    // This will print out all bank details of the specified account
    cout << "---------------------------" << endl;
    cout << "Account Details:" << endl;
    cout << "   Account Number: " << account->accountNumber << endl;
    cout << "   Account Holder Name: " << account->accountHolderName << endl;
    cout << "   Balance: " << account->balance << endl;
    cout << "   Account Type: " << account->accountType << endl;
}

void BankAccount::printAllAccounts(const vector<unique_ptr<BankAccount>> &bankAccounts) {
    int currentNum = 1;
    vector<Account> accountData;
    for (const auto& item : bankAccounts) {
        accountData.push_back({currentNum, item->getAccountNumber(), item->getAccountType(), item->getAccountHolderName(), item->getBalance()});
        currentNum+=1;
    }
    FormattedTable table_data = pipelineprinting::formatCustomData(accountData);
    pipelineprinting::printTable(table_data);
}

BankAccount BankAccount::createAccountFromInput(const vector<unique_ptr<BankAccount> > &bankAccounts) {
    // This will create a new account from input
    string newAccountNumber;
    string newAccountHolderName;
    string newAccountType;
    double newBalance;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Create Account Details" << endl;
    int accountTypeNum = InputValidator::getValidInput<int>(
        "What kind of account do you want to make? (1) Checking (2) Savings: ");
    if (accountTypeNum == 1) {
        newAccountType = "Checking";
    } else {
        newAccountType = "Savings";
    }
    cout << "Enter Account Number: ";
    cin.ignore();
    getline(cin, newAccountNumber);
    for (const auto &account: bankAccounts) {
        if (account->getAccountNumber() == newAccountNumber) {
            cout << endl << "There is another account with the same account number. Please try again" << endl;
            return createAccountFromInput(bankAccounts);
        }
    }
    cout << "Enter Account Holder Name: ";
    //cin.ignore();
    getline(cin, newAccountHolderName);
    //cin.ignore();
    newBalance = InputValidator::getValidInput<double>("Enter Balance:");
    return {newAccountNumber, newAccountHolderName, newBalance, newAccountType};
}

BankAccount BankAccount::copyAccount(const BankAccount *account) {
    // This will copy an account
    const BankAccount *newAccount(account);
    return *newAccount;
}
// Gemini AI helpt me rewrite this function. It still has my base code though
unique_ptr<BankAccount> BankAccount::accountCreator() {
    mt19937 generator(std::random_device{}());
    uniform_real_distribution<double> distribution(0.0, 10000.0);
    int accountTypeToUse = InputValidator::getValidInput<int>(
        "What kind of account do you want to make? (1) Checking (2) Savings: ");

    auto getAccountDetails = []() -> tuple<string, string, double> {
        string newAccountNumber;
        string newAccountHolderName;
        double newBalance;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Create Account Details" << endl;
        cout << "Enter Account Number: ";
        getline(cin, newAccountNumber);
        cout << "Enter Account Holder Name: ";
        getline(cin, newAccountHolderName);
        newBalance = InputValidator::getValidInput<double>("Enter Balance:");
        return make_tuple(newAccountNumber, newAccountHolderName, newBalance);
    };

    switch (accountTypeToUse) {
        case 1: {
            auto [number, name, balance] = getAccountDetails();
            return make_unique<CheckingAccount>(number, name, balance);
        }
        case 2: {
            auto [number, name, balance] = getAccountDetails();
            return make_unique<SavingsAccount>(number, name, balance);
        }
        case 3: {
            cout << "Creating default Checking Account for testing..." << endl;
            // Using make_unique to create a CheckingAccount on the heap and return a smart pointer
            return make_unique<CheckingAccount>("CHK-" + to_string(rand() % 1000), "Test User", distribution(generator));
        }
        case 4: {
            cout << "Creating default Savings Account for testing..." << endl;
            // Using make_unique to create a SavingsAccount on the heap and return a smart pointer
            return make_unique<SavingsAccount>("SAV-" + to_string(rand() % 1000), "Test User", distribution(generator));
        }
        default:
            cout << "Input is not within the valid range" << endl;
            return accountCreator();
    }
}

void BankAccount::setAccountType(string AccountType) {
    cout << "Something happened: " << AccountType << endl;
    this->accountType = AccountType;
}

BankAccount::BankAccount() {
    // This is the default constructor
    accountNumber = "";
    accountHolderName = "";
    balance = 0.0;
    accountType = "";
}

BankAccount::BankAccount(string acountNum, string HolderName, double bal, string accType) {
    // This is the parameterized constructor
    accountNumber = acountNum;
    accountHolderName = HolderName;
    balance = bal;
    accountType = accType;
}
