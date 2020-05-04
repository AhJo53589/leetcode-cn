
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int val = 0;
        bool flag = false;
        return Inorder(root, val, flag);
    }

    bool Inorder(TreeNode* root, int& val, bool& flag) {
        if (root == nullptr) return true;

        if (!Inorder(root->left, val, flag)) return false;

        if (flag && !(val < root->val)) return false;
        val = root->val;
        flag = true;

        if (!Inorder(root->right, val, flag)) return false;
        return true;
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }

    bool dfs(TreeNode* root, long long min, long long max) {
        if (root == NULL) return true;
        if (root->val <= min || root->val >= max) return false;
        return dfs(root->left, min, root->val) && dfs(root->right, root->val, max);
    }
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(TreeNode* root)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.isValidBST(root);
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
