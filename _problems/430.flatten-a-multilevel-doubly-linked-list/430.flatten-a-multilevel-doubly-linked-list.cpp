// 430.flatten-a-multilevel-doubly-linked-list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <random>

#include "..\Common\Common.h"
using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};


Node* flatten(Node* head)
{
	Node *pNode = head;
	while (pNode != NULL)
	{
		if (pNode->child != NULL)
		{
			Node *pNext = pNode->next;
			pNode->next = pNode->child;
			pNode->next->prev = pNode;
			pNode->child = NULL;
			flatten(pNode);
			while (pNode != NULL && pNode->next != NULL) pNode = pNode->next;
			pNode->next = pNext;
			if (pNext != NULL) pNext->prev = pNode;
		}
		pNode = pNode->next;
	}
	return head;
}

void PrintLinkList(Node *pHead, bool reverse = false)
{
	Node *pNode = pHead;
	if (!reverse)
	{
		while (pNode != NULL)
		{
			cout << pNode->val << " -> ";
			pNode = pNode->next;
		}
	}
	else
	{
		while (pNode != NULL)
		{
			cout << pNode->val << " <- ";
			pNode = pNode->prev;
		}
	}
	cout << endl;
}

void InitNode(Node ** pHead, string strValList)
{
	vector<int> val = StringToVectorInt(strValList);

	Node *pNode = NULL;
	for (int i = val.size() - 1; i >= 0; i--)
	{
		Node *pNew = new Node();
		pNew->val = val[i];
		pNew->next = pNode;
		if (pNode != NULL) pNode->prev = pNew;
		pNode = pNew;
	}
	pNode->prev = NULL;
	*pHead = pNode;
}

void Init(vector<Node**> pHead, vector<string> str, vector<int> pos)
{
	for (int i = 0; i < str.size(); i++)
	{
		InitNode(pHead[i], str[i]);
		PrintLinkList(*pHead[i]);
	}
	for (int i = 0; i < pos.size(); i++)
	{
		Node *pNode = *pHead[i];
		while (pos[i]-- > 0) pNode = pNode->next;
		pNode->child = *pHead[i + 1];
	}
}


int main()
{
	//// Test 01
	//vector<Node **> pHead;
	//Node *pHeadA = NULL;
	//Node *pHeadB = NULL;
	//Node *pHeadC = NULL;
	//pHead.push_back(&pHeadA);
	//pHead.push_back(&pHeadB);
	//pHead.push_back(&pHeadC);

	//vector<string> str;
	//str.push_back("[1,2,3,4,5,6]");
	//str.push_back("[7,8,9,10]");
	//str.push_back("[11,12]");

	//vector<int> pos;
	//pos.push_back(2);
	//pos.push_back(1);

	//Init(pHead, str, pos);

	// Test 02
	vector<Node **> pHead;
	Node *pHeadA = NULL;
	Node *pHeadB = NULL;
	Node *pHeadC = NULL;
	Node *pHeadD = NULL;
	Node *pHeadE = NULL;
	pHead.push_back(&pHeadA);
	pHead.push_back(&pHeadB);
	pHead.push_back(&pHeadC);
	pHead.push_back(&pHeadD);
	pHead.push_back(&pHeadE);

	vector<string> str;
	str.push_back("[1]");
	str.push_back("[2]");
	str.push_back("[3]");
	str.push_back("[4]");
	str.push_back("[5]");

	vector<int> pos;
	pos.push_back(0);
	pos.push_back(0);
	pos.push_back(0);
	pos.push_back(0);

	Init(pHead, str, pos);


	cout << endl;
	Node *pNode = flatten(pHeadA);
	PrintLinkList(pNode);
	while (pNode->next != NULL) pNode = pNode->next;
	PrintLinkList(pNode, true);
}
