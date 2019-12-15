#ifndef TMYDATELIST_H
#define TMYDATELIST_H
#include<cstdlib>

template <class T>
struct LinkNode 
{
	T data;
	LinkNode<T>* link;
	LinkNode(LinkNode<T>* prt = NULL) { link = prt; }
	LinkNode(const T& item, LinkNode<T>* prt = NULL) { data = item; link == prt; }
};

template <class T>
class TMyDateList 
{
	protected:
		LinkNode<T>* first;
		LinkNode<T>* last;
	public:
		TMyDateList();
		~TMyDateList();
		void makeEmpty();
		int Search(T x);
		LinkNode<T>* Locate(int i);
		bool Insert(int i, T& x);
		bool Remove(int i, T& x);
		int Length();
		void Print();
		void Sort();
};
#endif // TMYDATELIST_H
