
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (k-- > 0 && fast != nullptr) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.getKthFromEnd(head, k);
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
