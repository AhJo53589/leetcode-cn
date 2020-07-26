
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
        if (root == nullptr) return 0;
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }

    vector<int> dfs(TreeNode* root, int distance, int& ans) {
        if (root->left == nullptr && root->right == nullptr) return { 0 };

        vector<int> ret;
        vector<vector<int>> leaf(2, vector<int>());
        for (int i = 0; i < 2; i++) {
            TreeNode* child = (i == 0) ? root->left : root->right;
            if (child == nullptr) continue;

            leaf[i] = dfs(child, distance, ans);
            for (int j = 0; j < leaf[i].size(); j++) {
                if (++leaf[i][j] > distance) continue;
                ret.push_back(leaf[i][j]);
            }
        }

        for (int i = 0; i < leaf[0].size(); i++) {
            for (int j = 0; j < leaf[1].size(); j++) {
                int dis = leaf[0][i] + leaf[1][j];
                ans += (dis <= distance);
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
