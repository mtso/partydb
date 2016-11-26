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

			tree.clear();
			Assert::IsTrue(tree.isEmpty());
			Assert::AreEqual(0, tree.getHeight());
			Assert::AreEqual(0, tree.getNodeCount());
		}

	};
}