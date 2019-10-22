// 148.sort-list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <string>
#include <random>
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
#include "..\Common\ListNode.h"
using namespace std;

ListNode* merge(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;

	if (l1->val < l2->val)
	{
		l1->next = merge(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = merge(l2->next, l1);
		return l2;
	}
}

ListNode* sortList(ListNode* head)
{
	if (!head || !head->next) return head;
	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *brek = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		brek = slow;
		slow = slow->next;
	}
	brek->next = nullptr;
	ListNode *l1 = sortList(head);
	ListNode *l2 = sortList(slow);
	return merge(l1, l2);
}

int main()
{
	vector<ListNode *> lists;
	ListNode *pHead = nullptr;
	pHead = StringToListNode("[4,7,5,3]");
	lists.push_back(pHead);
	pHead = nullptr;

	for (auto p : lists)
	{
		cout << p << endl;
		pHead = sortList(p);
		cout << pHead << endl;
	}
}

