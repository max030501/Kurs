#pragma once
#include "Teacher.h"
class Professor : public Teacher{
	
public:
	Professor(string n, int s) : Teacher(n, s * 5) {
	    position = "Professor";

	};
	Professor(string n,string d, int s ) : Teacher(n,d , s) {
		position = "Professor";

	};
	
    void setSalary(int salary)override{
		Teacher::setSalary(salary);

        this->salary *= 5;
    }

};

