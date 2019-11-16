


//////////////////////////////////////////////////////////////////////////
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	n -= m;
	if (n++ == 0) return head;

	ListNode *pH = new ListNode(0);
	pH->next = head;

	ListNode *pM = pH;
	while (--m != 0)
	{
		pM = pM->next;
	}

	ListNode *pPre = nullptr;
	ListNode *pCur = pM->next;
	ListNode *pNxt = pCur->next;
	while (n-- != 0)
	{
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNxt;
		if (pCur == nullptr) break;
		pNxt = pCur->next;
	}

	pM->next->next = pCur;
	pM->next = pPre;

	head = pH->next;
	delete pH;
	return head;
}

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head, int m, int n)
{
	return reverseBetween(head,m,n);
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
	return "../../problems/reverse-linked-list-ii/tests.txt";
}

