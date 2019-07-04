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

//void initNode(Node ** root, string strInitData)
//{
//	{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}
//}
//
//void printNode(Node * root)
//{
//}
