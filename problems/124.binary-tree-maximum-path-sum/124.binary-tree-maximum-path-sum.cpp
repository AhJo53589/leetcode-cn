// 124.binary-tree-maximum-path-sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

int maxPathSum(TreeNode* root, int &val)
{
	if (root == nullptr) return 0;
	int left = maxPathSum(root->left, val);
	int right = maxPathSum(root->right, val);
	int lmr = root->val + max(0, left) + max(0, right);
	int ret = root->val + max(0, max(left, right));
	val = max(val, max(lmr, ret));
	return ret;
}

int maxPathSum(TreeNode* root)
{
	int val = INT_MIN;
	maxPathSum(root, val);
	return val;
}

int main()
{
	vector<TreeNode *> N;
	TreeNode *pHead;
	//vector<int> K;
	vector<int> A;

	StringToTreeNode(&pHead, "-10,9,20,null,null,15,7");
	N.push_back(pHead);
	pHead = nullptr;
	//K.push_back(1);
	A.push_back(42);

	StringToTreeNode(&pHead, "5,4,8,11,null,13,4,7,2,null,null,null,1");
	N.push_back(pHead);
	pHead = nullptr;
	//K.push_back(1);
	A.push_back(48);


	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		printTreeNode(N[i]);
		cout << "max Path Sum = " << A[i] << endl;
		cout << "my answer = " << maxPathSum(N[i]) << endl;
	}
}