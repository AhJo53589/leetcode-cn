// 707.design-linked-list.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
#include "..\Common\GraphNode.h"
#include "..\Common\TreeNode.h"
#include "..\Common\ListNode.h"
using namespace std;

class MyLinkedList
{
public:
	/** Initialize your data structure here. */
	MyLinkedList()
		: m_pHead(NULL)
		, m_len(0)
	{

	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index)
	{
		if (index < 0 || index >= m_len) return -1;

		ListNode *pNode = m_pHead;
		while (index-- > 0) pNode = pNode->next;
		return pNode->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val)
	{
		ListNode *pNode = m_pHead;
		m_pHead = new ListNode(val, m_pHead);
		m_len++;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val)
	{
		ListNode *pNode = m_pHead;
		while (pNode->next != NULL) pNode = pNode->next;
		pNode->next = new ListNode(val, NULL);
		m_len++;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val)
	{
		if (index > m_len) return;

		if (index <= 0) addAtHead(val);
		else if (index == m_len) addAtTail(val);
		else
		{
			ListNode *pNode = m_pHead;
			while (index-- > 1) pNode = pNode->next;
			ListNode *pNew = new ListNode(val, pNode->next);
			pNode->next = pNew;
			m_len++;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index)
	{
		if (index < 0 || index >= m_len) return;

		ListNode *pNode = m_pHead;
		if (index == 0)
		{
			m_pHead = m_pHead->next;
			delete pNode;
			m_len--;
		}
		else
		{
			while (index-- > 1) pNode = pNode->next;
			ListNode *pDelete = pNode->next;
			pNode->next = pDelete->next;
			delete pDelete;
			m_len--;
		}
	}

private:
	ListNode *m_pHead;
	int m_len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
	MyLinkedList linkedList;
	linkedList.addAtHead(1);
	linkedList.addAtTail(3);
	linkedList.addAtIndex(1, 2);   //链表变为1-> 2-> 3
	cout << linkedList.get(1);     //返回2
	linkedList.deleteAtIndex(-1);  //现在链表是1-> 3
	linkedList.get(1);            //返回3
}
