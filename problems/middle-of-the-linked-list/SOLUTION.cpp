
class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        vector<ListNode*> nodes;
        while (head != nullptr)
        {
            nodes.push_back(head);
            head = head->next;
        }
        return nodes[nodes.size() / 2];
    }
};

//////////////////////////////////////////////////////////////////////////
class Solution2 {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            head = head->next;
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
    return sln.middleNode(head);
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
