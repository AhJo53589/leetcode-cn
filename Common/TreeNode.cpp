// TreeNode.cpp 
//

//#include "pch.h"

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "TreeNode.h"
using namespace std;


std::vector<std::string> split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;	// 扩展字符串以方便操作
	size_t size = str.size();
	for (size_t i = 0; i < size; i++)
	{
		pos = str.find(pattern, i);
		if (pos < size)
		{
			std::string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

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

void initTree(TreeNode **root, string strInitData)
{
	vector<TreeNode_Val> initData = initTreeNode_Val(strInitData);
	if (initData[0].isNull) return;

	queue<TreeNode *> qTree;
	*root = new TreeNode(initData[0].val);
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
