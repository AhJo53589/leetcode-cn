// 101.IsSymmetric.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "..\Common\TreeNode.h"
using namespace std;


vector<TreeNode_Val> getTreeVal(TreeNode *root, bool isLeftTree)
{
	vector<TreeNode_Val> vecVal;
	if (root == NULL) return vecVal;

	queue<TreeNode *> qTree;
	qTree.push(root);
	while (!qTree.empty())
	{
		TreeNode *qHead = qTree.front();
		qTree.pop();

		if (qHead == NULL)
		{
			vecVal.push_back(TreeNode_Val(true));
			continue;
		}
		vecVal.push_back(TreeNode_Val(qHead->val));

		if (isLeftTree)
		{
			qTree.push(qHead->left);
			qTree.push(qHead->right);
		}
		else
		{
			qTree.push(qHead->right);
			qTree.push(qHead->left);
		}
	}
	return vecVal;
}

bool isSymmetric(TreeNode* root) // 8ms
{
	if (root == NULL) return true;

	vector<TreeNode_Val> vecLeft = getTreeVal(root, true);
	vector<TreeNode_Val> vecRight = getTreeVal(root, false);

	int iLen = vecLeft.size();
	if (iLen != vecRight.size()) return false;

	for (int i = 0; i < iLen; i++)
	{
		if (vecLeft[i].isNull != vecRight[i].isNull) return false;
		if (vecLeft[i].val != vecRight[i].val) return false;
	}
	return true;
}

//// mirror
//bool mirror(TreeNode *l, TreeNode *r)
//{
//	if (!l && !r) return true;
//	if (!l && r) return false;
//	if (l && !r) return false;
//	if (l->val != r->val) return false;
//	return mirror(l->left, r->right) && mirror(l->right, r->left);
//}
//
//bool isSymmetric(TreeNode* root)  // 4ms
//{
//	if (!root) return true;
//	return mirror(root->left, root->right);
//}
//// end

int main()
{
	string strInput{ "1,2,2,3,4,4,3" };
	//string strInput{ "1,2,2,null,3,null,3" };
	TreeNode *root = NULL;
	initTree(&root, strInput);
	printTreeNode(root);
	cout << endl << isSymmetric(root) << endl;
}
