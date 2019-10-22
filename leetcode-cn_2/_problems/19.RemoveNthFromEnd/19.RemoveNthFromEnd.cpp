// 19.RemoveNthFromEnd.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>

#include "..\Common\ListNode.h"

using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == nullptr || n == 0) return nullptr;
	if (head->next == nullptr) return nullptr;

	ListNode *pTemp = head;
	ListNode *pDeletePrev = head;
	ListNode *pDelete = nullptr;
	while (n > 0)
	{
		pTemp = pTemp->next;
		--n;
	}
	if (pTemp == nullptr)
	{
		pDelete = head;
		head = head->next;
		delete(pDelete);
		return head;
	}
	while (pTemp->next != nullptr)
	{
		pTemp = pTemp->next;
		pDeletePrev = pDeletePrev->next;
	}
	pDelete = pDeletePrev->next;
	pDeletePrev->next = pDelete->next;
	delete(pDelete);
	return head;
}

int main()
{
	ListNode *pHead = StringToListNode("[1,2,3,4,5,6,7,8,9]");
	cout << pHead << endl;

	//for (int i = 1; i < 2; i++)
	{
		int i = 3;
		cout << "delete num = " << i << endl;
		pHead = removeNthFromEnd(pHead, i);
		cout << pHead << endl;
		cout << endl;
	}
}
