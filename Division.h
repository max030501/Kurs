#pragma once
#include <vector>
#include "Assistant.h"
#include "Docent.h"
#include "Engineer.h"
#include "LabAssistant.h"
#include "Professor.h"
#include "SeniorTeacher.h"
using namespace std;


class Division
{
public:
    Division(){};

    virtual void add(Employee* worker) = 0;
    virtual float averageSalary() = 0;

};