// 337.house-robber-iii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
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


//vector<TreeNode *>getAllChild(vector<TreeNode *>pNode)
//{
//	vector<TreeNode *> pChild;
//	if (pNode.empty()) return pChild;
//	for (auto p : pNode)
//	{
//		if (p == NULL) continue;
//		if (p->left != NULL) pChild.push_back(p->left);
//		if (p->right != NULL) pChild.push_back(p->right);
//	}
//	return pChild;
//}
//
//unordered_map<TreeNode *, int> robMemo;
//int rob(TreeNode* pNode)
//{
//	if (pNode == NULL) return 0;
//	if (robMemo.count(pNode)) return robMemo[pNode];
//	int sum = 0;
//
//	// rob this house and prepare rob "child-child" houses
//	sum = pNode->val;
//	vector<TreeNode *> pChild = getAllChild({ pNode });
//	pChild = getAllChild({ pChild });
//	for (auto p : pChild) sum += rob(p);
//
//	// rob "child" houses
//	sum = max(sum, rob(pNode->left) + rob(pNode->right));
//
//	// Memo
//	robMemo[pNode] = sum;
//	return sum;
//}

void PostOrder(TreeNode *root, vector<TreeNode *>&pNodeList)
{
	if (root == NULL) return;
	if (root->left != NULL) PostOrder(root->left, pNodeList);
	if (root->right != NULL) PostOrder(root->right, pNodeList);
	pNodeList.push_back(root);
}

unordered_map<TreeNode *, int> robMemo[2];
int rob(TreeNode* pNode)
{
	if (pNode == NULL) return 0;
	vector<TreeNode *> pNodeList;
	PostOrder(pNode, pNodeList);

	for (auto p : pNodeList)
	{
		int s[2] = { 0,0 };	// 0 == include node val, 1 == not include node val

		s[0] = p->val;
		if (p->left != NULL) s[0] += robMemo[1][p->left];
		if (p->right != NULL) s[0] += robMemo[1][p->right];

		if (p->left != NULL) s[1] += robMemo[0][p->left];
		if (p->right != NULL) s[1] += robMemo[0][p->right];

		s[0] = max(s[0], s[1]);	// copy best val

		robMemo[0][p] = s[0];
		robMemo[1][p] = s[1];
	}
	return robMemo[0][pNode];
}

int main()
{
	vector<string> strInput;
	strInput.push_back("3,2,3,null,3,null,1");	// 7
	strInput.push_back("3,4,5,1,3,null,1");	// 9
	strInput.push_back("3,5,null,null,4,null,1,2");	// 9
	strInput.push_back("2,1,3,null,4");	// 7


	for (string s : strInput)
	{
		cout << "////////////////////////////////////" << endl;
		cout << "Input: " << endl;
		TreeNode *root = NULL;
		StringToTreeNode(&root, s);
		printTreeNode(root);

		//vector<TreeNode *> pNodeList;
		//PostOrder(root, pNodeList);
		//for (auto p : pNodeList)
		//{
		//	cout << p->val << " ";
		//}
		//cout << endl;

		int sum = rob(root);
		cout << endl << "Sum : " << sum << endl << endl;
	}
}
