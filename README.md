# BankAccount Class

A C++ class for making and editing a bank account.

## Data Dictionary
| Attribute           | Data Type | Description                             |
|---------------------|-----------|-----------------------------------------|
| `accountNumber`     | `string`  | Holds the accounts account number.      |
| `accountHolderName` | `string`  | Holds the accounts account holder name. |
| `balance`           | `double`  | Holds the accounts balance.             |

## Methods List

| Method Signature                                   | Return Type             | Description                            |
|----------------------------------------------------|-------------------------|----------------------------------------|
| `BankAccount()`                                    | (Constructor)           | Default constructor.                   |
| `BankAccount(acountNum, HolderName, bal)`          | (Constructor)           | Parameterized constructor.             |
| `getAccountNumber()`                               | `string`                | Gets the accounts number.              |
| `getAccountHolderName()`                           | `string`                | Gets the accounts account holder name. |
| `getBalance()`                                     | `double`                | Gets the account balance.              |
| `setAccountHolderName(accountHoldName)`            | `void`                  | Sets the account holder name.          |
| `deposit(amount)`                                  | `double`                | Deposits money into an account.        |
| `withdraw(amount)`                                 | `double`                | Withdraws money from a account.        |
| `BankAccount(const BankAccount& other)`            | (Constructor)           | Copy constructor.                      |
| `BankAccount& operator=(const BankAccount& other)` | (Assignment Operator)   | Assignment operator.                   |
| `~BankAccount()`                                   | (Destructor)            | Destructor.                            |
| `BankAccount& operator+=(double amount)`           | (Addition Operator)     | Addition operator.                     |
| `BankAccount& operator-=(double amount)`           | (Subtraction Operator)  | Subtraction operator.                  |
| `bool operator==(const BankAccount& other) const`  | (Equality Operator)     | Equality operator.                     |
| `bool operator<(const BankAccount& other) const`   | (Less Than Operator)    | Less than operator.                    |
| `bool operator>(const BankAccount& other) const`   | (Greater Than Operator) | Greater than operator.                 |
