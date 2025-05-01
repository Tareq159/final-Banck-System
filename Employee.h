#pragma once
#include "Client.h"
#include <vector>
#include "Person.h"
#include "VectorClient.h"
#include <stdexcept>
#include <exception>
#include<sstream>
#include<fstream>

class Employee :
    public Person
{
    double salary;
    
public:
    Employee(int id, string name, string password, double salary) :Person(id, name, password) {
        set_salary(salary);
    }
    void set_salary(double salary) {
        if (!Validation::validateSalary(salary)) {
            throw invalid_argument("Invalid salary. Salary must be at least 5000.\n");
        }
        this->salary = salary;
    }

    double get_salary() { return salary; }

   
    void display_info() {
        Person::display_info();
        cout << "Salary: " << salary  << endl;
    }

    void addClient(Client& client) {
        VectorClient::clients.push_back(client);
        int id;
		ifstream input;
		input.open("ClientLastId.txt");
		input >> id;
		input.close();

        ofstream of;
        of.open("Client.txt", ofstream::app);
        if (id != 0) {
            of << "\n";
        }
        of << client.get_id() << "-" <<
            client.get_name() << "-" <<
            client.get_password() << "-" <<
            client.get_balance();
        of.close();

        of.open("ClientLastId.txt");
        of << client.get_id();
        of.close();
        cout << "Client added successfully!\n";
    }

    Client* searchClient(int id) {
        auto& c = VectorClient::clients;
        for (auto& client : c) {
            if (client.get_id() == id) {
                return &client;
            }    
        }
        return nullptr;
    }

    void listClient() {
        if (VectorClient::clients.empty()) {
            cout << "No clients found.\n";
            return;
        }
        for (auto& client : VectorClient::clients) {
            client.display_info();
        }
    }

    void editClient(int id, string name, string password, double balance) {
        Client* client = searchClient(id);
        if (client) {
            client->set_name(name);
            client->set_password(password);
            client->set_balance(balance);
            cout << "Client updated successfully!\n";
        }
        else {
            cout << "Client not found!\n";
        }
        ofstream of;
        of.open("Client.txt");
        of.clear();
        of.close();

        of.open("Client.txt", ofstream::app);
        for (auto& c : VectorClient::clients) {
            if (c.get_id() != 1) {
                of << "\n";
            }
            of << c.get_id() << "-" <<
                c.get_name() << "-" <<
                c.get_password() << "-" <<
                c.get_balance();
            
        }
        of.close();
    }

};