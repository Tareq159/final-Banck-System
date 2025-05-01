#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation
{
public:
    static bool validateName(const string& name) {
        if (name.length() < 5 || name.length() > 20) {
            return false;
        }
        for (char c : name) {
            if (!isalpha(c)) {
                return false;
            }
        }
        return true;
    }


    static bool validatePassword(const string& password) {
        if (password.length() < 8 || password.length() > 20) {
            return false;
        }
        return true;
    }
    

    static bool validateId(int id) {
        return (id >= 0);
    }

    static bool validateSalary(double salary) {
        return salary >= 5000;
    }
    static bool validatBalance(double newBalance) {
        return  newBalance >= 1500;
    }
    static bool validatAmount(double newAmount) {
        return  newAmount > 0;
    }
    
    static bool validatWithdrow( double newAmount, double balance) {
        return newAmount <= balance;
    }
   
};

