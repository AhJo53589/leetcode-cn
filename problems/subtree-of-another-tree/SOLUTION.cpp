
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        while (s != nullptr) {
            if (dfs(s, t)) return true;
            return (isSubtree(s->left, t) || isSubtree(s->right, t));
        }
        return false;
    }

    bool dfs(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        if (s->val != t->val) return false;
        return (dfs(s->left, t->left) && dfs(s->right, t->right));
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(TreeNode* s, TreeNode* t)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.isSubtree(s, t);
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
