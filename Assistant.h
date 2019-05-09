#ifndef KURS_ASSISTANT_H
#define KURS_ASSISTANT_H
#include "Teacher.h"
class Assistant : public Teacher{
    void setSalary(int salary)override{
        this->salary=salary*2000*4*2;
    }
};
#endif //KURS_ASSISTANT_H
