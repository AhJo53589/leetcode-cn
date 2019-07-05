#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode * pNext) : val(x), next(pNext) {}
};

void PrintLinkList(ListNode *pHead);
void PrintCycleLinkList(ListNode *pHead);

void InitListNode(ListNode **pHead, string strValList);
void InitListNode(ListNode **pHead, string strValList, int valBegin, int valEnd);
void InitCycleListNode(ListNode **pHead, string strValList, int iCyclePos);
//void printNode(Node *root);


struct DoublyListNode 
{
	int val;
	DoublyListNode *next, *prev;
	DoublyListNode(int x) : val(x), next(NULL), prev(NULL) {}
	DoublyListNode(int x, DoublyListNode *pNext, DoublyListNode *pPrev) : val(x), next(pNext), prev(pPrev) {}
};

void PrintLinkList(DoublyListNode *pHead);


#endif //LIST_NODE_H
