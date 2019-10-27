


//////////////////////////////////////////////////////////////////////////
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	ListNode *pHead = NULL;
	ListNode *pNode = NULL;

	if (l1->val < l2->val)
	{
		pHead = l1;
		l1 = l1->next;
	}
	else
	{
		pHead = l2;
		l2 = l2->next;
	}
	pNode = pHead;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val < l2->val)
		{
			pNode->next = l1;
			l1 = l1->next;
		}
		else
		{
			pNode->next = l2;
			l2 = l2->next;
		}
		pNode = pNode->next;
	}
	pNode->next = l1 ? l1 : l2;
	// 	if (l1 != NULL)
	// 	{
	// 		pNode->next = l1;
	// 	}
	// 	if (l2 != NULL)
	// 	{
	// 		pNode->next = l2;
	// 	}
	return pHead;
}


//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* l1, ListNode* l2)
{
	return mergeTwoLists(l1,l2);
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
	return "../../problems/merge-two-sorted-lists/tests.txt";
}

