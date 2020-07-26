
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
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }

    vector<int> dfs(TreeNode* root, int distance, int& ans) {
        if (root == nullptr) return {};
        if (root->left == nullptr && root->right == nullptr) return { 0 };

        vector<int> ret;
        auto left = dfs(root->left, distance, ans);
        for (auto& e : left) {
            if (++e > distance) continue;
            ret.push_back(e);
        }
        auto right = dfs(root->right, distance, ans);
        for (auto& e : right) {
            if (++e > distance) continue;
            ret.push_back(e);
        }

        for (auto l : left) {
            for (auto r : right) {
                ans += (l + r <= distance);
            }
        }

        return ret;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root, int distance)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    cout << root << endl;
    cout << distance << endl;

    Solution sln;
    return sln.countPairs(root, distance);
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
