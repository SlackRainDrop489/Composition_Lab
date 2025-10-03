cmake_minimum_required(VERSION 4.0)
project(Inheritance_Lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(Inheritance_Lab main.cpp
        BankAccount.cpp
        BankAccount.h
        InputValidator.h
        CheckingAccount.cpp
        CheckingAccount.h
        SavingsAccount.cpp
        SavingsAccount.h
)