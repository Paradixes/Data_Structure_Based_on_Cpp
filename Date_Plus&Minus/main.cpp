#include <iostream>
#include "TMyDate.h"
#include <string>

using namespace std;

int main()
{
	string timepoint;
	TMyDate date1(0, 0, 0);
	TMyDate date2(0, 0, 0);
	TMyDate Result(0, 0, 0);
	int alter, count, db;
	cout << "This is a time calculation on a daily basis." << endl
		 << "Please press any key to continue" << endl;
	cin >> timepoint;
	system("cls");
	cout << "Please choose the function below" << endl
		<< "1. Add Days" << endl << "2. Dec Days" << endl
		<< "3. Days Between" << endl << "4. Days to Now" << endl;
	cin >> alter;
	system("cls");
	cout << "Please input the date you want to operate on." << endl
		<< "yyyymmdd: 20190920" << endl;
	date1.Input();
	cout << endl;
	if (alter == 1)
	{
		cout << "Please input the number of days you want to add: ";
		cin >> count;
		Result = date1 + count;
		cout << "\nThe result is: ";
		Result.Print();
	}
	else if (alter == 2)
	{
		cout << "Please input the number of days you want to minus: ";
		cin >> count;
		Result = date1 - count;
		cout << "\nThe result is: ";
		Result.Print();
	}
	else if (alter == 3)
	{
		cout << "Please input another date you want to operate on: ";
		date2.Input();
		db = date1 - date2;
		cout << "\nThe result is: " << db;
	}
	else if (alter == 4)
	{
		db = date1.DaysBetween();
		cout << "\nThe result is: " << db;
	}
	else
		cout << "Please choose the right choice" << endl;
	return 0;
}
