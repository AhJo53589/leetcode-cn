// 237.DeleteNode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>

#include "..\Common\ListNode.h"
using namespace std;

void deleteNode(ListNode *node)
{
	ListNode *pNext = node->next;
	node->val = pNext->val;
	node->next = pNext->next;
	delete(pNext);
	pNext = nullptr;
}

int main()
{
	ListNode *pHead = StringToListNode("[1,2,3,4,5,6,7,8,9,10]");
	cout << pHead << endl;

	const int cCheckNum = 10;
	for (int i = 3; i < cCheckNum; i++)
	{
		cout << "delete num = " << i << endl;
		deleteNode(FindNodeByVal(pHead, i));
		cout << pHead << endl;
		cout << endl;
	}
}
