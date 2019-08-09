﻿// 94.binary-tree-inorder-traversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
vector<int> inorderTraversal(TreeNode* root)
{
	if (root == nullptr) return {};
	vector<int> ret;
	vector<int> left;
	vector<int> right;

	if (root->left != nullptr) left = inorderTraversal(root->left);
	ret.insert(ret.end(), left.begin(), left.end());
	ret.push_back(root->val);
	if (root->right != nullptr) right = inorderTraversal(root->right);
	ret.insert(ret.end(), right.begin(), right.end());
	return ret;
}

int main()
{
	vector<TreeNode *> N;
	vector<vector<int>> A;
	TreeNode *pHead = nullptr;

	pHead = StringToTreeNode("1,null,2,3");
	N.push_back(pHead);
	A.push_back({ 1,3,2 });
	pHead = nullptr;


	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		DrawTreeNode(N[i]);
		cout << "inorderTraversal = " << endl;
		printVectorInt(A[i]);
		vector<int> ans = inorderTraversal(N[i]);
		cout << "my answer = " << endl;
		printVectorInt(ans);
	}
}