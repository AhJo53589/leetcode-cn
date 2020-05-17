
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* tail) {
        ListNode* pPrev = tail;
        ListNode* pCurr = head;
        while (pCurr != tail) {
            ListNode* pNext = pCurr->next;
            pCurr->next = pPrev;
            pPrev = pCurr;
            pCurr = pNext;
        }
        return pPrev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pPrev = dummy;
        ListNode* pCurr = head;
        while (pCurr != nullptr) {
            int i = 0;
            while (i++ < k && pCurr != nullptr) {
                pCurr = pCurr->next;
            }
            if (i != k + 1) break;

            ListNode* pTemp = pPrev->next;
            pPrev->next = reverseList(pTemp, pCurr);
            pPrev = pTemp;
        }
        return dummy->next;
    }
};

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.reverseKGroup(head, k);
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
