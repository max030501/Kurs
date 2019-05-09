#ifndef KURS_ENGINEER_H
#define KURS_ENGINEER_H
#include "TeachSupport.h"
class Engineer : public TeachSupport{
    void setSalary(int salary)override{
        this->salary=salary*1000*4*5;
    }
};
#endif //KURS_ENGINEER_H
