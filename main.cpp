/*
Quinn Alvine
10/3/25
This program is for making and editing a bank account
Lab Activities: Inheritance
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <memory>
#include <chrono>
#include "BankAccount.h"
#include "InputValidator.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "pipelineprinting.h"

using namespace std;
using FormattedTable = std::vector<std::vector<std::string>>;


void Menu(int accountNum, string accountType) { // This will display the menu
    cout << "---------------------------" << endl;
    cout << "You are in account number: " << accountNum << endl;
    cout << "Account Type: " << accountType << endl;
    cout << "---------------------------" << endl;
    cout << "1. Set account holder name" << endl;
    cout << "2. Get account holder name" << endl;
    cout << "3. Get account number" << endl;
    cout << "4. Get balance" << endl;
    cout << "5. Change balance" << endl;
    cout << "6. Create new account" << endl;
    cout << "7. Change account" << endl;
    cout << "8. Print all details" << endl;
    cout << "9. Copy existing account" << endl;
    cout << "10. Print all accounts" << endl;
    cout << "11. Quit" << endl;
    cout << "---------------------------" << endl;
}


int main() { // Main function
    //BankAccount BankAccount1("39102", "Unnamed", 0.0, "Savings"); // This creates the first account
    vector<unique_ptr<BankAccount>> BankAccounts;
    BankAccounts.push_back(BankAccount::accountCreator());
    //CheckingAccount::printAccount(CheckingAccount1);
    int currentAccountNum = 0; // This is the current account
    int currentDisplayAccountNum = 1; // This is the account number to be displayed
    int input; // This is the input
    int accountInputNum; // This is the input for changing accounts
    string newAccountName; // This is for holding the new name of an account
    do { // This is the main loop
        Menu(currentDisplayAccountNum, BankAccounts[currentAccountNum]->getAccountType()); // This will display the menu
        cout << "Enter your choice: "; // This will prompt you for your input
        if (!(cin >> input)) { // This will make sure that you are inputting an int
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << endl;
            switch (input) { // This is the main switch
                case 1: // Change account name
                    cout << "Enter account holder name: ";
                    cin.ignore();
                    getline(cin, newAccountName);
                    BankAccounts[currentAccountNum]->setAccountHolderName(newAccountName);
                    break;
                case 2: // Get account holder name
                    cout << "The name of this account is: " << BankAccounts[currentAccountNum]->getAccountHolderName() << endl;
                    break;
                case 3: // Get account number
                    cout << "The account number is: " << BankAccounts[currentAccountNum]->getAccountNumber() << endl;
                    break;
                case 4: // Get balance
                    cout << "The balance is: " << BankAccounts[currentAccountNum]->getBalance() << endl;
                    break;
                case 5: {
                    // Change balance
                    int optionInput = InputValidator::getValidInput<int>("Would you like to make a (1) Deposit or (2) a Withdraw:");
                    switch (optionInput) {
                        case 1: {
                            // Make a deposit
                            double deposit = InputValidator::getValidInput<double>("How much would you like to deposit:");
                            if (deposit <= 0) {
                                cout << "You can not deposit that amount" << endl;
                            } else {
                                BankAccounts[currentAccountNum]->deposit(deposit);
                            }
                            break;
                        }
                        case 2: {
                            // Make a withdrawal
                            cout << endl << "You currently have $" << BankAccounts[currentAccountNum]->getBalance() << endl;
                            double withdraw = InputValidator::getValidInput<double>("How much would you like to withdraw:");
                            BankAccounts[currentAccountNum]->withdraw(withdraw);
                            break;
                        }
                        default: ;
                    }
                    break;
                }
                case 6: {
                    // Create new account from input
                    BankAccounts.push_back(BankAccount::accountCreator());
                    break;
                }
                case 7: // Change account
                    if (BankAccounts.size() == 1) {
                        cout << "There is only one bank account" << endl;
                    } else {
                        cout << "There are " << BankAccounts.size() << " bank accounts" << endl;
                        accountInputNum = InputValidator::getValidInput<int>("Please enter account number:");
                        if (accountInputNum <= 0 or accountInputNum > BankAccounts.size()) {
                            cout << endl << "There is no account with this number" << endl;
                        } else {
                            currentAccountNum = accountInputNum - 1;
                            currentDisplayAccountNum = accountInputNum;
                        }
                    }
                    break;
                case 8:
                    BankAccount::printAccount(BankAccounts[currentAccountNum].get());
                    break;
                case 9: { // This will let you copy an account
                    // Copy existing account
                    int accountNum = -1;
                    if (BankAccounts.size() == 1) {
                        cout << "There is only one bank account. Would you like to copy it? (1) Yes (2) No" << endl;
                        int optionInput = InputValidator::getValidInput<int>("Option:");
                        if (optionInput == 1) {
                            accountNum = 0;
                        }
                    } else {
                        cout << "Which account would you like to copy? There are currently " << BankAccounts.size() << " accounts" << endl;
                        BankAccount::printAllAccounts(BankAccounts);
                        int accountToUse = InputValidator::getValidInput<int>("Account Number:");
                        if (accountToUse <= 0 or accountToUse > BankAccounts.size()) {
                            cout << "Your input is not within the valid range of accounts" << endl;
                        } else {
                            accountNum = accountToUse - 1;
                        }
                    }
                    if (accountNum != -1) {
                        if (BankAccounts[accountNum]->getAccountType() == "Checking") {
                            BankAccount* tempAccount = BankAccounts[accountNum].get();
                            unique_ptr<BankAccount> copiedAccount = make_unique<CheckingAccount>(tempAccount->getAccountNumber(), tempAccount->getAccountHolderName(), tempAccount->getBalance());
                            BankAccounts.push_back(std::move(copiedAccount));
                        } else {
                            BankAccount* tempAccount = BankAccounts[accountNum].get();
                            unique_ptr<BankAccount> copiedAccount = make_unique<SavingsAccount>(tempAccount->getAccountNumber(), tempAccount->getAccountHolderName(), tempAccount->getBalance());
                            BankAccounts.push_back(std::move(copiedAccount));
                        }
                        cout << "Account copied." << endl;
                    }
                    break;
                }
                case 10:
                    BankAccount::printAllAccounts(BankAccounts);
                    break;
                case 11: // Quit
                    cout << "Quit";
                    break;
                default:
                    cout << "Please enter a valid choice." << endl;
                    break;
            }
        }
    } while (input != 11); // will run while input is not 11
    return 0;
}