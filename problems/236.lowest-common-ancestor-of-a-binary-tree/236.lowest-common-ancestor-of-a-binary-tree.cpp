// 236.lowest-common-ancestor-of-a-binary-tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

//bool findOne(TreeNode *root, TreeNode *p, TreeNode *q)
//{
//	if (root == nullptr || p == nullptr || q == nullptr) return false;
//	if (root != p && root != q) return findOne(root->left, p, q) || findOne(root->right, p, q);
//	return true;
//}
//
//TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
//{
//	if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
//	if (root != p && root != q)
//	{
//		bool l = findOne(root->left, p, q);
//		bool r = findOne(root->right, p, q);
//		if (l && !r) return lowestCommonAncestor(root->left, p, q);
//		if (!l && r) return lowestCommonAncestor(root->right, p, q);
//	}
//	return root;
//}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root || p == root || q == root) return root;
	TreeNode *left = lowestCommonAncestor(root->left, p, q);
	if (left && left != p && left != q) return left;
	TreeNode *right = lowestCommonAncestor(root->right, p, q);
	if (left && right) return root;
	return left ? left : right;
}

int main()
{
	vector<TreeNode *> N;
	TreeNode *pHead;
	vector<pair<TreeNode *, TreeNode *>> K;
	vector<int> A;

	StringToTreeNode(&pHead, "3,5,1,6,2,0,8,null,null,7,4");
	N.push_back(pHead);
	K.push_back(make_pair(FindTreeNode(pHead, 5), FindTreeNode(pHead, 1)));
	A.push_back(3);
	pHead = nullptr;

	StringToTreeNode(&pHead, "3,5,1,6,2,0,8,null,null,7,4");
	N.push_back(pHead);
	K.push_back(make_pair(FindTreeNode(pHead, 5), FindTreeNode(pHead, 4)));
	A.push_back(5);
	pHead = nullptr;


	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		printTreeNode(N[i]);
		cout << "lowest Common Ancestor = " << A[i] << endl;
		TreeNode *pNode = lowestCommonAncestor(N[i], K[i].first, K[i].second);
		cout << "my answer = " << pNode->val << endl;
	}
}