#include "Priority_Queue.h"
#include <iostream>

using namespace std;

template <class T>
Priority_queue<T>::Priority_queue()
{
	first = new LinkNode<T>;
	first->link = NULL;
}

template <class T>
void Priority_queue<T>::makeEmpty()
{
	LinkNode<T>* p;
	while (first->link != NULL) 
	{
		p = first->link;
		first->link = p->link;
		delete p;
	}
}

template <class T>
bool Priority_queue<T>::Dequeue(T& x)
{
	LinkNode<T>* p = Biggest();
	if (p == NULL || p->link == NULL)
		return false;
	LinkNode<T>* del = p->link;
	p->link = del->link;
	x = del->data;
	delete del;
	return true;
}

template <class T>
bool Priority_queue<T>::Enqueue(T& x, int prior)
{
	LinkNode<T>* p = first;
	while (p->link != NULL)
		p = p->link;
	p->link = new LinkNode<T>;
	p->link->data = x;
	p->link->Priority = prior;
	return true;
}

template <class T>
bool Priority_queue<T>::IsEmpty()
{
	if (!getSize())
		return true;
	else
		return false;
}

template <class T>
int Priority_queue<T>::getSize()
{
	LinkNode<T>* p = first;
	int i = 0;
	while (p->link != NULL)
	{
		p = p->link;
		i++;
	}
	return i;
}

template <class T>
bool Priority_queue<T>::Front(T& x)
{
	LinkNode<T>*p = Smallest();
	if (p == NULL)
		return false;
	x = p->data;
	return true;
}

template <class T>
LinkNode<T>* Priority_queue<T>::Smallest()
{
	if (IsEmpty())
		return NULL;
	LinkNode<T>* p = first->link;
	LinkNode<T>* small = p;
	while (p->link != NULL)
	{
		p = p->link;
		if (p->Priority < small->Priority)
			small = p;
	}
	return small;
}

template <class T>
LinkNode<T>* Priority_queue<T>::Biggest()
{
	if (IsEmpty())
		return NULL;
	LinkNode<T>* p = first->link;
	LinkNode<T>* prep = first;
	LinkNode<T>* big = prep;

	while (p->link != NULL)
	{
		prep = p;
		p = p->link;
		if (p->Priority > big->link->Priority)
			big = prep;
	}
	return big;
}

template <class T>
bool Priority_queue<T>::Locate(string& t)
{
	LinkNode<T>* p = first->link;
	while (p != NULL)
	{
		if (p->data == t)
			cout << p->data << endl;
		p = p->link;
	}
	return true;
}