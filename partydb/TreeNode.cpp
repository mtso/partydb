// TreeNode.cpp
// Lab 4: partydb
// CIS 22C F2016: Matthew Tso

#ifndef PARTYDB_TREENODE_CPP
#define PARTYDB_TREENODE_CPP

#ifndef PARTYDB_TREENODE_H
#include "TreeNode.h"
#endif

template <typename Data>
TreeNode<Data>::TreeNode(const TreeNode<Data>& original)
	: right(original.right)
	, left(original.left)
	, data(original.data)
{
}

template <typename Data>
TreeNode<Data>::TreeNode(const Data& new_data, 
	TreeNode<Data>* new_left,
	TreeNode<Data>* new_right)
	: right(new_right)
	, left(new_left)
	, data(new_data)
{
}

template <typename Data>
bool TreeNode<Data>::isLeaf() const
{
	return right == nullptr && left == nullptr;
}

template <typename Data>
bool TreeNode<Data>::isFull() const
{
	return right != nullptr && left != nullptr;
}

template <typename Data>
Data TreeNode<Data>::getData() const
{
	return data;
}

template <typename Data>
void TreeNode<Data>::setData(const Data& new_data)
{
	data = new_data;
}

template <typename Data>
TreeNode<Data>* TreeNode<Data>::getLeft() const
{
	return left;
}

template <typename Data>
TreeNode<Data>* TreeNode<Data>::getRight() const
{
	return right;
}

template <typename Data>
void TreeNode<Data>::setLeft(TreeNode<Data>* new_left)
{
	left = new_left;
}

template <typename Data>
void TreeNode<Data>::setRight(TreeNode<Data>* new_right)
{
	right = new_right;
}

#endif