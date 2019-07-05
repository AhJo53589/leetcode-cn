// 142.linked-list-cycle-ii.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

#include "..\Common\ListNode.h"
using namespace std;


ListNode *detectCycle(ListNode *head)
{
	if (head == NULL) return NULL;

	// 步骤一：使用快慢指针判断链表是否有环
	ListNode *p = head;
	ListNode *p2 = head;
	bool hasCycle = false;
	while (p2->next != NULL && p2->next->next != NULL)
	{
		p = p->next;
		p2 = p2->next->next;
		if (p == p2)
		{
			hasCycle = true;
			break;
		}
	}

	// 步骤二：若有环，找到入环开始的节点
	if (!hasCycle) return NULL;

	ListNode *q = head;
	while (p != q)
	{
		p = p->next;
		q = q->next;
	}
	return q;
}

int main()
{
	string strValList = "[1,2,3,4,5,6,7,8,9]";
	int iCyclePos = 5;
	ListNode *pHead = NULL;
	InitCycleListNode(&pHead, strValList, iCyclePos);
	PrintCycleLinkList(pHead);

	ListNode *pNode = detectCycle(pHead);
	cout << pNode->val;
}
