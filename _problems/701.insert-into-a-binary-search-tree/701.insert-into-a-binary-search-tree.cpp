// 701.insert-into-a-binary-search-tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;


//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
TreeNode* insertIntoBST(TreeNode* root, int val)
{
	TreeNode *pNode = root;
	while (pNode != nullptr)
	{
		if (val == pNode->val) return root;
		if (val < pNode->val)
		{
			if (pNode->left == nullptr) pNode->left = new TreeNode(val);
			pNode = pNode->left;
		}
		else
		{
			if (pNode->right == nullptr) pNode->right = new TreeNode(val);
			pNode = pNode->right;
		}
	}
	return root;
}


int main()
{
	vector<TreeNode *> N;
	vector<int> K;
	vector<TreeNode *> A;

	N.push_back(StringToTreeNode("4,2,7,1,3"));
	K.push_back(5);
	A.push_back(StringToTreeNode("4,2,7,1,3,5"));

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		cout << N[i] << endl;
		DrawTreeNode(N[i]);

		TreeNode *ans = insertIntoBST(N[i], K[i]);
		cout << "insertIntoBST = " << A[i] << endl;
		cout << "My answer = " << ans << endl;
		DrawTreeNode(ans);

	}
}