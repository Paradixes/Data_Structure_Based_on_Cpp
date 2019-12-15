#include "GenList.h"
#include <stack>

using namespace std;

template<class T>
GenList<T>::GenList()
{
	first = new GenListNode<T>;
	assert(first != NULL);
}

template<class T>
bool GenList<T>::Head(Items<T>& x)
{
	if (first->tlink == NULL)
		return false;
	else {
		x.utype = first->tlink->utype;
		x.info = first->tlink->info;
		return true;
	}
}

template<class T>
bool GenList<T>::Tail(GenList<T>& lt)
{
	if (first->tlink == NULL)
		return false;
	else {
		lt.first->utype = 0;
		lt.first->info.ref = 0;
		lt.first->tlink = Copy(first->tlink->tlink);
		return true;
	}
}

template<class T>
GenListNode<T>* GenList<T>::First()
{
	return first->tlink;
}

template<class T>
GenListNode<T>* GenList<T>::Next(GenListNode<T>* elem)
{
	return elem->tlink;
}

template<class T>
GenList<T> GenList<T>::operator=(GenList<T>& R)
{
	R = Copy(R.first);
}


template<class T>
GenListNode<T>* GenList<T>::Copy(GenListNode<T>* ls)
{
	GenListNode<T>* q = NULL;
	if (ls != NULL)
	{
		q = new GenListNode<T>;
		q->utype = ls->utype;
		switch (ls->utype) 
		{
		case 0:q->info.ref = ls->info.ref; break;
		case 1:q->info.value = ls->info.value; break;
		case 2:q->info.hlink = Copy(ls->info.hlink); break;
		}
		q->tlink = Copy(ls->tlink);
	}
	return q;
}

template<class T>
int GenList<T>::Length()
{
	return Length(first);
}

template<class T>
int GenList<T>::Length(GenListNode<T>* ls)
{
	if (ls != NULL)
		return 1 + Length(ls->tlink);
	else return 0;
}

template<class T>
int GenList<T>::depth()
{
	return depth(first);
}

template<class T>
int GenList<T>::depth(GenListNode<T>* ls)
{
	if (ls->tlink == NULL)
		return 1;
	GenListNode<T>* temp = ls->tlink;
	int m = 0, n;
	while (temp != NULL)
	{
		if (temp->utype == 2)
		{
			n = depth(temp->info.hlink);
			if (m < n)
				m = n;
		}
		temp = temp->tlink;
	}
	return m + 1;
}

template<class T>
bool GenList<T>::operator==(GenList<T>& t)
{
	return equal(first, t.first);
}

template<class T>
bool GenList<T>::equal(GenListNode<T>* s, GenListNode<T>* t)
{
	int x;
	if (s->tlink == NULL && t->tlink == NULL)
		return true;
	else if (s->tlink->utype == t->tlink->utype) 
	{
		if (s->tlink->utype == 1)
			x == (s->tlink->info.value == t->tlink->info.value) ? 1 : 0;
		else if (s->tlink->utype == 2)
			x = equal(s->tlink->info.hlink, t->tlink->info.hlink);
		if (x == 1)
			return equal(s->tlink, t->tlink);
	}
	return false;
}

template<class T>
void delvalue(GenListNode<T>* ls, T x)
{
	if (ls->tlink != NULL)
	{
		GenListNode<T>* p = ls->tlink;
		while (p != NULL && (p->utype == 1 && p->info.value == x))
		{
			ls->tlink = p->tlink;
			delete p;
			p = ls->tlink;
		}
		if (p != NULL)
		{
			if (p->utype == 2)
				delvalue(p->info.hlink, x);
			delvalue(p, x);
		}
	}
}

template<class T>
GenList<T>::~GenList()
{
	Remove(first);
}

template<class T>
void GenList<T>::Remove(GenListNode<T>* ls)
{
	ls->info.ref--;
	if (ls->info.ref <= 0)
	{
		GenListNode<T>* q;
		while (ls->tlink != NULL)
		{
			q = ls->tlink;
			if (q->utype == 2)
			{
				Remove(q->info.hlink);
				if (q->info.hlink->info.ref <= 0)
					delete q->info.hlink;
			}
			ls->tlink = q->tlink;
			delete q;
		}
	}
}

template<class T>
void GenList<T>::Createlist(string& x, GenListNode<T>*& first)
{
	int x_Length = x.length();
	stack<GenListNode<T>*> Head;
	GenListNode<T>* ls = first;
	first->utype = 0; first->info.ref = 0;
	for (int i = 0; i < x_Length; i++)
	{
		if (x[i] != '(' && x[i] != ')')
		{
			GenListNode<T>* New = new GenListNode<T>;
			New->utype = 1;
			New->info.value = x[i];
			ls->tlink = New;
			ls = ls->tlink;
		}
		else if (x[i] == '(')
		{
			GenListNode<T>* New = new GenListNode<T>;
			New->utype = 2;
			New->info.hlink = new GenListNode<T>;
			New->info.hlink->utype = 0;
			New->info.hlink->info.ref = 1;
			ls->tlink = New;
			Head.push(New);
			ls = New->info.hlink;
		}
		else if (x[i] == ')' )
		{
			ls = NULL;
			ls = Head.top();
			Head.pop();
		}
	}
}

template<class T>
void GenList<T>::Input(string& x)
{
	Createlist(x, first);
}

template<class T>
GenListNode<T>* GenList<T>::deepest()
{
	stack<GenListNode<T>*> Head;
	int i = 1;
	int dep = depth();
	GenListNode<T>* ls = first;
	while (i < dep)
	{
		ls = ls->tlink;
		if (ls == NULL)
		{
			ls = Head.top();
			Head.pop();
			i--;
		}
		else if (ls->utype == 2) 
		{
			Head.push(ls);
			ls = ls->info.hlink;
			i++;
		}
	}
	return Head.top();
}