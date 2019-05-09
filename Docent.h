#ifndef KURS_DOCENT_H
#define KURS_DOCENT_H
#include "Teacher.h"
class Docent : public Teacher{
    void setSalary(int salary)override{
        this->salary=salary*2000*4*4;
    }
};
#endif //KURS_DOCENT_H
