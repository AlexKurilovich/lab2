#include <iostream>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	int choice;
	do
	{
		cout << "1. Работа 1" << endl;
		cout << "2. Работа 2" << endl;
		cout << "3. Работа 3" << endl;
		cout << "4. Работа 4" << endl;
		cout << "5. Выход" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			task1();
			system("cls");
			break;
		case 2:
			task2();
			system("cls");
			break;
		case 3:
			task3();
			system("cls");
			break;
		case 4:
			task4();
			system("cls");
			break;
		default:
			break;
		}

	} while (choice != 5);
}

int count_sym(char* arr) {
	char* ptr = arr;
	while (*ptr != '/0') {
		ptr++;

	}
	return ptr - arr;
}