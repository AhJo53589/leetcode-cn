
//////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // dp[索引][颜色][街区数量 - 1] = 最小花费
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, INT_MAX)));

        if (houses[0] == 0) {
            for (int j = 1; j <= n; j++) {
                dp[0][j][0] = cost[0][j - 1];
            }
        }
        else {
            dp[0][houses[0]][0] = 0;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k < target; k++) {
                    if (houses[i] == 0) {
                        for (int j_old = 1; j_old <= n; j_old++) {
                            if (dp[i - 1][j_old][k] == INT_MAX) continue;

                            if (j_old == j) {
                                dp[i][j][k] = min(dp[i - 1][j_old][k] + cost[i][j - 1], dp[i][j][k]);
                            }
                            else {
                                dp[i][j][k + 1] = min(dp[i - 1][j_old][k] + cost[i][j - 1], dp[i][j][k + 1]);
                            }
                        }
                    }
                    else {
                        if (dp[i - 1][j][k] == INT_MAX) continue;

                        if (houses[i] == j) {
                            dp[i][j][k] = min(dp[i - 1][j][k], dp[i][j][k]);
                        }
                        else {
                            dp[i][houses[i]][k + 1] = min(dp[i - 1][j][k], dp[i][houses[i]][k + 1]);
                        }
                    }
                }
            }
        }

        int ans = INT_MAX;
        for (int j = 1; j <= n; j++) {
            ans = min(ans, dp[m - 1][j][target - 1]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

//////////////////////////////////////////////////////////////////////////
int _solution_run(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
{
    //int caseNo = -1;
    //static int caseCnt = 0;
    //if (caseNo != -1 && caseCnt++ != caseNo) return {};
    printVectorT(houses);
    printVectorVectorT(cost);
    cout << m << ", " << n << ", " << target << endl;
    Solution sln;
    return sln.minCost(houses, cost, m, n, target);
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
