// 206.ReverseList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

struct ListNode
{
	int m_data;
	ListNode *m_pNext;
};

ListNode* ReverseIteratively(ListNode* pHead)
{
	ListNode* pReversedHead = NULL;
	ListNode* pNode = pHead;
	ListNode* pPrev = NULL;
	while (pNode != NULL)
	{
		// get the next node, and save it at pNext
		ListNode* pNext = pNode->m_pNext;
		// reverse the linkage between nodes
		pNode->m_pNext = pPrev;

		// move forward on the the list
		pPrev = pNode;
		pNode = pNext;
	}
	pReversedHead = pPrev;
	return pReversedHead;
}

void PrintLinkList(ListNode *pHead)
{
	ListNode *pNode = pHead;
	while (pNode != NULL)
	{
		std::cout << pNode->m_data << " - ";
		pNode = pNode->m_pNext;
	}
	std::cout << std::endl;
}

int main()
{
	const int cLinkListLen = 10;

	ListNode *pNode = NULL;
	ListNode *pNodeNew = NULL;

	for (int i = 0; i < cLinkListLen; i++)
	{
		pNodeNew = new ListNode();
		pNodeNew->m_data = i;
		pNodeNew->m_pNext = pNode;
		pNode = pNodeNew;
	}
	ListNode *pHead = pNode;
	PrintLinkList(pHead);

	ListNode *pReverseHead = ReverseIteratively(pHead);
	PrintLinkList(pReverseHead);
}
