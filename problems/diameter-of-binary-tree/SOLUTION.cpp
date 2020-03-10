
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root, int& ans)
    {
        if (root == nullptr) return 0;
        int left = diameterOfBinaryTree(root->left, ans);
        int right = diameterOfBinaryTree(root->right, ans);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        int ans = 0;
        diameterOfBinaryTree(root, ans);
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
    return sln.diameterOfBinaryTree(root);
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
