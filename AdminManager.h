#pragma once
#include "EmplooyeManager.h"
class AdminManager :
	public EmplooyeManager 
{
public:
    static void printAdminMenu() {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add client\n";
        cout << "2. Search client\n";
        cout << "3. List of client\n";
        cout << "4. Edit client\n";
        cout << "5. Add employee\n";
        cout << "6. Search employee\n";
        cout << "7. List of employee\n";
        cout << "8. Edit employee\n";
        cout << "9. Remove all employees\n";
        cout << "10. Remove all Client\n";
        cout << "11. Update Password \n";
        cout << "12. Update Name \n";
        cout << "13. Display Info\n";
        cout << "14. Logout\n";
        cout << "Enter your choice: ";
    }

    static void updatePassword(Admin* admin) {
        string newPass;
        cout << "Enter new password: ";
        newPass = DataEntry::enterPassword();

        admin->set_password(newPass);
        FileManager::editAdmin();
        cout << "Password updated successfully.\n";
    }
    static void updateName(Admin* admin) {
        string name;
        cout << "Enter new Name: ";
        name = DataEntry::enterName();

        admin->set_name(name);
        FileManager::editAdmin();
        cout << "Name updated successfully.\n";
    }

    static Admin* login(int id, string password) {
        for (Admin& admin : VectorAdmin::admins) {
            if (admin.get_id() == id && admin.get_password() == password) {
                cout << "\nLogin successful.\n";
                return &admin;
            }
        }
        cout << "\nInvalid ID or password.\n";
        return nullptr;
    }

    static void newEmployee(Admin* admin) {
        int id;
        string name, pass;
        double salary;
        cout << "Enter  Name , Password and Salary : \n";
        id = FilesHelper::getLast("EmployeeLastId.txt") + 1;
        name = DataEntry::enterName();
        pass = DataEntry::enterPassword();
        salary = DataEntry::enterSalary();
        Employee a(id, name, pass, salary);
        admin->addEmployee(a);
    }

    static void listAllEmployee(Admin* admin) {
        admin->listEmployee();
    }

    // true ?
    static void searchForEmployee(Admin* admin) {
        int id;
        cout << "Enter Id Employee to search : ";
        cin >> id;
        if (admin->searchEmployee(id)) {
            cout << "found. \n";
        }
        else {
            cout << "Not found. \n";
        }
    }

    static void editForEmployeeInfo(Admin* admin) {
        int id;
        string name, pass;
        double salary;
        cout << "Enter Id Employee :  ";
        cin >> id;
        if (admin->searchEmployee(id)) {
            name = DataEntry::enterName();
            pass = DataEntry::enterPassword();
            salary = DataEntry::enterSalary();
            admin->editEmployee(id, name, pass, salary);
        }
        else
        {
            cout << "Not found. \n";
        }

    }
    
    static void removAllClients() {
        FileManager::removeAllClients();
        VectorClient::clients.clear();
        cout << "Remove all Client DUNE \n";
    }
    static void removAllEmployees() {
        FileManager::removeAllEmployees();
        VectorEmployee::employees.clear();
        cout << "Remove all Employees DUNE \n";
    }

    static void adminOperations(Admin* admin) {
        int choice;
        double amount;
        int recipientId;
        bool found;

        int id;
        string name, pass;
        double balance;
        do {

            printAdminMenu();
            cin >> choice;

            switch (choice) {
            case 1:

                newClient(admin);

                system("pause");
                break;

            case 2:
                searchForClient(admin);

                system("pause");
                break;

            case 3:
                listAllClient(admin);
                system("pause");
                break;

            case 4:
                editForClientInfo(admin);
                system("pause");
                break;

            case 5:
                newEmployee(admin);
                system("pause");
                break;

            case 6:
                searchForEmployee(admin);

                system("pause");
                break;

            case 7:
                listAllEmployee(admin);
                system("pause");
                break;

            case 8:
                editForEmployeeInfo(admin);
                system("pause");
                break;
            case 9:
                removAllEmployees();
                system("pause");
                break;
            case 10:
                removAllClients();
                system("pause");
                break;

            case 11:
                updatePassword(admin);
                system("pause");
                break;
            
            case 12:
                updateName(admin);
                system("pause");
                break;

            case 13:
                admin->display_info();
                system("pause");
                break;

            case 14:
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

