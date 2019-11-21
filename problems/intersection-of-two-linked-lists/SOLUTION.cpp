


//////////////////////////////////////////////////////////////////////////
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
	ListNode *pA = headA;
	ListNode *pB = headB;
	if (pA == nullptr || pB == nullptr) return nullptr;

	int iDiff = 0;
	while (pA->next != nullptr)
	{
		pA = pA->next;
		iDiff--;
	}
	while (pB->next != nullptr)
	{
		pB = pB->next;
		iDiff++;
	}

	pA = headA;
	pB = headB;
	if (iDiff < 0)
	{
		while (iDiff++ < 0) pA = pA->next;
	}
	else
	{
		while (iDiff-- > 0) pB = pB->next;
	}

	while (pA->next != nullptr)
	{
		if (pA == pB) return pA;
		pA = pA->next;
		pB = pB->next;
	}
	if (pA == pB) return pA;
	return nullptr;
}

//////////////////////////////////////////////////////////////////////////
//ListNode _solution_run(ListNode *headA, ListNode *headB)
//{
//	return *getIntersectionNode(headA,headB);
//}

#define USE_SOLUTION_CUSTOM
string _solution_custom(TestCases &tc)
{
	string l1 = tc.get<string>();
	string l2 = tc.get<string>();
	int k1 = tc.get<int>();
	int k2 = tc.get<int>();
	ListNode *pA = nullptr;
	ListNode *pB = nullptr;
	StringIntToIntersectionNode(&pA, &pB, l1, l2, k1, k2);
	ListNode *pNode = getIntersectionNode(pA, pB);
	if (pNode == nullptr) return "null";
	return to_string(pNode->val);
}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/intersection-of-two-linked-lists/tests.txt";
}

