
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
		if (head == nullptr) return head;
		unordered_set<int> us{ head->val };

		ListNode* p = head;
		while (p->next != nullptr) {
			if (us.count(p->next->val) == 0) {
				us.insert(p->next->val);
				p = p->next;
			}
			else {
				p->next = p->next->next;
			}
		}
		return head;
    }
};

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.removeDuplicateNodes(head);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
