// TreeNode.h
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#ifndef PARTYDB_TREENODE_H
#define PARTYDB_TREENODE_H

template <typename Data>
class TreeNode
{
private:
	TreeNode<Data>* left;
	TreeNode<Data>* right;
	Data data;

public:
	TreeNode(const TreeNode<Data>& original);
	TreeNode(const Data& new_data, 
		TreeNode<Data>* new_left = nullptr, 
		TreeNode<Data>* new_right = nullptr);

	bool isLeaf() const;
	bool isFull() const;

	Data getData() const;
	void setData(const Data& new_data);

	TreeNode<Data>* getLeft() const;
	TreeNode<Data>* getRight() const;

	void setLeft(TreeNode<Data>* new_left);
	void setRight(TreeNode<Data>* new_right);
};

#ifndef PARTYDB_TREENODE_CPP
#include "TreeNode.cpp"
#endif

#endif