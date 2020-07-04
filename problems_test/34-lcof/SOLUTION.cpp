
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, sum, path, ans);
        return ans;
    }

    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& ans) {
        sum -= root->val;
        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == 0) {
                ans.push_back(path);
            }
        }

        if (root->left != nullptr) {
            dfs(root->left, sum, path, ans);
        }
        if (root->right != nullptr) {
            dfs(root->right, sum, path, ans);
        }
        path.pop_back();
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(TreeNode* root, int sum)
{
	//int caseNo = -1;
	//static int caseCnt = 0;
	//if (caseNo != -1 && caseCnt++ != caseNo) return {};

	Solution sln;
	return sln.pathSum(root, sum);
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
