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


// mirror
bool mirror(TreeNode *l, TreeNode *r)
{
	if (!l && !r) return true;
	if (!l && r) return false;
	if (l && !r) return false;
	if (l->val != r->val) return false;
	return mirror(l->left, r->right) && mirror(l->right, r->left);
}

bool isSymmetric(TreeNode* root)  // 4ms
{
	if (!root) return true;
	return mirror(root->left, root->right);
}
// end

int main()
{
	string strInput{ "1,2,2,3,4,4,3" };
	//string strInput{ "1,2,2,null,3,null,3" };
	TreeNode *root = StringToTreeNode(strInput);
	DrawTreeNode(root);
	cout << endl << isSymmetric(root) << endl;
}
