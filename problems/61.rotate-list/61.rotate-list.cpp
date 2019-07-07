// 61.rotate-list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
//#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
#include "..\Common\ListNode.h"
using namespace std;


ListNode* rotateRight(ListNode* head, int k)
{
	if (head == NULL) return head;
	if (head->next == NULL) return head;

	ListNode *pNode = head;
	int len = 0;
	while (pNode != NULL)
	{
		len++;
		if (pNode->next == NULL)
		{
			pNode->next = head;
			break;
		}
		pNode = pNode->next;
	}
	k = len - (k % len);
	pNode = head;
	while (k-- > 1) pNode = pNode->next;
	ListNode *pNewHead = pNode->next;
	pNode->next = NULL;

	return pNewHead;
}

int main()
{
	string str = "[1,2,3,4,5,6,7,8,9]";
	ListNode *pHead = NULL;
	InitListNode(&pHead, str);
	PrintLinkList(pHead);

	pHead = rotateRight(pHead, 3);
	PrintLinkList(pHead);
}
