


//////////////////////////////////////////////////////////////////////////
ListNode* rotateRight(ListNode* head, int k)
{
	if (head == NULL) return head;
	if (head->next == NULL) return head;

	ListNode *pNode = head;
	int len = 0;
	while (pNode != NULL)
	{
		len++;
		if (pNode->next == NULL)
		{
			pNode->next = head;
			break;
		}
		pNode = pNode->next;
	}
	k = len - (k % len);
	pNode = head;
	while (k-- > 1) pNode = pNode->next;
	ListNode *pNewHead = pNode->next;
	pNode->next = NULL;

	return pNewHead;
}


//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head, int k)
{
	return rotateRight(head,k);
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
	return "../../problems/rotate-list/tests.txt";
}

