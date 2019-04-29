// 234.IsPalindrome.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast != NULL)
	{
		slow = slow->next;
		fast = (fast->next != NULL) ? fast->next->next : fast->next;
	}

	ListNode *prev = NULL;
	while (slow != NULL)
	{
		ListNode *tmp = slow->next;
		slow->next = prev;
		prev = slow;
		slow = tmp;
	}

	while (head != NULL && prev != NULL)
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

void Init(ListNode **pHead)
{
	const int cLinkListLen = 3;

	ListNode *pNode = NULL;
	ListNode *pNodeNew = NULL;

	for (int i = 0; i < cLinkListLen; i++)
	{
		pNodeNew = new ListNode(cLinkListLen - i);
		pNodeNew->next = pNode;
		pNode = pNodeNew;
	}

	*pHead = pNode;
}

int main()
{
	ListNode *pHead = NULL;
	ListNode *pHead2 = NULL;
	Init(&pHead);
	Init(&pHead2);
	PrintLinkList(pHead);
	PrintLinkList(pHead2);

	//for (int i = 1; i < 2; i++)
	{
		pHead = mergeTwoLists(pHead, pHead2);
		PrintLinkList(pHead);
		cout << endl;
	}
}
