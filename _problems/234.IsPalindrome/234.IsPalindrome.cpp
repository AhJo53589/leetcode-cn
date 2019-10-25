// 234.IsPalindrome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>

#include "..\Common\ListNode.h"

using namespace std;

bool isPalindrome(ListNode* head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast != nullptr)
	{
		slow = slow->next;
		fast = (fast->next != nullptr) ? fast->next->next : fast->next;
	}

	ListNode *prev = nullptr;
	while (slow != nullptr)
	{
		ListNode *tmp = slow->next;
		slow->next = prev;
		prev = slow;
		slow = tmp;
	}

	while (head != nullptr && prev != nullptr)
	{
		if (head->val != prev->val) return false;

		head = head->next;
		prev = prev->next;
	}
	return true;
}

//bool isPalindrome(ListNode* head)
//{
//	ListNode* slow = head, *fast = head, *prev = nullptr;
//	while (fast) {//find mid node
//		slow = slow->next;
//		fast = fast->next ? fast->next->next : fast->next;
//	}
//	while (slow) {//reverse
//		ListNode* ovn = slow->next;
//		slow->next = prev;
//		prev = slow;
//		slow = ovn;
//	}
//	while (head && prev) {//check
//		if (head->val != prev->val) {
//			return false;
//		}
//		head = head->next;
//		prev = prev->next;
//	}
//	return true;
//}

int main()
{
	ListNode *pHead = StringToListNode("[1,2,2,1]");
	cout << pHead << endl;

	//for (int i = 1; i < 2; i++)
	{
		cout << isPalindrome(pHead) << endl;
	}
}
