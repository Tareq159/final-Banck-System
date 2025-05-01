#pragma once
#include "Employee.h"
#include "VectorEmployee.h"
class Admin :
    public Employee
{
public:
    
    Admin(int id, string name, string password, double salary) 
        :Employee(id, name, password,salary)
    {
    }
    void addEmployee(Employee& e) {
        VectorEmployee::employees.push_back(e);
        int id;
        ifstream input;
        input.open("EmployeeLastId.txt");
        input >> id;
        input.close();

        ofstream of;
        of.open("Employee.txt", ofstream::app);
        if (id != 0) {
            of << "\n";
        }
        of << e.get_id() << "-" <<
            e.get_name() << "-" <<
            e.get_password() << "-" <<
            e.get_salary();
        of.close();

        of.open("EmployeeLastId.txt");
        of << e.get_id();
        of.close();
        cout << "Employee added successfully!\n";
    }

    Employee* searchEmployee(int id) {
        auto& e = VectorEmployee::employees;
        for (auto& employee : e) {
            if (employee.get_id() == id) {
                return &employee;
            }
        }
        return nullptr;
    }

    void listEmployee() {
        if (VectorEmployee::employees.empty()) {
            cout << "No Employees found.\n";
            return;
        }
        for (auto& employee : VectorEmployee::employees) {
            employee.display_info();
        }
    }

    void editEmployee(int id, string name, string password, double salary) {
        Employee* employee = searchEmployee(id);
        if (employee) {
            employee->set_name(name);
            employee->set_password(password);
            employee->set_salary(salary);
            cout << "Employee updated successfully!\n";
        }
        else {
            cout << "Employee not found!\n";
        }
        ofstream of;
        of.open("Employee.txt");
        of.clear();
        of.close();

        of.open("Employee.txt", ofstream::app);
        for (auto& e : VectorEmployee::employees) {
            if (e.get_id() != 1) {
                of << "\n";
            }
            of << e.get_id() << "-" <<
                e.get_name() << "-" <<
                e.get_password() << "-" <<
                e.get_salary();

        }
        of.close();
    }
};

