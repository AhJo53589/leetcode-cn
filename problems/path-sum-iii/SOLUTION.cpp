class Solution2{
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> mp; //sum count
        int res = 0;
        mp[0] = 1;
        int cur = 0;
        dfs(root, sum, res, cur, mp);
        return res;
    }

    void dfs(TreeNode* root, int sum, int& res, int& cur, unordered_map<int, int>& mp) {
        if (!root)
            return;
        cur += root->val;
        res += mp[cur - sum];
        mp[cur] ++;
        dfs(root->left, sum, res, cur, mp);
        dfs(root->right, sum, res, cur, mp);
        mp[cur]--;
        cur -= root->val;
        return;
    }
};
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void dfs(TreeNode* root, int ps, int sum, unordered_map<int, int>& vi, int& ans)
    {
        if (root == nullptr) return;
        root->val += ps;
        ans += vi[root->val - sum];
        vi[root->val]++;
        dfs(root->left, root->val, sum, vi, ans);
        dfs(root->right, root->val, sum, vi, ans);
        vi[root->val]--;
    }

    int pathSum(TreeNode* root, int sum) 
    {
        int ans = 0;
        unordered_map<int, int> vi;
        vi[0] = 1;
        dfs(root, 0, sum, vi, ans);
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(TreeNode* root, int sum)
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
//    return {};
//}

//////////////////////////////////////////////////////////////////////////
//#define USE_GET_TEST_CASES_IN_CPP
//vector<string> _get_test_cases_string()
//{
//    return {};
//}
