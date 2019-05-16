#include <iostream>
#include <vector>
#include <fstream>
#include "Assistant.h"
#include "Docent.h"
#include "Engineer.h"
#include "LabAssistant.h"
#include "Professor.h"
#include "SeniorTeacher.h"
#include "IT.h"
#include "Kib.h"
#include "FTI.h"

using namespace std;

void printSeparator() {
    for (int i = 0; i < 100; i++)
        cout << "=";
    cout << endl;
}

void eraseWorker(vector<Employee *> emp, IT &InfT, FTI &Ft, Kib &Ki, int num) {
    if (emp[num - 1]->getDivision() == "Institute of Information Technologies") {
        for (int i = 0; i < InfT.vectorSize(); i++) {
            if (emp[num - 1] == InfT.ptrWorker(i)) {
                InfT.eraseWorker(i);
                break;
            }
        }

    } else if (emp[num - 1]->getDivision() == "Institute of Physics and Technology")
        for (int i = 0; i < Ft.vectorSize(); i++) {
            if (emp[num - 1] == Ft.ptrWorker(i)) {
                Ft.eraseWorker(i);
                break;
            }
        }
    else
        for (int i = 0; i < Ki.vectorSize(); i++) {
            if (emp[num - 1] == Ki.ptrWorker(i)) {
                Ki.eraseWorker(i);
                break;
            }
        }
}

void setDivision(vector<Employee *> &emp, string buff, IT &InfT, FTI &Ft, Kib &Ki) {
    if (buff == "Institute of Information Technologies")
        InfT.add(*(emp.end() - 1));
    else if (buff == "Institute of Physics and Technology")
        Ft.add(*(emp.end() - 1));
    else
        Ki.add(*(emp.end() - 1));
}

//char correctInput(int start, int end){
//    printSeparator();
//    string buff;
//    do {
//        cout << "Choice: ";
//        cin >> buff;
//        if ((buff[0] < start + 48) || (buff[0] > end + 48) || (buff[1] != '\0'))
//        {
//            cout << "Invalid input! Try again." << endl;
//            printSeparator();
//        }
//    } while ((buff[0] < start + 48) || (buff[0] > end + 48) || (buff[1] != '\0'));
//    printSeparator();
//    return buff[0];
//
//}
int correctInput() {
    string buff;
    int n = 0;
    do {
        cout << "Choice: ";
        cin >> buff;
        n = 0;
        for (int i = 0; i < buff.length(); i++) {
            if ((buff[i] > 47) && (buff[i] < 58))
                n++;
        }
        if ((n != buff.length()) || (buff[n] != '\0')) {
            cout << "Invalid input! Try again." << endl;
        }
        printSeparator();

    } while ((n != buff.length()) || (buff[n] != '\0'));
    return stoi(buff);

}

int getClasses(int sal, string pos) {
    if (pos == "Professor")
        return sal / (250 * 4 * 5);
    if (pos == "Docent")
        return sal / (250 * 4 * 4);
    if (pos == "Senior Teacher")
        return sal / (250 * 4 * 3);
    if (pos == "Assistant")
        return sal / (250 * 4 * 2);
    if (pos == "Engineer")
        return sal / (125 * 4 * 5);
    if (pos == "Laboratory Assistant")
        return sal / (125 * 4 * 4);
    return 0;

}


