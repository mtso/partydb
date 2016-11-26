
#include <iostream>
#include "BinarySearchTree.h"

#include "TreeNode.h"

int main()
{
	TreeNode<int>* node_1 = new TreeNode<int>(4);
	TreeNode<int>* node_2 = new TreeNode<int>(3);
	TreeNode<int>* node_3 = new TreeNode<int>(5);

	node_1->setLeft(node_2);
	node_1->setRight(node_3);

	system("pause");
	return 0;
}