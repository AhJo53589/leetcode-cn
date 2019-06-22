﻿// 206.ReverseList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode* head)
{
	ListNode* pReversedHead = NULL;
	ListNode* pNode = head;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		// get the next node, and save it at pNext
		ListNode* pNext = pNode->next;
		// reverse the linkage between nodes
		pNode->next = pPrev;

		// move forward on the the list
		pPrev = pNode;
		pNode = pNext;
	}
	pReversedHead = pPrev;
	return pReversedHead;
}

ListNode *FindNode(ListNode *pHead, int i)
{
	ListNode *pReturn = pHead;
	while (pReturn->val != i)
	{
		pReturn = pReturn->next;
	}
	return pReturn;
}

void PrintLinkList(ListNode *pHead)
{
	ListNode *pNode = pHead;
	while (pNode != NULL)
	{
		cout << pNode->val << " - ";
		pNode = pNode->next;
	}
	cout << endl;
}

void Init(ListNode **pHead)
{
	const int cLinkListLen = 10;

	ListNode *pNode = NULL;
	ListNode *pNodeNew = NULL;

	for (int i = 0; i < cLinkListLen; i++)
	{
		pNodeNew = new ListNode(i);
		pNodeNew->next = pNode;
		pNode = pNodeNew;
	}

	*pHead = pNode;
}

int main()
{
	ListNode *pHead = NULL;
	Init(&pHead);
	PrintLinkList(pHead);

	ListNode *pReverseHead = reverseList(pHead);
	PrintLinkList(pReverseHead);
}
