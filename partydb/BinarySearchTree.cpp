
#ifndef PARTYDB_BINARYSEARCHTREE_CPP
#define PARTYDB_BINARYSEARCHTREE_CPP

#ifndef PARTYDB_BINARYSEARCHTREE_H
#include "BinarySearchTree.h"
#endif

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

template <typename Data>
bool BinarySearchTree<Data>::isEmpty() const
{
	return root == nullptr;
}

template <typename Data>
int BinarySearchTree<Data>::getHeight() const;

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
void BinarySearchTree<Data>::setRootData(const Data& new_data);

template <typename Data>
void BinarySearchTree<Data>::insert(const Data& new_data);

template <typename Data>
void BinarySearchTree<Data>::remove(const Data& target);

template <typename Data>
void BinarySearchTree<Data>::clear();

template <typename Data>
bool BinarySearchTree<Data>::contains(const Data& target);

template <typename Data>
Data BinarySearchTree<Data>::getData(const Data& target);

#endif