
#include <iostream>
using namespace std;

#include "BinarySearchTree.h"
#include "TreeNode.h"

int main()
{
	BinarySearchTree<int> tree;

	tree.insert(4);
	//tree.insert(2);
	//tree.insert(6);

	tree.clear();
	tree.clear();

	cout << tree.getNodeCount() << endl;

	system("pause");
	return 0;
}