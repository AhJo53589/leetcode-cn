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
	//TreeNode *root = StringToTreeNode("2,0,31,null,1,25,40,null,null,11,30,34,45,10,18,29,32,null,36,43,46,4,null,12,24,26,null,null,null,35,39,42,44,null,48,3,9,null,14,22,null,null,27,null,null,38,null,41,null,null,null,47,49,null,null,5,null,13,15,21,23,null,28,37,null,null,null,null,null,null,null,null,8,null,null,null,17,19,null,null,null,null,null,null,null,7,null,16,null,null,20,6");
	TreeNode *root = StringToTreeNode(strInput);
	//DrawTreeNode(root);
	cout << root << endl;
	cout << endl << isValidBST(root) << endl;
}
