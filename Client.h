#pragma once
#include "Person.h"
#include <exception>
class Client :
    public Person
{
	double balance;
public:
	//con.pra
	Client(int id,string name,string password,double balance)
		:Person(id,name,password)
	{
		set_balance(balance);
	}
	//set
	void set_balance(double balance) {
		if (!Validation::validatBalance(balance)) {
			throw invalid_argument("ERROR!\n Balance must be at least 1500:\n");
		}
		this->balance = balance;
	}
	
	double get_balance() { return balance; }

	bool deposit(double amount) {
		if (!Validation::validatAmount(amount))
		{
			throw invalid_argument("Error: Invalid  amount. (amount > 0)\n");
		}
		balance += amount;
		return true;
	}
	bool withdrow(double amount) {
		if (!Validation::validatAmount(amount))
		{
			throw invalid_argument("Error: Invalid  amount. (amount > 0)\n");
			
		}
		if (Validation::validatWithdrow(amount,balance))
		{
			balance -= amount;
			return true ;
		}
		else { throw invalid_argument("ERROR! Not enough funds to complete the  withdrow.\n"); }

	}
	bool transferTo(double amount, Client& recipient) {
		if (!Validation::validatAmount(amount))
		{
			throw invalid_argument("Error: Invalid  amount. (amount > 0)\n");
		}
		if (withdrow(amount)) {
			recipient.deposit(amount);
			return true;
		}
		else {
			throw invalid_argument("ERROR! Not enough funds to complete the transfer.\n");
		}
	}
	void checkBalance() {
		cout << "Current Balance: " << balance << endl;
	}
	void display_info() {
		Person::display_info();
		cout << "balance: " << get_balance() << endl;
	}
};

