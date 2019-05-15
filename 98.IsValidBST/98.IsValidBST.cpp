// 98.IsValidBST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>
using namespace std;


struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode_Val
{
	int val;
	bool isNull;
	TreeNode_Val(int x) : val(x), isNull(false) {}
	TreeNode_Val(bool isN) : val(0), isNull(isN) {}
};

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

std::vector<std::string> split(std::string str, std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str += pattern;//扩展字符串以方便操作
	int size = str.size();
	for (int i = 0; i < size; i++)
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

int main()
{
	//string strInput{ "3,9,20,0,0,15,7" };
	//string strInput{ "2,1,4,0,0,3,6" };
	//string strInput{ "10,5,15,0,0,6,20" };
	string strInput{ 1,1 };
	TreeNode *root = NULL;
	initTree(&root, strInput);
	printTreeNode(root);
	cout << endl << isValidBST(root) << endl;
}
