// 235.lowest-common-ancestor-of-a-binary-search-tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
	if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
	if (p->val > q->val) return lowestCommonAncestor(root, q, p);
	if (root->val > q->val) return lowestCommonAncestor(root->left, p, q);
	if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);
	return root;
}

int main()
{
	vector<TreeNode *> N;
	TreeNode *pHead;
	vector<pair<TreeNode *, TreeNode *>> K;
	vector<int> A;

	StringToTreeNode(&pHead, "6,2,8,0,4,7,9,null,null,3,5");
	N.push_back(pHead);
	K.push_back(make_pair(FindTreeNode(pHead, 2), FindTreeNode(pHead, 8)));
	A.push_back(6);
	pHead = nullptr;

	StringToTreeNode(&pHead, "6,2,8,0,4,7,9,null,null,3,5");
	N.push_back(pHead);
	K.push_back(make_pair(FindTreeNode(pHead, 2), FindTreeNode(pHead, 4)));
	A.push_back(6);
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