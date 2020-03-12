
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void dfs(int k, int sum, int idx, vector<int>& cur, vector<vector<int>>& ans)
    {
        if (k == 0 && sum == 0)
        {
            //sort(cur.begin(), cur.end());
            ans.push_back(cur);
            return;
        }
        if (k == 0 || sum == 0) return;
        
        if (idx < 0) return;
        if (sum >= idx)
        {
            cur.push_back(idx);
            dfs(k - 1, sum - idx, idx - 1, cur, ans);
            cur.pop_back();
        }

        dfs(k, sum, idx - 1, cur, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(k, n, 9, cur, ans);
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
vector<vector<int>> _solution_run(int k, int n)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.combinationSum3(k, n);
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

#define USE_CHECKANSWER_CUSTOM
void _checkAnswer_custom(vector<vector<int>>& ans, TestCases& tc)
{
    _checkAnswer_custom_sort(ans, tc);
}