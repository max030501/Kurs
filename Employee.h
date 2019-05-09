#ifndef KURS_EMPLOYEE_H
#define KURS_EMPLOYEE_H

#include <string>
#include<iostream>
using namespace std;
class Employee{
protected:
    string position;
    string name;
    string division;
    int salary;
public:
    virtual void setSalary() = 0;
    virtual void print()= 0;
    void setName(string name){
        this->name=name;
    }
    void setDivision(string division){
        this->division=division;
    }
    void setPosition(string position){
        this->position=position;
    }
    string getName(){
        return name;
    }
    string getDivision(){
        return division;
    }
    string getPosition(){
        return position;
    }
    int getSalary(){
        return salary;
    }

};
#endif //KURS_EMPLOYEE_H
