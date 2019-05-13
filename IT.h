#pragma once

#include "Division.h"

class IT : public Division {
protected:
    vector<Employee*> IT_worker;
public:
    IT() : Division(){};
    void add(Employee *worker) override
    {
        IT_worker.push_back(worker);
    }
    float averageSalary() override{
        float n;
        for(int i = 0; i < IT_worker.size();i++)
        {
            n += IT_worker[i]->getSalary();
        }
        if(IT_worker.size() == 0){
            cout << "there aren't any IT workers in the employee list!";
            return 0;
        }
        n = n/(IT_worker.size());
        return n;
    }
    int vectorSize(){
        return IT_worker.size();
    }
    Employee* ptrWorker(int i){
        return IT_worker[i];
    }
    void eraseWorker(int i){
        IT_worker.erase(IT_worker.begin() + i);
    }

    void getWorker(int i){
        IT_worker[i]->print();
    }
};