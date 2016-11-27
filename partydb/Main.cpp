
#include <iostream>
using namespace std;

#include "BinarySearchTree.h"
#include "TreeNode.h"
#include "Person.h"

void print(int& node)
{
	cout << node + node << endl;
}

int main()
{
	BinarySearchTree<int> tree;

	tree.insert(4);
	tree.insert(2);
	tree.insert(6);
	tree.insert(3);

	tree.traverseBreadth(print);
	//tree.traverseInorder(print);
	//tree.traversePreorder(print);
	//tree.traversePostorder(print);

	//tree.contains(6);

	//try {
	//	cout << tree.getData(6) << endl;
	//}
	//catch (...) {
	//	cout << "Not found" << endl;
	//}
	//try {
	//	cout << tree.getData(5) << endl;
	//}
	//catch (BinarySearchTree<int>::NotFoundException error) {
	//	cout << error.getDescription() << endl;
	//}

	//tree.clear();
	//tree.clear();

	//cout << tree.getNodeCount() << endl;

	//Birthdate test_date = Birthdate(11, 13, 1928);
	//string test_name = "Mickey";
	//Person mickey = Person(test_date, test_name);

	//for (int i = -1; i < 10000; i *= -2) {
	//	cout << i << endl;
	//}

	system("pause");
	return 0;
}