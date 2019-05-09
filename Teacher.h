#ifndef KURS_TEACHER_H
#define KURS_TEACHER_H

#include "Employee.h"
class Teacher : public Employee{
public:
    virtual void setSalary(int salary);
    void print()override{
        cout << division << " - Teacher - "  << position << " - "<< name << endl;
        cout << "Salary : " << salary << endl;
    }


};
#endif //KURS_TEACHER_H
