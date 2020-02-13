
//////////////////////////////////////////////////////////////////////////
bool hasCycle(ListNode *head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast != nullptr)
	{
		fast = fast->next;
		if (fast == nullptr)
		{
			return false;
		}
		slow = slow->next;
		fast = fast->next;

		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
bool _solution_run(ListNode *head)
{
	return hasCycle(head);
}

#define USE_SOLUTION_CUSTOM
bool _solution_custom(TestCases &tc)
{
	string a = tc.get<string>();
	int b = tc.get<int>();
	ListNode *head = StringIntToCycleListNode(a, b);
	return hasCycle(head);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

