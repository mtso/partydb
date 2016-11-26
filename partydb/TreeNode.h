
#ifndef PARTYDB_TREENODE_H
#define PARTYDB_TREENODE_H

#include "Node.h"

template <typename Data>
class TreeNode //: protected Node<Data>
{
private:
	TreeNode<Data>* left;
	TreeNode<Data>* right;
	Data data;

public:
	TreeNode<Data>(const TreeNode<Data>& original);

	TreeNode<Data>(const Data& new_data, 
		const TreeNode<Data>* new_left = nullptr, 
		const TreeNode<Data>* new_right = nullptr);

	Data getData() const;
	void setData(const Data& new_data);

	TreeNode<Data>* getLeft() const;
	TreeNode<Data>* getRight() const;

	void setLeft(const TreeNode<Data>* new_left);
	void setRight(const TreeNode<Data>* new_right);

};

#ifndef PARTYDB_TREENODE_H
#include "TreeNode.cpp"
#endif

#endif