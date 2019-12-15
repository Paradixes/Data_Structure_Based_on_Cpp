#include "DblList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template<class T>
DblList<T>::DblList()
{
	first = new DblNode<T>;
	first->next = first->prev = first;
}

template<class T>
DblList<T>::~DblList()
{
	makeEmpty();
}

template<class T>
void DblList<T>::makeEmpty()
{
	DblNode<T>* p;
	while (first->next != first)
	{
		p = first->next;
		first->next = p->next;
		delete p;
	}
	delete first;
}

template<class T>
DblNode<T>* DblList<T>::Search(const T& x, int& n)
{
	if (x == first->data)
		return first;
	DblNode<T>* current = first->next;
	while (current != first && current->data != x)
		current = current->next;
	if (current != first)
		return current;
	else return ;
}

template<class T>
DblNode<T>* DblList<T>::Locate(T& x, int i, int d)
{
	int n;
	DblNode<T>* current = Search(x, n);
	if (first->next == first || i == 0)
		return first;
	for (int j = 1; j < i; j++)
	{
		if (d == 0)
			current = current->prev;
		else
			current = current->next;
	}
	return current;
}

template<class T>
bool DblList<T>::Remove(int i, T& x, int d)
{
	Move(i, d);
	DblNode<T>* current = first;
	if (current == NULL)
		return false;
	Move(1, d);
	current->next->prev = current->prev;
	current->prev->next = current->next;
	x = current->data;
	delete current;
	return true;
}

template<class T>
int DblList<T>::Length()const
{
	DblNode<T>* current = first->next;
	int count = 0;
	while (current != first)
	{
		current = current->next;
		count++;
	}
	return count;
}

template<class T>
void DblList<T>::Print()
{
	DblNode<T>* current = first;
	do
	{
		cout << current->data << endl;
		current = current->next;
	} while (current != first);
}

template<class T>
bool DblList<T>::Insert(int i, T x, int d, int t)
{
	DblNode<T>* current = Locate(first->data, i, d);
	DblNode<T>* newNode = new DblNode<T>(x);
	if (newNode == NULL)
	{
		cerr << "´æ´¢·ÖÅäÊ§°Ü£¡" << endl;
		exit(1);
	}
	if (t == 0)
	{
		first = newNode;
		first->next = first;
		first->prev = first;
	}
	else if (d == 0 && current != NULL)		//Ç°²å
	{
		newNode->prev = current->prev;
		current->prev = newNode;
		newNode->prev->next = newNode;
		newNode->next = current;
	}
	else if (d == 1 && current != NULL)		//ºó²å
	{
		newNode->next = current->next;
		current->next = newNode;
		newNode->next->prev = newNode;
		newNode->prev = current;
	}
	return true;
}

template<class T>
void DblList<T>::Move(int i, int d)
{
	for (int j = 0; j < i; j++)
	{
		if (d == 0)
			first = first->prev;
		else
			first = first->next;
	}
}