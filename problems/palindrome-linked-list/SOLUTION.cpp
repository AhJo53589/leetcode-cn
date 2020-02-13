
//bool isPalindrome(ListNode* head)
//{
//	ListNode* slow = head, *fast = head, *prev = nullptr;
//	while (fast) {//find mid node
//		slow = slow->next;
//		fast = fast->next ? fast->next->next : fast->next;
//	}
//	while (slow) {//reverse
//		ListNode* ovn = slow->next;
//		slow->next = prev;
//		prev = slow;
//		slow = ovn;
//	}
//	while (head && prev) {//check
//		if (head->val != prev->val) {
//			return false;
//		}
//		head = head->next;
//		prev = prev->next;
//	}
//	return true;
//}


//////////////////////////////////////////////////////////////////////////
bool isPalindrome(ListNode* head)
{
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast != nullptr)
	{
		slow = slow->next;
		fast = (fast->next != nullptr) ? fast->next->next : fast->next;
	}

	ListNode *prev = nullptr;
	while (slow != nullptr)
	{
		ListNode *tmp = slow->next;
		slow->next = prev;
		prev = slow;
		slow = tmp;
	}

	while (head != nullptr && prev != nullptr)
	{
		if (head->val != prev->val) return false;

		head = head->next;
		prev = prev->next;
	}
	return true;
}


//////////////////////////////////////////////////////////////////////////
bool _solution_run(ListNode* head)
{
	return isPalindrome(head);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}

