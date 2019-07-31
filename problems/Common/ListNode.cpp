// LinkedListNode.cpp 
//

//#include "pch.h"

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "Common.h"
#include "ListNode.h"
using namespace std;

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

void PrintCycleLinkList(ListNode * pHead)
{
	int num = 100;
	ListNode *pNode = pHead;
	while (pNode != NULL && num-- > 0)
	{
		cout << pNode->val << " - ";
		pNode = pNode->next;
	}
	cout << endl;

}

void StringToListNode(ListNode **pHead, string strValList)
{
	vector<int> val = StringToVectorInt(strValList);

	StringToListNode(pHead, strValList, 0, val.size());
}

void StringToListNode(ListNode ** pHead, string strValList, int valBegin, int valEnd)
{
	vector<int> val = StringToVectorInt(strValList);

	ListNode *pNode = NULL;
	for (int i = valEnd - 1; i >= valBegin; i--)
	{
		ListNode *pNew = new ListNode(val[i]);
		pNew->next = pNode;
		pNode = pNew;
	}
	*pHead = pNode;
}

void InitCycleListNode(ListNode **pHead, string strValList, int iCyclePos)
{
	StringToListNode(pHead, strValList);

	ListNode *pNode = *pHead;
	while (iCyclePos-- > 0) pNode = pNode->next;
	ListNode *pTail = pNode;
	while (pTail->next != NULL) pTail = pTail->next;
	pTail->next = pNode;
}

void PrintLinkList(DoublyListNode * pHead)
{
	DoublyListNode *pNode = pHead;
	while (pNode != NULL)
	{
		cout << pNode->val << " - ";
		pNode = pNode->next;
	}
	cout << endl;
}

//
//void printNode(Node * root)
//{
//}