bool readTxt(vector<Employee *> &emp, IT &InfT, FTI &Ft, Kib &Ki) {
    string buff1, buff2, buff3;
    int buffInt1, buffInt2;
    ifstream fin("..\\Employee.txt");
    if (!(fin.is_open())) {
        fin.close();
        ofstream{"..\\Employee.txt", ios_base::out};
        fin.open("..\\Employee.txt");
    }

    if (!(fin.is_open())) {
        cout << "File openning error!" << endl;
        return true;
    }

    fin.seekg(0, ios::end);
    if (fin.tellg() == 0) {
        fin.close();
        return false;
    }
    fin.seekg(0, ios::beg);

    while (!(fin.eof())) {


        getline(fin, buff1, '#');
        fin >> buffInt1;
        fin.ignore();
        fin >> buffInt2;
        fin.ignore();
        getline(fin, buff2, '#');
        fin.ignore();
        switch (buffInt2) {

            case 1: {
                emp.push_back(new Professor(buff1, buff2, buffInt1));
                break;
            }
            case 2: {
                emp.push_back(new Docent(buff1, buff2, buffInt1));
                break;
            }
            case 3: {
                emp.push_back(new SeniorTeacher(buff1, buff2, buffInt1));
                break;
            }
            case 4: {
                emp.push_back(new Assistant(buff1, buff2, buffInt1));
                break;
            }
            case 5: {
                emp.push_back(new Engineer(buff1, buff2, buffInt1));
                break;
            }
            case 6: {
                emp.push_back(new LabAssistant(buff1, buff2, buffInt1));
                break;
            }
        }
        setDivision(emp, buff2, InfT, Ft, Ki);

    }
    fin.close();
    return false;

}

void printEmp(vector<Employee *> emp) {
    cout << "List of the employees: " << endl;
    for (int i = 0; i < emp.size(); i++) {
        cout << i + 1 << ". " << emp[i]->getName() << endl;
    }
    printSeparator();
}


void completeOperation() {
    cout << "Action was successfully completed!" << endl;
    system("pause");
    printSeparator();
}

void changePosition(vector<Employee *> &emp, IT &InfT, FTI &Ft, Kib &Ki, int num) {
    string buff1, buff2;
    int buffInt, buffSwtch;
    buff1 = emp[num - 1]->getName();
    buff2 = emp[num - 1]->getDivision();
    buffInt = getClasses(emp[num - 1]->getSalary(), emp[num - 1]->getPosition());


    eraseWorker(emp, InfT, Ft, Ki, num);
    swap(emp[num - 1], emp[emp.size() - 1]);
    delete emp[emp.size() - 1];
    emp.erase(emp.end() - 1);

    cout << "What kind of employee do you want to set?" << endl;
    cout << "1. Teacher." << endl;
    cout << "2. Teaching support staff." << endl;
    printSeparator();
    do {
        buffSwtch = correctInput();
        if ((buffSwtch < 1) || (buffSwtch > 2)) {
            cout << "Invalid input! Try again." << endl;
        }
    } while ((buffSwtch < 1) || (buffSwtch > 2));
    switch (buffSwtch) {
        case 1: {
            cout << "What position do you want to set?" << endl;
            cout << "1. Professor." << endl;
            cout << "2. Docent." << endl;
            cout << "3. Senior Teacher." << endl;
            cout << "4. Assistant." << endl;
            printSeparator();
            do {
                buffSwtch = correctInput();
                if ((buffSwtch < 1) || (buffSwtch > 4)) {
                    cout << "Invalid input! Try again." << endl;
                }
            } while ((buffSwtch < 1) || (buffSwtch > 4));
            switch (buffSwtch) {
                case 1: {
                    emp.push_back(new Professor(buff1, buffInt));
                    break;
                }
                case 2: {
                    emp.push_back(new Docent(buff1, buffInt));
                    break;
                }
                case 3: {
                    emp.push_back(new SeniorTeacher(buff1, buffInt));
                    break;
                }
                case 4: {
                    emp.push_back(new Assistant(buff1, buffInt));
                    break;
                }
            }
            break;
        }
        case 2: {
            cout << "What position do you want to set?" << endl;
            cout << "1. Engineer." << endl;
            cout << "2. Laboratory Assistant." << endl;
            printSeparator();
            do {
                buffSwtch = correctInput();
                if ((buffSwtch < 1) || (buffSwtch > 2)) {
                    cout << "Invalid input! Try again." << endl;
                }
            } while ((buffSwtch < 1) || (buffSwtch > 2));

            switch (buffSwtch) {
                case 1: {
                    emp.push_back(new Engineer(buff1, buffInt));
                    break;
                }
                case 2: {
                    emp.push_back(new LabAssistant(buff1, buffInt));
                    break;
                }
            }
            break;
        }
    }
    if (buff2 == "Institute of Information Technologies") {
        InfT.add(*(emp.end() - 1));
        emp[emp.size() - 1]->setDivision("Institute of Information Technologies");
    } else if (buff2 == "Institute of Physics and Technology") {
        Ft.add(*(emp.end() - 1));
        emp[emp.size() - 1]->setDivision("Institute of Physics and Technology");
    } else {
        Ki.add(*(emp.end() - 1));
        emp[emp.size() - 1]->setDivision("Institute of Cybernetics");
    }


    swap(emp[num - 1], emp[emp.size() - 1]);

}


