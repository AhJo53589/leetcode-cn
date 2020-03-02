
//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return p;
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pPrev = nullptr;
        ListNode* pCurr = head;
        while (pCurr != nullptr)
        {
            ListNode* pNext = pCurr->next;
            pCurr->next = pPrev;
            pPrev = pCurr;
            pCurr = pNext;
        }
        return pPrev;
    }
};

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.reverseList(head);
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
