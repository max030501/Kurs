#ifndef KURS_SENIORTEACHER_H
#define KURS_SENIORTEACHER_H

#include "Teacher.h"
class SeniorTeacher : public Teacher{
    void setSalary(int salary)override{
        this->salary=salary*2000*4*3;
    }
};
#endif //KURS_SENIORTEACHER_H
