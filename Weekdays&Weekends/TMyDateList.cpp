#include "TMyDateList.h"
#include "TNewDate.h"
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
TMyDateList<T>::TMyDateList()
{
	first = new LinkNode<T>;
	first->link = NULL;
	last = first;
}

template <class T>
TMyDateList<T>::~TMyDateList()
{
	makeEmpty();
}

template <class T>
void TMyDateList<T>::makeEmpty()
{
	LinkNode<T>* p;
	while (first->link != NULL){
		p = first->link;
		first->link = p->link;
		delete p;
	}
}

template <class T>
LinkNode<T>* TMyDateList<T>::Locate(int i)
{
	if (i < 0)
		return NULL;
	LinkNode<T>* current = first;
	for (int k = 0; k < i && current != NULL; k++)
		current = current->link;
	return current;
}

template <class T>
int TMyDateList<T>::Search(T x)
{
	LinkNode<T>* current = first->link;
	int i = 1;
	while (current != NULL && !(current->data == x)) {
		current = current->link;
		i++;
	}
	if (current == NULL)
		return 0;
	else return i;
}

template <class T>
bool TMyDateList<T>::Insert(int i, T& x)
{
		LinkNode<T>* current = Locate(i);
		if (current == NULL)
			return (false);
		LinkNode<T>* newNode = new LinkNode<T>(x);
		if (newNode == NULL) {
			cerr << "Memory allocation error.";
			exit(1);
		}
		newNode->link = current->link;
		current->link = newNode;
	return (true);
}

template <class T>
bool TMyDateList<T>::Remove(int i, T& x)
{
	LinkNode<T>* current = Locate(i - 1);
	if (current == NULL || current->link == NULL)
		return (false);
	LinkNode<T>* del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
	return(true);
}

template <class T>
int TMyDateList<T>::Length()
{
	int n = 0;
	LinkNode<T>* current = first->link;
	while (current != NULL) {
		current = current->link;
		n++;
	}
	return n;
}

template <class T>
void TMyDateList<T>::Print()
{
	LinkNode<T>* current = first->link;
	while (current != NULL) {
		cout << current->data;
		current = current->link;
	}
}

template <class T>
void TMyDateList<T>::Sort() {
	LinkNode<T>* current = first->link, *temp = first->link;
	int i = 0;
	while (current->data > temp->link->data || temp->link = NULL) {
		temp = temp->link;
		i++;
	}
	first->link = current->link;
	Insert(i, current->data);
	delete current;
}
