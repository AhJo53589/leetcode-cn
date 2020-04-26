
//////////////////////////////////////////////////////////////////////////
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<int> s1;
        stack<int> s2;
        while (l1 != nullptr)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* dummy = new ListNode(0);
        int inc = 0;
        while (!s1.empty() || !s2.empty() || inc != 0)
        {
            int n1 = 0;
            int n2 = 0;
            if (!s1.empty())
            {
                n1 = s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                n2 = s2.top();
                s2.pop();
            }
            int val = n1 + n2 + inc;
            inc = val / 10;
            ListNode* node = new ListNode(val % 10);
            node->next = dummy->next;
            dummy->next = node;
        }
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
    return sln.addTwoNumbers(l1, l2);
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
