
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode** pp = (l1->val < l2->val) ? &l1 : &l2;
            cur->next = *pp;
            cur = cur->next;
            *pp = (*pp)->next;
        }
        cur->next = (l1 == nullptr) ? l2 : l1;
        return dummy->next;
    }
};

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* l1, ListNode* l2)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.mergeTwoLists(l1, l2);
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
