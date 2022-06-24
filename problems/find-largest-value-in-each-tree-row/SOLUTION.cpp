
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }

    void dfs(TreeNode* node, vector<int>& ans, int h) {
        if (node == nullptr) return;
        if (ans.size() == h) {
            ans.push_back(node->val);
        }
        ans[h] = max(ans[h], node->val);

        dfs(node->left, ans, h + 1);
        dfs(node->right, ans, h + 1);
    }
};

//////////////////////////////////////////////////////////////////////////
vector<int> _solution_run(TreeNode* root)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.largestValues(root);
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
