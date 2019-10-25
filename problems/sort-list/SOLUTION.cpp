
//////////////////////////////////////////////////////////////////////////
ListNode* merge(ListNode* l1, ListNode* l2)
{
	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;

	if (l1->val < l2->val)
	{
		l1->next = merge(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = merge(l2->next, l1);
		return l2;
	}
}

ListNode* sortList(ListNode* head)
{
	if (!head || !head->next) return head;
	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *brek = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		brek = slow;
		slow = slow->next;
	}
	brek->next = nullptr;
	ListNode *l1 = sortList(head);
	ListNode *l2 = sortList(slow);
	return merge(l1, l2);
}


//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head)
{
	return sortList(head);
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
	return "../../problems/sort-list/tests.txt";
}

