#include "SeqStack.h"
#include "Maze.h"
#include <iostream>

using namespace std;

int main()
{
	int Enter, Exit, Out = 1;
	Maze MyMaze;
	while (Out != 0)
	{
		cout << "Enter:" << endl;
		cin >> Enter;
		cout << "Exit:" << endl;
		cin >> Exit;
		MyMaze.TraverseMazeStack(Enter, Exit);
		MyMaze.OutputStack();
		cout << "\nOut or not?(0/1)" << endl;
		cin >> Out;
		system("cls");
	}
	return 0;
}
