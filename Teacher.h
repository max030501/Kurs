#ifndef KURS_TEACHER_H
#define KURS_TEACHER_H

#include "Employee.h"
class Teacher : public Employee {
public:
	Teacher() {};

	Teacher(string n, string p, string d, int s) : Employee(n, p, d, s*2000*4) {};


	virtual void setSalary(int salary) {
		this->salary = salary * 2000 * 4;
	}
	

	void print()override {
		cout << division << " - Teacher - " << position << " - " << name << endl;
		cout << "Salary : " << salary << endl;

	}


};
#endif //KURS_TEACHER_H
