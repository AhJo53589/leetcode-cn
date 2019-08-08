// 106.construct-binary-tree-from-inorder-and-postorder-traversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//	if (inorder.empty())
//		return NULL;
//	int i = inorder.size() - 1, j = postorder.size() - 1;
//	stack<TreeNode*> s;
//	TreeNode* t = new TreeNode(postorder[j]);
//	TreeNode *p = NULL;
//	s.push(t);
//	j--;
//	while (j >= 0) {
//		while (!s.empty() && inorder[i] == s.top()->val) {
//			p = s.top();
//			s.pop();
//			i--;
//		}
//		TreeNode* node = new TreeNode(postorder[j]);
//		if (p)
//			p->left = node;
//		else if (!s.empty())
//			s.top()->right = node;
//		s.push(node);
//		p = NULL;
//		j--;
//	}
//	return t;
//}

//////////////////////////////////////////////////////////////////////////
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
	if (inorder.size() != postorder.size() || inorder.size() == 0) return nullptr;

	int val = postorder[postorder.size() - 1];
	bool f = false;
	vector<int> left_inorder;
	vector<int> right_inorder;
	for (auto n : inorder)
	{
		if (n == val) { f = true; continue; }

		if (!f) left_inorder.push_back(n);
		else right_inorder.push_back(n);
	}
	vector<int> left_postorder;
	vector<int> right_postorder;
	for (auto n : postorder)
	{
		if (left_inorder.size() > left_postorder.size()) left_postorder.push_back(n);
		else if (right_inorder.size() > right_postorder.size()) right_postorder.push_back(n);
	}

	TreeNode *root = new TreeNode(val);
	root->left = buildTree(left_inorder, left_postorder);
	root->right = buildTree(right_inorder, right_postorder);
	return root;
}

int main()
{
	vector<pair<vector<int>, vector<int>>> N;
	vector<string> A;

	N.push_back({ {9,3,15,20,7}, {9,15,7,20,3} });
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
