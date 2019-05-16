#pragma once

#include "Teacher.h"

class Assistant : public Teacher {
public:
    Assistant(string n, int s) : Teacher(n, s * 2) {
        position = "Assistant";
    };

    Assistant(string n, string d, int s) : Teacher(n, d, s) {
        position = "Assistant";
    };

    void setSalary(int salary) override {
        Teacher::setSalary(salary);

        this->salary *= 2;
    }
};

