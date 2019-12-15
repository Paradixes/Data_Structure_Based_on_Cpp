#include "Print_Management.h"
#include "Priority_Queue.h"

#include <Windows.h>

int main()
{
	int quit = 1, alter, alter2 = 2;
	while (quit)
	{
		Management Data;
		cout << "Please choose the path of the data:" << endl;
		cout << "1. Keyboard\n" << "2. File" << endl;
		cin >> alter;
		system("cls");
		if (alter == 1)
			Data.BoardIn();
		else if (alter == 2)
			Data.FileIn();
		else if (alter != 1 && alter != 2)
		{
			cout << "Wrong choice!" << endl;
			Sleep(1000);
			system("cls");
			continue;
		}
		while (alter2 != 1)
		{
			system("cls");
			cout << "Choose the function below" << endl;
			cout << "1. Type\n" << "2. Search" << endl;
			cin >> alter2;
			system("cls");
			if (alter2 == 1)
				Data.Typing();
			else if (alter2 == 2)
				Data.Search();
		}
		cout << "Do you want to continue or quit?(1/0)" << endl;
		cin >> quit;
		system("cls");
	}
	Management a;

	return 0;
}
