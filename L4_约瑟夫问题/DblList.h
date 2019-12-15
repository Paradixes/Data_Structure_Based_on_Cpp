#ifndef DBLLIST_H
#define DBLLIST_H
#include <cstdlib>

template <class T> 
struct DblNode
{
	T data;
	DblNode<T>* prev, * next;
	DblNode(DblNode<T> *Left = NULL, DblNode<T>* Right = NULL)
		:prev(Left), next(Right){}
	DblNode(T value, DblNode<T> *Left = NULL, DblNode<T>* Right = NULL)
		:data(value), prev(Left), next(Right){}
};

template <class T>
class DblList
{
	protected:
		DblNode<T>* first;
	public:
		DblList();
		~DblList();
		void makeEmpty();
		bool IsEmpty() { return first->next == first; }
		DblNode<T>* Search(const T& x, int &n);
		DblNode<T>* Locate(T& x, int i, int d);
		bool Remove(int i, T &x, int d);
		int Length()const;
		void Print();
		bool Insert(int i, T x, int d, int t);
		void Move(int i, int d);
};


#endif // DBLLIST_H

