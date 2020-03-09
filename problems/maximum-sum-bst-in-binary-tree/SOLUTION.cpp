
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxSumBST(TreeNode* root) 
    {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

    vector<int> dfs(TreeNode* root, int& ans) 
    {
        if (!root) return { true, INT_MAX, INT_MIN, 0 };
        auto lArr = dfs(root->left, ans);
        auto rArr = dfs(root->right, ans);
        int sum = 0, curmax, curmin;
        if (!lArr[0] || !rArr[0] || root->val >= rArr[1] || root->val <= lArr[2]) 
        {
            return { false, 0, 0, 0 };
        }
        curmin = root->left ? lArr[1] : root->val;
        curmax = root->right ? rArr[2] : root->val;
        sum += (root->val + lArr[3] + rArr[3]);
        ans = max(ans, sum);
        return { true, curmin, curmax, sum };
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.maxSumBST(root);
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
