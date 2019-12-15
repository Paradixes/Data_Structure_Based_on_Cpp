//本程序由visual studio编译（C++11），若其他编译器无法编译通过可查看文件夹中的exe文件
#include <Windows.h>
#include "LOC.h"

using namespace std;

void GetNum(LOC &Data);

int main()
{
	LOC Data;
	int alter, out = 1;
	do {
		system("cls");
		cout << "Please choose the function: " << endl;
		cout << "1. Output" << endl;
		cout << "2. Maximum" << endl;
		cout << "3. Minimum" << endl;
		cout << "4. Median" << endl;
		cout << "5. Average" << endl;
		cout << "6. Search" << endl;
		cin >> alter;
		system("cls");
		if (alter == 0)
			break;
		if (alter == 1)
			cout << "Data: \n" << Data << endl;
		else if (alter == 2)
			cout << "Max: " << Data.Max() << endl;
		else if (alter == 3)
			cout << "Min: " << Data.Min() << endl;
		else if (alter == 4)
			cout << "Median: " << Data.Median() << endl;
		else if (alter == 5)
			cout << "Average: " << Data.Average() << endl;
		else if (alter == 6)
			GetNum(Data);
		else 
		{
			cerr << "Wrong choice!" << endl;
			Sleep(1000);
			continue;
		}
		cout << "Your operation has been completed, do you want to continue?(0/1)" << endl;
		cin >> out;
	} while (out != 0);
	return 0;
}

void GetNum(LOC &Data)
{
	int i, j;
	cout << "Row: ";
	cin >> i;
	cout << "\nLine: ";
	cin >> j;
	cout << Data.Search(i,j) << endl;
}
