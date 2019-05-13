#pragma once
#include "Division.h"
class Kib : public Division {
protected:
    vector<Employee*> Kib_worker;

public:
    Kib() : Division(){};
    void add(Employee *worker) override
    {
        Kib_worker.push_back(worker);
    }
    float averageSalary() override{
        float n;
        for(int i = 0; i < Kib_worker.size();i++)
        {
            n += Kib_worker[i]->getSalary();
        }
        if(Kib_worker.size() == 0){
            cout << "there aren't any Kib workers in the employee list!";
            return 0;
        }
        n = n/(Kib_worker.size());
        return n;
    }
    int vectorSize(){
        return Kib_worker.size();
    }
    Employee* ptrWorker(int i){
        return Kib_worker[i];
    }
    void eraseWorker(int i){
        Kib_worker.erase(Kib_worker.begin() + i);
    }
};