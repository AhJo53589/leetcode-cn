
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        head = dummy;
        while (head->next != nullptr) {
            if (head->next->val == val) {
                head->next = head->next->next;
                break;
            }
            head = head->next;
        }

        return dummy->next;
    }
};

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head, int val)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.deleteNode(head, val);
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
