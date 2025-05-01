#pragma once
#include <iostream>
#include <exception>
#include "Validation.h"
using namespace std;

class Person
{
    string name, password;
	int id;
public:

    Person(int id, string name, string password) {
        if (!Validation::validateId(id)) {
            throw invalid_argument( "Invalid ID.");
        }
        this->id = id;
        set_name(name);
        set_password(password);
    }
    void set_name(string name) {
        if (!Validation::validateName(name)) {
            throw invalid_argument( "Invalid name.");
        }
        this->name = name;
    }
    void set_password(string password) {
        if (!Validation::validatePassword(password)) {
            throw invalid_argument( "Invalid Password.");
        }
        this->password = password;
    }
    int get_id() {
        return id;
    }
    string get_name() {
        return name;
    }
    string get_password() {
        return password;
    }

    virtual void display_info() {
        cout << "ID : " << get_id() << endl;
        cout << "NAME : " << get_name() << endl;
    }
    //virtual void login(int id,string password) = 0;
};
