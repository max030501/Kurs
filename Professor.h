#ifndef KURS_PROFESSOR_H
#define KURS_PROFESSOR_H

#include "Teacher.h"
class Professor : public Teacher{
    void setSalary(int salary)override{
        this->salary=salary*2000*4*5;
    }
};
#endif //KURS_PROFESSOR_H
