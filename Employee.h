#pragma once

#include <string>
#include<iostream>

using namespace std;

class Employee {
protected:
    string position;
    string name;
    string division;
    int salary;

public:
    virtual void setSalary(int salary) = 0;

    virtual void print() = 0;

    Employee() {
        position = "default";
        name = "default";
        division = "default";
        salary = -1;
    };

    Employee(string n, int s) : salary(s), name(n) {};

    Employee(string n, string d, int s) : salary(s), division(d), name(n) {};


    void setName(string name) {
        this->name = name;
    }

    void setDivision(string division) {
        this->division = division;
    }

    void setPosition(string position) {
        this->position = position;
    }

    string getName() {
        return name;
    }

    string getDivision() {
        return division;
    }

    string getPosition() {
        return position;
    }

    int getSalary() {
        return salary;
    }
};

