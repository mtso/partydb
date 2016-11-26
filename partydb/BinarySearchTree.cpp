// BinarySearchTree.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#ifndef PARTYDB_BINARYSEARCHTREE_CPP
#define PARTYDB_BINARYSEARCHTREE_CPP

#ifndef PARTYDB_BINARYSEARCHTREE_H
#include "BinarySearchTree.h"
#endif

// Utility method

template <typename T>
T max(const T& x, const T& y)
{
	return (x > y) ? x : y;
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
void BinarySearchTree<Data>::deleteTree(TreeNode<Data>* sub_tree)
{
	if (sub_tree == nullptr) {
		return;
	}
	else {
		deleteTree(sub_tree->getLeft());
		deleteTree(sub_tree->getRight());

		delete sub_tree;
		sub_tree = nullptr;
		node_count--;
	}
}

template <typename Data>
TreeNode<Data>* BinarySearchTree<Data>::find(const Data& target, TreeNode<Data>* sub_tree) const
{
	if (sub_tree == nullptr) {
		return sub_tree;
	}
	else if (sub_tree->getData() == target) {
		return sub_tree;
	}
	else {
		TreeNode<Data>* left = find(target, sub_tree->getLeft());
		TreeNode<Data>* right = find(target, sub_tree->getRight());
		return (left != nullptr) ? left : right;
	}
}

template <typename Data>
void BinarySearchTree<Data>::inorder(void visit(Data& data), TreeNode<Data>* parent) const
{
	if (parent != nullptr)
	{
		inorder(visit, parent->getLeft());
		Data parent_data = parent->getData();
		visit(parent_data);
		inorder(visit, parent->getRight());
	}
}

template <typename Data>
void BinarySearchTree<Data>::preorder(void visit(Data& data), TreeNode<Data>* parent) const
{
	if (parent != nullptr)
	{
		Data parent_data = parent->getData();
		visit(parent_data);
		preorder(visit, parent->getLeft());
		preorder(visit, parent->getRight());
	}
}

template <typename Data>
void BinarySearchTree<Data>::postorder(void visit(Data& data), TreeNode<Data>* parent) const
{
	if (parent != nullptr)
	{
		postorder(visit, parent->getLeft());
		postorder(visit, parent->getRight());
		Data parent_data = parent->getData();
		visit(parent_data);
	}
}

//Public functions

template <typename Data>
BinarySearchTree<Data>::BinarySearchTree()
	: root(nullptr)
	, node_count(0)
{
}

template <typename Data>
BinarySearchTree<Data>::~BinarySearchTree()
{
	clear();
}

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
void BinarySearchTree<Data>::clear()
{
	deleteTree(root);
	root = nullptr; // Must set this or else it will be junk address.
}

template <typename Data>
bool BinarySearchTree<Data>::contains(const Data& target) 
{
	return find(target, root) != nullptr;
}

template <typename Data>
Data BinarySearchTree<Data>::getData(const Data& target)
{
	TreeNode<Data>* search = find(target, root);
	return (search != nullptr) ? search->getData() : throw NotFoundException();
}

template <typename Data>
void BinarySearchTree<Data>::traverseInorder(void visit(Data& data)) const
{
	inorder(visit, root);
}


template <typename Data>
void BinarySearchTree<Data>::traversePreorder(void visit(Data& data)) const
{
	preorder(visit, root);
}

template <typename Data>
void BinarySearchTree<Data>::traversePostorder(void visit(Data& data)) const
{
	postorder(visit, root);
}

#endif