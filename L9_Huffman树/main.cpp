#include "HuffmanTree.h"

using namespace std;

int main()
{
	HuffmanTree test;
	test.EnFile();
	system("cls");
	cout << "Coding Table: " << endl;
	test.Output();
	return 0;
}