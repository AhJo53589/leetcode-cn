
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        dfs(root, 1, ans);
        return ans;
    }

    void dfs(TreeNode* root, int d, int& ans) {
        if (root == nullptr) return;
        ans = max(ans, d);
        dfs(root->left, d + 1, ans);
        dfs(root->right, d + 1, ans);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxDepth(root);
}

//#define USE_SOLUTION_CUSTOM
//string _solution_custom(TestCases &tc)
//{
//	return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//	return {};
//}
