#pragma once

#include "Teacher.h"

class SeniorTeacher : public Teacher {
public:
    SeniorTeacher(string n, int s) : Teacher(n, s * 3) {
        position = "Senior Teacher";
    };

    SeniorTeacher(string n, string d, int s) : Teacher(n, d, s) {
        position = "Senior Teacher";
    };


    void setSalary(int salary) override {
        Teacher::setSalary(salary);

        this->salary *= 3;
    }
};
