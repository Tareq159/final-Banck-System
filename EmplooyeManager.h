#pragma once
#include <iostream>
#include <Windows.h>
#include "Employee.h"
#include "Client.h"
#include "VectorEmployee.h"
#include "FileManager.h"
#include "DataEntry.h" 

using namespace std;
class EmplooyeManager
{
public:
    static void printEmployeeMenu() {
        cout << "\n--- Employee Menu ---\n";
        cout << "1. Add client\n";
        cout << "2. Search client\n";
        cout << "3. List of client\n";
        cout << "4. Edit client\n";
        cout << "5. Update Password\n";
        cout << "6. Update Name\n";
        cout << "7. Display Info\n";
        cout << "8. Logout\n";
        cout << "Enter your choice: ";
    }

    static void updatePassword(Employee* employee) {
        string newPass;
        cout << "Enter new password: ";
        newPass = DataEntry::enterPassword();

        employee->set_password(newPass);
        FileManager::editEmployee();
        cout << "Password updated successfully.\n";
    }

    static void updateName(Employee* employee) {
        string name;
        cout << "Enter new Name: ";
        name = DataEntry::enterName();

        employee->set_name(name);
        FileManager::editEmployee();
        cout << "Name updated successfully.\n";
    }
    static Employee* login(int id, string password) {
        for (Employee& employee : VectorEmployee::employees) {
            if (employee.get_id() == id && employee.get_password() == password) {
                cout << "\nLogin successful.\n";
                return &employee;
            }
        }
        cout << "\nInvalid ID or password.\n";
        return nullptr;
    }

    static void newClient(Employee* employee) {
        int id;
        string name, pass;
        double balance;
        cout << "Enter  Name , Password and Balance : \n";
        id = FilesHelper::getLast("ClientLastId.txt") + 1;
        name = DataEntry::enterName();
        pass = DataEntry::enterPassword();
        balance = DataEntry::enterBalance();
        Client a(id, name, pass, balance);
        employee->addClient(a);
    }

    static void listAllClient(Employee* employee) {
        employee->listClient();
    }

    // true ?
    static void searchForClient(Employee* employee) {
        int id;
        cout << "Enter Id Client to search : ";
        cin >> id;
        if (employee->searchClient(id)) {
            cout << "found. \n";
        }
        else {
            cout << "Not found. \n";
        }
    }

    static void editForClientInfo(Employee* employee) {
        int id;
        string name, pass;
        double balance;
        cout << "Enter Id Client :  ";
        cin >> id;
        if (employee->searchClient(id)) {
            name = DataEntry::enterName();
            pass = DataEntry::enterPassword();
            balance = DataEntry::enterBalance();
            employee->editClient(id,name,pass,balance);
        }
        else
        {
            cout << "Not found. \n";
        }

    }

    static void employeeOperations(Employee* employee) {
        int choice;
        double amount;
        int recipientId;
        bool found;

        int id;
        string name, pass;
        double balance;
        do {

            printEmployeeMenu();
            cin >> choice;

            switch (choice) {
            case 1:

                newClient(employee);
                
                system("pause");
                break;

            case 2:
                searchForClient(employee);
                
                system("pause");
                break;

            case 3:
                listAllClient(employee);
                system("pause");
                break;

            case 4:
                editForClientInfo(employee);
                system("pause");
                break;

            case 5:
                updatePassword(employee);
                system("pause");
                break;
            case 6:
                updateName(employee);
                system("pause");
                break;

            case 7:
                employee->display_info();
                system("pause");
                break;

            case 8:
                cout << "Logging out...\n";
                Sleep(1000);


                return;

            default:
                cout << "Invalid choice. Try again.\n";
                Sleep(2000);
            }

            system("cls");
        } while (true);
    }

};

