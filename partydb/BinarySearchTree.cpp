// BinarySearchTree.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#ifndef PARTYDB_BINARYSEARCHTREE_CPP
#define PARTYDB_BINARYSEARCHTREE_CPP

#ifndef PARTYDB_BINARYSEARCHTREE_H
#include "BinarySearchTree.h"
#endif

template <typename T>
T max(const T& x, const T& y)
{
	return (x > y) ? x : y;
}

template <typename Data>
BinarySearchTree<Data>::BinarySearchTree()
	: root(nullptr)
	, node_count(0)
{
}

template <typename Data>
BinarySearchTree<Data>::~BinarySearchTree()
{
}

// Protected methods

template <typename Data>
int BinarySearchTree<Data>::recursivelyGetHeight(TreeNode<int>* sub_tree) const
{
	return sub_tree == nullptr ?
		0 : 1 + max(recursivelyGetHeight(sub_tree->getRight()),
		            recursivelyGetHeight(sub_tree->getLeft()));
}

template <typename Data>
void BinarySearchTree<Data>::deleteTree(BinarySearchTree<Data>* sub_tree);

//Public functions

template <typename Data>
bool BinarySearchTree<Data>::isEmpty() const
{
	return root == nullptr;
}

template <typename Data>
int BinarySearchTree<Data>::getHeight() const
{
	return recursivelyGetHeight(root);
}

template <typename Data>
int BinarySearchTree<Data>::getNodeCount() const
{
	return node_count;
}

template <typename Data>
Data BinarySearchTree<Data>::getRootData() const
{
	if (isEmpty()) {
		throw "Empty tree";
	}
	return root->getData();
}

template <typename Data>
void BinarySearchTree<Data>::setRootData(const Data& new_data)
{
	if (root == nullptr) {
		root = new TreeNode<Data>(new_data);
	}
	else {
		root->setData(new_data);
	}
}

template <typename Data>
void BinarySearchTree<Data>::insert(const Data& new_data)
{
	TreeNode<Data>* search = root;

	while (search != nullptr) 
	{
		if (search->getData() > new_data) 
		{
			if (search->getLeft() == nullptr) {
				search->setLeft(new TreeNode<Data>(new_data));
				node_count++;
				return;
			}
			search = search->getLeft();
		}
		else {
			if (search->getRight() == nullptr) {
				search->setRight(new TreeNode<Data>(new_data));
				node_count++;
				return;
			}
			search = search->getRight();
		}
	}
	root = new TreeNode<Data>(new_data);
	node_count++;
}

template <typename Data>
void BinarySearchTree<Data>::remove(const Data& target);

template <typename Data>
void BinarySearchTree<Data>::clear();

template <typename Data>
bool BinarySearchTree<Data>::contains(const Data& target);

template <typename Data>
Data BinarySearchTree<Data>::getData(const Data& target);

#endif