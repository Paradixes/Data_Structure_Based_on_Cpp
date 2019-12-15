#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "GenList.cpp"
#include "GenList.h"
#include <cmath>

using namespace std;

class TMyExp
{
private:
	GenList<string>Exp;
	size_t Length;
	double SeqSolve(string& x);
	double RulSolve(string& x);
	string TurnExp(GenListNode<string>* head);
	void Simplify(string& x);
public:
	TMyExp(string& x);
	~TMyExp() {};
	double Solve();
	void Process();
};

TMyExp::TMyExp(string& x)
{
	Length = x.length();
	for (int i = 0; i < Length; i++)
	{
		if (x[i] == ' ')
		{
			x.erase(i, 1);
			Length--;
		}
	}
	Exp.Input(x);
	Length = x.length();
}

double TMyExp::RulSolve(string& x)
{
	while (x.find('/') != string::npos || x.find('*') != string::npos)
	{
		string temp;
		int x_Length = x.length();
		int i, j;
		int opt;
		opt = x.find('/') == string::npos ? x.find('*') : x.find('/');
		for (i = opt - 1; isdigit(x[i]) || x[i] == '.'; i--)
			if (i == 0)
			{
				i = -1;
				break;
			}

		for (j = opt + 2; isdigit(x[j]) || x[j] == '.'; j++)
			if (j == x_Length - 1)
			{
				j = x_Length;
				break;
			}

		temp.assign(x, i + 1, j - i - 1);
		temp = to_string(SeqSolve(temp));
		Simplify(temp);
		x.replace(i + 1, j - i - 1, temp);
		//cout << x << endl;
	}
	return SeqSolve(x);
}

double TMyExp::SeqSolve(string& x)
{
	string num1, num2;
	char opt;
	int i = 0, j = 0;
	double result = 0.0;
	int x_length = x.length();

	for (i = 0; isdigit(x[i]) || x[i] == '.'; i++);
	num1 = x.substr(0, i);
	result = atof(num1.c_str());
	while (i < x_length - 1)
	{
		opt = x[i++];
		for (j = i + 1; (isdigit(x[j]) || x[j] == '.') && j <= x_length; j++);
		num2 = x.substr(i, j - i);

		double fig2 = atof(num2.c_str());

		switch (opt) {
		case'+':result += fig2; break;
		case'-':result -= fig2; break;
		case'*':result *= fig2; break;
		case'/':result /= fig2; break;
		default:cerr << "Wrong input!\n"; break;
		}
		i = j;
	}
	return result;
}

string TMyExp::TurnExp(GenListNode<string>* head)
{
	GenListNode<string>* Start = head->info.hlink->tlink;
	string x;
	while (Start != NULL)
	{
		x += Start->info.value;
		Start = Start->tlink;
	}
	return x;
}

double TMyExp::Solve()
{
	GenListNode<string>*Sub;
	int i = 1;
	double result;
	string Course, Final;
	while (Exp.depth() > 1)
	{
		int x = Exp.depth();
		Sub = Exp.deepest();
		Course = TurnExp(Sub);
		result = RulSolve(Course);
		Exp.Remove(Sub->info.hlink);
		Sub->utype = 1;
		Sub->info.value = to_string(result);
		Simplify(Sub->info.value);
		cout << " = ";
		Process();
	}
	Sub = Exp.First();
	while (Sub != NULL)
	{
		Final += Sub->info.value;
		Sub = Sub->tlink;
	}
	cout << " = ";
	return RulSolve(Final);
}

void TMyExp::Process()
{
	GenListNode<string>* p = Exp.First();
	stack<GenListNode<string>*>Head;
	while (p != NULL || !(Head.empty()))
	{
		if (p == NULL)
		{
			p = Head.top();
			Head.pop();
			cout << ')';
		}
		else if (p->utype == 1)
		{
			cout << p->info.value;
			p = p->tlink;
		}
		else if (p->utype == 2)
		{
			Head.push(p->tlink);
			p = p->info.hlink->tlink;
			cout << '(';
		}
	}
	cout << '\n';
}

void TMyExp::Simplify(string& x)
{
	size_t x_Length = x.length();
	size_t i = 0;
	for (i = x_Length - 1; x[i] == '0'; i--);
	x.erase(i + 1);
}

#endif // !CALCULATOR_H

