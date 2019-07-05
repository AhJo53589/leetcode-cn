// 160.intersection-of-two-linked-lists.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include "..\Common\ListNode.h"
using namespace std;


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode *pA = headA;
	ListNode *pB = headB;
	if (pA == NULL || pB == NULL) return NULL;

	int iDiff = 0;
	while (pA->next != NULL)
	{
		pA = pA->next;
		iDiff--;
	}
	while (pB->next != NULL)
	{
		pB = pB->next;
		iDiff++;
	}

	pA = headA;
	pB = headB;
	if (iDiff < 0)
	{
		while (iDiff++ < 0) pA = pA->next;
	}
	else
	{
		while (iDiff-- > 0) pB = pB->next;
	}

	while (pA->next != NULL)
	{
		if (pA == pB) return pA;
		pA = pA->next;
		pB = pB->next;
	}
	if (pA == pB) return pA;
	return NULL;
}


void Init(ListNode **pHeadA, ListNode **pHeadB, string strListA, string strListB, int skipA, int skipB)
{
	InitListNode(pHeadA, strListA, 0, skipA);
	InitListNode(pHeadB, strListB, 0, skipB);

	ListNode *pNode = NULL;
	vector<int> listA = StringToVectorInt(strListA);
	InitListNode(&pNode, strListA, skipA, listA.size());

	ListNode *pTailA = *pHeadA;
	ListNode *pTailB = *pHeadB;
	while (pTailA->next != NULL) pTailA = pTailA->next;
	while (pTailB->next != NULL) pTailB = pTailB->next;
	pTailA->next = pNode;
	pTailB->next = pNode;
}

int main()
{
	// listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
	string strListA = "[4,1,8,4,5]";
	string strListB = "[5,0,1,8,4,5]";
	int skipA = 2;
	int skipB = 3;

	ListNode *pHeadA = NULL;
	ListNode *pHeadB = NULL;
	Init(&pHeadA, &pHeadB, strListA, strListB, skipA, skipB);
	PrintLinkList(pHeadA);
	PrintLinkList(pHeadB);

	ListNode *pNode = getIntersectionNode(pHeadA, pHeadB);
	cout << pNode->val;
}
