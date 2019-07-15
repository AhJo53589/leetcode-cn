// 98.IsValidBST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


bool Inorder(TreeNode *root, int &val, bool &bFirstVal)
{
	if (root == NULL) return true;

	if (!Inorder(root->left, val, bFirstVal)) return false;

	if (!bFirstVal)
	{
		if (!(val < root->val)) return false;
	}
	else
	{
		bFirstVal = false;
	}
	val = root->val;

	if (!Inorder(root->right, val, bFirstVal)) return false;
	return true;
}

bool isValidBST(TreeNode* root)	// 12 ms
{
	int val = 0;
	bool bFirstVal = true;
	return Inorder(root, val, bFirstVal);
}

int main()
{
	//string strInput{ "3,9,20,0,0,15,7" };
	//string strInput{ "2,1,4,0,0,3,6" };
	//string strInput{ "10,5,15,0,0,6,20" };
	string strInput{ 1,1 };
	TreeNode *root = NULL;
	StringToTreeNode(&root, strInput);
	printTreeNode(root);
	cout << endl << isValidBST(root) << endl;
}
