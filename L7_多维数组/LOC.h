#ifndef LOC_H
#define LOC_H

#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include <algorithm>
#include <cstdlib>

class LOC
{
private:
	int Row;
	int Line;
	int Length;
	double* Array;
public:
	LOC();
	~LOC() { delete[]Array; }
	double Search(int i, int j);
	double Max();
	double Min();
	double Average();
	double Median();
	bool Output();
	friend std::ostream& operator << (std::ostream& os, LOC& s) {
		s.Output();
		return os;
	}
};

#endif // !LOC_H

