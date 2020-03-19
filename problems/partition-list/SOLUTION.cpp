
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = head;
        ListNode* ins = dummy;
        ListNode* rem = dummy;
        while (fast != nullptr && fast->val < x)
        {
            fast = fast->next;
        }
        while (ins != nullptr && ins->next != fast)
        {
            ins = ins->next;
        }
        while (fast != nullptr)
        {
            if (fast->val < x)
            {
                while (rem != nullptr && rem->next != fast)
                {
                    rem = rem->next;
                }
                if (rem == nullptr) break;
                ListNode* temp = ins->next;
                ins->next = rem->next;
                rem->next = rem->next->next;
                ins->next->next = temp;
                ins = ins->next;
            }
            fast = fast->next;
        }
        return dummy->next;
    }
};

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head, int x)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << head << endl;
    Solution sln;
    return sln.partition(head, x);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
