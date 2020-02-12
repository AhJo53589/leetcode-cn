// LinkedListNode.cpp 
//

//#include "pch.h"

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

#include "Common.h"
#include "ListNode.h"
using namespace std;

//////////////////////////////////////////////////////////////////////////
// leetcode playground
//////////////////////////////////////////////////////////////////////////

//vector<int> stringToIntegerVector(string input) {
//	vector<int> output;
//	trimLeftTrailingSpaces(input);
//	trimRightTrailingSpaces(input);
//	input = input.substr(1, input.length() - 2);
//	stringstream ss;
//	ss.str(input);
//	string item;
//	char delim = ',';
//	while (getline(ss, item, delim)) {
//		output.push_back(stoi(item));
//	}
//	return output;
//}
//
//ListNode* stringToListNode(string input) {
//	// Generate list from the input
//	vector<int> list = stringToIntegerVector(input);
//
//	// Now convert that list into linked list
//	ListNode* dummyRoot = new ListNode(0);
//	ListNode* ptr = dummyRoot;
//	for (int item : list) {
//		ptr->next = new ListNode(item);
//		ptr = ptr->next;
//	}
//	ptr = dummyRoot->next;
//	delete dummyRoot;
//	return ptr;
//}
//
//string listNodeToString(ListNode* node) {
//	if (node == nullptr) {
//		return "[]";
//	}
//
//	string result;
//	while (node) {
//		result += to_string(node->val) + ", ";
//		node = node->next;
//	}
//	return "[" + result.substr(0, result.length() - 2) + "]";
//}

//////////////////////////////////////////////////////////////////////////
ListNode *FindNodeByVal(ListNode *pHead, int val)
{
	ListNode *pNode = pHead;
	while (pNode != nullptr && pNode->val != val)
	{
		pNode = pNode->next;
	}
	return pNode;
}

const ListNode *DetectCycle(const ListNode *pHead)
{
	if (pHead == nullptr) return nullptr;

	bool hasCycle = false;
	const ListNode *pLow = pHead;
	const ListNode *pFast = pHead;
	while (pFast->next != nullptr && pFast->next->next != nullptr)
	{
		pLow = pLow->next;
		pFast = pFast->next->next;
		if (pLow == pFast)
		{
			hasCycle = true;
			break;
		}
	}
	if (!hasCycle) return nullptr;

	const ListNode *pEnter = pHead;
	while (pLow != pEnter)
	{
		pLow = pLow->next;
		pEnter = pEnter->next;
	}
	return pEnter;
}

string ListNodeToString(const ListNode * pHead)
{
	string ret;
	bool bEnter = false;
	const ListNode *pCycleEnter = DetectCycle(pHead);
	const ListNode *pNode = pHead;
	while (pNode != nullptr)
	{
		if (pCycleEnter != nullptr && pCycleEnter == pNode)
		{
			if (!bEnter)
			{
				bEnter = true;
				ret += "(";
			}
			else
			{
				ret += ")";
				break;
			}
		}
		ret += to_string(pNode->val);
		pNode = pNode->next;
		if (pNode != nullptr)
		{
			ret += ",";
		}
	}
	return ret;
}

ListNode * StringToListNode(const string data)
{
	vector<int> val = StringToVectorInt(data);
	return StringToListNode(data, 0, val.size());
}

ListNode * StringToListNode(const string data, int iBeg, int iEnd)
{
	vector<int> val = StringToVectorInt(data);

	ListNode *pNode = nullptr;
	for (int i = iEnd - 1; i >= iBeg; i--)
	{
		ListNode *pNew = new ListNode(val[i]);
		pNew->next = pNode;
		pNode = pNew;
	}
	return pNode;
}

ListNode * StringIntToCycleListNode(string strValList, int iCyclePos)
{
	ListNode *pHead = StringToListNode(strValList);
	if (iCyclePos == -1)
	{
		return pHead;
	}

	ListNode *pNode = pHead;
	while (iCyclePos-- > 0) pNode = pNode->next;
	ListNode *pTail = pNode;
	while (pTail->next != nullptr) pTail = pTail->next;
	pTail->next = pNode;
	return pHead;
}

void StringIntToIntersectionNode(ListNode ** pHeadA, ListNode ** pHeadB, string strListA, string strListB, int skipA, int skipB)
{
	*pHeadA = StringToListNode(strListA, 0, skipA);
	*pHeadB = StringToListNode(strListB, 0, skipB);

	vector<int> listA = StringToVectorInt(strListA);
	ListNode *pNode = StringToListNode(strListA, skipA, listA.size());

	ListNode *pTailA = *pHeadA;
	ListNode *pTailB = *pHeadB;
	while (pTailA->next != nullptr) pTailA = pTailA->next;
	while (pTailB->next != nullptr) pTailB = pTailB->next;
	pTailA->next = pNode;
	pTailB->next = pNode;
}

string ListNodeToString(const DoublyListNode * pHead)
{
	string ret;
	const DoublyListNode *pNode = pHead;
	while (pNode != nullptr)
	{
		ret += pNode->val;
		pNode = pNode->next;
		if (pNode != nullptr)
		{
			ret += ",";
		}
	}
	return ret;
}


