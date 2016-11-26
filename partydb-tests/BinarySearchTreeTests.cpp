#include "stdafx.h"
#include "CppUnitTest.h"

#include "BinarySearchTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace partydbtests
{
	TEST_CLASS(BinarySearchTreeTests)
	{
	public:

		TEST_METHOD(Construction)
		{
			BinarySearchTree<int> tree;
			Assert::IsTrue(tree.isEmpty());
			Assert::AreEqual(0, tree.getHeight());

			tree.insert(4);
			Assert::IsFalse(tree.isEmpty());
			Assert::AreEqual(1, tree.getNodeCount());
			Assert::AreEqual(1, tree.getHeight());

			tree.insert(2);
			tree.insert(6);
			Assert::AreEqual(3, tree.getNodeCount());
			Assert::AreEqual(2, tree.getHeight());
			Assert::AreEqual(6, tree.getData(6));

			Assert::IsFalse(tree.contains(5));
			Assert::IsFalse(tree.contains(-1));
			Assert::IsTrue(tree.contains(4));
			Assert::IsTrue(tree.contains(2));
			Assert::IsTrue(tree.contains(6));
			Assert::IsFalse(tree.contains(5));

			try {
				int data = tree.getData(5);
			}
			catch (BinarySearchTree<int>::NotFoundException error) {
				char* expected = "getData() could not find the target.";
				Assert::AreEqual(expected, error.getDescription());
			}

			tree.clear();
			Assert::IsTrue(tree.isEmpty());
			Assert::AreEqual(0, tree.getHeight());
			Assert::AreEqual(0, tree.getNodeCount());
		}

	};
}