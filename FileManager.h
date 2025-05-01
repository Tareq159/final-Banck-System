#pragma once

#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager :
	public DataSourceInterface
{
public:
	static void addClient(Client c) {
		FilesHelper::saveClient(c);
	}
	static void addEmployee(Employee e) {
		FilesHelper::saveEmployee("Employee.txt", "EmployeeLastId.txt", e);
	}
	static void addAdmin(Admin a) {
		FilesHelper::saveEmployee("Admin.txt", "AdminLastId.txt", a);
	}
	static vector<Client> getAllClients() {
		return FilesHelper::getClients();
	}
	static vector<Employee> getAllEmployees() {
		return FilesHelper::getEmployee();
	}
	static vector<Admin> getAllAdmins() {
		return  FilesHelper::getAdmin();
	}
	static void removeAllClients() {
		FilesHelper::clearFile("Client.txt", "ClientLastId.txt");
	}
	static void removeAllEmployees() {
		FilesHelper::clearFile("Employee.txt", "EmployeeLastId.txt");
	}
	static void removeAllAdmins() {
		FilesHelper::clearFile("Admin.txt", "AdminLastId.txt");
	}
	static void editClient() {
		
		removeAllClients();

		ofstream of;
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
	static void editEmployee() {
		removeAllEmployees();
		ofstream of;
		of.open("Employee.txt", ofstream::app);
		for (auto& c : VectorEmployee::employees) {
			if (c.get_id() != 1) {
				of << "\n";
			}
			of << c.get_id() << "-" <<
				c.get_name() << "-" <<
				c.get_password() << "-" <<
				c.get_salary();

		}
		of.close();
	}
	static void editAdmin() {
		removeAllAdmins();
		ofstream of;
		of.open("Admin.txt", ofstream::app);
		for (auto& c : VectorAdmin::admins) {
			if (c.get_id() != 1) {
				of << "\n";
			}
			of << c.get_id() << "-" <<
				c.get_name() << "-" <<
				c.get_password() << "-" <<
				c.get_salary();

		}
		of.close();
	}

};
