


//////////////////////////////////////////////////////////////////////////
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *pSum = new ListNode(0);
	ListNode *pNode = pSum;
	int iCarry = 0;
	while (l1 != NULL || l2 != NULL || iCarry != 0)
	{
		int i1 = (l1 != NULL) ? l1->val : 0;
		int i2 = (l2 != NULL) ? l2->val : 0;
		if (l1 != NULL) l1 = l1->next;
		if (l2 != NULL) l2 = l2->next;
		int val = (i1 + i2 + iCarry) % 10;
		iCarry = (i1 + i2 + iCarry) / 10;
		ListNode *pNew = new ListNode(val);
		pNode->next = pNew;
		pNode = pNew;
	}
	return pSum->next;
}


//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* l1, ListNode* l2)
{
	return addTwoNumbers(l1,l2);
}

//#define USE_SOLUTION_CUSTOM
//ListNode* _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

