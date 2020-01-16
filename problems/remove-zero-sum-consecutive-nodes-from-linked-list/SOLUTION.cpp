


//////////////////////////////////////////////////////////////////////////
ListNode* removeZeroSumSublists(ListNode* head)
{
	ListNode* dummy = new ListNode(0);
	dummy->next = head;

	ListNode* p = dummy;
	while (p->next != nullptr) 
	{
		ListNode* q = p->next;
		int sum = 0;
		while (q != nullptr)
		{
			sum += q->val;
			q = q->next;
			if (sum == 0) break;
		}

		if (sum == 0)
		{
			///////////////////////////////////////////////
			// 释放内存的做法 （leetcode传入参数delete会出错）
			//ListNode* del = nullptr;
			//while (p->next != q) 
			//{
			//	del = p->next;
			//	if (del != nullptr)
			//	{
			//		p->next = del->next;
			//		delete del;
			//	}
			//}

			///////////////////////////////////////////////
			// 不释放内存的做法
			p->next = q;
		}
		else 
		{
			p = p->next;
		}
	}
	return dummy->next;
}

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head)
{
	return removeZeroSumSublists(head);
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
	return "../../problems/remove-zero-sum-consecutive-nodes-from-linked-list/tests.txt";
}

