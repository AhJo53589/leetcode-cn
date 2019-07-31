// 2.add-two-numbers.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include "..\Common\ListNode.h"
using namespace std;



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *pSum = new ListNode(0);
	ListNode *pNode = pSum;
	int iCarry = 0;
	while (l1 != NULL || l2 != NULL || iCarry != 0)
	{
		int i1 = (l1 != NULL) ? l1->val : 0;
		int i2 = (l2 != NULL) ? l2->val : 0;
		if (l1 != NULL) l1 = l1->next;
		if (l2 != NULL) l2 = l2->next;
		int val = (i1 + i2 + iCarry) % 10;
		iCarry = (i1 + i2 + iCarry) / 10;
		ListNode *pNew = new ListNode(val);
		pNode->next = pNew;
		pNode = pNew;
	}
	return pSum->next;
}


int main()
{
	ListNode *pHead = NULL;
	//string str = "[1,2,6,3,4,5,6]";
	string str = "[1,2,3,4,5,6,7,8,9]";

	StringToListNode(&pHead, str);
	PrintLinkList(pHead);

	ListNode *pNode = addTwoNumbers(pHead, pHead);
	PrintLinkList(pNode);
}
