#include "Calculator.h"

using namespace std;

bool IsExp(string& x);
bool isopt(char& x);

int main()
{
	int alter = 1;
	while (alter != 0)
	{
		system("cls");
		string Exp;
		cout << "Please input an expression you want to calculate:\n" << "   ";
		getline(cin, Exp);
		if (!IsExp(Exp))
		{
			cerr << "Wrong Expression! Input any char to continue" << endl;
			cin >> alter;
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		//Exp = "1 + (2 + 3 * (4 / 2 - 6)) - (2 / (3 + 4 * (32 - 7)) + 5)";
		TMyExp Test(Exp);
		cout << Test.Solve();
		cout << "\nDo you want to continue?(0/1)\n";
		cin >> alter;
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	}
	return 0;
}

bool IsExp(string& x)
{
	size_t x_Length = x.length();
	int n = 0, m = 0;
	for (int i = 0; i < x_Length; i++)
	{
		if (x[i] == '(')
			n++;
		else if (x[i] == ')')
			m++;
	}
	if (n != m)
		return false;

	for (int i = 0; i < x_Length; i++)
	{
		if (!isopt(x[i]) && !isdigit(x[i]) && x[i] != ' ' && x[i] != '.' && x[i] != '(' && x[i] != ')')
			return false;
		else if (isopt(x[i]))
		{
			if (!isdigit(x[i + 1]) && x[i + 1] != '(' && x[i + 1] != ' ' && x[i + 1] != '.')
				return false;
		}
		else if (x[i] == '(')
		{
			if (x[i + 1] != '-' && x[i + 1] != '+' && !isdigit(x[i + 1]) && x[i + 1] != ' ')
				return false;
		}
		else if (x[i] == ')')
		{
			if (i < x_Length - 1)
				if (!isopt(x[i + 1]) && x[i + 1] != ' ' && x[i + 1] != ')')
					return false;
		}
		else if (isdigit(x[i]))
		{
			if (x[i + 1] == '(')
				return false;
		}
		else if (x[i] == '.')
		{
			if (x[i + 1] == '(')
				return false;
			for (int j = i + 1; j < x_Length && isdigit(x[j]) || x[j] == '.'; j++)
				if (x[j] == '.')
					return false;
		}
	}
	return true;
}

bool isopt(char& x)
{
	switch (x)
	{
	case'*':
	case'/':
	case'+':
	case'-':return true;
	default:return false;
	}
}