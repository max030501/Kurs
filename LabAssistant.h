#pragma once

#include "TeachSupport.h"

class LabAssistant : public TeachSupport {
public:
    LabAssistant(string n, int s) : TeachSupport(n, s * 4) {
        position = "Laboratory Assistant";
    };

    LabAssistant(string n, string d, int s) : TeachSupport(n, d, s) {
        position = "Laboratory Assistant";
    };

    void setSalary(int salary) override {
        TeachSupport::setSalary(salary);

        this->salary *= 4;
    }
};

