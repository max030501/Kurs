#include <vector>
#include <fstream>
#include "Assistant.h"
#include "Docent.h"
#include "Engineer.h"
#include "LabAssistant.h"
#include "Professor.h"
#include "SeniorTeacher.h"

void printSeparator();

int main()
{
	string buff;
	while (true) {
		do {
			cout << "Welcome to the headcount management programm!" << endl << "You can add, change or remove employees, print the list of employees or calculate the average salary for all kinds of employees or divisions." << endl;

			printSeparator();

			cout << "Available actions :" << endl;
			cout << "1. Add employee." << endl;
			cout << "2. Change employee." << endl;
			cout << "3. Remove employee." << endl;
			cout << "4. Print the list of employees." << endl;
			cout << "5. Calculate the average slarary for all kinds of employees or divisions." << endl;
			cout << "6. Exit the programm." << endl;
			printSeparator();
			cout << "Choose action : ";
			cin >> buff;
			if ((buff[0] < '1') || (buff[0] > '6') || (buff[1] != '\0'))
			{
				cout << "Invalid input! Try again." << endl;
				printSeparator();
			}
		} while ((buff[0] < '1') || (buff[0] > '6') || (buff[1] != '\0'));

		switch (buff[0])
		{
		case '1': {
			cin >> buff;
			Teacher prof(buff, buff, buff, 5);
		
			cout << prof.getSalary();
			break;
		}
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			return 0;

		}
	}



	
	system("pause");
	return 0;
}