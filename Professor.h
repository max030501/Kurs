#ifndef KURS_PROFESSOR_H
#define KURS_PROFESSOR_H

#include "Teacher.h"
class Professor : public Teacher{
	
public:
	Professor(string n, string p, string d, int s) : Teacher(n, p, d, s * 5) {};
	
    void setSalary(int salary)override{
		Teacher::setSalary(salary);

        this->salary *= 5;
    }
};
#endif //KURS_PROFESSOR_H
