#include "stdafx.h"
#include "CppUnitTest.h"

#include "TreeNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace partydbtests
{		
	TEST_CLASS(TreeNodeTests)
	{
	public:
		
		TEST_METHOD(SetLeftRight)
		{
			TreeNode<int>* node_1 = new TreeNode<int>(3);

			TreeNode<int>* node_2 = new TreeNode<int>(4);
			TreeNode<int>* node_3 = new TreeNode<int>(5);

			node_1->setLeft(node_2);
			node_1->setRight(node_3);

			Assert::AreEqual(3, node_1->getData());
			Assert::AreEqual(4, node_1->getLeft()->getData());
			Assert::AreEqual(5, node_1->getRight()->getData());
		}

	};
}