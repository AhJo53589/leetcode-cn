// TreeNode.cpp 
//

//#include "pch.h"

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "Common.h"
#include "TreeNode.h"
using namespace std;


vector<TreeNode_Val> initTreeNode_Val(string strInitData)
{
	vector<string> strArray = split(strInitData, ",");

	vector<TreeNode_Val> vecTreeNode_Val;
	for (auto str : strArray)
	{
		if (str == "null")
		{
			vecTreeNode_Val.push_back(TreeNode_Val(true));
		}
		else
		{
			vecTreeNode_Val.push_back(TreeNode_Val(stoi(str.c_str())));
		}
	}
	return vecTreeNode_Val;
}

void StringToTreeNode(TreeNode **root, string strInitData)
{
	vector<TreeNode_Val> initData = initTreeNode_Val(strInitData);
	if (initData[0].isNull) return;

	queue<TreeNode *> qTree;
	*root = new TreeNode(initData[0].val);
	qTree.push(*root);

	int i = 1;
	while (!qTree.empty())
	{
		TreeNode *qHead = NULL;
		while (qHead == NULL)
		{
			if (qTree.empty()) return;
			qHead = qTree.front();
			qTree.pop();
		}

		if (i == initData.size()) return;
		if (initData[i].isNull)
		{
			qTree.push(NULL);
		}
		else
		{
			(*qHead).left = new TreeNode(initData[i].val);
			qTree.push((*qHead).left);
		}
		i++;

		if (i == initData.size()) return;
		if (initData[i].isNull)
		{
			qTree.push(NULL);
		}
		else
		{
			(*qHead).right = new TreeNode(initData[i].val);
			qTree.push((*qHead).right);
		}
		i++;
	}
}

string TreeNodeToString(TreeNode * root)
{
	string str;
	queue<TreeNode *> qTree;
	qTree.push(root);

	while (!qTree.empty())
	{
		TreeNode *qHead = qTree.front();
		qTree.pop();

		if (qHead == NULL)
		{
			str += "NULL - ";
			continue;
		}
		str += to_string(qHead->val);
		str += " - ";
		qTree.push(qHead->left);
		qTree.push(qHead->right);
	}
	str += "\n";
	return str;
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
	cout << endl;
}
