


//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode *pHead)
{
	return reverseList(pHead);
}

//#define USE_SOLUTION_CUSTOM
//ListNode _solution_custom(TestCases &tc)
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
	return "../../problems/reverse-linked-list/tests.txt";
}

