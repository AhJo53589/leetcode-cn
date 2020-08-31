
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int ans = 0;
        dfs(root, k, ans);
        return ans;
    }

    void dfs(TreeNode* root, int &k, int& ans) {
        if (root == nullptr) return;
        dfs(root->right, k, ans);
        k--;
        if (k == 0) ans = root->val;
        dfs(root->left, k, ans);
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root, int k)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.kthLargest(root, k);
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
