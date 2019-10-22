// 104.MaxDepth.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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


int maxDepth(TreeNode* root)
{
	if (root == NULL) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
	TreeNode *root = StringToTreeNode("3,9,20,0,0,15,7");
	DrawTreeNode(root);
	cout << endl << maxDepth(root) << endl;
}
