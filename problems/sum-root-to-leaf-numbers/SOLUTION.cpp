
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void sumNumbers(TreeNode* root, int num, int& ans)
    {
        if (root == nullptr) return;
        num *= 10;
        num += root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            ans += num;
            return;
        }
        sumNumbers(root->left, num, ans);
        sumNumbers(root->right, num, ans);
    }

    int sumNumbers(TreeNode* root) 
    {
        int ans = 0;
        sumNumbers(root, 0, ans);
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.sumNumbers(root);
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
