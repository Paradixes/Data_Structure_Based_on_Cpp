#include "LOC.h"
#include <fstream> 

using namespace std;

LOC::LOC()
{
	string filename, line;
	ifstream fin;

	//filename = "test.txt";
	cout << "Please input filename: ";
	cin >> filename;
	fin.open(filename, ios::in);
	if (!fin)
	{
		cerr << "Couldn't open: " + filename;
		exit(1);
	}
	fin >> Row;
	fin >> Line;
	Length = Row * Line;
	Array = new double[Length];
	for (int i = 0; i < Length; i++)
	{
		fin >> *(Array + i);
	}
	fin.close();
}

double LOC::Search(int i, int j)
{
	if (j >= Line || i >= Row)
	{
		cerr << "Overstep the boundary!" << endl;
		return false;
	}
	return *(Array + i * Line + j);
}

double LOC::Max()
{
	double max = *Array;
	for (int i = 0; i < Length; i++)
		if (*(Array + i) > max)
			max = *(Array + i);
	return max;
}

double LOC::Min()
{
	double min = *Array;
	for (int i = 0; i < Length; i++)
		if (*(Array + i) < min)
			min = *(Array + i);
	return min;
}

double LOC::Average()
{
	double Sum = 0.0;
	for (int i = 0; i < Length; i++)
		Sum += *(Array + i);
	return Sum/Length;
}

double LOC::Median()
{
	double median;
	double* Sorted = new double[Length];
	for (int i = 0; i < Length; i++)
		*(Sorted + i) = *(Array + i);
	sort(Sorted, Sorted + Length);

	if (Length % 2 == 0)
		median = *(Sorted + (Length / 2));
	else
		median = (*(Sorted + (Length / 2)) + *(Sorted + (Length / 2 + 1)))/2;
	delete[]Sorted;
	return median;
}

bool LOC::Output()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Line; j++)
		{
			cout << *(Array + i * Line + j) << "\t";
		}
		cout << "\n";
	}
	return 0;
}
