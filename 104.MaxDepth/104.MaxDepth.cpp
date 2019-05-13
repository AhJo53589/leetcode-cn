// 104.MaxDepth.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root)
{
	if (root == NULL) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

void initTree(TreeNode **root, vector<int> initData)
{
	if (initData[0] == 0) return;

	queue<TreeNode *> qTree;
	*root = new TreeNode(initData[0]);
	qTree.push(*root);

	int i = 1;
	while (!qTree.empty())
	{
		TreeNode *qHead = qTree.front();
		qTree.pop();
		if (i == initData.size()) return;
		if (qHead == NULL)
		{
			i += 2;
			continue;
		}

		if (initData[i] == 0)
		{
			qTree.push(NULL);
		}
		else
		{
			(*qHead).left = new TreeNode(initData[i]);
			qTree.push((*qHead).left);
		}
		i++;

		if (i == initData.size()) return;
		if (initData[i] == 0)
		{
			qTree.push(NULL);
		}
		else
		{
			(*qHead).right = new TreeNode(initData[i]);
			qTree.push((*qHead).right);
		}
		i++;
	}
}

void printTreeNode(TreeNode *root)
{
	queue<TreeNode *> qTree;
	qTree.push(root);

	while (!qTree.empty())
	{
		TreeNode *qHead = qTree.front();
		qTree.pop();

		if (qHead == NULL)
		{
			cout << "NULL" << " - ";
			continue;
		}
		cout << qHead->val << " - ";
		qTree.push(qHead->left);
		qTree.push(qHead->right);
	}
}

int main()
{
	int A[] = { 3,9,20,0,0,15,7 };
	vector<int> initData;
	for (int i : A)
	{
		initData.push_back(i);
	}

	TreeNode *root = NULL;
	initTree(&root, initData);
	printTreeNode(root);
	cout << maxDepth(root) << endl;
}
