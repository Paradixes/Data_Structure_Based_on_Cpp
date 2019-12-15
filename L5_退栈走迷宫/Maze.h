#ifndef MAZE_H
#define MAZE_H
#include "SeqStack.h"
#include <iostream>

struct Intersection {
	int left = 0;
	int forw = 0;
	int right = 0;
	int back = 0;
	int tag = 1;
	int pos = 0;
	friend std::ostream& operator<<(std::ostream& out, const Intersection& o)
	{
		std::cout << o.left << " " << o.forw << " " << o.right << "" << o.back;
		return out;
	}
};

class Maze {
private:
	int MazeSize;
	Intersection* interMaze;
	SeqStack<int>* Stck;
	int curr = 0;
	int NextPos(int Curpos, int direction);
public:
	Maze();
	~Maze() { delete[]interMaze; };
	void TraverseMazeStack(int Entr, int Ext);
	void OutputStack() { std::cout << *Stck << std::ends; }
};

#endif // MAZE_H
