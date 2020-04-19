
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    const int mod = 1e9 + 7;

    void add(int& x, int y) {
        x += y;
        if (x >= mod) x -= mod;
    }

    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(101, vector<int>(51, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i < n; i += 1)
            for (int j = 0; j <= m; j += 1)
                for (int k = 0; k <= i; k += 1)
                    for (int x = 1; x <= m; x += 1)
                        add(dp[i + 1][max(x, j)][k + (x > j)], dp[i][j][k]);
        int ans = 0;
        for (int i = 1; i <= m; i += 1) add(ans, dp[n][i][k]);
        return ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(int n, int m, int k)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};

    Solution sln;
    return sln.numOfArrays(n, m, k);
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
