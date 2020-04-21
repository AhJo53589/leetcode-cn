
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

    int dfs(TreeNode* root, int& ans) {
        if (root == NULL) return 0;

        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        ans += abs(l - r);
        return l + r + root->val;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.findTilt(root);
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
