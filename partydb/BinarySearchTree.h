// BinarySearchTree.h
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#ifndef PARTYDB_BINARYSEARCHTREE_H
#define PARTYDB_BINARYSEARCHTREE_H

#include "TreeNode.h"

template <typename T>
T max(const T& x, const T& y);

template <typename Data>
class BinarySearchTree
{
private:
	TreeNode<Data>* root;

	int node_count;

protected:
	// Helper functions
	// Recursive functions here operate on pointers to parent nodes

	int recursivelyGetHeight(TreeNode<int>* sub_tree) const;

	void deleteTree(TreeNode<Data>* sub_tree);

	TreeNode<Data>* find(const Data& target, TreeNode<Data>* sub_tree) const;

public:

	class NotFoundException
	{
	private:
		char* description;
	public:
		NotFoundException(char* message = "getData() could not find the target.") : description(message) {}
		char* getDescription() const { return description; }
	};

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