void changeDivision(vector<Employee *> emp, IT &InfT, FTI &Ft, Kib &Ki, int num) {
    int buffSwtch;
    eraseWorker(emp, InfT, Ft, Ki, num);
    cout << "What division do you want to set?" << endl;
    cout << "1. Institute of Information Technologies." << endl;
    cout << "2. Institute of Physics and Technology." << endl;
    cout << "3. Institute of Cybernetics." << endl;
    printSeparator();
    do {
        buffSwtch = correctInput();
        if ((buffSwtch < 1) || (buffSwtch > 3)) {
            cout << "Invalid input! Try again." << endl;
        }
    } while ((buffSwtch < 1) || (buffSwtch > 3));
    switch (buffSwtch) {
        case 1: {
            InfT.add(*(emp.begin() + (num - 1)));
            emp[num - 1]->setDivision("Institute of Physics and Technology");
            break;
        }
        case 2: {
            Ft.add(*(emp.begin() + (num - 1)));
            emp[num - 1]->setDivision("Institute of Physics and Technology");
            break;
        }
        case 3: {
            Ki.add(*(emp.begin() + (num - 1)));
            emp[num - 1]->setDivision("Institute of Cybernetics");
            break;
        }
    }


}

void deleteEmp(vector<Employee *> &emp, IT &InfT, FTI &Ft, Kib &Ki, int num) {
    eraseWorker(emp, InfT, Ft, Ki, num);
    delete emp[num - 1];
    emp.erase(emp.begin() + (num - 1));
}

bool isExistPos(vector<Employee *> emp, string pos) {
    int n = 0;
    for (int i = 0; i < emp.size(); i++) {
        if (emp[i]->getPosition() == pos)
            n++;
    }
    if (n == 0)
        return false;
    else
        return true;
}


float averageSalary(vector<Employee *> emp, string pos) {
    int n = 0;
    int sal = 0;
    for (int i = 0; i < emp.size(); i++) {
        if (emp[i]->getPosition() == pos) {
            n++;
            sal += emp[i]->getSalary();
        }
    }
    return float(sal) / n;
}


void writeTxt(vector<Employee *> emp) {
    ofstream fout("../Employee.txt");
    for (int i = 0; i < emp.size(); i++) {
        fout << emp[i]->getName() << "#" << emp[i]->getSalary() << "#";
        if (emp[i]->getPosition() == "Professor")
            fout << "1";
        if (emp[i]->getPosition() == "Docent")
            fout << "2";
        if (emp[i]->getPosition() == "Senior Teacher")
            fout << "3";
        if (emp[i]->getPosition() == "Assistant")
            fout << "4";
        if (emp[i]->getPosition() == "Engineer")
            fout << "5";
        if (emp[i]->getPosition() == "Laboratory Assistant")
            fout << "6";
        fout << "#" << emp[i]->getDivision() << "#";
        if (i != (emp.size() - 1))
            fout << endl;

    }
    fout.close();
}

void deletePtr(vector<Employee *> emp) {
    for (int i = 0; i < emp.size(); i++)
        delete emp[i];
}


bool isExist(vector<Employee *> emp) {
    if (emp.size() == 0)
        return false;
    else
        return true;
}


