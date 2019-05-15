#pragma once
#include "Division.h"
class FTI : public Division {
protected:
    vector<Employee*> FTI_worker;
public:
    FTI() : Division(){};
    void add(Employee *worker) override
    {
        FTI_worker.push_back(worker);
    }
    float averageSalary() override{
        float n;
        for(int i = 0; i < FTI_worker.size();i++)
        {
            n += FTI_worker[i]->getSalary();
        }

        n = n/(FTI_worker.size());
        return n;
    }
    int vectorSize(){
        return FTI_worker.size();
    }
    Employee* ptrWorker(int i){
        return FTI_worker[i];
    }
    void eraseWorker(int i){
        FTI_worker.erase(FTI_worker.begin() + i);
    }
};