#include "stdafx.h"
#include "CppUnitTest.h"

#include "BinarySearchTree.h"
#include "Birthdate.h"

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

			tree.remove(6);
			Assert::AreEqual(2, tree.getNodeCount());
			
			tree.remove(4);
			Assert::AreEqual(1, tree.getNodeCount());
			Assert::AreEqual(2, tree.getRootData());

			tree.clear();
			Assert::IsTrue(tree.isEmpty());
			Assert::AreEqual(0, tree.getHeight());
			Assert::AreEqual(0, tree.getNodeCount());
		}

		TEST_METHOD(ManyRemovals)
		{
			BinarySearchTree<int> tree;

			for(int i = 1; i < 10000; i *= -2) {
				tree.insert(i);
			}
			Assert::AreEqual(14, tree.getNodeCount());

			for (int i = -1; i < 10000; i *= -2) {
				tree.insert(i);
			}
			Assert::AreEqual(29, tree.getNodeCount());

			tree.insert(-4);
			tree.insert(0);
			tree.insert(6);
			tree.insert(10);
			tree.insert(2);
			tree.insert(2);
			Assert::AreEqual(35, tree.getNodeCount());

			tree.remove(1);
			tree.remove(1);
			tree.remove(1);
			Assert::IsFalse(tree.contains(1));
			Assert::AreEqual(2, tree.getRootData());
			Assert::AreEqual(34, tree.getNodeCount());

			tree.remove(2);
			tree.remove(2);
			tree.remove(2);
			Assert::AreEqual(4, tree.getRootData());
			Assert::IsFalse(tree.contains(2));
			Assert::AreEqual(31, tree.getNodeCount());

			tree.remove(4);
			Assert::IsFalse(tree.contains(4));
			Assert::AreEqual(30, tree.getNodeCount());
			Assert::AreEqual(6, tree.getRootData());

			tree.remove(6);
			Assert::IsFalse(tree.contains(6));
			Assert::AreEqual(29, tree.getNodeCount());

			tree.remove(-1);
			Assert::IsFalse(tree.contains(-1));
			Assert::AreEqual(28, tree.getNodeCount());
		}

		TEST_METHOD(Birthdates) {
			BinarySearchTree<Birthdate> birthdays;
			for (int i = 0; i < 10; i++) {
				birthdays.insert(Birthdate(2, i + 1, 1992));
			}

			Assert::AreEqual(10, birthdays.getNodeCount());

			Assert::IsTrue(birthdays.contains(Birthdate(2, 9, 1992)));

			birthdays.remove(Birthdate(2, 9, 1992));
			
			Assert::IsFalse(birthdays.contains(Birthdate(2, 9, 1992)));
		}

		TEST_METHOD(DuplicateValues) {
			BinarySearchTree<int> tree;
			for (int i = 0; i < 20; i++) {
				tree.insert(20);
			}

			Assert::AreEqual(20, tree.getNodeCount());

			for (int i = 0; i < 20; i++) {
				tree.remove(20);
			}
			Assert::AreEqual(0, tree.getNodeCount());
		}
	};
}