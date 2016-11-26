// BST.h
// Lab 4: partydb
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef PARTYDB_BINARYSEARCHTREE_H
#define PARTYDB_BINARYSEARCHTREE_H

#include "TreeNode.h"

template <typename Data>
class BinarySearchTree
{
private:
	TreeNode<Data>* root;

	int node_count;

public:

	BinarySearchTree();
	~BinarySearchTree();

	bool isEmpty() const;

	int getHeight() const;

	int getNodeCount() const;

	Data getRootData() const;

	void setRootData(const Data& new_data);

	void insert(const Data& new_data);

	void remove(const Data& target);

	void clear();

	bool contains(const Data& target);

	Data getData(const Data& target);

};

#ifndef PARTYDB_BINARYSEARCHTREE_CPP
#include "BinarySearchTree.cpp"
#endif

#endif