


//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head)
{
	return swapPairs(head);
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
	return "../../problems/swap-nodes-in-pairs/tests.txt";
}

