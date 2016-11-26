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
	/** Pointer to the root node */
	TreeNode<Data>* root;

	/** 
	 * number of nodes that is:
	 * incremented by insert() 
	 * decremented by remove(), clear(), deleteTree()
	 */
	int node_count;

protected:
	// Helper functions
	// Recursive functions here operate on pointers to sub_trees through their parent nodes

	/**
	 * Returns the height of the tree, 
	 * each node that is not nullptr increments the result of their branch
	 */
	int recursivelyGetHeight(TreeNode<int>* sub_tree) const;

	/**
	 * Deletes a subtree
	 */
	void deleteTree(TreeNode<Data>* sub_tree);
	
	/**
	 * Searches for a node with data that matches its target
	 * @param target `Data` to match
	 * @param sub_tree parent node pointer
	 */
	TreeNode<Data>* find(const Data& target, TreeNode<Data>* sub_tree) const;

public:

	/**
	 * Thrown by getData() and remove() when find(target,sub_tree) cannot find the target.
	 */
	class NotFoundException
	{
	private:
		char* description;
	public:
		NotFoundException(char* message = "getData() could not find the target.") : description(message) {}
		char* getDescription() const { return description; }
	};

	/**
	 * Initializes root to nullptr and node_count to 0
	 */
	BinarySearchTree();

	/**
	 * clears the tree upon deconstruction
	 */
	~BinarySearchTree();

	/**
	 * True if the tree contains no nodes
	 * Returns root == nullptr
	 */
	bool isEmpty() const;

	/**
	 * Returns the tree height
	 */
	int getHeight() const;

	/**
	 * Returns node_count
	 */
	int getNodeCount() const;

	/**
	 * Returns the root's data
	 */
	Data getRootData() const;

	/**
	 * Set's root's data
	 */
	void setRootData(const Data& new_data);

	/**
	 * Inserts a new node into the tree
	 */
	void insert(const Data& new_data);

	/**
	 * TODO: Searches for a node with data that matches the target
	 * and then removes the node.
	 */
	void remove(const Data& target);

	/**
	 * Recursively deletes nodes from the tree
	 */
	void clear();

	/**
	 * True if the tree contains a node with data that matches the target
	 */
	bool contains(const Data& target);

	/**
	 * Returns the found node's data
	 */
	Data getData(const Data& target);
};

#ifndef PARTYDB_BINARYSEARCHTREE_CPP
#include "BinarySearchTree.cpp"
#endif

#endif