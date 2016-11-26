
#include <iostream>
using namespace std;

#include "BinarySearchTree.h"
#include "TreeNode.h"

int main()
{
	BinarySearchTree<int> tree;

	tree.insert(4);
	tree.insert(2);
	tree.insert(6);

	tree.contains(6);

	try {
		cout << tree.getData(6) << endl;
	}
	catch (...) {
		cout << "Not found" << endl;
	}
	try {
		cout << tree.getData(5) << endl;
	}
	catch (BinarySearchTree<int>::NotFoundException error) {
		cout << error.getDescription() << endl;
	}

	tree.clear();
	tree.clear();

	cout << tree.getNodeCount() << endl;

	system("pause");
	return 0;
}