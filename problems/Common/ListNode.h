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
	ListNode(int _val, ListNode * pNext) : val(_val), next(pNext) {}
};

void PrintLinkList(ListNode *pHead);
void PrintCycleLinkList(ListNode *pHead);

//void initNode(Node **root, string strInitData);
//void printNode(Node *root);



#endif //LIST_NODE_H
