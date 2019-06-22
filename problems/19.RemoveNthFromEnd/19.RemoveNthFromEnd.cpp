// 19.RemoveNthFromEnd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == NULL || n == 0) return NULL;
	if (head->next == NULL) return NULL;

	ListNode *pTemp = head;
	ListNode *pDeletePrev = head;
	ListNode *pDelete = NULL;
	while (n > 0)
	{
		pTemp = pTemp->next;
		--n;
	}
	if (pTemp == NULL)
	{
		pDelete = head;
		head = head->next;
		delete(pDelete);
		return head;
	}
	while (pTemp->next != NULL)
	{
		pTemp = pTemp->next;
		pDeletePrev = pDeletePrev->next;
	}
	pDelete = pDeletePrev->next;
	pDeletePrev->next = pDelete->next;
	delete(pDelete);
	return head;
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
	const int cLinkListLen = 3;

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

	//for (int i = 1; i < 2; i++)
	{
		int i = 3;
		cout << "delete num = " << i << endl;
		pHead = removeNthFromEnd(pHead, i);
		PrintLinkList(pHead);
		cout << endl;
	}
}
