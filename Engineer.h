#pragma once

#include "TeachSupport.h"

class Engineer : public TeachSupport {
public:
    Engineer(string n, int s) : TeachSupport(n, s * 5) {
        position = "Engineer";
    };

    Engineer(string n, string d, int s) : TeachSupport(n, d, s) {
        position = "Engineer";
    };

    void setSalary(int salary) override {
        TeachSupport::setSalary(salary);

        this->salary *= 5;
    }
};
