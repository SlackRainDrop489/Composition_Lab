# BankAccount Class

A C++ class for making and editing a bank account.

## Data Dictionary
| Attribute                                | Data Type     | Description                                    |
|------------------------------------------|---------------|------------------------------------------------|
| `accountNumber`                          | `string`      | Holds the accounts account number.             |
| `accountHolderName`                      | `string`      | Holds the accounts account holder name.        |
| `balance`                                | `double`      | Holds the accounts balance.                    |
| `accountType`                            | `string`      | Holds the accounts type.                       |
| `vector<Transaction> transactionHistory` | `Transaction` | Holds the transaction history for that account |


## Methods List

| Method Signature                                    | Return Type               | Description                                                            |
|-----------------------------------------------------|---------------------------|------------------------------------------------------------------------|
| `BankAccount()`                                     | (Constructor)             | Default constructor.                                                   |
| `BankAccount(acountNum, HolderName, bal, accType)`  | (Constructor)             | Parameterized constructor.                                             |
| `getAccountNumber()`                                | `string`                  | Gets the accounts number.                                              |
| `getAccountHolderName()`                            | `string`                  | Gets the accounts account holder name.                                 |
| `getAccountType()`                                  | `string`                  | Gets the account type.                                                 |
| `getBalance()`                                      | `double`                  | Gets the account balance.                                              |
| `setAccountHolderName(accountHoldName)`             | `void`                    | Sets the account holder name.                                          |
| `deposit(amount)`                                   | `double`                  | Deposits money into an account.                                        |
| `withdraw(amount)`                                  | `double`                  | Withdraws money from a account.                                        |
| `BankAccount(const BankAccount& other)`             | (Constructor)             | Copy constructor.                                                      |
| `BankAccount& operator=(const BankAccount& other)`  | (Assignment Operator)     | Assignment operator.                                                   |
| `~BankAccount()`                                    | (Destructor)              | Destructor.                                                            |
| `BankAccount& operator+=(double amount)`            | (Addition Operator)       | Addition operator.                                                     |
| `BankAccount& operator-=(double amount)`            | (Subtraction Operator)    | Subtraction operator.                                                  |
| `bool operator==(const BankAccount& other) const`   | (Equality Operator)       | Equality operator.                                                     |
| `bool operator<(const BankAccount& other) const`    | (Less Than Operator)      | Less than operator.                                                    |
| `bool operator>(const BankAccount& other) const`    | (Greater Than Operator)   | Greater than operator.                                                 |
| `printAccount(BankAccount)`                         | `void`                    | Prints out data about a bank account                                   |
| `printAllAccounts(vector<unique_prt<BankAccount>>)` | `void`                    | Prints out data about every account                                    |
| `accountCreator()`                                  | `unique_prt<BankAccount>` | Creates a new Checking or Savings account.                             |
| `printHistory()`                                    | `void`                    | Prints out all of the transactions that have been made on that account |

---
# CheckingAccount Class
Inherits BankAccount
## Data Dictionary
| Attribute        | Data Type | Description                                 |
|------------------|-----------|---------------------------------------------|
| `transactionFee` | `double`  | Holds the fee for when a withdrawal is made |

## Methods List

| Method Signature                              | Return Type   | Description                                                          |
|-----------------------------------------------|---------------|----------------------------------------------------------------------|
| `CheckingAccount(acountNum, HolderName, bal)` | (Constructor) | Creates a new CheckingAccount object that inherits BankAccount       |
| `withdraw(amount)`                            | `double`      | Withdraws money from an account and takes transactionFee out as well |

---
# SavingsAccount Class
Inherits BankAccount

## Data Dictionary
| Attribute     | Data Type | Description            |
|---------------|-----------|------------------------|
| `intrestRate` | `double`  | Holds the intrest rate |

## Methods List

| Method Signature                             | Return Type   | Description                                                   |
|----------------------------------------------|---------------|---------------------------------------------------------------|
| `SavingsAccount(acountNum, HolderName, bal)` | (Constructor) | Creates a new SavingsAccount object that inherits BankAccount |
| `calculateIntrest`                           | `void`        | Adds the intrest to the balance                               |

---

# Transaction Class

## Data Dictionary
| Attribute   | Data Type | Description                                |
|-------------|-----------|--------------------------------------------|
| `type`      | `string`  | Holds the type of transaction              |
| `amount`    | `double`  | Holds the amount added or removed          |
| `timestamp` | `string`  | Holds the time and date of the transaction |

## Methods List

| Method Signature                          | Return Type   | Description                  |
|-------------------------------------------|---------------|------------------------------|
| `Transaction(string type, double amount)` | (Constructor) | Creates a Transaction object |

---