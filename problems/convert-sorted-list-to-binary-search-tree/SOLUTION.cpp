
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail)
    {
        if (head == tail) return nullptr;
        if (head->next == tail) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;

        TreeNode* node = new TreeNode(slow->val);
        node->left = sortedListToBST(head, slow);
        node->right = sortedListToBST(fast, tail);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) 
    {
        return sortedListToBST(head, nullptr);
    }
};

//////////////////////////////////////////////////////////////////////////
TreeNode* _solution_run(ListNode* head)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << head << endl;
    Solution sln;
    return sln.sortedListToBST(head);
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
