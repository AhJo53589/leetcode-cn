// 24.swap-nodes-in-pairs.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include <bitset>

#include "..\Common\Common.h"
//#include "..\Common\GraphNode.h"
//#include "..\Common\TreeNode.h"
#include "..\Common\ListNode.h"
using namespace std;



ListNode* swapPairs(ListNode* head)
{
	if (head == nullptr) return head;
	ListNode *pNode = head;
	ListNode *pNodeNext = head->next;
	ListNode *pPrev = nullptr;
	head = (pNodeNext == nullptr) ? head : pNodeNext;
	while (pNode != nullptr && pNodeNext != nullptr)
	{
		if (pPrev != NULL) pPrev->next = pNodeNext;
		pPrev = pNode;

		ListNode *pTemp = pNodeNext->next;
		pNodeNext->next = pNode;
		pNode->next = pTemp;

		pNode = pTemp;
		pNodeNext = (pNode == nullptr) ? nullptr : pNode->next;
	}
	return head;
}

int main()
{
	vector<string> vStr;
	vector<int> vk;

	vStr.push_back("[1,2,3,4,5,6,7,8,9]");

	//vStr.push_back("[3,2,3,1,2,4,5,5,6,1]");
	//vk.push_back(4);

	//vStr.push_back("[1,2,3,4,5]");
	//vk.push_back(4);

	//vStr.push_back("[5,4,3,2,1]");
	//vk.push_back(2);

	for (int i = 0; i < vStr.size(); i++)
	{
		ListNode *pHead;
		StringToListNode(&pHead, vStr[i]);
		PrintLinkList(pHead);

		pHead = swapPairs(pHead);
		PrintLinkList(pHead);
		cout << endl;
	}
}
