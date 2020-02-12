#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct ListNode;

ListNode *FindNodeByVal(ListNode *pHead, int i);
const ListNode *DetectCycle(const ListNode *pHead);
string ListNodeToString(const ListNode *pHead);
ListNode *StringToListNode(const string data);
ListNode* StringToListNode(const string data, int iBeg, int iEnd);
ListNode* StringToListNode(const vector<int>& data, int iBeg, int iEnd);
ListNode *StringIntToCycleListNode(string strValList, int iCyclePos);
void StringIntToIntersectionNode(ListNode **pHeadA, ListNode **pHeadB, string strListA, string strListB, int skipA, int skipB);

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode * pNext) : val(x), next(pNext) {}

	friend ostream & operator<<(ostream& os, const ListNode *p)
	{
		string s = ListNodeToString(p);
		os << s.c_str();
		return os;
	}
};



//////////////////////////////////////////////////////////////////////////
struct DoublyListNode;

string ListNodeToString(const DoublyListNode *pHead);

struct DoublyListNode 
{
	int val;
	DoublyListNode *next, *prev;
	DoublyListNode() : val(0), next(nullptr), prev(nullptr) {}
	DoublyListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
	DoublyListNode(int x, DoublyListNode *pNext, DoublyListNode *pPrev) : val(x), next(pNext), prev(pPrev) {}
};


#endif //LIST_NODE_H
