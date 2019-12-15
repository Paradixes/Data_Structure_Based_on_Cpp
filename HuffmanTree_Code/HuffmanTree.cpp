#include "HuffmanTree.h"

using namespace std;

void HuffmanTree::FileIn()
{
	string filename;
	string temp;

	cout << "The file you want to open: " << endl;
	cin >> filename;
	ifstream fin;
	fin.open(filename, ios::in);
	if (!fin)
	{
		cerr << "Cannot Open " << filename << endl;
		exit(1);
	}
	while (!fin.eof())
	{
		fin >> temp;
		Data += temp;
		Data += " ";
	}
	fin.close();
}

HuffmanTree::HuffmanTree()
{
	FileIn();
	map<char, int> mp;
	for (auto c : Data)//create map
	{
		mp[c]++;
	}

	priority_queue<HuffmanNode*, vector< HuffmanNode* >, cmp> prt_q;//from map to priority_queue
	for (auto& v : mp)
	{
		HuffmanNode* temp = new HuffmanNode;
		temp->key = v.second;
		temp->value = v.first;
		prt_q.push(temp);
	}
	Freq = prt_q;

	while (prt_q.size() != 1)//from priority_queue to Tree
	{
		HuffmanNode* left = new HuffmanNode;
		HuffmanNode* right = new HuffmanNode;
		HuffmanNode* parent = new HuffmanNode;
		left = prt_q.top();
		prt_q.pop();
		right = prt_q.top();
		prt_q.pop();
		MergeTree(left, right, parent);
		prt_q.push(parent);
	}
	root = prt_q.top();
	prt_q.pop();
	Encode();
}

void HuffmanTree::DeleteTree(HuffmanNode* t)
{
	if (t != NULL)
	{
		DeleteTree(t->leftchild);
		DeleteTree(t->rightchild);
		delete t;
	}
}

void HuffmanTree::MergeTree(HuffmanNode*& left, HuffmanNode*& right, HuffmanNode*& parent)
{
	right->parent = left->parent = parent;
	parent->leftchild = left;
	parent->rightchild = right;
	parent->key = right->key + left->key;
	parent->value = NULL;
}

void HuffmanTree::Encode()
{
	stack<HuffmanNode*>t;
	HuffmanNode* p;
	string t_code;
	t.push(root);
	while (!t.empty())//Preorder Traversal
	{
		p = t.top();
		if (p->leftchild->value == 0 && p->refer == 0)//Left step
		{
			t.push(p->leftchild);
			t_code += "0";
			p->refer = 1;
		}
		else if ((p->leftchild->value != 0 || p->rightchild->value != 0) && p->refer != 2)//Find LeafNode & Encode
		{
			if (p->leftchild->value != 0)//Find left LeafNode & Encode
			{
				Code[p->leftchild->value] = t_code + "0";
			}

			if (p->rightchild->value != 0)//Find right LeafNode & Encode
			{
				Code[p->rightchild->value] = t_code + "1";
				t.pop();//Back step
				if (t.size() != 0)
					t_code.erase(t.size() - 1);
			}
			else//If not find, right step
			{
				t.push(p->rightchild);
				t_code += "1";
			}
			p->refer = 2;
		}
		else if (p->refer == 1)//Right step
		{
			p->refer = 2;
			t.push(p->rightchild);
			t_code += "1";
		}
		else if (p->refer == 2)//Back step
		{
			t.pop();
			if (t.size() != 0)
				t_code.erase(t.size() - 1);
		}
	}
}

void HuffmanTree::Output()
{
	priority_queue<HuffmanNode*, vector< HuffmanNode* >, cmp> temp = Freq;
	while (!temp.empty())
	{
		cout << temp.top()->value << "\t| " << temp.top()->key;
		for (auto v : Code)
		{
			if (v.first == temp.top()->value)
			{
				cout << "\t| " << v.second << endl;
				break;
			}
		}
		temp.pop();
	}
	cout << endl;
}

void HuffmanTree::EnFile()
{
	fstream fstrm;
	fstrm.open("EnCode.txt", ofstream::out | ofstream::trunc);
	if (!fstrm.is_open())
	{
		cerr << "Cannot Open " << "EnCode.txt" << endl;
		exit(1);
	}
	for (auto c : Data)
	{
		for (auto v : Code)
		{
			if (c == v.first)
			{
				fstrm << v.second;
				fstrm << " ";
			}
			else if (c == ' ')
				fstrm << '\n';
		}
	}
}