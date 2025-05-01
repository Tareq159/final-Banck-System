#pragma once
#include <iostream>
#include <Windows.h>
#include "Parser.h"
#include "VectorClient.h"
#include "VectorEmployee.h"
#include "VectorAdmin.h"
#include "ClientManager.h"
#include "AdminManager.h"
using namespace std;
class Screen
{
	static void readFileEmployee() {
		vector<string> sp;
		ifstream out;
		string line, name, password;
		int id;
		double salary;
		out.open("Employee.txt");
		while (getline(out, line)) {
			sp = Parser::split(line);
			id = stoi(sp[0]);
			name = sp[1];
			password = sp[2];
			salary = stod(sp[3]);
			VectorEmployee::employees.push_back(Employee(id, name, password, salary));
		}
		out.close();
	}
	static void readFileClient() {
		vector<string> sp;
		ifstream out;
		string line, name, password;
		int id;
		double balance;
		out.open("Client.txt");
		while (getline(out, line)) {
			sp = Parser::split(line);
			id = stoi(sp[0]);
			name = sp[1];
			password = sp[2];
			balance = stod(sp[3]);
			VectorClient::clients.push_back(Client(id, name, password, balance));
		}
		out.close();
	}
	static void readFileAdmin() {
		vector<string> sp;
		ifstream out;
		string line, name, password;
		int id;
		double salary;
		out.open("Admin.txt");
		while (getline(out, line)) {
			sp = Parser::split(line);
			id = stoi(sp[0]);
			name = sp[1];
			password = sp[2];
			salary = stod(sp[3]);
			VectorAdmin::admins.push_back(Admin(id, name, password, salary));
		}
		out.close();
	}
	static void bankName() {
        // طباعة كلمة TOP في السطر الأول (مكونة من 5 أسطر)
        cout << "\n\n\t\t\t\t\t*****  ***  ****      " << endl;
        cout << "\t\t\t\t\t  *   *   * *   *     " << endl;
        cout << "\t\t\t\t\t  *   *   * ****      " << endl;
        cout << "\t\t\t\t\t  *   *   * *         " << endl;
        cout << "\t\t\t\t\t  *    ***  *         " << endl;

        // طباعة كلمة BANK في السطر الثاني (مكونة من 5 أسطر)
        cout << "\n\n\t\t\t\t\t****   ***  *   * *   *" << endl;
        cout << "\t\t\t\t\t*   * *   * **  * *  * " << endl;
        cout << "\t\t\t\t\t****  ***** * * * ***  " << endl;
        cout << "\t\t\t\t\t*   * *   * *  ** *  * " << endl;
        cout << "\t\t\t\t\t****  *   * *   * *   *" << endl;
	}
	static bool invalid(int t) {
		return t == 1 || t == 2 || t == 3;
	}
	static void loginOptions() {
		Sleep(2000);
		cout << "1.Admin\n";
		cout << "2.Emplooye\n";
		cout << "3.Client\n";
		cout << "Enter choise : ";

	}

public:
	static void welcome() {
		bankName();
	}
	static void runApp() {
		readFileClient();
		readFileEmployee();
		readFileAdmin();
	}
	static int loginAs() {
		
		int t;
		do
		{
			loginOptions();
			cin >> t;
		} while (!invalid(t));
		return t;
	}
	static void loginScreen(int c) {
		int id;
		string pass;
		switch (c)
		{
		case 1:
			system("color 10");
			Admin* admin;
			do
			{
				if (VectorAdmin::admins.empty()) {
					cout << "No Admins her.\n";
					Sleep(2000);
					goto her;
				}
				// مع وايل ولا بدون ؟
				cout << "Enter Id and password : ";
				cin >> id >> pass;
				admin = AdminManager::login(id, pass);
				system("cls");

			} while (!admin);

			AdminManager::adminOperations(admin);
			her:
			break;
		case 2:
			system("color 90");
			Employee * employee;
			do
			{
				if (VectorEmployee::employees.empty()) {
					cout << "No Employee her.\n";
					Sleep(2000);
					goto her2;

				}
				// مع وايل ولا بدون ؟
				cout << "Enter Id and password : ";
				cin >> id >> pass;
				employee = EmplooyeManager::login(id, pass);
				system("cls");

			} while (!employee);

			EmplooyeManager::employeeOperations(employee);
			her2:
			break;
		case 3:

			Client* client;
			do
			{
				if (VectorClient::clients.empty()) {
					cout << "No Admins her.\n";
					Sleep(2000);
					goto her1;

				}
				// مع وايل ولا بدون ؟
				cout << "Enter Id and password : ";
				cin >> id >> pass;
				client = ClientManager::login(id, pass);
				system("cls");
				
			} while (!client);

			ClientManager::clientOperations(client);
			her1:
			system("cls");
			break;
		}
	}
	static void logout() {
		loginAs();
	}
};

