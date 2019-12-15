#ifndef PRINT_MANAGEMENT
#define PRINT_MANAGEMENT

#include <string>
#include <fstream>
#include "Priority_Queue.h"
#include "Priority_Queue.cpp"

class TypeData
{
protected:
	string name;
	string time;
	string terminal;
	string Size;
	string Status;
public:
	TypeData() {
		//Status = "Preparing";
	}
	friend ostream& operator << (ostream& os, TypeData& s) {
		cout.setf(ios::left);
		os << "Name: " << s.name << "\t";
		os << "Time: " << s.time << "\t";
		os << "Terminal: " << s.terminal << "\t";
		os << "Size: " << s.Size << "\t";
		os << s.Status;
		return os;
	}
	friend istream& operator >> (istream& is, TypeData& s) {
		is >> s.name;
		is >> s.time;
		is >> s.terminal;
		is >> s.Size;
		return is;
	}
	friend ifstream& operator >> (ifstream& fs, TypeData& s) {
		fs >> s.name;
		fs >> s.time;
		fs >> s.terminal;
		fs >> s.Size;
		return fs;
	}
	bool operator==(const string& t);
	bool ChangeStatus(int flag) {
		if (flag == 0)
			Status = "Typing";
		if (flag == 1)
			Status = "Completed";
		return true;
	}
};

class Management
{
protected:
	Priority_queue <TypeData> Data;
public:
	Management() {}
	~Management() {
		Data.makeEmpty();
	}
	bool BoardIn();
	bool FileIn();
	bool Typing();
	bool Search();
	friend ostream& operator << (ostream& os, Management& s){
		os << s.Data;
		return os;
	}
};

#endif // !PRINT_MANAGEMENT