

//ListNode* oddEvenList(ListNode* head) 
//{
//	if (head == NULL) return head;
//	if (head->next == NULL) return head;
//	if (head->next->next == NULL) return head;
//
//	ListNode *pEvenHead = head->next;
//	ListNode *pOdd = head;
//	ListNode *pEven = head->next;
//	ListNode *pNode = head->next->next;
//	int i = 2;
//	while (pNode != NULL)
//	{
//		if ((++i) % 2 == 1)
//		{
//			pOdd->next = pNode;
//			pOdd = pNode;
//		}
//		else
//		{
//			pEven->next = pNode;
//			pEven = pNode;
//		}
//		pNode = pNode->next;
//	}
//	pEven->next = NULL;
//	pOdd->next = pEvenHead;
//	return head;
//}


//////////////////////////////////////////////////////////////////////////
ListNode* oddEvenList(ListNode* head)
{
	if (!head || !head->next) return head;

	ListNode* odd = head;
	ListNode* even = head->next;
	ListNode* evenHead = even;

	while (even && even->next)
	{
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = evenHead;
	return head;
}


//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head)
{
	return oddEvenList(head);
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
	return "../../problems/odd-even-linked-list/tests.txt";
}

