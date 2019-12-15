#ifndef GENLIST_H
#define GENLIST_H

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
#include <vector>

template<class T>
class GenListNode {
public:
	GenListNode(int state = 0) {
		utype = 0;
		tlink = NULL;
		info.ref = 0;
	}
	GenListNode(GenListNode<T>& RL) {
		utype = RL.utype;
		tlink = RL.tlink;
		info = RL.info;
	}
	~GenListNode() {};
//protected:
	int utype;
	GenListNode<T>* tlink;
	struct information {
		int ref;
		T value;
		GenListNode<T>* hlink;
	}info;
};

template<class T>
struct Items {
	int utype;
	union {
		int ref;
		T value;
		GenListNode<T>* hlink;
	}info;
	Items() {
		utype = 0;
		info.ref = 0;
	}
	Items(Items<T>& RL) { 
		utype = RL.utype;
	}
};

template<class T>
class GenList {
protected:
	GenListNode<T>* first;
	GenListNode<T>* Copy(GenListNode<T>* ls);
	int Length(GenListNode<T>* ls);
	int depth(GenListNode<T>* ls);
	bool equal(GenListNode<T>* s, GenListNode<T>* t);
	void Createlist(std::string &x, GenListNode<T>*& First);
public:
	GenList();
	~GenList();
	void Remove(GenListNode<T>* ls);
	bool Head(Items<T>& x);
	bool Tail(GenList<T>& lt);
	GenListNode<T>* First();
	GenListNode<T>* Next(GenListNode<T>* elem);
	bool operator==(GenList<T>& t);
	GenList<T> operator=(GenList<T>& R);
	int Length();
	int depth();
	GenListNode<T>* deepest();
	void Input(std::string& x);
	friend std::istream& operator >> (std::istream& in, GenList<T>& L) {
		std::string x;
		in >> x;
		L.Createlist(x, L.first);
		return in;
	}
};

#endif // !GENLIST_H

