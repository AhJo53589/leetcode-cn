// 94.InorderTraversal.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

#include "..\Common\TreeNode.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> inorderTraversal(TreeNode* root)
{
	vector<int> vRet;
	if (root == NULL) return vRet;

	vector<int> vTemp;
	vTemp = inorderTraversal(root->left);
	vRet.insert(vRet.end(), vTemp.begin(), vTemp.end());
	vRet.push_back(root->val);
	vTemp = inorderTraversal(root->right);
	vRet.insert(vRet.end(), vTemp.begin(), vTemp.end());
	return vRet;
}

void printfVectorInt(vector<int> &nums)
{
	for (int i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	string strInput{ "1,null,2,3" };
	//string strInput{ "1,2,2,null,3,null,3" };
	TreeNode *root = NULL;
	initTree(&root, strInput);
	printTreeNode(root);
	vector<int> v = inorderTraversal(root);
	printfVectorInt(v);
}
