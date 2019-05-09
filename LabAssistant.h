#ifndef KURS_LABASSISTANT_H
#define KURS_LABASSISTANT_H
#include "TeachSupport.h"
class LabAssistant : public TeachSupport{
    void setSalary(int salary)override{
        this->salary=salary*1000*4*4;
    }
};
#endif //KURS_LABASSISTANT_H
