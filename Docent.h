#pragma once
#include "Teacher.h"
class Docent : public Teacher{
public:
    Docent(string n, int s) : Teacher(n, s * 4) {
        position = "Docent";
    };
    Docent(string n,string d, int s) : Teacher(n,d, s) {
        position = "Docent";
    };


    void setSalary(int salary)override{
        Teacher::setSalary(salary);

        this->salary *= 4;
    }
};

