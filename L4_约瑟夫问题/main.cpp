#include "DblList.h"
#include "DblList.cpp"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int x, n;
	int Num, Interval, Start, Direction;
	DblList<int> children;

	int alter = 1;
	cout << "This is a system to solve Josephus problem." << endl;
	system("pause");
	system("cls");

	while (alter != 0)
	{
		cout << "Num: ";
		cin >> Num;
		cout << endl << "Interval: ";
		cin >> Interval;
		cout << endl << "Start: ";
		cin >> Start;
		cout << endl << "Direction(anticlock: 0, clock: 1): ";
		cin >> Direction;
		cout << endl;
		for (int i = 0, t = 0; i < Num; i++, t++)
			children.Insert(i, i + 1, 1, t);

		children.Move(Start - 1, 1);

		for (int j = 0; j < Num - 1; j++)
		{
			children.Remove(Interval - 1, x, Direction);
			cout << "[" << j + 1 << "]" << x << "\n";
		}
		cout << endl;
		cout << "The last one is: ";
		children.Print();
		cout << "If you want to get out, please press 0.\n";
		cin >> alter;
		system("cls");
	}
	return 0;
}