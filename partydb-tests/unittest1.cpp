#include "stdafx.h"
#include "CppUnitTest.h"

#include "TreeNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace partydbtests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TreeNode<int>* node_1 = new TreeNode<int>(4);
			TreeNode<int>* node_2 = new TreeNode<int>(3);
			TreeNode<int>* node_3 = new TreeNode<int>(5);

			node_1->setLeft(node_2);
			node_1->setRight(node_3);
			// TODO: Your test code here
			//Assert::Fail(L"test case has not been written");
		}

	};
}