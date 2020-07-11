
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool winnerSquareGame(int n) {
        return dfs(n);
    }

    bool dfs(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        if (dp.count(n) != 0) return dp[n];
        int i = 1;
        while (i * i <= n) {
            if (!dfs(n - i * i)) {
                dp[n] = true;
                return true;
            }
            i++;
        }
        dp[n] = false;
        return false;
    }

private:
    unordered_map<int, bool> dp;
};

//////////////////////////////////////////////////////////////////////////
bool _solution_run(int n)
{
    int caseNo = -1;
    static int caseCnt = 0;
    if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.winnerSquareGame(n);
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
