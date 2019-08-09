// 117.populating-next-right-pointers-in-each-node-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//Node* connect(Node* root) {
//	if (root == NULL)
//		return NULL;
//
//	Node *dummy = new Node(-1, NULL, NULL, NULL);
//	Node *pre = dummy;
//	Node *head = root;
//
//	while (root != NULL) {
//		if (root->left) {
//			pre->next = root->left;
//			pre = pre->next;
//		}
//
//		if (root->right) {
//			pre->next = root->right;
//			pre = pre->next;
//		}
//
//		root = root->next;
//
//		if (root == NULL) {
//			pre = dummy;
//			root = dummy->next;
//			dummy->next = NULL;
//		}
//	}
//
//	return head;
//}

//////////////////////////////////////////////////////////////////////////
// 调试需要改成 TreeNode ，同时需要临时修改 TreeNode.h 中相关代码
//TreeNode* connect(TreeNode* root)
Node* connect(Node* root)
{
	if (root == nullptr) return {};

	if (root->left != nullptr && root->right != nullptr) root->left->next = root->right;

	auto f = [root]()
	{
		Node *pNode = root->next;
		while (pNode != nullptr)
		{
			if (pNode->left != nullptr) return pNode->left;
			if (pNode->right != nullptr) return pNode->right;
			pNode = pNode->next;
		}
		return pNode;
	};
	Node *pNodeChild = (root->right == nullptr) ? root->left : root->right;
	Node *pNodeNextChild = f();

	if (pNodeChild != nullptr && pNodeNextChild != nullptr) pNodeChild->next = pNodeNextChild;

	connect(root->right);
	connect(root->left);
	return root;
}


int main()
{
	vector<TreeNode *> N;
	TreeNode *pHead = nullptr;

	pHead = StringToTreeNode("1,2,3,4,5,null,7,8,9,null,null,null,15");
	N.push_back(pHead);
	pHead = nullptr;

	pHead = StringToTreeNode("1,2,9,3,5,10,11,4,null,6,7,null,null,12,13,null,null,null,null,8");
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