#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <fstream>

class HuffmanNode {
public:
	char value;
	int key;
	int refer;
	HuffmanNode* leftchild, * rightchild, * parent;
	HuffmanNode() :leftchild(NULL), rightchild(NULL), parent(NULL), refer(0), key(0), value(NULL) {}
	bool operator >= (HuffmanNode& R) { return key >= R.key; }
	bool operator > (HuffmanNode& R) { return key > R.key; }
	bool operator == (HuffmanNode& R) { return key == R.key; }
};

struct cmp
{
	bool operator()(const HuffmanNode* a, const HuffmanNode* b)
	{
		return a->key > b->key;
	}
};

class HuffmanTree
{
public:
	HuffmanTree();
	~HuffmanTree() { DeleteTree(root); }
	void EnFile();
	void Output();
protected:
	//std::string filename;
	HuffmanNode* root;
	std::map<char, std::string> Code;
	std::string Data;
	std::priority_queue<HuffmanNode*, std::vector< HuffmanNode* >, cmp> Freq;
	void Encode();
	void DeleteTree(HuffmanNode* t);
	void MergeTree(HuffmanNode*& ht1, HuffmanNode*& ht2, HuffmanNode*& parent);
	void FileIn();
};

#endif // !HUFFMANTREE_H
