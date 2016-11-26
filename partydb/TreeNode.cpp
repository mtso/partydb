
#include "TreeNode.h"

template <typename Data>
TreeNode<Data>::TreeNode(const TreeNode<Data>& original)
	: right(original.right)
	, left(original.left)
	, data(original.data)
{
}

template <typename Data>
TreeNode<Data>::TreeNode(const Data& new_data, 
	const TreeNode<Data>* new_left, 
	const TreeNode<Data>* new_right)
	: right(new_right)
	, left(new_left)
	, data(new_data)
{
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
void TreeNode<Data>::setLeft(const TreeNode<Data>* new_left)
{
	left = new_left;
}

template <typename Data>
void TreeNode<Data>::setRight(const TreeNode<Data>* new_right)
{
	right = new_right;
}