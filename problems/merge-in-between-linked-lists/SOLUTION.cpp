
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(0, list1);
        int i = 0;
        ListNode* la = dummy;
        while (i++ < a) {
            la = la->next;
        }
        ListNode* lb = la->next;
        while (i++ <= b) {
            lb = lb->next;
        }
        la->next = list2;
        while (list2 != nullptr && list2->next != nullptr) {
            list2 = list2->next;
        }
        list2->next = lb->next;
        return dummy->next;
    }
};

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* list1, int a, int b, ListNode* list2)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << list1 << endl;
    cout << a << ", " << b << endl;
    cout << list2 << endl;
    Solution sln;
    return sln.mergeInBetween(list1, a, b, list2);
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
