
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pPrev = dummy;
        ListNode* pNode = head;
        while (pNode != nullptr)
        {
            ListNode* pNext = pNode->next;
            bool delFlag = false;
            while (pNext != nullptr && pNext->val == pNode->val)
            {
                delFlag = true;
                pNext = pNext->next;
            }
            if (delFlag)
            {
                pPrev->next = pNext;
                pNode = pNext;
            }
            else
            {
                pPrev = pNode;
                pNode = pNode->next;
            }
        }
        return dummy->next;
    }
};

//////////////////////////////////////////////////////////////////////////
ListNode* _solution_run(ListNode* head)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.deleteDuplicates(head);
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
