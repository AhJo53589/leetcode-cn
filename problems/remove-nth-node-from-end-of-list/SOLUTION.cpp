


//////////////////////////////////////////////////////////////////////////
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	if (head == nullptr || n == 0) return nullptr;
	if (head->next == nullptr) return nullptr;

	ListNode *pTemp = head;
	ListNode *pDeletePrev = head;
	ListNode *pDelete = nullptr;
	while (n > 0)
	{
		pTemp = pTemp->next;
		--n;
	}
	if (pTemp == nullptr)
	{
		pDelete = head;
		head = head->next;
		delete(pDelete);
		return head;
	}
	while (pTemp->next != nullptr)
	{
		pTemp = pTemp->next;
		pDeletePrev = pDeletePrev->next;
	}
	pDelete = pDeletePrev->next;
	pDeletePrev->next = pDelete->next;
	delete(pDelete);
	return head;
}

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head, int n)
{
	return removeNthFromEnd(head,n);
}

//#define USE_SOLUTION_CUSTOM
//ListNode* _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/remove-nth-node-from-end-of-list/tests.txt";
}

