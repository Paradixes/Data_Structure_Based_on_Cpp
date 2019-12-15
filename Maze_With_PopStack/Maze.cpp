#include "Maze.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int Maze::NextPos(int Curpos, int direction)
{
	switch (direction)
	{
	case 0:return interMaze[Curpos].left;
	case 1:return interMaze[Curpos].forw;
	case 2:return interMaze[Curpos].right;
	case 3:return interMaze[Curpos].back;
	default:exit(1);
	}
}

Maze::Maze()
{
	std::string filename = "Maze.txt";
	ifstream fin;
	fin.open(filename, ios::in);
	if (!fin)
	{
		cerr << "Cannot Open Maze File:Maze.txt" << endl;
		exit(1);
	}
	fin >> MazeSize;
	Stck = new SeqStack<int>(MazeSize + 1);
	interMaze = new Intersection[MazeSize + 1];
	for (int i = 1; i <= MazeSize; i++)
	{
		fin >> interMaze[i].left >> interMaze[i].forw >> interMaze[i].right >> interMaze[i].back;
		interMaze[i].tag = 1;
		interMaze[i].pos = i;
	}
	fin.close();
}

void Maze::TraverseMazeStack(int Entr, int Ext)
{
	int dir, next = 0;
	curr = Entr;
	Stck->Push(curr);
	interMaze[curr].tag = 0;
	while (curr != Ext)
	{
		for (dir = 0; dir <= 3; dir++)
		{
			next = NextPos(curr, dir);
			if (next != 0 && interMaze[next].tag != 0)
			{
				Stck->Push(next);
				curr = next;
				interMaze[curr].tag = 0;
				break;
			}
		}
		if (dir == 4)
		{
			interMaze[curr].tag = 0;
			Stck->Pop(curr);
			Stck->getTop(curr);
		}
	}
}
