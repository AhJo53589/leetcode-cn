// 101.IsSymmetric.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

vector<TreeNode_Val> getTreeVal(TreeNode *root, bool isLeftTree)
{
	vector<TreeNode_Val> vecVal;
	if (root == NULL) return vecVal;

	queue<TreeNode *> qTree;
	qTree.push(root);
	while (!qTree.empty())
	{
		TreeNode *qHead = qTree.front();
		qTree.pop();

		if (qHead == NULL)
		{
			vecVal.push_back(TreeNode_Val(true));
			continue;
		}
		vecVal.push_back(TreeNode_Val(qHead->val));

		if (isLeftTree)
		{
			qTree.push(qHead->left);
			qTree.push(qHead->right);
		}
		else
		{
			qTree.push(qHead->right);
			qTree.push(qHead->left);
		}
	}
	return vecVal;
}

bool isSymmetric(TreeNode* root) // 8ms
{
	if (root == NULL) return true;

	vector<TreeNode_Val> vecLeft = getTreeVal(root, true);
	vector<TreeNode_Val> vecRight = getTreeVal(root, false);

	int iLen = vecLeft.size();
	if (iLen != vecRight.size()) return false;

	for (int i = 0; i < iLen; i++)
	{
		if (vecLeft[i].isNull != vecRight[i].isNull) return false;
		if (vecLeft[i].val != vecRight[i].val) return false;
	}
	return true;
}

//// mirror
//bool mirror(TreeNode *l, TreeNode *r)
//{
//	if (!l && !r) return true;
//	if (!l && r) return false;
//	if (l && !r) return false;
//	if (l->val != r->val) return false;
//	return mirror(l->left, r->right) && mirror(l->right, r->left);
//}
//
//bool isSymmetric(TreeNode* root)  // 4ms
//{
//	if (!root) return true;
//	return mirror(root->left, root->right);
//}
//// end

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
	string strInput{ "1,2,2,3,4,4,3" };
	//string strInput{ "1,2,2,null,3,null,3" };
	TreeNode *root = NULL;
	initTree(&root, strInput);
	printTreeNode(root);
	cout << endl << isSymmetric(root) << endl;
}
