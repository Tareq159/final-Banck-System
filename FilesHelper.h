#pragma once
#include "Parser.h"
#include "Validation.h"
#include "VectorClient.h"
#include "VectorEmployee.h"
#include "VectorAdmin.h"


class FilesHelper
{
public:
	

	static void saveLast(string fileName,int id) {
		if (!Validation::validateId(id)) {
			throw invalid_argument("Invalid ID.");
		}
		ofstream of;
		of.open(fileName);
		of << id;
		of.close();
	}
	static int getLast(string fileName) {
		int id;
		ifstream input;
		input.open(fileName);
		input >> id;
		input.close();
		return id;
	}
	static void saveClient(Client c) {
		VectorClient::clients.push_back(c);
		ofstream of;
		of.open("Client.txt" ,ofstream::app);
		if (getLast("ClientLastId.txt") != 0) {
			of << "\n";
		}
		of<<c.get_id() << "-" <<
			c.get_name() << "-" <<
			c.get_password() << "-" <<
			c.get_balance();
		of.close();
		
		of.open("ClientLastId.txt");
		of << c.get_id();
		of.close();
	}
	static void saveEmployee(string fileName, string fileNameLastId, Employee& e) {
		if (fileName == "Employee.txt") {
			VectorEmployee::employees.push_back(e);
		}
		else
		{
			Admin a(e.get_id(), e.get_name(), e.get_password(), e.get_salary());
			VectorAdmin::admins.push_back(a);
		}
		ofstream of;
		of.open(fileName, ofstream::app);
		if (getLast(fileNameLastId) != 0) {
			of << "\n";
		}
		of << e.get_id() << "-" <<
			e.get_name() << "-" <<
			e.get_password() << "-" <<
			e.get_salary();
		of.close();

		of.open(fileNameLastId);
		of << e.get_id();
		of.close();
	}

	static vector<Client> getClients() {
		return VectorClient::clients;
	}
	static vector<Employee> getEmployee() {
		return VectorEmployee::employees;
	}
	static vector<Admin> getAdmin() {
		return VectorAdmin::admins;
	}
	static void clearFile(string fileName, string fileNameLastId) {

		ofstream of;
		of.open(fileName);
		of.clear();
		of.close();
		
		of.open(fileNameLastId);
		of << 0;
		of.close();
	}

};

