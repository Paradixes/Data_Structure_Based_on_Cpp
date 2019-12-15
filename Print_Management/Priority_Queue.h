#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <string>
#include <cstdlib>
#include <iostream>

template <class T>
struct LinkNode
{
	T data;
	int Priority;
	LinkNode<T>* link;
	LinkNode(LinkNode<T>* prt = NULL) :link(prt) {}
	LinkNode(const T& item, LinkNode<T>* prt = NULL) :data(item), link(prt) {}
};

template <class T>
class Priority_queue
{
protected:
	LinkNode<T>* first;
	LinkNode<T>* Smallest();
	LinkNode<T>* Biggest();
public:
	Priority_queue();
	~Priority_queue() { makeEmpty(); }
	void makeEmpty();
	bool Enqueue(T& x, int prior);
	bool Dequeue(T& x);
	bool IsEmpty();
	bool Front(T& x);
	bool Locate(std::string& t);
	int getSize();
	friend std::ostream& operator << (std::ostream& os, Priority_queue<T>& s) {
		LinkNode<T>* p = s.first->link;
		for(;p != NULL; p = p->link)
			os << p->data << "\n";
		os << "\n";
		return os;
	}
};

#endif // PRIORITY_QUEUE_H
