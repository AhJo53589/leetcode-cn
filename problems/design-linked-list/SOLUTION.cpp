


//////////////////////////////////////////////////////////////////////////
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

	// for Test
	ListNode *GetListHead() { return m_pHead; }

private:
	ListNode *m_pHead;
	int m_len;
};

class MyLinkedList_Doubly
{
public:
	/** Initialize your data structure here. */
	MyLinkedList_Doubly()
		: m_pHead(NULL)
		, m_pTail(NULL)
		, m_len(0)
	{

	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index)
	{
		if (index < 0 || index >= m_len) return -1;

		DoublyListNode *pNode = NULL;
		if (index < m_len / 2)
		{
			pNode = m_pHead;
			while (index-- > 0) pNode = pNode->next;
		}
		else
		{
			pNode = m_pTail;
			while (index++ < m_len - 1) pNode = pNode->prev;
		}
		return pNode->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val)
	{
		m_pHead = new DoublyListNode(val, m_pHead, NULL);
		if (m_pHead->next != NULL)
		{
			m_pHead->next->prev = m_pHead;
		}
		m_len++;
		if (m_len == 1) m_pTail = m_pHead;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val)
	{
		m_pTail = new DoublyListNode(val, NULL, m_pTail);
		if (m_pTail->prev != NULL)
		{
			m_pTail->prev->next = m_pTail;
		}
		m_len++;
		if (m_len == 1) m_pHead = m_pTail;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val)
	{
		if (index > m_len) return;

		if (index <= 0) addAtHead(val);
		else if (index == m_len) addAtTail(val);
		else if (index < m_len / 2)
		{
			DoublyListNode *pNode = m_pHead;
			while (index-- > 1) pNode = pNode->next;
			DoublyListNode *pNew = new DoublyListNode(val, pNode->next, pNode);
			pNode->next = pNew;
			if (pNew->next != NULL)
			{
				pNew->next->prev = pNew;
			}
			m_len++;
			if (m_len == 1) m_pTail = m_pHead;
		}
		else
		{
			DoublyListNode *pNode = m_pTail;
			while (index++ < m_len - 1) pNode = pNode->prev;
			DoublyListNode *pNew = new DoublyListNode(val, pNode, pNode->prev);
			pNode->prev = pNew;
			if (pNew->prev != NULL)
			{
				pNew->prev->next = pNew;
			}
			m_len++;
			if (m_len == 1) m_pHead = m_pTail;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index)
	{
		if (index < 0 || index >= m_len) return;

		DoublyListNode *pNode = NULL;
		if (index == 0)
		{
			pNode = m_pHead;
			m_pHead = m_pHead->next;
			if (m_pHead != NULL)
			{
				m_pHead->prev = NULL;
			}
			delete pNode;
			m_len--;
		}
		else if (index == m_len - 1)
		{
			pNode = m_pTail;
			m_pTail = m_pTail->prev;
			if (m_pTail != NULL)
			{
				m_pTail->next = NULL;
			}
			delete pNode;
			m_len--;
		}
		else if (index < m_len / 2)
		{
			pNode = m_pHead;
			while (index-- > 1) pNode = pNode->next;
			DoublyListNode *pDelete = pNode->next;
			pNode->next = pDelete->next;
			if (pDelete->next != NULL)
			{
				pDelete->next->prev = pNode;
			}
			delete pDelete;
			m_len--;
		}
		else
		{
			pNode = m_pTail;
			while (index++ < m_len - 2) pNode = pNode->prev;
			DoublyListNode *pDelete = pNode->prev;
			pNode->prev = pDelete->prev;
			if (pDelete->prev != NULL)
			{
				pDelete->prev->next = pNode;
			}
			delete pDelete;
			m_len--;
		}

		if (m_len == 0)
		{
			m_pHead = NULL;
			m_pTail = NULL;
		}
	}

	// for Test
	DoublyListNode *GetListHead() { return m_pHead; }

private:
	DoublyListNode *m_pHead;
	DoublyListNode *m_pTail;
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


//////////////////////////////////////////////////////////////////////////
//void _solution_run(int x)
//{
//	return push(x);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	vector<string> sf = tc.get<vector<string>>();
	vector<vector<int>> param = tc.get<vector<vector<int>>>();

	string ans = "[";
	MyLinkedList *obj = nullptr;
	for (size_t i = 0; i < sf.size(); i++)
	{
		if (sf[i] == "MyLinkedList")
		{
			obj = new MyLinkedList();
			ans += "null";
		}
		else if (sf[i] == "get")
		{
			int r = obj->get(param[i][0]);
			ans += to_string(r);
		}
		else if (sf[i] == "addAtHead")
		{
			obj->addAtHead(param[i][0]);
			ans += "null";
		}
		else if (sf[i] == "addAtTail")
		{
			obj->addAtTail(param[i][0]);
			ans += "null";
		}
		else if (sf[i] == "addAtIndex")
		{
			obj->addAtIndex(param[i][0], param[i][1]);
			ans += "null";
		}
		else if (sf[i] == "deleteAtIndex")
		{
			obj->deleteAtIndex(param[i][0]);
			ans += "null";
		}
		ans += ",";
	}
	ans.pop_back();
	ans += "]";
	return ans;
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

