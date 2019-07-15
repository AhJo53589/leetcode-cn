// 102.LevelOrder.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

vector<vector<int>> levelOrder_single(queue<TreeNode *> qTree)
{
	vector<vector<int>> result;
	vector<int> vecValue;
	queue<TreeNode *> qTreeNextLevel;
	while (!qTree.empty())
	{
		TreeNode *pNode = qTree.front();
		qTree.pop();

		if (pNode == NULL) continue;

		vecValue.push_back(pNode->val);

		qTreeNextLevel.push(pNode->left);
		qTreeNextLevel.push(pNode->right);
	}

	if (!qTreeNextLevel.empty())
	{
		result = levelOrder_single(qTreeNextLevel);
	}
	if (!vecValue.empty())
	{
		result.insert(result.begin(), vecValue);
	}
	return result;
}

vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	if (root == NULL) return result;

	queue<TreeNode *> qTree;
	qTree.push(root);

	result = levelOrder_single(qTree);
	return result;
}

//vector<vector<int>> levelOrder(TreeNode* root) // 4ms
//{
//	vector<vector<int> >res;
//	if (root == NULL)
//		return res;
//	queue<TreeNode*> que;
//	TreeNode*p;
//	que.push(root);
//	int level = 0;
//	while (!que.empty())
//	{
//		res.push_back(vector<int>());
//		int len = que.size();
//		while (len--)
//		{
//			p = que.front();
//			que.pop();
//			res[level].push_back(p->val);
//			if (p->left) que.push(p->left);
//			if (p->right) que.push(p->right);
//		}
//		level++;
//	}
//	return res;
//}

void PrintMartix(vector<vector<int>> &m)
{
	cout << "Martix = " << endl;
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[i].size(); j++)
		{
			cout << m[i][j] << "\t";
		}
		cout << endl;
	}

}

int main()
{
	string strInput{ "3,9,20,null,null,15,7" };
	//string strInput{ "1,2,2,null,3,null,3" };
	TreeNode *root = NULL;
	StringToTreeNode(&root, strInput);
	printTreeNode(root);
	vector<vector<int>> result = levelOrder(root);
	PrintMartix(result);
}
