// 141.linked-list-cycle.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>

#include "..\Common\Common.h"
#include "..\Common\ListNode.h"
using namespace std;

bool hasCycle(ListNode *head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast != nullptr)
	{
		fast = fast->next;
		if (fast == nullptr) return false;
		slow = slow->next;
		fast = fast->next;

		if (slow == fast) return true;
	}
	return false;
}

int main()
{
	ListNode *pHead = InitCycleListNode("[1,2,3,4,5,6,7,8,9]", 5);
	cout << pHead << endl;

	//for (int i = 1; i < 2; i++)
	{
		cout << hasCycle(pHead) << endl;
		cout << endl;
	}
}
