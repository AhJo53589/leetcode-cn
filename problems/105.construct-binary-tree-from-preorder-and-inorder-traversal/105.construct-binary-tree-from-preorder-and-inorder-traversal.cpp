// 105.construct-binary-tree-from-preorder-and-inorder-traversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	if (preorder.size() != inorder.size() || inorder.size() == 0) return nullptr;

	int val = preorder[0];
	bool f = false;
	vector<int> left_inorder;
	vector<int> right_inorder;
	for (auto n : inorder)
	{
		if (n == val) { f = true; continue; }

		if (!f) left_inorder.push_back(n);
		else right_inorder.push_back(n);
	}
	vector<int> left_preorder;
	vector<int> right_preorder;
	for (auto n : preorder)
	{
		if (n == val) continue;
		if (left_inorder.size() > left_preorder.size()) left_preorder.push_back(n);
		else if (right_inorder.size() > right_preorder.size()) right_preorder.push_back(n);
	}

	TreeNode *root = new TreeNode(val);
	root->left = buildTree(left_preorder, left_inorder);
	root->right = buildTree(right_preorder, right_inorder);
	return root;
}

int main()
{
	vector<pair<vector<int>, vector<int>>> N;
	vector<string> A;

	N.push_back({ {3,9,20,15,7}, {9,3,15,20,7} });
	A.push_back("3,9,20,null,null,15,7");

	for (size_t i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		printVectorInt(N[i].first);
		printVectorInt(N[i].second);
		TreeNode *pNode = buildTree(N[i].first, N[i].second);
		cout << "buildTree = " << endl;
		cout << A[i] << endl;
		cout << "my answer = " << endl;
		printTreeNode(pNode);
	}
}