// 203.remove-linked-list-elements.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
#include "..\Common\ListNode.h"
using namespace std;


ListNode* removeElements(ListNode* head, int val)
{
	if (head == NULL) return head;
	while (head != NULL && head->val == val)
	{
		ListNode *pDelete = head;
		head = head->next;
		delete pDelete;
	}
	ListNode *pPreNode = NULL;
	ListNode *pNode = head;
	while (pNode != NULL && pNode->next != NULL)
	{
		pPreNode = pNode;
		pNode = pNode->next;

		if (pNode->val == val)
		{
			pPreNode->next = pNode->next;
			delete pNode;
			pNode = pPreNode;
		}
	}
	return head;
}

int main()
{
	ListNode *pHead = nullptr;
	//pHead = StringToListNode("[1,2,6,3,4,5,6]");
	pHead = StringToListNode("[1,2,2,1]");
	cout << pHead << endl;

	ListNode *pNode = removeElements(pHead, 2);
	cout << pNode << endl;
}
