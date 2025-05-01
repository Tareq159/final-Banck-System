#pragma once
#include <iostream>
#include <Windows.h>
#include "Client.h"
#include "VectorClient.h"
#include "FileManager.h"
#include "DataEntry.h" 

using namespace std;
class ClientManager
{
public:
    static void printClientMenu() {
        cout << "\n--- Client Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Check Balance\n";
        cout << "5. Update Password\n";
        cout << "6. Update Name\n";
        cout << "7. Display Info\n";
        cout << "8. Logout\n";
        cout << "Enter your choice: ";
    }

    static void updatePassword(Client* client) {
        string newPass;
        cout << "Enter new password: ";
        newPass = DataEntry::enterPassword();

        client->set_password(newPass);
        FileManager::editClient();
        cout << "Password updated successfully.\n";
    }
    static void updateName(Client* client) {
        string name;
        cout << "Enter new Name: ";
        name = DataEntry::enterName();

        client->set_name(name);
        FileManager::editClient();
        cout << "Name updated successfully.\n";
    }
    static Client* login(int id, string password) {
        for (Client& client : VectorClient::clients) {
            if (client.get_id() == id && client.get_password() == password) {
                cout << "\nLogin successful.\n";
                return &client;
            }
        }
        cout << "\nInvalid ID or password.\n";
        return nullptr;
    }

    static void clientOperations(Client* client) {
        int choice;
        double amount;
        int recipientId;
        bool found;
        string name;
        do {

            printClientMenu();
            cin >> choice;

            switch (choice) {
            case 1:

                cout << "Enter amount to deposit: ";
                amount = DataEntry::enterAmount();
                client->deposit(amount);
                FileManager::editClient();
                system("pause");
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                amount = DataEntry::enterAmount();

                client->withdrow(amount);
                FileManager::editClient();
                
                system("pause");
                break;

            case 3:
                cout << "Enter recipient ID: ";
                cin >> recipientId;
                cout << "Enter amount: ";
                amount = DataEntry::enterAmount();
                found = false;

                for (Client& recipient : VectorClient::clients) {
                    if (recipient.get_id() == recipientId) {
                        
                        client->transferTo(amount, recipient);
                        FileManager::editClient();
                        found = true;
                        break;
                        
                        
                    }
                }
                if (!found) cout << "Recipient not found!\n";
                system("pause");
                break;

            case 4:
                client->checkBalance();
                system("pause");
                break;

            case 5:
                updatePassword(client);
                system("pause");
                break;

            case 6:
                
                updateName(client);
                system("pause");
                break;


            case 7:
                client->display_info();
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

