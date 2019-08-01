// 230.kth-smallest-element-in-a-bst.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

void InOrder(TreeNode *root, int &k, int &val)
{
	if (k == 0) return;
	if (root == nullptr) return;
	if (root->left != nullptr) InOrder(root->left, k, val);
	if (k-- == 1) val = root->val;
	if (root->right != nullptr) InOrder(root->right, k, val);
}

int kthSmallest(TreeNode* root, int k)
{
	int val;
	InOrder(root, k, val);
	return val;
}

int main()
{
	vector<TreeNode *> N;
	TreeNode *pHead;
	vector<int> K;

	StringToTreeNode(&pHead, "3,1,4,null,2");
	N.push_back(pHead);
	pHead = nullptr;
	K.push_back(1);

	StringToTreeNode(&pHead, "5,3,6,2,4,null,null,1");
	N.push_back(pHead);
	pHead = nullptr;
	K.push_back(3);

	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		printTreeNode(N[i]);
		cout << "kth Smallest, k = " << K[i] << ", ans = ";
		cout << kthSmallest(N[i], K[i]) << endl;
	}
}