#ifndef KURS_TEACHSUPPORT_H
#define KURS_TEACHSUPPORT_H

#include "Employee.h"
class TeachSupport: public Employee{
public:
    virtual void setSalary(int salary) = 0;
    void print()override{
        cout << division << " - Teaching support staff - "  << position << " - "<< name << endl;
        cout << "Salary : " << salary << endl;
    }

};
#endif //KURS_TEACHSUPPORT_H
