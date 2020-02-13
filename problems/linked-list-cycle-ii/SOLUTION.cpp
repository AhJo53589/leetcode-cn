


//////////////////////////////////////////////////////////////////////////
ListNode *detectCycle(ListNode *head)
{
	if (head == NULL) return NULL;

	// 步骤一：使用快慢指针判断链表是否有环
	ListNode *p = head;
	ListNode *p2 = head;
	bool hasCycle = false;
	while (p2->next != NULL && p2->next->next != NULL)
	{
		p = p->next;
		p2 = p2->next->next;
		if (p == p2)
		{
			hasCycle = true;
			break;
		}
	}

	// 步骤二：若有环，找到入环开始的节点
	if (!hasCycle) return NULL;

	ListNode *q = head;
	while (p != q)
	{
		p = p->next;
		q = q->next;
	}
	return q;
}

//////////////////////////////////////////////////////////////////////////
ListNode _solution_run(ListNode *head)
{
	return *detectCycle(head);
}

#define USE_SOLUTION_CUSTOM
bool _solution_custom(TestCases &tc)
{
	string a = tc.get<string>();
	int b = tc.get<int>();
	ListNode *head = StringIntToCycleListNode(a, b);
	return detectCycle(head);
}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

