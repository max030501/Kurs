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

void printSeparator();
int correctInput(int start, int end);
bool readTxt(vector<Employee*> &emp, IT &InfT, FTI &Ft, Kib &Ki);
void printEmp(vector<Employee*> emp);
void completeOperation();
void changePosition(vector<Employee*> &emp, IT &InfT, FTI &Ft, Kib &Ki, int num);
void setDivision(vector<Employee*> &emp, string buff, IT &InfT, FTI &Ft, Kib &Ki);
int getClasses(int sal, string pos);
void changeDivision(vector<Employee*> emp, IT &InfT, FTI &Ft, Kib &Ki, int num);
void eraseWorker(vector<Employee*> emp, IT &InfT, FTI &Ft, Kib &Ki, int num);
void deleteEmp(vector<Employee*> &emp, IT &InfT, FTI &Ft, Kib &Ki, int num);
float averageSalary(vector<Employee*> emp, string pos);
bool writeTxt(vector<Employee*> emp);
void deletePtr(vector<Employee*> emp);






int main() {
	string buff;
	int buffInt, buffSal;
	vector<Employee *> emp;
	IT InfT;
	FTI Ft;
	Kib Ki;

	if (readTxt(emp, InfT, Ft, Ki)) {
		system("pause");
		return 0;
	}

	while (true) {

		cout << "Welcome to the headcount management programm!" << endl
			 << "You can add, change or remove employees, print the list of employees or calculate the average salary for all kinds of employees or divisions."
			 << endl;

		printSeparator();

		cout << "Available actions :" << endl;
		cout << "1. Add employee." << endl;
		cout << "2. Change employee." << endl;
		cout << "3. Remove employee." << endl;
		cout << "4. Print the full information of employees." << endl;
		cout << "5. Calculate the average slarary for all kinds of employees or divisions." << endl;
		cout << "6. Exit the programm." << endl;


		switch (correctInput(1, 6)) {
			case '1': {
				cout << "Enter the name: ";
				cin.ignore();
				getline(cin, buff);
				printSeparator();
				cout << "Enter the count of working classes per week: ";
				cin >> buffInt;
				printSeparator();
				cout << "What kind of employee do you want to add?" << endl;
				cout << "1. Teacher." << endl;
				cout << "2. Teaching support staff." << endl;
				switch (correctInput(1, 2)) {
					case '1': {
						cout << "What position do you want to add?" << endl;
						cout << "1. Professor." << endl;
						cout << "2. Docent." << endl;
						cout << "3. Senior Teacher." << endl;
						cout << "4. Assistant." << endl;
						switch (correctInput(1, 4)) {
							case '1': {
								emp.push_back(new Professor(buff, buffInt));
								break;
							}
							case '2': {
								emp.push_back(new Docent(buff, buffInt));
								break;
							}
							case '3': {
								emp.push_back(new SeniorTeacher(buff, buffInt));
								break;
							}
							case '4': {
								emp.push_back(new Assistant(buff, buffInt));
								break;
							}
						}
						break;
					}
					case '2': {
						cout << "What position do you want to add?" << endl;
						cout << "1. Engineer." << endl;
						cout << "2. Laboratory Assistant." << endl;
						switch (correctInput(1, 2)) {
							case '1': {
								emp.push_back(new Engineer(buff, buffInt));
								break;
							}
							case '2': {
								emp.push_back(new LabAssistant(buff, buffInt));
								break;
							}
						}
						break;
					}

				}
				cout << "Available divisions: " << endl;
				cout << "1. Institute of Information Technologies" << endl;
				cout << "2. Institute of Physics and Technology" << endl;
				cout << "3. Institute of Cybernetics" << endl;
				switch (correctInput(1, 3)) {
					case '1': {
						emp[emp.size() - 1]->setDivision("Institute of Information Technologies");
						InfT.add(*(emp.end() - 1));
						break;
					}
					case '2': {
						emp[emp.size() - 1]->setDivision("Institute of Physics and Technology");
						Ft.add(*(emp.end() - 1));
						break;
					}
					case '3': {
						emp[emp.size() - 1]->setDivision("Institute of Cybernetics");
						Ki.add(*(emp.end() - 1));
						break;
					}
				}
				completeOperation();
				break;
			}
			case '2': {
				printEmp(emp);
				cout << "Choose employee: ";
				cin >> buffInt;
				printSeparator();
				cout << "Available actions: " << endl;
				cout << "1. Change name." << endl;
				cout << "2. Change salary." << endl;
				cout << "3. Change position." << endl;
				cout << "4. Change division." << endl;
				switch (correctInput(1, 4)) {
					case '1': {
						cin.ignore();
						cout << "Enter the new name: ";
						getline(cin, buff);
						emp[buffInt - 1]->setName(buff);
						completeOperation();
						break;
					}
					case '2': {
						cout << "Enter the new count of working classes per week: ";
						cin >> buffSal;
						emp[buffInt - 1]->setSalary(buffSal);
						completeOperation();
						break;
					}
					case '3': {
						changePosition(emp, InfT, Ft, Ki, buffInt);
						completeOperation();
						break;
					}

					case '4': {
						changeDivision(emp, InfT, Ft, Ki, buffInt);
						completeOperation();
						break;
					}
				}
				break;

			}
			case '3': {
				printEmp(emp);
				cout << "Choose employee: ";
				cin >> buffInt;
				printSeparator();
				deleteEmp(emp, InfT, Ft, Ki, buffInt);
				completeOperation();
				break;

			}
			case '4': {
				printEmp(emp);
				cout << "Choose employee: ";
				cin >> buffInt;
				printSeparator();
				emp[buffInt - 1]->print();
				printSeparator();
				completeOperation();
				break;
			}
			case '5': {
				cout << "1. Average salary for employees." << endl;
				cout << "2. Average salary for divisions." << endl;
				switch (correctInput(1, 2)) {
					case '1': {
						cout << "1. Average salary for professors." << endl;
						cout << "2. Average salary for docents." << endl;
						cout << "3. Average salary for senior teachers." << endl;
						cout << "4. Average salary for assistents." << endl;
						cout << "5. Average salary for engineers." << endl;
						cout << "6. Average salary for laboratory assistants." << endl;
						cout << "7. Average salary for all employees." << endl;
						switch (correctInput(1, 7)) {
							case '1': {
								cout << "Average salary: " << averageSalary(emp, "Professor") << endl;
								break;
							}
							case '2': {
								cout << "Average salary: " << averageSalary(emp, "Docent") << endl;
								break;
							}
							case '3': {
								cout << "Average salary: " << averageSalary(emp, "Senior Teacher") << endl;
								break;
							}
							case '4': {
								cout << "Average salary: " << averageSalary(emp, "Assistant") << endl;
								break;
							}
							case '5': {
								cout << "Average salary: " << averageSalary(emp, "Engineer") << endl;
								break;
							}
							case '6': {
								cout << "Average salary: " << averageSalary(emp, "Laboratory Assistant") << endl;
								break;
							}
							case '7': {
								buffSal = 0;
								for (int i = 0; i < emp.size(); i++)
									buffSal += emp[i]->getSalary();
								if (emp.size() == 0) {
									cout << "Error!" << endl;
									break;
								}
								cout << "Average salary: " << float(buffSal) / emp.size() << endl;
								completeOperation();
								break;
							}
						}

						break;
					}
					case '2': {
						cout << "1. Average salary for Institute of Inforamtion Technologies." << endl;
						cout << "2. Average salary for Institute of Physics and Technology." << endl;
						cout << "3. Average salary for Institute of Cybernetics." << endl;
						switch (correctInput(1, 3)) {
							case '1': {
								cout << "Average salary : " << InfT.averageSalary() << endl;
								break;
							}
							case '2': {
								cout << "Average salary : " << Ft.averageSalary() << endl;
								break;
							}
							case '3': {
								cout << "Average salary : " << Ki.averageSalary() << endl;
								break;
							}
						}
						break;
					}
				}
				break;
			}


			case '6': {
				writeTxt(emp);
				deletePtr(emp);

				return 0;
			}

		}
	}
	system("pause");
	return 0;
}

