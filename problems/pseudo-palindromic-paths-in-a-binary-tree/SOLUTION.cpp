/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        unordered_map<int, int> vals;
        int ans = 0;
        dfs(root, vals, ans);
        return ans;
    }

    void dfs(TreeNode* root, unordered_map<int, int>& vals, int& ans) {
        if (root == nullptr) return;
        vals[root->val]++;

        if (root->left == nullptr && root->right == nullptr) {
            ans += check(vals);
        }
        dfs(root->left, vals, ans);
        dfs(root->right, vals, ans);

        vals[root->val]--;
    }

    bool check(unordered_map<int, int>& vals) {
        bool singleFlag = false;
        for (auto it = vals.begin(); it != vals.end(); it++) {
            if (it->second % 2 == 0) continue;
            if (singleFlag) return false;
            singleFlag = true;
        }
        return true;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.pseudoPalindromicPaths(root);
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
