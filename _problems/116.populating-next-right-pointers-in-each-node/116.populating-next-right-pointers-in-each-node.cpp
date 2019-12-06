﻿// 116.populating-next-right-pointers-in-each-node.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
//#include "..\Common\ListNode.h"
using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

//////////////////////////////////////////////////////////////////////////
// 调试需要改成 TreeNode ，同时需要临时修改 TreeNode.h 中相关代码
//TreeNode* connect(TreeNode* root)
Node* connect(Node* root)
{
	if (root == nullptr) return {};

	if (root->left != nullptr && root->right != nullptr) root->left->next = root->right;
	if (root->next != nullptr && root->next->left != nullptr) root->right->next = root->next->left;

	connect(root->left);
	connect(root->right);
	return root;
}


int main()
{
	vector<TreeNode *> N;
	TreeNode *pHead = nullptr;

	pHead = StringToTreeNode("1,2,3,4,5,6,7");
	N.push_back(pHead);
	pHead = nullptr;


	for (int i = 0; i < N.size(); i++)
	{
		cout << endl << "///////////////////////////////////////" << endl;
		DrawTreeNode(N[i]);
		cout << "connect = " << endl;
		//TreeNode *ans = connect(N[i]);
		cout << "my answer = " << endl;
		//DrawTreeNode(ans);
	}
}