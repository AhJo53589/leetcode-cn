


//////////////////////////////////////////////////////////////////////////
ListNode* removeElements(ListNode* head, int val)
{
	if (head == NULL) return head;
	while (head != NULL && head->val == val)
	{
		ListNode *pDelete = head;
		head = head->next;
		delete pDelete;
	}
	ListNode *pPreNode = NULL;
	ListNode *pNode = head;
	while (pNode != NULL && pNode->next != NULL)
	{
		pPreNode = pNode;
		pNode = pNode->next;

		if (pNode->val == val)
		{
			pPreNode->next = pNode->next;
			delete pNode;
			pNode = pPreNode;
		}
	}
	return head;
}

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head, int val)
{
	return removeElements(head,val);
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
	return "../../problems/remove-linked-list-elements/tests.txt";
}

