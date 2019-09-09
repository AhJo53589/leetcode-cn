// 206.ReverseList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>

#include "..\Common\ListNode.h"
using namespace std;


ListNode *reverseList(ListNode *pHead)
{
	ListNode *pNode = pHead;
	ListNode *pPrev = nullptr;

	while (pNode != nullptr)
	{
		ListNode *pNext = pNode->next;
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	return pPrev;
}

int main()
{
	ListNode *pHead = StringToListNode("[1,2,3,4,5,6,7,8,9]");
	cout << pHead << endl;

	ListNode *pReverseHead = reverseList(pHead);
	cout << pReverseHead << endl;
}
