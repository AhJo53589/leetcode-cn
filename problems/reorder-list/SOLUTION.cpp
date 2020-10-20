
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void reorderList(ListNode* head) {
    }

    ListNode* reorder(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* second = head->next;
        ListNode* tail = reorderList(head->next);
        if (tail != nullptr) {
            head->next = tail;
            head->next->next = second;
        }
    }
};

//////////////////////////////////////////////////////////////////////////
void _solution_run(ListNode* head)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.reorderList(head);
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
