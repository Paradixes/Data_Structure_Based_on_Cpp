#include <iostream>
#include <string>
#include "TNewDate.h"
#include "TMyDateList.h"
#include "TMyDateList.cpp"

using namespace std;
bool InWeekDay(TMyDateList<TNewDate> & Weekends, TNewDate &Date1, TNewDate &Date2);
bool AddWeekDay(TMyDateList<TNewDate>& Weekends);
bool AddWeekend(TMyDateList<TNewDate>& Weekends, TNewDate& Date1, TNewDate& Date2);
bool Start(TNewDate& Date1, TNewDate& Date2, TMyDateList<TNewDate>& Weekends);
bool Is_WeekDay();


int main()
{
	TMyDateList<TNewDate> Weekends;
	TNewDate Date1, Date2;
	int in = 0, n = 0, alter = 0, out = 1, enter = 0;
	int wrong = 1;

	cout << "This is a time calculator on a daily basis.\n" << endl;
	system("pause");
	system("cls");
	while (out != 0){
		if (enter == 0) {
			system("cls");
			enter = Start(Date1, Date2, Weekends);
			if (enter == 0)
				break;
		}
		system("cls");
		cout << "Please choose the function below" << endl;
		cout << "0. Quit" << endl;
		cout << "1. Come back to the first menu" << endl << "2. Weekdays between two dates" << endl;
		cout << "3. Add weekends" << endl << "4. Add weekdays" << endl << "5. Print weekends" << endl;
		cin >> alter;
		system("cls");
		if (alter == 0)
			break;
		else if (alter == 1) 
			enter = 0;
		else if (alter == 2) 
			cout << "The num of weekdays between that two days is: " << (abs(Date1 - Date2) - Weekends.Length()) << endl;
		else if (alter == 3)
			wrong = AddWeekend(Weekends, Date1, Date2);
		else if (alter == 4)
			wrong = AddWeekDay(Weekends);
		else if (alter == 5) 
			Weekends.Print();
		if (wrong && enter != 0) {
			cout << "\n\nYour operation has succeeded." << endl;
			cout << "If you want to quit, please input 0. Otherwise, press any other number." << endl;
			cin >> out;
		}
		else if (enter != 0) {
			cout << "Wrong operation!\n" << endl;
			system("pause");
			wrong = 1;
			continue;
		}
	}
	return (0);
}

bool InWeekDay(TMyDateList<TNewDate> &Weekends, TNewDate &Date1, TNewDate &Date2) {
	TNewDate Date;
	int i = 0, num;

	cout << "Please input the first date: " << endl;
	Date1.Input();
	cout << "Please input the second date: " << endl;
	Date2.Input();
	if (Date2 < Date1) {
		Date = Date1;
		Date1 = Date2;
		Date2 = Date;
	}
	Date = Date1;
	for (Date + 1; Date < Date2; Date + 1) {
		if (!Date.IsWeekDay()) {
			Weekends.Insert(i, Date);
			i++;
		}
	}
	num = abs(Date1 - Date2) - Weekends.Length();
	cout << "The num of weekdays between that two days is: " << num << endl;
	return (true);
}

bool AddWeekDay(TMyDateList<TNewDate>& Weekends) {
	TNewDate Add;
	int n, confirm;
	cout << "Please input a weekend day you want to change to a weekday: " << endl;
	Add.Input();
	if (Weekends.Search(Add)) {
		cout << "\nif you want to change " << endl;
		cout << Add << "into a weekday, please input 1, otherwise input any other number." << endl;
		cin >> confirm;
		if (confirm == 1) {
			n = Weekends.Search(Add);
			Weekends.Remove(n, Add);
		}
		return (true);
	}
	else {
		cout << "It's not a right date." << endl;
		return (false);
	}
}

bool AddWeekend(TMyDateList<TNewDate>& Weekends, TNewDate& Date1, TNewDate& Date2)
{
	int confirm;
	TNewDate Add;
	cout << "Please input a weekday you want to change to a weekend day: " << endl;
	Add.Input();
	if (Weekends.Search(Add) || !(Add > Date1) || !(Add < Date2)) {
		cout << "It's not a right date." << endl;
		return (false);
	}
	else {
		cout << "\nif you want to change " << endl;
		cout << Add << "into a weekend day, please input 1, otherwise input any other number." << endl;
		cin >> confirm;
		if (confirm == 1)
			Weekends.Insert(0, Add);
		return (true);
	}
}

bool Start(TNewDate& Date1, TNewDate& Date2, TMyDateList<TNewDate>& Weekends)
{
	TNewDate Date;
	int in = 0, n = 0, alter = 0, out = 1;
	int wrong = 0;
	while (out != 0) {
		system("cls");
		cout << "Please choose the function below" << endl;
		cout << "0. Quit" << endl;
		cout << "1. Weekdays between two dates" << endl << "2. Is weekday or weekend" << endl;
		cin >> alter;
		system("cls");
		if (alter == 0)
			return 0;
		if (alter == 1) {
			wrong = InWeekDay(Weekends, Date1, Date2);
			return 1;
		}
		else if (alter == 2)
			wrong = Is_WeekDay();

		if (wrong) {
			cout << "\n\nYour operation has succeeded." << endl;
			cout << "If you want to quit, please input 0. Otherwise, press any other number." << endl;
		}
		else {
			cout << "Wrong operation!\n" << endl;
			system("pause");
			continue;
		}
		cin >> out;
		if (out == 0)
			return 0;
		wrong = 0;
	}
}

bool Is_WeekDay()
{
	TNewDate Date;

	cout << "Please input a date: " << endl;
	Date.Input();
	if (Date.IsWeekDay())
		cout << "This is a weekday." << endl;
	else
		cout << "This is a weekend." << endl;
	return (true);
}
