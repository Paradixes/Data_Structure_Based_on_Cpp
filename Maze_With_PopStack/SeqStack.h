#ifndef SEQSTACK_H_INCLUDED
#define SEQSTACK_H_INCLUDED

#include <assert.h>
#include <iostream>

const int stackIncreasement = 20;

template <class T>
class SeqStack
{
public:
	SeqStack(int size);
	~SeqStack() { delete[]elements; }
	void Push(const T& x);
	bool Pop(T& x);
	bool getTop(T& x);
	bool IsEmpty()const { return (top == -1) ? true : false; }
	bool IsFull()const { return (top == maxSize - 1) ? true : false; }
	int getSize()const { return (top + 1); }
	void MakeEmpty() { top = -1; }
	friend std::ostream& operator << (std::ostream& os, SeqStack<T>& s) {
		for (int i = 0; i <= s.top; i++)
			os << i << ":" << s.elements[i] << std::endl;
		return os;
	}

private:
	T* elements;
	int top;
	int maxSize;
	void overflowProcess();
};

template <class T>
SeqStack<T>::SeqStack(int size) :top(-1), maxSize(size)
{
	elements = new T[maxSize];
	assert(elements != NULL);
}

template <class T>
void SeqStack<T>::overflowProcess()
{
	T* newArray = new T[maxSize + stackIncreasement];
	if (newArray = NULL) {
		std::cerr << "ÄÚ´æ·ÖÅäÊ§°Ü£¡" << std::endl;
		exit(1);
	}
	for (int i = 0; i <= top; i++)
		newArray[i] = elements[i];
	maxSize = maxSize + stackIncreasement;
	delete[]elements;
	elements = newArray;
}

template <class T>
void SeqStack<T>::Push(const T& x)
{
	if (IsFull() == true)
		overflowProcess();
	elements[++top] = x;
}

template <class T>
bool SeqStack<T>::Pop(T& x)
{
	if (IsEmpty() == true)
		return false;
	x = elements[top--];
	return true;
}

template <class T>
bool SeqStack<T>::getTop(T& x)
{
	if (IsEmpty() == true)
		return false;
	x = elements[top];
	return true;
}

#endif // !SEQSTACK_H_INCLUDED
