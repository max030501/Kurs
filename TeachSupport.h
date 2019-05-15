#pragma once
#include "Employee.h"
class TeachSupport: public Employee{
public:
    TeachSupport() : Employee() {};
    TeachSupport(string n, int s) : Employee(n, s*125*4) {};
    TeachSupport(string n,string d, int s) : Employee(n,d, s) {};

    virtual void setSalary(int salary) {
        this->salary = salary * 125 * 4;
    }
   void print()override {
		cout << "Employee name: " << name << endl;
		cout << "Employee division: " << division << endl;
		cout << "Employee position: Teaching support staff - " << position << endl;
		cout << "Employee salary: " << salary << endl;
	}
};
