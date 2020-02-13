
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//////////////////////////////////////////////////////////////////////////
int getDecimalValue(ListNode* head)
{
	int ans = 0;
	while (head != nullptr)
	{
		ans *= 2;
		ans += head->val;
		head = head->next;
	}
	return ans;
}

//////////////////////////////////////////////////////////////////////////
int _solution_run(ListNode* head)
{
	return getDecimalValue(head);
}

//#define USE_SOLUTION_CUSTOM
//int _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

