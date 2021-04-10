
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxValue(TreeNode* root, int k) {
        return dfs(root, k, k);
    }

    int dfs(TreeNode* root, int k, int t) {
        if (root == nullptr) return 0;
        if (um.find(root) != um.end()) {
            if (um[root][t] > -1) return um[root][t];
        }

        int ans = dfs(root->left, k, k) + dfs(root->right, k, k);
        if (t > 0) {
            for (int i = 0; i < t; i++) {
                int a = dfs(root->left, k, i);
                int b = dfs(root->right, k, t - 1 - i);
                ans = max(ans, a + b + root->val);
            }
        }

        if (um.find(root) == um.end()) {
            um[root] = vector<int>(k + 1, -1);
        }
        um[root][t] = ans;
        return ans;
    }

private:
    unordered_map<TreeNode*, vector<int>> um;
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.maxValue(root, k);
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
