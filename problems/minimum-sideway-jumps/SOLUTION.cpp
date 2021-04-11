
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(obstacles.size(), vector<int>(3, 1e9));
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 1;
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) continue;
                dp[i][j] = dp[i - 1][j];
            }
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) continue;
                int a = (j + 1) % 3;
                int b = (j + 2) % 3;
                int side = min(dp[i][a], dp[i][b]) + 1;
                dp[i][j] = min(side, dp[i][j]);
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& obstacles)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(obstacles);

    Solution sln;
    return sln.minSideJumps(obstacles);
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
