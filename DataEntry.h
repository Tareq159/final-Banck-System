#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
using namespace std;
class DataEntry
{
public:
    static string enterName() {
        string name;
        cout << "Enter name: ";
        getline(cin >> ws, name);
        while (!Validation::validateName(name)) {
            cout << "Invalid name (must be 5-20 letters). Try again: ";
            getline(cin >> ws, name);
        }
        return name;
    }

    static string enterPassword() {
        string password;
        cout << "Enter password: ";
        cin >> password;
        while (!Validation::validatePassword(password)) {
            cout << "Invalid password (8+ chars, mix of letters/numbers). Try again: ";
            cin >> password;
        }
        return password;
    }

    static double enterSalary() {
        double salary;
        cout << "Enter salary: ";
        cin >> salary;
        while (!Validation::validateSalary(salary)) {
            cout << "Invalid salary (min 5000). Try again: ";
            cin >> salary;
        }
        return salary;
    }

    static double enterBalance() {
        double balance;
        cout << "Enter balance: ";
        cin >> balance;
        while (!Validation::validatBalance(balance)) {
            cout << "Invalid balance (min 1500). Try again: ";
            cin >> balance;
        }
        return balance;
    }

    static double enterAmount() {
        double amount;
        cout << "Enter amount: ";
        cin >> amount;
        while (!Validation::validatAmount(amount)) {
            cout << "Invalid amount (must be positive). Try again: ";
            cin >> amount;
        }
        return amount;
    }
};

