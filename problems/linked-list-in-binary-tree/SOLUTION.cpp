
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root)
    {
        if (head == nullptr) return true;
        if (root == nullptr) return false;
        if (root->val != head->val) return false;
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root)
    {
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty())
        {
            auto q = que.front();
            que.pop();
            if (q == nullptr) continue;

            if (q->val == head->val)
            {
                if (dfs(head, q)) return true;
            }
            que.push(q->left);
            que.push(q->right);
        }
        return false;
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(ListNode* head, TreeNode* root)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.isSubPath(head, root);
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
