#pragma once
#include<vector> 
#include<string>
#include<sstream>
#include<fstream>
#include "Client.h"
#include "Admin.h"

class Parser
{
public:

	static vector<string> split(string line) {
		vector<string> result;
		stringstream ss(line);
		string word;
		char del = '-';
		while (getline(ss, word, del)) {
			result.push_back(word);
		}
		
		return result;
	}

	static Client parses_To_Client(string line) {
		string name, pass;
		int id;
		double balance;
		vector<string> splitLine =  split(line);
		id = stoi(splitLine[0]);
		if (!Validation::validateId(id)) {
			throw invalid_argument("Invalid ID.");
		}
		name = splitLine[1];
		if (!Validation::validateName(name)) {
			throw invalid_argument("Invalid name.");
		}
		pass = splitLine[2];
		if (!Validation::validatePassword(pass)) {
			throw invalid_argument("Invalid Password.");
		}
		balance = stod(splitLine[3]);
		if (!Validation::validatBalance(balance)) {
			throw invalid_argument("ERROR!\n Balance must be at least 1500:\n");
		}
		
		return Client(id, name, pass, balance);
	}
	static Employee parses_To_Employee(string line) {
		string name, pass;
		int id;
		double salary;
		vector<string> splitLine =  split(line);

		id = stoi(splitLine[0]);
		if (!Validation::validateId(id)) {
			throw invalid_argument("Invalid ID.");
		}
		name = splitLine[1];
		if (!Validation::validateName(name)) {
			throw invalid_argument("Invalid name.");
		}
		pass = splitLine[2];
		if (!Validation::validatePassword(pass)) {
			throw invalid_argument("Invalid Password.");
		}
		salary = stod(splitLine[3]);
		if (!Validation::validateSalary(salary)) {
			throw invalid_argument("ERROR!\n Salary must be at least 5000:\n");
		}
		
		return Employee(id, name, pass, salary);
	}
	static Admin parses_To_Admin(string line) {
		string name, pass;
		int id;
		double salary;
		vector<string> splitLine = split(line);

		id = stoi(splitLine[0]);
		if (!Validation::validateId(id)) {
			throw invalid_argument("Invalid ID.");
		}
		name = splitLine[1];
		if (!Validation::validateName(name)) {
			throw invalid_argument("Invalid name.");
		}
		pass = splitLine[2];
		if (!Validation::validatePassword(pass)) {
			throw invalid_argument("Invalid Password.");
		}
		salary = stod(splitLine[3]);
		if (!Validation::validateSalary(salary)) {
			throw invalid_argument("ERROR!\n Salary must be at least 5000:\n");
		}

		
		return Admin(id, name, pass, salary);
	}

};

