#pragma once

#include "Employee.h"

class Teacher : public Employee {
public:
    Teacher() : Employee() {};

    Teacher(string n, int s) : Employee(n, s * 250 * 4) {};

    Teacher(string n, string d, int s) : Employee(n, d, s) {};


    virtual void setSalary(int salary) {
        this->salary = salary * 250 * 4;
    }


    void print() override {
        cout << "Employee name: " << name << endl;
        cout << "Employee division: " << division << endl;
        cout << "Employee position: Teacher - " << position << endl;
        cout << "Employee salary: " << salary << endl;
    }


};
