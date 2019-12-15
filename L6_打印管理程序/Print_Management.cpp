#include "Print_Management.h"
#include <Windows.h>

bool Management::BoardIn()
{
	int n;
	TypeData temp;

	cout << "The number of the type data you want to input: ";
	cin >> n;
	if (n <= 0)
	{
		cerr << "Wrong number!";
		return false;
	}
	cout << "Name   " << "Time   " << "Terminal   " << "Size" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		Data.Enqueue(temp, n - i);
	}
}

bool Management::Typing()
{
	TypeData Del;
	int n = Data.getSize();

	for (int i = 0; i < n; i++)
	{
		system("cls");
		Data.Dequeue(Del);
		Del.ChangeStatus(0);
		for (int j = 0; j < 2; j++)
		{
			cout << Del << "\n" << Data;
			Sleep(200);
			system("cls");
			cout << Del << "." << "\n" << Data;
			Sleep(200);
			system("cls");
			cout << Del << ".." << "\n" << Data;
			Sleep(200);
			system("cls");
			cout << Del << "..." << "\n" << Data;
			Sleep(200);
			system("cls");
		}
		system("cls");
		Del.ChangeStatus(1);
		cout << Del << "\n" << Data;
		Sleep(500);
	}
	system("cls");
	cout << "Each task has been completed!\n" << endl;
	return true;
}

bool Management::FileIn()
{
	int n;
	TypeData temp;
	string filename;

	cout << "The file you want to open: " << endl;
	cin >> filename;
	ifstream fin;
	fin.open(filename, ios::in);
	if (!fin)
	{
		cerr << "Cannot Open " << filename << endl;
		exit(1);
	}
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> temp;
		Data.Enqueue(temp, n - i);
	}
	fin.close();
}

bool TypeData::operator==(const string& t)
{
	if (t == name || t == time || t == Size || t == terminal)
		return true;
	else return false;
}

bool Management::Search()
{
	string t;
	cout << "Input the keyword you want to search:" << endl;
	cin >> t;
	Data.Locate(t);
	Sleep(2000);
	return true;
}